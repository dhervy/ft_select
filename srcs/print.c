/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:48:36 by dhervy            #+#    #+#             */
/*   Updated: 2016/11/21 18:43:57 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_put_elem(t_all *all, t_arg *tmp)
{
	if (tmp->pos == 1)
		ft_putstr_fd(tgetstr("us", NULL), all->fd);
	if (tmp->select == 1)
		ft_putstr_fd(tgetstr("mr", NULL), all->fd);
	ft_putstr_fd(tmp->name, all->fd);
	ft_putstr_fd(tgetstr("me", NULL), all->fd);
}

void	ft_put_header(t_all *all)
{
	int		space;

	space = (all->column / 2) - 19;
	ft_putspace_fd(space, all->fd);
	ft_putstr_fd(LIGNE1, all->fd);
	ft_putspace_fd(space, all->fd);
	ft_putstr_fd(LIGNE2, all->fd);
	ft_putspace_fd(space, all->fd);
	ft_putstr_fd(LIGNE3, all->fd);
	ft_putspace_fd(space, all->fd);
	ft_putstr_fd(LIGNE4, all->fd);
	ft_putspace_fd(space, all->fd);
	ft_putstr_fd(LIGNE5, all->fd);
	ft_putspace_fd(space, all->fd);
	ft_putstr_fd(LIGNE6, all->fd);
	ft_putstr_fd("\n\n\n", all->fd);
}

void	ft_put_error(t_all *all)
{
	int		x;
	int		y;

	x = (all->column / 2) - 2;
	y = all->line / 2;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), x, y), all->fd);
	ft_putstr_fd("error", all->fd);
}

void	ft_put_list(t_arg **list, t_all *all, int lenmax)
{
	int		i;
	t_arg	*tmp;

	i = 0;
	tmp = *list;
	ft_putchar_fd('\n', all->fd);
	while (tmp)
	{
		if (i == all->columnlist)
		{
			ft_putchar_fd('\n', all->fd);
			i = 0;
		}
		ft_put_elem(all, tmp);
		if (i != all->columnlist - 1)
			ft_putspace_fd((lenmax - ft_strlen(tmp->name)) + 1, all->fd);
		i++;
		tmp = tmp->next;
	}
}

void	ft_check_put_list(t_arg **list, t_all *all)
{
	int		height_header;
	int		widht_header;
	int		nbrline;
	int		lenmax;

	ft_count_column(all);
	lenmax = ft_count_len_max(list);
	all->columnlist = all->column / (lenmax + 1);
	nbrline = ft_count_nbrline(all, list);
	height_header = 10;
	widht_header = 38;
	ft_clean(all);
	if ((all->line - nbrline > height_header) && all->column > widht_header)
		ft_put_header(all);
	if (nbrline + 1 < all->line)
		ft_put_list(list, all, lenmax);
	else if (all->line > height_header && all->column > widht_header)
		ft_put_header(all);
	if (nbrline > all->line && all->line > 1 && all->column > 5)
		ft_put_error(all);
}
