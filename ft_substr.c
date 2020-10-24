#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (NULL);
	if ((s_len = ft_strlen(s)) <= start || len < 1)
		return ((char *)ft_calloc(1, sizeof(char)));
	len = (s_len < len) ? (s_len - start) : len;
	if (len == SIZE_MAX)
		return (NULL);
	if (!(sub = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	s += start;
	ft_strlcpy(sub, s, len + 1);
	return (sub);
}