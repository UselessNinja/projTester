/*
** EPITECH PROJECT, 2018
** SYN_projTester_2017
** File description:
** projtester
*/

#include "../../include/projtester.h"

void print_head(projtester_t *pt, tree_t *node)
{
	int i = 0;
	int j = 0;

	for (i = 0; node->name[i] != '\0'; i++)
		if (node->name[i] == 47)
			j = i;
	for (i = 0; node->name[i] != 47; i++);
	i++;
	for (; node->name[i] != '\0' && i < j; i++) {
		write(pt->fd, "[", 1);
		for (; node->name[i] != 47 && i < j && node->name[i] != '\0'
			; i++)
			write(pt->fd, &node->name[i], 1);
		write(pt->fd, "] ", 2);
	}
	for (j += 1; node->name[j] != 46; j++)
		write(pt->fd, &node->name[j], 1);
	write(pt->fd, ": ", 2);
}

int args(projtester_t *pt, tree_t *node)
{
	int i;
	char *temp;

	if (node->data == NULL || node->data[0] == NULL) {
		pt->av = NULL;
		return (0);
	}
	for (i = 0; node->data[i] != NULL; i++) {
		if (strstr(node->data[i], "ARGS:")) {
			pt->av = my_str_to_word_array(node->data[i]);
			break;
		}
	}
	temp = pt->av[0];
	for (i = 0; temp[5 + i] != '\0'; i++)
		pt->av[0][i] = temp[5 + i];
	pt->av[0][i] = '\0';
	return (0);
}

void projtester(projtester_t *pt)
{
	tree_t *temp = pt->tree;

	if (temp->next == NULL)
		exit(0);
	while (temp->name != NULL) {
		if (check_extension(temp->name, "tdf", 0)) {
			args(pt, temp);
			print_head(pt, temp);
			exec_binary(pt);
		}
		temp = temp->next;
	}
}