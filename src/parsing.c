/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klino-an <klino-an@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:33:58 by klino-an          #+#    #+#             */
/*   Updated: 2025/08/04 16:36:48 by klino-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int check_input(char **argv)
{
    size_t i;
    i = 0;
    while (argv[i])
    {
        if (ft_isdigit(argv[i][0]) == 0)
            if((argv[i][0] != '-' || argv[i][0] != '+') 
                && ft_isdigit(argv[i][1]) == 0)
                return (-1);
        i++;
    }
    return (0);
}

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
void print_error(char *str)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(str, 2);
    exit(-1);
}


