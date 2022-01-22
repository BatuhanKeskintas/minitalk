/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:17:29 by bkeskint          #+#    #+#             */
/*   Updated: 2021/08/16 22:17:34 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	acknowledge(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("Acknowledged.\n");
}

int	main(int argc, char **argv)
{
	char	*ps_pid;
	char	*p_str;
	int		s_pid;

	if (argc > 2)
	{
		ps_pid = argv[1];
		s_pid = ft_atoi(ps_pid);
		p_str = argv[2];
		pid_sender(s_pid);
		signal(SIGUSR1, acknowledge);
		signal(SIGUSR2, acknowledge);
		pause();
		string_size_sender(s_pid, ft_strlen(p_str));
		pause();
		while (*p_str != 0)
		{
			string_sender(s_pid, p_str);
			p_str++;
		}
		string_sender(s_pid, p_str);
		pause();
	}
	return (0);
}
