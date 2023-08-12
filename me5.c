#include "me_shell.h"

/**
 * strLenDblePtrFunc_inner - calculates length of double pointer
 * (ending in NULL)
 * @s: double pointer
 * @x: double pointer
 *
 * Return: Length of double pointer
 *
 */
int strLenDblePtrFunc_inner(char **s, int x)
{
	while (s[x] != NULL)
		x++;
	return (x);
}
/*..........................NUM 25 BTW..........................*/
/*..........................NUM 25 END..........................*/


/**
 * setEnvFunc1 - overwrite an env variable or creates it
 *
 * @env: array of envbles
 * @variable: env vare to set
 * @valuel: valuel to
 * @shellVar: struct l info
 *
 * Return: 0 on sucror
 */
char **setEnvFunc1(char **env, char *variable, char *valuel,
						shellDType *shellVar)
{
	int x, y, check, z = 0, zenv = 0;
	char *joinEnv, *joinEnv2, *cpydupl1, **copy;

	if (strLen1(variable) == 0 || variable == 0)
		return (errorStrFunc(3, shellVar, 1), NULL);
	joinEnv2 = stringConcatFunc(variable, "=");
	if (joinEnv2 == 0)
		return (errorStrFunc(3, shellVar, 1), NULL);
	joinEnv = stringConcatFunc(joinEnv2, valuel), freSingle(joinEnv2);
	if (joinEnv == 0)
		return (errorStrFunc(3, shellVar, 1), NULL);
	z = strLen1(variable), zenv = strLenDblePtrFunc(env);
	for (x = 0; env && env[x] != 0; x++)
	{
		for (check = 0, y = 0; y < z && env[x][y] != 0; y++)
		{
			if (variable[y] == '=')
				return (freSingle(joinEnv), errorStrFunc(3, shellVar, 2), NULL);
			if (env[x][y] == variable[y])
				check++;
		}
		if (check == z && env[x][check] == '=')
		{
			freSingle(env[x]), cpydupl1 = stringDupl(joinEnv), freSingle(joinEnv);
			if (cpydupl1 == 0)
				return (errorStrFunc(3, shellVar, 1), NULL);
			return (env[x] = cpydupl1, env);
		}
	}
	copy = copyDoublePtrFunc(env, zenv, zenv + 1);
	if (env)
		freeDbPtrFunc(env);
	if (copy == 0)
		return (freSingle(joinEnv), errorStrFunc(3, shellVar, 1), NULL);
	env = copy, cpydupl1 = stringDupl(joinEnv), freSingle(joinEnv);
	if (cpydupl1 == 0)
		return (errorStrFunc(3, shellVar, 1), NULL);
	return (env[zenv] = cpydupl1, env);
}

/*..........................signalHandle..........................*/
/**
 * signalHandlerFunc - handles ctrl + c runtime
 * @x: unused valuel, just for betty
 *
 * Return: No return
 */
void signalHandlerFunc(int x)
{
	(void) x;
	printCmt(10);
}
/**
 * signalHandlerFunc2 - hand + c during cmd exec
 * @x: unused valuer betty
 *
 * Return: No return
 */
void signalHandlerFunc2(int x)
{
	(void) x;
	printCmt(11);
}

/*..........................stringConcatFunc..........................*/

/**
 * stringConcatFunc - concatenates two strings
 * @s1: string1
 * @s2: string2
 *
 * Return: Pointer
 */
char *stringConcatFunc(char *s1, char *s2)
{
	int l1, l2, i, j;
	char *s;
	char *nul = "";

	if (s1 == NULL)
		s1 = nul;
	if (s2 == NULL)
		s2 = nul;

	l1 = 0, l2 = 0;
	while (*(s1 + l1))
		l1++;
	while (*(s2 + l2))
		l2++;

	s = malloc(sizeof(char) * (l1 + l2 + 1));

	if (s == 0)
		return (0);

	for (i = 0; i < l1; i++)
		*(s + i) = *(s1 + i);

	for (i = 0, j = l1; i <= l2; j++, i++)
		*(s + j) = *(s2 + i);

	return (s);
}
