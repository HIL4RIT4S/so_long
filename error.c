/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:27:13 by imeliani          #+#    #+#             */
/*   Updated: 2023/01/18 17:31:56 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     check_ext(char *s)
{
    int i;
    
    i = 0;
    while (s[i])
    {
        if (s[i] != '1')
            return (1);
        i++;
    }
    return (0);
}

int     check_int(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] != '1' && s[i] != '0' && s[i] != 'P' && s[i] != 'E' 
            && s[i] != 'C')
            return (1);
    }
    return (0);
}

int     check_len(char **s)
{
    int i;
    int j;
    int k;

    i = 0;
    j = ft_strlen(s);
    k = 0;
    while (s[i])
    {
        while (s[i][k] && s[i][k] != '\n')
            k++;
        if (k != j)
            return (1);
        k = 0;
        i++;
    }
    return (0);
}

// int     check_item(char *s)
// {
//     int i;
//     int j;
//     int tab[128] = {0};

//     i = 0;
//     while (s[i])
//     {
//         while (s[i][j] && s[i][j] != '\n')
//         {
//             tab[(int)s[i][j]] += 1;
//             j++;
//         }
//         i++;
//     }
//     if (tab[80] != '1' && tab[69] != '1' && tab[67] < '1')
//         return (1);
//     return (0);
// } 

int     check_item(char *s)
{
    int i;
    int j;
    int epc[3];
    
    i = 0;
    while (s[i])
    {
        while (s[i][j] && s[i][j] != '\n')
        {
            if (s[i][j] == 'E')
                epc[1] += 1;
            else if (s[i][j] == 'P')
                epc[2] += 1;
            else if (s[i][j] == 'C')
                epc[3] += 1;
            j++;
        }
        if (epc[1] != '1' && epc[2] != '1' && epc[3] < 1)
            return (1);
        i++;
    }
    return (0);
}