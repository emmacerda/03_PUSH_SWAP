CC=gcc
CFLAGS=-Wall -Wextra -Werror
SANITIZER=-fsanitize=address
SOURCES =  ft_adaptive.c ft_atoi.c ft_checkarg.c ft_complex.c\
		   ft_create_stacks.c ft_find_disorder.c ft_split.c\
		   ft_str_utils.c ft_utils_lst.c main.c\
		   push.c reverse.c rotate.c simple.c swap.c ft_bench.c\
		   medium.c utils_medium.c ft_is_error.c ft_utils_complex.c\
		   ft_create_tab.c
OBJECTS = $(SOURCES:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(SANITIZER) $(OBJECTS) libftprintf.a -o $(NAME)

%.o: %.c ft_push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
