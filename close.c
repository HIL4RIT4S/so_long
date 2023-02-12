/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:01:59 by imeliani          #+#    #+#             */
/*   Updated: 2023/02/12 19:27:16 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_vars *vars)
{
	free_xpm(vars);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	mlx_loop_end(vars->mlx);
	free(vars->mlx);
	free_map(vars->ctab);
	free_map(vars->ptab);
	free(vars);
	exit(1);
}

int	ft_close2(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	mlx_loop_end(vars->mlx);
	free(vars->mlx);
	free_map(vars->ctab);
	free_map(vars->ptab);
	free(vars);
	exit(1);
}

void free_xpm(t_vars *vars)
{
    int	i;

	i = 0;
	while (i < 5)
	{
		mlx_destroy_image(vars->mlx, vars->img[i]);
		i++;
	}
}