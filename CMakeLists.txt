cmake_minimum_required(VERSION 3.16)
project(lemin C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(src)

add_executable(lemin
        includes/lem_in.h
        src/find_ways.c
        src/find_ways_count_steps_of_ways.c
        src/find_ways_del_ways_restore_links.c
        src/find_ways_find_short_way.c
        src/find_ways_set_minus.c
        src/find_ways_write_way.c
        src/ft_1.c
        src/ft_2.c
        src/main.c
        src/print_result.c
        src/print_result2.c
        src/validation_add_rooms_links.c
        src/validation_fill_links_rooms.c
        src/validation_get_line.c
        src/validation_get_links.c
        src/validation_get_num_ants.c
        src/validation_get_number.c
        src/validation_get_rooms.c
        src/validation_init.c
        src/validation_parse_input.c
        src/validation_set_error_free.c
        src/validation_set_room_name.c
        src/validation_test_empty_links.c)
