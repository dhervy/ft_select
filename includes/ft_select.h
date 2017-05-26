/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:29:17 by dhervy            #+#    #+#             */
/*   Updated: 2016/11/22 17:23:19 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "../libft/libft.h"
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>

# define LIGNE1 "\033[01;34m  __ _                _           _   \n"
# define LIGNE2 " / _| |_     ___  ___| | ___  ___| |_ \n"
# define LIGNE3 "| |_| __|   / __|/ _ \\ |/ _ \\/ __| __|\n"
# define LIGNE4 "|  _| |_    \\__ \\  __/ |  __/ (__| |_ \n"
# define LIGNE5 "|_|  \\__|___|___/\\___|_|\\___|\\___|\\__|\n"
# define LIGNE6 "       |_____|                        \n\033[00m"

int		g_global;

typedef struct		s_all
{
	struct termios	term;
	struct termios	termcpy;
	char			*name_term;
	int				column;
	int				line;
	int				columnlist;
	int				fd;
}					t_all;

typedef struct		s_arg
{
	char			*name;
	int				pos;
	int				select;
	int				num;
	struct s_arg	*next;
	struct s_arg	*prev;
}					t_arg;

void				ft_count_column(t_all *all);
int					ft_count_len_max(t_arg **list);
int					ft_init_term(t_all *all);
void				ft_init_list(t_arg **list, char **argv);
void				ft_put_list(t_arg **list, t_all *all, int lenmax);
int					ft_check_size(t_all *all);
int					my_outc(int c);
void				ft_clean(t_all *all);
void				ft_moove_curseur_left(t_all *all, t_arg **list);
void				ft_moove_curseur_right(t_all *all, t_arg **list);
void				ft_moove_curseur_top(t_all *all, t_arg **list);
void				ft_moove_curseur_bot(t_all *all, t_arg **list);
void				ft_select_list(t_all *all, t_arg **list);
void				ft_check_put_list(t_arg **list, t_all *all);
void				ft_find_key(t_all *all, t_arg **list);
void				ft_return(t_all *all, t_arg **list, int bol);
void				ft_free_list(t_all *all, t_arg **list);
void				ft_free_struct_all(t_all *all);
void				ft_free_struct_list(t_arg *tmp);
int					ft_count_nbrline(t_all *all, t_arg **list);
void				ft_find(t_all *all, t_arg **list);
void				ft_add(t_all *all, t_arg **list);
void				ft_signal();
void				sig_hook(int n);
void				ft_signal_z(t_all *all);
int					ft_count_nbrline(t_all *all, t_arg **list);

#endif
