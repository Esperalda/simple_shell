#include "you_shell.h"

/* ................................NUM 27 BTW................................*/
/**
 * errorSub2 - extra modes
 * @coluspc: number
 * @conc_b: error
 * @optn: cmd
 * @conc_a: cmd
 * Return: pointer
 */
char *errorSub2(char *conc_a, char *conc_b, char *optn, char *coluspc)
{
	conc_a = stringCatenator(conc_b, coluspc);
	if (!conc_a) /*hsh: cnt: cmd: error: */
	{
		printCmt(1);
		return (freeCharFoluke(conc_b), NULL);
	}
	freeCharFoluke(conc_b);

	conc_b = stringCatenator(conc_a, optn);

	if (!conc_b) /*hsh: cnt: cmd: error: optn*/
	{
		printCmt(1);
		return (freeCharFoluke(conc_a), NULL);
	}
	freeCharFoluke(conc_a);
	return ("fol");

}

/* ................................NUM 27 BTW................................*/
/**
 * errorSub1 - extra modes
 * @conc_a: number
 * @conc_b: error
 * @optn: cmd
 * Return: pointer
 */
char *errorSub1(char *conc_a, char *conc_b, char *optn)
{
	conc_a = stringCatenator(conc_b, optn);
	if (!conc_a) /*hsh: cnt: cmd: error optn*/
	{
		printCmt(1);
		return (freeCharFoluke(conc_b), NULL);
	}
	freeCharFoluke(conc_b);
	return (conc_a);
}
/* ................................NUM 27 END................................*/


/**
 * hlpComnd - help of built-in commands
 * @shell_var: struc
 * Return: 1 if succesful, -1 if fail
 */
ssize_t hlpComnd(shellDType *shell_var)
{
	int check = 1, bchck = 0;
	helps_s help[] = {
		{"exit", hlpExitFunc},
		{"env", hlpEnviron},
		{"setenv", hlpSetEnviron},
		{"unsetenv", hlpUnSetEnviron},
		{"cd", cdHlp},
		{"help", hlpHlp},
		{"alias", hlpAlias}
	};

	int i = 7;
	int p = 1;

	for (; shell_var->options[p]; p++, i = 7)
	{
		while (i--)
			if (!stringCompare(shell_var->options[p], help[i].built))
				help[i].h(), bchck = 1;
	}
	if (shell_var->options[1] == NULL)
	{
		prntHlp();
		bchck = 1;
	}
	if (bchck == 0)
	{
		check = -1;
		errorSetStr(6, shell_var, 2);
	}

	free(shell_var->options);
	return (check);
}


/* ................................NUM 14 START..............................*/
/**
 * hlpUnSetEnviron - prints hel
 */
void hlpUnSetEnviron(void)
{
	hlpUnSetEnvironFol();
}
/* ................................NUM 14 BTW................................*/
/**
 * hlpUnSetEnvironFol - prints hel
 */
void hlpUnSetEnvironFol(void)
{
	putsFunctn("unsetenv: unsetenv [VARIABLE]\n");
	putsFunctn("    Initializes a new environment var1, or ");
	putsFunctn("    modifies an existing one.\n\n");
	putsFunctn("    VARIABLE must not have the character '='.\n");
	putsFunctn("    If no arguments are given, setenv prints the current ");
	putsFunctn("    environment.\n");
}
/* ................................NUM 14 END................................*/
