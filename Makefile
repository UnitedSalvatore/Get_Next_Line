NAME = get_next_line
LIB = libft/libft.a

FILENAMES = get_next_line.c \
			main.c


SOURCES = $(addprefix ./, $(FILENAMES))
OBJECTS = $(addprefix ./obj/, $(FILENAMES:.c=.o))

CC = gcc
FLAGS ?= -Wall -Wextra -Werror -g
FLAGS += -I./src/ -I./libft/

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB)
	$(CC) -o $@ $(FLAGS) $(OBJECTS) $(LIB)

$(LIB):
	make -C ./libft/

obj:
	mkdir obj/

obj/%.o: ./%.c | obj
	$(CC) -c $(FLAGS) $< -o $@

clean:
	make -C ./libft/ fclean
	rm -rf obj/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
