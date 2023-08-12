#include "header.h"

/**
 * get_builtinFunPtr - builtin
 * @cmd: command
 * Return: function
 */

int (*get_builtinFunPtr(char *cmd))(data_shell *)
{
	builtin_cmds builtin[] = {
	    {"env", shEnv},
	    {"exit", quit_shell_op},
	    {"setenv", setenviron},
	    {"unsetenv", unsetenviron},
	    {"cd", change_dir_SH},
	    {"hlp", get_asst2},
	    {NULL, NULL}};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (stringcompare(builtin[i].name, cmd) == 0)
			break;
	}
	return (builtin[i].f);
}

/**
 * get_error - calls
 * @datshell: data
 * @eval: error
 * Return: error
 */

int get_error(data_shell *datshell, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = errordtenviron_message(datshell);
		break;
	case 126:
		error = error_RD_126(datshell);
		break;
	case 127:
		error = error_missing(datshell);
		break;
	case 2:
		if (stringcompare("exit", datshell->args[0]) == 0)
			error = error_ext_shell(datshell);
		else if (stringcompare("cd", datshell->args[0]) == 0)
			error = error_getcurrent_dir(datshell);
		break;
	}
	if (error)
	{
		write(STDERR_FILENO, error, string_length(error));
		free(error);
	}
	datshell->status = eval;
	return (eval);
}

/**
 * get_asst2 - function
 * @datshell: dat
 * Return: Return 0
 */

int get_asst2(data_shell *datshell)
{
	if (datshell->args[1] == 0)
		aut_asstant_general();
	else if (stringcompare(datshell->args[1], "setenv") == 0)
		aut_asstsetenvironee();
	else if (stringcompare(datshell->args[1], "env") == 0)
		aut_asstantEnvirone();
	else if (stringcompare(datshell->args[1], "unsetenv") == 0)
		aut_asstunsetenvironddd();
	else if (stringcompare(datshell->args[1], "hlp") == 0)
		authenticator_asst();
	else if (stringcompare(datshell->args[1], "exit") == 0)
		authenticate_asst_Ext();
	else if (stringcompare(datshell->args[1], "cd") == 0)
		aut_asst_current_dir();
	else if (stringcompare(datshell->args[1], "alias") == 0)
		authenticator_asst_alias();
	else
		write(STDERR_FILENO, datshell->args[0],
		      string_length(datshell->args[0]));

	datshell->status = 0;
	return (1);
}

/* .........................NUM 13 START.......................*/

/**
 * show_line - assigns
 * @lneptr1: Buffer
 * @buffer: str that
 * @n: size
 * @j: size
 */
void show_line(char **lneptr1, size_t *n, char *buffer, size_t j)
{
	if (*lneptr1 == NULL)
	{
		show_lineDaf(lneptr1, n, buffer, j);
	}
	else if (*n < j)
	{
		show_lineDaf(lneptr1, n, buffer, j);
	}
	else
	{
		string_copy(*lneptr1, buffer);
		free(buffer);
	}
}

/* .........................NUM 13 BTW.........................*/

/**
 * show_lineDaf - assigns
 * @lneptr1: Buffer
 * @buffer: str
 * @n: size
 * @j: size
 */
void show_lineDaf(char **lneptr1, size_t *n, char *buffer, size_t j)
{
	if (j > BUFSIZE)
		*n = j;

	else
		*n = BUFSIZE;
	*lneptr1 = buffer;
}
