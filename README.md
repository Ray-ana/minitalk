*This project has been created as part of the 42 curriculum by rzimaeva.*

# Description
The minitalk project consists of creating a small data transmission program using UNIX signals. It involves a client and a server that communicate with each other using only SIGUSR1 and SIGUSR2.

# Instructions
Compile both the server and the client executables using the Makefile:

	make

Run the server first to obtain its Process ID (PID):

	./server

In another terminal, run the client by passing the server's PID and the message to transmit:

	./client <server_pid> "Hello World"

# Resources
I mainly did my project with peer learning and a few different links

https://medium.com/@beatrizbazaglia/minitalk-6176322eb954

https://42-cursus.gitbook.io/guide/2-rank-02/minitalk/understand-minitalk
