/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:47:44 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/08 19:31:18 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	set_color(const char *restrict fmt, t_pf_env *e)
{
	int i;

	if (!ft_strncmp(fmt + e->i, "{black}", 7) && (i = 7))
		e->ret += write(e->fd, "\x1B[30m", 5);
	else if (!ft_strncmp(fmt + e->i, "{red}", 5) && (i = 5))
		e->ret += write(e->fd, "\x1B[31m", 5);
	else if (!ft_strncmp(fmt + e->i, "{green}", 7) && (i = 7))
		e->ret += write(e->fd, "\x1B[32m", 5);
	else if (!ft_strncmp(fmt + e->i, "{yellow}", 8) && (i = 8))
		e->ret += write(e->fd, "\x1B[33m", 5);
	else if (!ft_strncmp(fmt + e->i, "{blue}", 6) && (i = 6))
		e->ret += write(e->fd, "\x1B[34m", 5);
	else if (!ft_strncmp(fmt + e->i, "{magenta}", 9) && (i = 9))
		e->ret += write(e->fd, "\x1B[35m", 5);
	else if (!ft_strncmp(fmt + e->i, "{cyan}", 6) && (i = 6))
		e->ret += write(e->fd, "\x1B[36m", 5);
	else if (!ft_strncmp(fmt + e->i, "{white}", 7) && (i = 7))
		e->ret += write(e->fd, "\x1B[37m", 5);
	else
		return ;
	e->i += i;
}

void		check_settings(const char *restrict fmt, t_pf_env *e)
{
	int tmp;

	tmp = e->i;
	if (!ft_strncmp(fmt + e->i, "{off}", 5))
	{
		e->ret += write(e->fd, "\x1B[0m", 4);
		e->i += 5;
		return ;
	}
	else
		set_color(fmt, e);
	if (tmp == e->i)
		e->ret += write(e->fd, &fmt[e->i++], 1);
}
