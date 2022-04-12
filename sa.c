/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:34 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/19 16:09:36 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	sa(t_stack utils, int flag)
{
	int	tmp;

	if (utils.tail_a == 0)
		return (utils);
	tmp = utils.a[0];
	utils.a[0] = utils.a[1];
	utils.a[1] = tmp;
	if (flag)
		write(1, "sa\n", 3);
	else
		utils.mv++;
	return (utils);
}
