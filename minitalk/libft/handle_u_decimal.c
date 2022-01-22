/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:10:51 by bkeskint          #+#    #+#             */
/*   Updated: 2021/08/16 22:05:54 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"ft_printf.h"

char	*convert_u(unsigned int num, int base)
{
	static char		*representation;
	static char		buffer[50];
	char			*ptr;

	representation = "0123456789";
	ptr = &buffer[49];
	*ptr = '\0';
	while (num != 0)
	{
		*-- ptr = representation[num % base];
		num /= base;
	}
	return (ptr);
}

void	handle_u_decimal(t_parameters table)
{
	unsigned int	num;

	num = va_arg(table->ap, unsigned int);
	if (num == 0)
		table->count += write(1, "0", 1);
	else
		table->count += write(1, convert_u(num, 10),
				ft_strlen(convert_u(num, 10)));
	(table->i)++;
}
