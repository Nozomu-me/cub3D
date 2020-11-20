/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:08:59 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/12 15:04:50 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file.h"

void		ft_check_colors(char *str, t_infos *infos)
{
	if (ft_strncmp(str, "C", ft_bigger_len(str, "C")) == 0)
	{
		if (infos->c.r != -1 && infos->c.g != -1 && infos->c.b != -1)
			ft_print_error("Error\ndouble color error", infos);
	}
	if (ft_strncmp(str, "F", ft_bigger_len(str, "F")) == 0)
	{
		if (infos->f.r != -1 && infos->f.g != -1 && infos->f.b != -1)
			ft_print_error("Error\ndouble color error", infos);
	}
}

char		**ft_sub_parsing_colors(char *str, char **split, t_infos *infos)
{
	int		i;
	char	**rgb;

	i = 0;
	while (split[i] != NULL)
		i++;
	if (i > 2 || ft_strncmp(split[0], str, ft_bigger_len(split[0], str)))
		ft_print_error("Error\ncolors format error", infos);
	i = 0;
	rgb = ft_split(split[1], ',');
	while (rgb[i] != NULL)
	{
		if (!ft_isnumeric(rgb[i]))
			ft_print_error("Error\ncolors format error", infos);
		i++;
	}
	return (rgb);
}

t_colors	ft_parsing_colors(char *line, char *str, t_infos *infos)
{
	t_colors	colors;
	char		**split;
	int			i;
	char		**rgb;

	i = 0;
	ft_check_colors(str, infos);
	split = ft_split(line, ' ');
	rgb = ft_sub_parsing_colors(str, split, infos);
	while (rgb[i] != NULL)
		i++;
	if (i > 3)
		ft_print_error("Error\ncolors format error", infos);
	colors.r = ft_atoi(rgb[0]);
	colors.g = ft_atoi(rgb[1]);
	colors.b = ft_atoi(rgb[2]);
	if ((colors.r < 0 || colors.r > 255) || (colors.r < 0 || colors.r > 255)
	|| (colors.r < 0 || colors.r > 255))
		ft_print_error("Error\ncolors range is not correct", infos);
	ft_free_tab(split);
	ft_free_tab(rgb);
	return (colors);
}
