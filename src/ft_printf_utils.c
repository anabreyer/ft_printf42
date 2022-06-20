#include "libft.h"
#include "ft_printf.h"

void    ft_putstr(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        write(1, &str, 1);
        i++;
    }
}

int     ft_printstr(char *str)
{
    int     i;

    i = 0;
    if (str == NULL)
    {
        ft_putstr("(null)");
        return (6);
    }
    while (str[i])
    {
        write(1, &str, 1);
        i++;
    }
    return (i);
}

int    ft_printnbr(int n)
{
    int     len;
    char    *num;

    len = 0;
    num = ft_itoa(n);
    len = ft_printstr(num);
    free (num);
    return (len);
}

int     ft_printper(void)
{
    write(1, "%", 1);
    return (1);
}