#include "you_shell.h"

/*..........................NUM 14 END..........................*/


/*..........................NUM 15 START..........................*/
/**
 * auxChnDir - auxiliary function of cd built in
 * @shellVar: struct contll info
 * @curDire: the current
 *
 * Return: Pointer to dif fail
 */
char *auxChnDir(shellDType *shellVar, char *curDire)
{
	char *oldPwd_b = NULL, *oldPwd_a = NULL, *dir = NULL;

	if (shellVar->options[1] && shellVar->options[2])
	{
		auxChnDir_inner(shellVar, curDire);
		return (dir);
	}

	oldPwd_b = stringDupl(getEnvi("OLDPWD", *(shellVar->envCpy)));
	if (oldPwd_b)
		oldPwd_a = stringDupl(oldPwd_b + 7), freSingle(oldPwd_b);
	if (!oldPwd_b)
	{
		oldPwd_a = stringDupl(curDire);
		/* free(oldPwd_a), free(shellVar->options), free(curDire); */
		/* return (shellVar->exit_Num[0] = 2, NULL); */
	}

	dir = oldPwd_a;

	return (dir);
}
/*..........................NUM 15 BTW..........................*/
/**
 * auxChnDir_inner - auxiliary function of cd built in
 * @shellVar: struct shell info
 * @curDire: the cutory
 *
 * Return: Pointer toL if fail
 */
void auxChnDir_inner(shellDType *shellVar, char *curDire)
{
	printCmt(7);
	shellVar->exit_Num[0] = 2;
	free(shellVar->options);
	freSingle(curDire);
}
/*..........................NUM 15 BTW..........................*/
/*..........................NUM 15 END..........................*/



/**
 * cdCmdFunc - builnd cd
 * @shellVar: struct
 * Return: 1 if succif fail
 */
ssize_t cdCmdFunc(shellDType *shellVar)
{
	char *curDire = NULL, *dir = NULL, **nEnv, *oldPwd_a = NULL;
	int exit = 1, chcka = 1, chcka_minus = 0;

	curDire = getcwd(NULL, 4096);
	if (!curDire)
		return (errorStrFunc(4, shellVar, 2), free(shellVar->options), -1);
	if (!shellVar->options[1] ||
			(shellVar->options[1] && (!stringCompareFunc(shellVar->options[1], "~"))))
	{
		dir = auxChnDir2(shellVar, curDire);
		if (!dir)
			return (free(shellVar->options), freSingle(curDire), 1);
	}
	else
		if (!stringCompareFunc(shellVar->options[1], "-"))
		{
			dir = auxChnDir(shellVar, curDire);
			if (!dir)
				return (free(shellVar->options), freSingle(curDire), 1);
			chcka_minus = 1;
		}
		else
			dir = shellVar->options[1];
	if (dir)
		chcka = chdir(dir);
	if (chcka == 0 && chcka_minus == 1)
		write(1, dir, strLen1(dir)), printCmt(11);
	if (chcka != 0)
		errorStrFunc(4, shellVar, 2), exit = -1;
	else
	{
		nEnv = setEnvFunc1(*(shellVar->envCpy), "PWD", dir, shellVar);
		*(shellVar->envCpy) = nEnv;
		nEnv = setEnvFunc1(*(shellVar->envCpy), "OLDPWD", curDire, shellVar);
		*(shellVar->envCpy) = nEnv;
	}
	free(shellVar->options), freSingle(curDire), freSingle(oldPwd_a);
	if (chcka_minus == 1)
		freSingle(dir);
	return (exit);
}


/*..........................built_ins3..........................*/
/*..........................NUM 4 START..........................*/
/**
 * powerFunc - gets the result of base to ower
 * @base: base decimal
 * @pot: power
 *
 * Return: result
 */
long powerFunc(long base, long pot)
{
	long x = 0;
	long res = 1;

	for (x = 0; x < pot; x++)
		powerFunc_inner(base, res);

	return (res);
}
/*..........................NUM 4 BTW..........................*/
/**
 * powerFunc_inner - gets the result of base to ower
 * @base: base decim
 * @res: power
 *
 * Return: result
 */
long powerFunc_inner(long base, long res)
{
	res *= base;
	return (res);
}
/*..........................NUM 4 END..........................*/
