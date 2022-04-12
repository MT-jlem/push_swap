/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:13:41 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/19 16:14:39 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	pb(t_stack utils, int flag)
{
	int	i;

	i = 0;
	if (utils.tail_a == -1)
		return (utils);
	utils.top_b--;
	utils.b[utils.top_b] = utils.a[0];
	while (i < utils.tail_a)
	{
		utils.a[i] = utils.a[i + 1];
		i++;
	}
	utils.tail_a--;
	if (flag)
		write(1, "pb\n", 3);
	else
		utils.mv++;
	return (utils);
}
