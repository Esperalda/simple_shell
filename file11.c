#include "shell.h"

/*..........................NUM 17 START..........................*/
/**
 * helpEnv1 - prints help of t in
 *
 * Return: No Return
 */
void helpEnv1(void)
{
	helpEnv1_inner();
}
/*..........................NUM 17 BTW..........................*/
/**
 * helpEnv1_inner - prints heluilt in
 *
 * Return: No Return
 */
void helpEnv1_inner(void)
{
	putsToStd("env: env\n");
	putsToStd("    prints the current environment.\n\n");
	putsToStd("    Has no options\n");
}
/*..........................NUM 17 BTW..........................*/
/*..........................NUM 17 END..........................*/


/*..........................NUM 18 START..........................*/
/**
 * helpSetenv1 - prints help v built in
 *
 * Return: No Return
 */
void helpSetenv1(void)
{
	helpSetenv1_inner();
}
/*..........................NUM 18 BTW..........................*/
/**
 * helpSetenv1_inner - prinp of setenv built in
 *
 * Return: No Return
 */
void helpSetenv1_inner(void)
{
	putsToStd("setenv: setenv [VARIABLE] [VALUE]\n");
	putsToStd("    Initializes a new environment variable, ");
	putsToStd("    or modifies an existing one.\n\n");
	putsToStd("    VARIABLE must not have the character '='.\n");
	putsToStd("    If no arguments are given, setenv prints ");
	putsToStd("    the current environment.\n");
}
/*..........................NUM 18 BTW..........................*/
/*..........................NUM 18 END..........................*/


/*..........................NUM 19 START..........................*/
/*..........................NUM 19 BTW..........................*/
/*..........................NUM 19 BTW..........................*/
/*..........................NUM 19 END..........................*/
/**
 * helpCmdFunc1 - help of ands
 * @shellVar: struinfo
 *
 * Return: 1 if succesful, -1 if fail
 */
ssize_t helpCmdFunc1(shellDType *shellVar)
{
	int check = 1, bcheck = 0;
	helps_s help[] = {
		{"exit", helpExit1},
		{"env", helpEnv1},
		{"setenv", helpSetenv1},
		{"unsetenv", helpUnSetEnv1},
		{"cd", helpCdFunc1},
		{"help", helpHelpFunc1},
		{"alias", helpAliasFunc}
	};

	int i = 7;
	int p = 1;

	for (; shellVar->options[p]; p++, i = 7)
	{
		while (i--)
			if (!stringCompareFunc(shellVar->options[p], help[i].built))
				help[i].h(), bcheck = 1;
	}
	if (shellVar->options[1] == NULL)
	{
		printsHelpFunc1();
		bcheck = 1;
	}
	if (bcheck == 0)
	{
		check = -1;
		errorStrFunc(6, shellVar, 2);
	}

	free(shellVar->options);
	return (check);
}
