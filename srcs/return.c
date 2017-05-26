/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 05:29:11 by dhervy            #+#    #+#             */
/*   Updated: 2016/11/21 19:03:37 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_free_struct_list(t_arg *tmp)
{
	free(tmp->name);
	tmp->next = NULL;
	tmp->prev = NULL;
	free(tmp);
}

void	ft_free_struct_all(t_all *all)
{
	free(all->name_term);
	free(all);
}

void	ft_free_list(t_all *all, t_arg **list)
{
	t_arg	*tmp;
	t_arg	*tmp2;

	tmp2 = *list;
	tmp = *list;
	while (tmp2)
	{
		tmp = tmp2;
		tmp2 = tmp2->next;
		ft_free_struct_list(tmp);
	}
}

int		ft_check_select(t_arg **list)
{
	t_arg	*tmp;

	tmp = *list;
	while (tmp->next && tmp->select == 0)
		tmp = tmp->next;
	if (tmp->select == 1)
		return (1);
	else
		return (0);
}

void	ft_return(t_all *all, t_arg **list, int bol)
{
	t_arg	*tmp;

	tmp = *list;
	ft_clean(all);
	if (bol == 1 && ft_check_select(list))
	{
		while (tmp && tmp->select == 0)
			tmp = tmp->next;
		ft_putstr(tmp->name);
		tmp = tmp->next;
		while (tmp)
		{
			if (tmp->select == 1)
			{
				ft_putchar(' ');
				ft_putstr(tmp->name);
			}
			tmp = tmp->next;
		}
		ft_putchar('\n');
	}
	ft_free_list(all, list);
	ft_putstr_fd(tgetstr("ve", NULL), all->fd);
	tcsetattr(0, TCSADRAIN, &all->termcpy);
	exit(1);
}
