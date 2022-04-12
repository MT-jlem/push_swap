/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:11:39 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/19 16:12:11 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	rb(t_stack	utils, int flag)
{
	int	i;
	int	tmp;

	if ((utils.tail_b - utils.top_b) == 1)
		return (utils);
	i = utils.top_b;
	tmp = utils.b[utils.top_b];
	while (i < utils.tail_b - 1)
	{
		utils.b[i] = utils.b[i + 1];
		i++;
	}
	utils.b[utils.tail_b - 1] = tmp;
	if (flag == 1)
		write(1, "rb\n", 3);
	else if (flag == 2)
		utils.mv++;
	return (utils);
}
