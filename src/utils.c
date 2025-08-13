/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:34:16 by klino-an          #+#    #+#             */
/*   Updated: 2025/08/13 17:17:43 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stacks *stack_a)
{
	if (!stack_a)
		return (false);
	while (stack_a->next)
		if (stack_a->next->value > stack_a->value)
			stack_a = stack_a->next;
	else
		return (false);
	return (true);
}

long	ft_atol(char *str)
{
	long	nb;
	int		sign;
	int		i;

	sign = 1;
	nb = 0;
	i = 0;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (sign * nb);
}

void	mem_clear(t_stacks **stack_a, char **matriz)
{
	t_stacks	*temp;
	t_stacks	*next;
	int			i;

	if (stack_a && (*stack_a))
	{
		temp = *stack_a;
		while (temp)
		{
			next = temp->next;
			if (temp)
				free(temp);
			temp = next;
		}
	}
	*stack_a = NULL;
	i = 0;
	if (!matriz)
		return ;
	while (matriz[i])
		free(matriz[i++]);
	free(matriz);
}

void	free_split(char **split)
{
	size_t	j;

	j = 0;
	while (split[j])
		free(split[j++]);
	free(split);
}

void	rrr(t_stacks **stack_a, t_stacks **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
