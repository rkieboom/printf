/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printhex.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 07:01:40 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/31 16:48:56 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printhex(t_flags *list, char *result)
{
	list->chramount += ft_strlen(result);
	if (ft_putstr(result) == -1)
		return (-1);
	return (0);
}

int		hex_printwidth(t_flags *list, char *result)
{
	int		length;

	length = ft_strlen(result);
	list->chramount += ft_strlen(result);
	if (list->flags_minus == 1)
		if (ft_putstr(result) == -1)
			return (-1);
	while ((list->flags_wval - length) > 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->chramount++;
		list->flags_wval--;
	}
	if (list->flags_minus == 0)
		if (ft_putstr(result) == -1)
			return (-1);
	return (0);
}

int		hex_printprec(t_flags *list, char *result)
{
	int		length;

	length = ft_strlen(result);
	if (result[0] == '0' && result[1] == '\0' && list->flags_precval == 0)
		result[0] = '\0';
	list->chramount += ft_strlen(result);
	while ((list->flags_precval - length) > 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		list->chramount++;
		list->flags_precval--;
	}
	if (ft_putstr(result) == -1)
		return (-1);
	return (0);
}

int		hex_printnull(t_flags *list, char *result)
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
	if (hex_printnull2(list, result, length, i) == -1)
		return (-1);
	return (0);
}
