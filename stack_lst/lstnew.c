/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohal-al <mohal-al@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 19:47:46 by mohal-al          #+#    #+#             */
/*   Updated: 2026/10/08 19:49:31 by mohal-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = malloc (sizeof (t_list));
	if (!ptr)
	{
		return (NULL);
	}
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
