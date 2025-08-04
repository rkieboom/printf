/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkprint2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkieboom <rkieboom@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:49:31 by rkieboom          #+#    #+#             */
/*   Updated: 2025/08/06 15:52:53 by rkieboom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	checkprintstring(t_printf_context *list)
{
	int	ret;

	ret = -1;
	if (chkflagsnull(list) || (list->flags.left_align && !list->flags.has_precision &&\
	!list->flags.has_width && !list->flags.zero_pad))
		ret = print_string_simple(list);
	else if (list->flags.has_precision && !list->flags.has_width && !list->flags.zero_pad)
		ret = print_string_with_precision(list);
	else if (!list->flags.left_align && !list->flags.has_precision && list->flags.has_width)
		ret = print_string_with_width(list);
	else if (list->flags.left_align && !list->flags.has_precision && list->flags.has_width)
		ret = print_string_left_aligned(list);
	else if (!list->flags.left_align && list->flags.has_precision && list->flags.has_width)
		ret = print_string_width_and_prec(list);
	else if (list->flags.left_align && list->flags.has_precision && list->flags.has_width)
		ret = print_string_left_width_prec(list);
	return (ret);
}

int	checkprintchar(t_printf_context *list)
{
	int	ret;

	ret = -1;
	if (chkflagsnull(list) || (list->flags.left_align && !list->flags.has_precision &&\
	!list->flags.has_width && !list->flags.zero_pad))
		ret = print_char_simple(list);
	else if (!list->flags.left_align && !list->flags.has_precision\
	&& list->flags.has_width && !list->flags.zero_pad)
		ret = print_char_with_width(list);
	else if (list->flags.left_align && !list->flags.has_precision\
	&& list->flags.has_width && !list->flags.zero_pad)
		ret = print_char_left_aligned(list);
	return (ret);
}

int	checkprintpnter(t_printf_context *list, int ret)
{
	unsigned long	decimal;
	char			*result;

	decimal = va_arg(list->args, unsigned long);
	if (decimal == 0)
		list->flags.has_precision ? (result = ft_strdup("0x"))\
		: (result = ft_strdup("0x0"));
	else
		result = convtopnter(list, decimal);
	if (!result)
		return (-1);
	result[0] = '0';
	result[1] = 'x';
	if (chkflagsnull(list) || (list->flags.left_align && !list->flags.has_width &&\
	!list->flags.zero_pad))
		ret = print_pointer_simple(list, result);
	else if (list->flags.has_width && !list->flags.zero_pad)
		ret = print_pointer_with_width(list, result);
	else if (!list->flags.left_align && !list->flags.has_width && !list->flags.zero_pad)
		ret = print_pointer_with_precision(list, decimal);
	free(result);
	return (ret);
}

int	checkprinthex(t_printf_context *list, int ret)
{
	char	*result;

	result = convtohex(list, va_arg(list->args, unsigned int));
	if (!result)
		return (-1);
	if (chkflagsnull(list) || (list->flags.left_align && !list->flags.has_precision &&\
	!list->flags.has_width && !list->flags.zero_pad))
		ret = print_hex_simple(list, result);
	else if (!list->flags.has_precision && list->flags.has_width &&\
	!list->flags.zero_pad)
		ret = print_hex_with_width(list, result);
	else if (list->flags.has_precision &&\
	!list->flags.has_width && !list->flags.zero_pad)
		ret = print_hex_with_precision(list, result);
	else if (list->flags.zero_pad && !list->flags.has_precision &&\
	!list->flags.has_width)
		ret = print_hex_zero_padded(list, result);
	else if (!list->flags.zero_pad && list->flags.has_precision &&\
	list->flags.has_width)
		ret = print_hex_width_and_prec(list, result);
	else if (list->flags.zero_pad && list->flags.has_precision &&\
	!list->flags.has_width)
		ret = print_hex_zero_and_prec(list, result);
	else if (list->flags.has_width && list->flags.has_precision &&\
	list->flags.zero_pad)
		ret = print_hex_width_and_prec(list, result);
	else if (list->flags.has_width && !list->flags.has_precision &&\
	list->flags.zero_pad)
		ret = print_hex_zero_padded(list, result);
	free(result);
	return (ret);
}
