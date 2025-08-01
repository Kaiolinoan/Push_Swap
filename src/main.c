//CABEÇALHO
#include "../push_swap.h"



int main(int argc, char**argv)
{
    t_stacks *stack_a;
    // t_stacks *stack_b;

    stack_a = NULL;
    // stack_b = NULL;
    if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
        return (0);
    else if (argc == 2)
        argv = ft_split(argv[1], 32);
    start_stacks(argv, &stack_a);
    while (stack_a)
    {
        printf("%d", stack_a->value);
        stack_a = stack_a->next;
    }
}