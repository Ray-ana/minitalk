/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzimaeva <rzimaeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:25:26 by rzimaeva          #+#    #+#             */
/*   Updated: 2025/12/29 16:37:59 by rzimaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf.h"
#include "minitalk.h"

volatile sig_atomic_t	g_status; /*utiliser SIGINT pour le main*/

void signal_handler(int status)
{
    gSignalStatus = status;
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	c;//contient 8 bytes
	static int	count_byt;//se souvient du compte de bytes grace au static
	pid_t	client;
	
	client = info->si_pid;
	(void)context;
	c <<= 1;
	if (sig == SIGUSR2)
		c |= 1;
	count_byt++;
	if (count_byt == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		count_byt = 0;
	}
	/*kill(info->si_pid, SIGUSR1); SI BONUS*/
}

int	main(void)
{
	ft_printf("PID : %s", getpid);
	return (0);
}