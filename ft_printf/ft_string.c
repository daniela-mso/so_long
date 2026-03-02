/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:40:37 by danielad          #+#    #+#             */
/*   Updated: 2025/11/21 12:40:44 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(char *s)
{
	int	count;

	if (s == NULL)
		s = "(null)";
	count = 0;
	while (s[count] != '\0')
		count++;
	write(1, s, count);
	return (count);
}
