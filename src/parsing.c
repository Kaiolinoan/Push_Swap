/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:33:58 by klino-an          #+#    #+#             */
/*   Updated: 2025/08/06 18:41:53 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int  check_doubles(char **argv, int nbr)
{
    size_t i;
    int temp;
    int count;
    
    i = 0;
    count = 0;
    while (argv[i])
    {
        temp = atol(argv[i++]);
        if (temp == nbr)
            count++;
        if(count >= 2)
            return (-1);
    }
    return (0);
}
void print_error(t_stacks **stack_a, char **matriz)
{
    ft_putstr_fd("Error\n", 2);
    mem_clear(stack_a, matriz);
    exit(-1);
}

static bool check_charcaters(char **argv)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if ((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '+' || argv[i][j] == '-')
                j++;
            else 
                return (false);
        }
        i++;
    }
    return (true);
}

int check_input(char **argv)
{
    size_t i;
    size_t j;
    
    i = 0;
    if (check_charcaters(argv) == false)
        return (-1);
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] == '+' || argv[i][j] == '-')
            {
                if ((argv[i][0] == '+' || argv[i][0] == '-') && ft_isdigit(argv[i][1]))
                    j++;
                else        
                    return (-1);
            }
            else 
                j++;
        }
        i++;
    }
    return (0);
}

int number_len(char *str)
{
    size_t i;
    size_t counter;

    i = 0;
    counter = 0;
    while (str[i] && !(str[i] >= '1' && str[i] <= '9'))
        i++;
    while (str[i] && ft_isdigit(str[i]) == 2048)
    {
        counter++;
        i++;
    }
    return (counter);
}


