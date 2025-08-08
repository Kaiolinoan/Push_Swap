/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:34:06 by klino-an          #+#    #+#             */
/*   Updated: 2025/08/06 19:08:10 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pb(t_stacks **stack_a, t_stacks **stack_b)
{
    t_stacks *temp;

    if (!(*stack_a))
        return ;

    temp = (*stack_a);
    temp->previous = NULL;
    (*stack_a) = (*stack_a)->next;
    if (*stack_a)
        (*stack_a)->previous = NULL;

    if (!(*stack_b))
    {
        (*stack_b) = temp;
        (*stack_b)->next = NULL;
    }
    else 
    {
        temp->next = (*stack_b);
        (*stack_b)->previous = temp;
        (*stack_b) = temp;
    }
    write(1, "pb\n", 3);
}

void    pa(t_stacks **stack_a, t_stacks **stack_b)
{
    t_stacks *temp;

    if (!(*stack_b))
        return ;

    temp = (*stack_b);
    temp->previous = NULL;
    (*stack_b) = (*stack_b)->next;
    if (*stack_b)
        (*stack_b)->previous = NULL;

    if (!(*stack_a))
    {
        (*stack_a) = temp;
        (*stack_a)->next = NULL;
    }
    else 
    {
        temp->next = (*stack_a);
        (*stack_a)->previous = temp;
        (*stack_a) = temp;
    }
    write(1, "pa\n", 3);
}

void sa(t_stacks **stack_a)
{
    int len;
    int temp;
    int temp_index;

    len = stack_len(*stack_a);
    if (len <= 1)
        return ;
    
    temp = (*stack_a)->value;
    temp_index = (*stack_a)->index;
    (*stack_a)->value = (*stack_a)->next->value;
    (*stack_a)->index = (*stack_a)->next->index;
    (*stack_a)->next->value = temp;
    (*stack_a)->next->index = temp_index;
    write(1,"sa\n", 3);
}

void sb(t_stacks **stack_b)
{
    int len;
    int temp;
    int temp_index;

    len = stack_len(*stack_b);
    if (len <= 1)
        return ;
    
    temp = (*stack_b)->value;
    temp_index = (*stack_b)->index;
    (*stack_b)->value = (*stack_b)->next->value;
    (*stack_b)->index = (*stack_b)->next->index;
    (*stack_b)->next->value = temp;
    (*stack_b)->next->index = temp_index;
    write(1,"sb\n", 3);
}

void ss(t_stacks **stack_a, t_stacks **stack_b)
{
    sa(stack_a);
    sb(stack_b);
    write(1,"ss\n", 3);
}

void ra(t_stacks **stack_a)
{
   t_stacks *temp;
   t_stacks *last;

    if (!stack_a || !(*stack_a))
        return ;
    temp = (*stack_a);
    (*stack_a) = (*stack_a)->next;
    (*stack_a)->previous = NULL;
    last = find_last_node(*stack_a);
    last->next = temp;
    temp->previous = last;
    temp->next = NULL;
    write(1,"ra\n", 3);
}

void rb(t_stacks **stack_b)
{
    t_stacks *temp;
    t_stacks *last;

    if (!stack_b || !(*stack_b))
        return ;
    temp = (*stack_b);
    (*stack_b) = (*stack_b)->next;
    (*stack_b)->previous = NULL;
    last = find_last_node(*stack_b);
    last->next = temp;
    temp->previous = last;
    temp->next = NULL;
    write(1,"rb\n", 3);
}

void rr(t_stacks **stack_a, t_stacks **stack_b)
{
    ra(stack_a);
    rb(stack_b);
    write(1,"rr\n", 3);
}

void rra(t_stacks **stack_a)
{
    t_stacks *last;

    if (!stack_a || !(*stack_a))
        return ;
    last = find_last_node(*stack_a);
    last->previous->next = NULL;
    last->next = (*stack_a);
    (*stack_a)->previous = last;
    (*stack_a) = last;
    write(1,"rra\n", 4);
}

void rrb(t_stacks **stack_b)
{
    t_stacks *last;

    if (!stack_b || !(*stack_b))
        return ;
    last = find_last_node(*stack_b);
    last->previous->next = NULL;
    last->next = (*stack_b);
    (*stack_b)->previous = last;
    (*stack_b) = last;
    write(1,"rrb\n", 4);
}

void rrr(t_stacks **stack_a, t_stacks **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    write(1,"rrr\n", 4);
}


