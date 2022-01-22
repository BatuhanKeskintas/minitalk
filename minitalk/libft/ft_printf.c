/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:58:40 by bkeskint          #+#    #+#             */
/*   Updated: 2021/07/29 15:57:42 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *string, ...)
{
	t_parameters	table;
	size_t			counter;

	table = malloc(sizeof(struct s_parameters));
	if (!table || !string)
	{
		if (!string)
			free(table);
		return (-1);
	}
	initialize(table);
	va_start (table->ap, string);
	interpret(string, table);
	va_end (table->ap);
	counter = table->count;
	free (table);
	return (counter);
}
