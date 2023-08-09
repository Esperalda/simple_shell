#include "you_shell.h"

/* ................................NUM 3 START..............................*/

/**
 * secAuxCd - auxiliary built in func of cd
 * @shell_var: struct
 * @cur_dir: current dir
 * Return: pointer
 */
char *secAuxCd(shellDType *shell_var, char *cur_dir)
{
	char *home, *dire = NULL;

	(void) cur_dir;
	home = fetchEnviron("HOME", *(shell_var->envCpy));
	if (home)
		dire = secAuxCdFol(home, dire);

	return (dire);
}
/* ................................NUM 3 BTW................................*/
/**
 * secAuxCdFol - auxiliary built in func of cd
 * @home: struct
 * @dire: current dir
 * Return: pointer
 */
char *secAuxCdFol(char *home, char *dire)
{
	dire = home + 5;
	return (dire);
}
/* ................................NUM 3 END................................*/


/**
 * firstAuxCd - auxiliary built in func of cd
 * @shell_var: struct
 * @cur_dir: current dir
 * Return: Pointe
 */
char *firstAuxCd(shellDType *shell_var, char *cur_dir)
{
	char *oldpwd2 = NULL, *oldpwDir = NULL, *dire = NULL;

	if (shell_var->options[1] && shell_var->options[2])
	{
		printCmt(7);
		shell_var->exitnum[0] = 2;
		free(shell_var->options);
		freeCharFoluke(cur_dir);
		return (dire);
	}

	oldpwd2 = stringDuplicateFunc(fetchEnviron("OLDPWD", *(shell_var->envCpy)));
	if (oldpwd2)
		oldpwDir = stringDuplicateFunc(oldpwd2 + 7), free(oldpwd2);
	if (!oldpwd2)
	{
		oldpwDir = stringDuplicateFunc(cur_dir);
		/* free(oldpwDir), free(shell_var->options), free(cur_dir); */
		/* return (shell_var->exitnum[0] = 2, NULL); */
	}

	dire = oldpwDir;

	return (dire);
}

/**
 * cDirCmnd - built in command for cd
 * @shell_var: struct
 * Return: 1
 */
ssize_t cDirCmnd(shellDType *shell_var)
{
	char *cur_dir = NULL, *dire = NULL, **nenviron, *oldpwDir = NULL;
	int exit = 1, chckr = 1, checkerSubtrctn = 0;

	cur_dir = getcwd(NULL, 4096);
	if (!cur_dir)
		return (errorSetStr(4, shell_var, 2), free(shell_var->options), -1);
	if (!shell_var->options[1] ||
			(shell_var->options[1] && (!stringCompare(shell_var->options[1], "~"))))
	{
		dire = secAuxCd(shell_var, cur_dir);
		if (!dire)
			return (free(shell_var->options), freeCharFoluke(cur_dir), 1);
	}
	else
		if (!stringCompare(shell_var->options[1], "-"))
		{
			dire = firstAuxCd(shell_var, cur_dir);
			if (!dire)
				return (free(shell_var->options), freeCharFoluke(cur_dir), 1);
			checkerSubtrctn = 1;
		}
		else
			dire = shell_var->options[1];
	if (dire)
		chckr = chdir(dire);
	if (chckr == 0 && checkerSubtrctn == 1)
		write(1, dire, stringLengthFunc(dire)), printCmt(2);
	if (chckr != 0)
		errorSetStr(4, shell_var, 2), exit = -1;
	else
	{
		nenviron = setEnvironm(*(shell_var->envCpy), "PWD", dire, shell_var);
		*(shell_var->envCpy) = nenviron;
		nenviron = setEnvironm(*(shell_var->envCpy), "OLDPWD", cur_dir, shell_var);
		*(shell_var->envCpy) = nenviron;
	}
	free(shell_var->options), freeCharFoluke(cur_dir), freeCharFoluke(oldpwDir);
	if (checkerSubtrctn == 1)
		freeCharFoluke(dire);
	return (exit);
}

/* ................................500..............................*/




/* ................................NUM 4 START..............................*/
/**
 * powerFunc - gets the result of base to ower
 * @base: base
 * @pot: power
 *
 * Return: result
 */
long powerFunc(long base, long pot)
{
	long x = 0, res = 1;

	for (x = 0; x < pot; x++)
		powerFuncFol(base, res);

	return (res);
}

