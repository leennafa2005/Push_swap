/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohal-al <mohal-al@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:37:11 by mohal-al          #+#    #+#             */
/*   Updated: 2026/10/08 19:39:56 by mohal-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack ||!(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	write(1, "sa\n", 3);
}

void	sb(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack ||!(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	write(1, "sb\n", 3);
}

void	ss(t_list **stack1, t_list **stack2)
{
	sa(stack1);
	sb(stack2);
}
