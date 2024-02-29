/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 05:50:01 by rlamtaou          #+#    #+#             */
/*   Updated: 2024/02/01 05:50:03 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/libft.h"

void	ft_change_position(t_all_about_map *map)
{
	if (map->flag_fu == 'R')
	{
		map->map_info.map[map->x_player][map->y_player + 1] = 'P';
		map->map_info.map[map->x_player][map->y_player] = '0';
		map->y_player = map->y_player + 1;
	}
	if (map->flag_fu == 'L')
	{
		map->map_info.map[map->x_player][map->y_player - 1] = 'P';
		map->map_info.map[map->x_player][map->y_player] = '0';
		map->y_player = map->y_player - 1;
	}
	if (map->flag_fu == 'U')
	{
		map->map_info.map[map->x_player - 1][map->y_player] = 'P';
		map->map_info.map[map->x_player][map->y_player] = '0';
		map->x_player = map->x_player - 1;
	}
	if (map->flag_fu == 'D')
	{
		map->map_info.map[map->x_player + 1][map->y_player] = 'P';
		map->map_info.map[map->x_player][map->y_player] = '0';
		map->x_player = map->x_player + 1;
	}
}

void	ft_right_move(t_all_about_map *map)
{
	if (map->flag_fr == 500 && map->flag_fu == 'R' && map->flag_k == '0')
	{
		map->y_pixl += 12;
		ft_draw_block("./textures/mario_R2.xpm", map);
		map->flag_k = '1';
	}
	else if (map->flag_fr == 1000 && map->flag_fu == 'R' && map->flag_k == '1')
	{
		map->y_pixl += 12;
		ft_draw_block("./textures/mario_R3.xpm", map);
		map->flag_k = '2';
	}
	else if (map->flag_fr == 1500 && map->flag_fu == 'R' && map->flag_k == '2')
	{
		map->y_pixl += 12;
		ft_draw_block("./textures/mario_R2.xpm", map);
		map->flag_k = '3';
	}
	else if (map->flag_fr == 2000 && map->flag_fu == 'R' && map->flag_k == '3')
	{
		map->y_pixl += 12;
		ft_draw_block("./textures/mario_R1.xpm", map);
		ft_print_shell(map);
		ft_change_position(map);
	}
}

void	ft_left_move(t_all_about_map *map)
{
	if (map->flag_fr == 500 && map->flag_fu == 'L' && map->flag_k == '0')
	{
		map->y_pixl -= 12;
		ft_draw_block("./textures/mario_L2.xpm", map);
		map->flag_k = '1';
	}
	else if (map->flag_fr == 1000 && map->flag_fu == 'L' && map->flag_k == '1')
	{
		map->y_pixl -= 12;
		ft_draw_block("./textures/mario_L3.xpm", map);
		map->flag_k = '2';
	}
	else if (map->flag_fr == 1500 && map->flag_fu == 'L' && map->flag_k == '2')
	{
		map->y_pixl -= 12;
		ft_draw_block("./textures/mario_L2.xpm", map);
		map->flag_k = '3';
	}
	else if (map->flag_fr == 2000 && map->flag_fu == 'L' && map->flag_k == '3')
	{
		map->y_pixl -= 12;
		ft_draw_block("./textures/mario_L1.xpm", map);
		ft_print_shell(map);
		ft_change_position(map);
	}
}

void	ft_up_move(t_all_about_map *map)
{
	if (map->flag_fr == 500 && map->flag_fu == 'U' && map->flag_k == '0')
	{
		map->x_pixl -= 15;
		ft_draw_block("./textures/mario_U2.xpm", map);
		map->flag_k = '1';
	}
	else if (map->flag_fr == 1000 && map->flag_fu == 'U' && map->flag_k == '1')
	{
		map->x_pixl -= 15;
		ft_draw_block("./textures/mario_U3.xpm", map);
		map->flag_k = '2';
	}
	else if (map->flag_fr == 1500 && map->flag_fu == 'U' && map->flag_k == '2')
	{
		map->x_pixl -= 15;
		ft_draw_block("./textures/mario_U2.xpm", map);
		map->flag_k = '3';
	}
	else if (map->flag_fr == 2000 && map->flag_fu == 'U' && map->flag_k == '3')
	{
		map->x_pixl -= 15;
		ft_draw_block("./textures/mario_U1.xpm", map);
		ft_print_shell(map);
		ft_change_position(map);
	}
}

void	ft_down_move(t_all_about_map *map)
{
	if (map->flag_fr == 500 && map->flag_fu == 'D' && map->flag_k == '0')
	{
		map->x_pixl += 15;
		ft_draw_block("./textures/mario_D2.xpm", map);
		map->flag_k = '1';
	}
	else if (map->flag_fr == 1000 && map->flag_fu == 'D' && map->flag_k == '1')
	{
		map->x_pixl += 15;
		ft_draw_block("./textures/mario_D3.xpm", map);
		map->flag_k = '2';
	}
	else if (map->flag_fr == 1500 && map->flag_fu == 'D' && map->flag_k == '2')
	{
		map->x_pixl += 15;
		ft_draw_block("./textures/mario_D2.xpm", map);
		map->flag_k = '3';
	}
	else if (map->flag_fr == 2000 && map->flag_fu == 'D' && map->flag_k == '3')
	{
		map->x_pixl += 15;
		ft_draw_block("./textures/mario_D1.xpm", map);
		ft_print_shell(map);
		ft_change_position(map);
	}
}
