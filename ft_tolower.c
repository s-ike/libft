int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c += ('a' - 'A');
	return (c);
}