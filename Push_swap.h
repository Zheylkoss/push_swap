/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:29:55 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/20 16:11:42 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

typedef struct s_list
{
	long	content;
    int		cost_a;
    int		cost_b;
    int		index;
    int		pos;
    int		target_pos;
    struct	s_list	*next;
	struct	s_list	*prev; //check not use yet
}			t_list;

size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(int content);
long	ft_atol(const char *nptr);
int		ft_atoi(const char *nptr);
void	ft_lastadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ptb(t_list **a, t_list **b);
void	pta(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
int		stack_size(t_list *a);
int		ft_lstsize(t_list *lst);
int		size_3(t_list **a);
void	size_5(t_list **a, t_list **b, int j);
int		ft_push_swap(char **argv, t_list **a, t_list **b);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
int		checker_if_list_sort(t_list *a);
void	bubbleSort(int *tab, int n);
int		ft_big_sort(t_list **a, t_list **b, int j);
void	cost_b(t_list **a, t_list **b);
int		cout_global(t_list **a, t_list **b);
void	cost_a(t_list **a, t_list **b);
int		cout_reel(int cost_a, int cost_b);
void	pos(t_list **a, t_list **b);
void	put_index(t_list **a, int *tab, int j);
void	target_pos(t_list **a, t_list **b);
void	fait_le_mouv(int i, t_list **a, t_list **b);

#endif
