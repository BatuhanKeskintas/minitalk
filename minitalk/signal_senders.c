/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_senders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:29:58 by bkeskint          #+#    #+#             */
/*   Updated: 2021/10/22 14:44:03 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	string_sender(int pid, char *act_char)
{
	int	i;
	int	act_char_i;

	act_char_i = (int) *act_char;
	i = 0;
	while (i <= 8)
	{
		if (act_char_i % 2 == 0)
		{
			kill(pid, SIGUSR1);
			pause();
		}
		else
		{
			kill(pid, SIGUSR2);
			pause();
		}
		act_char_i /= 2;
		i++;
	}
	usleep(50);
}

void	string_size_sender(int pid, size_t str_size)
{
	int	i;

	i = 0;
	while (i <= 4 * 8)
	{
		if (str_size % 2 == 0)
		{
			kill(pid, SIGUSR1);
			pause();
		}
		else
		{
			kill(pid, SIGUSR2);
			pause();
		}
		str_size /= 2;
		i++;
	}
	usleep(50);
}

void	pid_sender(int pid)
{
	int	i;
	int	c_pid;

	c_pid = getpid();
	ft_printf("PID: %i\n", c_pid);
	i = 0;
	while (i <= 16)
	{
		if (c_pid % 2 == 0)
		{
			usleep(200);
			kill(pid, SIGUSR1);
		}
		else
		{
			usleep(200);
			kill(pid, SIGUSR2);
		}
		c_pid /= 2;
		i++;
	}
}
