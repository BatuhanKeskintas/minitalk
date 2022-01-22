/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:53:38 by bkeskint          #+#    #+#             */
/*   Updated: 2021/10/09 17:55:34 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	set_param(void)
{
	g_param.bytes = 0;
	g_param.c_pid = 0;
	g_param.c_rec = 0;
}

void	get_client_pid(void)
{
	set_param();
	signal(SIGUSR1, signal_handler1);
	signal(SIGUSR2, signal_handler1);
	while (g_param.bytes <= 16)
		pause();
	g_param.c_rec = 1;
	ft_printf("Client PID: %i\n", g_param.c_pid);
	kill(g_param.c_pid, SIGUSR1);
}

void	get_string_size(void)
{
	g_param.bytes = 0;
	g_param.size = 0;
	signal(SIGUSR1, signal_handler3);
	signal(SIGUSR2, signal_handler3);
	while (g_param.bytes <= 4 * 8)
		pause();
	g_param.str = (char *) malloc(g_param.size * sizeof(char));
	g_param.act = g_param.str;
	usleep(100);
	kill(g_param.c_pid, SIGUSR1);
}

void	get_char(void)
{
	char	act_char;

	g_param.bytes = 0;
	g_param.act_char = 0;
	act_char = '\0';
	while (g_param.bytes <= 8)
		pause();
	if (g_param.act_char == 0)
		g_param.act_char = -1;
	else
		act_char = (char) g_param.act_char;
	if (act_char != '\0')
	{
		*(g_param.act) = act_char;
		g_param.act++;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
	{
		g_param.act_char = 0;
		get_client_pid();
		get_string_size();
		if (g_param.str == 0)
			write(1, "An Error Occured !\n", 19);
		else
		{
			signal(SIGUSR1, signal_handler2);
			signal(SIGUSR2, signal_handler2);
			while (g_param.act_char != -1)
				get_char();
			write(1, g_param.str, g_param.size);
			write(1, "\n", 1);
			free(g_param.str);
			usleep(50);
			kill(g_param.c_pid, SIGUSR2);
		}
	}
	return (0);
}
