/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 01:51:32 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/08 01:52:40 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP2_H
# define PUSH_SWAP2_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
//a values to represent the different strategies for sorting
typedef enum e_strategy
{
	INVALID,
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef struct s_flag
{
	t_strategy	strategy;
	int			bench;
	int			strategy_set;
	int			bench_set;
}	t_flag;//to check that the strategy or bench has been set once

typedef struct s_list//to store numbers after parsing
{
	int				content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *num, int *value);
int		is_digit(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	init_flags(t_flag *flag);
int		parse_flags(char *av, t_flag *flag);
int		is_strategy(char *arg);
int		is_bench(char *arg);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	malloc_free(char **av);
int		store_num(t_list **lst, int num);
int		parse_num(char *num, t_list **stack_a);
int		parse_args(int ac, char **av, t_flag *flag,
			t_list **stack_a);

#endif