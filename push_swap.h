/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:06:05 by klino-an          #+#    #+#             */
/*   Updated: 2025/08/13 17:18:21 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdbool.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stacks
{
	int				value;
	int				index;
	struct s_stacks	*next;
	struct s_stacks	*previous;
}					t_stacks;

// nodes
void				start_stacks(char **argv, t_stacks **stack_a);
t_stacks			*find_last_node(t_stacks *stack);
int					stack_len(t_stacks *stack);
void				normalize(t_stacks **stack_a);

// parsing
bool				check_doubles(char **argv, int nbr);
bool				check_input(char **argv);
void				print_error(t_stacks **stack_a, char **matriz);
int					number_len(char *str);

// utils
long				ft_atol(char *str);
bool				is_sorted(t_stacks *stack_a);
void				mem_clear(t_stacks **stack_a, char **matriz);
void				free_split(char **split);

// operations
void				rrr(t_stacks **stack_a, t_stacks **stack_b);
void				pb(t_stacks **stack_a, t_stacks **stack_b);
void				pa(t_stacks **stack_a, t_stacks **stack_b);
void				ss(t_stacks **stack_a, t_stacks **stack_b);
void				rra(t_stacks **stack_a);
void				rrb(t_stacks **stack_b);
void				sa(t_stacks **stack_a);
void				sb(t_stacks **stack_b);
void				ra(t_stacks **stack_a);
void				rb(t_stacks **stack_b);

// small_ sort
void				small_sort(t_stacks **stack_a, t_stacks **stack_b, int len);

// big_sort
void				radix_sort(t_stacks **stack_a, t_stacks **stack_b, int len);

#endif