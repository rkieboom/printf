/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkieboom <rkieboom@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:02:47 by rkieboom          #+#    #+#             */
/*   Updated: 2025/08/06 16:02:43 by rkieboom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include "ft_printf.h"
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef enum s_specifier
{
	SPEC_CHAR,			/* %c */
	SPEC_STRING,		/* %s */
	SPEC_INT,			/* %d, %i */
	SPEC_UINT,			/* %u */
	SPEC_HEX_LOWER,		/* %x */
	SPEC_HEX_UPPER,		/* %X */
	SPEC_POINTER,		/* %p */
	SPEC_PERCENT,		/* %% */
	SPEC_NONE
}	t_specifier;

typedef struct s_format_flags
{
	bool	left_align;		/* - flag: left-justify output */
	bool	zero_pad;		/* 0 flag: pad with zeros instead of spaces */
	bool	has_precision;	/* . flag: precision was specified */
	bool	has_width;		/* width was specified */
	int		precision;		/* precision value */
	int		width;			/* width value */
}	t_format_flags;

typedef struct s_printf_context
{
	const char		*format_str;	/* pointer to format string */
	va_list			args;			/* variadic arguments */
	t_specifier		specifier;		/* current format specifier type */
	t_format_flags	flags;			/* format flags and modifiers */
	int				char_count;		/* total characters printed */
}	t_printf_context;

/* Core printf functions */
int				readline(const char *str, t_printf_context *list);
void			resolve_conflicting_flags(t_printf_context *list);
void			handle_negative_width(t_printf_context *list);
int				checkdatatype(const char *str, t_printf_context *flags, int *i);

/* Flag parsing functions */
int				checkflags(const char *str, t_printf_context *flags);
void			markflag(const char *str, t_printf_context *list, int *i);
void			markflag2(const char *str, t_printf_context *list, int *i);
void			markflag3(const char *str, t_printf_context *list, int *i);

/* Print dispatcher functions */
int				checkprint(t_printf_context *list);
int				checkprintprocent(t_printf_context *list);
int				checkprintint(t_printf_context *list, int ret);
int				checkprinthex(t_printf_context *list, int ret);
int				checkprintpnter(t_printf_context *list, int ret);
int				checkprintunsignedint(t_printf_context *list, int ret);
int				checkprintstring(t_printf_context *list);
int				checkprintchar(t_printf_context *list);

/* Utility functions */
int				ft_putstrlen(const char *str, int len);
void			setallflagstonull(t_printf_context *flags);
int				checkbignum(int a, int b, int c);
int				ft_putunbr(unsigned int number);
int				chkflagsnull(t_printf_context *flags);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *str);
int				ft_putstr(const char *str);
int				skipnull(const char *str);
int				checksizeprec(int number);
int				ft_atoi(const char *str);
int				ft_putnbr(int number);
int				checksize(int number);
int				ft_putchar(char c);
int				ft_isdigit(int c);
char			*ft_uitoa(unsigned int n);
char			*ft_itoa(int n);

/* Character printing functions */
int				print_char_simple(t_printf_context *list);
int				print_char_with_width(t_printf_context *list);
int				print_char_left_aligned(t_printf_context *list);

/* String printing functions */
int				print_string_simple(t_printf_context *list);
int				print_string_with_precision(t_printf_context *list);
int				print_string_with_width(t_printf_context *list);
int				print_string_left_aligned(t_printf_context *list);
int				print_string_width_and_prec(t_printf_context *list);
int				print_string_left_width_prec(t_printf_context *list);

/* Integer printing functions */
int				print_int_simple(t_printf_context *list, char *result);
int				print_int_with_width(t_printf_context *list, char *result);
int				print_int_with_precision(t_printf_context *list, char *result);
int				print_int_zero_padded(t_printf_context *list, char *result);
int				print_int_width_and_prec(t_printf_context *list, char *result);
int				print_int_zero_and_prec(t_printf_context *list, char *result, int i);

/* Unsigned integer printing functions */
int				print_uint_simple(t_printf_context *list, char *result);
int				print_uint_with_width(t_printf_context *list, char *result);
int				print_uint_with_precision(t_printf_context *list, char *result);
int				print_uint_zero_padded(t_printf_context *list, char *result);
int				print_uint_width_and_prec(t_printf_context *list, char *result);
int				print_uint_zero_and_prec(t_printf_context *list, char *result);

/* Hexadecimal printing functions */
int				print_hex_simple(t_printf_context *list, char *result);
int				print_hex_with_width(t_printf_context *list, char *result);
int				print_hex_with_precision(t_printf_context *list, char *result);
int				print_hex_zero_padded(t_printf_context *list, char *result);
int				print_hex_width_and_prec(t_printf_context *list, char *result);
int				print_hex_zero_and_prec(t_printf_context *list, char *result);
char			*convtohex(t_printf_context *list, unsigned int decimal);
int				checksizehex(unsigned int decimal);

/* Pointer printing functions */
int				print_pointer_simple(t_printf_context *list, char *result);
int				print_pointer_with_width(t_printf_context *list, char *result);
int				print_pointer_with_precision(t_printf_context *list, unsigned long decimal);
int				checksizepnter(unsigned long decimal);
char			*convtopnter(t_printf_context *list, unsigned long decimal);

/* Percent printing functions */
int				print_percent_simple(t_printf_context *list);
int				print_percent_with_width(t_printf_context *list);
int				print_percent_left_aligned(t_printf_context *list);
int				print_percent_zero_padded(t_printf_context *list);
int				print_percent_left_zero(t_printf_context *list);

#endif