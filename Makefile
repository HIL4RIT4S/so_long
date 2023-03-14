# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 15:46:35 by pdosso-d          #+#    #+#              #
#    Updated: 2023/03/14 19:11:23 by imeliani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	so_long.c\
					close.c\
					error.c\
					error2.c\
					map.c\
					move.c\
					pathfinding.c\
					
OBJS			=	$(SRCS:.c=.o)

CC              =   gcc
RM              =   rm -f
CFLAGS          =   -Wall -Wextra -Werror

NAME            =    so_long

LIBRARIES		=	-L libftprintfgnl -lftprintfgnl
INCLUDES		=	-Ilibftprintfgnl

all:            $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror $(INCLUDES) -g3 -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):		$(OBJS)
				make -C libftprintfgnl
				$(CC) $(CFLAGS) $(OBJS) -Lminilibx-linux -lmlx_Linux -Lminilibx-linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBRARIES)
				
clean:
				make -C libftprintfgnl clean
				$(RM) $(OBJS) 


fclean:         clean
				make -C libftprintfgnl fclean
				$(RM) $(NAME)

norme :
	norminette $(SRCS) so_long.h
	
re:             fclean $(NAME)

.PHONY:			all clean fclean re norme 
