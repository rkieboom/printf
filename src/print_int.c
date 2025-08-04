/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkieboom <rkieboom@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:13:11 by rkieboom          #+#    #+#             */
/*   Updated: 2025/08/06 16:02:24 by rkieboom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	print_int_simple(t_printf_context *list, char *result)
{
	list->char_count += (int)ft_strlen(result);
	if (ft_putstr(result) == -1)
		return (-1);
	return (0);
}

int	print_int_with_width(t_printf_context *list, char *result)
{
	int		length;

	length = ft_strlen(result);
	list->char_count += ft_strlen(result);
	if (list->flags.left_align)
		if (ft_putstr(result) == -1)
			return (-1);
	while ((list->flags.width - length) > 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->char_count++;
		list->flags.width--;
	}
	if (!list->flags.left_align)
		if (ft_putstr(result) == -1)
			return (-1);
	return (0);
}

static int	print_int_precision_helper(t_printf_context *list, char *result, int length, int i)
{
	while ((list->flags.precision - length) > 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		list->char_count++;
		list->flags.precision--;
	}
	if (ft_putstr(result + i) == -1)
		return (-1);
	return (0);
}

int	print_int_with_precision(t_printf_context *list, char *result)
{
	int	length;
	int	i;

	i = 0;
	length = ft_strlen(result);
	if (result[0] == '0' && result[1] == '\0' && list->flags.precision == 0)
		result[0] = '\0';
	list->char_count += ft_strlen(result);
	if (*result == '-')
	{
		if (*result == '-')
		{
			if (ft_putchar('-') == -1)
				return (-1);
			list->flags.precision++;
			i = 1;
		}
	}
	if (print_int_precision_helper(list, result, length, i) == -1)
		return (-1);
	return (0);
}

static int	print_int_zero_helper(t_printf_context *list, char *result, int length, int i)
{
	while ((list->flags.width - length) > 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		list->char_count++;
		list->flags.width--;
	}
	if (!list->flags.left_align)
		if (ft_putstr(result + i) == -1)
			return (-1);
	return (0);
}

int	print_int_zero_padded(t_printf_context *list, char *result)
{
	int	length;
	int	i;

	i = 0;
	length = ft_strlen(result);
	list->char_count += ft_strlen(result);
	if (list->flags.left_align)
	{
		if (ft_putstr(result) == -1)
			return (-1);
	}
	else if (*result == '-')
	{
		if (ft_putchar('-') == -1)
			return (-1);
		list->flags.precision++;
		i = 1;
	}
	if (print_int_zero_helper(list, result, length, i) == -1)
		return (-1);
	return (0);
}

static int	print_int_width_prec_helper(t_printf_context *list, char *result, int length, int i)
{
	int precval;

	precval = list->flags.precision;
	if (*result == '-')
	{
		if (ft_putchar('-') == -1)
			return (-1);
		i = 1;
	}
	while ((list->flags.precision - length) > 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		list->char_count++;
		list->flags.precision--;
	}
	if (list->flags.left_align)
		if (ft_putstr(result + i) == -1)
			return (-1);
	length = ft_strlen(result);
	while (list->flags.width - checkbignum(0, precval, length) > 0 && list->flags.left_align)
	{
		ft_putchar(' ');
		list->char_count++;
		list->flags.width--;
	}
	if (!list->flags.left_align)
		if (ft_putstr(result + i) == -1)
			return (-1);
	return (0);
}

int	print_int_width_and_prec(t_printf_context *list, char *result)
{
	int	length;
	int	i;

	i = 0;
	if (result[0] == '0' && result[1] == '\0' && list->flags.precision == 0)
		result[0] = '\0';
	list->char_count += ft_strlen(result);
	length = ft_strlen(result);
	if (*result == '-')
		list->flags.precision++;
	while ((list->flags.width - checkbignum(0, list->flags.precision, length)) > 0 && !list->flags.left_align)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->char_count++;
		list->flags.width--;
	}
	if (print_int_width_prec_helper(list, result, length, i) == -1)
		return (-1);
	return (0);
}

static int	print_int_zero_prec_helper(t_printf_context *list, char *result, int length, int i)
{
	int precval;

	precval = list->flags.precision;
	if (*result == '-')
	{
		if (ft_putchar('-') == -1)
			return (-1);
		i = 1;
	}
	while ((list->flags.precision - length) > 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		list->char_count++;
		list->flags.precision--;
	}
	if (list->flags.left_align)
		if (ft_putstr(result + i) == -1)
			return (-1);
	length = ft_strlen(result);
	while (list->flags.width - checkbignum(0, precval, length) > 0 && list->flags.left_align)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->char_count++;
		list->flags.width--;
	}
	if (!list->flags.left_align)
		if (ft_putstr(result + i) == -1)
			return (-1);
	return (0);
}

int	print_int_zero_and_prec(t_printf_context *list, char *result, int i)
{
	int		length;

	length = ft_strlen(result);
	if (*result == '0' && length == 1)
	{
		*result = '\0';
		length--;
	}
	list->char_count += length;
	if (*result == '-')
		list->flags.precision++;
	while ((list->flags.width - checkbignum(0, list->flags.precision, length)) > 0 && !list->flags.left_align)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->char_count++;
		list->flags.width--;
	}
	if (print_int_zero_prec_helper(list, result, length, i) == -1)
		return (-1);
	return (0);
}