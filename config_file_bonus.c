/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_file_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:22:34 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/14 14:16:10 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file_bonus.h"

void		ft_sub_config_file(t_infos *infos, char *line)
{
	if (ft_start_with(line, "R"))
		ft_parsing_resol(line, infos);
	else if (ft_start_with(line, "NO"))
		infos->no = ft_parsing_path(line, "NO", infos);
	else if (ft_start_with(line, "SO"))
		infos->so = ft_parsing_path(line, "SO", infos);
	else if (ft_start_with(line, "WE"))
		infos->we = ft_parsing_path(line, "WE", infos);
	else if (ft_start_with(line, "EA"))
		infos->ea = ft_parsing_path(line, "EA", infos);
	else if (ft_start_with(line, "S"))
		infos->s = ft_parsing_path(line, "S", infos);
	else if (ft_start_with(line, "C"))
		infos->c = ft_parsing_path(line, "C", infos);
	else if (ft_start_with(line, "F"))
		infos->f = ft_parsing_path(line, "F", infos);
}

void		ft_config_file_helper(char *str, char *l, t_infos *infos, int fd)
{
	if (ft_isvalid(l[0]) == 0 || (l[0] == ' ' &&
	ft_check_config(infos) == 1))
	{
		free(l);
		ft_print_error("Error\nsome weird things were added", infos);
	}
	ft_sub_config_file(infos, l);
	if (ft_check_config(infos) == 0)
		ft_parsing_map(str, infos, fd);
}

t_infos		ft_config_file(char *str)
{
	int			fd;
	char		*line;
	t_infos		infos;

	ft_struct_init(&infos);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	while (get_next_line(fd, &line) > 0)
	{
		ft_config_file_helper(str, line, &infos, fd);
		free(line);
	}
	if (ft_check_config(&infos) == 1)
	{
		ft_print_error("Error\nsconfig file structure is invalid", &infos);
	}
	return (infos);
}
