#include "me_shell.h"

/*..........................path..........................*/
/*..........................NUM 10 START..........................*/
/**
 * pathCheckFunc1 - check if current dir must be added
 * @path: path env e
 *
 * Return: Pointer to adw PATH
 *
 */

char *pathCheckFunc1(char *path)
{
	char *nupath;
	int x, y, nusize, cnter = 0;

	for (x = 0; path[x]; x++)
	{

		if (path[x] == '=' && path[x + 1] == ':')
			cnter++;
		if (path[x] == ':' && path[x + 1] == ':')
			cnter++;
		if (path[x] == ':' && path[x + 1] == '\0')
			cnter++;
	}
	if (cnter == 0)
		return (0);
	nusize = strLen1(path) + 1 + cnter;
	nupath = malloc(sizeof(char) * nusize);

	for (x = 0, y = 0; x < nusize; x++, y++)
	{
		if (path[y] == '=' && path[y + 1] == ':')
		{
			nupath[x] = pathCheckFunc1_inner(path, nupath, x, y), x++;
			continue;
		}
		if (path[y] == ':' && path[y + 1] == ':')
		{
			nupath[x] = pathCheckFunc1_inner(path, nupath, x, y), x++;
			continue;
		}
		if (path[y] == ':' && path[y + 1] == '\0')
		{
			nupath[x] = pathCheckFunc1_inner(path, nupath, x, y), x++;
			continue;
		}
		nupath[x] = path[y];
	}
	freSingle(path);
	return (nupath);
}
/*..........................NUM 10 BTW..........................*/
/**
 * pathCheckFunc1_inner - cheir must be added
 * @path: path env ble
 * @nupath: path iable
 * @x: path env le
 * @y: path enble
 *
 * Return: Pointer new PATH
 *
 */

char pathCheckFunc1_inner(char *path, char *nupath, int x, int y)
{
	nupath[x] = path[y], nupath[x + 1] = '.';
	return (nupath[x]);
}
/*..........................NUM 10 END..........................*/


/**
 * pathFunc1 - Searche a cmd in PATH
 * @cmd: string contativariable PATH
 * @env: current environment
 * @shellVar: strucng shell info
 *
 * Return: Pointer to aPATH or by itself
 *
 */

char *pathFunc1(char *cmd, char **env, shellDType *shellVar)
{
	char *path, *path2;
	struct stat st;
	char *token, *concaten1, *concaten2, *pthchck1, *delim = ":=";
	int x;

	for (x = 0; cmd[x]; x++)
		if (cmd[x] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (concaten1 = stringConcatFunc(cmd, '\0'));
			else
				return (0);
		}

	path2 = getEnvi("PATH", env);
	(void) shellVar;
	if (!path2)
		return (0);
	path = stringDupl(path2);
	pthchck1 = pathCheckFunc1(path);
	if (pthchck1)
		path = pthchck1;
	token = strTokenFunc(path, delim);
	for (token = strTokenFunc(0, delim); token; token = strTokenFunc(0, delim))
	{
		concaten1 = stringConcatFunc(token, "/");
		concaten2 = stringConcatFunc(concaten1, cmd);
		freSingle(concaten1);
		if (stat(concaten2, &st) == 0)
		{
			/*Found the command in PATH*/
			freSingle(path);
			return (concaten2);
		}
		freSingle(concaten2);
	}

	freSingle(path);
	return (0);
}

/*..........................setenv..........................*/


/**
 * copyDoublePtrFunc - copies an array of strings (double pointer)
 *
 * @p: double poinpy
 * @oldSze: originof P
 * @newSze: size
 *
 * Return: Pointec
 */
char **copyDoublePtrFunc(char **p, int oldSze, int newSze)
{
	char **copy;
	int x, countSize1;

	if (!p && (oldSze == newSze))
		return (NULL);

	if (newSze < oldSze)
	{
		countSize1 = newSze;
		copy = malloc(sizeof(char *) * (countSize1 + 1));
	}
	else
	{
		countSize1 = oldSze;
		copy = malloc(sizeof(char *) * (newSze + 1));
	}
	if (copy == 0)
		return (0);

	if (p)
		for (x = 0; x < countSize1; x++)
		{
			copy[x] = stringDupl(p[x]);
			if (copy[x] == 0)
			{
				x--;
				for (; x >= 0; x--)
					freSingle(copy[x]);
				free(copy);
				return (0);
			}
		}

	/* Add Null in the end */
	copy[newSze] = '\0';

	return (copy);
}

/*..........................NUM 25 START..........................*/
/**
 * strLenDblePtrFunc - calculates length of double pointer (ending in NULL)
 * @s: double pointer
 *
 * Return: Length of doubl
 *
 */
int strLenDblePtrFunc(char **s)
{
	int x = 0;

	if (!s)
		return (0);

	x = strLenDblePtrFunc_inner(s, x);

	return (x);
}
/*..........................NUM 25 BTW..........................*/
