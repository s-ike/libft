#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	offset;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len--)
	{
		offset = 0;
		while (*(haystack + offset) == *(needle + offset)
			&& *(needle + offset) && 0 < len + 1 - offset)
			offset++;
		if (*(needle + offset) == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}