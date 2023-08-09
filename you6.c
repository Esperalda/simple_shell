#include "you_shell.h"

/**
 * stringTokenizeFunc - tokenizes a string
 *
 * @str: string to operate
 * @delim: delimiter
 * Return: pointer to string
 */
char *stringTokenizeFunc(char *str, const char *delim)
{
	const char *C_org = delim;
	int issEql = 1, issGetInto = 0;
	static char *step, *stepNull;
	static int isEnd;

	if (str)
		isEnd = 0;
	if (isEnd)
		return (NULL);
	step = (str) ? str : (stepNull + 1);
	if (str)
		stepNull = str;
	else
		str = step;
	while (*str && issEql)
	{
		issEql = 0;
		for (delim = C_org; *delim; delim++)
			if (*str == *delim)
				issEql = 1;
		str = (!issEql) ? str : str + 1;
		isEnd = (*str) ? 0 : 1;
		if (isEnd)
			return (NULL);
	}
	step = str;
	while (*str && !issEql)
	{
		issEql = 0;
		for (delim = C_org; *delim; delim++)
			if (*str == *delim)
			{
				issGetInto = 1, issEql = 1;
				isEnd = (*(str + 1)) ? 0 : 1, *str = '\0';
			}
		str = (issEql) ? str : str + 1;
		if (!issGetInto && !*str)
			isEnd = 1;
	}
	return (stepNull = str, step);
}


/**
 * cpyDoblePtrDel - copies an array of string
 * @p: double pointe
 * @nw_size: siz
 * @jump: val to skip during operation
 * Return: Pointer malloec
 */
char **cpyDoblePtrDel(char **p, int nw_size, int jump)
{
	char **copy;
	int i, j, copSize;

	copSize = nw_size;
	copy = malloc(sizeof(char *) * (copSize + 1));
	if (copy == 0)
		return (0);

	for (i = 0, j = 0; j < copSize; i++, j++)
	{
		if (i == jump)
			i++;
		copy[j] = stringDuplicateFunc(p[i]);
		if (copy[j] == 0)
		{
			j--;
			for (; j >= 0; j--)
				free(copy[j]);
			freeDobleCharPntrFoluke(copy);
			return (0);
		}
	}

	copy[nw_size] = '\0';

	return (copy);
}

/**
 * unSetEnviron - unsets an enviromenta
 * @env: array of en
 * @var1: env var
 * @shell_var: struc
 * Return: 0 on success
 */
char **unSetEnviron(char **env, char *var1, shellDType *shell_var)
{
	int i, j, check, l = 0, lenv = 0, found = 0;
	char **copy;

	shell_var->unsetnull[0] = 0;
	if (!env)
		return (printCmt(3), NULL);
	if (stringLengthFunc(var1) == 0 || var1 == 0)
		return (errorSetStr(3, shell_var, 1), NULL);
	l = stringLengthFunc(var1), lenv = strLenPtr(env);
	for (i = 0; env[i] != 0; i++)
	{
		for (check = 0, j = 0; j < l && env[i][j] != 0; j++)
		{
			if (var1[j] == '=')
				return (errorSetStr(3, shell_var, 2), NULL);
			if (env[i][j] == var1[j])
				check++;
		}
		if (check == l && env[i][check] == '=')
		{
			/* Found env to erase */
			found = 1;
			if ((lenv - 1) != 0)
			{
				copy = cpyDoblePtrDel(env, lenv - 1, i);
				if (copy == 0)
					return (errorSetStr(7, shell_var, 1), NULL);
			}
			else
				shell_var->unsetnull[0] = 1, copy = NULL;
			freeDobleCharPntrFoluke(env), env = copy;
			return (env);
		}
	}
	if (found == 0)
		return (printCmt(12), NULL);
	return (env);

}
