/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:33:34 by imeliani          #+#    #+#             */
/*   Updated: 2023/03/14 18:19:50 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include "libftprintfgnl/libftprintfgnl.h"

# define UP		119
# define DOWN	115
# define LEFT	97
# define RIGHT	100
# define REALUP 65362
# define REALDOWN 65364
# define REALLEFT 65361
# define REALRIGHT 65363

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	**img;
	char	**ctab;
	char	**ptab;
	int		xp;
	int		yp;
	int		size[2];
	void	*image[5];
	int		c;
	int		cc;
	int		move;
}				t_vars;

char	**clear_map(char **tab);
int		ok_close(t_vars *vars);
int		error_close(t_vars *vars);
void	free_xpm(t_vars*vars);
int		check_ext(t_vars*vars);
int		check_int(t_vars *vars);
int		check_len(t_vars *vars);
int		check_item(t_vars *vars);
int		check_name(char *s);
void	check_image(t_vars *vars);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		map(t_vars *vars, char *av);
void	my_map(t_vars *vars);
void	size_map(t_vars *vars);
int		key_press(int key, t_vars *vars);
void	path2(t_vars *vars);
int		path(t_vars *vars);
int		check_error(t_vars *vars, char *s);
int		mlx_fe(t_vars *vars);
void	printab(t_vars *vars);
void	haut(t_vars *vars);
void	bas(t_vars *vars);
void	gauche(t_vars *vars);
void	droite(t_vars *vars);
void	recup_p(t_vars *vars);
int		check_ec(char **tab);
void	clearmemory(char **str);
#endif