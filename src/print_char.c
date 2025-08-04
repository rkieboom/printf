/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkieboom <rkieboom@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 05:35:35 by rkieboom          #+#    #+#             */
/*   Updated: 2025/08/06 16:02:29 by rkieboom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	print_char_simple(t_printf_context *list)
{
	char	result;

	result = va_arg(list->args, int);
	list->char_count++;
	if (ft_putchar(result) == -1)
		return (-1);
	return (0);
}

int	print_char_with_width(t_printf_context *list)
{
	char	result;

	result = va_arg(list->args, int);
	while ((list->flags.width - 1) > 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->flags.width--;
		list->char_count++;
	}
	if (ft_putchar(result) == -1)
		return (-1);
	list->char_count++;
	return (0);
}

int	print_char_left_aligned(t_printf_context *list)
{
	char	result;

	result = va_arg(list->args, int);
	if (ft_putchar(result) == -1)
		return (-1);
	list->char_count++;
	while ((list->flags.width - 1) > 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->flags.width--;
		list->char_count++;
	}
	return (0);
}