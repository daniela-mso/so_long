/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:31:14 by danielad          #+#    #+#             */
/*   Updated: 2025/11/21 12:31:16 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_adress(uintptr_t ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		count += ft_string("(nil)");
	else
	{
		count = ft_hexa_len_count(ptr);
		ft_string("0x");
		count += 2;
		ft_ptr_putnbr(ptr);
	}
	return (count);
}
