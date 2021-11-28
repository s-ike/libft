/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:12:45 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/28 21:27:11 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cnt_words(char const *str, char c)
{
	size_t	cnt;

	if (*str == '\0')
		return (0);
	if (c == '\0')
		return (1);
	cnt = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (!*str)
			break ;
		while (*str && *str != c)
			str++;
		cnt++;
	}
	return (cnt);
}

static int	free_memories_in_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	return (0);
}

static int	set_words(char **strs, char const *str, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (1)
	{
		while (*str && *str == c)
			str++;
		if (!*str)
			break ;
		len = 0;
		while (str[len] && str[len] != c)
			len++;
		strs[i] = ft_substr(str, 0, len);
		if (!strs[i++])
			return (free_memories_in_strs(strs));
		str += len;
	}
	strs[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = (char **)malloc((cnt_words(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	if (!set_words(strs, s, c))
	{
		free(strs);
		strs = NULL;
		return (NULL);
	}
	return (strs);
}
