/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:34:32 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/10 15:20:19 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file.h"
#include "cub.h"
#include "mlx.h"

void		ft_sub_raycasting(t_cub *cub, t_cast *cast, int i, int *side)
{
	cast->cam = 2 * i / (double)cub->config.r.x - 1;
	cast->raydir.x = cub->player.dir.x + cub->player.plane.x * cast->cam;
	cast->raydir.y = cub->player.dir.y + cub->player.plane.y * cast->cam;
	cast->map.x = (int)cub->player.pos.x;
	cast->map.y = (int)cub->player.pos.y;
	cast->delta.dist_x = fabs(1 / cast->raydir.x);
	cast->delta.dist_y = fabs(1 / cast->raydir.y);
	ft_check_raydir(cast, cub);
	ft_check_hit(cast, cub, side);
}

void		ft_create_image(t_cub *cub)
{
	if (cub->mlx.img.img_ptr)
		mlx_destroy_image(cub->mlx.mlx_ptr, cub->mlx.img.img_ptr);
	cub->mlx.img.img_ptr = mlx_new_image(cub->mlx.mlx_ptr,
	cub->config.r.x, cub->config.r.y);
	cub->mlx.img.data = (int *)mlx_get_data_addr(cub->mlx.img.img_ptr,
	&cub->mlx.img.bpp, &cub->mlx.img.size_l, &cub->mlx.img.endian);
}

void		ft_help_raycasting(t_cub *cub, double buf[cub->config.r.x])
{
	ft_cast_sprite(cub, buf);
	if (g_save == 1)
	{
		save_bmp(cub);
		exit(0);
	}
}

void		ft_colors_textures(t_cub *cub)
{
	ft_load_textures(cub);
	get_colors(cub);
}

void		ft_raycasting(t_cub *cub)
{
	int		side;
	int		i;
	t_cast	cast;
	double	buf[cub->config.r.x];

	ft_colors_textures(cub);
	cast.text.width = cub->texture[0].width;
	cast.text.height = cub->texture[0].hieght;
	i = 0;
	ft_create_image(cub);
	ft_draw_floor_ceil(cub);
	while (i < cub->config.r.x)
	{
		ft_sub_raycasting(cub, &cast, i, &side);
		cast.perp_dist = ft_check_side(&cast, cub, &side);
		cast.s_step = 1.0 * cast.text.height / cast.line_h;
		cast.tex_pos = (cast.draw.start - cub->config.r.y / 2 +
		cast.line_h / 2) * cast.s_step;
		ft_draw_walls(&cast, cub, side, i);
		buf[i] = cast.perp_dist;
		i++;
	}
	ft_help_raycasting(cub, buf);
	mlx_put_image_to_window(cub->mlx.mlx_ptr, cub->mlx.win,
	cub->mlx.img.img_ptr, 0, 0);
}
