/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explications.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzimaeva <rzimaeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:12:23 by rzimaeva          #+#    #+#             */
/*   Updated: 2025/12/26 21:47:09 by rzimaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

c'est quoi un signal = interruption, Un signal est un message très court (une simple notification numérique) 
		envoyé par le système d'exploitation ou par un autre programme à un processus.

signal / sigaction = Pour configurer le comportement du programme à la réception d'un signal. 
		sigaction est fortement recommandé car il permet de récupérer le PID de l'expéditeur via siginfo_t.
kill = pour envoyer un signal à un processus spécifique.
getpid,Pour obtenir l'ID du processus actuel.
pause,Pour mettre le programme en attente jusqu'à la réception d'un signal (évite de consommer 100% du CPU).

SIGUSR1 = un signal utilisateur qui represente en bit 0
SIGUSR2 = un signal utilisateur qui represente en bit 1

1. l'envoi = processus A (le client) utilise la fonction 
	kill(pid_serveur, SIGUSR1)
2. la receptioon = noyau (Operating System) recoit la demande, la notif
	et interromp le processus B (les serveur)
3. le traitement = serveur s'arrete pour effectuer une fonction appelee
	"special handler" qu'on definit

client envoie signal du type SIGUSR1 ou SIGUSR2 a serveur puis il ecrit 1 ou 0

apres 8 bits en ecrit les caracteres 
void handle_spe(int	s)
{
	if (s == SIGUSR1)
		//return (0);
	else if (s == SIGUSR2)
		//return (1);
}

prendre en compte le cas ou l client veut pid -1 pour pas shutdozn le pc
/*radix pour pushswap*/