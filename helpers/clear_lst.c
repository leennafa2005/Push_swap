/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 23:29:28 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/10 23:29:28 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap2.h"

void	del_content(int content)
{
	(void)content;
}

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}
