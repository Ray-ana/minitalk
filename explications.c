/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explications.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzimaeva <rzimaeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:12:23 by rzimaeva          #+#    #+#             */
/*   Updated: 2026/01/07 18:07:33 by rzimaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

c'est quoi un signal = interruption, Un signal est un message très court (une simple notification numérique) 
		envoyé par le système d'exploitation ou par un autre programme à un processus.

signal / sigaction = Pour configurer le comportement du programme à la réception d'un signal. 
		sigaction est fortement recommandé car il permet de récupérer le PID de l'expéditeur via siginfo_t.
kill = pour envoyer un signal à un processus spécifique.
getpid,Pour obtenir l'ID du processus actuel.
pause,Pour mettre le programme en attente jusqu'à la réception d'un signal (évite de consommer 100% du CPU).

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
operateur binaire = |, &, ^ par ex, quand tu travailles avec des bits

On remplit deja tout le "tableau" de 0 donc pour SIGUSR1 c'est correct,
si on recoit le signal de SIGUSR2 on va remplacer le dernier 0 tout a droite par un 1
vu qu'on a tout remplace par decaler a gauche grace a c <<= 1, tout a ete remplace par des 0
donc SIGUSR1 represente deja 0 car la condition if (sig == SIGUSR2) est fausse, ce qui veut dire pour que
ca soit vrai ca doit forcement etre 1 a cause de c |= 1, donc le contenant de SIGUSR2

c |= 1 veut juste dire OU, donc c'est ccomme si tu faisais c += 1 car tu rajoutes/ remplace
le 0 tout a droite par le 1 en question

Dans la librairie signal.h
SIGUSR1 = vaut 10 (ou 30 sur Mac) mais represente 0 dans notre projet car on utilise aue 2 signaux
SIGUSR2 = dans la meme logique, vaut 12 (ou 31 sur Mac) mais represente 1

on peut alors pas dire par ex "if (sig == 1) car SIGUSR2 n'est pas egal a 1 mais a 12

bit et bytes c'est PAS pareil !! 
bit = par ex un char c'est 8 bits
bytes = un char c'est 1 bytes, traduction de octet -> octet!bit

La sous-routine sigaction permet à un processus appelant d'examiner et de modifier l'action à effectuer 
lorsqu'un signal spécifique est envoyé au processus émettant cette sous-routine

prendre en compte le cas ou l client veut pid -1 pour pas shutdozn le pc
/*radix pour pushswap*/