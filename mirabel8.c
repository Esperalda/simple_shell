#include "header.h"

/**
 * setenviron - compar
 * @datshell: data
 * Return: 1
 */

int setenviron(data_shell *datshell)
{
	if (datshell->args[1] == NULL || datshell->args[2] == NULL)
	{
		get_error(datshell, -1);
		return (1);
	}
	prepareEnvron(datshell->args[1], datshell->args[2], datshell);
	return (1);
}

/* .........................NUM 12 START.......................*/
/**
 * unsetenviron - deletes
 *
 * @datshell: data
 *
 * Return: 1
 */

int unsetenviron(data_shell *datshell)
{
	char **reallocdtenvironT, *varenv_c, *nameenv_c;
	int i, j, k, l;

	if (datshell->args[1] == NULL)
	{
		get_error(datshell, -1);
		return (1);
	}
	k = l = -1;
	for (i = 0; datshell->dtenviron[i]; i++)
	{
		varenv_c = nameenv_c = "ye";
		k = unsetenvironDaf(datshell, varenv_c, nameenv_c, i, l);
	}
	if (k == -1)
	{
		get_error(datshell, -1);
		return (1);
	}
	reallocdtenvironT = malloc(sizeof(char *) * (i));
	for (i = j = 0; datshell->dtenviron[i]; i++)
	{
		if (i != k)
		{
			reallocdtenvironT[j] = datshell->dtenviron[i];
			j++;
		}
	}
	reallocdtenvironT[j] = NULL;
	free(datshell->dtenviron[k]);
	free(datshell->dtenviron);
	datshell->dtenviron = reallocdtenvironT;
	return (1);
}

/* .........................NUM 12 BTW.........................*/
/**
 * unsetenvironDaf - delete
 * @datshell: data
 * @varenv_c: data
 * @nameenv_c: data
 * @i: data
 * @k: data
 * Return: 1 on success.
 */

int unsetenvironDaf(data_shell *datshell, char *varenv_c, char *nameenv_c,
		    int i, int k)
{
	varenv_c = _strdup(datshell->dtenviron[i]);
	nameenv_c = stringtok(varenv_c, "=");
	if (stringcompare(nameenv_c, datshell->args[1]) == 0)
	{
		k = i;
	}
	freeCharMemDaf(varenv_c);

	return (k);
}

/* .........................NUM 12 END.........................*/

/**
 * confirmdtenvironmente - checks
 *
 * @h: head
 * @in: input
 * @data: data
 */

void confirmdtenvironmente(strct_variable **h, char *in, data_shell *data)
{
	int row, chr, j, lvalr;
	char **EnvrT;

	EnvrT = data->dtenviron;
	for (row = 0; EnvrT[row]; row++)
	{
		for (j = 1, chr = 0; EnvrT[row][chr]; chr++)
		{
			if (EnvrT[row][chr] == '=')
			{
				lvalr = string_length(EnvrT[row] + chr + 1);
				include_Revar_node(h, j, EnvrT[row] + chr + 1, lvalr);
				return;
			}
			if (in[j] == EnvrT[row][chr])
				j++;
			else
				break;
		}
	}
	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}
	include_Revar_node(h, j, NULL, 0);
}

/**
 * confirm_variable - check
 *
 * @h: head
 * @in: input
 * @st: lastar
 * @data: data structure
 * Return: int
 */

int confirm_variable(strct_variable **h, char *in, char *st, data_shell *data)
{
	int i, lstt, lpdt;

	lstt = string_length(st);
	lpdt = string_length(data->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				include_Revar_node(h, 2, st, lstt), i++;
			else if (in[i + 1] == '$')
				include_Revar_node(h, 2, data->pid, lpdt), i++;
			else if (in[i + 1] == '\n')
				include_Revar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				include_Revar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				include_Revar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				include_Revar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				include_Revar_node(h, 0, NULL, 0);
			else
				confirmdtenvironmente(h, in + i, data);
		}
	}
	return (i);
}
