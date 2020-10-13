#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	char	byte;

	if ((unsigned)c < 0x80)
		write(fd, &c, sizeof(char));
	else
	{
		byte = (c & 0b11111111) >> 6 | 0b11000000;
		write(fd, &byte, 1);
		byte = (c & 0b00111111) | 0b10000000;
		write(fd, &byte, 1);
	}
}