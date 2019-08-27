/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:48:19 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/17 17:46:49 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_endl_or_end(char *str)
{
	int i;

	i = 0;
	while (!(str[i] == '\n' || !str[i]))
		i++;
	return (i);
}

static int	trim_content(char **content, char **line)
{
	int		i;
	char	*tmp;

	i = find_endl_or_end(*content);
	if (!(*content)[i])
	{
		*line = ft_strdup(*content);
		ft_strdel(content);
		if (!(*line))
			return (-1);
	}
	else
	{
		*line = ft_strsub(*content, 0, i);
		tmp = ft_strdup(*content + i + 1);
		ft_strdel(&(*content));
		if (!(*line) || !tmp)
			return (-1);
		*content = tmp;
		if (!(*content)[0])
			ft_strdel(&(*content));
	}
	return (1);
}

static void	upd_content(char **curr, char *new)
{
	char *tmp;

	tmp = ft_strjoin(*curr, new);
	ft_strdel(&(*curr));
	*curr = tmp;
}

static int	read_and_save(const int fd, t_gnl *gnl, char **line)
{
	int		ret;

	if (BUFF_SIZE <= 0 ||
		!(gnl->buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	*(gnl->curr) = (*gnl->curr) ? (*gnl->curr) : ft_strnew(1);
	while ((ret = read(fd, gnl->buf, BUFF_SIZE)) > 0)
	{
		gnl->buf[ret] = '\0';
		upd_content(gnl->curr, gnl->buf);
		if (!(gnl->curr))
			return (-1);
		if (ft_strchr(*gnl->curr, '\n'))
			break ;
	}
	ft_strdel(&gnl->buf);
	if (ret < 0)
		return (-1);
	if (!ret && (!(*gnl->curr) || !((*gnl->curr)[0])))
		return (0);
	return (trim_content(gnl->curr, line));
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl gnl;

	gnl.curr = &gnl.rests[fd];
	if (!line || fd < 0)
		return (-1);
	return (read_and_save(fd, &gnl, line));
}
