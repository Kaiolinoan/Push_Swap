#include "push_swap.h"

void    pb(t_stacks **stack_a, t_stacks **stack_b)
{
    if (!(*stack_a))
        return ;
    
    t_stacks *head;

    head = (*stack_a);

    (*stack_a) = (*stack_a)->next;
    (*stack_a)->previous = NULL;
    if (!(*stack_b))
    {
        (*stack_b) = head;
        (*stack_b)->next = NULL;
        (*stack_b)->previous = NULL;
    }
    else 
    {
        head->next = (*stack_b);
        (*stack_b) = head;
    }
    
}

void    pa(t_stacks **stack_a, t_stacks **stack_b)
{
    if (!(*stack_b))
        return ;
    
}