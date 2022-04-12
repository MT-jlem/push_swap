/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:09:43 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/19 16:10:10 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	rrr(t_stack	utils, int flag)
{
	if (utils.tail_a == 0)
		return (utils);
	utils = rra(utils, 0);
	utils = rrb(utils, 0);
	if (flag)
		write(1, "rrr\n", 4);
	else
		utils.mv++;
	return (utils);
}
