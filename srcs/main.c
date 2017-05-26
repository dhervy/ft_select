/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:42:58 by dhervy            #+#    #+#             */
/*   Updated: 2016/11/22 16:32:09 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_clean(t_all *all)
{
	ft_putstr_fd(tgetstr("cl", NULL), all->fd);
}

int		ft_refresh(t_all *all, t_arg **list)
{
	while (42)
	{
		if (g_global == 2)
			ft_signal_z(all);
		if (ft_check_size(all) == 1 || g_global == 1)
		{
			if (g_global == 1)
				g_global = 0;
			ft_check_put_list(list, all);
		}
		ft_find_key(all, list);
	}
	return (0);
}

int		main(int argc, char **argv, char **env)
{
	t_all		*all;
	t_arg		*list;

	ft_signal();
	g_global = 0;
	all = (t_all*)ft_memalloc(sizeof(t_all));
	if ((all->fd = open(ttyname(0), O_RDWR)) == -1)
	{
		ft_putstr_fd("error", 0);
		return (-1);
	}
	if (argc <= 1)
		ft_putstr("Usage : ft_select [Param]\n");
	if (ft_init_term(all) == -1 || argc <= 1)
		return (-1);
	if (argc > 1)
		ft_init_list(&list, argv);
	ft_putstr_fd(tgetstr("vi", NULL), all->fd);
	ft_check_put_list(&list, all);
	ft_refresh(all, &list);
	return (0);
}
