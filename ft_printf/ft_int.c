/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:39:25 by danielad          #+#    #+#             */
/*   Updated: 2025/11/21 12:39:38 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int(int nbr)
{
	int	count;

	count = ft_len_count(nbr);
	ft_putnbr(nbr);
	return (count);
}
