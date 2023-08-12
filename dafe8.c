#include "header.h"

/**
 * strcartenate_current_dir - function
 * @datshell: data
 * @msges: message
 * @error: output
 * @ver_strC: counter
 * Return: error
 */

char *strcartenate_current_dir(data_shell *datshell, char *msges,
								char *error, char *ver_strC)
{
	char *illegal_flag;

	string_copy(error, datshell->av[0]);
	string_cartenate(error, ": ");
	string_cartenate(error, ver_strC);
	string_cartenate(error, ": ");
	string_cartenate(error, datshell->args[0]);
	string_cartenate(error, msges);
	if (datshell->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datshell->args[1][1];
		illegal_flag[2] = '\0';
		string_cartenate(error, illegal_flag);
		freeCharMemDaf(illegal_flag);
	}
	else
	{
		string_cartenate(error, datshell->args[1]);
	}

	string_cartenate(error, "\n");
	string_cartenate(error, "\0");
	return (error);
}

/* .........................NUM 16 START.......................*/

/**
 * error_getcurrent_dir - error
 * @datshell: data
 * Return: Error
 */

char *error_getcurrent_dir(data_shell *datshell)
{
	int length, len_id1;
	char *error, *ver_strC, *msges;

	ver_strC = autIToAlph(datshell->counter);
	if (datshell->args[1][0] == '-')
	{
		msges = print_message('i');
		len_id1 = 2;
	}
	else
	{
		msges = print_message('c');
		len_id1 = string_length(datshell->args[1]);
	}

	length = string_length(datshell->av[0]) + string_length(datshell->args[0]);
	length += string_length(ver_strC) + string_length(msges) + len_id1 + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		freeCharMemDaf(ver_strC);
		return (NULL);
	}

	error = strcartenate_current_dir(datshell, msges, error, ver_strC);

	freeCharMemDaf(ver_strC);

	return (error);
}

/* .........................NUM 16 BTW.........................*/
/**
 * print_message - error
 * @option: data
 * Return: Error
 */

char *print_message(char option)
{
	char *msges;

	if (option == 'i')
		msges = ": Invalid option ";
	else if (option == 'c')
		msges = ": can't cd to ";
	else if (option == 's')
		msges = ": Syntax error: \" ";
	else if (option == 'u')
		msges = "\" unexpected\n";
	return (msges);
}

/* .........................NUM 16 END.........................*/

/* .........................NUM 17 START.......................*/
/**
 * aut_asstantEnvirone - Hl
 */

void aut_asstantEnvirone(void)
{
	char *hlp = "env: env [option] [name=value] [command [args]]\n\t";

	aut_asstantEnvironeDaf(hlp);
}

/* .........................NUM 17 BTW.........................*/
/**
 * aut_asstantEnvironeDaf - Hlp
 * @hlp: str
 */

void aut_asstantEnvironeDaf(char *hlp)
{
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, hlp, string_length(hlp));
}

/* .........................NUM 17 END.........................*/


