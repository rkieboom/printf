/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printpnter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 14:31:55 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/30 14:56:55 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		printpnter(t_flags *list, char *result)
{
	if (ft_putstr(result) == -1)
		return (-1);
	list->chramount += ft_strlen(result);
	return (0);
}

int		pnt_widthprint(t_flags *list, char *result)
{
	int				length;

	length = ft_strlen(result);
	if (list->flags_minus == 1)
		if (ft_putstr(result) == -1)
			return (-1);
	if (list->flags_wval > length)
	{
		list->flags_wval -= length;
		while (list->flags_wval > 0)
		{
			if (ft_putchar(' ') == -1)
				return (-1);
			list->flags_wval--;
			list->chramount++;
		}
	}
	list->chramount += ft_strlen(result);
	if (list->flags_minus == 0)
		if (ft_putstr(result) == -1)
			return (-1);
	return (0);
}

int		pnt_precprint(t_flags *list, unsigned long decimal)
{
	if (decimal == 0)
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		list->chramount += 2;
	}
	return (0);
}

int		checksizepnter(unsigned long decimal)
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

char	*convtopnter(t_flags *list, unsigned long decimal)
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
		else if (temp >= 10 && temp <= 15 && list->type_pnter)
			result[i] = (temp + 87);
		decimal /= 16;
		i--;
	}
	return (result);
}
