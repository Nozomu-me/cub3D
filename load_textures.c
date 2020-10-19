/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:01:57 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/14 16:04:43 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file.h"
#include "cub.h"
#include "mlx.h"

void		ft_sub_load_textures(t_cub *cub)
{
	cub->texture[0].img_ptr = mlx_xpm_file_to_image(cub->mlx.mlx_ptr,
	cub->config.no, &cub->texture[0].width, &cub->texture[0].hieght);
	cub->texture[1].img_ptr = mlx_xpm_file_to_image(cub->mlx.mlx_ptr,
	cub->config.so, &cub->texture[1].width, &cub->texture[1].hieght);
	cub->texture[2].img_ptr = mlx_xpm_file_to_image(cub->mlx.mlx_ptr,
	cub->config.we, &cub->texture[2].width, &cub->texture[2].hieght);
	cub->texture[3].img_ptr = mlx_xpm_file_to_image(cub->mlx.mlx_ptr,
	cub->config.ea, &cub->texture[3].width, &cub->texture[3].hieght);
	cub->texture[4].img_ptr = mlx_xpm_file_to_image(cub->mlx.mlx_ptr,
	cub->config.s, &cub->texture[4].width, &cub->texture[4].hieght);
}

void		ft_load_textures(t_cub *cub)
{
	ft_sub_load_textures(cub);
	cub->texture[0].data = (int*)mlx_get_data_addr(cub->texture[0].img_ptr,
	&cub->texture[0].bpp, &cub->texture[0].size_l, &cub->texture[0].endian);
	cub->texture[1].data = (int*)mlx_get_data_addr(cub->texture[1].img_ptr,
	&cub->texture[1].bpp, &cub->texture[1].size_l, &cub->texture[1].endian);
	cub->texture[2].data = (int*)mlx_get_data_addr(cub->texture[2].img_ptr,
	&cub->texture[2].bpp, &cub->texture[2].size_l, &cub->texture[2].endian);
	cub->texture[3].data = (int*)mlx_get_data_addr(cub->texture[3].img_ptr,
	&cub->texture[3].bpp, &cub->texture[3].size_l, &cub->texture[3].endian);
	cub->texture[4].data = (int*)mlx_get_data_addr(cub->texture[4].img_ptr,
	&cub->texture[4].bpp, &cub->texture[4].size_l, &cub->texture[4].endian);
}
