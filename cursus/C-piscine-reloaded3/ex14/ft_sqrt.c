/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:24:51 by oduran-m          #+#    #+#             */
/*   Updated: 2025/12/10 17:49:32 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = 0;
	while (tmp < nb)
	{
		tmp = i * i;
		i++;
	}
	if (tmp == nb)
		return (i - 1);
	else
		return (0);
}

/*int	main(void)
{
	printf("Resultado: %d\n", ft_sqrt(82));
	return (0);
}*/
