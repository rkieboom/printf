/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printstring2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 14:49:48 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/30 16:14:58 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		string_precwidthprint(t_flags *list)
{
	char	*result;
	int		length;

	length = 0;
	result = va_arg(list->ap, char*);
	if (!result)
	{
		length = (list->flags_precval < 6) ? list->flags_precval : 6;
		if (list->flags_wval >= length)
			list->chramount += list->flags_wval;
		else
			list->chramount += length;
		list->flags_wval -= length;
		while (list->flags_wval > 0)
		{
			if (ft_putchar(' ') == -1)
				return (-1);
			list->flags_wval--;
		}
		if (ft_putstrlen("(null)", length) == -1)
			return (-1);
	}
	else if (string_precwidthprint2(list, result, length) == -1)
		return (-1);
	return (0);
}

int		string_precwidthprint2(t_flags *list, char *result, int length)
{
	if (list->flags_precval < (int)ft_strlen(result))
		length = list->flags_precval;
	else
		length = ft_strlen(result);
	if (list->flags_wval <= length)
	{
		if (ft_putstrlen(result, length) == -1)
			return (-1);
	}
	else
	{
		list->flags_wval -= length;
		list->chramount += list->flags_wval;
		while (list->flags_wval > 0)
		{
			if (ft_putchar(' ') == -1)
				return (-1);
			list->flags_wval--;
		}
		if (ft_putstrlen(result, length) == -1)
			return (-1);
	}
	list->chramount += length;
	return (0);
}

int		string_minprecwidthprint(t_flags *list)
{
	char	*result;
	int		length;

	length = 0;
	result = va_arg(list->ap, char*);
	if (!result)
	{
		length = (list->flags_precval < 6) ? list->flags_precval : 6;
		if (list->flags_wval >= length)
			list->chramount += list->flags_wval;
		else
			list->chramount += length;
		list->flags_wval -= length;
		if (ft_putstrlen("(null)", length) == -1)
			return (-1);
		while (list->flags_wval > 0)
		{
			if (ft_putchar(' ') == -1)
				return (-1);
			list->flags_wval--;
		}
	}
	else if (string_minprecwidthprint2(list, result, length) == -1)
		return (-1);
	return (0);
}

int		string_minprecwidthprint2(t_flags *list, char *result, int length)
{
	if (list->flags_precval < (int)ft_strlen(result))
		length = list->flags_precval;
	else
		length = ft_strlen(result);
	if (list->flags_wval <= length)
	{
		if (ft_putstrlen(result, length) == -1)
			return (-1);
	}
	else
	{
		list->flags_wval -= length;
		list->chramount += list->flags_wval;
		if (ft_putstrlen(result, length) == -1)
			return (-1);
		while (list->flags_wval > 0)
		{
			if (ft_putchar(' ') == -1)
				return (-1);
			list->flags_wval--;
		}
	}
	list->chramount += length;
	return (0);
}
