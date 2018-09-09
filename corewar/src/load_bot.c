/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:05:57 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/07 11:06:57 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

typedef struct s_process	t_process;

struct s_process	*load_bot(char *path, int player_no)
{
	unsigned int		i;
	int					fd;

	i = PLAYER_POS(player_no, g_env.player_total);
	if ((fd = open(path, O_RDONLY)) < 0)
	{
		exit(0);
		f_printf("%s not found\n", path);
	}
	lseek(fd, AT_CODE, SEEK_SET);
	read(fd, g_env.memory + i, CHAMP_MAX_SIZE);
	close(fd);
	return (process_create(player_no, i, false));
}