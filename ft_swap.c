/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:14:57 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/08/05 14:52:40 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push.h"

int ft_push_swap (char** argv);
int	check_list (char** argv, int i);
int	check (char** tab);

int ft_push_swap (char** argv)
{
	int	i;

	i = 1;
	if (check_list(argv, i) == 1)
	{
		printf("Error\n");
		return(1);
	}
	if (check_list(argv, i) == 2)
	{
		printf("t'es le boss\n");
		return (2);
	}
	else
		return(0);
}

int	check_list (char** argv, int i)
{
	while (argv[i])
	{
		if (check(ft_split(argv[i], ' ')) == 1)
			return (1);		
		i++;
	}
	return (2);
}

int	check (char** tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (tab[i][j] == 45 && (47 < tab[i][j + 1] && tab[i][j + 1] < 58))
				j++;
			else if (47 < tab[i][j] && tab[i][j] < 58)
				j++;
			else
				return(1);
		}
		j = 0;
		i++;
	}
	
	return (2);
}

int	main (int argc, char** argv)
{
	ft_push_swap(argv);
	return (0);
}

/* typedef struct t_list
{
    void    *content;
    t_list  *next;
}           s_list;
*/