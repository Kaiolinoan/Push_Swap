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


long ft_atol(char *str);


#endif