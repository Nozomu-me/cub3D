/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:16:36 by amouassi          #+#    #+#             */
/*   Updated: 2020/03/08 20:49:57 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_file_bonus.h"

int			ft_isnumeric(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char		*ft_charjoin(char const *s1, char c)
{
	int		i;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	str = malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	return (str);
}

int			ft_start_with(char *s1, char *s2)
{
	int		i;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 < len2)
		return (0);
	i = 0;
	while (i < len2)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int			ft_bigger_len(char *s1, char *s2)
{
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (i > j)
		return (i);
	else
		return (j);
}
