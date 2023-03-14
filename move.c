/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:40:37 by imeliani          #+#    #+#             */
/*   Updated: 2023/03/14 18:51:11 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key, t_vars *vars)
{
	if (key == 65307 || key == 113)
		ok_close(vars);
	if (key == REALUP || key == UP)
		haut(vars);
	if (key == REALDOWN || key == DOWN)
		bas(vars);
	if (key == REALLEFT || key == LEFT)
		gauche(vars);
	if (key == REALRIGHT || key == RIGHT)
		droite(vars);
	my_map(vars);
	if (check_ec(vars->ptab) == 0)
		ok_close(vars);
	return (0);
}

void	haut(t_vars *vars)
{
	int	i[2];

	i[0] = vars->xp;
	i[1] = vars->yp;
	if ((vars->ptab[i[0] - 1][i[1]] == '1') ||
		(vars->ptab[i[0] - 1][i[1]] == 'E' && vars->cc != vars->c))
	{
		vars->ptab[i[0]][i[1]] = 'P';
		vars->xp = i[0];
	}
	else
	{
		if (vars->ptab[i[0] - 1][i[1]] == 'C')
			vars->cc++;
		vars->ptab[i[0] - 1][i[1]] = 'P';
		vars->ptab[i[0]][i[1]] = '0';
		vars->xp = i[0] - 1;
		vars->move++;
		ft_printf("%d\n", vars->move);
	}
}

void	bas(t_vars *vars)
{
	int	i[2];

	i[0] = vars->xp;
	i[1] = vars->yp;
	if ((vars->ptab[i[0] + 1][i[1]] == '1') ||
		(vars->ptab[i[0] + 1][i[1]] == 'E' && vars->cc != vars->c))
	{
		vars->ptab[i[0]][i[1]] = 'P';
		vars->xp = i[0];
	}
	else
	{
		if (vars->ptab[i[0] + 1][i[1]] == 'C')
			vars->cc++;
		vars->ptab[i[0] + 1][i[1]] = 'P';
		vars->ptab[i[0]][i[1]] = '0';
		vars->xp = i[0] + 1;
		vars->move++;
		ft_printf("%d\n", vars->move);
	}
}

void	gauche(t_vars *vars)
{
	int	i[2];

	i[0] = vars->xp;
	i[1] = vars->yp;
	if ((vars->ptab[i[0]][i[1] - 1] == '1') ||
		(vars->ptab[i[0]][i[1] - 1] == 'E' && vars->cc != vars->c))
	{
		vars->ptab[i[0]][i[1]] = 'P';
		vars->xp = i[0];
	}
	else
	{
		if (vars->ptab[i[0]][i[1] - 1] == 'C')
			vars->cc++;
		vars->ptab[i[0]][i[1] - 1] = 'P';
		vars->ptab[i[0]][i[1]] = '0';
		vars->yp = i[1] - 1;
		vars->move++;
		ft_printf("%d\n", vars->move);
	}
}

void	droite(t_vars *vars)
{
	int	i[2];

	i[0] = vars->xp;
	i[1] = vars->yp;
	if ((vars->ptab[i[0]][i[1] + 1] == '1') ||
		(vars->ptab[i[0]][i[1] + 1] == 'E' && vars->cc != vars->c))
	{
		vars->ptab[i[0]][i[1]] = 'P';
		vars->xp = i[0];
	}
	else
	{
		if (vars->ptab[i[0]][i[1] + 1] == 'C')
			vars->cc++;
		vars->ptab[i[0]][i[1] + 1] = 'P';
		vars->ptab[i[0]][i[1]] = '0';
		vars->yp = i[1] + 1;
		vars->move++;
		ft_printf("%d\n", vars->move);
	}
}
