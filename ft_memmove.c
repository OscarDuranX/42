#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if(!dest && !src)
		return (0);
	i = 0;
	if((size_t)dest - (size_t)src < n)
	{
		i = n - 1;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			--i;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			++i;
		}
	}
	return (dest);
}

/*int	main(void)
{
	char test[21] = "hola si no no si xkn";
	char	*p = test + 5;
	char	*src = test + 17;
	
	printf("Antes de memmove, test es \"%s\"\n", test);
	ft_memmove( p, src, 2);
	printf("Despues de memmove, test es \"%s\"\n", test);
	return (0);
}*/
