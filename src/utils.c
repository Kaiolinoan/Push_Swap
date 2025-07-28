// CABECALHO
#include "push_swap.h"

long ft_atol(char *str)
{
    long nb;
    int sign;
    int i;

    sign = 1;
    nb = 0;
    i = 0;
    while ((str[i] >= 7 && str[i] <= 13 ) || str[i] == 32)
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return (sign * nb);
}