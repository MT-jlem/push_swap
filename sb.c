/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:27 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/19 16:09:29 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	sb(t_stack utils, int flag)
{
	int	tmp;

	if ((utils.tail_b - utils.top_b) == 1)
		return (utils);
	tmp = utils.b[utils.top_b];
	utils.b[utils.top_b] = utils.b[utils.top_b - 1];
	utils.b[utils.top_b - 1] = tmp;
	if (flag)
		write(1, "sb\n", 3);
	else
		utils.mv++;
	return (utils);
}
