/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_animtion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 05:33:08 by rlamtaou          #+#    #+#             */
/*   Updated: 2024/02/01 05:33:09 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/libft.h"

void	ft_cheak_animition(t_all_about_map *map, t_maps *info)
{
	if (map->map_info.map[info->x][info->y] == 'C' && map->count % 950 == 0
		&& map->flag_c == 0)
	{
		MLX_P(map->mlx_x, map->mlx_win, map->img.grass, info->y * SIZE_OF_ROWS,
			info->x * SIZE_OF_COLS);
		MLX_P(map->mlx_x, map->mlx_win, map->coin_animation[map->x], info->y
			* SIZE_OF_ROWS, info->x * SIZE_OF_COLS);
	}
}

void	ft_coine_move(t_all_about_map *map)
{
	t_maps	info;

	info.x = 0;
	info.i = 0;
	info.j = 0;
	while (info.x < map->map_info.rows)
	{
		info.y = 0;
		while (info.y < map->map_info.cols)
		{
			ft_cheak_animition(map, &info);
			info.y++;
			info.i = info.i + SIZE_OF_ROWS;
		}
		info.i = 0;
		info.j = info.j + SIZE_OF_COLS;
		info.x++;
	}
	map->count++;
	if (map->count % 950 == 0)
		map->x++;
	if (map->x > 7)
		map->x = 0;
	if (map->count >= 951)
		map->count = 0;
}
