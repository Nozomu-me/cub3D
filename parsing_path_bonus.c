/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:08:02 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/10 14:12:03 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file_bonus.h"

void		ft_sub_check_path(char *str, t_infos *infos)
{
	if (ft_strncmp(str, "S", ft_bigger_len(str, "S")) == 0)
	{
		if (infos->s != NULL)
			ft_print_error("Error\ndouble path error", infos);
	}
	else if (ft_strncmp(str, "F", ft_bigger_len(str, "F")) == 0)
	{
		if (infos->f != NULL)
			ft_print_error("Error\ndouble path error", infos);
	}
	else if (ft_strncmp(str, "C", ft_bigger_len(str, "C")) == 0)
	{
		if (infos->c != NULL)
			ft_print_error("Error\ndouble path error", infos);
	}
}

void		ft_check_path(char *str, t_infos *infos)
{
	if (ft_strncmp(str, "NO", ft_bigger_len(str, "NO")) == 0)
	{
		if (infos->no != NULL)
			ft_print_error("Error\ndouble path error", infos);
	}
	else if ((ft_strncmp(str, "SO", ft_bigger_len(str, "SO")) == 0))
	{
		if (infos->so != NULL)
			ft_print_error("Error\ndouble path error", infos);
	}
	else if (ft_strncmp(str, "WE", ft_bigger_len(str, "WE")) == 0)
	{
		if (infos->we != NULL)
			ft_print_error("Error\ndouble path error", infos);
	}
	else if (ft_strncmp(str, "EA", ft_bigger_len(str, "EA")) == 0)
	{
		if (infos->ea != NULL)
			ft_print_error("Error\ndouble path error", infos);
	}
	ft_sub_check_path(str, infos);
}

char		*ft_parsing_path(char *line, char *str, t_infos *infos)
{
	char		**split;
	int			i;
	int			fd;
	char		*path;

	i = 0;
	ft_check_path(str, infos);
	split = ft_split(line, ' ');
	while (split[i] != NULL)
		i++;
	if (i > 2 || ft_strncmp(split[0], str, ft_bigger_len(split[0], str)))
		ft_print_error("Error\npath format error", infos);
	fd = open(split[1], O_RDONLY);
	if (fd == -1)
		ft_print_error("Error\npath not found", infos);
	path = ft_strdup(split[1]);
	ft_free_tab(split);
	close(fd);
	return (path);
}
