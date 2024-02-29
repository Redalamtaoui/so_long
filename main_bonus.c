/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 04:42:04 by rlamtaou          #+#    #+#             */
/*   Updated: 2024/01/28 04:42:07 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/libft_bonus.h"

int	ft_change(int key, t_all_about_map *map)
{
	if (key == 53)
		ft_exit(map);
	if (key == 13 && map->flag_k == '0' && ft_check_block(map, key) == 1)
	{
		map->flag_fr = 0;
		map->flag_fu = 'U';
	}
	else if (key == 2 && map->flag_k == '0' && ft_check_block(map, key) == 1)
	{
		map->flag_fr = 0;
		map->flag_fu = 'R';
	}
	else if (key == 0 && map->flag_k == '0' && ft_check_block(map, key) == 1)
	{
		map->flag_fr = 0;
		map->flag_fu = 'L';
	}
	else if (key == 1 && map->flag_k == '0' && ft_check_block(map, key) == 1)
	{
		map->flag_fr = 0;
		map->flag_fu = 'D';
	}
	return (0);
}

int	ft_render_player(t_all_about_map *map)
{
	ft_up_move(map);
	ft_right_move(map);
	ft_left_move(map);
	ft_down_move(map);
	ft_coine_move(map);
	ft_monster(map);
	if (map->coins == map->coins_colect)
		map->coins_colect = ft_render_door(map);
	if (map->flag_k == '7' && map->flag_fr == 10000)
		ft_exit(map);
	if (map->flag_fr <= 10000)
		map->flag_fr++;
	if (map->flag_coins_animtion == 8)
		map->flag_coins_animtion = 0;
	if (map->flag_f_c == 1000)
		map->flag_f_c = 0;
	map->monster_fr++;
	if (map->monster_fr >= 10000)
		map->monster_fr = 0;
	return (0);
}

void	ft_init_var(t_all_about_map *map)
{
	int	i;

	map->flag_fr = 10000;
	map->flag_fu = 'X';
	map->flag_k = '0';
	map->flag_door = '0';
	map->flag_coins_animtion = 0;
	map->flag_f_c = 0;
	map->x = 0;
	map->count = 0;
	map->flag_c = 0;
	map->monster_fr = 0;
	map->coins_colect = 0;
	map->num = 0;
	map->m_flag_move = malloc((map->monsters + 1) * sizeof(int));
	if (map->m_flag_move == NULL)
		ft_exit(map);
	i = 0;
	while (i <= map->monsters)
		map->m_flag_move[i++] = 0;
	map->coin_animation = malloc(9 * 8);
	if (map->coin_animation == NULL)
		ft_exit(map);
	full_coin(map);
}

void	ft_init_and_draw(t_all_about_map *map)
{
	map->mlx_x = mlx_init();
	if (map->mlx_x == NULL)
	{
		ft_print_str("error in connection\n");
		free_map(map, 0);
		free(map->map_in_one_line);
		exit(2);
	}
	map->mlx_win = mlx_new_window(map->mlx_x, map->map_info.cols * SIZE_OF_ROWS,
			map->map_info.rows * SIZE_OF_COLS, "Mrio_1337");
	if (map->mlx_win == NULL)
	{
		ft_print_str("error in window\n");
		free_map(map, 0);
		free(map->map_in_one_line);
		exit(2);
	}
	ft_load_xpm(map);
	ft_draw_map(map);
	ft_init_var(map);
}

int	main(int ac, char **av)
{
	t_all_about_map	map;

	if (ac == 2)
	{
		map.fd = open(av[1], 'r');
		if (map.fd == -1)
			ft_error('4');
		map.path_name = av[1];
		full_check_map(&map);
		close(map.fd);
		ft_init_and_draw(&map);
		mlx_string_put(map.mlx_x, map.mlx_win, 10, 10, 0xFFFFFF,
			"Number Of Move:0");
		mlx_key_hook(map.mlx_win, ft_change, &map);
		mlx_hook(map.mlx_win, 17, 0, destroy, &map);
		mlx_loop_hook(map.mlx_x, ft_render_player, &map);
		mlx_loop(map.mlx_x);
	}
}
