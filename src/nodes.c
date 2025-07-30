//cabecalho

#include "../push_swap.h"

t_stacks *find_last_node(t_stacks *stack)
{
    while (stack->next != NULL)
        stack = stack->next;
    return (stack);       
}

static void create_nodes(t_stacks **stack_a, int nbr)
{
    t_stacks *node;
    t_stacks *last_node;

    if (!stack_a)
        return ;

    node = malloc(sizeof(t_stacks));
    if (!node)
        return ;
    node->value = nbr;
    node->next = NULL;
    if (!(*stack_a))
    {
        node->previous = NULL;
        (*stack_a) = node;
    }
    else
    {
        last_node = find_last_node(*stack_a);
        last_node->next = node;
        node->previous = last_node;
    }
}

void start_stacks(char **argv, t_stacks **stack_a)
{
    long nbr;
    size_t i;
    i = 0;
    
    while (argv[i])
    {
        nbr = ft_atol(argv[i]);
        if (nbr < INT_MIN || nbr > INT_MAX)
            print_error("Numbers are not in the int range\n");
        if (check_doubles(argv, nbr) == -1)
            print_error("There are duplicate numbers\n");
        if (check_input(argv))
            print_error("The input is not valid\n");
        create_nodes(stack_a, (int)nbr);
        i++;
        while ((*stack_a))
        {
            ft_printf("%d\n", (*stack_a)->value);
            (*stack_a) = (*stack_a)->next;
        }
    }
}