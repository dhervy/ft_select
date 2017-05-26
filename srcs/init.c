/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:49:48 by dhervy            #+#    #+#             */
/*   Updated: 2016/11/21 18:33:49 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_init_term(t_all *all)
{
	if ((all->name_term = getenv("TERM")) == NULL)
	{
		ft_putstr_fd("Error : No Env\n", 2);
		return (-1);
	}
	if (tgetent(NULL, all->name_term) == 0)
		return (-1);
	if (tcgetattr(0, &all->term) == -1)
		return (-1);
	if (tcgetattr(0, &all->termcpy) == -1)
		return (-1);
	all->term.c_lflag &= ~(ICANON);
	all->term.c_lflag &= ~(ECHO);
	all->term.c_cc[VMIN] = 0;
	all->term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &all->term);
	return (1);
}

t_arg	*ft_init_new(t_arg *new, char *str)
{
	new = (t_arg*)ft_memalloc(sizeof(t_arg));
	new->name = ft_strdup(str);
	new->pos = 1;
	new->select = 0;
	new->num = 1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_init_list(t_arg **list, char **argv)
{
	t_arg	*new;
	t_arg	*tmp;
	int		i;
	int		num;

	i = 2;
	num = 2;
	new = ft_init_new(new, argv[1]);
	tmp = new;
	*list = new;
	while (argv[i])
	{
		new = NULL;
		new = (t_arg*)ft_memalloc(sizeof(t_arg));
		new->name = ft_strdup(argv[i]);
		new->pos = 0;
		new->select = 0;
		new->num = num;
		new->next = NULL;
		new->prev = tmp;
		tmp->next = new;
		tmp = new;
		i++;
		num++;
	}
}
