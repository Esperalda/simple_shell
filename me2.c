#include "you_shell.h"

/* ................................NUM 24 START..............................*/
/**
 * errorSetStr - creates str
 * @errn: numb
 * @shell_var: struct
 * @exnum: val
 * Return: 0
 */
int errorSetStr(int errn, shellDType *shell_var, int exnum)
{
	int cnt = shell_var->errnum[0], z = 0;
	char *cmd = shell_var->cmd, **optn = shell_var->options;
	char *hshname = shell_var->hshname;
	char *nustr = "brown", *conc_a = "folu", *conc_b = "foluke", *coluspc = ": ";
	char *err[] = {
		"not found", "Permission denied", "Invalid number",
		"name is NULL, points to string of length 0, or has an '=' chararacter",
		"can't cd(change dire) to ", "Invalid optn ", "Help command error",
		"Error allocating memory", "Wrong Alias", NULL
	};

	errorSetStrFolu1(errn, cnt,  z, hshname, nustr,
				conc_a, conc_b, coluspc, err);

	errorSetStrFolu2(errn, conc_a, conc_b, coluspc, err, cmd);

	if (errn > 1 && errn < 6 && errn != 3)
		conc_b = errorSub(errn, conc_b, optn[1]);
	if (conc_b == NULL)
	{
		printCmt(1);
		return (-1);
	}

	while (conc_b[z] != 0)
		z++;
	write(2, conc_b, z), printCmt(2);
	freeCharFoluke(conc_b);
	shell_var->exitnum[0] = exnum;
	return (0);
}

/* ................................NUM 24 BTW................................*/
/**
 * errorSetStrFolu2 - creates str
 * @errn: numb
 * @conc_a: struct
 * @conc_b: val
 * @coluspc: val
 * @err: val
 * @cmd: val
 * Return: 0
 */
int errorSetStrFolu2(int errn, char *conc_a, char *conc_b,
						char *coluspc, char *err[], char *cmd)
{
	freeCharFoluke(conc_b);
	conc_b = stringCatenator(conc_a, cmd);
	if (!conc_b) /*hsh: cnt: cmd*/
		return (freeCharFoluke(conc_a), printCmt(1), -1);
	freeCharFoluke(conc_a);

	conc_a = stringCatenator(conc_b, coluspc);
	if (!conc_a) /*hsh: cnt: cmd: */
		return (freeCharFoluke(conc_b), printCmt(1), -1);
	freeCharFoluke(conc_b);

	conc_b = stringCatenator(conc_a, err[errn]);
	if (!conc_b) /*hsh: cnt: cmd: error*/
		return (freeCharFoluke(conc_a), printCmt(1), -1);
	freeCharFoluke(conc_a);
	return (0);
}

/* ................................NUM 24 BTW................................*/
/**
 * errorSetStrFolu1 - creates str
 * @errn: numb
 * @cnt: struct
 * @z: val
 * @hshname: val
 * @nustr: val
 * @conc_a: val
 * @conc_b: val
 * @coluspc: val
 * @err: val
 * Return: 0
 */
int errorSetStrFolu1(int errn, int cnt, int  z, char *hshname, char *nustr,
				char *conc_a, char *conc_b, char *coluspc, char *err[])
{
	conc_a = stringCatenator(hshname, coluspc);
	if (!conc_a) /*hsh: */
		return (printCmt(1), -1);

	if (errn == 7) /* Alloc Error */
		errorSetStrFolu(errn, z, conc_a, conc_b, err);

	nustr = intToAlp(cnt);
	if (!nustr)  /* number to string */
		return (freeCharFoluke(conc_a), printCmt(1), -1);

	conc_b = stringCatenator(conc_a, nustr);
	if (!conc_b) /*hsh: cnt*/
	{
		printCmt(1);
		return (freeCharFoluke(conc_a), freeCharFoluke(nustr),  -1);
	}
	freeCharFoluke(conc_a), freeCharFoluke(nustr);

	conc_a = stringCatenator(conc_b, coluspc);
	if (!conc_a) /*hsh: cnt: */
		return (freeCharFoluke(conc_b), printCmt(1), -1);
	return (0);
}


/* ................................NUM 24 BTW................................*/
/**
 * errorSetStrFolu - creates str
 * @errn: numb
 * @z: struct
 * @conc_a: val
 * @conc_b: val
 * @err: val
 * Return: 0
 */
int errorSetStrFolu(int errn, int z, char *conc_a, char *conc_b, char *err[])
{
		conc_b = stringCatenator(conc_a, err[errn]); /*hsh: cnt: error*/
		if (!conc_b)
			return (freeCharFoluke(conc_a), printCmt(1), -1);
		freeCharFoluke(conc_a);
		while (conc_b[z] != 0)
			z++;
		write(2, conc_b, z), printCmt(2);
		freeCharFoluke(conc_b);
		return (0);
}
/* ................................NUM 24 END................................*/


/* ................................NUM 27 START..............................*/
/**
 * errorSub - extra modes
 * @errn: number
 * @conc_b: error
 * @optn: cmd
 * Return: pointer
 */
char *errorSub(int errn, char *conc_b, char *optn)
{
	char *conc_a = "foluke", *coluspc = ": ";

	if (errn == 2) /* exit error */
	{
		errorSub2(conc_a, conc_b, optn, coluspc);
	}
	if (errn > 3) /* Errors with options at end */
	{
		errorSub1(conc_a, conc_b, optn);
	}
	return (conc_b);
}

