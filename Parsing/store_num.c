/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 06:49:29 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/10 06:49:29 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap2.h"

int	is_there_duplicate(t_list *lst, int num)
{
	while (lst)
	{
		if (lst->content == num)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	is_sorted(t_list *stack_a)
{
	if (!stack_a || !stack_a->next)
		return (1);
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	store_num(t_list **lst, int num)
{
	t_list	*new_node;

	if (is_there_duplicate(*lst, num))
		return (0);
	new_node = ft_lstnew(num);
	if (!new_node)
		return (0);
	ft_lstadd_back(lst, new_node);
	return (1);
}
