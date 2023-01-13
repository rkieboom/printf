/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 13:10:57 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/30 16:50:44 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		checkprint(t_flags *list)
{
	int ret;

	ret = -1;
	if (list->type_int == 1)
		ret = checkprintint(list, -1);
	else if (list->type_uint == 1)
		ret = checkprintunsignedint(list, -1);
	else if (list->type_string == 1)
		ret = checkprintstring(list);
	else if (list->type_char == 1)
		ret = checkprintchar(list);
	else if (list->type_pnter == 1)
		ret = checkprintpnter(list, ret);
	else if (list->type_uhex == 1 || list->type_uhexcap)
		ret = checkprinthex(list, -1);
	else if (list->type_procent > 0)
		ret = checkprintprocent(list);
	return (ret);
}

int		checkprintprocent(t_flags *list)
{
	int ret;

	ret = -1;
	if (list->flags_width == 0 && list->flags_zero\
	== 0 && list->flags_minus == 0)
		ret = p_print(list);
	else if (list->flags_width == 1 && list->flags_zero\
	== 0 && list->flags_minus == 0)
		ret = p_printwidth(list);
	else if (list->flags_width == 0 && list->flags_zero\
	== 1 && list->flags_minus == 0)
		ret = p_printnull(list);
	else if (list->flags_width == 0 && list->flags_zero\
	== 0 && list->flags_minus == 1)
		ret = p_print(list);
	else if (list->flags_width == 0 && list->flags_zero\
	== 1 && list->flags_minus == 1)
		ret = p_printminnull(list);
	else if (list->flags_width == 1 && list->flags_zero\
	== 0 && list->flags_minus == 1)
		ret = p_printminwidth(list);
	return (ret);
}

int		checkprintint(t_flags *list, int ret)
{
	char	*result;

	result = ft_itoa(va_arg(list->ap, int));
	if (!result)
		return (-1);
	if (chkflagsnull(list) || (list->flags_minus == 1 && list->flags_width\
	== 0 && list->flags_precision == 0 && list->flags_zero == 0))
		ret = printint(list, result);
	else if (list->flags_width == 1 && list->flags_precision\
	== 0 && list->flags_zero == 0)
		ret = int_printwidth(list, result);
	else if (list->flags_width == 0 && list->flags_precision\
	== 1 && list->flags_zero == 0)
		ret = int_printprec(list, result);
	else if (list->flags_width == 0 && list->flags_precision\
	== 0 && list->flags_zero == 1)
		ret = int_printnull(list, result);
	else if (list->flags_width == 1 && list->flags_precision\
	== 1 && list->flags_zero == 0)
		ret = int_printwidthprec(list, result);
	else if (list->flags_width == 0 && list->flags_precision\
	== 1 && list->flags_zero == 1)
		ret = int_printzeroprec(list, result, 0);
	free(result);
	return (ret);
}

int		checkprintunsignedint(t_flags *list, int ret)
{
	char	*result;

	result = ft_uitoa(va_arg(list->ap, unsigned int));
	if (chkflagsnull(list) || (list->flags_minus == 1 &&\
	list->flags_width == 0 && list->flags_precision ==\
	0 && list->flags_zero == 0))
		ret = printuint(list, result);
	else if (list->flags_width == 1 && list->flags_precision\
	== 0 && list->flags_zero == 0)
		ret = uint_printwidth(list, result);
	else if (list->flags_width == 0 && list->flags_precision\
	== 1 && list->flags_zero == 0)
		ret = uint_printprec(list, result);
	else if (list->flags_width == 0 && list->flags_precision\
	== 0 && list->flags_zero == 1)
		ret = uint_printnull(list, result);
	else if (list->flags_width == 1 && list->flags_precision\
	== 1 && list->flags_zero == 0)
		ret = uint_printwidthprec(list, result);
	else if (list->flags_width == 0 && list->flags_precision\
	== 1 && list->flags_zero == 1)
		ret = uint_printzeroprec(list, result);
	free(result);
	return (ret);
}
