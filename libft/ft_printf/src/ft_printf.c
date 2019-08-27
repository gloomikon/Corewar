/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:47:53 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/08 19:36:09 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	main_loop(const char *restrict format, t_pf_env *e)
{
	while (format[e->i])
	{
		if (format[e->i] == '{')
			check_settings(format, e);
		else if (!ft_strcmp(format + e->i, "%"))
			break ;
		else if (format[e->i] == '%' && format[e->i + 1] != '%')
			parse_and_print(format, e);
		else if (format[e->i] == '%' && format[e->i + 1] == '%')
		{
			e->ret += write(e->fd, "%", 1);
			e->i += 2;
		}
		else
			e->ret += write(e->fd, &format[e->i++], 1);
	}
}

int			ft_printf(const char *restrict format, ...)
{
	t_pf_env	e;

	ft_bzero(&e, sizeof(e));
	e.fd = 1;
	va_start(e.ap[0], format);
	va_copy(e.ap[1], e.ap[0]);
	main_loop(format, &e);
	va_end(e.ap[0]);
	return (e.ret);
}

int			ft_dprintf(int fd, const char *restrict format, ...)
{
	t_pf_env	e;

	ft_bzero(&e, sizeof(e));
	e.fd = fd;
	va_start(e.ap[0], format);
	va_copy(e.ap[1], e.ap[0]);
	main_loop(format, &e);
	va_end(e.ap[0]);
	return (e.ret);
}
