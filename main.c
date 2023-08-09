#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include "shell.h"
/**
 * main - Shell Program
 * @ac: count of input parameters to program
 * @av: parameters as input to program
 * @env: unix environment
 *
 * Return: Should only exit through shell inputs
 */
int main(int ac, char **av, char **env)
{
	size_t bufsize = 0;
	char **command, *pathCmd, *buffer = NULL;
	shellDType *shellVar;
	int errn = 0, exnum = 0, relation = 0, run_able = 0, sizeEnv, enul = 0;
	ssize_t isBuiltIn;

	if (ac > 1 || av == NULL)
		write(2, "Please run with no arguments\n", 29), exit(127);
	signal(SIGINT, sigHandlr);
	sizeEnv = strLenPtr(env);
	env = cpyDoblePtr(env, sizeEnv, sizeEnv);
	shellVar = shellStructDef(av[0], &errn, &exnum, &relation, &run_able, &env, &enul);
	while (1)
	{
		command = NULL;
		command = chckInputFunc(ac, av, &bufsize, &buffer, shellVar);
		if (!command)
			continue;
		addComnd(shellVar, buffer, command[0], command);
		isBuiltIn = chckBuiltIn(shellVar);
		if (isBuiltIn == -1 || isBuiltIn == 1)
			continue;
		pathCmd = searchPath(command[0], env, shellVar);
		addPath2Comnd(shellVar, pathCmd);
		if (!pathCmd)
		{
			free(command);
			shellVar->errnum[0] += 1, errorSetStr(0, shellVar, 127);
			continue;
		}
		else if (access(pathCmd, X_OK) == -1)
			errorSetStr(1, shellVar, 126);
		else
			excuteCmd(pathCmd, command, env, shellVar);
		free(command);
		free(pathCmd);

	}
	freeDobleCharPntrFoluke(*(shellVar->envCpy)), free(shellVar);
	return (0);
}
/**
 * shellStructDef - initializes shell struct
 * @argv0: name of executable
 * @errn: number of error message
 * @exnum: exit number of shell
 * @relation: relation for logical operators
 * @run_able: if cmd should be run
 * @env: current environment
 * @unsetnull: check for setting environment to NULL
 *
 * Return: Pointer to struct
 *
 */
shellDType *shellStructDef(char *argv0, int *errn, int *exnum,
		    int *relation, int *run_able, char ***env, int *unsetnull)
{
	shellDType *shellpack;

	shellpack = malloc(sizeof(struct shellDType));
	if (shellpack == 0)
		return (write(2, "Memory Error", 22), NULL);
	shellpack->hshname = argv0;
	shellpack->buffer = NULL;
	shellpack->cmd = NULL;
	shellpack->options = NULL;
	shellpack->path = NULL;
	shellpack->errnum = errn;
	shellpack->exitnum = exnum;
	shellpack->relation = relation;
	shellpack->run_able = run_able;
	shellpack->envCpy = env;
	shellpack->unsetnull = unsetnull;

	return (shellpack);
}
/**
 * addComnd - adds values to shell struct
 * @shellVar: shell struct
 * @buffer: string written after prompt
 * @command: command written after prompt
 * @parameters: parameters of command
 *
 * Return: No return
 */
void addComnd(shellDType *shellVar, char *buffer, char *command, char **parameters)
{
	shellVar->buffer = buffer;
	shellVar->cmd = command;
	shellVar->options = parameters;
}

/**
 * addPath2Comnd - initializes path value of struct
 * @shellVar: shell struct
 * @pathCmd: path of cmd written after propmpt
 *
 * Return: No Return
 */
void addPath2Comnd(shellDType *shellVar, char *pathCmd)
{
	shellVar->path = pathCmd;
}
