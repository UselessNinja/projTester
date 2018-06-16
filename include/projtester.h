/*
** EPITECH PROJECT, 2018
** SYN_projTester_2017
** File description:
** projtester
*/

#ifndef PROJTESTER_H_
	#define PROJTESTER_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "../lib/my/my.h"

typedef struct tree_s {
	char *name;
	char **data;
	struct tree_s *next;
} tree_t;

typedef struct argv_s {
	char *trd;
	char *bft;
	char *outputfile;
} argv_t;

typedef struct projtester_s {
	pid_t pid;
	int fd;
	char **av;
	argv_t arg;
	tree_t *tree;
} projtester_t;

/*
** nodes
*/

tree_t *create_node(void);
void add_data(tree_t *node, char *path, char **data);
void add_nodes(tree_t *node);
void free_graph(tree_t *tree);
void print_tree(tree_t *node);

/*
** parsing
*/

int is_directory(char *trd, char *d_name);
void get_data_from_dir(projtester_t *pt);
void get_data_from_subdir(projtester_t *pt, char *path);
void subdirectory_management(struct dirent *data, projtester_t *pt, char *path);
void get_data_from_file(projtester_t *pt, char *path, struct dirent *data);
void sort_alphabetically(tree_t *node);

/*
** display
*/

void tree(projtester_t *pt);
void projtester(projtester_t *pt);

/*
** exec
*/

void exec_binary(projtester_t *pt);

#endif /* !PROJTESTER_H_ */