/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkieboom <rkieboom@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 07:01:40 by rkieboom          #+#    #+#             */
/*   Updated: 2025/08/06 16:02:27 by rkieboom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	print_hex_simple(t_printf_context *list, char *result)
{
	list->char_count += ft_strlen(result);
	if (ft_putstr(result) == -1)
		return (-1);
	return (0);
}

int	print_hex_with_width(t_printf_context *list, char *result)
{
	int	length;

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

int	print_hex_with_precision(t_printf_context *list, char *result)
{
	int	length;

	length = ft_strlen(result);
	if (result[0] == '0' && result[1] == '\0' && list->flags.precision == 0)
		result[0] = '\0';
	list->char_count += ft_strlen(result);
	while ((list->flags.precision - length) > 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		list->char_count++;
		list->flags.precision--;
	}
	if (ft_putstr(result) == -1)
		return (-1);
	return (0);
}

static int	print_hex_zero_helper(t_printf_context *list, char *result, int length)
{
	while ((list->flags.width - length) > 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		list->char_count++;
		list->flags.width--;
	}
	if (!list->flags.left_align)
		if (ft_putstr(result) == -1)
			return (-1);
	return (0);
}

int	print_hex_zero_padded(t_printf_context *list, char *result)
{
	int	length;

	length = ft_strlen(result);
	list->char_count += ft_strlen(result);
	if (list->flags.left_align)
	{
		if (ft_putstr(result) == -1)
			return (-1);
	}
	if (print_hex_zero_helper(list, result, length) == -1)
		return (-1);
	return (0);
}

static int	print_hex_width_prec_helper(t_printf_context *list, char *result, int length)
{
	int precval;

	precval = list->flags.precision;
	while ((list->flags.precision - length) > 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		list->char_count++;
		list->flags.precision--;
	}
	if (list->flags.left_align)
		if (ft_putstr(result) == -1)
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
		if (ft_putstr(result) == -1)
			return (-1);
	return (0);
}

int	print_hex_width_and_prec(t_printf_context *list, char *result)
{
	int	length;

	if (result[0] == '0' && result[1] == '\0' && list->flags.precision == 0)
		result[0] = '\0';
	list->char_count += ft_strlen(result);
	length = ft_strlen(result);
	while ((list->flags.width - checkbignum(0, list->flags.precision, length)) > 0 && !list->flags.left_align)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->char_count++;
		list->flags.width--;
	}
	if (print_hex_width_prec_helper(list, result, length) == -1)
		return (-1);
	return (0);
}

static int	print_hex_zero_prec_helper(t_printf_context *list, char *result, int length)
{
	int precval;

	precval = list->flags.precision;
	while ((list->flags.precision - length) > 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		list->char_count++;
		list->flags.precision--;
	}
	if (list->flags.left_align)
		if (ft_putstr(result) == -1)
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
		if (ft_putstr(result) == -1)
			return (-1);
	return (0);
}

int	print_hex_zero_and_prec(t_printf_context *list, char *result)
{
	int	length;

	length = ft_strlen(result);
	if (*result == '0' && length == 1)
	{
		*result = '\0';
		length--;
	}
	list->char_count += length;
	while ((list->flags.width - checkbignum(0, list->flags.precision, length)) > 0 && !list->flags.left_align)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->char_count++;
		list->flags.width--;
	}
	if (print_hex_zero_prec_helper(list, result, length) == -1)
		return (-1);
	return (0);
}

char	*convtohex(t_printf_context *list, unsigned int decimal)
{
	char			*result;
	unsigned int	temp;
	int				i;

	if (decimal == 0)
		return (ft_strdup("0"));
	i = checksizehex(decimal) - 2;
	result = malloc(sizeof(char) * checksizehex(decimal));
	result[i + 1] = '\0';
	if (!result)
		return (NULL);
	while (decimal > 0)
	{
		temp = (decimal % 16);
		if (temp <= 9)
			result[i] = (temp) + '0';
		else if (temp >= 10 && temp <= 15 && list->specifier == SPEC_HEX_LOWER)
			result[i] = (temp + 87);
		else if (temp >= 10 && temp <= 15 && list->specifier == SPEC_HEX_UPPER)
			result[i] = (temp + 55);
		decimal /= 16;
		i--;
	}
	return (result);
}

int	checksizehex(unsigned int decimal)
{
	int	i;

	i = 0;
	while (decimal > 0)
	{
		decimal /= 16;
		i++;
	}
	return (i + 1);
}