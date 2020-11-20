/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_resol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:07:05 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/12 14:45:38 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file.h"

void		ft_sub_parsing_resol(t_infos *infos)
{
	if (infos->r.x > 2560 || infos->r.y > 1440)
	{
		infos->r.x = 2560;
		infos->r.y = 1440;
	}
	if (infos->r.x < 640 || infos->r.y < 360)
	{
		infos->r.x = 640;
		infos->r.y = 360;
	}
}

void		ft_parsing_resol(char *line, t_infos *infos)
{
	char		**split;
	int			i;

	i = 0;
	if (infos->r.x != 0 || infos->r.y != 0)
		ft_print_error("Error\ndouble resolution error", infos);
	split = ft_split(line, ' ');
	while (split[i] != NULL)
		i++;
	if (i > 3)
		ft_print_error("Error\nresolution format error", infos);
	if (ft_strncmp(split[0], "R", ft_strlen(split[0]))
	|| !ft_isnumeric(split[1])
	|| !ft_isnumeric(split[2]))
		ft_print_error("Error\nresolution format error", infos);
	infos->r.x = ft_atoi(split[1]);
	infos->r.y = ft_atoi(split[2]);
	ft_sub_parsing_resol(infos);
	ft_free_tab(split);
}
