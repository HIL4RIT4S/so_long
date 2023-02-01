/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:07:43 by imeliani          #+#    #+#             */
/*   Updated: 2023/02/01 16:59:16 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void    up(char **s, int x, int y)
// {
//     while (s[x][y] != '1' && s[x][y] != 'E')
//     {
//         if (s[x][y] != '*')
//         {
//             s[x][y] = '*';
//         }
//         x++;
//         else if (s[x][y] == 'E')
//         {
//             s[x][y] = '1';
//         }
//     }
// }

// void    down(char **s, int x, int y)
// {
//     while (s[x][y] != '1' && s[x][y] != 'E')
//     {
//         if (s[x][y] != '*')
//         {
//             s[x][y] = '*';
//         }
//         x--;
//         else if (s[x][y] == 'E')
//         {
//             s[x][y] = '1';
//         }
//     }
// }

// void    right(char **s, int x, int y)
// {
//     while (s[x][y] != '1' && s[x][y] != 'E')
//     {
//         if (s[x][y] != '*')
//         {
//             s[x][y] = '*';
//         }
//         y++;
//         else if (s[x][y] == 'E')
//         {
//             s[x][y] = '1';
//         }
//     }
// }

// void    left(char **s, int x, int y)
// {
//     while (s[x][y] != '1' && s[x][y] != 'E')
//     {
//         if (s[x][y] != '*')
//         {
//             s[x][y] = '*';
//         }
//         y--;
//         else if (s[x][y] == 'E')
//         {
//             s[x][y] = '1';
//         }
//     }
// }

void    up(char **s, int x, int y)
{
    while (s[x])
    {
        while(s[x][y])
        {
            if(s[x][y] != '1')
                s[x][y] == 'P';
            x++;
        }
        break ;
    }
} 

void    down(char **s, int x, int y)
{
    while (s[x])
    {
        while(s[x][y])
        {
            if(s[x][y] != '1')
                s[x][y] == 'P';
            x--;
        }
        break ;
    }
}

void    right(char **s, int x, int y)
{
    while(s[x])
    {
        while(s[x][y])
        {
            if(s[x][y] != '1')
                s[x][y] == 'P';
            y++;
        }
        break ;
    }
}

void    left(char **s, int x, int y)
{
    while(s[x])
    {
        while(s[x][y])
        {
            if(s[x][y] != '1')
                s[x][y] == 'P';
            y--;
        }
        break ;
    }    
}

void    all(char **s, int x, int y)
{
    if (s[x + 1][y] != '1')
        up(s, x, y);
    if (s[x - 1][y] != '1')
        down(s, x, y);
    if (s[x][y + 1] != '1')
        right(s, x, y);
    if (s[x][y - 1] != '1')
        left(s, x, y);   
}