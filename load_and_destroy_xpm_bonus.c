/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_and_destroy_xpm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 05:38:53 by rlamtaou          #+#    #+#             */
/*   Updated: 2024/02/01 05:38:56 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/libft_bonus.h"

void	*ft_load_check(t_all_about_map *map, char *name)
{
	void	*img;

	img = XPM(map->mlx_x, name, &map->width, &map->height);
	if (img == NULL)
	{
		ft_print_str("error in image\n");
		exit(2);
	}
	return (img);
}

void	ft_load_xpm(t_all_about_map *map)
{
	map->img.grass = ft_load_check(map, "./textures/grass1.xpm");
	map->img.wall_lim = ft_load_check(map, "./textures/wall.xpm");
	map->img.wall = ft_load_check(map, "./textures/wall_s.xpm");
	map->img.player = ft_load_check(map, "./textures/mario_D1.xpm");
	map->img.close_door = ft_load_check(map, "./textures/close_door.xpm");
	map->img.open_door = ft_load_check(map, "./textures/open_door.xpm");
	map->img.collect = ft_load_check(map, "./textures/c1.xpm");
	map->img.barmil = ft_load_check(map, "./textures/barmil.xpm");
	map->img.monster = ft_load_check(map, "./textures/monster_1.xpm");
	map->img.stone = ft_load_check(map, "./textures/stone1.xpm");
}

void	full_coin(t_all_about_map *map)
{
	map->coin_animation[0] = ft_load_check(map, "./textures/c1.xpm");
	map->coin_animation[1] = ft_load_check(map, "./textures/c2.xpm");
	map->coin_animation[2] = ft_load_check(map, "./textures/c3.xpm");
	map->coin_animation[3] = ft_load_check(map, "./textures/c4.xpm");
	map->coin_animation[4] = ft_load_check(map, "./textures/c5.xpm");
	map->coin_animation[5] = ft_load_check(map, "./textures/c6.xpm");
	map->coin_animation[6] = ft_load_check(map, "./textures/c7.xpm");
	map->coin_animation[7] = ft_load_check(map, "./textures/c8.xpm");
	map->coin_animation[8] = NULL;
}

void	free_map(t_all_about_map *map, int x)
{
	while (x < map->map_info.rows)
	{
		free(map->map_info.map[x]);
		x++;
	}
	free(map->map_info.map);
}

void	ft_destroy_img(t_all_about_map *map)
{
	MLX_DEST(map->mlx_x, map->img.grass);
	MLX_DEST(map->mlx_x, map->img.wall_lim);
	MLX_DEST(map->mlx_x, map->img.wall);
	MLX_DEST(map->mlx_x, map->img.player);
	MLX_DEST(map->mlx_x, map->img.close_door);
	MLX_DEST(map->mlx_x, map->img.open_door);
	MLX_DEST(map->mlx_x, map->img.collect);
	MLX_DEST(map->mlx_x, map->img.barmil);
}
