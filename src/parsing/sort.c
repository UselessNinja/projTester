/*
** EPITECH PROJECT, 2018
** SYN_projTester_2017
** File description:
** sort
*/

#include "../../include/projtester.h"

void swapptr(tree_t *none, tree_t *ntwo)
{
	void *temp;

	temp = none->name;
	none->name = ntwo->name;
	ntwo->name = temp;
	temp = none->data;
	none->data = ntwo->data;
	ntwo->data = temp;
}

void sort_alphabetically(tree_t *node)
{
	int i = 0;
	tree_t *ptr = node;

	if (ptr->next == NULL)
		return;
	while ((ptr->next->name != NULL && ptr->next != NULL && ptr)) {
		if (strcmp(ptr->name, ptr->next->name) > 0) {
			swapptr(ptr, ptr->next);
			i++;
		}
		ptr = ptr->next;
	}
	if (i != 0)
		sort_alphabetically(node);
}
