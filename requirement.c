/*
** EPITECH PROJECT, 2018
** SYN_projTester_2017
** File description:
** requirement
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

void my_ps_synthesis(void)
{
	int stat;
	char *av[2] = {"ps", NULL};
	char *env[1] = {NULL};
	pid_t pid;

	pid = fork();
	if (pid == -1)
		exit(84);
	if (pid == 0)
		execve("/usr/bin/ps", av, env);
	else
		wait(&stat);
}