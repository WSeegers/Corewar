/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_isalpha.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 23:56:09 by WSeegers          #+#    #+#             */
/*   Updated: 2018/09/02 15:33:19 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_string.h"

int		f_isalpha(int c)
{
	return (f_islower(c) || f_isupper(c));
}