#include "libft.h"
#include "ft_printf.h"

int     ft_ptrlen(uintptr_t num)
{
    int     len;

    len = 0;
    while (num != 0)
    {
        len ++;
        num = num / 16;
    }
    return (len);
}

void    ft_putptr(uintptr_t num)
{
    if (num >= 16)
    {
        ft_putptr(num / 16);
        ft_putptr(num % 16);
    }
    else
    {
        if (num <= 9)
            ft_putchar_fd((num + '0'), 1);
        else
        {
           ft_putchar_fd((num - 10 + 'a'), 1);
        }
    }
}

int     ft_printptr(unsigned long long ptr)
{
        int     plen;

        plen = 0;
        plen += write(1, "0x", 2);
        if (ptr == 0)
            plen += write(1, "0", 1);
        else
        {
            ft_putptr(ptr);
            plen += ft_ptrlen(ptr);
        }
        return (plen);
}
