#include "you_shell.h"

/**
 * isDigitFunc - checks if a character is a digit num
 * @c: character
 * Return: 1
 *
 */
int isDigitFunc(int c)
{
	return ((c >= 48 && c <= 57) ? 1 : 0);
}

/**
 * isNumba - checks if a str has numbers
 * @s: str
 * Return: 1
 */
int isNumba(char *s)
{
	for (; *s; s++)
		if (!isDigitFunc(*s))
			return (0);
	return (1);
}

/* ................................NUM 28 START..............................*/
/* ................................NUM 28 BTW................................*/
/* ................................NUM 28 END................................*/
/**
 * chckInputFunc - checks for input
 * @ac: numb of main arguments
 * @av: main arg
 * @bufsize: size of buffer
 * @buffer: buffer
 * @shell_var: struct of shell info
 * Return: On success 1.
 */
char **chckInputFunc(int ac, char **av, size_t *bufsize,
		   char **buffer, shellDType *shell_var)
{
	ssize_t charctrs;
	char **command;
	int exitnum;

	if (ac == 1)
	{
		if (isatty(STDIN_FILENO))
			printCmt(8);
		charctrs = getline(buffer, bufsize, stdin);

		if (charctrs == -1)
		{
			exitnum = shell_var->exitnum[0];
			freeCharFoluke(*buffer);
			if (*(shell_var->envCpy))
				freeDobleCharPntrFoluke(*(shell_var->envCpy));
			free(shell_var);
			if (isatty(STDIN_FILENO))
				printCmt(2);
			exit(exitnum);
		}
		if (**buffer == '#' || !charctrs || **buffer == '\n')
			return (NULL);
		*buffer = delComnt(*buffer);
		command = fetchParam(*buffer, shell_var);
	}
	else
	{
		command = malloc(sizeof(char *) * (ac - 1));
		if (!command)
		{
			errorSetStr(7, shell_var, 1);
			return (NULL);
		}

		command[ac - 1] = '\0';
		while (ac--)
			command[ac - 1] = av[ac];
	}
	return (command);
}


/* ................................NUM 7 START..............................*/

/**
 * delComnt - deletes a commnet
 * @str: str
 * Return: pointer
 */
char *delComnt(char *str)
{
	char *C_org = str;

	for (; str && *str; str++)
		if (*str == '#' && *(str - 1) == ' ')
		{
			*str = delComntFol(*str);
			break;
		}

	return (C_org);
}
/* ................................NUM 7 BTW................................*/
/**
 * delComntFol - deletes a commnet
 * @str: str
 * Return: pointer
 */
char delComntFol(char str)
{
	str = '\0';
	return (str);
}
/* ................................NUM 7 END................................*/
