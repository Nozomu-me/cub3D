/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:53:57 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/08 20:48:35 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file_bonus.h"
#include "cub_bonus.h"
#include "mlx.h"

int		ft_close(void *param)
{
	(void)param;
	exit(0);
}

int		deel_key(int key, void *param)
{
	t_cub	*cub;

	cub = (t_cub*)param;
	if (key == 53)
		exit(EXIT_FAILURE);
	if (key == 13 || key == 1)
		ft_move_up_down(key, cub);
	if (key == 124 || key == 123)
		ft_rotate(key, cub);
	if (key == 0 || key == 2)
		ft_move_right_left(key, cub);
	mlx_destroy_image(cub->mlx.mlx_ptr, cub->mlx.img.img_ptr);
	cub->mlx.img.img_ptr = mlx_new_image(cub->mlx.mlx_ptr,
	cub->config.r.x, cub->config.r.y);
	ft_raycasting(cub);
	return (0);
}
