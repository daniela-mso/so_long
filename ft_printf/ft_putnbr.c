/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:41:25 by danielad          #+#    #+#             */
/*   Updated: 2025/11/21 12:43:01 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long nbr)
{
	if (nbr < 0)
	{
		ft_char('-');
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_char(nbr + '0');
}

void	ft_ptr_putnbr(uintptr_t nbr)
{
	if (nbr > 15)
	{
		ft_ptr_putnbr(nbr / 16);
		ft_ptr_putnbr(nbr % 16);
	}
	else if (nbr > 9 && nbr < 16)
		ft_char(nbr - 10 + 'a');
	else
		ft_char(nbr + '0' );
}

void	ft_hexa_putnbr(long int nbr, char format)
{
	if (nbr > 15)
	{
		ft_hexa_putnbr(nbr / 16, format);
		ft_hexa_putnbr(nbr % 16, format);
	}
	else if ((nbr > 9 && nbr < 16) && (format == 'x'))
		ft_char(nbr - 10 + 'a');
	else if ((nbr > 9 && nbr < 16) && format == 'X')
		ft_char(nbr - 10 + 'A');
	else
		ft_char(nbr + '0' );
}
