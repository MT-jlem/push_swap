/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:27:05 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/19 16:29:33 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	pa(t_stack utils, int flag)
{
	int	i;

	i = utils.tail_a;
	if (utils.top_b == utils.tail_b)
		exit(1);
	while (i >= 0)
	{
		utils.a[i + 1] = utils.a[i];
		i--;
	}
	utils.tail_a++;
	utils.a[0] = utils.b[utils.top_b];
	utils.top_b++;
	if (flag)
		write(1, "pa\n", 3);
	else
		utils.mv++;
	return (utils);
}
