/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:07:43 by imeliani          #+#    #+#             */
/*   Updated: 2023/02/01 19:57:57 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void    up(char **s, int x, int y)
// {
//     while (s[x][y] != '1' && s[x][y] != 'E')
//     {
//         if (s[x][y] != 'P')
//         {
//             s[x][y] = 'P';
//         }
//         x++;
//         if (s[x][y] == 'E')
//         {
//             s[x][y] = '1';
//         }
//     }
// }

// void    down(char **s, int x, int y)
// {
//     while (s[x][y] != '1' && s[x][y] != 'E')
//     {
//         if (s[x][y] != 'P')
//         {
//             s[x][y] = 'P';
//         }
//         x--;
//         if (s[x][y] == 'E')
//         {
//             s[x][y] = '1';
//         }
//     }
// }

// void    right(char **s, int x, int y)
// {
//     while (s[x][y] != '1' && s[x][y] != 'E')
//     {
//         if (s[x][y] != 'P')
//         {
//             s[x][y] = 'P';
//         }
//         y++;
//         if (s[x][y] == 'E')
//         {
//             s[x][y] = '1';
//         }
//     }
// }

void    left(char **s, int x, int y)
{
    while (s[x][y] != '1' && s[x][y] != 'E')
    {
        if (s[x][y] != 'P')
        {
            s[x][y] = 'P';
        }
        y--;
        if (s[x][y] == 'E')
        {
            s[x][y] = '1';
        }
    }
}

void path2(t_vars *vars)
{
    int i[2];

    i[0] = 0;
    while (vars->ctab[++i[0]])
    {
        i[1] = 0;
        while(vars->ctab[i[0]][++i[1]])
        {
            if (vars->ctab[i[0]][i[1]] == 'P')
            {
                if (vars->ctab[i[0]][i[1] + 1] == '0' || vars->ctab[i[0]][i[1] + 1] == 'C')
                    vars->ctab[i[0]][i[1] + 1] = 'P';
                if (vars->ctab[i[0]][i[1] - 1] == '0' || vars->ctab[i[0]][i[1] - 1] == 'C')
                    vars->ctab[i[0]][i[1] - 1] = 'P';
                if (vars->ctab[i[0 + 1]][i[1]] == '0' || vars->ctab[i[0 + 1]][i[1]] == 'C')
                    vars->ctab[i[0 + 1]][i[1]] = 'P';
                if (vars->ctab[i[0 - 1]][i[1]] == '0' || vars->ctab[i[0 - 1]][i[1]] == 'C')
                    vars->ctab[i[0 - 1]][i[1]] = 'P';
            }
            
        }
    }
}

void path(t_vars *vars)
{
    int i[2];
    int l;

    i[0] = 0;
    l = 0;
    while (vars->ctab[++i[0]])
    {
        i[1] = 0;
        while(vars->ctab[i[0]][++i[1]])
        {
            if (vars->ctab[i[0]][i[1]] == '0' || vars->ctab[i[0]][i[1]] == 'C')
                l++;
        }
    }
    while(--l >= 0)
    {
        printab(vars);
        path2(vars);
    }
}

// void    all(char **s, int x, int y)
// {
//     up(s, x, y);
//     down(s, x, y);
//     left(s, x, y);
//     right(s, x, y);
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