/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkieboom <rkieboom@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:45:14 by rkieboom          #+#    #+#             */
/*   Updated: 2025/08/06 15:53:06 by rkieboom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_printf(const char *str, ...)
{
	t_printf_context	*list;
	int					retval;

	retval = 0;
	list = malloc(sizeof(t_printf_context));
	if (list == NULL)
		return (-1);
	if (!str)
		return (0);
	va_start(list->args, str);
	retval = readline(str, list);
	va_end(list->args);
	if (retval != -1)
		retval = list->char_count;
	free(list);
	return (retval);
}

int	readline(const char *str, t_printf_context *list)
{
	int	i;

	i = 0;
	list->char_count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
		{
			if (ft_putchar(str[i]) == -1)
				return (-1);
			i++;
			list->char_count++;
		}
		if (str[i] == '\0')
			return (0);
		i++;
		setallflagstonull(list);
		str += checkflags(str + i, list);
		if (list->specifier == SPEC_INT || list->specifier == SPEC_HEX_LOWER || list->specifier == SPEC_HEX_UPPER\
		|| list->specifier == SPEC_UINT || list->specifier == SPEC_STRING)
			resolve_conflicting_flags(list);
		if (checkprint(list) == -1)
			return (-1);
	}
	return (0);
}

void	resolve_conflicting_flags(t_printf_context *list)
{
	if (list->flags.left_align && list->flags.zero_pad)
	{
		list->flags.zero_pad = false;
	}
}

int	checkdatatype(const char *str, t_printf_context *flags, int *i)
{
	if (*str == 'c')
		flags->specifier = SPEC_CHAR;
	else if (*str == 's')
		flags->specifier = SPEC_STRING;
	else if (*str == 'p')
		flags->specifier = SPEC_POINTER;
	else if (*str == 'd' || *str == 'i')
		flags->specifier = SPEC_INT;
	else if (*str == 'u')
		flags->specifier = SPEC_UINT;
	else if (*str == 'x')
		flags->specifier = SPEC_HEX_LOWER;
	else if (*str == 'X')
		flags->specifier = SPEC_HEX_UPPER;
	else if (*str == '%')
		flags->specifier = SPEC_PERCENT;
	else
		return (1);
	(*i)++;
	return (0);
}
