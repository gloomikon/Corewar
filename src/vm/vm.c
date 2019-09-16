/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:42:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/15 18:35:04 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

<<<<<<< HEAD
=======

>>>>>>> 505bd1108f09ab900ae6a67e00fb08756c3a285c
void	print_usage(void)
{
	ft_printf("Usage: ./corewar [-dump | -d nbr_cycles] [[-n number] [-v] "
		   "champion1.cor] ...");
	exit(1);
<<<<<<< HEAD
=======

>>>>>>> 505bd1108f09ab900ae6a67e00fb08756c3a285c
}

t_corewar	*new_corewar(void)
{
	t_corewar	*corewar;
	int			i;

	if (!(corewar = ft_memalloc(sizeof(t_corewar))))
		terminate(MEMORY_ALLOCATION);
	if (!(corewar->map = ft_memalloc(sizeof(uint8_t) * MEM_SIZE)))
		terminate(MEMORY_ALLOCATION);
	if (!(corewar->champs = malloc(sizeof(t_champ*) * MAX_PLAYERS)))
		terminate(MEMORY_ALLOCATION);
	i = -1;
	while (++i < MAX_PLAYERS)
		if (!(corewar->champs[i] = ft_memalloc(sizeof(t_champ))))
			terminate(MEMORY_ALLOCATION);
	return corewar;
}

void	init_dump_flag(int *argc, char ***argv, t_corewar *cw)
{
	if (cw->dump_mode == 0 && (*argc > 1) && ft_isnumber(*(*argv + 1), 10))
	{
		cw->dump_mode = (ft_strequ(**argv, "-dump")) ? 32 : 64;
		if ((cw->dump_cycles = (int)ft_atoi(*(*argv + 1))) < 0)
			cw->dump_cycles = -1;
		(*argv) += 2;
		(*argc) -= 2;
	}
	else
		print_usage();
}

<<<<<<< HEAD
t_champ	*find_champ(t_champ *lst, int id)
{
	while (lst)
	{
		if (lst->id == id)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	add_champ(t_champ **lst, t_champ *new)
{
	t_champ *curr;

	if (!(*lst))
		*lst = new;
	else
	{
		curr = *lst;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

int		convert_to_int(uint8_t *bytes, size_t size) // govno ???
{
	int		i;
	int		res;
	bool	sign;

	sign = bytes[0] & (1 << 7);
	i = 0;
	res = 0;
	while (size)
	{
		res += (sign) ? (bytes[size -1] ^ 0xFF) << (i++ * 8) :
						bytes[size - 1] << (i++ * 8);
		--size;
	}
	sign ? res = ~(res) : 0;
	return (res);
}

int		read_from_bytecode(int fd)
{
	uint8_t		buff[4];
	size_t		size;

	size = read(fd, &buff, 4);
	if (size == -1)
		terminate(FILE_READING);
	else if (size < 4)
		terminate(FILE_INVALID);
	return (convert_to_int(buff, 4));
}

t_champ	*new_champ(char *file, int id)
=======
void	add_champ(int *argc, char **argv, t_champ **lst, t_corewar *cw)
>>>>>>> 505bd1108f09ab900ae6a67e00fb08756c3a285c
{
	int		fd;
	t_champ	*champ;

	if (!(champ = ft_memalloc(sizeof(t_champ))))
		terminate(MEMORY_ALLOCATION);
	champ->id = id;
	if ((fd = open(file, O_RDONLY)) == -1)
		terminate(FILE_OPENING);
	if (read_from_bytecode(fd) != COREWAR_EXEC_MAGIC)
		terminate(INVALID_MAGIC);
	return (champ);
}

void	proc_champ(int *argc, char ***argv, t_champ **lst, t_corewar *cw)
{
	int	id;

	if (ft_strequ(**argv, "-n") && (*argc > 2))
	{
		if (ft_isnumber(*(*argv + 1), 10) == false
		|| (id = (int)ft_atoi(*(*argv + 1))) > MAX_PLAYERS
		|| id < 1
		|| find_champ(*lst, id)
		|| !check_file_extension(*(*argv + 2), "cor"))
			print_usage();
		add_champ(lst, new_champ(*(*argv + 2), id));
		++(cw->champs_num)	;
		(*argv) += 3;
		(*argc) -= 3;
	}
}

void	parse_args(int argc, char **argv, t_corewar *cw)
{
	t_champ *lst;

	lst = NULL;
	(argv++) && (argc--);
	while (argc >= 1)
		if (ft_strequ(*argv, "-dump") || ft_strequ(*argv, "-d"))
			init_dump_flag(&argc, &argv, cw);
		else if (check_file_extension(*argv, "cor") || ft_strequ(*argv, "-n"))
<<<<<<< HEAD
			proc_champ(&argc, &argv, &lst, cw);
=======
			add_champ(&argc, &argv, &lst, cw);
>>>>>>> 505bd1108f09ab900ae6a67e00fb08756c3a285c
}

int		main(int argc, char **argv)
{
	t_corewar	*cw;

	if (argc < 2)
		print_usage();
	parse_args(argc, argv, (cw = new_corewar()));

}