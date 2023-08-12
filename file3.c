#include "shell.h"

/**
 * errorStrFunc2_inner - extra modes for error generation
 * @concat_a: number correspondingr
 * @concat_b: error part frounc
 * @optNoni: cmd optN
 *
 * Return: pointer to string
 */
char *errorStrFunc2_inner(char *concat_b, char *optNoni,
								char *concat_a)
{
	concat_a = stringConcatFunc(concat_b, optNoni);
	if (!concat_a) /*hsh: cnter: cmd: error optNoni*/
	{
		printCmt(1);
		return (freSingle(concat_b), NULL);
	}
	freSingle(concat_b);
	return (concat_a);
}
/*..........................NUM 3 END..........................*/


/*..........................built_ins1..........................*/

/**
 * exitCmdFunc - built in command exit
 * @shellVar: struct col info
 *
 * Return: -1 if error
 */
ssize_t exitCmdFunc(shellDType *shellVar)
{
	long val2Exit;

	if (shellVar->options[1] == NULL || isNumFunc(shellVar->options[1]))
	{
		val2Exit = a2iFunc(shellVar->options[1]);

		if (val2Exit >= 0 && val2Exit < INT_MAX)
		{
			if (val2Exit > 255)
				val2Exit %= 256;
			if (shellVar->options[1] == NULL)
				val2Exit = shellVar->exit_Num[0];
			free(*(shellVar->options));
			free(shellVar->options);
			if (*(shellVar->envCpy))
				freeDbPtrFunc(*(shellVar->envCpy));
			free(shellVar);
			exit(val2Exit);
		}
	}
	errorStrFunc(2, shellVar, 2);
	free(shellVar->options);
	return (-1);
}

/*..........................NUM 13 START..........................*/
/**
 * envCmdFunc - built in comm
 * @shellVar: struct contain info
 *
 * Return: 1 if succ
 */
ssize_t envCmdFunc(shellDType *shellVar)
{
	char **str;
	int chcka = 1, chk;

	if (*(shellVar->envCpy) == NULL)
	{
		chk = 1;
		chcka = cmdMore(shellVar, chk);
	}

	str = *(shellVar->envCpy);

	if (shellVar->options[1] == NULL)
	{
		envCmdFunc_lower(str);
	}
	else
	{
		errorStrFunc(0, shellVar, 2);
		chcka = -1;
	}

	free(shellVar->options);
	return (chcka);
}
/*..........................NUM 13 BTW..........................*/
/**
 * cmdMore - built in command env
 * @shellVar: struct containinfo
 * @chk: struct containi
 *
 * Return: 1 if succesful
 */
int cmdMore(shellDType *shellVar, int chk)
{
	if (chk == 1)
	{
		/* write(2, "Environment is it\n", 36); */
		printCmt(3);
	}
	else if (chk == 2)
		printCmt(4);
	else if (chk == 3)
		printCmt(5);

	shellVar->exit_Num[0] = 2;
	free(shellVar->options);
	return (-1);
}
/*..........................NUM 13 BTW..........................*/
/**
 * envCmdFunc_lower - built  env
 * @str: struct contai
 *
 * Return: 1 if succesful
 */
void envCmdFunc_lower(char **str)
{
	for (; str && *str; str++)
	{
		write(1, *str, strLen1(*str));
		printCmt(11);
	}
}
/*..........................NUM 13 END..........................*/
