#include "../includes/header.h"

void    ft_putstrb(char *str, int len)
{
    write(1, str, len);
}
