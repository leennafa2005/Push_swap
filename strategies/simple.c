/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:20:05 by mohal-al          #+#    #+#             */
/*   Updated: 2026/10/21 20:29:35 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		print_stack(t_list *stack, char *name);

int	minv(t_list **stack)
{
	t_list	*temp;
	int		min;

	temp = *stack;
	min = temp->content;
	while (temp)
	{
		if (min > temp->content)
			min = temp->content;
		temp = temp->next;
	}
	return (min);
}

static int	get_steps(t_list *b, int val)
{
	int	steps;

	steps = 0;
	while (b && val < b->content)
	{
		steps++;
		b = b->next;
	}
	return (steps);
}

void	simple(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	steps;
	int	size_a;

	while ((*stack_a)->next->next)
	{
		size_a = ft_lstsize(*stack_a);
		steps = get_steps(*stack_a, minv(stack_a));
		if (steps != 0 && steps <= size_a / 2)
		{
			while (steps--)
				ra(stack_a, bench);
		}
		else
		{
			while (steps != 0 && steps++ < size_a)
				rra(stack_a, bench);
		}
		pb(stack_a, stack_b, bench);
		if ((!(*stack_a)->next->next)
			&& (*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a, bench);
	}
	while (*stack_b)
		pa(stack_a, stack_b, bench);
}
