# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 11:59:01 by negambar          #+#    #+#              #
#    Updated: 2025/01/14 13:15:29 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFT = libft
GET = get_next_line/*.c

SRC =  maps/maps.c maps/matrix.c maps/matrix2.c \
	textures/t_check.c textures/t_utils.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	guided/main.c guided/main_utils.c guided/player.c guided/extras.c guided/maps_utils.c guided/extras2.c \
	guided/move_utils.c maps/flood_fill.c maps/utils.c maps/utils2.c
OBJDIR = objects

$(shell mkdir -p $(OBJDIR))

CC = cc
FLAGS = -Wall -Wextra -Werror -Ilibft -g
MINILBX = -Lminilibx-linux -lmlx -Llibft -lft -lXext -lX11 -lm

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME) $(LIBFT) $(GET)

$(NAME): $(OBJ) $(LIBFT) $(GET)
		@echo Linking... $(NAME)
		@make -C $(LIBFT)
		$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(MINILBX)
$(OBJDIR)/%.o : %.c
	@mkdir -p $(dir $@)
	@echo Compiling $<...
	$(CC) $(FLAGS) -c $< -o $@

clean:
		@echo Cleaning...
		@rm -rf $(OBJDIR)
		@make clean -C $(LIBFT)
fclean: clean
		@echo Cleaning...
		@make fclean -C $(LIBFT)
		rm -f $(NAME)
crash: fclean $(NAME); make clean
re: fclean all
.PHONY: clean fclean re all
.SILENT: