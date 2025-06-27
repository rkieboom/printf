/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printchar.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 05:35:35 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/30 16:37:51 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printchar(t_flags *list)
{
	char result;

	result = va_arg(list->ap, int);
	list->chramount++;
	if (ft_putchar(result) == -1)
		return (-1);
	return (0);
}

int		char_widthprint(t_flags *list)
{
	char result;

	result = va_arg(list->ap, int);
	while ((list->flags_wval - 1) > 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->flags_wval--;
		list->chramount++;
	}
	if (ft_putchar(result) == -1)
		return (-1);
	list->chramount++;
	return (0);
}

int		char_minwidthprint(t_flags *list)
{
	char result;

	result = va_arg(list->ap, int);
	if (ft_putchar(result) == -1)
		return (-1);
	list->chramount++;
	while ((list->flags_wval - 1) > 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->flags_wval--;
		list->chramount++;
	}
	return (0);
}
