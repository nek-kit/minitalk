/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoaney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:48:09 by rmoaney           #+#    #+#             */
/*   Updated: 2021/09/15 20:29:34 by rmoaney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_text
{
	char		s;
	int			len;
}				t_text;

void			ft_putstr(char *s);
void			ft_putnbr(int n);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);

#endif
