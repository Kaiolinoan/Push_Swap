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

void small_sort(t_stacks **stack_a, t_stacks **stack_b, int len)
{
    if (len == 5)
        sort_five();
    else if (len == 4)
    {
        pb(&stack_a, &stack_b);
        sort_three();
    }
    else if (len == 3)
        sort_three();
    else if (len == 2)
        ra(&stack_a);
    return ;
}

void prepare_three(t_stacks **stack_a)
{
    t_stacks *biggest;
    t_stacks *middle;
    t_stacks *smallest;

    normalize(stack_a);

    while ((*stack_a))
    {
        if ((*stack_a)->index == 0)
            smallest = (*stack_a);
        else if ((*stack_a)->index == 1)
            middle = (*stack_a);
        else if ((*stack_a)->index == 2);
            biggest = (*stack_a);
        (*stack_a) = (*stack_a)->next;
    }
}

void sort_three(t_stacks *biggest, t_stacks *middle, t_stacks *smallest)
{
    
}

