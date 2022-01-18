/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoaney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:38:24 by rmoaney           #+#    #+#             */
/*   Updated: 2021/09/15 20:23:34 by rmoaney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					znak;
	unsigned long long	num;

	i = 0;
	znak = 1;
	num = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\v') || \
			(str[i] == '\n') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		znak = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > 2147483647 && znak > 0)
			return (-1);
		if (num > 2247483648 && znak < 0)
			return (0);
		num = (num * 10) + ((int)str[i++] - '0');
	}
	return (num * znak);
}
