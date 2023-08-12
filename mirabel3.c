#include "header.h"

/* .........................NUM 6 START.........................*/
/**
 * dis_stx_error - prints
 * @datshell: data
 * @input: input
 * @i: data
 * @bool: input
 */
void dis_stx_error(data_shell *datshell, char *input, int i, int bool)
{
	char *msges = NULL, *msges_two = "mirabel", *msges_three = "dafe",
			*error, *counter = "dafe-mirabel";
	int length = 0, chk;

	if (input[i] == ';')
	{
		if (bool == 0)
		{
			chk = 1;
			dis_stx_errorDaf(input, i, chk);
		}
		else
		{
			chk = 2;
			dis_stx_errorDaf(input, i, chk);
		}
	}
	if (input[i] == '|')
	{
		chk = 3;
		dis_stx_errorDaf(input, i, chk);
	}
	if (input[i] == '&')
	{
		chk = 4;
		dis_stx_errorDaf(input, i, chk);
	}
	dis_stx_errorDafIn2(datshell, msges, msges_two,
					msges_three, length, counter);
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		freeCharMemDaf(counter);
		return;
	}
	dis_stx_errorDafIn(datshell, msges, msges_two,
					msges_three, error, counter);
	write(STDERR_FILENO, error, length);
	freeCharMemDaf(error);
	freeCharMemDaf(counter);
}

/* .........................NUM 6 BTW...........................*/
/**
 * dis_stx_errorDafIn2 - prints
 * @datshell: data
 * @msges: input
 * @msges_two: data
 * @msges_three: input
 * @length: data
 * @counter: input
 */
void dis_stx_errorDafIn2(data_shell *datshell, char *msges, char *msges_two,
					char *msges_three, int length, char *counter)
{
	msges_two = print_message('s');
	msges_three = print_message('u');
	counter = autIToAlph(datshell->counter);
	length = string_length(datshell->av[0]) + string_length(counter);
	length += string_length(msges) + string_length(msges_two)
					+ string_length(msges_three) + 2;
}

/* .........................NUM 6 BTW...........................*/
/**
 * dis_stx_errorDafIn - prints
 * @datshell: data
 * @msges: input
 * @msges_two: data
 * @msges_three: input
 * @error: index
 * @counter: a
 */
void dis_stx_errorDafIn(data_shell *datshell, char *msges, char *msges_two,
					char *msges_three, char *error, char *counter)
{
	string_copy(error, datshell->av[0]);
	string_cartenate(error, ": ");
	string_cartenate(error, counter);
	string_cartenate(error, msges_two);
	string_cartenate(error, msges);
	string_cartenate(error, msges_three);
	string_cartenate(error, "\0");
}
/* .........................NUM 6 BTW...........................*/

/**
 * dis_stx_errorDaf - print
 * @input: inpu
 * @i: dat
 * @chk: inpu
 * Return: char
 */
char *dis_stx_errorDaf(char *input, int i, int chk)
{
	char *Innmsg;

	if (chk == 1)
		Innmsg = (input[i + 1] == ';' ? ";;" : ";");
	else if (chk == 1)
		Innmsg = (input[i - 1] == ';' ? ";;" : ";");
	else if (chk == 1)
		Innmsg = (input[i + 1] == '|' ? "||" : "|");
	else
		Innmsg = (input[i + 1] == '&' ? "&&" : "&");
	return (Innmsg);
}

/* .........................NUM 6 END...........................*/

/**
 * confirm_stx_error - intermediate
 *
 * @datshell: data
 * @input: input
 * Return: 1
 */

int confirm_stx_error(data_shell *datshell, char *input)
{
	int begn = 0, f_char = 0, i = 0;

	f_char = basc_chararacter(input, &begn);
	if (f_char == -1)
	{
		dis_stx_error(datshell, input, begn, 0);
		return (1);
	}

	i = error_separator_OP(input + begn, 0, *(input + begn));
	if (i != 0)
	{
		dis_stx_error(datshell, input, begn + i, 1);
		return (1);
	}
	return (0);
}



