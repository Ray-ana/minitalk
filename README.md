Projet minitalk 42 :

	 Le projet minitalk consiste a coder une communication client/server grace a l'usage des signaux SIGUSR1 et SIGUSR2 bit par bit.

Fichiers a rendre :

	- server.c = affiche le PID et affiche le message recu
	- client.c = envoie le message au server
	- Makefile
	- minitalk.h
	- ft_printf (recode et non le vrai)
	- libft (si besoin)

Execution :

	Pour se faire, il faudra faire la commande "make" dans le terminal pour executer le Makefile du ft_printf ET du minitalk. Ensuite, il faut utiliser la commande d'execution ./server pour recuperer le PID et ensuite dans un terminal different on va executer ./client PID "message" pour qu'il puisse s'afficher dans le terminal de notre server.

Commandes a executer en cas d'erreur :

	Etant donne qu'on manipule des bits il se peut qu'il y ait une erreur de communication entre le client et le server ce qui melange le compte de bits et donc perturbe la transmission des messages.

	Il faut alors ctrl+c pour reinitialiser le server et faire la commande "make re" pour reinitialiser le client en cas de confusion de bits ("make fclean" pour supprimer les objets et les exécutables).