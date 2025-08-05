/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:34:13 by klino-an          #+#    #+#             */
/*   Updated: 2025/08/05 17:27:28 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

    stack_a = NULL;
    stack_b = NULL;
    if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
        return (0);
    else if (argc == 2)
        argv = ft_split(argv[1], 32);
    start_stacks(argv, &stack_a);

    bool sla = is_sorted(&stack_a);

    if (sla == false)
        printf("nao ordenado");
    else
        printf("ordenado");
    // pb(&stack_a, &stack_b);
    // pb(&stack_a, &stack_b);
    // pb(&stack_a, &stack_b);
    // printf(" -----ANTES----:\n");
    // print_stacks(stack_a, stack_b);

    // rrr(&stack_a, &stack_b);
        
    // printf(" -----DEPOIS----:\n");
    // print_stacks(stack_a, stack_b);

}