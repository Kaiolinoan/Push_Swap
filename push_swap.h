#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "Libft/libft.h"


typedef struct s_stacks
{
    int value;
    struct s_stacks next*;
    struct s_stacks previous*;
}   t_stacks;


#endif