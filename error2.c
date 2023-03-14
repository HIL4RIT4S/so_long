/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:34:36 by imeliani          #+#    #+#             */
/*   Updated: 2023/03/14 18:36:50 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_image(t_vars *vars)
{
	int			a;
	int			i[2];
	static char	*image[5] = {
		"image/C.xpm", "image/E.xpm", "image/P.xpm",
		"image/S.xpm", "image/W.xpm" };

	i[0] = -1;
	i[1] = -1;
	while (++i[0] < 5)
	{
	vars->image[i[0]] = mlx_xpm_file_to_image(vars->mlx, image[i[0]], &a, &a);
		if (!vars->image[i[0]])
		{
			while (++i[1] < i[0])
				mlx_destroy_image(vars->mlx, vars->image[i[1]]);
			error_close(vars);
		}
	}
}

int	check_ec(char **tab)
{
	int	i[2];

	i[0] = 0;
	while (tab[i[0]])
	{
		i[1] = 0;
		while (tab[i[0]][i[1]])
		{
			if ((tab[i[0]][i[1]] == 'E') || (tab[i[0]][i[1]] == 'C'))
				return (1);
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}
