/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_big_hexadecimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:53:59 by bkeskint          #+#    #+#             */
/*   Updated: 2021/08/16 22:05:20 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"ft_printf.h"

char	*convert_bx(unsigned int num, int base)
{
	static char		*representation;
	static char		buffer[50];
	char			*ptr;

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

void	handle_big_hexadecimal(t_parameters table)
{
	unsigned int	i;

	i = va_arg(table->ap, unsigned int);
	if (i == 0)
	{
		table->count += write(1, "0", 1);
	}
	else
		table->count += write(1, convert_bx(i, 16),
				ft_strlen (convert_bx(i, 16)));
	(table->i)++;
}
