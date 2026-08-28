*This project has been created as part of the 42 curriculum by oduran-m.*

## Description

Este proyecto esta echo para aprender a configurar un sistema operatibo desde un inicio instalando-lo des de un archivo '.iso'. En este caso hemos usado el SO Debian 13.4.
Porque he usado Debian 13.4:
- Por su simplicidad de uso para principiantes.
- Tiene una base de docuemntacion muy extensa y una gran comunidad que te peude ayudar en cualquier caso.
- Por su estabilidad ya que es un SO de lo mas robustos.
- Su gestor de paquetes APT es muy intuitivo y sencillo de usar.
- Junto a que es un software libre de uso sin ninguna patente.

###Cual es el proposito de una maquina virtual?
- Proporciona un entorno completamente seguro y aislado preparado para realizar pruebas y desarrollo.
- Permite tener multiples sistemas operativos en una sola maquina y tener una mejor eficiencia de recursos.
- Puedes recuperar el sitema operativo ante desastres con sencillas copias de seguridad de todos los estados del sistema.
- Puedes desarollar y hacer pruevas de cualquier cosa con el SO sin miedo a afectar al sistema anfitrion.
- Puedes ejecutar SO o aplicaciones m'as antiguas para probar cualquier cosa.
###APT o APTITUDE
APT(Advanced Package Tool):
- Es un gestor de paquetes de bajo nivel y basico.
- Solo esta para lindea de comandos.
- Rapido y ligero como una pluma.
- Usado por defecto para la mayoria de los scripits y automatizaciones.
Aptitude:
- Gestor de alto nivel echo sobre el APT.
- Ofrece una interfaz para mejor experiencia del usuario pero tambien ofrece uso en linea de comando.
- Mejor resolucion de dependencias.
- Funciones interactivas mejores y mas detalladas de los paquetes de dependecias.
- Una gestion mas eficiente en paquetes huerfanos.
- Mas amigable para un usuario no familiarizado con la terminal.
### AppArmor
AppArmor (Application Armor) se trata de un modulo de seguridad de Linux basado en el control de acceso obligatorio (Mandatory Access Control, MAC):
- Tiene una restriccion de aplicaciones uqe limita la capacidad del programa para acceder a los recursos del sistema.
- Tiene restricciones por perfiles de segurida lo cual permite restringir los recursos a las aplicaciones por perfiles.
- Controla el accesso basanndose en las rutas de los archivos.
- Permite restringir el acceso a las aplicaciones explicitamente.
- Es  completamente funcional junto a los permisos tradicionales de Linux y los complementa.
### LVM
LVM(Logical Volume Manager) se trata de particiones flexibles del disco duro que permiten organizar la informacion de forma que el sistema tiene mucha mas flexibilidad para ampliar o acortar el espacio.
Flexibilidad:
- Redimensionamiento dinámico de particiones sin desmontarlas.
- Permite una gestion sencilla y rapida en multiples dispositivos fisicos.
- Crea una imagen de seguridad.
Estructuras:
- Physical Volumes (PV): Disco duro o particiones fisicas.
- Volume Groups (VG): Conjuntos de volumenes fisicos.
- Logical Volumes (LV): Particiones virtuales que peuden abarcar varios volumenes fisicos.
Ventjas sobre las articiones tradicionales:
- Se redimensionan sobre la marcha.
- Transferencia de datos etre dispositivos de almacenamiento.
- Realiza copias de seguridad consistentes.
- Distribuye datos entre los dispositivos para optimizar el rendimiento.

## Insructions

Solo hace falta abrir la aplicacion de Virtual Box y darle al boton de Start!!(disfruten y vean)

## Partes
A contiuacion voy a documentar todas las partes importantes del proyecto emepzando por lo mas basico a lo mas complejo:
###sudo
Para verificar si el comando "sudo" esta instalado:
	$ sudo -V
Para configurar las politicas de seguridad de sudo tendresmo que poner este comando para cceder al archivo de configuracion de sudo:
	$ sudo visudo
Dentro de este archivo vamos a anyadir 9 comandos para hacer mas seguro nuestro comando sudo:
	Defaults	env_reset (limpia las variables del entorno)
	Defaults	mail_badpass (Si se equiboca de pass se envia un correo)
	Defaults	passwd_tries=3 (total de intentos para entrar la contrasenya de sudo)
	Defaults	badpass_message (Mensaje de contrasenya erronea personalizado)
	Defaults	logfile (Ruta donde se van a almazenar los registros de sudo)
	Defaults	log_input, log_output (graba la entrada y la salida del comando)
	Defaults	iolog_dir (ruta donde se van a guardar los registros de entrada y salida)
	Defaults	requiretty (solo se puede usar sudo en terminal real)
	Defaults	secure_path (Carpetas exlcuidas de sudo)
###Configuracion politicas de constrasenya
Vamos a editar el siguiente archivo para modificar las politicas de nuestra contrasenya:
	$ nano /etc/login.defs
En este archivo vamos a edtiar las siguientes lineas de configuracion:
	PASS_MAX_DAYS	30 (maximo numero de dias para que caduque la contrasenya)
	PASS_MIN_DAYS	2  (Numero minimo de dias antes de que se caduque la contrasenya)
	PASS_WARN_AGE	7  (Numero de dias antes de que caduqie la constrasenya para mostrar la advertencia)
Vamos a editar las normas de la contrasenya para eso instalaremos "libpam-pwquality" y accederemos al archivo de configuracion:
	$ sudo apt install libpam-pwquality
	$ nano /etc/pam.d/common-password
Dentro del archivo coniugraremos la contrasenya de la suigueinte forma:
	- minlen=10 (Numero minimo de caracteres que debe tener)
	- ucredit=-1 (Minimo tiene que tener una letra minuscula, si fuera un + indicaria el maximo)
	- dcredit=-1 (Tiene que tener al menos un digito)
	- lcredit=-1 (Minimo 1 letra minuscula)
	- maxrepeat=3 (No puede tener el mismo caracter repetido 3 veces consecutivas)
	- reject_username (No puede contener el nombre del usuario)
	- difok=7 (Debe contener al menos siete caracteres distintos a la ultima contrasenya usada)
	- enforce_for_root (Esta politica de contrasenya tambien se aplicara al usuario root)
Comprueva los detalles del usuario:
	$ sudo chage -l oduran
	$ sudo chage -M 30 -m 2 -W 7 oduran
###Script
Vamos ha hacer un script que se ejecute cada 10 miuto automaticamente, en el escript le vamos a configurar de la siguiente manera para que nos muestre informacion del sistema operativo, vamos a crear el archivo y a darl permisos:
	$ sudo touch /usr/local/bin/monitoring.sh
	$ sudo chmod 755 /usr/local/bin/monitoring.sh
Una vez creado el .sh vamos a escribir todo esto:
#!/bin/bash

# ARCH
arch=$(uname -a) //Muestra la arquitectura del SO ("-a" == "--all")

# CPU PHYSICAL
cpuf=$(grep "physical id" /proc/cpuinfo | wc -l) // Imprime el numero de nucleos del SO

# CPU VIRTUAL
cpuv=$(grep "processor" /proc/cpuinfo | wc -l) // imprime el numero de nucleos virtuales del SO

# RAM
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}') // Obtener los MB de memoria usados
ram_use=$(free --mega | awk '$1 == "Mem:" {print $3}') // Numero totl de MB de memoria
ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}') // Obtener el porcentaje usado de memoria

# DISK
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), disk_t/1024}') // Obten el total de memoria del disco
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}') // Obten la memoria usada en ese momento
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t+= $2} END {printf("%d"), disk_u/disk_t*100}') // Calucla el porcentaje con los dos valores anteriores y los pone en porcentaje

# CPU LOAD
cpul=$(vmstat 1 2 | tail -1 | awk '{printf $15}') // Obten el porcentaje de CPU inactiva
cpu_op=$((100 - $cpul)) // Calcula el porcentaje de CPU usada
cpu_fin=$(printf "%.1f" $cpu_op) // Formatea el resultado para verlo en porcentaje

# LAST BOOT
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}') // Fecha y hora del ultimo reinicio

# LVM USE
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi) //Saver si el servicio de lvm esta activo o no

# TCP CONNEXIONS
tcpc=$(ss -ta | grep ESTAB | wc -l) // Obten el numero deconeccines TCP que tienes en ese momento

# USER LOG
ulog=$(users | wc -w) // numero de usuarios que tiene el SO

# NETWORK
ip=$(hostname -I) // Obten la IP
mac=$(ip link | grep "link/ether" | awk '{print $2}') // Obten la MAC del PC

# SUDO
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l) // Obten el total de comandos ejecutados por sudo

wall "	Architecture: $arch		// manda un mensaje a las terminales de los usuarios
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
Una vez tenemos el archivo .sh hace falta configurarlo para que se ejecute cada 10 minutos, para eso primero vamos a ir a:
	$ sudo visudo
A bajo de esta linea "%sudo ALL=(ALL:ALL) ALL" le anyadimos esta linea:
	oduran ALL=(ALL) NOPASSWD: /usr/local/bin/monitoring.sh
para indicarle dodne esta el archivo a ejecutar, luego vamos a activar el servicio cron con el siguiente comando:
	$ sudo systemctl enable cron.service
y vamos a configuar el servicio cron para que lo ejecute cada 10 minutos, ejecutamos este comando:
	$ sudo crontab -u root -e
y vamos a anyadir esta linea a bajo del todo:
	*/10 * * * * sh /path_to_file.sh
en mi caso se vera de esta forma:
	*/10 * * * * sh /usr/local/bin/monitoring.sh
###Particiones
Comando para comprobar las particiones:
	$ lsblk
###Gestion de grupos y usuarios
Saber cuantos usuarios existen:
	$ users
Saber gruos existentes:
	$ groups
Crear usuario:
	$ sudo adduser <login>
Crear grupo:
	$ sudo addgroup <nombregrupo>
Comprueba los miembros del grupo:
	$ getent group <nombregrupo>
Anyadir un usuario a algun grupo:
	$ sudo adduser <nombreusuario> <nombregrupo>
###SSH
SSH acronim de "Secure shell". Se tata de un protocolo disenyado como alternatica segura a los otros protocolos de shell remotos que no son seguros. Usa un modelo cliente-servidor en el que los 2 se comunican a trabes de un canal seguro.
Verificar la instalacion de SSH:
	$ sudo service ssh status
Se configura a traves del archivo "sshd_config"
	$ sudo nano /etc/ssh/sshd_config (puerto 4242 y deshabilitar el login root)
Tenemos que indicar el puerto abierto en el archivo "ssh_config"
	$ sudo nano /etc/ssh/ssh_config
Reseteamos el servicio para efectuar los canvios:
	$ sudo service ssh restart
Tenemos que abrir el puerto 4242 en la maquina virtual para poder acceder de fuera al servidor:
	Settings > Network > Advanced > Port Forwarding > Adds new port forwarding rules
En nuestra maquina ya podemos conectaros en ssh con el comando:
	$ ssh <user>@localhost -p 4242 o 4241 ('-p' es de puerto) 
	$ ssh <user>@127.0.0.1 -p 4242 o 4241
Para ver en tu maquina real los puestos por los que escucha la maquina usamos este mando:
	$ netstat -tuln | grep 4242
###UFW (Uncomplicated Firewall)
Se trata de un firewall que usa lineas de comandos para la configuracion iptables con comandos simples y faciles de enteder.
Habilitar el ufw:
	$ sudo ufw enable
Habilitar puerto:
	$ sudo ufw allow <puerto>
	Ex: $ sudo ufw allow 4242
Ver los puertos habilitados:
	$ sudo ufw status
###BONUS
#lighttpd
Lighttpd es un servidor web diseñado para ser rápido, seguro, flexible y compatible con los estándares. Está optimizado para entornos donde la velocidad es una prioridad, ya que consume menos CPU y RAM que otros servidores.
Lo instalamos con:
	$ sudo apt install lighttpd -y
Vamos a avilitar el puerto 80 en nuestro firewall:
	$ sudo ufw allow 80
Abrimos el puerto 80 en nuestra maquina virtual:
	Settings > Network > Advanced > Port Forwarding > Adds new port forwarding rules
HAbilitamos el lighttpd para que se inicie automaticamente cuando iniciamos debian:
	$ sudo systemctl enable lighttpd
	$ sudo systemctl start lighttpd
#MariaDB
MariaDB: Es una base de datos. Se utiliza para diversos fines, como almacenamiento de datos, comercio electrónico, funciones empresariales y aplicaciones de registro.
La vamos a instalar y configurar con estos comandos:
	$ sudo apt install mariadb-server
	$ sudo mysql_secure_installation
Nos saldra un questionario, vamos a contestar estas respuestas ya que ya tenemos un usario root creado:
	- Switch to unix_socket autentication? → N 
	- Change the root password? → N
	- Remove anonymous users? → Y 
	- Disallow root login remotely? → Y 
	- Remove test database and access to it? → Y 
	- Reload privilege tables now? → Y
Una vez instalada y configurada vamos a cear una base de datos en MariaDB:
	$ sudo mariadb
	$ CREATE ATABASE oduran;
Y la configuramos para usarla:
	$ GRANT ALL ON oduran.* TO 'oduran'@'localhost' IDENTIFIED BY '@Iloveecole42' WITH GRANT OPTION;
Vamos a actualizar los permisos para actualizar los canvios echos:
	$ FLUSH PRIVILEGES;
#PHP
Es un lenguaje de programación. Se utiliza principalmente para desarrollar aplicaciones web dinámicas y sitios web interactivos. PHP se ejecuta en el servidor.
Necesitaremos instalar el PHP y ciertas dependencias:
	$ sudo apt install php-fpm php-mysql php-curl php-gd php-zip -y
Podremos verificar si se a instalado bien con el comando:
	$ php -v
Vamos a configurar el archivo de php:
	$ sudo nano /etc/lighttpd/conf-available/15-fastcgi-php.com
En el archivo lo vamos a configrar con estas lineas de codigo:
"
fastcgi.server = ( ".php" =>
	( "localhost" =>
		(
			"socket" => "/run/php/php8.4-fpm.sock", // pon tu numero de version de php
			"broken-scritfilname" => "enable"
		)
	)
)
"
y vamos a resetear el servidio para aplicar la configuracion:
	$ sudo lighty-enable-mod fastcgi
	$ sudo lighty-enable-mod fastcgi-php
	$ sudo systemctl reload //status lighttpd
#Wordpress
Es un sistema de creacion de contenido centrado en la creacion de paginas web para que qualquiera pueda realicar una web de forma intuitiva y facil.
Lo instalamos con el siguiente comando que primero tendremos que instalar el "wget" para descaergar la ultima version oficial de la pagina web y luego lo vamos a instalar a la carpeta de nuestro servidor web:
	$ sudo apt install wget -y
	$ sudo wget https://wordpress.org/latest.tar.gz -P /var/www/html
una vez descargado lo descomprimimos:
	$ sudo tar -xzvf /var/www/html/latest.tar.gz -C /var/www/html
y borramos el archivo .tar:
	$ sudo rm /var/www/html/latest.tar.gz
copiamos todo el contenido de worpdres a fuera para que una ve hacedamos a la rutal "localhost" nos abra directamente el wordrepss yborramos la carpeta vacia:
	$ sudo cp -r /var/www/html/wordpress/* /var/www/html
	$ sudo rm -rf /var/www/html/wordpress
Renombramos la pagina de configuracion para configurar el Wordpress por defecto, cambiamos de propietario con el comando "chwon" y le damos permisos con "chmod":
	$ sudo cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
	$ sudo chown -R www-data:www-data /var/www/html
	$ sudo chmod -R 755 /var/www/html
Vamos a editar el archivo de Wordpress para configurar la base de datos creada anteriormente en MariaDB en el archvio "wp-config.php":
	$ sudo nano /var/www/html/wp-config.php
En este archivo conguramos las siguentes lineas:
	define( 'DB_NAME', 'oduran' );
	define( 'DB_USER', 'oduran' );
	define( 'DB_PASSWORD', '@Iloveecole42' );
Una vez configurado Wordpres ya podremos acceder des de nuestra navegador con la URL:
	"localhost:8080" 
Nos saldra la web de Wordpress y la configuramos
#Plugin Redis para Wordpress
El plugin de redis es un puente para conectar tu sitoo con un servidor Redis, el cual actua como una memoria cach'e de objetos. Evita que WordPress consulte a su base de datos para caergar la misma inforacion una y otra vez, Redis alamcena esos datos temporalemnte en la RAM del servidor para agilizar-lo.
Lo instalamos con el siguente comando:
	$ sudo apt install redis-server -y
	$ sudo apt install php-redis -y
lo activamos haciendo un restart al lighttpd asi efectuamos los canvios:
	$ sudo systemctl restart lighttpd
Vamos a configurar el redis para que se conecte al servidor, para eso tenemos que editar el archivo 'redis.conf':
	$ sudo nano /etc/redis/redis.conf
Vamos a anyadir las siguentes lineas:
	requirepass @Iloveecole42 //pass que usaremos para acceder a Redis
	save 900 1 // si pasan 900 segundos y cambia 1 clave redis hace una copia en el disco
	save 300 10 // si pasan 300 segundos y cambia 10 clave redis hace una copia en el disco
	save 60 10000 // si pasan 60 segundos y cambia 10000 clave redis hace una copia en el disco
En conjunto esto forma una politica de guardado automatico en la cache del servidor.
Vamos a crear la carpeta dodne redis guardara las copias y poner el directorio a su usuario para que no genere ningun conflicto:
	$ sudo mkdir -p /var/lib/redis
	$ sudo chown redis:redis /var/lib/redis
Reseteamos el servicido para efectuar los canvios:
	$ sudo systemctl restart redis-server
Configuramos WordPress para que se conecte con nuestros servidor de Redis:
	$ sudo nano /var/www/html/wp-config.php
Dentro de ese archivo ponemos la configuracion de Redis:
	define('WP_REDIS_HOST', '127.0.0.1');
	define('WP_REDIS_PASS', '@Iloveecole42');
Vamos a testear que el servidor este bien implementado:
	$ redis-cli //Conectar al servidor redis
Dentro del servidor enviamos:
	$ auth @Iloveecole42 //Nos tiene que devolver 'OK' para confirmar que todo va bien.
	$ ping // Le hacemos un ping para ver si devuelve 'PONG' para confirmar que recibe y envia bien el servidor.
A continuacion tenemos que ir a nuestro Wordpress, ir a la parte de plugins i instalar el plugin 'Redis Object Cache' una vez instalado, lo vamos a conectar, si lo hemos echo todo bien en la parte de 'Status' se tiene que poner 'Conectado' en verde y sabremos que ya esta funcionando.
	

