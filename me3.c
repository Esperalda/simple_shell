#include "you_shell.h"

/**
 * exitCmdFunc - exit command
 * @shell_var: struct
 * Return: -1 if error
 */
ssize_t exitCmdFunc(shellDType *shell_var)
{
	long exit_value;

	if (shell_var->options[1] == NULL || isNumba(shell_var->options[1]))
	{
		exit_value = atoiFol(shell_var->options[1]);

		if (exit_value >= 0 && exit_value < INT_MAX)
		{
			if (exit_value > 255)
				exit_value %= 256;
			if (shell_var->options[1] == NULL)
				exit_value = shell_var->exitnum[0];
			free(*(shell_var->options));
			free(shell_var->options);
			if (*(shell_var->envCpy))
				freeDobleCharPntrFoluke(*(shell_var->envCpy));
			free(shell_var);
			exit(exit_value);
		}
	}
	errorSetStr(2, shell_var, 2);
	free(shell_var->options);
	return (-1);
}

/**
 * envCmd - env command
 * @shell_var: struct
 * Return: 1
 */
ssize_t envCmd(shellDType *shell_var)
{
	char **str;
	int chckr = 1;

	if (*(shell_var->envCpy) == NULL)
	{
		printCmt(3);
		shell_var->exitnum[0] = 2;
		free(shell_var->options);
		return (-1);
	}

	str = *(shell_var->envCpy);

	if (shell_var->options[1] == NULL)
	{
		for (; str && *str; str++)
		{
			write(1, *str, stringLengthFunc(*str));
			printCmt(2);
		}
	}
	else
	{
		errorSetStr(0, shell_var, 2);
		chckr = -1;
	}

	free(shell_var->options);
	return (chckr);
}
/**
 * setEnvironCmd - setenv command
 * @shell_var: struct
 * Return: 1
 */
ssize_t setEnvironCmd(shellDType *shell_var)
{
	char **nenviron, *var1 = NULL, *val1 = NULL;

	if (shell_var->options[1])
	{
		var1 = shell_var->options[1];
		if (!shell_var->options[2])
		{
			printCmt(4);
			shell_var->exitnum[0] = 2;
			free(shell_var->options);
			return (-1);
		}
		else
			val1 = shell_var->options[2];
	}
	if (var1 == 0)
	{
		printCmt(5);
		shell_var->exitnum[0] = 2;
		free(shell_var->options);
		return (-1);
	}

	nenviron = setEnvironm(*(shell_var->envCpy), var1, val1, shell_var);

	if (nenviron == 0)
	{
		free(shell_var->options);
		return (-1);
	}

	*(shell_var->envCpy) = nenviron;
	free(shell_var->options);
	return (1);
}
/**
 * unSetEnvironComnd - unsetenv command
 * @shell_var: struct
 * Return: 1
 */
ssize_t unSetEnvironComnd(shellDType *shell_var)
{
	char **nenviron, *var1 = NULL;

	if (shell_var->options[1])
		var1 = shell_var->options[1];
	else
	{
		shell_var->exitnum[0] = 2;
		printCmt(6);
		return (free(shell_var->options), -1);
	}

	if (var1 == 0)
	{
		free(shell_var->options);
		return (1);
	}

	nenviron = unSetEnviron(*(shell_var->envCpy), var1, shell_var);

	if (nenviron == 0 && shell_var->unsetnull[0] == 0)
	{
		free(shell_var->options);
		shell_var->exitnum[0] = 2;
		return (-1);
	}

	*(shell_var->envCpy) = nenviron;
	free(shell_var->options);
	return (1);
}

/**
 * chckBuiltIn - checks if the command is built in
 * @shell_var: struct
 * Return: On fail 0
 */
ssize_t chckBuiltIn(shellDType *shell_var)
{
	builtIn_s ops[] = {
		{"exit", exitCmdFunc},
		{"env", envCmd},
		{"setenv", setEnvironCmd},
		{"unsetenv", unSetEnvironComnd},
		{"cd", cDirCmnd},
		{"help", hlpComnd}
	};

	int x = 6, builtcheck; /* lenght of ops array */

	while (x--)
		if (!stringCompare(shell_var->cmd, ops[x].cmd))
		{
			shell_var->errnum[0] += 1;
			builtcheck = ops[x].f(shell_var);
			if (builtcheck == 1)
				shell_var->exitnum[0] = 0;
			return (builtcheck);
		}

	return (0);
}

