/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_before_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 03:33:04 by rlamtaou          #+#    #+#             */
/*   Updated: 2024/02/01 05:23:09 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/libft_bonus.h"

int	ft_check_up(t_all_about_map *map)
{
	if (map->map_info.map[map->x_player - 1][map->y_player] == 'C')
	{
		map->coins_colect++;
		map->flag_c = 1;
	}
	else if (map->flag_door == '1' && map->map_info.map[map->x_player
			- 1][map->y_player] == 'E')
		ft_end_game(map, 'w');
	else if (map->map_info.map[map->x_player - 1][map->y_player] == 'M')
		ft_end_game(map, 'l');
	else if (map->map_info.map[map->x_player - 1][map->y_player] != '1'
		&& map->map_info.map[map->x_player - 1][map->y_player] != 'E'
		&& map->map_info.map[map->x_player - 1][map->y_player] != 'B'
		&& map->map_info.map[map->x_player - 1][map->y_player] != 'S'
		&& map->map_info.map[map->x_player - 1][map->y_player] != 'W')
		return (1);
	else
		return (0);
	return (1);
}

int	ft_check_right(t_all_about_map *map)
{
	if (map->map_info.map[map->x_player][map->y_player + 1] == 'C')
	{
		map->coins_colect++;
		map->flag_c = 1;
	}
	else if (map->flag_door == '1'
		&& map->map_info.map[map->x_player][map->y_player + 1] == 'E')
		ft_end_game(map, 'w');
	else if (map->map_info.map[map->x_player][map->y_player + 1] == 'M')
		ft_end_game(map, 'l');
	else if (map->map_info.map[map->x_player][map->y_player + 1] != '1'
		&& map->map_info.map[map->x_player][map->y_player + 1] != 'E'
		&& map->map_info.map[map->x_player][map->y_player + 1] != 'B'
		&& map->map_info.map[map->x_player][map->y_player + 1] != 'S'
		&& map->map_info.map[map->x_player][map->y_player + 1] != 'W')
		return (1);
	else
		return (0);
	return (1);
}

int	ft_check_left(t_all_about_map *map)
{
	if (map->map_info.map[map->x_player][map->y_player - 1] == 'C')
	{
		map->coins_colect++;
		map->flag_c = 1;
	}
	else if (map->flag_door == '1'
		&& map->map_info.map[map->x_player][map->y_player - 1] == 'E')
		ft_end_game(map, 'w');
	else if (map->map_info.map[map->x_player][map->y_player - 1] == 'M')
		ft_end_game(map, 'l');
	else if (map->map_info.map[map->x_player][map->y_player - 1] != '1'
		&& map->map_info.map[map->x_player][map->y_player - 1] != 'E'
		&& map->map_info.map[map->x_player][map->y_player - 1] != 'B'
		&& map->map_info.map[map->x_player][map->y_player - 1] != 'S'
		&& map->map_info.map[map->x_player][map->y_player - 1] != 'W')
		return (1);
	else
		return (0);
	return (1);
}

int	ft_check_down(t_all_about_map *map)
{
	if (map->map_info.map[map->x_player + 1][map->y_player] == 'C')
	{
		map->coins_colect++;
		map->flag_c = 1;
	}
	else if (map->flag_door == '1' && map->map_info.map[map->x_player
			+ 1][map->y_player] == 'E')
		ft_end_game(map, 'w');
	else if (map->map_info.map[map->x_player + 1][map->y_player] == 'M')
		ft_end_game(map, 'l');
	else if (map->map_info.map[map->x_player + 1][map->y_player] != '1'
		&& map->map_info.map[map->x_player + 1][map->y_player] != 'E'
		&& map->map_info.map[map->x_player + 1][map->y_player] != 'B'
		&& map->map_info.map[map->x_player + 1][map->y_player] != 'S'
		&& map->map_info.map[map->x_player + 1][map->y_player] != 'W')
		return (1);
	else
		return (0);
	return (1);
}

int	ft_check_block(t_all_about_map *map, int key)
{
	if (key == 119 && ft_check_up(map) == 0) 
			return (0);
		else if (key == 115 && ft_check_down(map) == 0) 
			return (0);
		else if (key == 100 && ft_check_right(map) == 0) 
			return (0);
		else if (key == 97 && ft_check_left(map) == 0)
			return (0);
		map->num++;
		ft_string(map);
		return (1);
}
