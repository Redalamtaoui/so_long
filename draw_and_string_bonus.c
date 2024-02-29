/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 05:35:20 by rlamtaou          #+#    #+#             */
/*   Updated: 2024/02/01 05:35:22 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/libft_bonus.h"

void	ft_print_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_draw_line(t_all_about_map *map)
{
	int	x;

	x = 0;
	while (x < map->map_info.cols)
	{
		MLX_P(map->mlx_x, map->mlx_win, map->img.wall_lim, x * SIZE_OF_ROWS, 0);
		x++;
	}
}

void	ft_string(t_all_about_map *map)
{
	char	*num;
	char	*tmp;

	if (map->flag_c != 1)
	{
		num = ft_itoa(map->num);
		tmp = ft_strjoin("Number Of Move:", num, 0);
		ft_draw_line(map);
		mlx_string_put(map->mlx_x, map->mlx_win, 10, 10, 0xFFFFFF, tmp);
		free(tmp);
		free(num);
	}
}

void	ft_print_shell(t_all_about_map *map)
{
	char	*nums;
	char	*tmp;

	nums = ft_itoa(map->num);
	tmp = nums;
	nums = ft_strjoin(nums, "\n", 0);
	map->flag_k = '0';
	map->flag_c = 0;
	ft_print_str(nums);
	free(nums);
	free(tmp);
}
