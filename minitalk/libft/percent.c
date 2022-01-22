/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:36:52 by bkeskint          #+#    #+#             */
/*   Updated: 2021/07/30 01:40:18 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent(t_parameters table)
{
	table->c = '%';
	table->count += write(1, &(table->c), 1);
	(table->i)++;
}
