/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 12:45:14 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/30 17:32:53 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	t_flags		*list;
	int			retval;

	retval = 0;
	list = malloc(sizeof(t_flags));
	if (list == NULL)
		return (-1);
	if (!str)
		return (0);
	va_start(list->ap, str);
	retval = readline(str, list);
	va_end(list->ap);
	if (retval != -1)
		retval = list->chramount;
	free(list);
	return (retval);
}

int		readline(const char *str, t_flags *list)
{
	int i;

	i = 0;
	list->chramount = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
		{
			if (ft_putchar(str[i]) == -1)
				return (-1);
			i++;
			list->chramount++;
		}
		if (str[i] == '\0')
			return (0);
		i++;
		setallflagstonull(list);
		str += checkflags(str + i, list);
		if (list->type_int == 1 || list->type_uhex == 1 || list->type_uhexcap\
		== 1 || list->type_uint == 1 || list->type_string == 1)
			fixflags(list);
		if (checkprint(list) == -1)
			return (-1);
	}
	return (0);
}

void	fixflags(t_flags *list)
{
	if (list->flags_minus == 1 && list->flags_zero == 1)
	{
		list->flags_zero = 0;
		list->flags_width = 1;
		if (list->flags_wval == 0)
			list->flags_wval = list->flags_zeroval;
	}
}

int		checkdatatype(const char *str, t_flags *flags, int *i)
{
	if (*str == 'c')
		flags->type_char = 1;
	else if (*str == 's')
		flags->type_string = 1;
	else if (*str == 'p')
		flags->type_pnter = 1;
	else if (*str == 'd' || *str == 'i')
		flags->type_int = 1;
	else if (*str == 'u')
		flags->type_uint = 1;
	else if (*str == 'x')
		flags->type_uhex = 1;
	else if (*str == 'X')
		flags->type_uhexcap = 1;
	else if (*str == '%')
		flags->type_procent = 1;
	else
		return (1);
	(*i)++;
	return (0);
}
