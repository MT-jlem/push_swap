/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:08:59 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/19 16:09:09 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	rrb(t_stack utils, int flag)
{
	int	i;
	int	tmp;

	if ((utils.tail_b - utils.top_b) == 1)
		return (utils);
	i = utils.tail_b - 1;
	tmp = utils.b[i];
	while (i > utils.top_b)
	{
		utils.b[i] = utils.b[i - 1];
		i--;
	}
	utils.b[utils.top_b] = tmp;
	if (flag)
		write(1, "rrb\n", 4);
	else
		utils.mv++;
	return (utils);
}
