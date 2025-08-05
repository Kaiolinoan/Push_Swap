/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:34:10 by klino-an          #+#    #+#             */
/*   Updated: 2025/08/05 16:34:28 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int stack_len(t_stacks *stack)
{
    size_t i;

    if (!stack)
        return (0);
    i = 0;
    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return (i);
}

t_stacks *create_node(int value)
{
    t_stacks *node;

    node = malloc(sizeof(t_stacks));
    node->value = value;
    node->next = NULL;
    node->previous = NULL;
    return (node);
}

t_stacks *find_last_node(t_stacks *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next != NULL)
        stack = stack->next;
    return (stack);       
}

static void create_stack(t_stacks **stack_a, int nbr)
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
        create_stack(stack_a, (int)nbr);
        i++;
        // while ((*stack_a))
        // {
        //     printf("%d\n", (*stack_a)->value);
        //     (*stack_a) = (*stack_a)->next;
        // }
    }
}