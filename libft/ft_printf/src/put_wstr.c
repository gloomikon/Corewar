/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:16:17 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 15:19:37 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_wstr(t_pf_env *e, wchar_t c)
{
	if (c <= 0x7F)
		put_wstr_c(e, c);
	else if (c <= 0x7FF)
	{
		put_wstr_c(e, (c >> 6) + 0xC0);
		put_wstr_c(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		put_wstr_c(e, ((c >> 12) + 0xE0));
		put_wstr_c(e, ((c >> 6) & 0x3F) + 0x80);
		put_wstr_c(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		put_wstr_c(e, (c >> 18) + 0xF0);
		put_wstr_c(e, ((c >> 12) & 0x3F) + 0x80);
		put_wstr_c(e, ((c >> 6) & 0x3F) + 0x80);
		put_wstr_c(e, (c & 0x3F) + 0x80);
	}
}
