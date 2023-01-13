/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 14:02:47 by rkieboom       #+#    #+#                */
/*   Updated: 2020/01/31 18:32:40 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flags
{
	const char	*str;

	va_list		ap;

	int			type_int;
	int			type_uint;
	int			type_string;
	int			type_char;
	int			type_pnter;
	int			type_uhex;
	int			type_uhexcap;

	int			chramount;
	int			type_procent;

	int			flags_minus;

	int			flags_zero;
	int			flags_zeroval;

	int			flags_precision;
	int			flags_precval;

	int			flags_width;
	int			flags_wval;

}				t_flags;

int				ft_printf(const char *str, ...);
int				readline(const char *str, t_flags *list);
void			fixflags(t_flags *list);
void			zeroflagstarfix(t_flags *list);
int				checkdatatype(const char *str, t_flags *flags, int *i);

int				checkflags(const char *str, t_flags *flags);
void			markflag(const char *str, t_flags *list, int *i);
void			markflag2(const char *str, t_flags *list, int *i);
void			markflag3(const char *str, t_flags *list, int *i);

int				checkprint(t_flags *list);
int				checkprintprocent(t_flags *list);
int				checkprintint(t_flags *list, int ret);
int				checkprinthex(t_flags *list, int ret);
int				checkprintpnter(t_flags *list, int ret);
int				checkprintunsignedint(t_flags *list, int ret);
int				checkprintstring(t_flags *list);
int				checkprintchar(t_flags *list);

int				ft_putstrlen(const char *str, int len);
void			setallflagstonull(t_flags *flags);
int				checkbignum(int a, int b, int c);
int				ft_putunbr(unsigned int number);
int				chkflagsnull(t_flags *flags);
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

int				printchar(t_flags *list);
int				char_widthprint(t_flags *list);
int				char_minwidthprint(t_flags *list);

int				p_print(t_flags *list);
int				p_printwidth(t_flags *list);
int				p_printminwidth(t_flags *list);
int				p_printnull(t_flags *list);
int				p_printminnull(t_flags *list);

int				printhex(t_flags *list, char *result);
int				hex_printwidth(t_flags *list, char *result);
int				hex_printprec(t_flags *list, char *result);
int				hex_printnull(t_flags *list, char *result);
int				hex_printnull2(t_flags *list, char *result, int length, int i);
int				hex_printwidthprec(t_flags *list, char *result);
int				hex_printwidthprec2(t_flags *list, char *result\
				, int length, int i);
int				hex_printwidthprec3(t_flags *list, char *result\
				, int precval, int i);
int				hex_printzeroprec(t_flags *list, char *result\
				, int i);
int				hex_printzeroprec2(t_flags *list, char *result\
				, int i, int length);
int				hex_printzeroprec3(t_flags *list, char *result\
				, int precval, int i);
char			*convtohex(t_flags *list, unsigned int decimal);
int				checksizehex(unsigned int decimal);

int				printint(t_flags *list, char *result);
int				int_printwidth(t_flags *list, char *result);
int				int_printprec(t_flags *list, char *result);
int				int_printprec2(t_flags *list, char *result, int length, int i);
int				int_printzeroprec(t_flags *list, char *result, int i);
int				int_printzeroprec2(t_flags *list, char *result\
				, int length, int i);
int				int_printzeroprec3(t_flags *list, char *result\
				, int precval, int i);
int				int_printwidthprec(t_flags *list, char *result);
int				int_printwidthprec2(t_flags *list, char *result\
				, int length, int i);
int				int_printwidthprec3(t_flags *list, char *result\
				, int precval, int i);
int				int_printnull(t_flags *list, char *result);
int				int_printnull2(t_flags *list, char *result, int length, int i);

int				printpnter(t_flags *list, char *result);
int				pnt_widthprint(t_flags *list, char *result);
int				pnt_precprint(t_flags *list, unsigned long decimal);
int				checksizepnter(unsigned long decimal);
char			*convtopnter(t_flags *list, unsigned long decimal);

int				printstring(t_flags *list);
int				string_precprint(t_flags *list);
int				string_precprint2(t_flags *list, char *result, int length);
int				string_widthprint(t_flags *list);
int				string_widthprint2(t_flags *list, char *result, int length);
int				string_precwidthprint(t_flags *list);
int				string_precwidthprint2(t_flags *list, char *result, int length);
int				string_minprecwidthprint(t_flags *list);
int				string_minprecwidthprint2(t_flags *list, char *result\
				, int length);
int				string_minwidthprint(t_flags *list);
int				string_minwidthprint2(t_flags *list, char *result, int length);

int				printuint(t_flags *list, char *result);
int				uint_printwidth(t_flags *list, char *result);
int				uint_printprec(t_flags *list, char *result);
int				uint_printprec2(t_flags *list, char *result, int length, int i);
int				uint_printnull(t_flags *list, char *result);
int				uint_printnull2(t_flags *list, char *result, int length, int i);
int				uint_printzeroprec(t_flags *list, char *result);
int				uint_printzeroprec2(t_flags *list, char *result, int length);
int				uint_printzeroprec3(t_flags *list, char *result\
				, int precval, int i);
int				uint_printwidthprec(t_flags *list, char *result);
int				uint_printwidthprec2(t_flags *list, char *result, int length);
int				uint_printwidthprec3(t_flags *list, char *result\
				, int precval, int i);

#endif
