/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:34:13 by klino-an          #+#    #+#             */
/*   Updated: 2025/08/07 18:00:33 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void print_index(t_stacks *stack_a, t_stacks *stack_b)
{
    printf("stack A:\n");
    while (stack_a)
    {
        printf("%d\n", stack_a->index);
        stack_a = stack_a->next;
    }  
    printf("stack B:\n");
    while (stack_b)
    {
        printf("%d\n", stack_b->index);
        stack_b = stack_b->next;
    }
}

void print_stacks(t_stacks *stack_a, t_stacks *stack_b)
{
    printf("stack A:\n");
    while (stack_a)
    {
        printf("%d\n", stack_a->value);
        stack_a = stack_a->next;
    }  
    printf("stack B:\n");
    while (stack_b)
    {
        printf("%d\n", stack_b->value);
        stack_b = stack_b->next;
    }
}

int main(int argc, char**argv)
{
    t_stacks *stack_a;
    t_stacks *stack_b;
    char **matrix;

    stack_a = NULL;
    stack_b = NULL;
    if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
        return (0);
    if (argc == 2)
        matrix = ft_split(argv[1], 32);
    else 
        matrix = &argv[1];
    start_stacks(matrix, &stack_a);

    /* if (!is_sorted(&stack_a))
    {
        if (stack_len(stack_a) <= 5)
            small_sort();
        else 
            big_sort();
    } */
   normalize(&stack_a);
   
//    pb(&stack_a, &stack_b);
//    pb(&stack_a, &stack_b);
//    pb(&stack_a, &stack_b);
   
    printf(" -----ANTES----:\n");
    print_stacks(stack_a, stack_b);

    
    printf("------INDEX-----: \n");
    print_index(stack_a, stack_b);
    
    small_sort(&stack_a, &stack_b, stack_len(stack_a));
    // rrb(&stack_b);
  
        
    printf(" -----DEPOIS----:\n");
    print_stacks(stack_a, stack_b);

    printf("------INDEX-----: \n");
    print_index(stack_a, stack_b);

}
