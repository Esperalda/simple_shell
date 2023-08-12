#include "header.h"

/**
 * errordtenviron_message - error
 * @datshell: data
 * Return: error
 */

char *errordtenviron_message(data_shell *datshell)
{
	int length;
	char *error;
	char *ver_strC;
	char *msges;

	ver_strC = autIToAlph(datshell->counter);
	msges = ": Unable to add/remove from environment\n";
	length = string_length(datshell->av[0]) + string_length(ver_strC);
	length += string_length(datshell->args[0]) + string_length(msges) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		freeCharMemDaf(error);
		freeCharMemDaf(ver_strC);
		return (NULL);
	}

	string_copy(error, datshell->av[0]);
	string_cartenate(error, ": ");
	string_cartenate(error, ver_strC);
	string_cartenate(error, ": ");
	string_cartenate(error, datshell->args[0]);
	string_cartenate(error, msges);
	string_cartenate(error, "\0");
	free(ver_strC);

	return (error);
}

/**
 * error_RD_126 - error
 * @datshell: data
 *
 * Return: The
 */

char *error_RD_126(data_shell *datshell)
{
	int length;
	char *ver_strC;
	char *error;

	ver_strC = autIToAlph(datshell->counter);
	length = string_length(datshell->av[0]) + string_length(ver_strC);
	length += string_length(datshell->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		freeCharMemDaf(error);
		freeCharMemDaf(ver_strC);
		return (NULL);
	}
	string_copy(error, datshell->av[0]);
	string_cartenate(error, ": ");
	string_cartenate(error, ver_strC);
	string_cartenate(error, ": ");
	string_cartenate(error, datshell->args[0]);
	string_cartenate(error, ": Permission denied\n");
	string_cartenate(error, "\0");
	freeCharMemDaf(ver_strC);
	return (error);
}

/**
 * SH_loop - Loop
 * @datshell: data
 */

void SH_loop(data_shell *datshell)
{
	int loop, i_end_of_file;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "prompt by dafe and mirabel$ ", 29);
		input = scan_line(&i_end_of_file);
		if (i_end_of_file != -1)
		{
			input = remove_command(input);
			if (input == NULL)
				continue;

			if (confirm_stx_error(datshell, input) == 1)
			{
				datshell->status = 2;
				freeCharMemDaf(input);
				continue;
			}
			input = rest_variable(input, datshell);
			loop = separate_command_args(datshell, input);
			datshell->counter += 1;
			freeCharMemDaf(input);
		}
		else
		{
			loop = 0;
			freeCharMemDaf(input);
		}
	}
}

/* .........................NUM 14 START.......................*/

/**
 * exchange_character - swaps
 *
 * @input: inpu
 * @bool: type
 * Return: swapped
 */

char *exchange_character(char *input, int bool)
{
	int i = 0, chk;

	if (bool == 0)
	{
		chk = 1;
		input = exchange_characterDaf(input, i, chk);
	}
	else
	{
		chk = 2;
		input = exchange_characterDaf(input, i, chk);
	}
	return (input);
}

/* .........................NUM 14 BTW.........................*/

/**
 * exchange_characterDaf - swaps
 *
 * @input: input
 * @i: type
 * @chk: type
 * Return: swapped
 */

char *exchange_characterDaf(char *input, int i, int chk)
{
	int chkgn;

	if (chk == 1)
	{
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '|')
			{
				chkgn = 1;
				input = exchange_characterDafNest(input, i, chkgn);
			}
			if (input[i] == '&')
			{
				chkgn = 2;
				input = exchange_characterDafNest(input, i, chkgn);
			}
		}
	}
	else
	{
		for (i = 0; input[i]; i++)
		{
			chkgn = 3;
			input = exchange_characterDafNest(input, i, chkgn);
		}
	}
	return (input);
}

/* .........................NUM 14 BTW.........................*/
