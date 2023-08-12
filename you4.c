#include "me_shell.h"

/**
 * setEnvCmdFunc - built ietenv
 * @shellVar: struct conll info
 *
 * Return: 1 if succfail
 */
ssize_t setEnvCmdFunc(shellDType *shellVar)
{
	char **nEnv;
	char *variable = NULL;
	char *valuel = NULL;

	if (shellVar->options[1])
	{
		variable = shellVar->options[1];
		if (!shellVar->options[2])
		{
			cmdMore(shellVar, 2);
		}
		else
			valuel = shellVar->options[2];

	}
	if (variable == 0)
	{
		cmdMore(shellVar, 3);
	}

	nEnv = setEnvFunc1(*(shellVar->envCpy), variable, valuel, shellVar);

	if (nEnv == 0)
	{
		free(shellVar->options);
		return (-1);
	}

	*(shellVar->envCpy) = nEnv;
	free(shellVar->options);
	return (1);
}

/**
 * unSetEnvCmdFunc - built  env
 * @shellVar: struct c ll info
 *
 * Return: 1 if succesful,  il
 */
ssize_t unSetEnvCmdFunc(shellDType *shellVar)
{
	char **nEnv;
	char *variable = NULL;

	if (shellVar->options[1])
		variable = shellVar->options[1];
	else
	{
		shellVar->exit_Num[0] = 2;
		printCmt(6);
		return (free(shellVar->options), -1);
	}

	if (variable == 0)
	{
		free(shellVar->options);
		return (1);
	}

	nEnv = unSetEnvFunf(*(shellVar->envCpy), variable, shellVar);

	if (nEnv == 0 && shellVar->unsetnull[0] == 0)
	{
		free(shellVar->options);
		shellVar->exit_Num[0] = 2;
		return (-1);
	}

	*(shellVar->envCpy) = nEnv;
	free(shellVar->options);
	return (1);
}

/**
 * checkIfBuiltinFunc - checks if cmd is a built in
 * @shellVar: struct conta
 * Return: On fail 0
 */
ssize_t checkIfBuiltinFunc(shellDType *shellVar)
{
	builtIn_s ops[] = {
		{"exit", exitCmdFunc},
		{"env", envCmdFunc},
		{"setenv", setEnvCmdFunc},
		{"unsetenv", unSetEnvCmdFunc},
		{"cd", cdCmdFunc},
		{"help", helpCmdFunc1}
	};

	int x = 6, builtcheck; /* lenght of ops array */

	while (x--)
		if (!stringCompareFunc(shellVar->cmd, ops[x].cmd))
		{
			shellVar->errnum[0] += 1;
			builtcheck = ops[x].f(shellVar);
			if (builtcheck == 1)
				shellVar->exit_Num[0] = 0;
			return (builtcheck);
		}

	return (0);
}

/*..........................built_ins2..........................*/
/*..........................NUM 14 START..........................*/
/**
 * auxChnDir2 - auxiliary function of cd built in
 * @shellVar: struct con shell info
 * @curDire: current d
 *
 * Return: pointer to  if fail
 */
char *auxChnDir2(shellDType *shellVar, char *curDire)
{
	char *home, *dir = NULL;

	(void) curDire;
	home = getEnvi("HOME", *(shellVar->envCpy));
	if (home)
		dir = auxChnDir2_inner(home);

	return (dir);
}

/*..........................NUM 14 BTW..........................*/
/**
 * auxChnDir2_inner - auxiliary function of cd built in
 * @home: struct contain info
 * Return: pointer to H if fail
 */
char *auxChnDir2_inner(char *home)
{
	return (home + 5);
}
/*..........................NUM 14 BTW..........................*/
