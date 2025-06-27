/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printhex2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 15:35:53 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/30 16:12:36 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hex_printzeroprec(t_flags *list, char *result, int i)
{
	int		length;

	length = ft_strlen(result);
	if (*result == '0' && length == 1)
	{
		*result = '\0';
		length--;
	}
	list->chramount += length;
	if (*result == '-')
		list->flags_precval++;
	while ((list->flags_zeroval - checkbignum(0, list->flags_precval, length))\
	> 0 && list->flags_minus == 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->chramount++;
		list->flags_zeroval--;
	}
	if (hex_printzeroprec2(list, result, i, length) == -1)
		return (-1);
	return (0);
}

int		hex_printzeroprec2(t_flags *list, char *result, int i, int length)
{
	int precval;

	precval = list->flags_precval;
	if (*result == '-')
	{
		if (ft_putchar('-') == -1)
			return (-1);
		i = 1;
	}
	while ((list->flags_precval - length) > 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		list->chramount++;
		list->flags_precval--;
	}
	if (list->flags_minus == 1)
		if (ft_putstr(result + i) == -1)
			return (-1);
	if (hex_printzeroprec3(list, result, precval, i) == -1)
		return (-1);
	return (0);
}

int		hex_printzeroprec3(t_flags *list, char *result, int precval, int i)
{
	int length;

	length = ft_strlen(result);
	while (list->flags_zeroval - checkbignum(0, precval, length)\
	> 0 && list->flags_minus == 1)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->chramount++;
		list->flags_zeroval--;
	}
	if (list->flags_minus == 0)
		if (ft_putstr(result + i) == -1)
			return (-1);
	return (0);
}

char	*convtohex(t_flags *list, unsigned int decimal)
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
		else if (temp >= 10 && temp <= 15 && list->type_uhex)
			result[i] = (temp + 87);
		else if (temp >= 10 && temp <= 15 && list->type_uhexcap)
			result[i] = (temp + 55);
		decimal /= 16;
		i--;
	}
	return (result);
}

int		checksizehex(unsigned int decimal)
{
	int i;

	i = 0;
	while (decimal > 0)
	{
		decimal /= 16;
		i++;
	}
	return (i + 1);
}
