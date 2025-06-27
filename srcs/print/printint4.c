/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printint4.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 13:57:41 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/30 13:58:23 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_printnull(t_flags *list, char *result)
{
	int		length;
	int		i;

	i = 0;
	length = ft_strlen(result);
	list->chramount += ft_strlen(result);
	if (list->flags_minus == 1)
	{
		if (ft_putstr(result) == -1)
			return (-1);
	}
	else if (*result == '-')
	{
		if (ft_putchar('-') == -1)
			return (-1);
		list->flags_precval++;
		i = 1;
	}
	if (int_printnull2(list, result, length, i) == -1)
		return (-1);
	return (0);
}

int		int_printnull2(t_flags *list, char *result, int length, int i)
{
	while ((list->flags_zeroval - length) > 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		list->chramount++;
		list->flags_zeroval--;
	}
	if (list->flags_minus == 0)
		if (ft_putstr(result + i) == -1)
			return (-1);
	return (0);
}
