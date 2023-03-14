/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:27:13 by imeliani          #+#    #+#             */
/*   Updated: 2023/03/14 18:33:15 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ext(t_vars *vars)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (vars->ctab[i][j])
		i++;
	k = i;
	i = 0;
	while (vars->ctab[i][++j])
	{
		if (vars->ctab[i][j] != '1')
			return (1);
	}
	i = k;
	j = -1;
	while (vars->ctab[i][++j])
	{
		if (vars->ctab[i][j] != '1')
			return (1);
	}
	return (0);
}

int	check_int(t_vars *vars)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = ft_strlen(vars->ctab[0]) - 1;
	j = 0;
	while (vars->ctab[i])
	{
		while (vars->ctab[i][j])
		{
			if (vars->ctab[i][0] != '1' || vars->ctab[i][k] != '1')
				return (1);
			if (vars->ctab[i][j] != '1' && vars->ctab[i][j] != '0' &&
				vars->ctab[i][j] != 'P' && vars->ctab[i][j] != 'E' &&
				vars->ctab[i][j] != 'C')
				return (1);
		j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_len(t_vars *vars)
{
	int	i[2];
	int	j;

	i[0] = 0;
	j = ft_strlen(vars->ctab[i[0]]);
	while (vars->ctab[i[0]])
	{
		i[1] = 0;
		while (vars->ctab[i[0]][i[1]] && vars->ctab[i[0]][i[1]] != '\n')
			i[1]++;
		if (i[1] != j)
			return (1);
	i[0]++;
	}
	return (0);
}

int	check_item(t_vars *vars)
{
	int			i[2];
	static int	epc[3] = {0};

	i[0] = -1;
	i[1] = -1;
	while (vars->ctab[++i[0]])
	{
		while (vars->ctab[i[0]][++i[1]] && vars->ctab[i[0]][i[1]] != '\n')
		{
			if (vars->ctab[i[0]][i[1]] == 'E')
				epc[0] = epc[0] + 1;
			if (vars->ctab[i[0]][i[1]] == 'P')
				epc[1] = epc[1] + 1;
			if (vars->ctab[i[0]][i[1]] == 'C')
			{
				epc[2] = epc[2] + 1;
				vars->c = vars->c + 1;
			}
		}
		i[1] = 0;
	}
	if ((epc[0] != 1) || (epc[1] != 1) || (epc[2] < 0))
		return (1);
	return (0);
}

int	check_name(char *s)
{
	int	i;

	i = ft_strlen(s);
	if (s[i - 1] != 'r')
		return (1);
	if (s[i - 2] != 'e')
		return (1);
	if (s[i - 3] != 'b')
		return (1);
	if (s[i - 4] != '.')
		return (1);
	i = i - 5;
	while (s[i])
	{
		if (s[i] == '.')
			return (1);
	i--;
	}
	return (0);
}

// int     check_ext(char *s)
// {
//     int i;
//     i = 0;
//     while (s[i])
//     {
//         if (s[i] != '1')
//             return (1);
//         i++;
//     }
//     return (0);
// }
// 
// int     check_int(char *s)
// {
//     int i;
//     int j;
// 
//     i = 0;
//     j = ft_strlen(s);
//     if (s[0] != '1' || s[j - 1] != '1')
//         return (1);
//     while (s[i])
//     {
//         if (s[i] != '1' && s[i] != '0' && s[i] != 'P' && s[i] != 'E' 
//             && s[i] != 'C')
//             return (1);
//         i++;
//     }
//     return (0);
// }
// 
// int     check_len(char **s)
// {
//     int i;
//     int j;
//     int k;
// 
//     i = 0;
//     j = ft_strlen(s);
//     k = 0;
//     while (s[i])
//     {
//         while (s[i][k] && s[i][k] != '\n')
//             k++;
//         if (k != j)
//             return (1);
//         k = 0;
//         i++;
//     }
//     return (0);
// }
// 
// int     check_item(char **s)
// {
//     int i;
//     int j;
//     int epc[3];
//     t_vars vars;
// 
//     i = 0;
//     while (s[i])
//     {
//         j = 0;
//         while (s[i][++j] && s[i][j] != '\n')
//         {
//             if (s[i][j] == 'E')
//                 epc[0] += 1;
//             if (s[i][j] == 'P')
//                 epc[1] += 1;
//             if (s[i][j] == 'C')
//                 epc[2] += 1;
//             if (s[i][j] != '0' && s[i][j] != '1')
//                 return (1);
//         }
//         if (epc[0] != '1' && epc[1] != '1' && epc[2] < '1')
//             return (1);
//         i++;
//     }
//     return (0);
// }
// 
// int     check_name(char *s)
// {
//     int i;
// 
//     i = ft_strlen(s);
//     if (s == 0)
//         return (1);
//     else if (i < 5)
//         return (1);
//     else if (ft_strcmp(s + i - 4, ".ber") != 0)
//         return (1);
//     return (0);
// }
