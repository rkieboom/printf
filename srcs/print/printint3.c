/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printint3.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 16:41:29 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/30 16:13:44 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_printwidthprec(t_flags *list, char *result)
{
	int		length;
	int		i;

	i = 0;
	if (result[0] == '0' && result[1] == '\0' && list->flags_precval == 0)
		result[0] = '\0';
	list->chramount += ft_strlen(result);
	length = ft_strlen(result);
	if (*result == '-')
		list->flags_precval++;
	while ((list->flags_wval - checkbignum(0, list->flags_precval, length))\
	> 0 && list->flags_minus == 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->chramount++;
		list->flags_wval--;
	}
	if (int_printwidthprec2(list, result, length, i) == -1)
		return (-1);
	return (0);
}

int		int_printwidthprec2(t_flags *list, char *result, int length, int i)
{
	int precval;

	precval = list->flags_precval;
	if (*result == '-')
	{
		if (ft_putchar('-') == -1)
			return (-1);
		i = 1;
	}
	while ((list->flags_precval - length) > 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		list->chramount++;
		list->flags_precval--;
	}
	if (list->flags_minus == 1)
		if (ft_putstr(result + i) == -1)
			return (-1);
	if (int_printwidthprec3(list, result, precval, i) == -1)
		return (-1);
	return (0);
}

int		int_printwidthprec3(t_flags *list, char *result, int precval, int i)
{
	int length;

	length = ft_strlen(result);
	while (list->flags_wval - checkbignum(0, precval, length)\
	> 0 && list->flags_minus == 1)
	{
		ft_putchar(' ');
		list->chramount++;
		list->flags_wval--;
	}
	if (list->flags_minus == 0)
		if (ft_putstr(result + i) == -1)
			return (-1);
	return (0);
}
