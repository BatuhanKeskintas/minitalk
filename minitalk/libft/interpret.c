/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:15:23 by bkeskint          #+#    #+#             */
/*   Updated: 2021/08/16 22:05:43 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	interpret(const char *string, t_parameters table)
{
	while (string[table->i] != '\0')
	{
		if (string[table->i] == '%')
		{
			(table->i)++;
			if (string[table->i] != '%')
			{
				jump(string, table);
			}
			else
				percent(table);
		}
		else
		{
			table->c = string[table->i];
			table->count += write(1, &(table->c), 1);
			(table->i)++;
		}
	}
}
