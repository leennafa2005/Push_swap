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

int	store_num(t_list **lst, int num)
{
	t_list	*new_node;

	new_node = ft_lstnew(num);
	if (!new_node)
		return (0);
	ft_lstadd_back(lst, new_node);
	return (1);
}
