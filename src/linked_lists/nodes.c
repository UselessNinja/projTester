/*
** EPITECH PROJECT, 2018
** SYN_projTester_2017
** File description:
** nodes
*/

#include "../../include/projtester.h"

tree_t *create_node(void)
{
	tree_t *node = malloc(sizeof(tree_t));

	node->name = NULL;
	node->data = NULL;
	node->next = NULL;
	return (node);
}

void add_nodes(tree_t *node)
{
	tree_t *temp = node;

	while (temp->next)
		temp = temp->next;
	temp->next = create_node();
}

void add_data(tree_t *node, char *path, char **data)
{
	int i;
	tree_t *temp = node;

	while (temp->next)
		temp = temp->next;
	temp->name = strdup(path);
	if (data != NULL) {
		temp->data = malloc(sizeof(data) + 8);
		for (i = 0; data[i] != NULL; i++)
			temp->data[i] = strdup(data[i]);
		temp->data[i] = NULL;
	}
}

void free_graph(tree_t *tree)
{
	tree_t *old = tree;

	while (tree) {
		old = tree;
		tree = tree->next;
		free(old->name);
		if (old->data != NULL)
			free(old->data);
		free(old);
	}
}

void print_tree(tree_t *node)
{
	tree_t *temp = node;

	if (temp->name != NULL) {
		write(1, temp->name, my_strlen(temp->name));
		write(1, "\n", 1);
		print_tree(temp->next);
	}
}