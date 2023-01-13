/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printstring.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 05:32:23 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/30 16:16:43 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		printstring(t_flags *list)
{
	char *result;

	result = va_arg(list->ap, char*);
	if (!result)
	{
		if (ft_putstr("(null)") == -1)
			return (-1);
		list->chramount += 6;
		return (0);
	}
	list->chramount += ft_strlen(result);
	if (ft_putstr(result) == -1)
		return (-1);
	return (0);
}

int		string_precprint(t_flags *list)
{
	int		length;
	char	*result;

	result = va_arg(list->ap, char*);
	if (!result)
	{
		if (list->flags_precval <= 6)
		{
			length = list->flags_precval;
			if (ft_putstrlen("(null)", length) == -1)
				return (-1);
		}
		else
		{
			if (ft_putstr("(null)") == -1)
				return (-1);
			length = 6;
		}
		list->chramount += length;
		return (0);
	}
	if (string_precprint2(list, result, ft_strlen(result)) == -1)
		return (-1);
	return (0);
}

int		string_precprint2(t_flags *list, char *result, int length)
{
	if (list->flags_precval < length)
	{
		length = list->flags_precval;
		if (ft_putstrlen(result, length) == -1)
			return (-1);
	}
	else
	{
		length = ft_strlen(result);
		if (ft_putstr(result) == -1)
			return (-1);
	}
	list->chramount += length;
	return (0);
}

int		string_widthprint(t_flags *list)
{
	char	*result;
	int		length;

	result = va_arg(list->ap, char*);
	length = (!result) ? 6 : ft_strlen(result);
	if (length > list->flags_wval)
	{
		if (!result)
		{
			if (ft_putstr("(null)") == -1)
				return (-1);
		}
		else
		{
			if (ft_putstr(result) == -1)
				return (-1);
		}
		list->chramount += length;
		return (0);
	}
	if (string_widthprint2(list, result, length) == -1)
		return (-1);
	return (0);
}

int		string_widthprint2(t_flags *list, char *result, int length)
{
	list->chramount += list->flags_wval;
	list->flags_wval -= length;
	while (list->flags_wval > 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->flags_wval--;
	}
	if (!result)
	{
		if (ft_putstr("(null)") == -1)
			return (-1);
	}
	else
	{
		if (ft_putstr(result) == -1)
			return (-1);
	}
	return (0);
}
