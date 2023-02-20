/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:28:22 by imeliani          #+#    #+#             */
/*   Updated: 2023/02/20 14:59:16 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
                vars->xp == i[0];
                vars->yp == i[1];
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
int path(t_vars *vars)
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
    return(0);
}


