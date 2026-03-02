/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:32:14 by danielad          #+#    #+#             */
/*   Updated: 2026/03/02 17:42:22 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <inttypes.h>

int		ft_printf(const char *format, ...);
int		ft_char(char c);
int		ft_string(char *s);
int		ft_int(int nbr);
int		ft_len_count(long nbr);
int		ft_unsigned(unsigned int nbr);
int		ft_adress(uintptr_t ptr);
int		ft_hexa_len_count(unsigned long long int nbr);
int		ft_hexa(long int nbr, char format);
void	ft_putnbr(long nbr);
void	ft_hexa_putnbr(long int nbr, char format);
void	ft_putnbr(long nbr);
void	ft_ptr_putnbr(uintptr_t nbr);

#endif 