/*
** EPITECH PROJECT, 2018
** SYN_projTester_2017
** File description:
** fill_tree
*/

#include "../../include/projtester.h"

int is_directory(char *trd, char *d_name)
{
	struct stat st;
	char *temp = my_strcat_dup(trd, d_name);

	stat(temp, &st);
	free(temp);
	return (S_ISDIR(st.st_mode));
}

void get_data_from_file(projtester_t *pt, char *path, struct dirent *data)
{
	size_t len = 0;
	int i = 0;
	FILE *fd;
	char *tmp = NULL;
	char **buffer;
	int guard;

	path = my_strcat_dup(path, data->d_name);
	fd = fopen(path, "r");
	if (!fd)
		return;
	buffer = malloc(sizeof(char **) * (getsize(fd) + 1));
	for (guard = getline(&tmp, &len, fd); guard != -1; i++,
		guard = getline(&tmp, &len, fd))
		buffer[i] = strdup(tmp);
	buffer[i] = NULL;
	add_data(pt->tree, path, buffer);
	fclose(fd);
}

void printerr(DIR *fd, char *path, projtester_t *pt)
{
	if (fd == NULL) {
		fprintf(stderr, "Cannot open directory %s\n", pt->arg.trd);
		free(path);
		exit(84);
	}
	pt->tree = create_node();
}

void get_data_from_dir(projtester_t *pt)
{
	char *path = pt->arg.trd;
	DIR *fd;
	struct dirent *data;

	if (path[strlen(path) - 1] !=  '/')
		path = my_strcat_dup(path, "/");
	fd = opendir(path);
	printerr(fd, path, pt);
	for (data = readdir(fd); data != NULL; data = readdir(fd)) {
		if (!strcmp(".", data->d_name) || !strcmp("..", data->d_name))
			continue;
		if (is_directory(path, data->d_name))
			subdirectory_management(data, pt, path);
		else {
			get_data_from_file(pt, path, data);
			add_nodes(pt->tree);
		}
	}
	closedir(fd);
}