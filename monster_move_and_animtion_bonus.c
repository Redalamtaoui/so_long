/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_move_and_animtion.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 07:06:43 by rlamtaou          #+#    #+#             */
/*   Updated: 2024/02/01 07:06:45 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/libft_bonus.h"

void	ft_right_monster(t_all_about_map *map, t_maps *info)
{
	if (map->map_info.map[info->x][info->y + 1] == 'P')
	{
		ft_end_game(map, 'l');
		return ;
	}
	map->new_m_x = info->x * SIZE_OF_COLS;
	map->new_m_y = info->y * SIZE_OF_ROWS;
	MLX_P(map->mlx_x, map->mlx_win, map->img.grass, map->new_m_y, map->new_m_x);
	map->new_m_x = info->x * SIZE_OF_COLS;
	map->new_m_y = (info->y + 1) * SIZE_OF_ROWS;
	MLX_P(map->mlx_x, map->mlx_win, map->img.monster, map->new_m_y,
		map->new_m_x);
	map->map_info.map[info->x][info->y + 1] = 'M';
	map->map_info.map[info->x][info->y] = '0';
	info->y++;
}

void	ft_left_monster(t_all_about_map *map, t_maps *info)
{
	if (map->map_info.map[info->x][info->y - 1] == 'P')
	{
		ft_end_game(map, 'l');
		return ;
	}
	map->new_m_x = info->x * SIZE_OF_COLS;
	map->new_m_y = info->y * SIZE_OF_ROWS;
	MLX_P(map->mlx_x, map->mlx_win, map->img.grass, map->new_m_y, map->new_m_x);
	map->new_m_x = info->x * SIZE_OF_COLS;
	map->new_m_y = (info->y - 1) * SIZE_OF_ROWS;
	MLX_P(map->mlx_x, map->mlx_win, map->img.monster, map->new_m_y,
		map->new_m_x);
	map->map_info.map[info->x][info->y - 1] = 'M';
	map->map_info.map[info->x][info->y] = '0';
	info->y++;
}

void	ft_move_m(t_all_about_map *map, t_maps *info)
{
	if (map->map_info.map[info->x][info->y + 1] != '1'
		&& map->map_info.map[info->x][info->y + 1] != 'B'
		&& map->map_info.map[info->x][info->y + 1] != 'M'
		&& map->map_info.map[info->x][info->y + 1] != 'C'
		&& map->map_info.map[info->x][info->y + 1] != 'D'
		&& map->map_info.map[info->x][info->y + 1] != 'W'
		&& map->m_flag_move[map->m_flag_count] == 0 && map->monster_fr == 500)
		ft_right_monster(map, info);
	else if (map->map_info.map[info->x][info->y - 1] != '1'
		&& map->map_info.map[info->x][info->y - 1] != 'B'
		&& map->map_info.map[info->x][info->y - 1] != 'M'
		&& map->map_info.map[info->x][info->y - 1] != 'C'
		&& map->map_info.map[info->x][info->y - 1] != 'D'
		&& map->map_info.map[info->x][info->y - 1] != 'W'
		&& map->m_flag_move[map->m_flag_count] == 1 && map->monster_fr == 500)
		ft_left_monster(map, info);
}

int	ft_is_true(t_all_about_map *map, t_maps *info, int flag)
{
	if (flag == 1)
		if (map->map_info.map[info->x][info->y + 1] == '1'
			|| map->map_info.map[info->x][info->y + 1] == 'B'
			|| map->map_info.map[info->x][info->y + 1] == 'M'
			|| map->map_info.map[info->x][info->y + 1] == 'C'
			|| map->map_info.map[info->x][info->y + 1] == 'D'
			|| map->map_info.map[info->x][info->y + 1] == 'W')
			return (1);
	if (flag == 2)
		if (map->map_info.map[info->x][info->y - 1] == '1'
			|| map->map_info.map[info->x][info->y - 1] == 'B'
			|| map->map_info.map[info->x][info->y - 1] == 'M'
			|| map->map_info.map[info->x][info->y - 1] == 'C'
			|| map->map_info.map[info->x][info->y - 1] == 'D'
			|| map->map_info.map[info->x][info->y - 1] == 'W')
			return (1);
	return (0);
}

void	ft_monster(t_all_about_map *map)
{
	t_maps	info;

	map->m_flag_count = 0;
	info.x = 0;
	while (info.x < map->map_info.rows)
	{
		info.y = 0;
		while (info.y < map->map_info.cols)
		{
			if (map->map_info.map[info.x][info.y] == 'M')
			{
				if (ft_is_true(map, &info, 1) == 1)
					map->m_flag_move[map->m_flag_count] = 1;
				else if (ft_is_true(map, &info, 2) == 1)
					map->m_flag_move[map->m_flag_count] = 0;
				if (map->flag_c != 1)
					ft_move_m(map, &info);
				map->m_flag_count++;
			}
			info.y++;
		}
		info.x++;
	}
}
