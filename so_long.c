/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:03:16 by imeliani          #+#    #+#             */
/*   Updated: 2023/02/01 20:00:55 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void printab(t_vars *vars)
{
    int i;

    i = -1;
    while (vars->ctab[++i])
    {
        printf("%s\n", vars->ctab[i]);
    }
}

// int end(t_vars *vars)
// {
//     mlx_destroy_image(vars->mlx, vars->img);
//     mlx_clear_window(vars->mlx, vars->win);
//     mlx_destroy_window(vars->mlx, vars->win);
//     mlx_destroy_display(vars->mlx);
//     free(vars->mlx);
//     vars->mlx = 0;
//     exit(0);
//     return (0);
// }

void path2(t_vars *vars)
{
    int i[2];

    i[0] = 0;
    while (vars->ctab[++i[0]])
    {
        i[1] = 0;
        while(vars->ctab[i[0]][++i[1]])
        {
            if (vars->ctab[i[0]][i[1]] == 'P')
            {
                if (vars->ctab[i[0]][i[1] + 1] == '0' || vars->ctab[i[0]][i[1] + 1] == 'C')
                    vars->ctab[i[0]][i[1] + 1] = 'P';
                if (vars->ctab[i[0]][i[1] - 1] == '0' || vars->ctab[i[0]][i[1] - 1] == 'C')
                    vars->ctab[i[0]][i[1] - 1] = 'P';
                if (vars->ctab[i[0] + 1][i[1]] == '0' || vars->ctab[i[0] + 1][i[1]] == 'C')
                    vars->ctab[i[0] + 1][i[1]] = 'P';
                if (vars->ctab[i[0] - 1][i[1]] == '0' || vars->ctab[i[0] - 1][i[1]] == 'C')
                    vars->ctab[i[0] - 1][i[1]] = 'P';
            }
            
        }
    }
}

void path(t_vars *vars)
{
    int i[2];
    int l;

    i[0] = 0;
    l = 0;
    while (vars->ctab[++i[0]])
    {
        i[1] = 0;
        while(vars->ctab[i[0]][++i[1]])
        {
            if (vars->ctab[i[0]][i[1]] == '0' || vars->ctab[i[0]][i[1]] == 'C')
                l++;
        }
    }
    while(--l >= 0)
    {
        printab(vars);
        printf("\n");
        path2(vars);
    }
}

int     map(t_vars *vars, int fd)
{
    char    *s;
    char    *line;
    
    // fd = open(fd, O_RDONLY);
    if (fd == -1)
        return (0);
    s = ft_calloc(1, 1);
    line = 0;
    while ((s = get_next_line(fd)))
        line = ft_strjoin(line, s);   
    vars->ctab = ft_split(line, '\n');
    vars->ptab = ft_split(line, '\n');
    return (0);
}

// int check_error(t_vars *vars)
// {
//     if ("fonction" != 0)
//         return(ft_printf("nom de l'erreur"));
// }

int main()
{
    int fd;
    t_vars vars;
    
    fd = open("map.ber", O_RDONLY);
    map(&vars, fd);
    // if (check_error(&vars) != 0)
    //     return(1);
    printab(&vars);
    path(&vars);
    // t_vars  vars;
    // int x;
    // int y;
    
    
    // vars.mlx = mlx_init();
    // if (!vars.mlx)
    //     return (0);
    // vars.win = mlx_new_window(vars.mlx, 1200, 980, "Je m'appelle Pablo");
    // vars.img = mlx_xpm_file_to_image (vars.mlx, "picsou.xpm", &x, &y);
    // if (!vars.img)
    //     return (end(&vars));
    // mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
    // mlx_hook(vars.win, 17, 0, end, &vars);
    // mlx_loop(vars.mlx);
}