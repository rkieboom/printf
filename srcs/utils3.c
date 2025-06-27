/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 16:23:21 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/30 16:51:32 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		skipnull(const char *str)
{
	int i;

	i = 0;
	while (str[i] == '0' && str[i] != '\0')
		i++;
	return (i);
}

void	setallflagstonull(t_flags *flags)
{
	flags->type_procent = 0;
	flags->type_int = 0;
	flags->type_uint = 0;
	flags->type_string = 0;
	flags->type_char = 0;
	flags->type_pnter = 0;
	flags->type_uhex = 0;
	flags->type_uhexcap = 0;
	flags->flags_minus = 0;
	flags->flags_zero = 0;
	flags->flags_zeroval = 0;
	flags->flags_precision = 0;
	flags->flags_precval = 0;
	flags->flags_width = 0;
	flags->flags_wval = 0;
}

int		checkbignum(int a, int b, int c)
{
	int result;

	result = a;
	if (b > result)
		result = b;
	if (c > result)
		result = c;
	return (result);
}

int		checksize(int number)
{
	int result;

	result = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		result++;
		number *= -1;
	}
	while (number > 0)
	{
		number /= 10;
		result++;
	}
	return (result);
}

int		checksizeprec(int number)
{
	int result;

	result = 0;
	if (number == 0)
		return (0);
	if (number == -2147483648)
		return (11);
	if (number < 0)
		number *= -1;
	while (number > 0)
	{
		number /= 10;
		result++;
	}
	return (result);
}
