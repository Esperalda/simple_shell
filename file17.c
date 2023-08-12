#include "me_shell.h"

/*..........................unsetenv..........................*/
/**
 * copyDoublePtrFuncDel - copies an array of strings (double pointer)
 *
 * @p: double poipy
 * @newSze: size
 * @jump: valuel tha skipped in copy
 *
 * Return: Poin
 */
char **copyDoublePtrFuncDel(char **p, int newSze, int jump)
{
	char **copy;
	int i, j, countSize1;

	countSize1 = newSze;
	copy = malloc(sizeof(char *) * (countSize1 + 1));
	if (copy == 0)
		return (0);

	for (i = 0, j = 0; j < countSize1; i++, j++)
	{
		if (i == jump)
			i++;
		copy[j] = stringDupl(p[i]);
		if (copy[j] == 0)
		{
			j--;
			for (; j >= 0; j--)
				freSingle(copy[j]);
			free(copy);
			return (0);
		}
	}

	copy[newSze] = '\0';

	return (copy);
}


/*..........................NUM 27 START..........................*/
/*..........................NUM 27 BTW..........................*/
/*..........................NUM 27 BTW..........................*/
/*..........................NUM 27 END..........................*/
/**
 * unSetEnvFunf - unsets an enviromental variable
 *
 * @env: array of env
 * @variable: env vaet
 * @shellVar: structnfo
 *
 * Return: 0 on succer
 */
char **unSetEnvFunf(char **env, char *variable, shellDType *shellVar)
{
	int i, j, check, l = 0, ilenv = 0, found = 0;
	char **copy;

	shellVar->unsetnull[0] = 0;
	if (!env)
	{
		return (printCmt(3), NULL);
		/* return (write(2, "Environment is NULL\n", 20), NULL); */
	}
	if (strLen1(variable) == 0 || variable == 0)
		return (errorStrFunc(3, shellVar, 1), NULL);
	l = strLen1(variable), ilenv = strLenDblePtrFunc(env);
	for (i = 0; env[i] != 0; i++)
	{
		for (check = 0, j = 0; j < l && env[i][j] != 0; j++)
		{
			if (variable[j] == '=')
				return (errorStrFunc(3, shellVar, 2), NULL);
			if (env[i][j] == variable[j])
				check++;
		}
		if (check == l && env[i][check] == '=')
		{
			/* Found env to erase */
			found = 1;
			if ((ilenv - 1) != 0)
			{
				copy = copyDoublePtrFuncDel(env, ilenv - 1, i);
				if (copy == 0)
					return (errorStrFunc(7, shellVar, 1), NULL);
			}
			else
				shellVar->unsetnull[0] = 1, copy = NULL;
			freeDbPtrFunc(env), env = copy;
			return (env);
		}
	}
	if (found == 0)
		return (printCmt(12), NULL);
	return (env);
}
