/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:11:32 by oduran-m          #+#    #+#             */
/*   Updated: 2026/01/13 20:13:27 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
/*
int main()
{
   char cadena[] = "Erase un vez...";
   char *puntero; 
 
   puntero = (char *)ft_memchr( cadena, 'a', 5 );
   printf( "%s\n", cadena); 
   printf( "%s\n", puntero ); 
 
   return 0;
}*/
