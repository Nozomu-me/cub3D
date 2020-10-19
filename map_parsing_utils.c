/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:40:03 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/14 14:20:37 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file.h"

int			ft_isvalid(char c)
{
	if (c == 'R' || c == 'N' || c == 'S' || c == 'W' || c == 'E' ||
	c == 'F' || c == 'C' || c == '1' || c == '\0' || c == ' ')
		return (1);
	return (0);
}

int			ft_isplayer_pos(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	return (0);
}

int			ft_check(t_infos *infos, int i, int j)
{
	if ((i < infos->lines && i > 0) && (j < infos->colomns && j > 0))
	{
		if ((infos->map[i + 1][j] == ' ') || (infos->map[i - 1][j] == ' ') ||
		(infos->map[i][j + 1] == ' ') || (infos->map[i][j - 1] == ' '))
			return (1);
	}
	return (0);
}

int			ft_ismap(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != '0' && str[i] != '1' && str[i] != ' '))
			return (1);
		i++;
	}
	return (0);
}
