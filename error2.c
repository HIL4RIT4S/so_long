/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:34:36 by imeliani          #+#    #+#             */
/*   Updated: 2023/02/20 14:34:26 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_all(char *s)
{
    
}

void check_image(t_vars *vars)
{
    static int     i[2] = {-1, -1};
    int     a;

    while (++i[0] < 5)
    {
        vars->image[i[0]] = mlx_xpm_file_to_image(vars->mlx, vars->image[i[0]], 
            &a, &a);
        if (!vars->image[i[0]])
        {
            while (++i[1] < i[0])
                mlx_destroy_image(vars->mlx, vars->image[i[1]]);
            error_close(vars);
        }
    }
}