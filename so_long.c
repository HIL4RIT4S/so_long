/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:03:16 by imeliani          #+#    #+#             */
/*   Updated: 2023/02/05 20:00:26 by imeliani         ###   ########.fr       */
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

int     check_ext(t_vars *vars)
{
    int i;
    int j;
    int k;
    
    i = -1;
    j = 0;
    k = 0;
    while (vars->ctab[++i][j])
        k++;
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

int     check_int(t_vars *vars)
{
    int i;
    int j;
    int k;
    
    i = 0;
    j = -1;
    k = 0;
    while (vars->ctab[i][++j])
        k++;
    j = 0;
    if (vars->ctab[i][j] != '1' || k != '1')
        return (1);
    while (vars->ctab[i][j])
    {
        while (vars->ctab[i][j])
        {
            if (vars->ctab[i][j] != '1' && vars->ctab[i][j] != '0' && 
                vars->ctab[i][j] != 'P' && vars->ctab[i][j] != 'E' && 
                vars->ctab[i][j] != 'C')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int     check_len(t_vars *vars)
{
    int i[2];
    int j;

    i[0] = 0;
    j = ft_strlen(vars->ctab[i[0]]);
    while (vars->ctab)
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

int     check_item(t_vars *vars)
{
    int i[2];
    int epc[3] = {0};
    
    i[0] = -1;
    i[1] = -1;
    while (vars->ctab[++i[0]][i[1]])
    {
        while (vars->ctab[i[0]][i[1]] && vars->ctab[i[0]][i[1]] != '\n')
        {
            if (vars->ctab[i[0]][i[1]] == 'E')
                epc[0] += 1;
            if (vars->ctab[i[0]][i[1]] == 'P')
                epc[1] += 1;
            if (vars->ctab[i[0]][i[1]] == 'C')
                epc[2] += 1;
            if (vars->ctab[i[0]][i[1]] != '0' && vars->ctab[i[0]][i[1]] != '1')
                return (1);
        }
        if (epc[0] != '1' && epc[1] != '1' && epc[2] < '1')
            return (1);
    }
    return (0);
}

int     check_name(char *s)
{
    int i;

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
        i++;
    }
    return (0);
}

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

int path(t_vars *vars)
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
    return(0);
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

int check_error(t_vars *vars)
{    
    if (check_ext(vars) != 0 || check_int(vars) != 0 || check_len(vars) != 0 || check_item (vars) != 0)
        return(ft_printf("Erreur: Map invalide"));
    return (0);
}

int main()
{
    int fd;
    t_vars vars;
    
    fd = open("map.ber", O_RDONLY);
    map(&vars, fd);
    if (check_error(&vars) != 0)
        return(1);
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