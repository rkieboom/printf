/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printstring3.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 14:50:03 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/30 16:18:19 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		string_minwidthprint(t_flags *list)
{
	char	*result;
	int		length;

	result = va_arg(list->ap, char*);
	if (!result)
	{
		if (ft_putstr("(null)") == -1)
			return (-1);
		length = 6;
	}
	else if ((int)ft_strlen(result) > list->flags_wval)
	{
		length = ft_strlen(result);
		if (ft_putstr(result) == -1)
			return (-1);
		list->chramount += length;
		return (0);
	}
	else
		length = ft_strlen(result);
	if (string_minwidthprint2(list, result, length) == -1)
		return (-1);
	return (0);
}

int		string_minwidthprint2(t_flags *list, char *result, int length)
{
	if (result)
		if (ft_putstr(result) == -1)
			return (-1);
	list->flags_wval -= length;
	list->chramount += length;
	while (list->flags_wval > 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->flags_wval--;
		list->chramount++;
	}
	return (0);
}
