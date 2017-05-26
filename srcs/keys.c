/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 01:46:00 by dhervy            #+#    #+#             */
/*   Updated: 2016/11/21 18:49:54 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_init_num(t_all *all, t_arg **list)
{
	int		i;
	t_arg	*tmp;

	tmp = *list;
	i = 1;
	while (tmp)
	{
		tmp->num = i;
		i++;
		tmp = tmp->next;
	}
	ft_check_put_list(list, all);
}

void	ft_del_elem2(t_arg *tmp)
{
	while (tmp->pos == 0)
		tmp = tmp->next;
	if (tmp->next == NULL)
	{
		tmp->prev->pos = 1;
		tmp->prev->next = NULL;
		ft_free_struct_list(tmp);
	}
	else
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		tmp->next->pos = 1;
		ft_free_struct_list(tmp);
	}
}

void	ft_del_elem(t_all *all, t_arg **list)
{
	t_arg	*tmp;

	tmp = *list;
	if (tmp->pos == 1)
	{
		if (tmp->next)
			tmp->next->pos = 1;
		else
			ft_return(all, list, 0);
		tmp->next->prev = NULL;
		*list = tmp->next;
		ft_free_struct_list(tmp);
	}
	else
		ft_del_elem2(tmp);
	ft_init_num(all, list);
}

void	ft_find_key(t_all *all, t_arg **list)
{
	char	buf[3];

	read(0, buf, 3);
	if (buf[0] == 27 && buf[2] == 67)
		ft_moove_curseur_right(all, list);
	if (buf[0] == 27 && buf[2] == 68)
		ft_moove_curseur_left(all, list);
	if (buf[0] == 27 && buf[2] == 65)
		ft_moove_curseur_top(all, list);
	if (buf[0] == 27 && buf[2] == 66)
		ft_moove_curseur_bot(all, list);
	if (buf[0] == 32)
		ft_select_list(all, list);
	if (buf[0] == 127 || buf[0] == 92)
		ft_del_elem(all, list);
	if (buf[0] == 10)
		ft_return(all, list, 1);
	if ((buf[0] == 27 && buf[1] == 0 && buf[2] == 0) || g_global == 3)
		ft_return(all, list, 0);
	if (buf[0] == 6)
		ft_find(all, list);
	if (buf[0] == 1)
		ft_add(all, list);
}
