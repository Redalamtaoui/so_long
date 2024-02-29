/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 05:38:22 by rlamtaou          #+#    #+#             */
/*   Updated: 2024/02/01 05:38:24 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/libft_bonus.h"

int	ft_isvalide_path(t_all_about_map *map, int x, int y, char block)
{
	if (x < 0 || x >= map->map_info.rows || y < 0 || y >= map->map_info.cols)
		return (0);
	if (map->copy_of_map[x][y] == block || map->copy_of_map[x][y] == '1'
		|| map->copy_of_map[x][y] == 'W' || map->copy_of_map[x][y] == 'S'
		|| map->copy_of_map[x][y] == 'B' || map->copy_of_map[x][y] == 'V')
		return (0);
	map->copy_of_map[x][y] = 'V';
	if (ft_isvalide_path(map, x + 1, y, block) || ft_isvalide_path(map, x - 1,
			y, block) || ft_isvalide_path(map, x, y + 1, block)
		|| ft_isvalide_path(map, x, y - 1, block))
		return (1);
	return (0);
}

void	ft_path(t_all_about_map *map, int x, int y, int check)
{
	while (map->copy_of_map[x])
	{
		y = 0;
		while (map->copy_of_map[x][y])
		{
			if (map->copy_of_map[x][y] == 'C' && check == 2)
				ft_error('3');
			if (map->copy_of_map[x][y] == 'E' && check == 1)
				ft_error('3');
			y++;
		}
		x++;
	}
}

void	ft_player_path(t_all_about_map *map, int x, int y)
{
	map->map_info.map = ft_split(map->map_in_one_line, '\n');
	while (map->map_info.map[x])
	{
		y = 0;
		while (map->map_info.map[x][y])
		{
			if (map->map_info.map[x][y] == 'P')
			{
				map->x_player = x;
				map->y_player = y;
				map->x_pixl = map->x_player * SIZE_OF_COLS;
				map->y_pixl = map->y_player * SIZE_OF_ROWS;
				return ;
			}
			y++;
		}
		x++;
	}
}
