/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:24:11 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:24:14 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <unistd.h>

# define LEN_ARRS_LOC 25000
# define LEN_ARRS 250000
# define LEN_STR 44000000
# define KEY_START_ROOM "##start"
# define KEY_END_ROOM "##end"
# define KEY_ICON_COMMENT '#'

typedef struct	s_n
{
	int			num_room;
	struct s_n	*next;
}				t_n;

typedef struct	s_l
{
	int			num_room;
	int			weight;
	int			allow;
	int			del;
	struct s_l	*next;
}				t_l;

typedef struct	s_d
{
	int			num_ants;
	int			num_rooms;
	t_l			**links_rooms;
	t_l			**tmp_pointers_links;
	t_l			*ways[LEN_ARRS_LOC];
	int			*levels_rooms;
	int			*tmp4;
	int			*tmp5;
	int			*room_from;
	int			start;
	int			end;
	char		**rooms_names;
	t_n			**rooms_alphabet;
	int			num_str;
	int			n[LEN_ARRS_LOC];
	int			fd;
	int			len_input_str;
	char		buf[LEN_ARRS_LOC];
	char		b[1];
	int			two_rooms[2];
	int			*x_rooms;
	int			*y_rooms;
	char		*input_str;
	int			c_start;
	int			c_end;
	int			c_steps;
	int			c_pack;
}				t_d;

char			*ft_strdup(const char *s1);
void			*ft_memalloc(size_t size);
int				ft_strequ(char const *s1, char const *s2);
int				ft_isdigit(int c);
void			ft_putnbr_end(int n, char end_symbol);
size_t			ft_strlen(const char *s);
void			ft_putstr_end(char *str, char end_symbol);
void			ft_bzero(void *b, size_t n);
void			find__ways(t_d *d);
void			set_error(t_d *d, char *str_error);
void			free_data(t_d *d, int i, int j);
int				get_number(t_d *d, long long i, int j, long long minus);
int				get_line(t_d *d);
void			get_num_ants(t_d *d);
int				get_cript_number(const char *str);
void			set_room_alpha(t_d *d, t_n *tmp);
void			test_unique_coordinates(t_d *d, int i);
void			set_room_name(t_d *d, int i, int j);
void			get_room(t_d *d, int i, int k);
int				is_room2(t_d *d, char *buf, int j);
int				is_rooms(t_d *d, int n, int j);
int				test_string_on_valid_link(t_d *d, int n);
void			get_rooms(t_d *d);
t_l				*set_new_link_for_room(t_d *d);
int				fill_links_rooms(t_d *d);
void			add_rooms_links(t_d *d);
int				get_links_from_input(t_d *d);
void			delete_links(t_d *d, int room_from, int room_to);
int				test_empty_ways(t_d *d, int i, int j, int k);
int				parse_input(t_d *d);
void			init(t_d *d);
void			write_way_in_packs_ways(t_d *d, int end);
void			back_links_to_original(t_d *d);
void			delete_cur_way(t_d *d, int i);
void			deactive_short_way_and_set_minus(t_d *d, t_l *from, t_l *to);
int				is_minus_ways(t_d *d, t_l *to, t_l *from, t_l *link);
int				find_shortest_way(t_d *d, int i);
void			set_level_to_rooms(t_d *d, int room);
void			copy_tmp5_to_tmp4(t_d *d, int i);
int				wasnt_here(t_d *d, int room, int room_from);
t_l				*get_link(t_d *d, int from, int to);
void			print_result(t_d *d, int i);
void			print_all_in_one_step(t_d *d);
int				count_steps_of_ways(t_d *d, int i, int num_pack);
int				catch_shortest_pack_of_ways(t_d *d, int i, int k);
void			copy_ways(t_d *d, int i);
int				is_use_busy_room(t_d *d, t_l *t_fa, t_l *t_sl, int i);

#endif
