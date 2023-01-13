/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printprocent.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 17:42:44 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/27 18:46:18 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		p_print(t_flags *list)
{
	list->chramount++;
	if (list->type_procent == 1)
	{
		if (ft_putchar('%') == -1)
			return (-1);
	}
	else
		list->chramount--;
	return (0);
}

int		p_printwidth(t_flags *list)
{
	list->chramount += list->flags_wval;
	while ((list->flags_wval - 1) > 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->flags_wval--;
	}
	if (list->type_procent == 1)
	{
		if (ft_putchar('%') == -1)
			return (-1);
	}
	else
		list->chramount--;
	return (0);
}

int		p_printminwidth(t_flags *list)
{
	if (list->type_procent == 1)
	{
		if (ft_putchar('%') == -1)
			return (-1);
	}
	else
		list->chramount--;
	list->chramount += list->flags_wval;
	while ((list->flags_wval - 1) > 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->flags_wval--;
	}
	return (0);
}

int		p_printnull(t_flags *list)
{
	list->chramount += list->flags_zeroval;
	while ((list->flags_zeroval - 1) > 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		list->flags_zeroval--;
	}
	if (list->type_procent == 1)
	{
		if (ft_putchar('%') == -1)
			return (-1);
	}
	else
		list->chramount--;
	return (0);
}

int		p_printminnull(t_flags *list)
{
	if (list->type_procent == 1)
	{
		if (ft_putchar('%') == -1)
			return (-1);
	}
	else
		list->chramount--;
	list->chramount += list->flags_zeroval;
	while ((list->flags_zeroval - 1) > 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		list->flags_zeroval--;
	}
	return (0);
}
