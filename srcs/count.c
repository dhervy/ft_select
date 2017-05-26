/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:50:53 by dhervy            #+#    #+#             */
/*   Updated: 2016/11/21 18:43:20 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_count_column(t_all *all)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	all->column = w.ws_col;
	all->line = w.ws_row;
}

int		ft_count_len_max(t_arg **list)
{
	t_arg	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	while (tmp)
	{
		if (ft_strlen(tmp->name) > i)
			i = ft_strlen(tmp->name);
		tmp = tmp->next;
	}
	return (i);
}

int		ft_check_size(t_all *all)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	if (all->column != w.ws_col || all->line != w.ws_row)
	{
		all->column = w.ws_col;
		all->line = w.ws_row;
		return (1);
	}
	return (0);
}

int		ft_count_nbrline(t_all *all, t_arg **list)
{
	int		nbrline;
	t_arg	*tmp;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	if (all->columnlist == 0)
		all->columnlist++;
	nbrline = (tmp->num / all->columnlist) + 1;
	return (nbrline);
}
