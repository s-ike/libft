#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*c1;
	const char	*c2;

	c1 = s1;
	c2 = s2;
	while (n--)
	{
		if (*c1++ != *c2++)
			return (*(const unsigned char *)(c1 - 1)
				- *(const unsigned char *)(c2 - 1));
	}
	return (0);
}