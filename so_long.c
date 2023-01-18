/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:03:16 by imeliani          #+#    #+#             */
/*   Updated: 2023/01/18 13:39:45 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int     map(char *fd)
// {
//     int     fd;
//     char    *s;
//     char    *line;
//     char    **str;
    
//     fd = open(fd, O_RDONLY);
//     if (fd == -1)
//         return (0);
//     while (s = get_next_line(fd))
//     {
//         line = ft_strjoin(line, s);   
//     }
//     str = ft_split(line, '\n');
//     return (str);
// }

int end(t_vars *vars)
{
    mlx_destroy_image(vars->mlx, vars->img);
    mlx_clear_window(vars->mlx, vars->win);
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
    vars->mlx = 0;
    exit(0);
    return (0);
}

int main()
{
    t_vars  vars;
    int x;
    int y;
    
    
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1200, 980, "Je m'appelle Pablo");
    vars.img = mlx_xpm_file_to_image (vars.mlx, "picsou.xpm", &x, &y);
    if (!vars.img)
        return (end(&vars));
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
    mlx_hook(vars.win, 17, 0, end, &vars);
    mlx_loop(vars.mlx);
}