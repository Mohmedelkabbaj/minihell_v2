/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:37:36 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/05/05 14:51:51 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_help	*ft_lstnew(int content)
{
	t_help	*node;

	node = (t_help *)malloc(sizeof(*node));
	if (!(node))
		return (NULL);
	node->index = content;
	node->cmd = NULL;
	node->next = NULL;
	node->pre = NULL;
	return (node);
}

t_add	*ft_lstnew1(int content)
{
	t_add	*node;

	node = (t_add *)malloc(sizeof(*node));
	if (!(node))
		return (NULL);
	node->file = NULL;
	node->type = -1;
	node->sep = NULL;
	node->str = NULL;
	node->limit = NULL;
	node->next = NULL;
	node->pre = NULL;
	return (node);
}
int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstdelone(t_list **lst)
{
	t_list	*tmp;

	if (lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (*alst)
			new->next = *alst;
		*alst = new;
	}
}
void	ft_lstadd_back(t_help **alst, t_help *new)
{
	t_help	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast(*alst);
			last->next = new;
		}
		else
			*alst = new;
		new->pre = last;
	}
}

t_help	*ft_lstlast(t_help *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back1(t_add **alst, t_add *new)
{
	t_add	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast1(*alst);
			last->next = new;
		}
		else
			*alst = new;
		new->pre = last;
	}
}


t_add	*ft_lstlast1(t_add *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
