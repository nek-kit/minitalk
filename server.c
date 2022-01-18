/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoaney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:08:43 by rmoaney           #+#    #+#             */
/*   Updated: 2021/09/15 20:33:00 by rmoaney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_text	g_text;

static void	ft_txt(int bit)
{
	g_text.s = g_text.s + ((bit & 1) << g_text.len);
	g_text.len++;
	if (g_text.len == 7)
	{
		write(1, &g_text.s, 1);
		if (!g_text.s)
			write(1, "\n", 1);
		g_text.s = 0;
		g_text.len = 0;
	}
}

int	main(void)
{
	int	pid;

	g_text.s = 0;
	g_text.len = 0;
	pid = getpid();
	ft_putstr("PID: ");
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR2, ft_txt);
		signal(SIGUSR1, ft_txt);
		pause();
	}
}
