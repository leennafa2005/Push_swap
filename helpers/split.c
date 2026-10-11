/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 00:32:17 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/10 00:32:17 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && (s[i] != c))
				i++;
		}
	}
	return (count);
}

static size_t	get_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && (s[i] != c))
		i++;
	return (i);
}

static char	*copy_word(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	*r;

	i = 0;
	len = get_len(s, c);
	r = malloc((len + 1) * sizeof(char));
	if (!r)
		return (NULL);
	while (s[i] && (s[i] != c))
	{
		r[i] = s[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

static void	mallocs_free(char **s, size_t j)
{
	while (j > 0)
	{
		j--;
		free(s[j]);
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**res;

	i = 0;
	j = 0;
	res = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (j < word_count(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		res[j] = copy_word(&s[i], c);
		if (!res[j])
		{
			mallocs_free(res, j);
			return (NULL);
		}
		i = i + get_len(&s[i], c);
		j++;
	}
	res[j] = NULL;
	return (res);
}
