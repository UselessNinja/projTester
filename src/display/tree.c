/*
** EPITECH PROJECT, 2018
** SYN_projTester_2017
** File description:
** tree
*/

#include "../../include/projtester.h"

void disp_last(char *str)
{
	int i;
	int j = 0;

	if (str[strlen(str) - 1] ==  '/')
		str[strlen(str) - 1] = '\0';
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == 47)
			j = i + 1;
	}
	for (i = j; str[i] != '\0'; i++) {
		write(1, &str[i], 1);
	}
	write(1, "\n", 1);
}

void display_tabs(char *str, char *trd)
{
	int i;
	int j = 0;
	int k = 0;

	if (trd[strlen(trd) - 1] ==  '/')
		trd[strlen(trd) - 1] = '\0';
	if (str[strlen(str) - 1] ==  '/')
		str[strlen(str) - 1] = '\0';
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == 47)
			j++;
	}
	for (i = 0; trd[i] != '\0'; i++) {
		if (trd[i] == 47)
			k++;
	}
	for (i = 0; i < (j - k); i++)
		write(1, "-----", 5);
}

void tree(projtester_t *pt)
{
	tree_t *temp = pt->tree;

	disp_last(pt->arg.trd);
	while (temp->name != NULL) {
		display_tabs(temp->name, pt->arg.trd);
		disp_last(temp->name);
		temp = temp->next;
	}
	free_graph(pt->tree);
	exit (0);
}