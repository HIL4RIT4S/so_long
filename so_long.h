/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:33:34 by imeliani          #+#    #+#             */
/*   Updated: 2023/02/20 15:18:22 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include "libftprintfgnl.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (1)
# endif


typedef struct	s_vars {
	void	*mlx;
	void	*win;
    void    **img;
	char 	**ctab;
	char 	**ptab;
	int 	xp;
	int 	yp;
	int 	size[2];
	int 	image[5] = {
		"image/C.xpm", "image/E.xpm", "image/P.xpm",
		"image/S.xpm", "image/W.xpm"};
}				t_vars;

// char	**ft_split(char const *s, char c);
// int     map(char *fd);
// int		ft_strcmp(char *s1, char *s2);
// char	*get_next_line(int fd);
// char	*ft_strchr(const char *s, int c);
// char	*ft_strjoin(char const *s1, char const *s2);
// void	*ft_calloc(size_t nmemb, size_t size);
// void	ft_bzero(void *s, size_t n);
// void	*ft_memset(void *s, int c, size_t n);
// size_t	ft_strlen(const char *str);

// void 	up(char **s, int x, int y);
// void 	down(char **s, int x, int y);
// void    right(char **s, int x, int y);
// void 	left(char **s, int x, int y);
// void 	all(char **s, int x, int y);

#endif