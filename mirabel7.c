#include "header.h"

/**
 * for_command_execution - executes
 *
 * @datshell: data
 * Return: 1
 */

int for_command_execution(data_shell *datshell)
{
	pid_t pd, wpda;
	int stte, exc;
	char *dir;
	(void)wpda;

	exc = test_executionee(datshell);
	if (exc == -1)
		return (1);
	if (exc == 0)
	{
		dir = locteOrigCmd(datshell->args[0], datshell->dtenviron);
		if (confirm_for_error(dir, datshell) == 1)
			return (1);
	}
	pd = fork();
	if (pd == 0)
	{
		if (exc == 0)
			dir = locteOrigCmd(datshell->args[0], datshell->dtenviron);
		else
			dir = datshell->args[0];
		execve(dir + exc, datshell->args, datshell->dtenviron);
	}
	else if (pd < 0)
	{
		perror(datshell->av[0]);
		return (1);
	}
	else
	{
		do {
			wpda = waitpid(pd, &stte, WUNTRACED);
		} while (!WIFEXITED(stte) && !WIFSIGNALED(stte));
	}
	datshell->status = stte / 256;
	return (1);
}

/**
 * environ_ident - compares
 * @newenvi: name
 * @name: name
 *
 * Return: 0
 */

int environ_ident(const char *newenvi, const char *name)
{
	int i, res;

	for (i = 0; newenvi[i] != '='; i++)
	{
		if (newenvi[i] != name[i])
		{
			return (0);
		}
	}
	res = i + 1;
	return (res);
}

/**
 * getenviron - get
 * @name: name
 * @dtenviron: environment
 *
 * Return: value
 */

char *getenviron(const char *name, char **dtenviron)
{
	char *ptrEnvr;
	int i, movef;

	ptrEnvr = NULL;
	movef = 0;
	for (i = 0; dtenviron[i]; i++)
	{
		movef = environ_ident(dtenviron[i], name);
		if (movef)
		{
			ptrEnvr = dtenviron[i];
			break;
		}
	}
	return (ptrEnvr + movef);
}

/**
 * shEnv - print
 *
 * @datshell: data
 * Return: 1
 */

int shEnv(data_shell *datshell)
{
	int i, j;

	for (i = 0; datshell->dtenviron[i]; i++)
	{
		for (j = 0; datshell->dtenviron[i][j]; j++)
			;

		write(STDOUT_FILENO, datshell->dtenviron[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datshell->status = 0;

	return (1);
}

/**
 * prepareEnvron - sets
 *
 * @name: name
 * @value: value
 * @datshell: data
 */

void prepareEnvron(char *name, char *value, data_shell *datshell)
{
	int i;
	char *varEnvC, *nameEnvC;

	for (i = 0; datshell->dtenviron[i]; i++)
	{
		varEnvC = _strdup(datshell->dtenviron[i]);
		nameEnvC = stringtok(varEnvC, "=");
		if (stringcompare(nameEnvC, name) == 0)
		{
			free(datshell->dtenviron[i]);
			datshell->dtenviron[i] = m_detail(nameEnvC, value);
			free(varEnvC);
			return;
		}
		free(varEnvC);
	}
	datshell->dtenviron = my_realloc_hdp(datshell->dtenviron, i,
										sizeof(char *) * (i + 2));
	datshell->dtenviron[i] = m_detail(name, value);
	datshell->dtenviron[i + 1] = NULL;
}
