/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzimaeva <rzimaeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 13:21:10 by rzimaeva          #+#    #+#             */
/*   Updated: 2026/01/07 21:21:33 by rzimaeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t g_sig = 0;
 
void signal_g(int status)
{
    g_sig = status;
}
void send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)//vu que i = 7, on decale tout vers la droite, regarde suite en bas
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

int	ft_atoi(char *str)//recupere le PID, ascii to integer
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10 + (str[i] - 48));
		i++;
	}
	return (result * sign);
}
send char
{
	while (bit)
}

// Remarque bien : les 7 premiers bits sont des 0, et seul le dernier est un 1.
//     Les 0 agissent comme un mur : n'importe quoi & 0 donnera toujours 0.
//     Le 1 à la fin agit comme une fenêtre : il laisse passer la valeur originale du bit.



//Exemple concret avec 'A' (01000001) et i = 6 :
//     On part de : 01000001
//     c >> 6 : On décale de 6 positions vers la droite.
//         Le 1 du début (position 6) se déplace tout à la fin.
//        On obtient : 00000001
//     ... & 1 : On compare avec 00000001.
//         1 ET 1 égale 1.
//     Résultat : La condition == 1 est VRAIE. Tu envoies SIGUSR2.



// Exemple avec 'A' (01000001) et i = 5 :
//     On part de : 01000001
//     c >> 5 : On décale de 5 positions.
//         Le bit à cette position était un 0.
//         On obtient : 00000010
//     ... & 1 : On compare le dernier bit (0) avec 1.
//         0 ET 1 égale 0.
//     Résultat : La condition == 1 est FAUSSE. Tu envoies SIGUSR1.



//3 arg = ./client PID(24839423) message("ewfw")
int main(int ac, char **av)
{
	int	i;
	i = 0;
	if (ac = 3)
	{
		
	}
			
}