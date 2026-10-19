/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:37:11 by mohal-al          #+#    #+#             */
/*   Updated: 2026/10/18 17:31:40 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swapo(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_list **stack_a, t_bench *bench)
{
	swapo(stack_a);
	write(1, "sa\n", 3);
	bench->sa++;
	bench->total++;
}

void	sb(t_list **stack_b, t_bench *bench)
{
	swapo(stack_b);
	write(1, "sb\n", 3);
	bench->sb++;
	bench->total++;
}

void	ss(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	swapo(stack_a);
	swapo(stack_b);
	write(1, "ss\n", 3);
	bench->ss++;
	bench->total++;
}
