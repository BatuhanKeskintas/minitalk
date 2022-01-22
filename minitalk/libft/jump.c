/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:18:23 by bkeskint          #+#    #+#             */
/*   Updated: 2021/08/16 22:05:38 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	jump(const char *string, t_parameters table)
{
	if (string[table->i] == 'c')
		handle_char (table);
	else if (string[table->i] == 'd' || string[table->i] == 'i')
		handle_integer (table);
	else if (string[table->i] == 's')
		handle_string (table);
	else if (string[table->i] == 'p')
		handle_pointer (table);
	else if (string[table->i] == 'u')
		handle_u_decimal (table);
	else if (string[table->i] == 'x')
		handle_hexadecimal (table);
	else if (string[table->i] == 'X')
		handle_big_hexadecimal (table);
	else
	{
		table->c = string[table->i];
		table->count += write(1, &(table->c), 1);
		(table->i)++;
	}
}
