/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:40:12 by dhervy            #+#    #+#             */
/*   Updated: 2016/11/21 18:42:10 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_signal_z(t_all *all)
{
	char	c[2];

	c[0] = all->term.c_cc[VSUSP];
	c[1] = '\0';
	ft_clean(all);
	ft_putstr_fd(tgetstr("ve", NULL), all->fd);
	tcsetattr(0, TCSADRAIN, &all->termcpy);
	signal(SIGTSTP, SIG_DFL);
	g_global = 0;
	ioctl(0, TIOCSTI, c);
}

int		ft_fg(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	ft_putstr_fd(tgetstr("cl", NULL), 2);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 0;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &term);
	signal(SIGTSTP, sig_hook);
	ft_putstr_fd(tgetstr("vi", NULL), 2);
	g_global = 1;
	return (0);
}

void	sig_hook(int n)
{
	if (n == 2)
		g_global = 3;
	if (n == 18)
		g_global = 2;
	else if (n == 19)
		ft_fg();
}

void	ft_signal(void)
{
	signal(SIGINT, sig_hook);
	signal(SIGQUIT, sig_hook);
	signal(SIGTSTP, sig_hook);
	signal(SIGCONT, sig_hook);
}
