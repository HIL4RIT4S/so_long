# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 15:46:35 by marbaret          #+#    #+#              #
#    Updated: 2023/01/15 17:06:01 by imeliani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS            =	so_long.c 
# get_next_line.c 
# get_next_line_utils.c put_img.c\
# 					ft_split.c ft_substr.c sl_check_error.c sl_utils.c sl_check_path.c\

OBJS            =    $(SRCS:.c=.o)

CC              =    gcc
RM              =    rm -f
CFLAGS          =    -Wall -Wextra -Werror

NAME            =    so_long

all:            $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g3 -Iminilibx-linux -Imlx_linux -O3 -c $< -o $@

$(NAME):		$(OBJS)

				$(CC) $(CFLAGS) $(OBJS) -Lminilibx-linux -lmlx_Linux -Lminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
				$(RM) $(OBJS)


fclean:         clean
				$(RM) $(NAME)


re:             fclean $(NAME)

bonus:			re
.PHONY:			all clean fclean re bonus
