/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoaney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:40:57 by rmoaney           #+#    #+#             */
/*   Updated: 2021/09/25 11:21:45 by rmoaney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_txt_send(int pid, size_t len, char *txt)
{
	size_t	i;
	int		bit;

	i = 0;
	while ((len + 1) > i)
	{
		bit = 0;
		while (bit < 7)
		{
			if ((txt[i] >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		ft_putstr("You need to use: client PID message\n");
	else
	{
		pid = ft_atoi(argv[1]);
		ft_txt_send(pid, ft_strlen(argv[2]), argv[2]);
	}
	return (0);
}
