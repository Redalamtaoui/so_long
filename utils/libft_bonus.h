/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:04:09 by rlamtaou          #+#    #+#             */
/*   Updated: 2024/02/01 02:48:10 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include <fcntl.h>
# include <mlx.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define SIZE_OF_ROWS 48
# define SIZE_OF_COLS 60
# define XPM mlx_xpm_file_to_image
# define MLX_DEST mlx_destroy_image
# define MLX_P mlx_put_image_to_window

typedef struct _lines
{
	char		**map;
	int			rows;
	int			cols;
}				t_creat_map;

typedef struct map_imp
{
	int			x;
	int			y;
	int			j;
	int			i;
	int			a;
	int			b;
}				t_maps;

typedef struct _xpm_img
{
	void		*grass;
	void		*wall_lim;
	void		*wall;
	void		*player;
	void		*close_door;
	void		*open_door;
	void		*collect;
	void		*monster;
	void		*barmil;
	void		*stone;
}				t_xpm_img;
typedef struct _map
{
	int			end_read;
	char		*map_in_one_line;
	t_creat_map	map_info;
	char		*path_name;
	char		**copy_of_map;
	int			fd;
	int			coins;
	int			coins_colect;
	int			door;
	int			player;
	int			monsters;
	int			check_path_door;
	int			check_path_coins;

	int			x_player;
	int			y_player;
	int			x_door;
	int			y_door;

	int			x_old;
	int			y_old;
	int			x_pixl;
	int			y_pixl;
	t_xpm_img	img;
	void		*mlx_x;
	void		*mlx_win;
	int			width;
	int			height;

	int			flag_fr;
	char		flag_fu;
	char		flag_k;

	int			flag_coins_animtion;
	int			flag_f_c;
	char		**coin_animation;
	int			x;
	int			count;
	int			flag_c;

	int			monster_fr;
	int			m_flag_count;
	int			*m_flag_move;
	int			new_m_x;
	int			new_m_y;

	char		flag_door;
	int			num;
}				t_all_about_map;

size_t			ft_strlen(char const *str);
void			*ft_calloc(size_t nitems, size_t size);
void			ft_bzero(void *ptr, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char *s1, char *s2, int free_s);
char			*get_next_line(int fd, t_all_about_map *map);
char			**ft_split(char const *s1, char c);
void			full_check_map(t_all_about_map *map);
int				isValidPath(t_all_about_map *map, int x, int y, char block);
void			ft_draw_map(t_all_about_map *map);
void			ft_load_xpm(t_all_about_map *map);
void			ft_destroy_img(t_all_about_map *map);
void			ft_load_xpm(t_all_about_map *map);
void			ft_put_img(t_all_about_map *map, char gool, t_maps *info);
int				ft_change(int key, t_all_about_map *map);
int				ft_render_player(t_all_about_map *map);
void			ft_draw_block(char *player_move, t_all_about_map *map);
void			full_coin(t_all_about_map *map);
void			ft_init_and_draw(t_all_about_map *map);
void			ft_init_var(t_all_about_map *map);
void			ft_exit(t_all_about_map *map);
void			ft_end_game(t_all_about_map *map, char name);
void			ft_change_position(t_all_about_map *map);
void			ft_right_move(t_all_about_map *map);
void			ft_left_move(t_all_about_map *map);
void			ft_up_move(t_all_about_map *map);
void			ft_down_move(t_all_about_map *map);
void			ft_move_m(t_all_about_map *map, t_maps *info);
void			ft_monster(t_all_about_map *map);
void			ft_draw_block(char *player_move, t_all_about_map *map);
void			ft_draw_map(t_all_about_map *map);
void			ft_put_img(t_all_about_map *map, char gool, t_maps *info);
int				ft_render_door(t_all_about_map *map);
void			ft_coine_move(t_all_about_map *map);
int				ft_check_block(t_all_about_map *map, int key);
int				ft_check_down(t_all_about_map *map);
int				ft_check_left(t_all_about_map *map);
int				ft_check_right(t_all_about_map *map);
int				ft_check_up(t_all_about_map *map);
char			*ft_itoa(int n);
void			ft_draw_line(t_all_about_map *map);
void			ft_string(t_all_about_map *map);
void			free_map(t_all_about_map *map, int x);
void			*ft_load_check(t_all_about_map *map, char *name);
int				destroy(t_all_about_map *map);
void			ft_print_shell(t_all_about_map *map);
void			ft_path(t_all_about_map *map, int x, int y, int check);
int				ft_isvalide_path(t_all_about_map *map, int x, int y,
					char block);
void			ft_error(char error);
void			free_copy_map(t_all_about_map *map, int x);
void			ft_player_path(t_all_about_map *map, int x, int y);
void			ft_print_str(char *str);
#endif
