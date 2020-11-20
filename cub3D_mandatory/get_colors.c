/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:35:15 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/10 14:08:37 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			get_colors(t_cub *cub)
{
	cub->ciel = cub->config.c.r * pow(256, 2) + cub->config.c.g *
	pow(256, 1) + cub->config.c.b * pow(256, 0);
	cub->floor = cub->config.f.r * pow(256, 2) + cub->config.f.g *
	pow(256, 1) + cub->config.f.b * pow(256, 0);
}
