#include "header.h"

/**
 * exchange_characterDafNest - swaps
 *
 * @input: inpu
 * @i: type
 * @chkgn: type
 * Return: swapped
 */

char *exchange_characterDafNest(char *input, int i, int chkgn)
{
	if (chkgn == 1)
	{
		if (input[i + 1] != '|')
			input[i] = 16;
		else
			i++;
	}
	else if (chkgn == 2)
	{
		if (input[i + 1] != '&')
			input[i] = 12;
		else
			i++;
	}
	else
	{
		input[i] = (input[i] == 16 ? '|' : input[i]);
		input[i] = (input[i] == 12 ? '&' : input[i]);
	}
	return (input);
}

/* .........................NUM 14 END.........................*/

/* .........................NUM 15 START.......................*/

/**
 * undo_stringForRev - reverses
 * @s: input
 */

void undo_stringForRev(char *s)
{
	int count = 0, i, j = 0;
	char *str, temp = 'A';

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (i = 0; i < (count - 1); i++)
	{
		undo_stringForRevDaf(i, j, str, temp);
	}
}

/* .........................NUM 15 BTW.........................*/

/**
 * undo_stringForRevDaf - reverses
 * @i: input
 * @j: input
 * @str: input
 * @temp: input
 */

void undo_stringForRevDaf(int i, int j, char *str, char temp)
{
	for (j = i + 1; j > 0; j--)
	{
		undo_stringForRevDafNest(j, str, temp);
	}
}

/* .........................NUM 15 BTW.........................*/

/**
 * undo_stringForRevDafNest - reverses
 * @j: input
 * @str: input
 * @temp: input
 */

void undo_stringForRevDafNest(int j, char *str, char temp)
{
	temp = *(str + j);
	*(str + j) = *(str + (j - 1));
	*(str + (j - 1)) = temp;
}

/* .........................NUM 15 END.........................*/

/**
 * change_dir_ftp - changes
 * @datshell: data
 */

void change_dir_ftp(data_shell *datshell)
{
	char pwd[PATH_MAX], *dir, *copy_pwdir, *copy_string_tok_pwd;

	getcwd(pwd, sizeof(pwd));
	copy_pwdir = _strdup(pwd);
	prepareEnvron("OLDPWD", copy_pwdir, datshell);
	dir = datshell->args[1];
	if (stringcompare(".", dir) == 0)
	{
		prepareEnvron("PWD", copy_pwdir, datshell);
		freeCharMemDaf(copy_pwdir);
		return;
	}
	if (stringcompare("/", copy_pwdir) == 0)
	{
		freeCharMemDaf(copy_pwdir);
		return;
	}
	copy_string_tok_pwd = copy_pwdir;
	undo_stringForRev(copy_string_tok_pwd);
	copy_string_tok_pwd = stringtok(copy_string_tok_pwd, "/");
	if (copy_string_tok_pwd != NULL)
	{
		copy_string_tok_pwd = stringtok(NULL, "\0");

		if (copy_string_tok_pwd != NULL)
			undo_stringForRev(copy_string_tok_pwd);
	}
	if (copy_string_tok_pwd != NULL)
	{
		chdir(copy_string_tok_pwd);
		prepareEnvron("PWD", copy_string_tok_pwd, datshell);
	}
	else
	{
		chdir("/");
		prepareEnvron("PWD", "/", datshell);
	}
	datshell->status = 0;
	freeCharMemDaf(copy_pwdir);
}
