*Proyecto realizado como parte del currículo de 42 por **oduran-m*** 
# Born2beroot – Debian + Bonus (Lighttpd, MariaDB, WordPress, Redis)

---

## Descripción

Este proyecto sirve para aprender a configurar un sistema operativo desde cero, instalándolo a partir de una imagen `.iso`.  
En este caso se utiliza **Debian 13.4** como sistema operativo principal.

### ¿Por qué Debian 13.4?

- Sencillo de usar para principiantes.  
- Dispone de una documentación muy extensa y una comunidad muy activa.  
- Es un sistema muy estable y robusto.  
- Su gestor de paquetes **APT** es intuitivo y fácil de usar.  
- Es software libre, sin patentes de uso.

---

## Conceptos previos

### ¿Cuál es el propósito de una máquina virtual?

- Proporcionar un entorno seguro y aislado para pruebas y desarrollo.  
- Permitir varios sistemas operativos en una misma máquina física.  
- Facilitar copias de seguridad y restauración ante desastres.  
- Probar y desarrollar sin afectar al sistema anfitrión.  
- Ejecutar sistemas operativos o aplicaciones más antiguas.

### APT vs Aptitude

**APT (Advanced Package Tool)**  
- Gestor de paquetes de bajo nivel.  
- Orientado a línea de comandos.  
- Rápido y ligero.  
- Usado por defecto en scripts y automatizaciones.

**Aptitude**  
- Gestor de alto nivel construido sobre APT.  
- Ofrece interfaz interactiva y también línea de comandos.  
- Mejor resolución de dependencias.  
- Mejor gestión de paquetes huérfanos.  
- Más amigable para usuarios no acostumbrados a la terminal.

### AppArmor

**AppArmor (Application Armor)** es un módulo de seguridad para Linux basado en **MAC (Mandatory Access Control)**.

- Restringe qué recursos del sistema puede usar cada aplicación.  
- Usa **perfiles de seguridad** por aplicación.  
- Controla el acceso según la **ruta del archivo**.  
- Complementa a los permisos tradicionales de Linux.

### LVM (Logical Volume Manager)

LVM permite crear particiones flexibles en el disco, dando más libertad para ampliar o reducir espacio.

**Flexibilidad**

- Redimensionado dinámico de volúmenes (en muchos casos sin desmontar).  
- Gestión sencilla de múltiples discos físicos.  
- Posibilidad de crear **snapshots** (copias coherentes del estado).

**Estructuras principales**

- **PV (Physical Volume):** disco o partición física.  
- **VG (Volume Group):** conjunto de PV.  
- **LV (Logical Volume):** “partición virtual” creada dentro del VG.

**Ventajas frente a particiones tradicionales**

- Redimensionado más flexible.  
- Facilita migrar datos entre dispositivos.  
- Permite copias de seguridad consistentes.  
- Puede distribuir datos entre discos para mejorar rendimiento.

---

## Instrucciones rápidas

Para arrancar la máquina: abrir **VirtualBox** y pulsar **Start** sobre la VM de Born2beroot.

---

## Contenidos

A continuación se describen las partes más importantes del proyecto, desde la configuración básica hasta el bonus.

---

## 1. Configuración de `sudo`

### Verificar instalación

```bash
sudo -V
```

### Editar políticas de seguridad

Abrir el archivo principal de configuración:

```bash
sudo visudo
```

Añadir estas líneas `Defaults`:

```text
Defaults    env_reset                      # Limpia variables de entorno
Defaults    mail_badpass                   # Envía correo si hay contraseñas erróneas
Defaults    passwd_tries=3                 # Intentos máximos para la contraseña de sudo
Defaults    badpass_message="Wrong password. Try again."  # Mensaje personalizado
Defaults    logfile="/var/log/sudo.log"    # Ruta de registros de sudo
Defaults    log_input,log_output           # Registra entrada y salida de comandos
Defaults    iolog_dir="/var/log/sudo"      # Directorio de logs de E/S
Defaults    requiretty                     # Obliga a usar sudo desde una TTY real
Defaults    secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
```

*(Ajusta rutas y mensaje según tu configuración.)*

---

## 2. Políticas de contraseña

### `/etc/login.defs`

```bash
sudo nano /etc/login.defs
```

Configurar:

```text
PASS_MAX_DAYS  30   # Días máximos antes de caducar la contraseña
PASS_MIN_DAYS  2    # Días mínimos entre cambios de contraseña
PASS_WARN_AGE  7    # Días de aviso antes de la caducidad
```

### Reglas de calidad de contraseña (PAM)

Instalar módulo:

```bash
sudo apt install libpam-pwquality
sudo nano /etc/pam.d/common-password
```

Parámetros recomendados de `pam_pwquality.so`:

```text
minlen=10          # Longitud mínima
ucredit=-1         # Al menos 1 mayúscula
lcredit=-1         # Al menos 1 minúscula
dcredit=-1         # Al menos 1 dígito
maxrepeat=3        # Máximo 3 caracteres iguales seguidos
reject_username    # Prohíbe usar el nombre de usuario en la contraseña
difok=7            # Mínimo 7 caracteres distintos a la contraseña anterior
enforce_for_root   # También se aplica al usuario root
```
Canviar contrasenya:
```bash
sudo passwd oduran
```

### Comprobar política aplicada

```bash
sudo chage -l oduran
sudo chage -M 30 -m 2 -W 7 oduran
```

---

## 3. Script de monitorización (`monitoring.sh`)

### Crear script y permisos

```bash
sudo touch /usr/local/bin/monitoring.sh
sudo chmod 755 /usr/local/bin/monitoring.sh
```

### Contenido del script

```bash
#!/bin/bash

# ARCH: arquitectura y versión del kernel
arch=$(uname -a)

# CPU PHYSICAL: número de CPUs físicas
cpuf=$(grep "physical id" /proc/cpuinfo | wc -l)

# CPU VIRTUAL: número de CPUs lógicas (vCPU)
cpuv=$(grep -c "^processor" /proc/cpuinfo)

# RAM: total, usada y porcentaje
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
ram_use=$(free --mega | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

# DISK: total, usado y porcentaje (excluyendo /boot)
disk_total=$(df -m | grep "^/dev/" | grep -v "/boot" | awk '{t += $2} END {printf("%.1fGb"), t/1024}')
disk_use=$(df -m | grep "^/dev/" | grep -v "/boot" | awk '{u += $3} END {print u}')
disk_percent=$(df -m | grep "^/dev/" | grep -v "/boot" | awk '{u += $3; t += $2} END {printf("%d"), u*100/t}')

# CPU LOAD: porcentaje de uso de CPU
cpul=$(vmstat 1 2 | tail -1 | awk '{print $15}')   # % idle
cpu_op=$((100 - cpul))
cpu_fin=$(printf "%.1f" "$cpu_op")

# LAST BOOT
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# LVM USE
lvmu=$(if lsblk | grep -q "lvm"; then echo yes; else echo no; fi)

# TCP CONNECTIONS
tcpc=$(ss -ta | grep ESTAB | wc -l)

# USER LOG: usuarios conectados
ulog=$(users | wc -w)

# NETWORK: IP y MAC
ip=$(hostname -I)
mac=$(ip link | awk '/link\/ether/ {print $2}')

# SUDO: número de comandos ejecutados con sudo
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "	Architecture: $arch
	CPU physical: $cpuf
	vCPU: $cpuv
	Memory Usage: $ram_use/${ram_total}MB ($ram_percent%)
	Disk Usage: $disk_use/${disk_total} ($disk_percent%)
	CPU load: $cpu_fin%
	Last boot: $lb
	LVM use: $lvmu
	Connections TCP: $tcpc ESTABLISHED
	User log: $ulog
	Network: IP $ip ($mac)
	Sudo: $cmnd cmd"
```

### Ejecutar cada 10 minutos con `cron`

1. Permitir ejecutar el script sin contraseña:

```bash
sudo visudo
```

Añadir:

```text
oduran ALL=(ALL) NOPASSWD: /usr/local/bin/monitoring.sh
```

2. Habilitar y arrancar `cron`:

```bash
sudo systemctl enable cron.service
sudo systemctl start cron.service
```

3. Editar `crontab` de root:

```bash
sudo crontab -u root -e
```

Añadir:

```text
*/10 * * * * sh /usr/local/bin/monitoring.sh
```

---

## 4. Particiones y usuarios

### Particiones

```bash
lsblk
```

### Gestión de usuarios y grupos

```bash
users                       # usuarios conectados
groups                      # grupos del usuario actual
sudo adduser <login>        # crear usuario
sudo addgroup <grupo>       # crear grupo
getent group <grupo>        # ver miembros de un grupo
sudo adduser <user> <grupo> # añadir usuario a grupo
```

---

## 5. SSH

SSH (*Secure Shell*) es un protocolo seguro para administrar máquinas de forma remota.

### Comandos principales

```bash
sudo service ssh status                 # comprobar servicio
sudo nano /etc/ssh/sshd_config         # configurar servidor (puerto 4242, root login no)
sudo service ssh restart               # aplicar cambios
```

En VirtualBox: abrir el puerto 4242 en **Port Forwarding**.

Conexión desde la máquina real:

```bash
ssh <user>@localhost -p 4242
ssh <user>@127.0.0.1 -p 4242
netstat -tuln | grep 4242               # ver puertos en escucha
```

---

## 6. UFW (Uncomplicated Firewall)

Firewall sencillo para gestionar `iptables` mediante comandos simples.

```bash
sudo ufw enable
sudo ufw allow 4242
sudo ufw status
```

---

## 7. Bonus – Servidor web completo

### 7.1 Lighttpd

```bash
sudo apt install lighttpd -y
sudo ufw allow 80
# Abrir puerto 80 en VirtualBox (Port Forwarding)
sudo systemctl enable lighttpd
sudo systemctl start lighttpd
```

### 7.2 MariaDB

```bash
sudo apt install mariadb-server
sudo mariadb-secure-installation   # o mysql_secure_installation según versión
```

Respuestas típicas:

- Switch to unix_socket authentication? → N  
- Change the root password? → N  
- Remove anonymous users? → Y  
- Disallow root login remotely? → Y  
- Remove test database and access to it? → Y  
- Reload privilege tables now? → Y  

Crear base de datos y usuario:

```sql
sudo mariadb
CREATE DATABASE oduran;
GRANT ALL ON oduran.* TO 'oduran'@'localhost' IDENTIFIED BY '@Iloveecole42' WITH GRANT OPTION;
FLUSH PRIVILEGES;
```

### 7.3 PHP

```bash
sudo apt install php-fpm php-mysql php-curl php-gd php-zip -y
php -v
```

Configurar FastCGI para Lighttpd:

```bash
sudo nano /etc/lighttpd/conf-available/15-fastcgi-php.conf
```

```text
fastcgi.server = ( ".php" =>
  ( "localhost" =>
    ( "socket" => "/run/php/php8.4-fpm.sock",   # ajusta versión
      "broken-scriptfilename" => "enable"
    )
  )
)
```

Activar módulos y recargar:

```bash
sudo lighty-enable-mod fastcgi
sudo lighty-enable-mod fastcgi-php
sudo systemctl reload lighttpd
```

### 7.4 WordPress

```bash
sudo apt install wget -y
sudo wget https://wordpress.org/latest.tar.gz -P /var/www/html
sudo tar -xzvf /var/www/html/latest.tar.gz -C /var/www/html
sudo rm /var/www/html/latest.tar.gz
sudo cp -r /var/www/html/wordpress/* /var/www/html
sudo rm -rf /var/www/html/wordpress
```

Configurar archivos y permisos:

```bash
sudo cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
sudo chown -R www-data:www-data /var/www/html
sudo chmod -R 755 /var/www/html
sudo nano /var/www/html/wp-config.php
```

En `wp-config.php`:

```php
define( 'DB_NAME', 'oduran' );
define( 'DB_USER', 'oduran' );
define( 'DB_PASSWORD', '@Iloveecole42' );
```

Acceso en el navegador (según port forwarding):

```text
http://localhost:8080
```

### 7.5 Plugin Redis para WordPress

Instalación:

```bash
sudo apt install redis-server -y
sudo apt install php-redis -y
sudo systemctl restart lighttpd
```

Configurar Redis:

```bash
sudo nano /etc/redis/redis.conf
```

```text
requirepass @Iloveecole42   # contraseña de Redis
save 900 1                  # 900s y ≥1 cambio → snapshot
save 300 10                 # 300s y ≥10 cambios → snapshot
save 60 10000               # 60s y ≥10000 cambios → snapshot
```

Crear directorio de datos:

```bash
sudo mkdir -p /var/lib/redis
sudo chown redis:redis /var/lib/redis
sudo systemctl restart redis-server
```

Configurar WordPress:

```bash
sudo nano /var/www/html/wp-config.php
```

```php
define( 'WP_REDIS_HOST', '127.0.0.1' );
define( 'WP_REDIS_PASS', '@Iloveecole42' );
```

Probar Redis:

```bash
redis-cli
auth @Iloveecole42   # debe devolver OK
ping                 # debe devolver PONG
```

En el panel de WordPress: instalar el plugin **Redis Object Cache**, activarlo y comprobar que en *Status* aparece “Connected”.

## 8. Comandos útiles para las correcciones

### 8.1 Sistema y particiones

```bash
uname -a             # Info del kernel y la arquitectura
lsblk                # Ver discos, particiones y LVM
df -h                # Uso de disco por partición
hostnamectl          # Nombre de host y SO
```

### 8.2 Usuarios, grupos y contraseñas

```bash
getent passwd oduran                        # Ver que el usuario existe
getent group sudo                           # Ver miembros del grupo sudo
id oduran                                   # UID, GID y grupos del usuario
sudo chage -l oduran                        # Política de caducidad de la contraseña
sudo grep '^PASS_' /etc/login.defs          # Ver PASS_MAX_DAYS, etc.
sudo grep pwquality /etc/pam.d/common-password   # Reglas de complejidad
```

### 8.3 `sudo` y seguridad

```bash
sudo -V                                  # Versión de sudo y ruta de sudoers
sudo grep '^Defaults' /etc/sudoers       # Opciones env_reset, logfile, etc.
sudo tail -n 20 /var/log/sudo.log        # Últimos registros de sudo
journalctl _COMM=sudo | tail -n 10       # Logs de sudo en journalctl
```

### 8.4 Firewall (UFW)

```bash
sudo ufw status verbose   # Comprobar que está activo y reglas detalladas
sudo ufw status numbered  # Ver reglas con número
```

### 8.5 SSH

```bash
sudo systemctl status ssh                         # Estado del servicio SSH
sudo grep -E 'Port|PermitRootLogin' /etc/ssh/sshd_config
sudo ss -tlnp | grep 4242                         # Ver que escucha en el puerto 4242
ssh <user>@localhost -p 4242                      # Probar la conexión desde la máquina real
```

### 8.6 Script de monitorización y cron

```bash
sudo ls -l /usr/local/bin/monitoring.sh   # Ver permisos (debe ser 755)
sudo crontab -u root -l                   # Ver la línea */10 * * * * ...
sudo systemctl status cron                # Estado del servicio cron
sudo /usr/local/bin/monitoring.sh         # Ejecutar el script manualmente
```

### 8.7 Servicios bonus

#### Lighttpd

```bash
sudo systemctl status lighttpd
sudo ss -tlnp | grep 80
```

#### MariaDB

```bash
sudo systemctl status mariadb
sudo mariadb -e "SHOW DATABASES;"
```

#### PHP

```bash
php -v
sudo ls /etc/lighttpd/conf-available/15-fastcgi-php.conf
```

#### WordPress

```bash
ls -l /var/www/html/
sudo grep DB_NAME /var/www/html/wp-config.php
```

#### Redis

```bash
sudo systemctl status redis-server
redis-cli ping                 # Debe devolver PONG
redis-cli auth @Iloveecole42   # Debe devolver OK
sudo grep requirepass /etc/redis/redis.conf
```
---
