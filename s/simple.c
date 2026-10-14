/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:20:05 by mohal-al          #+#    #+#             */
/*   Updated: 2026/10/14 18:24:01 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void	print_stack(t_list *stack, char *name);
int minv(t_list **stack)
{
    t_list *temp;
    int min;
    
    temp = *stack;
    min = temp -> content;
    while (temp)
    {
        if (min > temp-> content)
                min = temp -> content;
        temp = temp-> next;
    }
    return (min);
    
}

/* دالة صغيرة بس بتجيب كم خطوة لازم نمشي لنلاقي مكان الرقم */
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

void	simple(t_list **stack_a, t_list **stack_b)
{
	int	steps;
	int	size_a;

	while (*stack_a)
	{
		size_a = ft_lstsize(*stack_a);
		steps = get_steps(*stack_a, minv(stack_a));
		if (steps != 0 && steps <= size_a / 2)
		{
			while (steps--)
				ra(stack_a);
		}
		else
		{
			while (steps != 0 && steps++ < size_a)
				rra(stack_a);
		}
		pb(stack_a,stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

#include <stdio.h>

/* دالة مساعدة بتلف على الستاك وبتطبع كل رقم بسطر مع سهم لطيف */
void	print_stack(t_list *stack, char *name)
{
	printf("\n--- Stack %s ---\n", name);
	if (!stack)
	{
		printf("(empty)\n");
		return ;
	}
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
	printf("----------------\n");
}


