/*
** EPITECH PROJECT, 2018
** SYN_projTester_2017
** File description:
** main
*/

#include "../include/projtester.h"

void help(void)
{
	fprintf(stderr, "USAGE\n");
	fprintf(stderr, "\t./projTester TRD [BFT] [outputFile]\n\n");
	fprintf(stderr, "DESCRIPTION\n");
	fprintf(stderr, "\tTRD\t\troot directory of all the tests\n");
	fprintf(stderr, "\tBFT\t\tbinary file to be tested\n");
	fprintf(stderr, "\toutputFile\tfile in which the result is printed\n");
	exit(84);
}

void get_args(int ac, projtester_t *pt, char **av)
{
	if (ac == 2) {
		pt->arg.trd = av[1];
		pt->arg.bft = NULL;
		pt->arg.outputfile = NULL;
	}
	if (ac == 3) {
		pt->arg.trd = av[1];
		pt->arg.bft = av[2];
		pt->arg.outputfile = NULL;
	}
	if (ac == 4) {
		pt->arg.trd = av[1];
		pt->arg.bft = av[2];
		pt->arg.outputfile = av[3];
	}
}

int main(int ac, char **av)
{
	projtester_t pt;

	if (ac < 2 || ac > 4)
		help();
	get_args(ac, &pt, av);
	get_data_from_dir(&pt);
	sort_alphabetically(pt.tree);
	pt.fd = 1;
	if (ac == 2)
		tree(&pt);
	if (ac == 4) {
		pt.fd = open(pt.arg.outputfile, O_CREAT | O_TRUNC | O_RDWR);
		if (pt.fd == -1)
			return (84);
	}
	projtester(&pt);
	if (ac == 4)
		close(pt.fd);
	free_graph(pt.tree);
	return (0);
}