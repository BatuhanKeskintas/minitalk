/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:43:08 by bkeskint          #+#    #+#             */
/*   Updated: 2021/08/16 22:08:59 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_parameters
{
	va_list	ap;
	int		i;
	char	c;
	char	cha;
	size_t	count;
}	*t_parameters;

int		ft_printf(const char *string, ...);
void	initialize(t_parameters table);
void	interpret(const char *string, t_parameters table);
void	jump(const char *string, t_parameters table);
void	handle_integer(t_parameters table);
void	handle_char(t_parameters table);
void	percent(t_parameters table);
void	handle_string(t_parameters table);
void	handle_hexadecimal(t_parameters table);
void	handle_pointer(t_parameters table);
void	handle_u_decimal(t_parameters table);
void	handle_big_hexadecimal(t_parameters table);

#endif