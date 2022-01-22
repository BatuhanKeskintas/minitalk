/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:41:10 by bkeskint          #+#    #+#             */
/*   Updated: 2021/08/16 22:06:08 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*convert_int(unsigned int num, int base)
{
	static char	*representation;
	static char	buffer[50];
	char		*ptr;

	representation = "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	while (num != 0)
	{
		*-- ptr = representation[num % base];
		num /= base;
	}
	return (ptr);
}

static void	put_number(char *ptr, t_parameters table)
{
	int	i;

	i = 0;
	while (ptr[i] != '\0')
	{
		table->count += write(1, &ptr[i], 1);
		i++;
	}
}

void	handle_integer(t_parameters table)
{
	long int	number;
	long int	x;

	number = va_arg(table->ap, int);
	x = number;
	if (x < 0)
	{
		table->count += write(1, "-", 1);
		x = -x;
	}
	if (number == 0)
		table->count += write(1, "0", 1);
	else
		put_number (convert_int(x, 10), table);
	(table->i)++;
}
