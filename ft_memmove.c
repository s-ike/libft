#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	d = dst;
	s = src;
	while (len--)
		d[len] = s[len];
	return (dst);
}