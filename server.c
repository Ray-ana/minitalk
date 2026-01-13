/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzimaeva <rzimaeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:25:26 by rzimaeva          #+#    #+#             */
/*   Updated: 2026/01/12 18:22:36 by rzimaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf.h"
#include "minitalk.h"

void	sig_handle(int nbsig)
{
	static unsigned char	c;
	static int				count_bit;

	c <<= 1;
	if (nbsig == SIGUSR2)
		c |= 1;
	count_bit++;
	if (count_bit == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		count_bit = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	signal(SIGUSR1, sig_handle);
	signal(SIGUSR2, sig_handle);
	while (1)
	{
		pause();
	}
	return (0);
}
