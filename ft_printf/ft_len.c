/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:39:47 by danielad          #+#    #+#             */
/*   Updated: 2025/11/21 12:40:29 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_count(long nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		count++;
	if (nbr < 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

int	ft_hexa_len_count(unsigned long long int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}
