/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:28:22 by imeliani          #+#    #+#             */
/*   Updated: 2023/03/14 19:24:50 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path2(t_vars *vars)
{
	int	i[2];

	i[0] = -1;
	while (vars->ctab[++i[0]])
	{
		i[1] = -1;
		while (vars->ctab[i[0]][++i[1]])
		{
			if (vars->ctab[i[0]][i[1]] == 'P')
			{
				if (vars->ctab[i[0]][i[1] + 1] == '0' ||
					vars->ctab[i[0]][i[1] + 1] == 'C')
						vars->ctab[i[0]][i[1] + 1] = 'P';
				if (vars->ctab[i[0]][i[1] - 1] == '0' ||
					vars->ctab[i[0]][i[1] - 1] == 'C')
						vars->ctab[i[0]][i[1] - 1] = 'P';
				if (vars->ctab[i[0] + 1][i[1]] == '0' ||
					vars->ctab[i[0] + 1][i[1]] == 'C')
						vars->ctab[i[0] + 1][i[1]] = 'P';
				if (vars->ctab[i[0] - 1][i[1]] == '0' ||
					vars->ctab[i[0] - 1][i[1]] == 'C')
						vars->ctab[i[0] - 1][i[1]] = 'P';
			}
		}
	}
}

int	path(t_vars *vars)
{
	int			i[2];
	static int	l = 0;

	i[0] = -1;
	while (vars->ctab[++i[0]])
	{
		i[1] = -1;
		while (vars->ctab[i[0]][++i[1]])
		{
			if (vars->ctab[i[0]][i[1]] == '0' || vars->ctab[i[0]][i[1]] == 'C')
					l[0]++;
		}
	}
	while (--l[0] >= 0)
		path2(vars);
	i[0] = -1;
	while (vars->ctab[++i[0]])
	{
		i[1] = -1;
		while (vars->ctab[i[0]][++i[1]])
		{
			if (vars->ctab[i[0]][i[1]] == 'C')
				return (1);
		}
	}
	return (0);
}

void	recup_p(t_vars *vars)
{
	int	i[2];

	i[0] = -1;
	while (vars->ptab[++i[0]])
	{
		i[1] = -1;
		while (vars->ptab[i[0]][++i[1]])
		{
			if (vars->ptab[i[0]][i[1]] == 'P')
			{
				vars->xp = i[0];
				vars->yp = i[1];
				break ;
			}
		}
	}
}
