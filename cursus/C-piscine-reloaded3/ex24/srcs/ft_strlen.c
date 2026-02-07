/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:47:50 by oduran-m          #+#    #+#             */
/*   Updated: 2025/11/11 17:59:53 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = -1;
	while (str[++len])
	{
	}
	return (len);
}
/*
int	main(void)
{
	char	str[] = "Mang";
	int	len;

	len = ft_strlen(str);
	printf ("leng string: %d \n", len);
	return (0);
}*/
