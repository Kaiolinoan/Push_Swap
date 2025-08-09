/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:50:00 by klino-an          #+#    #+#             */
/*   Updated: 2025/08/07 18:58:40 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stacks *find_related_index(t_stacks *stack_a, int value)
{
    t_stacks *node;
    normalize(&stack_a);
    while (stack_a)
    {
        if (stack_a->index ==  value)
            node = stack_a;
        stack_a = stack_a->next;
    }
    return (node);
}



static void sort_three(t_stacks **stack_a)
{
    t_stacks *biggest;

    biggest = find_related_index(*stack_a, 2);
    if (biggest->index == (*stack_a)->index)
        ra(stack_a);
    else if (biggest->index == (*stack_a)->next->index)
        rra(stack_a);
    if ((*stack_a)->index > (*stack_a)->next->index)
        sa(stack_a);
}

static void sort_four(t_stacks **stack_a, t_stacks **stack_b)
{
    t_stacks *smallest;
    t_stacks *last;

    smallest = find_related_index(*stack_a, 0);
    last = find_last_node(*stack_a);
    //while(smtg)
    if ((*stack_a)->index == smallest->index)
        pb(stack_a, stack_b);
    else if ((*stack_a)->next->index == smallest->index)
        sa(stack_a);
    else if (last->index == smallest->index ||
                last->previous->index == smallest->index)
        while ((*stack_a)->index != smallest->index)
            rra(stack_a);


    sort_three(stack_a);
}
void sort_five(t_stacks **stack_a, t_stacks **stack_b)
{
    (void)stack_a;
    (void)stack_b;
}
void small_sort(t_stacks **stack_a, t_stacks **stack_b, int len)
{
    if (len == 5)
        sort_five(stack_a, stack_b);
    else if (len == 4)
        sort_four(stack_a, stack_b);
    else if (len == 3)
        sort_three(stack_a);
    else if (len == 2)
        ra(stack_a);
}



