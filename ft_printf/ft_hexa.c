/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:41:01 by danielad          #+#    #+#             */
/*   Updated: 2025/11/21 12:41:03 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(long int nbr, char format)
{
	int	count;

	count = ft_hexa_len_count(nbr);
	if (nbr < 0)
		nbr *= -1;
	ft_hexa_putnbr(nbr, format);
	return (count);
}
