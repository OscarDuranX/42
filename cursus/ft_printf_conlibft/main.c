/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduran-m <oduran-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:05:12 by oduran-m          #+#    #+#             */
/*   Updated: 2026/02/09 20:33:28 by oduran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int	main(int argc, char **argv)
{
	int	ret_ft;
	int	ret_pf;

	ft_printf("+============================+\n");
	ft_printf("| FT_PRINTF TEST BY agarcia2 |\n");
	ft_printf("+============================+\n\n");

	if (argc != 2)
	{
		ft_printf("Usage: ./ft_printf <string>\n");
		return (1);
	}

	ft_printf("+===========+\n");
	ft_printf("| CHAR TEST |\n");
	ft_printf("+===========+\n");
	ret_ft = ft_printf("ft_printf: %c\n", 'A');
	ret_pf = printf("printf   : %c\n", 'A');
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);

	ft_printf("+=============+\n");
	ft_printf("| STRING TEST |\n");
	ft_printf("+=============+\n");
	ret_ft = ft_printf("ft_printf: %s\n", argv[1]);
	ret_pf = printf("printf   : %s\n", argv[1]);
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);

	ret_ft = ft_printf("ft_printf NULL: %s\n", (char *)NULL);
	ret_pf = printf("printf   NULL: %s\n", (char *)NULL);
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);
	
	ft_printf("+=============+\n");
	ft_printf("| INT / DIGIT |\n");
	ft_printf("+=============+\n");
	ret_ft = ft_printf("ft_printf: %d %i\n", INT_MAX, INT_MIN);
	ret_pf = printf("printf   : %d %li\n", INT_MAX, INT_MIN);
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);

	ft_printf("+===============+\n");
	ft_printf("| UNSIGNED TEST |\n");
	ft_printf("+===============+\n");
	ret_ft = ft_printf("ft_printf: %u\n", -1);
	ret_pf = printf("printf   : %u\n", -1);
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);
	
	ft_printf("+==========+\n");
	ft_printf("| HEX TEST |\n");
	ft_printf("+==========+\n");
	ret_ft = ft_printf("ft_printf: %x %X\n", 3735928559u, 3735928559u);
	ret_pf = printf("printf   : %x %X\n", 3735928559u, 3735928559u);
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);
	
	ft_printf("+==============+\n");
	ft_printf("| POINTER TEST |\n");
	ft_printf("+==============+\n");
	ret_ft = ft_printf("ft_printf: %p\n", argv);
	ret_pf = printf("printf   : %p\n", argv);
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);

	ret_ft = ft_printf("ft_printf NULL: %p\n", NULL);
	ret_pf =    printf("printf    NULL: %p\n", NULL);
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);

	ft_printf("+==============+\n");
	ft_printf("| PERCENT TEST |\n");
	ft_printf("+==============+\n");
	ret_ft = ft_printf("ft_printf: %%%\n");
	ret_pf = printf("printf   : %%%");
	ft_printf("ret ft: %d | ret printf: %d\n\n", ret_ft, ret_pf);

	ft_printf("+====================+\n");
	ft_printf("| END OF TEST SUITE |\n");
	ft_printf("+====================+\n");
	
	return (0);
}
