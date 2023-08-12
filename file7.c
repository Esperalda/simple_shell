#include "me_shell.h"

/*..........................shPrmptInputs..........................*/

/**
 * shPrmptInput - checks for input in after shell prompt
 * @ac: cnter of main ts
 * @av: main arguments
 * @bufsize: size of bufmpt
 * @buffer: buffer in
 * @shellVar: struct fo
 *
 * Return: On success 1.
 * On error, -1 is returno is set appropriately.
 */
char **shPrmptInput(int ac, char **av, size_t *bufsize,
		   char **buffer, shellDType *shellVar)
{
	ssize_t charctrs;
	char **command;
	int exit_Num;

	if (ac == 1)
	{
		if (isatty(STDIN_FILENO))
			printCmt(8);
		charctrs = getline(buffer, bufsize, stdin);

		if (charctrs == -1)
		{
			exit_Num = shellVar->exit_Num[0];
			free(*buffer);
			if (*(shellVar->envCpy))
				freeDbPtrFunc(*(shellVar->envCpy));
			free(shellVar);
			if (isatty(STDIN_FILENO))
				printCmt(11);
			exit(exit_Num);
		}
		if (**buffer == '#' || !charctrs || **buffer == '\n')
			return (NULL);
		*buffer = delCmntFunc(*buffer);
		command = getParam(*buffer, shellVar);
	}
	else
	{
		command = malloc(sizeof(char *) * (ac - 1));
		if (!command)
		{
			errorStrFunc(7, shellVar, 1);
			return (NULL);
		}

		command[ac - 1] = '\0';
		while (ac--)
			command[ac - 1] = av[ac];
	}
	return (command);
}

/*..........................NUM 6 START..........................*/
/**
 * delCmntFunc - deletes a commnet insline
 *
 * @str: string to o
 *
 * Return: pointer t
 *
 */
char *delCmntFunc(char *str)
{
	char *org = str;

	for (; str && *str; str++)
		if (*str == '#' && *(str - 1) == ' ')
		{
			*str = delCmntFunc_inner();
			break;
		}

	return (org);
}
/*..........................NUM 6 BTW..........................*/
/**
 * delCmntFunc_inner - deletes a commnide a command line
 * Return: pointer tng
 *
 */
char delCmntFunc_inner(void)
{
	return ('\0');
}
/*..........................NUM 6 END..........................*/


/*..........................execCmdFunc..........................*/
/**
 * execCmdFunc - creates a child prcss to execute a cmd
 *
 * @program: command e executed
 * @command: argum command
 * @env: currentnment
 * @shellVar: struct witnformation
 *
 * Return: pointer to the valvironment,
 * or NULL if there is n
 *
 */
int execCmdFunc(char *program, char *command[], char **env,
						shellDType *shellVar)
{
	pid_t prcss, stat;
	int execveSts = 0, waitSts = 0;

	prcss = fork();
	signal(SIGINT, signalHandlerFunc2);
	if (prcss == -1)
	{
		printCmt(9);
		exit(-1);
	}
	if (prcss == 0)
	{

		execveSts = execve(program, command, env);
		if (execveSts == -1)
		{
			_exit(-1);
		}
	}
	else
	{
		waitSts = wait(&stat);
		signal(SIGINT, signalHandlerFunc);
		if (waitSts == -1)
			exit(-1);
		if (WEXITSTATUS(stat) == 0)
			shellVar->exit_Num[0] = 0;
		else
			shellVar->exit_Num[0] = 2;
	}

	shellVar->errnum[0] += 1;
	return (0);
}

/*..........................getenv..........................*/

/**
 * getEnvi - gets an environment variable
 *
 * @name: name of environiable
 * @env: current en
 * Return: pointer to tin the environment,
 * or NULL if thch
 *
 */
char *getEnvi(const char *name, char **env)
{
	int x, y, check, z = 0;

	if (!env)
		return (NULL);

	while (name[z] != 0)
		z++;

	for (x = 0; env[x] != 0; x++)
	{
		for (check = 0, y = 0; y < z && env[x][y] != 0; y++)
			if (env[x][y] == name[y])
				check++;
		if (check == z && env[x][check] == '=')
			return (env[x]);
	}

	return (NULL);
}

