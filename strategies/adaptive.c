/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 19:26:57 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/21 17:40:10 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptive(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	float	d;

	d = disorder(stack_a);
	if ((ft_lstsize(*stack_a) <= 5) || d < 0.2)
		simple(stack_a, stack_b, bench);
	else if (d >= 0.2 && d < 0.5)
		medium(stack_a, stack_b, bench);
	else if (d >= 0.5)
		complex(stack_a, stack_b, bench);
}
