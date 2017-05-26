/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 08:55:56 by dhervy            #+#    #+#             */
/*   Updated: 2016/11/22 17:48:37 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_put_add(t_all *all, t_arg **list, int x, int y)
{
	char	*line;
	t_arg	*tmp;
	t_arg	*new;

	tmp = *list;
	line = NULL;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), x, y), all->fd);
	ft_putstr_fd("Ajouter : ", all->fd);
	ft_putstr_fd(tgetstr("ve", NULL), all->fd);
	tcsetattr(0, TCSADRAIN, &all->termcpy);
	get_next_line(1, &line);
	if (line[0] != '\0')
	{
		while (tmp->next)
			tmp = tmp->next;
		new = (t_arg*)ft_memalloc(sizeof(t_arg));
		new->name = ft_strdup(line);
		new->num = tmp->num + 1;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
	tcsetattr(0, TCSADRAIN, &all->term);
	ft_putstr_fd(tgetstr("vi", NULL), all->fd);
	ft_check_put_list(list, all);
}

void	ft_add(t_all *all, t_arg **list)
{
	int		nbrline;
	int		x;
	int		y;

	nbrline = ft_count_nbrline(all, list);
	y = all->line - nbrline;
	x = all->column / 4;
	if (y > 0)
	{
		if ((all->line - nbrline > 10) && all->column > 38)
			ft_put_add(all, list, x, 8);
		else if (nbrline + 1 < all->line)
			ft_put_add(all, list, x, 0);
	}
}

void	ft_put_find2(t_arg *tmp, char *line)
{
	if (ft_strcmp(line, "*"))
	{
		while (tmp)
		{
			if (!ft_strcmp(tmp->name, line))
				tmp->select = 1;
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp)
		{
			tmp->select = 1;
			tmp = tmp->next;
		}
	}
}

void	ft_put_find(t_all *all, t_arg **list, int x, int y)
{
	char	*line;
	t_arg	*tmp;
	t_arg	*new;

	tmp = *list;
	line = NULL;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), x, y), all->fd);
	ft_putstr_fd("find : ", all->fd);
	ft_putstr_fd(tgetstr("ve", NULL), all->fd);
	tcsetattr(0, TCSADRAIN, &all->termcpy);
	get_next_line(0, &line);
	ft_put_find2(tmp, line);
	ft_putstr_fd(tgetstr("vi", NULL), all->fd);
	tcsetattr(0, TCSADRAIN, &all->term);
	ft_check_put_list(list, all);
}

void	ft_find(t_all *all, t_arg **list)
{
	int		nbrline;
	int		x;
	int		y;

	nbrline = ft_count_nbrline(all, list);
	y = all->line - nbrline;
	x = all->column / 4;
	if (y > 0)
	{
		if ((all->line - nbrline > 10) && all->column > 38)
			ft_put_find(all, list, x, 8);
		else if (nbrline + 1 < all->line)
			ft_put_find(all, list, x, 0);
	}
}
