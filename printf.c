#include <unistd.h>
#include <stdio.h>
# include<stdarg.h>
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

void    ft_write_format(char format ,void *arg ,int *len)
{
    if (format == 's')
        ft_putstr((char *)arg , len);
    else if (format == 'd')
        ft_putnbr((long)arg , len);
    else if (format == 'x')
        ft_putbase((unsigned long)arg , len);

}
int ft_printf(char *str, ...)
{
    int len = 0;
    int i = 0;
    va_list lst;
    va_start(lst, str);
    while (str[i])
    {
        if(str[i] == '%')
        {
            i++;
            ft_write_format(str[i] , va_arg(lst, void *),&len);
        }
        else len += ft_putchar(str[i]);
    i++;
    }
    va_end(lst);
    return len;
}