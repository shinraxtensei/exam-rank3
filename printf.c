#include <unistd.h>
#include <stdio.h>

int ft_putchar(char c)
{
    write(1,&c,1);
    return 1;
}

void ft_putstr(char *str, int *len)
{
    int i = 0;
    while (*str)
        *len += ft_putchar(*str++);
}

void	ft_putnbr(int n , int *len)
{
	long	i;

	i = n;
	if (i < 0)
	{
		*len += ft_putchar('-');
		i = i * -1;
	}
	if ((i >= 0) && (i <= 9))
	{
	    *len +=	ft_putchar((i + '0'));
	}
	if (i > 9)
	{
		ft_putnbr((i / 10), len);
		ft_putnbr((i % 10), len);
	}
}

void	ft_putbase(unsigned long hexa, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (hexa <= 15)
		(*len) += ft_putchar(base[hexa]);
	if (hexa > 15)
	{
		ft_putbase(hexa / 16, len);
		ft_putbase(hexa % 16, len);
	}
}
