/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:06:15 by oduran-m          #+#    #+#             */
/*   Updated: 2026/01/24 18:24:59 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strdup(const char *s)
{
	char	*tmp_str;
	size_t	i;

	if (!s)
		return (NULL);
	tmp_str = (char *)malloc (sizeof(*s) * (ft_strlen (s1) + 1));
	if (!tmp_str)
		return (NULL);
	i = -1;
	while (s[++i])
		tmp_str[i] = s[i];
	tmp_str[i] = '\0';
	return (tmp_str);
}
/*
int main() {
    char *original = "Hola Mundo";
    char *copia;

    // Duplicar la cadena
    copia = ft_strdup(original);

    if (copia != NULL) {
        printf("Original: %s\n", original);
        printf("Copia: %s\n", copia);

        // ¡IMPORTANTE! Liberar la memoria cuando ya no se necesite
        free(copia); 
    }

    return 0;
}*/
