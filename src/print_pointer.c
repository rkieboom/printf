/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkieboom <rkieboom@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:31:55 by rkieboom          #+#    #+#             */
/*   Updated: 2025/08/06 15:53:46 by rkieboom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	print_pointer_simple(t_printf_context *list, char *result)
{
	if (ft_putstr(result) == -1)
		return (-1);
	list->char_count += ft_strlen(result);
	return (0);
}

int	print_pointer_with_width(t_printf_context *list, char *result)
{
	int	length;

	length = ft_strlen(result);
	if (list->flags.left_align)
		if (ft_putstr(result) == -1)
			return (-1);
	if (list->flags.width > length)
	{
		list->flags.width -= length;
		while (list->flags.width > 0)
		{
			if (ft_putchar(' ') == -1)
				return (-1);
			list->flags.width--;
			list->char_count++;
		}
	}
	list->char_count += ft_strlen(result);
	if (!list->flags.left_align)
		if (ft_putstr(result) == -1)
			return (-1);
	return (0);
}

int	print_pointer_with_precision(t_printf_context *list, unsigned long decimal)
{
	if (decimal == 0)
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		list->char_count += 2;
	}
	return (0);
}

int	checksizepnter(unsigned long decimal)
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

char	*convtopnter(t_printf_context *list, unsigned long decimal)
{
	char	*result;
	int		temp;
	int		i;

	i = checksizepnter(decimal);
	result = malloc(sizeof(char) * (2 + checksizepnter(decimal)));
	if (!result)
		return (NULL);
	result[i + 1] = '\0';
	while (decimal > 0)
	{
		temp = (decimal % 16);
		if (temp <= 9)
			result[i] = (temp) + '0';
		else if (temp >= 10 && temp <= 15 && list->specifier == SPEC_POINTER)
			result[i] = (temp + 87);
		decimal /= 16;
		i--;
	}
	return (result);
}