/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uitoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 19:21:05 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/30 16:50:54 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_umallocsize(unsigned int n)
{
	int j;

	j = 0;
	if (n == 0)
		j++;
	while (n > 0)
	{
		n = n / 10;
		j++;
	}
	return (j);
}

static void	ft_uconversion(char *result, unsigned int n, unsigned int i)
{
	result[ft_umallocsize(n)] = '\0';
	i = ft_umallocsize(n) - 1;
	if (n < 0)
	{
		n = n * -1;
		result[0] = '-';
	}
	if (n == 0)
		result[0] = '0';
	while (n > 0)
	{
		result[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
}

char		*ft_uitoa(unsigned int n)
{
	int		i;
	char	*result;

	i = 0;
	result = malloc(sizeof(char) * ft_umallocsize(n) + 1);
	if (result == NULL)
		return (NULL);
	ft_uconversion(result, n, i);
	return (result);
}
