/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/11/05 17:16:43 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <htable/s_htable.h>
#include <unit/s_unit.h>
#include <time.h>

void	D_UNIT_FUNCT(ret_val)
{
	t_htable	htable;
	char		str[6];
	ui			i;

	i = 0;
	str[5] = 0;
	D_UNIT(assert)(D_HTABLE(init)(&htable, 613, 0) == 1);
	while (i < 100)
	{
		str[0] = rand() % 200;
		str[1] = rand() % 175;
		str[2] = rand() % 100;
		str[3] = rand() % 125;
		str[4] = rand() % 34;
		i = i + 1;
		D_UNIT(assert)(D_HTABLE(add)(&htable, str, malloc(sizeof(int))) == 1);
	}
	D_HTABLE(destroy)(&htable);
}

void	D_UNIT_FUNCT(memleaks)
{
	t_htable	htable;
	char		str[6];
	ui			i;

	i = 0;
	srand(time(NULL));
	D_HTABLE(init)(&htable, 197, free);
	str[5] = 0;
	while (i < 100)
	{
		str[0] = rand() % 200;
		str[1] = rand() % 175;
		str[2] = rand() % 100;
		str[3] = rand() % 125;
		str[4] = rand() % 34;
		i = i + 1;
		D_HTABLE(add)(&htable, str, malloc(sizeof(int)));
	}
	D_HTABLE(destroy)(&htable);
	(void)t;
}

int		main(int argc, char const** argv)
{
	t_unit	unit;

	D_UNIT(init)(&unit);
	D_UNIT(add_context)(&unit, "Leaks", 0, 0);
	D_UNIT(add_test)(&unit, "Leaks", memleaks);
	D_UNIT(add_context)(&unit, "Method", 0, 0);
	D_UNIT(add_test)(&unit, "Method", ret_val);
	D_UNIT(console_run)(&unit);
	D_UNIT(destroy)(&unit);
	(void)argc;
	(void)argv;
	return (0);
}
