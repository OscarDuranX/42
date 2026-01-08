#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if(size <= ft_strlen(dest))
		return (size + ft_strlen(dest);
	i = 0;
	j = ft_strlen(dest);
	while ( src[i] && j < (ft_strlen(src) - 1))
	{
		dest[j] = src[i];
		++j;
		++i;
	}	
	dest[j] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[i]));
}
