/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzimaeva <rzimaeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:25:26 by rzimaeva          #+#    #+#             */
/*   Updated: 2026/01/07 18:09:14 by rzimaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf.h"
#include "minitalk.h"

//on utilise void handle(int sig, siginfo_t, void *) au lieu de void handle(int sig) car ca nous permet de recuperer le PID client
//on laisse qund meme void *present pour que le compilateur fonctionne mais ca ne sert a rien dans minitalk
void	sig_handler(int nbsig/*contient numero du signal 10 ou 12 voir explications.c*/, siginfo_t *info_pid, void *present)
{
	static char	c;//contient 8 BITS MAIS 1 seul BYTE
	static int	count_bit;//se souvient du compte de bytes grace au static
	pid_t	client;
	
	client = info_pid->si_pid;//si_pid fait partie de la structure siginfo_t
	(void)present;//(void) sert a utiliser le parametre context car on l'utilise nulle part dans le code
	c <<= 1;//pour decaler les bytes a gauche laissant une case vide tout a droite car on recoit les bytes un par un et non en meme temps
	//1 = 00000001! (on decale a gauche) <<=1, 10 = 0000001!0 <<=1, 100 = 000001!00 <<=1, 1000 = 00001!000
	if (nbsig == SIGUSR2)
		c |= 1;//rajoute le 1 tout a la fin
	count_bit++;
	if (count_bit == 8)//total de bits voulu 
	{
		if (c == '\0')//si on a atteint la fin des bits on va juste a la ligne
			write(1, "\n", 1);
		else
			write(1, &c, 1);//sinon on affiche le caractere voulu et on recommence avec un autre caractere
		c = 0;//Une fois la lettre affichée, on vide la boîte (c) et on remet le compteur à zéro pour pouvoir construire la lettre suivante.
		count_bit = 0;
	}
	/*kill(client, SIGUSR1); SI BONUS*/
}

int	main(void)
{
	ft_printf("PID : %s", getpid);
	return (0);
}