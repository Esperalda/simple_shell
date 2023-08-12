#include "header.h"

/**
 * authenticator_asstDaf - Hlp
 * @hlp: lastarg
 */

void authenticator_asstDaf(char *hlp)
{
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, hlp, string_length(hlp));
}

/* .........................NUM 3 END...........................*/

/* .........................NUM 4 START.........................*/
/**
 * authenticator_asst_alias - Hlp
 */

void authenticator_asst_alias(void)
{
	char *hlp = "alias: alias [-p] [name[=value]...]\n";

	 authenticator_asst_aliasDaf(hlp);
}
/* .........................NUM 4 BTW.........................*/
/**
 * authenticator_asst_aliasDaf - Hlp
 *  * @hlp: lastarg
 */

void authenticator_asst_aliasDaf(char *hlp)
{
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, hlp, string_length(hlp));
}

/* .........................NUM 4 END...........................*/


/* .........................NUM 5 START.........................*/

/**
 * error_separator_OP - finds
 *
 * @input: input
 * @i: index
 * @lastarg: lastarg
 * Return: index
 */
int error_separator_OP(char *input, int i, char lastarg)
{
	int count, chk, ret;

	count = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
	{
		ret = error_separator_OP(input + 1, i + 1, lastarg);
		return (ret);
	}

	if (*input == ';')
		if (lastarg == '|' || lastarg == '&' || lastarg == ';')
			return (i);

	if (*input == '|')
	{
		chk = 1;
		ret = error_separator_OPDaf(input, i, lastarg, count, chk);
		return (ret);
	}

	if (*input == '&')
	{
		chk = 2;
		ret = error_separator_OPDaf(input, i, lastarg, count, chk);
		return (ret);
	}
	ret = error_separator_OP(input + 1, i + 1, *input);

	return (ret);
}

/* .........................NUM 5 BTW...........................*/
/**
 * error_separator_OPDaf - finds
 *
 * @input: input
 * @i: index
 * @lastarg: lastarg
 * @count: lastarg
 * @chk: lastarg
 * Return: index
 */
int error_separator_OPDaf(char *input, int i, char lastarg, int count, int chk)
{
	int a = 0, b = 0, c;

	if (chk == 1)
	{
		if (lastarg == ';' || lastarg == '&')
			return (i);

		if (lastarg == '|')
		{
			count = duplicate_character(input, 0);
			if (count == 0 || count > 1)
				a = 4;
		}
	}

	else
	{
		if (lastarg == ';' || lastarg == '|')
			return (i);

		if (lastarg == '&')
		{
			count = duplicate_character(input, 0);
			if (count == 0 || count > 1)
				b = 8;
		}
	}
	c = a + b;
	c = i;
	return (c);
}

/* .........................NUM 5 END...........................*/
