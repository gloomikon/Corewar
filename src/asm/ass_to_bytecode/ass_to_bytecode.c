/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass_to_bytecode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 01:58:09 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/06 19:34:53 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass_to_bytecode.h"

void	insert_ints_instead_mentions(t_pars *pars)
{
	t_mention	*mention;
	t_label		*label;

	label = pars->labels;
	while (label)
	{
		if (label->op_pos != -1)
		{
			mention = label->mentions;
			while (mention)
			{
				printf("dbg = %d\n", label->op_pos - mention->op_pos);
				write_to_bytecode(pars->code, mention->pos,
						(label->op_pos - mention->op_pos), mention->size);
				mention = mention->next;
			}
		}
		else
			terminate_label(label);
	}
}

void	read_file(t_pars *pars)
{
	char	*line;
	int		res;

	pars->end = new_entity(pars, END);
	while ((res = read_next_line(pars->fd, &line)) > 0
		&& !(pars->col = 0)
		&& (++pars->row))
		while (line[pars->col])
			skip_whitespaces(&(pars->col), line)
			&& skip_comment(&(pars->col), line)
			&& (line[pars->col] != '\0')
			&& get_entities(pars, &line);
	add_entity(&(pars->entities), pars->end);
	res == -1 ? terminate("An error occurred while opening file") : 0;
}

int		ass_to_bytecode(char *file)
{
	t_entity	*curr;
	t_pars		*pars;
	int			fd;

	(fd = open(file, O_RDONLY)) < 0 ? terminate("Invalid file") : 0;
	pars = init_pars(fd);
	read_file(pars);
	curr = pars->entities;
	get_champ_bio(pars, &curr);
	read_and_proc_entities(pars, &curr);
	return (1);
}
