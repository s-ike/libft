#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (ft_strdup(""));
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(str, s1, s1_len + 1);
	ft_memcpy(str + s1_len, s2, s2_len + 1);
	return (str);
}