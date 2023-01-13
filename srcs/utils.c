/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 12:47:04 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/30 16:50:57 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_atoi(const char *str)
{
	int			i;
	long long	result;
	long long	posorneg;

	result = 0;
	posorneg = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			posorneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result * 10 + (str[i] - '0')) < result)
			return (((posorneg * -1) - 1) / 2);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return ((int)(result * posorneg));
}

int		ft_putchar(char c)
{
	int ret;

	ret = write(1, &c, 1);
	if (ret == -1)
		return (-1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_putstr(const char *str)
{
	int ret;

	ret = write(1, str, ft_strlen(str));
	if (ret == -1)
		return (-1);
	return (0);
}

int		ft_putstrlen(const char *str, int len)
{
	int ret;

	ret = write(1, str, len);
	if (ret == -1)
		return (-1);
	return (0);
}
