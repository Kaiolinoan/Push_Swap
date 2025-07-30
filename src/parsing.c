//cabecalho

#include "../push_swap.h"

int check_input(char **argv)
{
    size_t i;
    i = 0;
    while (argv[i])
    {
        if (ft_isdigit(argv[i][0]) == 0)
            if(argv[i][0] != '-' && ft_isdigit(argv[i][1]) == 0)
                return (-1);
        i++;
    }
    return (0);
}

int  check_doubles(char **argv, int nbr)
{
    size_t i;
    int temp;
    int count;
    
    i = 0;
    count = 0;
    while (argv[i])
    {
        temp = atol(argv[i++]);
        if (temp == nbr)
            count++;
        if(count >= 2)
            return (-1);
    }
    return (0);
}
void print_error(char *str)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(str, 2);
    exit(-1);
}


