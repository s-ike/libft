#include "libft.h"

static size_t	cnt_words(char const *s, char c)
{
	size_t	cnt;

	if (*s == '\0')
		return (0);
	if (c == '\0' && *s)
		return (1);
	cnt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		while (*s && *s != c)
			s++;
		cnt++;
	}
	return (cnt);
}

static void		free_memories(char **strs, size_t size)
{
	while (size)
		free(strs[size--]);
}

static int		set_words(char **strs, char const *str, char c, size_t cnt)
{
	size_t	i;
	char	*start;
	char	*end;

	i = 0;
	while (i < cnt)
	{
		while (*str == c)
			str++;
		start = (char *)str;
		end = ft_strchr(str, c);
		strs[i] = !end ? ft_strdup(str) : ft_substr(start, 0, end - start);
		if (!strs[i])
		{
			if (0 < i)
				free_memories(strs, i - 1);
			return (0);
		}
		str += end ? end - start : 0;
		i++;
	}
	strs[i] = NULL;
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	cnt;

	if (!s)
		return (NULL);
	cnt = cnt_words(s, c);
	if (!(strs = (char **)malloc((cnt + 1) * sizeof(char *))))
		return (NULL);
	if (!set_words(strs, s, c, cnt))
	{
		free(strs);
		return (NULL);
	}
	return (strs);
}