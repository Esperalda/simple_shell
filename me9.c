#include "you_shell.h"

/* ................................NUM 22 START..............................*/
/**
 * printCmt - Reverses string
 * @chk: str to rev
 */
void printCmt(int chk)
{
	switch (chk)
	{
		case 1:
			write(2, "Memory Error", 22);
			break;
		case 2:
			write(2, "\n", 1);
			break;
		case 3:
			write(2, "Environment is Null\n", 36);
			break;
		case 4:
			write(2, "Invalid VALUE\n", 14);
			break;
		case 5:
			write(2, "Invalid VARIABLE\n", 17);
			break;
		case 6:
		    write(2, "Please provide an argument\n", 27);
			break;
		case 7:
		    write(2, "cd: too many arguments\n", 23);
			break;
		case 8:
		    write(1, "prompt by foluke $ ", 19);
			break;
		case 9:
		    write(2, "Fork Error", 10);
			break;
		case 10:
			write(1, "\nprompt by foluke $ ", 20);
			break;
		case 11:
			write(1, "\n", 1);
			break;
		case 12:
			write(2, "VARIABLE not found\n", 19);
			break;
	}
}
/* ................................NUM 22 END................................*/



/* ................................NUM 10 BTW................................*/
/**
 * pthChckerFol - check current dir
 * @path: path
 * @nwpath: path
 * @x: path
 * @y: path
 * Return: Pointer to adress of new PAT
 */

char pthChckerFol(char *path, char *nwpath, int x, int y)
{
	nwpath[x] = path[y], nwpath[x + 1] = '.', x++;
	return (nwpath[x]);
}
/* ................................NUM 10 END................................*/


/**
 * searchPath - Searches for a cmd
 * @cmd: string
 * @env: current environment
 * @shell_var: stru
 * Return: Point
 */

char *searchPath(char *cmd, char **env, shellDType *shell_var)
{
	char *path, *path2;
	struct stat st;
	char *token, *concat, *concatenat2, *pathChck, *delim = ":=";
	int x;

	for (x = 0; cmd[x]; x++)
		if (cmd[x] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (concat = stringCatenator(cmd, '\0'));
			else
				return (0);
		}

	path2 = fetchEnviron("PATH", env);
	(void) shell_var;
	if (!path2)
		return (0);
	path = stringDuplicateFunc(path2);
	pathChck = pthChcker(path);
	if (pathChck)
		path = pathChck;
	token = stringTokenizeFunc(path, delim);
	for (token = stringTokenizeFunc(0, delim);
		token; token = stringTokenizeFunc(0, delim))
	{
		concat = stringCatenator(token, "/");
		concatenat2 = stringCatenator(concat, cmd);
		freeCharFoluke(concat);
		if (stat(concatenat2, &st) == 0)
		{
			/*Found the command in PATH*/
			free(path);
			return (concatenat2);
		}
		freeCharFoluke(concatenat2);
	}

	freeCharFoluke(path);
	return (0);
}




/**
 * putsFunctn - prints string to std output
 * @s: strin
 */
void putsFunctn(char *s)
{
	write(1, s, stringLengthFunc(s));
}




/* ................................NUM 11 START..............................*/
/**
 * hlpExitFunc - prints hel
 */
void hlpExitFunc(void)
{
	hlpExitFuncFol();
}
