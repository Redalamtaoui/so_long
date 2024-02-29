/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_and_end_game.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 06:57:46 by rlamtaou          #+#    #+#             */
/*   Updated: 2024/02/01 06:57:47 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/libft_bonus.h"

void	ft_end_game(t_all_about_map *map, char name)
{
	mlx_destroy_window(map->mlx_x, map->mlx_win);
	map->mlx_win = mlx_new_window(map->mlx_x, 1024, 576, "end_game");
	if (name == 'w')
		map->img.wall = ft_load_check(map, "./textures/win_game.xpm");
	else if (name == 'l')
		map->img.wall = ft_load_check(map, "./textures/game_over.xpm");
	MLX_P(map->mlx_x, map->mlx_win, map->img.wall, 0, 0);
	map->flag_k = '7';
	map->flag_fr = 0;
	map->flag_c = 1;
}

void	ft_exit(t_all_about_map *map)
{
	mlx_clear_window(map->mlx_x, map->mlx_win);
	ft_destroy_img(map);
	mlx_destroy_window(map->mlx_x, map->mlx_win);
	free_map(map, 0);
	free(map->map_in_one_line);
	exit(2);
}

int	destroy(t_all_about_map *map)
{
	ft_exit(map);
	return (0);
}

void	ft_error(char error)
{
	if (error == '1')
	{
		ft_print_str("invalide extension\n");
		exit(2);
	}
	if (error == '2')
	{
		ft_print_str("invalide map\n");
		exit(2);
	}
	if (error == '3')
	{
		ft_print_str("invalide path\n");
		exit(2);
	}
	if (error == '4')
	{
		ft_print_str("invalide file\n");
		exit(2);
	}
}

void	free_copy_map(t_all_about_map *map, int x)
{
	while (x < map->map_info.rows)
	{
		free(map->copy_of_map[x]);
		x++;
	}
	free(map->copy_of_map);
}
