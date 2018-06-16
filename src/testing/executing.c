/*
** EPITECH PROJECT, 2018
** SYN_projTester_2017
** File description:
** executing
*/

#include "../../include/projtester.h"

char **make_arguments(projtester_t *pt)
{
	int i = 0;
	char **arguments = malloc(sizeof(char **) * 10);

	arguments[0] = my_strdup(pt->arg.bft);
	if (pt->av == NULL) {
		arguments[1] = NULL;
		return (arguments);
	}
	for (i = 0; pt->av[i] != NULL; i++)
		arguments[i + 1] = my_strdup(pt->av[i]);
	arguments[i + 1] = NULL;
	return (arguments);
}

char **default_path(void)
{
	char **path = malloc(sizeof(char *) * 2);

	path[0] = malloc(sizeof(char) * my_strlen("/bin") + 1);
	path[0] = "/bin";
	path[1] = malloc(sizeof(char) * (my_strlen("/usr/bin") + 1));
	path[1] = "/usr/bin";
	return (path);
}

void exec_withpath(projtester_t *pt)
{
	char *env[1] = {NULL};
	char **arguments = make_arguments(pt);

	pt->pid = fork();
	if (pt->pid == -1)
		exit(84);
	if (pt->pid == 0) {
		execve(pt->arg.bft, arguments, env);
	} else
		wait(NULL);
}

void exec_withoutpath(projtester_t *pt)
{
	int i = 0;
	char *full_path;
	char **arguments = make_arguments(pt);
	char **path = default_path();
	char *env[1] = {NULL};


	pt->pid = fork();
	do {
		full_path = my_strcat_dup(path[i],
		my_strcat_dup("/", pt->arg.bft));
		i++;
	} while (access(full_path, F_OK) != 0 && path[i] != NULL);
	if (access(full_path, F_OK) == 0 && pt->pid == 0) {
		if (execve(full_path, arguments, env) == -1) {
			exit(84);
		}
	} else if (access(full_path, F_OK) != 0)
		exit(84);
	wait(NULL);
}

void exec_binary(projtester_t *pt)
{
	dup2(pt->fd, 1);
	if (strchr(pt->arg.bft, '/') != NULL ||
		strchr(pt->arg.bft, '.') != NULL)
		exec_withpath(pt);
	else
		exec_withoutpath(pt);
}