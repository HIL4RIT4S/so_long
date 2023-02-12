/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:52:45 by imeliani          #+#    #+#             */
/*   Updated: 2023/02/12 19:25:22 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int     map(t_vars vars, int fd)
// {
//     char    *s;
//     char    *line;
    
//     fd = open(fd, O_RDONLY);
//     if (fd == -1)
//         return (0);
//     while (s = get_next_line(fd))
//     {
//         line = ft_strjoin(line, s);   
//     }
//     vars.ctab = ft_split(line, '\n');
//     vars.ptab = ft_split(line, '\n');
//     return (0);
// }

void my_map(t_vars *vars)
{
    int i[2];
    
    i[0] = -1;
    while(++i[0] < vars->ptab[i[0]][i[1]])
    {
        i[1] = -1;
        while(++i[1] < vars->ptab[i[0]][i[1]])
        {
            if (vars->ptab[i[0]][i[1]] == '1')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img[0], 
                i[0] * 64, i[1] * 64);
            if (vars->ptab[i[0]][i[1]] == '0')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img[1], 
                i[0] * 64, i[1] * 64);
            if (vars->ptab[i[0]][i[1]] == 'E')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img[2], 
                i[0] * 64, i[1] * 64);
            if (vars->ptab[i[0]][i[1]] == 'C')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img[3], 
                i[0] * 64, i[1] * 64);
            if (vars->ptab[i[0]][i[1]] == 'P')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img[4], 
                i[0] * 64, i[1] * 64);
        }
    }
}