/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohal-al <mohal-al@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 21:28:28 by mohal-al          #+#    #+#             */
/*   Updated: 2026/10/08 16:15:28 by mohal-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list 
{
    int value;
    struct s_list *next;
    struct s_list *prev;
} t_list;

void sa(t_list **stack);
void sb(t_list **stack);
void ss(t_list **stack1, t_list **stack2);


