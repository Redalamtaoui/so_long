/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 05:33:38 by rlamtaou          #+#    #+#             */
/*   Updated: 2024/02/01 05:33:42 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/libft.h"

int	ft_render_door(t_all_about_map *map)
{
	MLX_P(map->mlx_x, map->mlx_win, map->img.grass, map->y_door * SIZE_OF_ROWS,
		map->x_door * SIZE_OF_COLS);
	MLX_P(map->mlx_x, map->mlx_win, map->img.open_door, map->y_door
		* SIZE_OF_ROWS, map->x_door * SIZE_OF_COLS);
	map->flag_door = '1';
	return (0);
}
