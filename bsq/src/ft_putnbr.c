#include "../includes/header.h"

void    ft_putnbr(int nb)
{
    if (nb < 0)
    {
        ft_putchar('-');
        if (nb == -2147483648)
        {
            ft_putchar('2');
            nb = -147483648;
        }
        nb *= -1;
    }
    if (nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar(nb % 10 + 48);
}
