/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkieboom <rkieboom@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 05:32:23 by rkieboom          #+#    #+#             */
/*   Updated: 2025/08/06 15:53:59 by rkieboom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	print_string_simple(t_printf_context *list)
{
	char	*result;

	result = va_arg(list->args, char*);
	if (!result)
	{
		if (ft_putstr("(null)") == -1)
			return (-1);
		list->char_count += 6;
		return (0);
	}
	list->char_count += ft_strlen(result);
	if (ft_putstr(result) == -1)
		return (-1);
	return (0);
}

static int	print_string_precision_helper(t_printf_context *list, char *result, int length)
{
	if (list->flags.precision < length)
	{
		length = list->flags.precision;
		if (ft_putstrlen(result, length) == -1)
			return (-1);
	}
	else
	{
		length = ft_strlen(result);
		if (ft_putstr(result) == -1)
			return (-1);
	}
	list->char_count += length;
	return (0);
}

int	print_string_with_precision(t_printf_context *list)
{
	int		length;
	char	*result;

	result = va_arg(list->args, char*);
	if (!result)
	{
		if (list->flags.precision <= 6)
		{
			length = list->flags.precision;
			if (ft_putstrlen("(null)", length) == -1)
				return (-1);
		}
		else
		{
			if (ft_putstr("(null)") == -1)
				return (-1);
			length = 6;
		}
		list->char_count += length;
		return (0);
	}
	if (print_string_precision_helper(list, result, ft_strlen(result)) == -1)
		return (-1);
	return (0);
}

static int	print_string_width_helper(t_printf_context *list, char *result, int length)
{
	list->char_count += list->flags.width;
	list->flags.width -= length;
	while (list->flags.width > 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->flags.width--;
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

int	print_string_with_width(t_printf_context *list)
{
	char	*result;
	int		length;

	result = va_arg(list->args, char*);
	length = (!result) ? 6 : ft_strlen(result);
	if (length > list->flags.width)
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
		list->char_count += length;
		return (0);
	}
	if (print_string_width_helper(list, result, length) == -1)
		return (-1);
	return (0);
}

static int	print_string_left_width_helper(t_printf_context *list, char *result, int length)
{
	if (result)
		if (ft_putstr(result) == -1)
			return (-1);
	list->flags.width -= length;
	list->char_count += length;
	while (list->flags.width > 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->flags.width--;
		list->char_count++;
	}
	return (0);
}

int	print_string_left_aligned(t_printf_context *list)
{
	char	*result;
	int		length;

	result = va_arg(list->args, char*);
	if (!result)
	{
		if (ft_putstr("(null)") == -1)
			return (-1);
		length = 6;
	}
	else if ((int)ft_strlen(result) > list->flags.width)
	{
		length = ft_strlen(result);
		if (ft_putstr(result) == -1)
			return (-1);
		list->char_count += length;
		return (0);
	}
	else
		length = ft_strlen(result);
	if (print_string_left_width_helper(list, result, length) == -1)
		return (-1);
	return (0);
}

static int	print_string_width_prec_helper(t_printf_context *list, char *result, int length)
{
	if (list->flags.precision < (int)ft_strlen(result))
		length = list->flags.precision;
	else
		length = ft_strlen(result);
	if (list->flags.width <= length)
	{
		if (ft_putstrlen(result, length) == -1)
			return (-1);
	}
	else
	{
		list->flags.width -= length;
		list->char_count += list->flags.width;
		while (list->flags.width > 0)
		{
			if (ft_putchar(' ') == -1)
				return (-1);
			list->flags.width--;
		}
		if (ft_putstrlen(result, length) == -1)
			return (-1);
	}
	list->char_count += length;
	return (0);
}

int	print_string_width_and_prec(t_printf_context *list)
{
	char	*result;
	int		length;

	length = 0;
	result = va_arg(list->args, char*);
	if (!result)
	{
		length = (list->flags.precision < 6) ? list->flags.precision : 6;
		if (list->flags.width >= length)
			list->char_count += list->flags.width;
		else
			list->char_count += length;
		list->flags.width -= length;
		while (list->flags.width > 0)
		{
			if (ft_putchar(' ') == -1)
				return (-1);
			list->flags.width--;
		}
		if (ft_putstrlen("(null)", length) == -1)
			return (-1);
	}
	else if (print_string_width_prec_helper(list, result, length) == -1)
		return (-1);
	return (0);
}

static int	print_string_left_width_prec_helper(t_printf_context *list, char *result, int length)
{
	if (list->flags.precision < (int)ft_strlen(result))
		length = list->flags.precision;
	else
		length = ft_strlen(result);
	if (list->flags.width <= length)
	{
		if (ft_putstrlen(result, length) == -1)
			return (-1);
	}
	else
	{
		list->flags.width -= length;
		list->char_count += list->flags.width;
		if (ft_putstrlen(result, length) == -1)
			return (-1);
		while (list->flags.width > 0)
		{
			if (ft_putchar(' ') == -1)
				return (-1);
			list->flags.width--;
		}
	}
	list->char_count += length;
	return (0);
}

int	print_string_left_width_prec(t_printf_context *list)
{
	char	*result;
	int		length;

	length = 0;
	result = va_arg(list->args, char*);
	if (!result)
	{
		length = (list->flags.precision < 6) ? list->flags.precision : 6;
		if (list->flags.width >= length)
			list->char_count += list->flags.width;
		else
			list->char_count += length;
		list->flags.width -= length;
		if (ft_putstrlen("(null)", length) == -1)
			return (-1);
		while (list->flags.width > 0)
		{
			if (ft_putchar(' ') == -1)
				return (-1);
			list->flags.width--;
		}
	}
	else if (print_string_left_width_prec_helper(list, result, length) == -1)
		return (-1);
	return (0);
}