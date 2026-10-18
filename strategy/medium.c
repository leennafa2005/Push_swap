/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:47:37 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/18 19:20:47 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	give_chunk(t_list **stack_a)
{
	int		sizec;
	t_list	*temp;

	temp = *stack_a;
	sizec = ft_sqrt(ft_lstsize(*stack_a));
	while (temp)
	{
		temp->chunk = (temp->index) / sizec;
		temp = temp->next;
	}
}

static int	get_steps_chunk(t_list *b, int val)
{
	int	steps;

	steps = 0;
	while (b && val != b->chunk)
	{
		steps++;
		b = b->next;
	}
	return (steps);
}

void	medium2(t_list **stack_a, t_list **stack_b, int chunk_size,
		int chunk_num, t_bench *bench)
{
	int	j;
	int	js;

	j = 0;
	while (*stack_a && j < chunk_num)
	{
		js = 0;
		while (*stack_a && js < (chunk_size))
		{
			if ((*stack_a)->chunk == j)
			{
				pb(stack_a, stack_b, bench);
				js++;
			}
			else if (get_steps_chunk(*stack_a, j) <= (ft_lstsize(*stack_a) / 2))
				ra(stack_a, bench);
			else
				rra(stack_a, bench);
		}
		j++;
	}
}

static int	get_steps_index(t_list *b, int val)
{
	int	steps;

	steps = 0;
	while (b && val != b->index)
	{
		steps++;
		b = b->next;
	}
	return (steps);
}

void	medium(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	chunk_num;
	int	chunk_size;
	int	size_b;
	int	steps;
	
	give_index(stack_a);
	give_chunk(stack_a);
	chunk_size = ft_sqrt(ft_lstsize(*stack_a));
	chunk_num = (ft_lstsize(*stack_a) / chunk_size) + 1;
	medium2(stack_a, stack_b, chunk_size, chunk_num, bench);
	while (*stack_b)
	{
		size_b = ft_lstsize(*stack_b);
		steps = get_steps_index(*stack_b, get_max(stack_b));
		if (steps != 0 && steps <= size_b / 2)
			while (steps--)
				rb(stack_b, bench);
		else
			while (steps != 0 && steps++ < size_b)
				rrb(stack_b, bench);
		pa(stack_a, stack_b, bench);
	}
}
