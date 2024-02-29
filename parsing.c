/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 06:44:32 by rlamtaou          #+#    #+#             */
/*   Updated: 2024/02/01 06:54:36 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/libft.h"

void	ft_cheak_name(t_all_about_map *map, int x, int y, char *exten)
{
	x = ft_strlen(map->path_name) - 4;
	while (exten[y])
		if (exten[y++] != map->path_name[x++])
			ft_error('1');
}

void	ft_cheak_map3(t_all_about_map *map, int x)
{
	while (map->map_in_one_line[x])
	{
		if (map->map_in_one_line[x] != 'P' && map->map_in_one_line[x] != 'E'
			&& map->map_in_one_line[x] != 'C' && map->map_in_one_line[x] != 'M'
			&& map->map_in_one_line[x] != 'B' && map->map_in_one_line[x] != 'W'
			&& map->map_in_one_line[x] != 'S' && map->map_in_one_line[x] != '1'
			&& map->map_in_one_line[x] != '0'
			&& map->map_in_one_line[x] != '\n')
			ft_error('2');
		x++;
	}
	x = (map->map_info.cols + 1) * (map->map_info.rows - 1);
	while (map->map_in_one_line[x])
		if (map->map_in_one_line[x++] != '1')
			ft_error('2');
}

void	ft_cheak_map2(t_all_about_map *map, int x, int len)
{
	while (map->map_in_one_line[x])
	{
		if (map->map_in_one_line[x] == 'P')
			map->player++;
		else if (map->map_in_one_line[x] == 'E')
			map->door++;
		else if (map->map_in_one_line[x] == 'C')
			map->coins++;
		else if (map->map_in_one_line[x] == 'M')
			map->monsters++;
		else if (map->map_in_one_line[x] == '\n')
		{
			if (len == map->map_info.cols)
				len = 0;
			else
				ft_error('2');
			x++;
		}
		x++;
		len++;
	}
	if (map->map_in_one_line[x] == '\0' && len != map->map_info.cols)
		ft_error('2');
	if (map->player != 1 || map->door != 1 || map->coins < 1)
		ft_error('2');
}

void	ft_cheak_map1(t_all_about_map *map, int x)
{
	while (map->end_read == 0)
		map->map_in_one_line = ft_strjoin(map->map_in_one_line,
				get_next_line(map->fd, map), 1);
	if (map->map_in_one_line == NULL
		|| map->map_in_one_line[map->map_info.cols] == '\n')
		ft_error('2');
	while (map->map_in_one_line[map->map_info.cols] != '\n')
		if (map->map_in_one_line[map->map_info.cols++] != '1')
			ft_error('2');
	while (map->map_in_one_line[x++])
		if ((map->map_in_one_line[x] == '\n' && map->map_in_one_line[x
					+ 1] == '\n') || (map->map_in_one_line[x] == '\n'
				&& map->map_in_one_line[x + 1] == '\0')
			|| (map->map_in_one_line[x] == '\n' && map->map_in_one_line[x
					+ 1] != '1') || (map->map_in_one_line[x] == '\n'
				&& map->map_in_one_line[x - 1] != '1'))
			ft_error('2');
	else if (map->map_in_one_line[x] == '\n')
		map->map_info.rows++;
	map->map_info.rows++;
	ft_cheak_map2(map, 0, 0);
	ft_cheak_map3(map, 0);
}

void	full_check_map(t_all_about_map *map)
{
	map->map_in_one_line = NULL;
	map->end_read = 0;
	map->map_info.cols = 0;
	map->map_info.rows = 0;
	map->player = 0;
	map->door = 0;
	map->coins = 0;
	ft_cheak_name(map, 0, 0, ".ber");
	ft_cheak_map1(map, 0);
	ft_player_path(map, 0, 0);
	map->copy_of_map = ft_split(map->map_in_one_line, '\n');
	ft_path(map, ft_isvalide_path(map, map->x_player, map->y_player, '1'), 0,
		1);
	free_copy_map(map, 0);
	map->copy_of_map = ft_split(map->map_in_one_line, '\n');
	ft_path(map, ft_isvalide_path(map, map->x_player, map->y_player, 'E'), 0,
		2);
	free_copy_map(map, 0);
}
