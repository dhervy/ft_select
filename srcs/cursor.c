/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:15:28 by dhervy            #+#    #+#             */
/*   Updated: 2016/11/21 18:37:54 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_select_list(t_all *all, t_arg **list)
{
	t_arg	*tmp;

	tmp = *list;
	while (tmp && tmp->pos == 0)
		tmp = tmp->next;
	tmp->select = (tmp->select == 1 ? 0 : 1);
	ft_moove_curseur_right(all, list);
}

void	ft_moove_curseur_left(t_all *all, t_arg **list)
{
	int		num;
	int		ligne;
	t_arg	*tmp;

	tmp = *list;
	num = 0;
	while (tmp && tmp->pos == 0)
		tmp = tmp->next;
	if (tmp->pos == 1)
		num = tmp->num;
	tmp->pos = 0;
	if (tmp->prev)
		tmp->prev->pos = 1;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->pos = 1;
	}
	ft_check_put_list(list, all);
}

void	ft_moove_curseur_bot(t_all *all, t_arg **list)
{
	t_arg	*tmp;
	t_arg	*tmp2;
	int		num;
	int		line;
	int		linemax;

	tmp = *list;
	num = 0;
	while (tmp->pos == 0)
		tmp = tmp->next;
	tmp2 = tmp;
	num = tmp->num + all->columnlist;
	while (tmp->next && tmp->num != num)
		tmp = tmp->next;
	if (tmp->num == num)
	{
		tmp2->pos = 0;
		tmp->pos = 1;
	}
	ft_check_put_list(list, all);
}

void	ft_moove_curseur_top(t_all *all, t_arg **list)
{
	int		num;
	t_arg	*tmp;
	int		line;
	int		sous;

	tmp = *list;
	num = 0;
	while (tmp->pos == 0)
		tmp = tmp->next;
	if (tmp->num - all->columnlist > 0)
	{
		tmp->pos = 0;
		num = tmp->num - all->columnlist;
		while (tmp->num > num)
			tmp = tmp->prev;
		tmp->pos = 1;
	}
	ft_check_put_list(list, all);
}

void	ft_moove_curseur_right(t_all *all, t_arg **list)
{
	int		num;
	t_arg	*tmp;

	tmp = *list;
	num = 0;
	while (tmp && tmp->pos == 0)
		tmp = tmp->next;
	if (tmp->pos == 1)
		num = tmp->num;
	tmp->pos = 0;
	if (tmp->next)
		tmp->next->pos = 1;
	else
	{
		tmp = *list;
		tmp->pos = 1;
	}
	ft_check_put_list(list, all);
}
