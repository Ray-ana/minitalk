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
	
	client = info->si_pid;//Grâce au flag SA_SIGINFO que tu mettras dans ton 
	//sigaction, la structure info contient le PID du client. Cette ligne permet de savoir précisément qui t'envoie le signal.
	(void)context;//(void) sert a utiliser le parametre context car on l'utilise nulle part dans le code
	c <<= 1;//pour decaler les bytes a gauche laissant une case vide tout a droite car on recoit les bytes un par un et non en meme temps
	//00000001| <<=1 0000001|0 <<=1 000001|00 <<=1 00001|000
	if (sig == SIGUSR2)
		c |= 1;//rajoute le 1 tout a la fin
	count_byt++;
	if (count_byt == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;//Une fois la lettre affichée, on vide la boîte (c) et on remet le compteur à zéro pour pouvoir construire la lettre suivante.
		count_byt = 0;
	}
	/*kill(info->si_pid, SIGUSR1); SI BONUS*/
}

int	main(void)
{
	ft_printf("PID : %s", getpid);
	return (0);
}
