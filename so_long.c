/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:03:16 by imeliani          #+#    #+#             */
/*   Updated: 2023/03/14 19:07:29 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printab(t_vars *vars)
{
	int	i;

	i = -1;
	while (vars->ptab[++i])
	{
		printf("%s\n", vars->ptab[i]);
	}
}

int	check_error(t_vars *vars, char *s)
{
	if (check_name(s) != 0)
		return (ft_printf("Erreur: Nom incorrect"), 1);
	if (check_ext(vars) != 0)
		return (ft_printf("Erreur: check_ext"), 1);
	if (check_int(vars) != 0)
		return (ft_printf("Erreur: check_int"), 1);
	if (check_len(vars) != 0)
		return (ft_printf("Erreur: check_len"), 1);
	if (check_item (vars) != 0)
		return (ft_printf("Erreur: check_item"), 1);
	if (path(vars) != 0)
		return (ft_printf("Erreur: Aucun chemin"), 1);
	return (0);
}

int	mlx_fe(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		clearmemory(vars->ctab);
		clearmemory(vars->ptab);
		free(vars);
		return (1);
	}
	vars->win = mlx_new_window(vars->mlx, vars->size[1] * 64,
			vars->size[0] * 64, "SO_LONG");
	if (!vars->win)
	{
		free(vars->mlx);
		exit(EXIT_FAILURE);
	}
	check_image(vars);
	my_map(vars);
	mlx_hook (vars->win, 02, 1L << 0, &key_press, vars);
	mlx_hook (vars->win, 17, 0, &ok_close, vars);
	mlx_loop(vars->mlx);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	*s;
	t_vars	*vars;

	s = av[1];
	if (!env || !*env)
		return (0);
	vars = ft_calloc(1, sizeof(t_vars));
	if (ac == 2)
	{
		map(vars, av[1]);
		recup_p(vars);
		if (check_error(vars, s) != 0)
			return (1);
		size_map(vars);
		mlx_fe(vars);
	}
	else
	{
		ok_close(vars);
		return (0);
	}
}
