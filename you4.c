#include "you_shell.h"

/**
 * strLenPtr - calculates length of double pointe
 * @s: double pointer
 * Return: Length of double pointer
 */
int strLenPtr(char **s)
{
	int x = 0;

	if (!s)
		return (0);

	while (s[x] != NULL)
		x++;
	return (x);
}



/**
 * setEnvironm - overwrite an en
 * @env: array of env variables
 * @var1: env var
 * @val1: val
 * @shell_var: struc
 * Return: 0 on success, -1 on error
 */
char **setEnvironm(char **env, char *var1, char *val1, shellDType *shell_var)
{
	int x, y, check, z = 0, env6 = 0;
	char *catEnvs1, *catEnvs2, *DupCp, **copy;

	if (stringLengthFunc(var1) == 0 || var1 == 0)
		return (errorSetStr(3, shell_var, 1), NULL);
	catEnvs2 = stringCatenator(var1, "=");
	if (catEnvs2 == 0)
		return (errorSetStr(3, shell_var, 1), NULL);
	catEnvs1 = stringCatenator(catEnvs2, val1), free(catEnvs2);
	if (catEnvs1 == 0)
		return (errorSetStr(3, shell_var, 1), NULL);
	z = stringLengthFunc(var1), env6 = strLenPtr(env);
	for (x = 0; env && env[x] != 0; x++)
	{
		for (check = 0, y = 0; y < z && env[x][y] != 0; y++)
		{
			if (var1[y] == '=')
				return (free(catEnvs1), errorSetStr(3, shell_var, 2), NULL);
			if (env[x][y] == var1[y])
				check++;
		}
		if (check == z && env[x][check] == '=')
		{
			free(env[x]), DupCp = stringDuplicateFunc(catEnvs1), free(catEnvs1);
			if (DupCp == 0)
				return (errorSetStr(3, shell_var, 1), NULL);
			return (env[x] = DupCp, env);
		}
	}
	copy = cpyDoblePtr(env, env6, env6 + 1);
	if (env)
		freeDobleCharPntrFoluke(env);
	if (copy == 0)
		return (free(catEnvs1), errorSetStr(3, shell_var, 1), NULL);
	env = copy, DupCp = stringDuplicateFunc(catEnvs1), free(catEnvs1);
	if (DupCp == 0)
		return (errorSetStr(3, shell_var, 1), NULL);
	return (env[env6] = DupCp, env);
}


/**
 * sigHandlr - handles ctrl + c during runtime
 * @x: unused val
 */
void sigHandlr(int x)
{
	(void) x;
	printCmt(10);
}



/**
 * sigHandlr2 - handles ctrl + c during commd executn
 * @x: unused val1
 */
void sigHandlr2(int x)
{
	(void) x;
	printCmt(11);
}


/* ................................NUM 19 START..............................*/
/**
 * stringCatenator - concatenates strings
 * @s_one: str
 * @s_two: strin
 * Return: Pointer
 */
char *stringCatenator(char *s_one, char *s_two)
{
	int l1, l2, i, j;
	char *s;
	/* char *nul = ""; */

	if (s_one == NULL)
		s_one = stringCatenatorFol();
	if (s_two == NULL)
		s_two = stringCatenatorFol();

	l1 = 0, l2 = 0;
	while (*(s_one + l1))
		l1++;
	while (*(s_two + l2))
		l2++;

	s = malloc(sizeof(char) * (l1 + l2 + 1));

	if (s == 0)
		return (0);

	for (i = 0; i < l1; i++)
		*(s + i) = *(s_one + i);

	for (i = 0, j = l1; i <= l2; j++, i++)
		*(s + j) = *(s_two + i);

	return (s);
}
