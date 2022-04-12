/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:13:04 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/19 12:13:55 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	ss(t_stack utils, int flag)
{	
	if (utils.tail_a == 0)
		return (utils);
	utils = sa(utils, flag);
	utils = sb(utils, flag);
	if (flag)
		write(1, "ss\n", 3);
	else
		utils.mv++;
	return (utils);
}
