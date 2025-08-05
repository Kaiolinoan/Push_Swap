/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:34:06 by klino-an          #+#    #+#             */
/*   Updated: 2025/08/05 16:57:40 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//colocar o write em cada funcao dps

void    pb(t_stacks **stack_a, t_stacks **stack_b)
{
    t_stacks *node;
    
    if (!(*stack_a))
        return ;
    node = create_node((*stack_a)->value);
    node->next = (*stack_b);
    if (!(*stack_b))
        (*stack_b) = node;
    else 
    {
        (*stack_b)->previous = node;
        (*stack_b) = node;
    }
    (*stack_a) = (*stack_a)->next;
}

void    pa(t_stacks **stack_a, t_stacks **stack_b)
{
    t_stacks *node;

    if (!(*stack_b))
        return ;
    node = create_node((*stack_b)->value);
    node->next = (*stack_a);
    if (!(*stack_a))
        (*stack_a) = node;
    else 
    {
        (*stack_a)->previous = node;
        (*stack_a) = node;
    }
    (*stack_b) = (*stack_b)->next;
    
}

void sa(t_stacks **stack_a)
{
    int len;
    int temp;

    len = stack_len(*stack_a);
    if (len <= 1)
        return ;
    
    temp = (*stack_a)->value;
    (*stack_a)->value = (*stack_a)->next->value;
    (*stack_a)->next->value = temp;
}

void sb(t_stacks **stack_b)
{
    int len;
    int temp;

    len = stack_len(*stack_b);
    if (len <= 1)
        return ;
    
    temp = (*stack_b)->value;
    (*stack_b)->value = (*stack_b)->next->value;
    (*stack_b)->next->value = temp;
}

void ss(t_stacks **stack_a, t_stacks **stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void ra(t_stacks **stack_a)
{
    int temp;
    t_stacks *node;
    t_stacks *last;

    if (!stack_a || !(*stack_a))
        return ;
    temp = (*stack_a)->value;
    (*stack_a) = (*stack_a)->next;
    (*stack_a)->previous = NULL;
    node = create_node(temp);
    last = find_last_node(*stack_a);
    last->next = node;
    node->previous = last;
}

void rb(t_stacks **stack_b)
{
    int temp;
    t_stacks *node;
    t_stacks *last;

    if (!stack_b || !(*stack_b))
        return ;
    temp = (*stack_b)->value;
    (*stack_b) = (*stack_b)->next;
    (*stack_b)->previous = NULL;
    node = create_node(temp);
    last = find_last_node(*stack_b);
    last->next = node;
    node->previous = last;
}

void rr(t_stacks **stack_a, t_stacks **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void rra(t_stacks **stack_a)
{
    int temp;
    t_stacks *last;
    t_stacks *node;

    if (!stack_a || !(*stack_a))
        return ;
    last = find_last_node(*stack_a);
    temp = last->value;
    last->previous->next = NULL;
    // free(last); NAO SEI AINDA SOBRE ISSO;
    node = create_node(temp);
    node->next = (*stack_a);
    (*stack_a)->previous = node;
    (*stack_a) = node;
}

void rrb(t_stacks **stack_b)
{
    int temp;
    t_stacks *last;
    t_stacks *node;

    if (!stack_b || !(*stack_b))
        return ;
    last = find_last_node(*stack_b);
    temp = last->value;
    last->previous->next = NULL;
    // free(last); NAO SEI AINDA SOBRE ISSO;
    node = create_node(temp);
    node->next = (*stack_b);
    (*stack_b)->previous = node;
    (*stack_b) = node;
}

void rrr(t_stacks **stack_a, t_stacks **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}


