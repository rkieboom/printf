/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkieboom <rkieboom@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:11:27 by rkieboom          #+#    #+#             */
/*   Updated: 2025/08/06 15:54:38 by rkieboom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_putnbr(int number)
{
	if (number == -2147483648)
	{
		if (ft_putstr("-2147483648") == -1)
			return (-1);
		return (0);
	}
	if (number < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		number *= -1;
	}
	if ((number / 10) > 0)
		if (ft_putnbr(number / 10) == -1)
			return (-1);
	if (ft_putchar((number % 10) + 48) == -1)
		return (-1);
	return (0);
}

int	ft_putunbr(unsigned int number)
{
	if ((number / 10) > 0)
		if (ft_putunbr(number / 10) == -1)
			return (-1);
	if (ft_putchar((number % 10) + 48) == -1)
		return (-1);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*result;

	result = malloc((1 + ft_strlen(s1)) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	chkflagsnull(t_printf_context *flags)
{
	if (!flags->flags.left_align && !flags->flags.zero_pad\
	&& !flags->flags.has_precision && !flags->flags.has_width)
		return (1);
	return (0);
}
