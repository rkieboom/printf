/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printint2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 16:39:17 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/30 16:13:33 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		int_printzeroprec(t_flags *list, char *result, int i)
{
	int		length;

	length = ft_strlen(result);
	if (*result == '0' && length == 1)
	{
		*result = '\0';
		length--;
	}
	list->chramount += length;
	if (*result == '-')
		list->flags_precval++;
	while ((list->flags_zeroval - checkbignum(0, list->flags_precval, length))\
	> 0 && list->flags_minus == 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->chramount++;
		list->flags_zeroval--;
	}
	if (int_printzeroprec2(list, result, length, i) == -1)
		return (-1);
	return (0);
}

int		int_printzeroprec2(t_flags *list, char *result, int length, int i)
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
	if (int_printzeroprec3(list, result, precval, i) == -1)
		return (-1);
	return (0);
}

int		int_printzeroprec3(t_flags *list, char *result, int precval, int i)
{
	int length;

	length = ft_strlen(result);
	while (list->flags_zeroval - checkbignum(0, precval, length)\
	> 0 && list->flags_minus == 1)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->chramount++;
		list->flags_zeroval--;
	}
	if (list->flags_minus == 0)
		if (ft_putstr(result + i) == -1)
			return (-1);
	return (0);
}
