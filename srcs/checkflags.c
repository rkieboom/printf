/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkflags.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 11:58:52 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/30 17:41:05 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		checkflags(const char *str, t_flags *flags)
{
	int i;
	int j;

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

void	zeroflagstarfix(t_flags *list)
{
	list->flags_zeroval *= -1;
	list->flags_minus = 1;
	list->flags_wval = list->flags_zeroval;
	list->flags_zero = 0;
	list->flags_width = 1;
}

void	markflag(const char *str, t_flags *list, int *i)
{
	if (*str == '-')
	{
		list->flags_minus = 1;
		(*i)++;
	}
	else if (*str == '0')
	{
		list->flags_zero = 1;
		if (*(str + 1) == '*')
		{
			list->flags_zeroval = va_arg(list->ap, int);
			if (list->flags_zeroval < 0)
				zeroflagstarfix(list);
			(*i) += 2;
			return ;
		}
		(*i) += skipnull(str);
		list->flags_zeroval = ft_atoi(str);
		if (list->flags_zeroval >= 0)
			(*i) += checksizeprec(list->flags_zeroval);
	}
	else
		markflag2(str, list, i);
}

void	markflag2(const char *str, t_flags *list, int *i)
{
	if (*str == '.')
	{
		list->flags_precision = 1;
		(*i)++;
		str++;
		if (*str == '*')
		{
			list->flags_precval = va_arg(list->ap, int);
			if (list->flags_precval < 0)
				list->flags_precision = 0;
			(*i)++;
			return ;
		}
		(*i) += skipnull(str);
		list->flags_precval = ft_atoi(str);
		if (list->flags_precval > 0)
			(*i) += checksizeprec(list->flags_precval);
	}
	else
		markflag3(str, list, i);
}

void	markflag3(const char *str, t_flags *list, int *i)
{
	list->flags_wval = ft_atoi(str);
	if (*str == '*')
	{
		list->flags_width = 1;
		list->flags_wval = va_arg(list->ap, int);
		if (list->flags_wval < 0)
		{
			list->flags_minus = 1;
			list->flags_wval *= -1;
		}
		(*i)++;
	}
	else if ((list->flags_wval > 0) || ft_isdigit(*str))
	{
		if (*str == '0')
			(*i) += skipnull(str);
		list->flags_width = 1;
		(*i) += checksize(list->flags_wval);
	}
}
