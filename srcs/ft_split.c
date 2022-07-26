/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:08:27 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/28 14:54:25 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		count_1(char const *s, char c);
static void		*count_2(char const *s, char c, char **tab, int nb_words);
static void		fill(char **tab, char const *s, char c, int j);
static char		**c_empty(char const *s);

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nb_words;

	if (s == NULL)
		return (NULL);
	if (s[0] == 0)
	{
		tab = malloc (sizeof(char *));
		if (tab == NULL)
			return (NULL);
		tab[0] = NULL;
		return (tab);
	}
	if (c == 0)
		return (tab = c_empty(s));
	nb_words = count_1(s, c);
	tab = malloc (nb_words * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	count_2(s, c, tab, nb_words);
	fill(tab, s, c, nb_words);
	return (tab);
}

static int	count_1(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	if (s[i - 1] != c)
		j++;
	return (j);
}

static void	*count_2(char const *s, char c, char **tab, int nb_words)
{
	int	j;
	int	i;
	int	counter;

	i = -1;
	j = 0;
	while (++i < (nb_words - 1))
	{
		counter = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
		{
			j++;
			counter++;
		}
		tab[i] = malloc ((counter + 1) * sizeof(char));
		if (tab[i] == NULL)
		{
			while (--i >= 0)
				free(tab[i]);
			return (NULL);
		}
	}
	return (0);
}

static void	fill(char **tab, char const *s, char c, int nb_words)
{
	int	j;
	int	a;
	int	i;

	j = 0;
	a = 0;
	i = 0;
	while (j < (nb_words - 1))
	{
		while (s[i] == c)
			i++;
		a = 0;
		while (s[i] != c && s[i])
		{
			tab[j][a] = s[i];
			i++;
			a++;
		}
		tab[j][a] = '\0';
		j++;
	}
	tab[nb_words - 1] = NULL;
}

static char	**c_empty(char const *s)
{
	size_t		size ;
	int			i;
	char		**abc;

	i = 0;
	size = ft_strlen(s);
	abc = malloc (2 * sizeof(char *));
	if (abc == NULL)
		return (NULL);
	abc[0] = malloc ((size + 1) * sizeof(char));
	if (abc[0] == NULL)
		return (NULL);
	while (s[i])
	{
		abc[0][i] = s[i];
		i++;
	}
	abc[0][i] = '\0';
	abc[1] = NULL;
	return (abc);
}
