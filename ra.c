/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:12:24 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/19 16:13:11 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	ra(t_stack utils, int flag)
{
	int	i;
	int	tmp;

	if (utils.tail_a == 0)
		return (utils);
	i = 0;
	tmp = utils.a[0];
	while (i < utils.tail_a)
	{
		utils.a[i] = utils.a[i + 1];
		i++;
	}
	utils.a[utils.tail_a] = tmp;
	if (flag == 1)
		write(1, "ra\n", 3);
	else if (flag == 2)
		utils.mv++;
	return (utils);
}
