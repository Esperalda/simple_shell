#include "header.h"

/* .........................NUM 11 START.......................*/
/**
 * locteOrigCmd - locates
 *
 * @cmd: command
 * @dtenviron: environment
 * Return: location
 */

char *locteOrigCmd(char *cmd, char **dtenviron)
{
	char *path, *ptr_pth, *tkn_pth, *dir;
	int len_dir, cmd_len, i;
	struct stat st;

	path = getenviron("PATH", dtenviron);
	if (path)
	{
		ptr_pth = _strdup(path);
		cmd_len = string_length(cmd);
		tkn_pth = stringtok(ptr_pth, ":");
		i = 0;
		while (tkn_pth != NULL)
		{
			if (test_CurrentDir(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = string_length(tkn_pth);
			dir = malloc(len_dir + cmd_len + 2);
			string_copy(dir, tkn_pth);
			string_cartenate(dir, "/");
			string_cartenate(dir, cmd);
			string_cartenate(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				freeCharMemDaf(ptr_pth);
				return (dir);
			}
			freeCharMemDaf(dir);
			tkn_pth = stringtok(NULL, ":");
		}
		freeCharMemDaf(ptr_pth);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/* .........................NUM 11 BTW.........................*/
/**
 * freeCharMemDaf - frees
 * @temp: head
 */

void freeCharMemDaf(char *temp)
{
	free(temp);
}

/* .........................NUM 11 BTW.........................*/
/**
 * freeIntMemDaf - frees
 * @temp: head of the linked list.
 */

void freeIntMemDaf(int *temp)
{
	free(temp);
}

/* .........................NUM 11 END.........................*/

/**
 * test_executionee - determines
 *
 * @datshell: data
 * Return: 0
 */

int test_executionee(data_shell *datshell)
{
	struct stat st;
	int i;
	char *input;

	input = datshell->args[0];
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);
	if (stat(input + i, &st) == 0)
	{
		return (i);
	}
	get_error(datshell, 127);
	return (-1);
}

/**
 * confirm_for_error - verifies
 *
 * @dir: destinatio
 * @datshell: data
 * Return: 1
 */
int confirm_for_error(char *dir, data_shell *datshell)
{
	if (dir == NULL)
	{
		get_error(datshell, 127);
		return (1);
	}
	if (stringcompare(datshell->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			get_error(datshell, 126);
			freeCharMemDaf(dir);
			return (1);
		}
		freeCharMemDaf(dir);
	}
	else
	{
		if (access(datshell->args[0], X_OK) == -1)
		{
			get_error(datshell, 126);
			return (1);
		}
	}
	return (0);
}
