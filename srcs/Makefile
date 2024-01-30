# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 18:29:24 by ffleitas          #+#    #+#              #
#    Updated: 2024/01/29 19:47:30 by ffleitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = ../libft/libftprintf.a
SRC = game_graphs.c main.c parsing_map_utils.c parsing_map.c map_path.c
OBJS = $(SRC:.c=.o)
CC = gcc -g3 -Wall -Wextra -Werror #-fsanitize=address
INCLUDES = -lmlx -framework OpenGL -framework AppKit
	

all: $(NAME)

$(LIBFT) :
	@$(MAKE) -s -C ../libft

$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) $(LIBFT) $(INCLUDES) -o $@

clean:
	@$(MAKE) -s -C ../libft clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -s -C ../libft fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re