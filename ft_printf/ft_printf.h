/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruotolo <sruotolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:39:32 by sruotolo          #+#    #+#             */
/*   Updated: 2024/02/21 21:39:41 by sruotolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H //!! getnextline
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>

int	ft_pointer(unsigned long x);
int	ft_printf(const char *p, ...);
int	ft_putchar(char c);
int	ft_putdigit(int a);
int	ft_putstr(char *str);
int	ft_unsint(unsigned int a);
int	ft_puthex(unsigned int x);
int	ft_putxx(unsigned int x);
#endif
