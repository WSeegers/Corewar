/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:09:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/17 08:18:35 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

typedef struct s_process	t_process;

void	print_proc(void **process)
{
	t_process	*bot;

	bot = (t_process*)*process;
	f_printf("\n");
	print_bot(bot);
}

int		main(int argc, char *argv[])
{
	t_list	*process_list;

	if (!(argc == 3))
		return (0);

	// INNIT ENV
	f_bzero(g_env.memory, MEM_SIZE);
	g_env.player_total = 2;
	g_env.last_live = 0;
	g_env.next_id = 1;
	g_env.process_list = list_create(free);
	g_env.cycles = 1;
	g_env.live_counter = 0;
	g_env.cycle_to_die = CYCLE_TO_DIE;
	g_env.last_delta = 0;
	g_env.delta_count = 0;

	// Loading of bots
	process_list = g_env.process_list;
	load_bot(argv[1], 1);
	if (argc > 2)
		load_bot(argv[2], 2);

	battle_loop();

	print_memory();
	f_printf("\n");
	// f_print_bot(list_get(process_list, 0));
	f_printf("bots-> %d\n", g_env.process_list->size);
	// list_iterate(g_env.process_list, print_proc);
	f_printf("last_live-> %d\n", g_env.last_live);
	f_printf("cycles: %d\n", g_env.cycles);
}
