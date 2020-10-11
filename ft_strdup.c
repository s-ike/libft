#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	len;

	len = ft_strlen(s1);
	if (!(cpy = malloc((len + 1) * sizeof(char))))
		return (NULL);
	return (ft_memcpy(cpy, s1, len + 1));
}