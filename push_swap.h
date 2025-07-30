#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "Libft/libft.h"
#define INT_MIN -2147483648
#define INT_MAX  2147483647

typedef struct s_stacks
{
    int value;
    struct s_stacks *next;
    struct s_stacks *previous;
}   t_stacks;

//nodes
void start_stacks(char **argv, t_stacks **stack_a);
t_stacks *find_last_node(t_stacks *stack);

//parsing
int  check_doubles(char **argv, int nbr);
int check_input(char **argv);
void print_error(char *str);

//utils
long ft_atol(char *str);

#endif