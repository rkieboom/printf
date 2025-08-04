/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkieboom <rkieboom@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:58:52 by rkieboom          #+#    #+#             */
/*   Updated: 2025/08/06 14:45:58 by rkieboom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	checkflags(const char *str, t_printf_context *flags)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (checkdatatype(str, flags, &i))
	{
		markflag(str, flags, &j);
		i += j;
		str += j;
		j = 0;
	}
	return (i);
}

void	handle_negative_width(t_printf_context *list)
{
	list->flags.width *= -1;
	list->flags.left_align = true;
	list->flags.zero_pad = false;
	list->flags.has_width = true;
}

void	markflag(const char *str, t_printf_context *list, int *i)
{
	if (*str == '-')
	{
		list->flags.left_align = true;
		(*i)++;
	}
	else if (*str == '0')
	{
		list->flags.zero_pad = true;
		if (*(str + 1) == '*')
		{
			list->flags.width = va_arg(list->args, int);
			if (list->flags.width < 0)
				handle_negative_width(list);
			(*i) += 2;
			return ;
		}
		(*i) += skipnull(str);
		list->flags.width = ft_atoi(str);
		if (list->flags.width >= 0)
		{
			list->flags.has_width = true;
			(*i) += checksizeprec(list->flags.width);
		}
	}
	else
		markflag2(str, list, i);
}

void	markflag2(const char *str, t_printf_context *list, int *i)
{
	if (*str == '.')
	{
		list->flags.has_precision = true;
		(*i)++;
		str++;
		if (*str == '*')
		{
			list->flags.precision = va_arg(list->args, int);
			if (list->flags.precision < 0)
				list->flags.has_precision = false;
			(*i)++;
			return ;
		}
		(*i) += skipnull(str);
		list->flags.precision = ft_atoi(str);
		if (list->flags.precision > 0)
			(*i) += checksizeprec(list->flags.precision);
	}
	else
		markflag3(str, list, i);
}

void	markflag3(const char *str, t_printf_context *list, int *i)
{
	list->flags.width = ft_atoi(str);
	if (*str == '*')
	{
		list->flags.has_width = true;
		list->flags.width = va_arg(list->args, int);
		if (list->flags.width < 0)
		{
			list->flags.left_align = true;
			list->flags.width *= -1;
		}
		(*i)++;
	}
	else if ((list->flags.width > 0) || ft_isdigit(*str))
	{
		if (*str == '0')
			(*i) += skipnull(str);
		list->flags.has_width = true;
		(*i) += checksize(list->flags.width);
	}
}
