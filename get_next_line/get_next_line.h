/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:03:47 by amouassi          #+#    #+#             */
/*   Updated: 2019/12/19 17:18:47 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t		ft_strlen(const char *str);
char		*ft_substr(char const*s, unsigned int start, size_t len);
char		*ft_strjoin(char const*s1, char const *s2);
char		*ft_strdup(const char *s1);
int			get_next_line(int fd, char **line);
int			find_index(char *str, char c);
#endif
