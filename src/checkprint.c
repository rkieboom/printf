/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkieboom <rkieboom@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:10:57 by rkieboom          #+#    #+#             */
/*   Updated: 2025/08/06 14:54:01 by rkieboom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	checkprint(t_printf_context *list)
{
	int	ret;

	ret = -1;
	if (list->specifier == SPEC_INT)
		ret = checkprintint(list, -1);
	else if (list->specifier == SPEC_UINT)
		ret = checkprintunsignedint(list, -1);
	else if (list->specifier == SPEC_STRING)
		ret = checkprintstring(list);
	else if (list->specifier == SPEC_CHAR)
		ret = checkprintchar(list);
	else if (list->specifier == SPEC_POINTER)
		ret = checkprintpnter(list, ret);
	else if (list->specifier == SPEC_HEX_LOWER || list->specifier == SPEC_HEX_UPPER)
		ret = checkprinthex(list, -1);
	else if (list->specifier == SPEC_PERCENT)
		ret = checkprintprocent(list);
	return (ret);
}

int	checkprintprocent(t_printf_context *list)
{
	int	ret;

	ret = -1;
	if (!list->flags.has_width && !list->flags.zero_pad	&& !list->flags.left_align)
		ret = print_percent_simple(list);
	else if (list->flags.has_width && !list->flags.zero_pad && !list->flags.left_align)
		ret = print_percent_with_width(list);
	else if (!list->flags.has_width && list->flags.zero_pad && !list->flags.left_align)
		ret = print_percent_zero_padded(list);
	else if (!list->flags.has_width && !list->flags.zero_pad && list->flags.left_align)
		ret = print_percent_simple(list);
	else if (!list->flags.has_width && list->flags.zero_pad && list->flags.left_align)
		ret = print_percent_left_zero(list);
	else if (list->flags.has_width && !list->flags.zero_pad && list->flags.left_align)
		ret = print_percent_left_aligned(list);
	return (ret);
}

int	checkprintint(t_printf_context *list, int ret)
{
	char	*result;

	result = ft_itoa(va_arg(list->args, int));
	if (!result)
		return (-1);
	if (chkflagsnull(list) || (list->flags.left_align && !list->flags.has_width &&\
	!list->flags.has_precision && !list->flags.zero_pad))
		ret = print_int_simple(list, result);
	else if (list->flags.has_width && !list->flags.has_precision && !list->flags.zero_pad)
		ret = print_int_with_width(list, result);
	else if (!list->flags.has_width && list->flags.has_precision && !list->flags.zero_pad)
		ret = print_int_with_precision(list, result);
	else if (!list->flags.has_width && !list->flags.has_precision && list->flags.zero_pad)
		ret = print_int_zero_padded(list, result);
	else if (list->flags.has_width && list->flags.has_precision && !list->flags.zero_pad)
		ret = print_int_width_and_prec(list, result);
	else if (!list->flags.has_width && list->flags.has_precision && list->flags.zero_pad)
		ret = print_int_zero_and_prec(list, result, 0);
	else if (list->flags.has_width && list->flags.has_precision && list->flags.zero_pad)
		ret = print_int_width_and_prec(list, result);
	else if (list->flags.has_width && !list->flags.has_precision && list->flags.zero_pad)
		ret = print_int_zero_padded(list, result);
	free(result);
	return (ret);
}

int	checkprintunsignedint(t_printf_context *list, int ret)
{
	char	*result;

	result = ft_uitoa(va_arg(list->args, unsigned int));
	if (chkflagsnull(list) || (list->flags.left_align && !list->flags.has_width &&\
	!list->flags.has_precision && !list->flags.zero_pad))
		ret = print_uint_simple(list, result);
	else if (list->flags.has_width && !list->flags.has_precision\
	&& !list->flags.zero_pad)
		ret = print_uint_with_width(list, result);
	else if (!list->flags.has_width && list->flags.has_precision\
	&& !list->flags.zero_pad)
		ret = print_uint_with_precision(list, result);
	else if (!list->flags.has_width && !list->flags.has_precision\
	&& list->flags.zero_pad)
		ret = print_uint_zero_padded(list, result);
	else if (list->flags.has_width && list->flags.has_precision\
	&& !list->flags.zero_pad)
		ret = print_uint_width_and_prec(list, result);
	else if (!list->flags.has_width && list->flags.has_precision\
	&& list->flags.zero_pad)
		ret = print_uint_zero_and_prec(list, result);
	else if (list->flags.has_width && list->flags.has_precision\
	&& list->flags.zero_pad)
		ret = print_uint_width_and_prec(list, result);
	else if (list->flags.has_width && !list->flags.has_precision\
	&& list->flags.zero_pad)
		ret = print_uint_zero_padded(list, result);
	free(result);
	return (ret);
}
