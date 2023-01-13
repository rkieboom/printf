/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkprint2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 17:49:31 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/30 16:50:48 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		checkprintstring(t_flags *list)
{
	int		ret;

	ret = -1;
	if (chkflagsnull(list) || (list->flags_minus == 1 &&\
	list->flags_precision == 0 &&\
	list->flags_width == 0 && list->flags_zero == 0))
		ret = printstring(list);
	else if (list->flags_precision == 1 &&\
	list->flags_width == 0 && list->flags_zero == 0)
		ret = string_precprint(list);
	else if (list->flags_minus == 0 && list->flags_precision == 0\
	&& list->flags_width == 1)
		ret = string_widthprint(list);
	else if (list->flags_minus == 1 && list->flags_precision == 0\
	&& list->flags_width == 1)
		ret = string_minwidthprint(list);
	else if (list->flags_minus == 0 && list->flags_precision == 1\
	&& list->flags_width == 1)
		ret = string_precwidthprint(list);
	else if (list->flags_minus == 1 && list->flags_precision == 1\
	&& list->flags_width == 1)
		ret = string_minprecwidthprint(list);
	return (ret);
}

int		checkprintchar(t_flags *list)
{
	int ret;

	ret = -1;
	if (chkflagsnull(list) || (list->flags_minus == 1 &&\
	list->flags_precision == 0 &&\
	list->flags_width == 0 && list->flags_zero == 0))
		ret = printchar(list);
	else if (list->flags_minus == 0 && list->flags_precision == 0\
	&& list->flags_width == 1 && list->flags_zero == 0)
		ret = char_widthprint(list);
	else if (list->flags_minus == 1 && list->flags_precision == 0\
	&& list->flags_width == 1 && list->flags_zero == 0)
		ret = char_minwidthprint(list);
	return (ret);
}

int		checkprintpnter(t_flags *list, int ret)
{
	unsigned long	decimal;
	char			*result;

	decimal = va_arg(list->ap, unsigned long);
	if (decimal == 0)
		list->flags_precision ? (result = ft_strdup("0x"))\
		: (result = ft_strdup("0x0"));
	else
		result = convtopnter(list, decimal);
	if (!result)
		return (-1);
	result[0] = '0';
	result[1] = 'x';
	if (chkflagsnull(list) || (list->flags_minus == 1\
	&& list->flags_width == 0 && list->flags_zero == 0))
		ret = printpnter(list, result);
	else if (list->flags_width == 1 && list->flags_zero == 0)
		ret = pnt_widthprint(list, result);
	else if (list->flags_minus == 0 && list->flags_width\
	== 0 && list->flags_zero == 0)
		ret = pnt_precprint(list, decimal);
	free(result);
	return (ret);
}

int		checkprinthex(t_flags *list, int ret)
{
	char	*result;

	result = convtohex(list, va_arg(list->ap, unsigned int));
	if (!result)
		return (-1);
	if (chkflagsnull(list) || (list->flags_minus == 1 && list->flags_precision\
	== 0 && list->flags_width == 0 && list->flags_zero == 0))
		ret = printhex(list, result);
	else if (list->flags_precision == 0 && \
	list->flags_width == 1 && list->flags_zero == 0)
		ret = hex_printwidth(list, result);
	else if (list->flags_precision == 1 &&\
	list->flags_width == 0 && list->flags_zero == 0)
		ret = hex_printprec(list, result);
	else if (list->flags_zero == 1 && list->flags_precision == 0\
	&& list->flags_width == 0)
		ret = hex_printnull(list, result);
	else if (list->flags_zero == 0 && list->flags_precision == 1\
	&& list->flags_width == 1)
		ret = hex_printwidthprec(list, result);
	else if (list->flags_zero == 1 && list->flags_precision == 1\
	&& list->flags_width == 0)
		ret = hex_printzeroprec(list, result, 0);
	free(result);
	return (ret);
}
