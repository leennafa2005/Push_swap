/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 01:51:32 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/19 17:53:23 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Printf/ft_printf.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>

typedef enum e_strategy
{
	INVALID,
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
}					t_strategy;

typedef struct s_flag
{
	t_strategy		strategy;
	int				bench;
	int				strategy_set;
	int				bench_set;
}					t_flag;

typedef struct s_list
{
	int				content;
	int				index;
	int				chunk;
	struct s_list	*next;
}					t_list;

typedef struct s_bench
{
	int				pa;
	int				pb;
	int				sa;
	int				sb;
	int				ss;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_bench;

int					ft_atoi(const char *num, int *value);
int					is_digit(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				init_flags(t_flag *flag);
int					parse_flags(char *av, t_flag *flag);
int					is_strategy(char *arg);
int					is_bench(char *arg);
char				**ft_split(char const *s, char c);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				malloc_free(char **av);
int					store_num(t_list **lst, int num);
int					parse_num(char *num, t_list **stack_a);
int					parse_args(int ac, char **av, t_flag *flag,
						t_list **stack_a);
int					is_there_duplicate(t_list *lst, int num);
void				call_strategy(t_strategy strategy, t_list **stack_a,
						t_list **stack_b, t_bench *bench);
void				ft_lstclear(t_list **lst, void (*del)(int));
void				del_content(int content);
int					is_sorted(t_list *stack_a);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstnew(int content);
t_list				*get_before_last(t_list *lst);

void				sa(t_list **stack, t_bench *bench);
void				sb(t_list **stack, t_bench *bench);
void				ss(t_list **stack1, t_list **stack2, t_bench *bench);
void				pa(t_list **stack_a, t_list **stack_b, t_bench *bench);
void				pb(t_list **stack_a, t_list **stack_b, t_bench *bench);
void				ra(t_list **stack_a, t_bench *bench);
void				rb(t_list **stack_b, t_bench *bench);
void				rr(t_list **stack_a, t_list **stack_b, t_bench *bench);
void				rra(t_list **stack_a, t_bench *bench);
void				rrb(t_list **stack_b, t_bench *bench);
void				rrr(t_list **stack_a, t_list **stack_b, t_bench *bench);
float				disorder(t_list **stack);
void				simple(t_list **stack_a, t_list **stack_b, t_bench *bench);
void				print_stack(t_list *stack, char *name);
int					ft_sqrt(int nb);
void				medium(t_list **stack_a, t_list **stack_b, t_bench *bench);

int					get_index(t_list **stack_a, int value);
void				give_index(t_list **stack_a);
int					get_max(t_list **stack_b);
void				complex(t_list **stack_a, t_list **stack_b, t_bench *bench);
void				adaptive(t_list **stack_a, t_list **stack_b, t_bench *b);
void				bench(t_bench *bench_data, int strategy, float disoreder);

#endif
