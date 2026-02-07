/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 03:28:05 by oduran-m          #+#    #+#             */
/*   Updated: 2026/02/04 22:08:37 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void	pruebaparte1(void)
{	
	printf("Funcion ft_isalpha:\n");
	printf("Res ft: a-> %d   Res ftreal: a-> %d\n", ft_isalpha('a'), isalpha('a'));
	printf("Res ft: Z-> %d   Res ftreal: Z-> %d\n", ft_isalpha('Z'), isalpha('Z'));
	printf("Res ft: 2-> %d   Res ftreal: 2-> %d\n\n", ft_isalpha('2'), isalpha('2'));

	printf("Funcion ft_isdigit:\n");
	printf("Res ft: 7-> %d   Res ftreal: 7-> %d\n", ft_isdigit('7'), isdigit('7'));
	printf("Res ft: a-> %d   Res ftreal: a-> %d\n", ft_isdigit('a'), isdigit('a'));
	printf("Res ft: 0-> %d   Res ftreal: 0-> %d\n\n", ft_isdigit('0'), isdigit('0'));

	printf("Funcion ft_isalnum:\n");
	printf("Res ft: a-> %d   Res ftreal: a-> %d\n", ft_isalnum('a'), isalnum('a'));
	printf("Res ft: 7-> %d   Res ftreal: 7-> %d\n", ft_isalnum('7'), isalnum('7'));
	printf("Res ft: =-> %d   Res ftreal: =-> %d\n\n", ft_isalnum('='), isalnum('='));

	printf("Funcion ft_isascii:\n");
	printf("Res ft: =-> %d   Res ftreal: =-> %d\n", ft_isascii('='), isascii('='));
	printf("Res ft: *-> %d   Res ftreal: *-> %d\n", ft_isascii('*'), isascii('*'));
	printf("Res ft: -1-> %d   Res ftreal: -1-> %d\n\n", ft_isascii(-1), isascii(-1));

	printf("Funcion ft_isprint:\n");
	printf("Res ft: *-> %d   Res ftreal: *-> %d\n", ft_isprint('*'), isprint('*'));
	printf("Res ft: NUl-> %d   Res ftreal: NUL-> %d\n", ft_isprint(0), isprint(0));
	printf("Res ft: DEL-> %d   Res ftreal: DEL-> %d\n\n", ft_isprint(127), isprint(127));

	printf("Funcion ft_strlen:\n");
	printf("Res ft: holas-> %lu   Res ftreal:  %lu\n", ft_strlen("holas"), strlen("holas"));
	printf("Res ft: ssddeee-> %lu   Res ftreal:  %lu\n", ft_strlen("ssddeee"), strlen("ssddeee"));
	printf("Res ft: -> %lu   Res ftreal: %lu\n\n", ft_strlen(""), strlen(""));

	printf("Funcion ft_memset:\n");
	char	str[20] = "1111111111";
	int		d[5] = {1, 2, 3, 4, 5};
	str[10] = '\0';
	printf("Cadena char str antes %s\n", str);
	printf("Cadena int d antes %d - %d - %d - %d - %d\n", d[0], d[1], d[2], d[3], d[4]);
	ft_memset(str, '*', 10);
	ft_memset(d, 0, sizeof(d));
	printf("Cadena char str despues de ft_memset(str, '*', 5) =  %s:\n", str);
	printf("Cadena int d despues de ft_memset(d, 0, sizeof(d)) = %d - %d - %d - %d - %d \n\n", d[0], d[1], d[2], d[3], d[4]);

	printf("Funcion ft_bzero:\n");
	char buffer[20] = "Hola Mundo";
    int numeros[5] = {1, 2, 3, 4, 5};
    printf("Antes de ft_bzero (char): %s\n", buffer);
    ft_bzero(buffer, sizeof(buffer));
    printf("Despues de ft_bzero (char): '%s' (vacio)\n", buffer);
    printf("Antes de ft_bzero (int): %d, %d, ...\n", numeros[0], numeros[1]);
    ft_bzero(numeros, sizeof(numeros));
    printf("Despues de ft_bzero (int): %d, %d, ... (ambos 0)\n", numeros[0], numeros[1]);
	
	printf("Funcion ft_memcpy:\n");
	char src[] = "Hola Mundo";
    char dest[] = "Copia 11 bytes";
    printf("src: %s\n", src);
    printf("Destino antes: %s\n", dest);
    ft_memcpy(dest, src, sizeof(src));
    printf("Destino despues: %s\n\n", dest);

	printf("Funcion ft_memmove:\n");
	char data[] = "ABCDEFGHIJ";
    printf("Antes de ft_memmove(data + 2, data, 5): %s\n", data); 
	ft_memmove(data + 2, data, 5);
    printf("Resultado: %s\n\n", data); 
   
	printf("Funcion ft_strlcpy:\n");
	char *origen = "Hola, este es un texto muy largo";
    char destino[10]; // Búfer pequeño (solo 10 bytes)

    // Copia de forma segura. El tercer parámetro es el TAMAÑO TOTAL del búfer.
    size_t long_total = ft_strlcpy(destino, origen, sizeof(destino));

    printf("Cadena original: '%s'\n", origen);
    printf("Cadena copiada (truncada): '%s'\n", destino);
    printf("Longitud del origen intentada: %zu\n", long_total);
    printf("Tamaño del búfer destino: %zu\n", sizeof(destino));
    if (long_total >= sizeof(destino)) {
        printf("ADVERTENCIA: La cadena fue truncada.\n\n");
    }

	printf("Funcion ft_strlcat:\n");
	char destino2[20] = "Hola, ";
    char *origen2 = "este es un mensaje muy largo";
    printf("Cadena origen: '%s'\n", origen2);
    size_t total_intentado = ft_strlcat(destino2, origen2, sizeof(destino2));
    printf("Cadena final: '%s'\n", destino2);
    printf("Longitud que se intentó crear: %zu\n", total_intentado);
    if (total_intentado >= sizeof(destino2)) {
        printf("Aviso: La cadena fue truncada porque el búfer es pequeño.\n\n");
    }

	printf("Funcion ft_toupper:\n");
	printf("Res ft: a-> %c   Res ftreal: a-> %c\n", ft_toupper('a'), toupper('a'));
	printf("Res ft: G-> %c   Res ftreal: G-> %c\n", ft_toupper('G'), toupper('G'));
	printf("Res ft: h-> %c   Res ftreal: h-> %c\n\n", ft_toupper('h'), toupper('h'));

	printf("Funcion ft_tolower:\n");
	printf("Res ft: G-> %c   Res ftreal: G-> %c\n", ft_tolower('G'), tolower('G'));
	printf("Res ft: s-> %c   Res ftreal: s-> %c\n", ft_tolower('s'), tolower('s'));
	printf("Res ft: B-> %c   Res ftreal: B-> %c\n\n", ft_tolower('B'), tolower('B'));
	
	printf("Funcion ft_strchr:\n");
	char *frase = "Hola Mundo desde C";
    char buscar = 'M';
    char *resultado;
    printf("Frase: '%s'\n", frase);
    resultado = ft_strchr(frase, buscar);
    if (resultado != NULL) {
        printf("Carácter '%c' encontrado.\n", buscar);
        printf("Texto desde la aparición: '%s'\n", resultado);
        printf("Posición (índice): %ld\n\n", resultado - frase);
    } else {
        printf("El carácter '%c' no se encuentra en la cadena.\n\n", buscar);
    }

	printf("Funcion ft_strrchr:\n");
	char *archivo = "imagen.de.respaldo.jpg";
    char buscar2 = '.';
    char *ultimo_punto;
    ultimo_punto = ft_strrchr(archivo, buscar2);
    if (ultimo_punto != NULL) 
		printf("Se encontro la extension: %s\n\n", ultimo_punto);
    else 
		 printf("El archivo no tiene extension.\n\n");

	printf("Funcion ft_strncmp:\n");
	char *s1 = "manzana roja";
    char *s2 = "manzana verde";
    int result;
	result = ft_strncmp(s1, s2, 7);
    if (result == 0)
        printf("Las cadenas coinciden en los primeros 7 caracteres.\n\n");
	else
        printf("Las cadenas son diferentes desde el principio.\n\n");

	printf("Funcion ft_memchr:\n");
	char mensaje1[] = "Datos\0Secretos"; // Contiene un nulo en medio
    char buscar1 = 'S';
    char *resultado1;
    resultado1 = (char *)ft_memchr(mensaje1, buscar1, 14);
    if (resultado1 != NULL) {
        printf("Carácter '%c' encontrado en la posición: %ld\n", buscar1, resultado1 - mensaje1);
        printf("Texto desde ahí: %s\n\n", resultado1);
    } else
		printf("Carácter no encontrado.\n\n");

	printf("Funcion ft_memcmp:\n");
	int arr1[] = {10, 20, 30, 40};
    int arr2[] = {10, 20, 30, 40};
    int arr3[] = {10, 20, 55, 40};
    if (ft_memcmp(arr1, arr2, sizeof(arr1)) == 0)
		printf("arr1 y arr2 son exactamente iguales.\n\n");
    if (ft_memcmp(arr1, arr3, sizeof(arr1)) != 0) 
		printf("arr1 y arr3 son diferentes.\n\n");

	printf("Funcion ft_strnstr:\n");
	char *pajar = "Servidor: Ejecutando comando... OK";
    char *aguja = "Ejecutando";
    char *result3;
	result3 =  ft_strnstr(pajar, aguja, 20);
	if (result3)
		printf("Encontrado: '%s'\n\n", result3);
	else 
		printf("No se encontró '%s' en el rango especificado.\n\n", aguja);

	printf("Funcion ft_atoi:\n");
	printf("Res ft: 12-> %d   Res ftreal: 12-> %d\n", ft_atoi("12"), atoi("12"));
	printf("Res ft: -15-> %d   Res ftreal: -15-> %d\n", ft_atoi("-15"), atoi("-15"));
	printf("Res ft: 0251-> %d   Res ftreal: 0251-> %d\n\n", ft_atoi("0251"), atoi("0251"));
	
	printf("Funcion ft_calloc:\n");
	int *array4;
    int n = 5;
    array4 = (int *)ft_calloc(n, sizeof(int));

    if (array4 == NULL) 
        printf("Error: No se pudo asignar memoria.\n");
    printf("Contenido inicial (siempre 0):\n\n");
	for (int i = 0; i < n; i++)
		printf("Elemento %d: %d\n", i, array4[i]);
    free(array4);
	printf("\n");

	printf("Funcion ft_strdup:\n");
	const char *original3 = "Texto base";
    char *copia3;
    copia3 = ft_strdup(original3);
    if (copia3 == NULL)
        fprintf(stderr, "Error de memoria\n");
    copia3[0] = 'B';
    printf("Original: %s\n", original3); // "Texto base"
    printf("Copia:    %s\n", copia3);    // "Bexto base"
    free(copia3);
}

char    upper_lower(unsigned int i, char c)
{
    if (ft_isalpha(c))
    {
        if (i % 2 == 0)
            return (ft_toupper(c));
        else
            return (ft_tolower(c));
    }
    return (c);
}
void    upper_lower2(unsigned int i, char *c)
{
    if (ft_isalpha(*c))
    {
        if (i % 2 == 0)
            *c = ft_toupper(*c);
        else
            *c = ft_tolower(*c);
    }
}
char    mask_even(unsigned int i, char c)
{
    if (ft_isalpha(c) && i % 2 == 0)
        return ('*');
    return (c);
}
void    mask_odd(unsigned int i, char *c)
{
    if (ft_isalpha(*c) && i % 2 != 0)
        *c = '#';
}
void	pruebaparte2(void)
{
	printf("Funcion ft_substr:\n");
	char *texto1 = "Lenguaje de programación C";
    char *sub1 = ft_substr(texto1, 12, 12);
    printf("cadena: %s\n", texto1);
    if (sub1 != NULL) {
        printf("Subcadena: %s\n\n", sub1);
        free(sub1);
    }
	printf("Funcion ft_strjoin:\n");
	char	*s1 = "holass";
	char	*s2 = "Bon dia";
    char *resultado;
	resultado = ft_strjoin(s1,s2);

    if (resultado) {
        printf("Resultado: '%s'\n\n", resultado);
        free(resultado); // ¡Memoria dinámica!
    }

	printf("Funcion ft_strtrim:\n");
	char texto[] = "   Hola Mundo con espacios   ";
    printf("Antes: '[%s]'\n", texto);
    char *limpio = ft_strtrim(texto, " ");
    printf("Después: '[%s]'\n\n", limpio);
	
	printf("Funcion ft_split:\n");
	char	*splittest ="hola,si,no,porque,porsi";
	char	**resul;
	printf("test split: %s\n",splittest);
	resul = ft_split(splittest, ',');
	while (*resul)
	{
		printf("Resultado split: %s\n", *resul);
		resul++;
	}
	printf("\n");

	printf("Funcion ft_itoa:\n");
	printf("Res ft: 12-> %s\n", ft_itoa(12));
	printf("Res ft: -25412-> %s\n", ft_itoa(-25412));
	printf("Res ft: 393999987-> %s\n", ft_itoa(393999987));
	
	printf("Funcion ft_strmapi:\n");
    char *result;

    printf("===== Test 1: upper/lower alternado =====\n");
    result = ft_strmapi("Hola MuNdO 42!", upper_lower);
    printf("Resultado: %s\n\n", result);
    free(result);

    printf("===== Test 2: ocultar letras en índices pares =====\n");
    result = ft_strmapi("libft es clave", mask_even);
    printf("Resultado: %s\n\n", result);
    free(result);

    printf("===== Test 3: string vacío =====\n");
    result = ft_strmapi("", upper_lower);
    printf("Resultado: \"%s\"\n\n", result);
    free(result);

	printf("Funcion ft_striteri:\n");
	char str1[] = "HoLa MuNdO 42!";
    char str2[] = "libft es clave";
    char str3[] = "";

    printf("===== Test 1: upper/lower alternado =====\n");
    printf("Antes : %s\n", str1);
    ft_striteri(str1, upper_lower2);
    printf("Después: %s\n\n", str1);

    printf("===== Test 2: ocultar letras en índices impares =====\n");
    printf("Antes : %s\n", str2);
    ft_striteri(str2, mask_odd);
    printf("Después: %s\n\n", str2);

    printf("===== Test 3: string vacío =====\n");
    printf("Antes : \"%s\"\n", str3);
    ft_striteri(str3, upper_lower2);
    printf("Después: \"%s\"\n\n", str3);
	
	printf("Funcion ft_putchar_fd:\n");
	printf("Imprimido con ft_putchar_fd:\n");
	ft_putchar_fd('h', 1);
	ft_putchar_fd('o', 1);
	ft_putchar_fd('l', 1);
	ft_putchar_fd('a', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('\n', 1);
	
	printf("Funcion ft_putstr_fd:\n");
	printf("Imprimido con ft_putstr_fd:\n");
	ft_putstr_fd("Hola \n\n", 1);
	
	printf("Funcion ft_putendl_fd:\n");
	printf("Imprimido con ft_putendl_fd:\n");
	ft_putendl_fd("Hola \n", 1);
	
	printf("Funcion ft_putnbr_fd:\n");
	printf("Imprimido con ft_putnbr_fd:\n");
	ft_putnbr_fd(1011, 1);
	ft_putchar_fd('\n', 1);
}

void del_content(void *content)
{
    free(content);
}
void    print_content(void *content)
{
    printf("%s\n", (char *)content);
}
void *dup_str(void *content)
{
    return ft_strdup((char *)content);
}
void	pruebaparte3(void)
{
	printf("Funcion ft_lstnew:\n");
	t_list  *node;
    char    *str = malloc(11);
	strcpy(str, "Hola libft");
    node = ft_lstnew(str);
    printf("content: %s\n", (char *)node->content);
    printf("next   : %p\n\n", (void *)node->next);

	printf("Funcion ft_lstadd_front:\n");
	t_list *new_node;
	char	*str2 = malloc(8);
	strcpy(str2, "Primero");
	new_node = ft_lstnew(str2);
    ft_lstadd_front(&node, new_node);
    printf("Primer nodo : %s\n", (char *)node->content);
    printf("Siguiente   : %s\n\n", (char *)node->next->content);

	printf("Funcion ft_lstsize:\n");
	int	size;
	size = ft_lstsize(node);
    printf("Size de nodo : %d\n\n",size);	
	
	printf("Funcion ft_lstlast:\n");
	t_list  *last;
	last = ft_lstlast(node);
	printf("Último nodo: %s\n\n", (char *)last->content);

	printf("Funcion ft_lstadd_back:\n");
	char	*str3 = malloc(8);
	strcpy(str3, "Tercero");
	new_node = ft_lstnew(str3);
	ft_lstadd_back(&node, new_node);
	last = ft_lstlast(node);
	if (last)
		printf("Último nodo: %s\n\n", (char *)last->content);

	printf("Funcion ft_lstdelone:\n");
	t_list *to_delete = node->next;
	node->next = node->next->next;
	ft_lstdelone(to_delete, del_content);
    last = ft_lstlast(node);
    printf("Último nodo ahora: %s\n\n", (char *)last->content);
    printf("Primer nodo : %s\n", (char *)node->content);
    printf("Siguiente   : %s\n\n", (char *)node->next->content);
	
	printf("Funcion ft_lstclear:\n");
	ft_lstclear(&node, del_content);
    printf("Lista vacía: %p\n\n", (void *)node);
	
	printf("Funcion ft_lstiter:\n");
	ft_lstadd_back(&node, ft_lstnew(strdup("Primero")));
    ft_lstadd_back(&node, ft_lstnew(strdup("Segundo")));
    ft_lstadd_back(&node, ft_lstnew(strdup("Tercero")));
    printf("Contenido de la lista:\n");
    ft_lstiter(node, print_content);
    ft_lstclear(&node, del_content);
    printf("\n\n");
	
	printf("Funcion ft_lstmap:\n");
	t_list *list = NULL;
    t_list *mapped;
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Uno")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Dos")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Tres")));
    mapped = ft_lstmap(list, dup_str, del_content);
    printf("Lista original:\n");
    ft_lstiter(list, print_content);
    printf("\nLista mapeada:\n");
    ft_lstiter(mapped, print_content);
    ft_lstclear(&list, del_content);
    ft_lstclear(&mapped, del_content);
}

int	main(void)
{
	
	printf("1- Parte 1 pruebas:\n\n");
	pruebaparte1();	
	printf("\n\n2- Parte 2 pruebas:\n\n");
	pruebaparte2();
	printf("\n\n3- Parte 3 pruebas:\n\n");
	pruebaparte3();
return (0);
}
