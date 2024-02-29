/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 05:34:24 by rlamtaou          #+#    #+#             */
/*   Updated: 2024/02/01 05:34:27 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/libft.h"

void	ft_put_img(t_all_about_map *map, char gool, t_maps *info)
{
	MLX_P(map->mlx_x, map->mlx_win, map->img.grass, info->i, info->j);
	if (gool == '1')
		MLX_P(map->mlx_x, map->mlx_win, map->img.wall_lim, info->i, info->j);
	else if (gool == 'E')
		MLX_P(map->mlx_x, map->mlx_win, map->img.close_door, info->i, info->j);
	else if (gool == 'P')
		MLX_P(map->mlx_x, map->mlx_win, map->img.player, info->i, info->j);
	else if (gool == 'B')
		MLX_P(map->mlx_x, map->mlx_win, map->img.barmil, info->i, info->j);
	else if (gool == 'C')
		MLX_P(map->mlx_x, map->mlx_win, map->img.collect, info->i, info->j);
	else if (gool == 'M')
		MLX_P(map->mlx_x, map->mlx_win, map->img.monster, info->i, info->j);
	else if (gool == 'S')
		MLX_P(map->mlx_x, map->mlx_win, map->img.stone, info->i, info->j);
	else if (gool == 'W')
		MLX_P(map->mlx_x, map->mlx_win, map->img.wall, info->i, info->j);
}

void	ft_draw_map(t_all_about_map *map)
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
			if (map->map_info.map[info.x][info.y] == 'E')
			{
				map->x_door = info.x;
				map->y_door = info.y;
			}
			ft_put_img(map, map->map_info.map[info.x][info.y], &info);
			info.y++;
			info.i = info.i + SIZE_OF_ROWS;
		}
		info.i = 0;
		info.j = info.j + SIZE_OF_COLS;
		info.x++;
	}
}

void	ft_draw_block(char *player_move, t_all_about_map *map)
{
	MLX_DEST(map->mlx_x, map->img.player);
	if (map->flag_fu == 'L')
	{
		map->y_old = map->y_pixl + 12;
		map->x_old = map->x_pixl;
	}
	else if (map->flag_fu == 'R')
	{
		map->y_old = map->y_pixl - 12;
		map->x_old = map->x_pixl;
	}
	else if (map->flag_fu == 'U')
	{
		map->y_old = map->y_pixl;
		map->x_old = map->x_pixl + 15;
	}
	else if (map->flag_fu == 'D')
	{
		map->y_old = map->y_pixl;
		map->x_old = map->x_pixl - 15;
	}
	map->img.player = ft_load_check(map, player_move);
	MLX_P(map->mlx_x, map->mlx_win, map->img.grass, map->y_old, map->x_old);
	MLX_P(map->mlx_x, map->mlx_win, map->img.player, map->y_pixl, map->x_pixl);
}
