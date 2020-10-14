#include "libft.h"

static void	recursive_putnbr(unsigned int n, int fd)
{
	if (n / 10 == 0)
	{
		ft_putchar_fd(n + '0', fd);
		return ;
	}
	recursive_putnbr(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	if (n < 0)
		ft_putchar_fd('-', fd);
	un = n < 0 ? -(n) : n;
	recursive_putnbr(un, fd);
}