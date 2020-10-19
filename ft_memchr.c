#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = s;
	while (0 < n--)
		if (*ptr++ == (unsigned char)c)
			return ((void *)(ptr - 1));
	return (NULL);
}