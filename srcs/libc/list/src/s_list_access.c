/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_access.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 22:27:02 by qperez            #+#    #+#             */
/*   Updated: 2013/11/04 09:59:05 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_list_access method>
** < back, front, begin, end, get_cell >
** Copyright (C) <2013>  Quentin Perez <qperez42@gmail.com>
**
** This file is part of 42-toolkit.
**
** 42-toolkit is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <list/s_list.h>
#include <stddef.h>

void				*f_list_back(t_list *v_this)
{
	if (v_this->v_end != NULL)
		return (v_this->v_end->v_data);
	return (NULL);
}

void				*f_list_front(t_list *v_this)
{
	if (v_this->v_begin != NULL)
		return (v_this->v_begin->v_data);
	return (NULL);
}

inline t_list_cell	*f_list_begin(const t_list *v_this)
{
	return (v_this->v_begin);
}

inline t_list_cell	*f_list_end(const t_list *v_this)
{
	return (v_this->v_end);
}

t_list_cell			*f_list_get_cell(t_list *list, ui cell_at)
{
	ui			i;
	t_list_cell	*cur;

	i = 0;
	cur = list->v_begin;
	while (cur != NULL && i < cell_at)
	{
		cur = cur->v_next;
		i = i + 1;
	}
	return (cur);
}
