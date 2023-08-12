#include "header.h"

/**
 * freeDataFxn - frees data structure
 *
 * @datash: data structure
 * Return: no return
 */

void freeDataFxn(data_shell *datash)
{
	unsigned int n;

	for (n = 0; datash->dtenviron[n]; n++)
	{
		free(datash->dtenviron[n]);
	}

	free(datash->dtenviron);
	free(datash->pid);
}


/**
 * init_data - Initialize data structure
 *
 * @datash: data structure
 * @av: argument vector
 * Return: no return
 */

void init_data(data_shell *datash, char **av)
{
	unsigned int m;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (m = 0; environ[m]; m++)
		;

	datash->dtenviron = malloc(sizeof(char *) * (m + 1));

	for (m = 0; environ[m]; m++)
	{
		datash->dtenviron[m] = _strdup(environ[m]);
	}

	datash->dtenviron[m] = NULL;
	datash->pid = autIToAlph(getpid());
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */

int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT, fetch_SIGINT);
	init_data(&datash, av);
	SH_loop(&datash);
	freeDataFxn(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
