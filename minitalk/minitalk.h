/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:17:33 by bkeskint          #+#    #+#             */
/*   Updated: 2021/10/22 14:43:52 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

/*
	recieved_bytes
	client pid
	client recieved
	sending string size
	actual char
	begining of the string
	actual
*/

struct s_param
{
	int		bytes;
	int		c_pid;
	int		c_rec;
	int		size;
	int		act_char;
	char	*str;
	char	*act;
}	g_param;

void	signal_handler1(int sig);
void	signal_handler2(int sig);
void	signal_handler3(int sig);
void	pid_sender(int pid);
void	acknowledge(int sig);
void	string_size_sender(int pid, size_t size);
void	string_sender(int pid, char *act);

#endif
