/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:15:34 by bkeskint          #+#    #+#             */
/*   Updated: 2021/08/16 22:06:02 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"ft_printf.h"

char	*convert_p(unsigned long long num, int base)
{
	static char		*representation;
	static char		buffer[50];
	char			*ptr;

	representation = "0123456789abcdef";
	ptr = &buffer[49];
	*ptr = '\0';
	while (num != 0)
	{
		*-- ptr = representation[num % base];
		num /= base;
	}
	return (ptr);
}

void	handle_pointer(t_parameters table)
{
	unsigned long long	num;
	unsigned long long	x;

	num = va_arg(table->ap, unsigned long);
	x = num;
	if (x == 0)
		table->count += write(1, "0x0", 3);
	else
	{
		table->count += write(1, "0x", 2);
		table->count += write(1, convert_p(num, 16),
				ft_strlen(convert_p(num, 16)));
	}
	(table->i)++;
}
