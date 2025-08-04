/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkieboom <rkieboom@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:02:47 by rkieboom          #+#    #+#             */
/*   Updated: 2025/08/06 16:02:41 by rkieboom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/**
 * @brief A custom implementation of printf
 * @param format The format string containing text and format specifiers
 * @param ... Variable arguments corresponding to format specifiers
 * @return Number of characters printed, or -1 on error
 * 
 * Supported format specifiers:
 * - %c: Character
 * - %s: String
 * - %p: Pointer address
 * - %d, %i: Signed decimal integer
 * - %u: Unsigned decimal integer
 * - %x: Lowercase hexadecimal
 * - %X: Uppercase hexadecimal
 * - %%: Literal percent sign
 * 
 * Supported flags:
 * - '-': Left-justify
 * - '0': Zero-padding
 * - '.': Precision
 * - Width specifiers
 */
int	ft_printf(const char *format, ...);

#endif
