#include "libft.h"

static size_t	cnt_digit(double num)
{
	size_t	digit;

	digit = 0;
	if (num < 0)
		num *= -1;
	if (num < 1)
		return (1);
	while (1 <= num)
	{
		num = num / 10;
		digit++;
	}
	return (digit);
}

static void	itoa_recursion(char *dst, int i, unsigned int un)
{
	if (10 < un)
	{
		dst[i] = un % 10 + '0';
		itoa_recursion(dst, i - 1, un / 10);
	}
	else
		dst[i] = un + '0';
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	un;
	int				len;

	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		un = -n;
		len = cnt_digit(un) + 1;
	}
	else
	{
		un = n;
		len = cnt_digit(un);
	}
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
		*result = '-';
	itoa_recursion(result, len - 1, un);
	result[len] = '\0';
	return (result);
}
