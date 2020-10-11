#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (!n || dst == src)
		return (dst);
	while (n--)
		*d++ = *s++;
	return (dst);
}