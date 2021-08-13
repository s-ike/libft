/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:12:24 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/14 03:12:25 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
