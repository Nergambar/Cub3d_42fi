# Name of the executable #
NAME = libft.a

# Source files and object files #
SRC = ft_isprint.c ft_putendl_fd.c ft_strlcat.c ft_substr.c \
ft_atoi_mdf.c  ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c \
ft_bzero.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c \
ft_calloc.c ft_memcmp.c ft_split_mdf.c ft_strmapi.c \
ft_isalnum.c ft_memcpy.c ft_strchr.c ft_strncmp.c \
ft_isalpha.c ft_memmove.c ft_strdup.c ft_strnstr.c \
ft_isascii.c ft_memset.c ft_striteri.c ft_strrchr.c \
ft_isdigit.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c ft_itoa.c

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c 

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Compiler and compiler flags #
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Targets #
$(NAME): $(OBJ)
	$(AR) -r $@ $?
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
clean:
	rm -f $(OBJ) $(BONUS_OBJ)
fclean: clean
	rm -f $(NAME)
bonus: $(BONUS_OBJ)
	ar rc $(NAME) $(BONUS_OBJ)
	ranlib $(NAME)
all: $(NAME) bonus
re: fclean all
.PHONY: all clean fclean bonus re