/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printuint.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 19:20:36 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/31 18:06:35 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printuint(t_flags *list, char *result)
{
	list->chramount += (int)ft_strlen(result);
	if (ft_putstr(result) == -1)
		return (-1);
	return (0);
}

int		uint_printwidth(t_flags *list, char *result)
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

int		uint_printprec(t_flags *list, char *result)
{
	int		length;
	int		i;

	i = 0;
	length = ft_strlen(result);
	if (result[0] == '0' && result[1] == '\0' && list->flags_precval == 0)
		result[0] = '\0';
	list->chramount += ft_strlen(result);
	if (*result == '-')
	{
		if (*result == '-')
		{
			if (ft_putchar('-') == -1)
				return (-1);
			list->flags_precval++;
			i = 1;
		}
	}
	if (int_printprec2(list, result, length, i) == -1)
		return (-1);
	return (0);
}

int		uint_printprec2(t_flags *list, char *result, int length, int i)
{
	while ((list->flags_precval - length) > 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		list->chramount++;
		list->flags_precval--;
	}
	if (list->flags_minus == 0)
		if (ft_putstr(result + i) == -1)
			return (-1);
	return (0);
}

int		uint_printnull(t_flags *list, char *result)
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
	if (uint_printnull2(list, result, length, i) == -1)
		return (-1);
	return (0);
}
