#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	while (set && *s1)
		if (ft_strchr(set, *s1))
		{
			s1++;
			len--;
		}
		else
			break ;
	while (set && 0 < len && ft_strchr(set, s1[len - 1]))
		len--;
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	return (str);
}