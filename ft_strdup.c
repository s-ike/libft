#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	len;

	len = ft_strlen(s1);
	if (!(p = malloc((len + 1) * sizeof(char))))
		return (NULL);
	return (ft_memcpy(p, s1, len + 1));
}