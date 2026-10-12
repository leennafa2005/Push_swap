/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohal-al <mohal-al@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:20:05 by mohal-al          #+#    #+#             */
/*   Updated: 2026/10/12 22:28:42 by mohal-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void	print_stack(t_list *stack, char *name);
int maxv(t_list **stack)
{
    t_list *temp;
    int max;
    
    temp = *stack;
    max = temp -> content;
    while (temp)
    {
        if (max < temp-> content)
                max = temp -> content;
        temp = temp-> next;
    }
    return (max);
    
}
void	simplen(t_list **stack_a, t_list **stack_b)
{
	int	count;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if ((*stack_b)->content < (*stack_b)->next->content)
		sb(stack_b);
	while (*stack_a)
	{
		count = 0;
		while ((*stack_a)->content < (*stack_b)->content
			&& (count < ft_lstsize(*stack_b) - 1))
		{
			rb(stack_b);
			count++;
		}
		pb(stack_a, stack_b);
		if ((*stack_b)->content < (*stack_b)->next->content)
			sb(stack_b);
        while (count --)
         rrb(stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
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
	int	size_b;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if ((*stack_b)->content < (*stack_b)->next->content)
		sb(stack_b);
	while (*stack_a)
	{
		size_b = ft_lstsize(*stack_b);
		steps = get_steps(*stack_b, (*stack_a)->content);
		if (steps <= size_b / 2)
		{
			while (steps--)
				rb(stack_b);
		}
		else
		{
			while (steps++ < size_b)
				rrb(stack_b);
		}
		pb(stack_a, stack_b);
		if ((*stack_b)->content < (*stack_b)->next->content)
			sb(stack_b);	
	}
	while ((*stack_b)->content < (*stack_b)->next->content)
		rb(stack_b); 
	while (*stack_b)
		pa(stack_a, stack_b);
    print_stack(*stack_a, "A (Sorted Output)");
	print_stack(*stack_b, "B (Should be empty)");
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


