/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasa <zyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:21:30 by zyasa             #+#    #+#             */
/*   Updated: 2022/12/18 20:13:22 by zyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	put_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	put_point(long double nbr, int base, int is_upper)
{
	int	count;

	count = 0;
	count += put_str("0x");
	count += put_nbr(nbr, base, is_upper);
	return (count);
}

int	put_nbr(long double nbr, int base, int is_upper)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		count++;
	}
	if (nbr >= base)
		count += put_nbr(((unsigned long) nbr / base), base, is_upper);
	if (is_upper == 1)
	{
		write(1, &UPPER_BASE[(unsigned long)nbr % base], 1);
		count++;
	}
	else
	{
		write(1, &LOWER_BASE[(unsigned long)nbr % base], 1);
		count++;
	}
	return (count);
}
