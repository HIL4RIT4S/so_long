# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 15:46:35 by pdosso-d          #+#    #+#              #
#    Updated: 2023/02/01 18:55:06 by imeliani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	so_long.c\

OBJS			=	$(SRCS:.c=.o)

# SRCS_BONUS		=	check_map_bonus.c\
# 					change_map_bonus.c\
# 					main_bonus.c\
# 					player_move_bonus.c\
# 					put_image_bonus.c\
# 					tools_bonus.c\

OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

CC              =   gcc
RM              =   rm -f
CFLAGS          =   -Wall -Wextra -Werror

NAME            =    so_long
# NAME_BONUS            =    so_long_bonus

LIBRARIES		=	-L libftprintfgnl -lftprintfgnl
INCLUDES		=	-Ilibftprintfgnl

all:            $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror $(INCLUDES) -g3 -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):		$(OBJS)
				make -C libftprintfgnl
				$(CC) $(CFLAGS) $(OBJS) -Lminilibx-linux -lmlx_Linux -Lminilibx-linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBRARIES)
# bonus:			$(NAME_BONUS)

# $(NAME_BONUS):		$(OBJS_BONUS)
# 				make -C libftprintfgnl
# 				$(CC) $(CFLAGS) $(OBJS_BONUS) -Lminilibx-linux -lmlx_Linux -Lminilibx-linux -lXext -lX11 -lm -lz -o $(NAME_BONUS) $(LIBRARIES)

norme :
	norminette $(SRCS) so_long.h libftprintfgnl

clean:
				make -C libftprintfgnl clean
				$(RM) $(OBJS) 


fclean:         clean
				make -C libftprintfgnl fclean
				$(RM) $(NAME)


re:             fclean $(NAME)

.PHONY:			all clean fclean re bonus norme
