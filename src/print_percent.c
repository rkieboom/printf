/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkieboom <rkieboom@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:42:44 by rkieboom          #+#    #+#             */
/*   Updated: 2025/08/06 16:02:22 by rkieboom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	print_percent_simple(t_printf_context *list)
{
	list->char_count++;
	if (list->specifier == SPEC_PERCENT)
	{
		if (ft_putchar('%') == -1)
			return (-1);
	}
	else
		list->char_count--;
	return (0);
}

int	print_percent_with_width(t_printf_context *list)
{
	list->char_count += list->flags.width;
	while ((list->flags.width - 1) > 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->flags.width--;
	}
	if (list->specifier == SPEC_PERCENT)
	{
		if (ft_putchar('%') == -1)
			return (-1);
	}
	else
		list->char_count--;
	return (0);
}

int	print_percent_left_aligned(t_printf_context *list)
{
	if (list->specifier == SPEC_PERCENT)
	{
		if (ft_putchar('%') == -1)
			return (-1);
	}
	else
		list->char_count--;
	list->char_count += list->flags.width;
	while ((list->flags.width - 1) > 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->flags.width--;
	}
	return (0);
}

int	print_percent_zero_padded(t_printf_context *list)
{
	list->char_count += list->flags.width;
	while ((list->flags.width - 1) > 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		list->flags.width--;
	}
	if (list->specifier == SPEC_PERCENT)
	{
		if (ft_putchar('%') == -1)
			return (-1);
	}
	else
		list->char_count--;
	return (0);
}

int	print_percent_left_zero(t_printf_context *list)
{
	if (list->specifier == SPEC_PERCENT)
	{
		if (ft_putchar('%') == -1)
			return (-1);
	}
	else
		list->char_count--;
	list->char_count += list->flags.width;
	while ((list->flags.width - 1) > 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->flags.width--;
	}
	return (0);
}