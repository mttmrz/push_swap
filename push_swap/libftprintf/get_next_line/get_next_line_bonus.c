/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bianca <bianca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:48:46 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/21 10:13:01 by bianca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*no_space(char *str)
{
	free(str);
	return (NULL);
}

char	*ft_turnback(char *s1)
{
	int		i;
	int		b;
	char	*sub;

	i = 0;
	b = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (s1[i] == '\n')
		i++;
	sub = ft_calloc(1, ft_stlen(s1) - i + 1);
	while (s1[b + i])
	{
		sub[b] = s1[i + b];
		b++;
	}
	free(s1);
	if (sub[0] == '\0' )
	{
		free(sub);
		return (NULL);
	}
	return (sub);
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		s2[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
		s2[i] = '\n';
	return (s2);
}

char	*ft_line(char *str, int i, int fd)
{
	static char		*line[1024];
	char			*dest;

	if (i == 0 && (!line[fd] || line[fd] == NULL || line[fd][0] == '\0'))
		return (no_space(str));
	if ((!str || str == NULL) && i == 1)
		return (0);
	if (!line[fd] || line[fd] == NULL)
		line[fd] = ft_calloc(1, BUFFER_SIZE + 1);
	line[fd] = ft_stjoin(line[fd], str);
	if (ft_checkn(line[fd], i) != 0)
	{
		if (i != 2)
			return ("a");
		else if (i == 2)
		{
			dest = ft_calloc(1, ft_checkn(line[fd], i) + 2);
			dest = ft_strcpy(line[fd], dest);
			line[fd] = ft_turnback(line[fd]);
			return (dest);
		}
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*dest;
	ssize_t		b;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	while (ft_line(str, 1, fd) == 0)
	{
		str = ft_calloc(1, BUFFER_SIZE + 1);
		b = read(fd, str, BUFFER_SIZE);
		if (b == 0 || b == -1)
		{
			if (ft_line(str, 0, fd) == NULL)
				return (NULL);
			break ;
		}
	}
	dest = ft_calloc(1, 1);
	dest = ft_line(dest, 2, fd);
	return (dest);
}
