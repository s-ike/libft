#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\r'
		|| c == '\f' || c == '\t' || c == '\v');
}

int			ft_atoi(const char *str)
{
	unsigned int	num;
	int				sign;

	num = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = *str == '-' ? -1 : 1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		if (num)
			num *= 10;
		num += (*str++ - '0');
	}
	return (sign * num);
}