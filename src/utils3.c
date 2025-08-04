/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkieboom <rkieboom@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:23:21 by rkieboom          #+#    #+#             */
/*   Updated: 2025/08/06 16:02:13 by rkieboom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	skipnull(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0' && str[i] != '\0')
		i++;
	return (i);
}

void	setallflagstonull(t_printf_context *flags)
{
	flags->specifier = SPEC_NONE;
	flags->flags.left_align = false;
	flags->flags.zero_pad = false;
	flags->flags.has_precision = false;
	flags->flags.has_width = false;
	flags->flags.precision = 0;
	flags->flags.width = 0;
}

int	checkbignum(int a, int b, int c)
{
	int	result;

	result = a;
	if (b > result)
		result = b;
	if (c > result)
		result = c;
	return (result);
}

int	checksize(int number)
{
	int	result;

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

int	checksizeprec(int number)
{
	int	result;

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
