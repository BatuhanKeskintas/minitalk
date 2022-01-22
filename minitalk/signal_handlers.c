/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:30:20 by bkeskint          #+#    #+#             */
/*   Updated: 2021/08/16 23:28:39 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler1(int signal)
{
	int	base;
	int	i;

	base = 1;
	i = 0;
	while (i < g_param.bytes)
	{
		base = base * 2;
		i++;
	}
	if (g_param.c_rec == 0 && signal == SIGUSR2)
		g_param.c_pid += base;
	g_param.bytes++;
	usleep(50);
}

void	signal_handler2(int signal)
{
	int	base;
	int	i;

	base = 1;
	i = 0;
	while (i < g_param.bytes)
	{
		base = base * 2;
		i++;
	}
	if (signal == SIGUSR2)
		g_param.act_char += base;
	g_param.bytes++;
	usleep(50);
	kill(g_param.c_pid, SIGUSR1);
}

void	signal_handler3(int signal)
{
	int	base;
	int	i;

	base = 1;
	i = 0;
	while (i < g_param.bytes)
	{
		base = base * 2;
		i++;
	}
	if (signal == SIGUSR2)
		g_param.size += base;
	g_param.bytes++;
	usleep(50);
	kill(g_param.c_pid, SIGUSR1);
}
