//CABEÇALHO
#include "../push_swap.h"

int check_input(char **argv)
{
    size_t i;
    i = 0;
    printf("argv:\n");
    while(argv[i])
    {
        printf("[%ld]%s\n", i,argv[i]);
        i++;
    }
    printf("fim argv\n");
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

void start_stacks(char **argv)
{
   /*  t_stacks *stack_a;
    t_stacks *stack_b;
    
    stack_a = NULL;
    stack_b = NULL; */
    int nbr;
    size_t i;
    i = 0;
    
    while (argv[i])
    {
        nbr = ft_atol(argv[i]);
        if (nbr <= INT_MIN || nbr >= INT_MAX)
            print_error("Numbers are not in the int range\n");
        if (check_doubles(argv, nbr) == -1)
            print_error("There are duplicate numbers\n");
        if (check_input(argv))
            print_error("The input is not valid\n");
        i++;
    }
}

int main(int argc, char**argv)
{
    if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
        return (0);
    else if (argc == 2)
        argv = ft_split(argv[1], 32);
    start_stacks(argv);
}