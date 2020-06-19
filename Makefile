NAME = lem-in

# dirs
DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_INCLUDES = ./includes

HEADER = $(DIR_INCLUDES)/lem_in.h

# files
C_FILES = find_ways_count_steps_of_ways.c\
		find_ways_del_ways_restore_links.c\
		find_ways_find_short_way.c\
		find_ways_set_minus.c\
		find_ways_write_way.c\
		find_ways.c\
		ft_1.c\
		ft_2.c\
		main.c\
		print_result.c\
		print_result2.c\
		validation_add_rooms_links.c\
		validation_fill_links_rooms.c\
		validation_get_line.c\
		validation_get_links.c\
		validation_get_num_ants.c\
		validation_get_number.c\
		validation_get_rooms.c\
		validation_init.c\
		validation_parse_input.c\
		validation_set_error_free.c\
		validation_set_room_name.c\
		validation_test_empty_links.c\

SRCS = $(addprefix $(DIR_SRC)/,$(C_FILES))
OBJS = $(addprefix $(DIR_OBJ)/,$(C_FILES:.c=.o))

# flags
CC = gcc
FLAGS = -Wall -Werror -Wextra
INC_HEADERS = -I $(DIR_INCLUDES)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(DIR_OBJ) $(OBJS) $(DIR_SRC) $(SRCS)
	$(CC) $(FLAGS) $(OBJS) $(INC_HEADERS) -o $@

$(DIR_OBJ):
	mkdir -p obj

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(HEADER)
	$(CC) $(FLAGS) -I $(DIR_INCLUDES) -c $< -o $@

clean:
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
