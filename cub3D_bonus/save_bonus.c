/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 20:15:34 by amouassi          #+#    #+#             */
/*   Updated: 2020/10/19 12:09:55 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

t_bmp		new_bmp(int w, int h, t_file_bmp *f_bmp)
{
	t_bmp bmp;

	f_bmp->file_size = 54 + 4 * w * h;
	f_bmp->reserved = 0;
	f_bmp->offset = 54;
	f_bmp->header_size = 54 - 14;
	f_bmp->width = w;
	f_bmp->height = -h;
	bmp.plane[0] = 1;
	bmp.plane[1] = 0;
	bmp.bpp[0] = 32;
	bmp.bpp[1] = 0;
	bmp.compression = 0;
	bmp.bit_size = 4 * w * h;
	bmp.perpexx = 0;
	bmp.perpexy = 0;
	bmp.num_color = 0;
	bmp.imp_color = 0;
	return (bmp);
}

void		write_bytes(int *line, int w, int fd)
{
	int		i;

	i = 0;
	while (i < w)
	{
		write(fd, &line[i], 4);
		i++;
	}
}

void		write_bitmap(int *data, int h, int w, int fd)
{
	int		i;

	i = 0;
	while (i < h)
	{
		write_bytes(&data[i * w], w, fd);
		i++;
	}
}

void            save_bmp(t_cub *cub)
{
    t_bmp       bmp;
    int         fd;
    t_file_bmp  f_bmp;
    bmp = new_bmp(cub->config.r.x, cub->config.r.y, &f_bmp);
    fd = open("save_bonus.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    write(fd, "BM", 2);
    write(fd, &f_bmp, 24);
    write(fd, &bmp, 28);
    write_bitmap(cub->mlx.img.data, cub->config.r.y, cub->config.r.x, fd);
    close(fd);
}
