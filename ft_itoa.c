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

char		*ft_itoa(int n)
{
	char			*result;
	unsigned int	un;
	int				len;

	un = n < 0 ? -(n) : n;
	len = n < 0 ? cnt_digit(un) + 1 : cnt_digit(un);
	if (!(result = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	result[len] = '\0';
	if (n == 0)
		result[--len] = '0';
	else
	{
		while (0 < un)
		{
			result[--len] = un % 10 + '0';
			un /= 10;
		}
		if (n < 0 && 0 < len)
			result[--len] = '-';
	}
	return (result);
}
