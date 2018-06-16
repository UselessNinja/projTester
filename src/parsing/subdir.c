/*
** EPITECH PROJECT, 2018
** SYN_projTester_2017
** File description:
** subdir
*/

#include "../../include/projtester.h"

void if_error(DIR *fd, char *path)
{
	if (fd == NULL) {
		fprintf(stderr, "Cannot open directory %s\n", path);
		free(path);
		exit(84);
	}
}

void subdirectory_management(struct dirent *data, projtester_t *pt, char *path)
{
	char *sub;

	sub = my_strcat_dup(path, data->d_name);
	if (sub[strlen(sub) - 1] !=  '/')
		sub = my_strcat_dup(sub, "/");
	add_data(pt->tree, sub, NULL);
	add_nodes(pt->tree);
	get_data_from_subdir(pt, sub);
	free(sub);

}

void get_data_from_subdir(projtester_t *pt, char *path)
{
	DIR *fd;
	struct dirent *data;

	fd = opendir(path);
	if_error(fd, path);
	for (data = readdir(fd); data != NULL; data = readdir(fd)) {
		if (!strcmp(".", data->d_name) || !strcmp("..", data->d_name))
			continue;
		if (is_directory(path, data->d_name)) {
			subdirectory_management(data, pt, path);
		} else {
			get_data_from_file(pt, path, data);
			add_nodes(pt->tree);
		}
	}
	closedir(fd);
}