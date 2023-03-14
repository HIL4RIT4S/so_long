/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:52:45 by imeliani          #+#    #+#             */
/*   Updated: 2023/03/14 19:13:00 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map(t_vars *vars, char *av)
{
	int		fd;
	char	*s;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Fichier invalide"));
	line = 0;
	while ((s = get_next_line(fd)))
	{
		line = ft_strjoin(line, s);
		free(s);
	}
	vars->ctab = ft_split(line, '\n');
	vars->ptab = ft_split(line, '\n');
	free(line);
	close(fd);
	return (0);
}

// void size_map(t_vars *vars)
// {
//     int i;

//     i = 0;
//     while (vars->ctab[i])
//         i++;
//     vars->size[0] = i;
//     i = 0;
//     while (vars->ctab[0][i])
//         i++;
//     vars->size[1] = i;
// }

void	size_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->ctab[i])
		i++;
	vars->size[0] = i;
	vars->size[1] = ft_strlen(vars->ctab[0]);
}

void	my_map(t_vars *vars)
{
	int	i[2];

	i[0] = -1;
	while (++i[0] < vars->size[0])
	{
		i[1] = -1;
		while (++i[1] < vars->size[1])
		{
			if (vars->ptab[i[0]][i[1]] == 'C')
				mlx_put_image_to_window (vars->mlx, vars->win, vars->image[0],
					i[1] * 64, i[0] * 64);
			if (vars->ptab[i[0]][i[1]] == 'E')
				mlx_put_image_to_window (vars->mlx, vars->win, vars->image[1],
					i[1] * 64, i[0] * 64);
			if (vars->ptab[i[0]][i[1]] == 'P')
				mlx_put_image_to_window (vars->mlx, vars->win, vars->image[2],
					i[1] * 64, i[0] * 64);
			if (vars->ptab[i[0]][i[1]] == '0')
				mlx_put_image_to_window (vars->mlx, vars->win, vars->image[3],
					i[1] * 64, i[0] * 64);
			if (vars->ptab[i[0]][i[1]] == '1')
				mlx_put_image_to_window (vars->mlx, vars->win, vars->image[4],
					i[1] * 64, i[0] * 64);
		}
	}
}
