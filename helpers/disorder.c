/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 17:32:05 by mohal-al          #+#    #+#             */
/*   Updated: 2026/10/20 19:54:06 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

float	disorder(t_list **stack)
{
	int		mistakes;
	int		total_pairs;
	t_list	*temp;
	t_list	*head;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	head = *stack;
	while (head != NULL)
	{
		temp = head->next;
		while (temp != NULL)
		{
			total_pairs += 1;
			if (head->content > temp->content)
				mistakes += 1;
			temp = temp->next;
		}
		head = head->next;
	}
	return ((float)mistakes / (float)total_pairs);
}
