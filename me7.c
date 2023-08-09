#include "you_shell.h"

/**
 * excuteCmd - creates a child prcss to execute a cmd
 * @program: command
 * @command: arg
 * @env: curr env
 * @shell_var: struct
 * Return: pointer
 */
int excuteCmd(char *program, char *command[], char **env,
			shellDType *shell_var)
{
	pid_t prcss, sttus;
	int execSts = 0, wait1_Sts = 0;

	prcss = fork();
	signal(SIGINT, sigHandlr2);
	if (prcss == -1)
	{
		printCmt(9);
		exit(-1);
	}
	if (prcss == 0)
	{

		execSts = execve(program, command, env);
		if (execSts == -1)
		{
			_exit(-1);
		}
	}
	else
	{
		wait1_Sts = wait(&sttus);
		signal(SIGINT, sigHandlr);
		if (wait1_Sts == -1)
			exit(-1);
		if (WEXITSTATUS(sttus) == 0)
			shell_var->exitnum[0] = 0;
		else
			shell_var->exitnum[0] = 2;
	}

	shell_var->errnum[0] += 1;
	return (0);
}


/**
 * fetchEnviron - fetch an environ var
 *
 * @name: name
 * @env: current env
 * Return: pointer to the val1 in the environment, *
 */
char *fetchEnviron(const char *name, char **env)
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


/* ................................NUM 8 START..............................*/
/**
 * memorySet - fills memory
 * @s: memory
 * @b: constant
 * @n: first n byte
 * Return: On success 1.
 */
char *memorySet(char *s, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		s[x] = memorySetFol(s, b, x);
	return (s);
}
/* ................................NUM 8 BTW................................*/
/**
 * memorySetFol - fills memory
 * @s: memory
 * @b: constant
 * @x: first n byte
 * Return: On success 1.
 */
char memorySetFol(char *s, char b, unsigned int x)
{
	s[x] = b;
	return (s[x]);
}
/* ................................NUM 8 END................................*/


/* ................................NUM 9 START..............................*/
/**
 * memoryCopy - copies mem
 * @dest: destination
 * @src: source
 * @n: size of memory
 *
 * Return: Returns memory copied
 */
char *memoryCopy(char *dest, char *src, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		dest[x] = memoryCopyFol(dest, src, x);
	return (dest);
}
/* ................................NUM 9 BTW................................*/
