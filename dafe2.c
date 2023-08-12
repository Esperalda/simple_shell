#include "header.h"

/* .........................NUM 13 END.........................*/

/**
 * scan_line - reads
 *
 * @i_end_of_file: return
 * Return: input
 */

char *scan_line(int *i_end_of_file)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_end_of_file = getline(&input, &bufsize, stdin);
	return (input);
}

/**
 * get_line3 - Read
 * @lneptr1: buffer
 * @n: size
 * @stream: stream
 * Return: The
 */

ssize_t get_line3(char **lneptr1, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retri_val;
	char *buffer, t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			freeCharMemDaf(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = my_realloc(buffer, input, input + 1);
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	show_line(lneptr1, n, buffer, input);
	retri_val = input;
	if (i != 0)
		input = 0;
	return (retri_val);
}

/**
 * fetch_SIGINT - Handle
 * @sig: Signal handler
 */

void fetch_SIGINT(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n ", 2);
}

/**
 * error_missing - generic
 * @datshell: data
 * Return: Error
 */

char *error_missing(data_shell *datshell)
{
	int length;
	char *error, *ver_strC;

	ver_strC = autIToAlph(datshell->counter);
	length = string_length(datshell->av[0]) + string_length(ver_strC);
	length += string_length(datshell->args[0]) + 16;
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
	string_cartenate(error, ": not found\n");
	string_cartenate(error, "\0");
	freeCharMemDaf(ver_strC);
	return (error);
}

/**
 * error_ext_shell - generic
 * @datshell: data
 *
 * Return: Error
 */

char *error_ext_shell(data_shell *datshell)
{
	int length;
	char *error;
	char *ver_strC;

	ver_strC = autIToAlph(datshell->counter);
	length = string_length(datshell->av[0]) + string_length(ver_strC);
	length += string_length(datshell->args[0])
				+ string_length(datshell->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		freeCharMemDaf(ver_strC);
		return (NULL);
	}
	string_copy(error, datshell->av[0]);
	string_cartenate(error, ": ");
	string_cartenate(error, ver_strC);
	string_cartenate(error, ": ");
	string_cartenate(error, datshell->args[0]);
	string_cartenate(error, ": Illegal number: ");
	string_cartenate(error, datshell->args[1]);
	string_cartenate(error, "\n\0");
	freeCharMemDaf(ver_strC);

	return (error);
}
