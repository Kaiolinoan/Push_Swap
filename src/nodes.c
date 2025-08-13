/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:34:10 by klino-an          #+#    #+#             */
/*   Updated: 2025/08/13 17:07:35 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_len(t_stacks *stack)
{
	size_t	i;

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

t_stacks	*find_last_node(t_stacks *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

static void	create_stack(t_stacks **stack_a, int nbr)
{
	t_stacks	*node;
	t_stacks	*last_node;

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

void	start_stacks(char **argv, t_stacks **stack_a)
{
	long	nbr;
	int		nb_len;
	size_t	i;

	i = 0;
	while (argv[i])
	{
		nbr = ft_atol(argv[i]);
		nb_len = number_len(argv[i]);
		if ((nbr < INT_MIN || nbr > INT_MAX) || nb_len > 10)
			print_error(stack_a, argv);
		if (!check_doubles(argv, nbr))
			print_error(stack_a, argv);
		if (!check_input(argv))
			print_error(stack_a, argv);
		create_stack(stack_a, (int)nbr);
		i++;
	}
	i = 0;
}

void	normalize(t_stacks **stack_a)
{
	t_stacks	*current;
	t_stacks	*compare;

	current = (*stack_a);
	compare = (*stack_a);
	while (current)
	{
		current->index = 0;
		current = current->next;
	}
	current = (*stack_a);
	while (current)
	{
		compare = (*stack_a);
		while (compare)
		{
			if (current->value > compare->value)
				current->index += 1;
			compare = compare->next;
		}
		current = current->next;
	}
}
