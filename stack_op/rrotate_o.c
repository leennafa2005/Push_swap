/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:19:08 by mohal-al          #+#    #+#             */
/*   Updated: 2026/10/18 17:30:33 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*get_before_last(t_list *lst)
{
	if (!lst || !lst->next)
		return (NULL);
	while (lst->next->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

static void	rrottait(t_list **stack)
{
	t_list	*temp;
	t_list	*last;
	t_list	*before_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	before_last = get_before_last(*stack);
	last = before_last->next;
	temp = *stack;
	*stack = last;
	last->next = temp;
	before_last->next = NULL;
}

void	rra(t_list **stack_a, t_bench *bench)
{
	rrottait(stack_a);
	write(1, "rra\n", 4);
	bench->rra++;
	bench->total++;
}

void	rrb(t_list **stack_b, t_bench *bench)
{
	rrottait(stack_b);
	write(1, "rrb\n", 4);
	bench->rrb++;
	bench->total++;
}

void	rrr(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	rrottait(stack_a);
	rrottait(stack_b);
	write(1, "rrr\n", 4);
	bench->rrr++;
	bench->total++;
}
