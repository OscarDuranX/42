/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:45:25 by oduran-m          #+#    #+#             */
/*   Updated: 2026/01/13 19:04:58 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (*s1 != '\0' && *s2 != '\0' && i < n)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
/*
int	main()
{
   char s1[9] = "artesano";
   char s2[8] = "aritista";
   int i;

   printf( "s1=%s\t", s1 );
   printf( "s2=%s\n", s2 );

   i = ft_strncmp( s1, s2, 3 );
   printf( "Las 3 primeras letras de s1 son " );
   if( i < 0 )  printf( "menores que" );
   else if( i > 0 )  printf( "mayores que" );
   else  printf( "iguales a" );
   printf( " s2\n" );

   return 0;
}*/
