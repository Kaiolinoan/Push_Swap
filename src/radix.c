//header

#include "../push_swap.h"

void radix_sort(t_stacks **stack_a, t_stacks **stack_b, int len)
{
    int max_index;
    int max_bits;
    int i;
    int j;

    max_bits = 0;
    max_index = len - 1;
    i = 0;
    while ((max_index >> max_bits) != 0)
        max_bits++;
    while (i < max_bits)
    {
        j = 0;
        while (j < len)
        {
            if (((*stack_a)->index >> i & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
            j++;
        }
        while (*stack_b)
            pa(stack_a, stack_b);
        i++;
    }
}
