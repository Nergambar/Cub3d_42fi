# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 11:59:01 by negambar          #+#    #+#              #
#    Updated: 2024/12/04 11:09:04 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFT = ./libft
GET = get_next_line/*.c

SRC =  maps/maps.c maps/matrix.c maps/matrix2.c maps/mtx_utils.c \
	textures/t_check.c textures/t_utils.c textures/t_wallcheck.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	main.c

CC = cc
FLAGS = -Wall -Wextra -Werror -g -Ilibft
MINILBX = -Lminilibx-linux -lmlx -Llibft -lft -lXext -lX11

OBJ = $(SRC:.c=.o)

all: $(NAME) $(LIBFT) $(GET)
$(NAME): $(OBJ) $(LIBFT) $(GET)
		@echo Linking... $(NAME)
		@make -C $(LIBFT)
		ar rc $(NAME) $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(MINILBX)
%.o : %.c
	@echo Compiling $<...
	$(CC) $(FLAGS) -o $@ -c $<
clean:
		@echo Cleaning...
		@rm -f $(OBJ)
		@make clean -C $(LIBFT)
fclean: clean
		@echo Cleaning...
		@make fclean -C $(LIBFT)
		rm -f $(NAME)
crash: fclean $(NAME); make clean
re: fclean all
.PHONY: clean fclean re all
.SILENT: