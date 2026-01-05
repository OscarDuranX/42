#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if(!dest && !src)
		return (0);
	i = -1;
	while (++i < n)
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}
/*
int	main(void)
{
	int n = 5;
	int p[] = {10, 20, 55, 33, 69};
	int q[n];
	
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);
	ft_memcpy(q, p, n * sizeof(int));
	printf("\n");
	for (int i = 0; i< n; i++)
		printf("%d ", q[i]);
}*/
