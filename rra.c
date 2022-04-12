/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:10:24 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/19 16:10:36 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	rra(t_stack	utils, int flag)
{
	int	i;
	int	tmp;

	if (utils.tail_a == 0)
		return (utils);
	i = utils.tail_a;
	tmp = utils.a[i];
	while (i > 0)
	{
		utils.a[i] = utils.a[i - 1];
		i--;
	}
	utils.a[0] = tmp;
	if (flag)
		write(1, "rra\n", 4);
	else
		utils.mv++;
	return (utils);
}
