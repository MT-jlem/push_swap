/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:10:47 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/19 16:11:25 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	rr(t_stack	utils, int flag)
{
	if (utils.tail_a == 0)
		return (utils);
	utils = rb(utils, 0);
	utils = ra(utils, 0);
	if (flag)
		write(1, "rr\n", 3);
	else
		utils.mv++;
	return (utils);
}
