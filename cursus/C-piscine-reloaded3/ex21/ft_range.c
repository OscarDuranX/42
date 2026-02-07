/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:16:47 by oduran-m          #+#    #+#             */
/*   Updated: 2025/12/18 21:55:39 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	leng;
	int	*tmp;
	int	i;
	int	j;

	if (min >= max)
		return (NULL);
	leng = max - min;
	tmp = (int *)malloc(sizeof(int) * (leng + 1));
	if (!tmp)
		return (NULL);
	i = -1;
	j = min;
	while (++i < leng)
	{
		tmp[i] = j;
		j++;
	}
	return (tmp);
}
/*int	main(void)
{
	 int	*i;

	 i = ft_range(2, 7);
	 free (i);
	 return (0);
}*/
