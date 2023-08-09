#include "you_shell.h"

/* ................................NUM 17 BTW................................*/
/**
 * hlpAliasFol - prints hel
 */
void hlpAliasFol(void)
{
	putsFunctn("alias: alias alias [name[='val1'] ...]\n");
	putsFunctn("    Define or display aliases.\n\n");
	putsFunctn("    Without arguments, `alias' prints the list of aliases ");
	putsFunctn("    in the reusable\n");
	putsFunctn("    form `alias NAME=VALUE' on standard output.\n\n");
	putsFunctn("     Otherwise, an alias is defined for each NAME whose ");
	putsFunctn("    VALUE is given.\n");
	putsFunctn("    A trailing space in VALUE causes the next word to ");
	putsFunctn("    be checked for\n");
	putsFunctn("    alias substitution when the alias is expanded.\n\n");
	putsFunctn("    Exit Status:\n");
	putsFunctn("    alias returns true unless a NAME is supplied for which ");
	putsFunctn("    no alias has been\n");
	putsFunctn("    defined.\n");
}
/* ................................NUM 17 END................................*/


/* ................................NUM 18 START..............................*/
/**
 * prntHlp - prints hel
 */
void prntHlp(void)
{
	prntHlpFol();
}
/* ................................NUM 18 BTW................................*/
/**
 * prntHlpFol - prints hel
 */
void prntHlpFol(void)
{
	putsFunctn("Shell HSH, version 1.0(1)-release (x86_64-pc-linux-gnu)\n");
	putsFunctn("These shell commands are defined internally.\n");
	putsFunctn("Type `help' to see this list.\n");
	putsFunctn("Type help  'BUILTIN'' to find out more about ");
	putsFunctn("the function 'BUILTIN'.\n\n");
	putsFunctn(" exit [n]\n");
	putsFunctn(" env\n");
	putsFunctn(" setenv [VARIABLE] [VALUE]\n");
	putsFunctn(" unsetenv [VARIABLE]\n");
	putsFunctn(" cd [DIRECTORY]\n");
	putsFunctn(" help [BUILTIN ...]\n");
	putsFunctn(" alias [name[='val1'] ...]\n");
}
/* ................................NUM 18 END................................*/

/**
 * freeDobleCharPntrFoluke - frees a double pointe
 * @p: double pointer to free
 */
void freeDobleCharPntrFoluke(char **p)
{
	int x, z = 0;

	while (p[z] != 0)
		z++;

	for (x = 0; x < z; x++)
	{
		freeCharFoluke(p[x]);
	}
	free(p);
}

/* ................................NUM 19 START..............................*/
/* ................................NUM 19 BTW................................*/
/* ................................NUM 19 END................................*/
/**
 * cpyDoblePtr - copies an array of string
 *
 * @p: double pointe
 * @oldSize: original siz
 * @nw_size: size of copy
 * Return: Pointer malloec
 */
char **cpyDoblePtr(char **p, int oldSize, int nw_size)
{
	char **copy;
	int x, copSize;

	if (!p && (oldSize == nw_size))
		return (NULL);

	if (nw_size < oldSize)
	{
		copSize = nw_size;
		copy = malloc(sizeof(char *) * (copSize + 1));
	}
	else
	{
		copSize = oldSize;
		copy = malloc(sizeof(char *) * (nw_size + 1));
	}
	if (copy == 0)
		return (0);

	if (p)
		for (x = 0; x < copSize; x++)
		{
			copy[x] = stringDuplicateFunc(p[x]);
			if (copy[x] == 0)
			{
				x--;
				for (; x >= 0; x--)
					freeCharFoluke(copy[x]);
				freeDobleCharPntrFoluke(copy);
				return (0);
			}
		}
	/* Add Null in the end */
	copy[nw_size] = '\0';

	return (copy);
}
