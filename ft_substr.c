#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (NULL);
	if ((s_len = ft_strlen(s)) <= start || !len)
		return (ft_calloc(1, sizeof(char)));
	if (s_len < len + start)
		len = s_len - start;
	if (!(sub = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	s += start;
	ft_strlcpy(sub, s, len + 1);
	return (sub);
}