/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:40:37 by imeliani          #+#    #+#             */
/*   Updated: 2023/02/12 16:11:21 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_press(t_vars *vars, int key)
{
    static int     move = 0;

	if (key == 65307 || key == 113)
		ft_close(vars);
    if ((key == 65362 || key == 119) && vars->ptab[vars->x][vars->y + 10] != '1' ||
        vars->ptab[vars->x - 10][vars->y] != 'E') // up
    {
        vars->y += 10;
        move++;
        ft_printf("%d\n", move);
    }
    if ((key == 65364 || key == 115) && vars->ptab[vars->x][vars->y - 10] != '1' ||
        vars->ptab[vars->x - 10][vars->y] != 'E') // down
    {
        vars->y -= 10;
        move++;
        ft_printf("%d\n", move);  
    }
    if ((key == 65361 || key == 97) && vars->ptab[vars->x + 10][vars->y] != '1' ||
        vars->ptab[vars->x - 10][vars->y] != 'E') // left
    {
        vars->x += 10;
        move++;
        ft_printf("%d\n", move);
    }
    if ((key == 65363 || key == 100) && vars->ptab[vars->x - 10][vars->y] != '1' ||
        vars->ptab[vars->x - 10][vars->y] != 'E') // right
    {
        vars->x -= 10;
        move++;
        ft_printf("%d\n", move);
    }
    return (0);
}