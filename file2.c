#include "shell.h"

/*..........................NUM 12 START..........................*/
/**
 * intToAlph - converts an integer to string
 *
 * @n: number
 *
 * Return: pointer to string
 */
char *intToAlph(int n)
{
	unsigned long int x = 0, base = 10;
	char *str;

	str = intToAlph_upper(n, x, base);

	if (str == 0)
		return (0);

	for (; n > 0; x++)
	{
		str[x] = (n % base) + '0';
		n = Length_base_inner(n, base);
		/* n = n / base; */
	}
	str[x] = '\0';
	reverseString(str);
	return (str);
}
/*..........................NUM 12 BTW..........................*/
/**
 * intToAlph - converts an integer to string
 *
 * @n: number
 *
 * Return: pointer to string
 */
char *intToAlph_upper(int n, unsigned long int x, unsigned long int base)
{	
	char *str;

	if (n != 0)
		str = malloc(Length_base(n, base) + 1);
	else
		str = malloc(2), str[x] = '0', x++;
	return (str);
}
/*..........................NUM 12 BTW..........................*/
/*..........................NUM 12 END..........................*/

/*..........................NUM 2 START..........................*/
/**
 * errorStrFunc - creates a string with error line
 * @errNum: number corresponding to type of error
 * @shellVar: struct containing shell information
 * @exnum: valuel of exit the shell should have
 *
 * Return: 0 success, -1 fail
 */
int errorStrFunc(int errNum, shellDType *shellVar, int exnum)
{
	int cnter = shellVar->errnum[0], z = 0;
	char *cmd = shellVar->cmd, **optNoni = shellVar->options;
	char *sh_Name = shellVar->hshname;
	char *numStr = "foluke", *concat_a = "foluke", *concat_b = "foluke", *collctspace = ": ";
	char *err[] = {
		"not found", "Permission denied", "Illegal number",
		"name is NULL, points to string of len 0, or has an '=' char.",
		"can't cd to ", "Illegal optNoni ", "Help command error",
		"Error allocating memory", "Wrong Alias",
		NULL
	};
	
	errorStrFunc1(errNum, cnter, z, sh_Name, numStr,
					concat_a, err, concat_b, collctspace, cmd);

	freSingle(concat_a);
	concat_a = stringConcatFunc(concat_b, collctspace);
	if (!concat_a) /*hsh: cnter: cmd: */
		return (freSingle(concat_b), printCmt(1), -1);
	freSingle(concat_b);
	concat_b = stringConcatFunc(concat_a, err[errNum]);
	if (!concat_b) /*hsh: cnter: cmd: error*/
		return (freSingle(concat_a), printCmt(1), -1);
	freSingle(concat_a);
	if (errNum > 1 && errNum < 6 && errNum != 3)
		concat_b = errorStrFunc2(errNum, concat_b, optNoni[1]);
	if (concat_b == NULL)
	{
		printCmt(1);
		return (-1);
	}
	while (concat_b[z] != 0)
		z++;
	write(2, concat_b, z), printCmt(2);
	freSingle(concat_b);
	shellVar->exit_Num[0] = exnum;
	return (0);
}
/*..........................NUM 2 BTW..........................*/
/**
 * errorStrFunc - creates a string with error line
 * @errNum: number corresponding to type of error
 * @shellVar: struct containing shell information
 * @exnum: valuel of exit the shell should have
 *
 * Return: 0 success, -1 fail
 */
int errorStrFunc1(int errNum, int cnter, int z, char *sh_Name,
					char *numStr, char *concat_a, char *err[],
					char *concat_b, char *collctspace, char *cmd)
{
	concat_a = stringConcatFunc(sh_Name, collctspace);
	if (!concat_a) /*hsh: */
		return (printCmt(1), -1);
	if (errNum == 7) /* Alloc Error */
	{
		concat_b = "fol";
		errorStrFunc_inner(errNum, concat_a, concat_b, err, z);
	}
	numStr = intToAlph(cnter);
	if (!numStr)  /* number to string */
		return (freSingle(concat_a), printCmt(1), -1);
	concat_b = stringConcatFunc(concat_a, numStr);
	if (!concat_b) /*hsh: cnter*/
	{
		printCmt(1);
		return (freSingle(concat_a), freSingle(numStr),  -1);
	}
	freSingle(concat_a), freSingle(numStr);
	concat_a = stringConcatFunc(concat_b, collctspace);
	if (!concat_a) /*hsh: cnter: */
		return (freSingle(concat_b), printCmt(1), -1);
	freSingle(concat_b);
	concat_b = stringConcatFunc(concat_a, cmd);
	if (!concat_b) /*hsh: cnter: cmd*/
		return (freSingle(concat_a), printCmt(1), -1);
	return (0);
}
/*..........................NUM 2 BTW..........................*/

/*..........................NUM 2 BTW..........................*/

/*..........................NUM 2 BTW..........................*/
/**
 * errorStrFunc - creates a string with error line
 * @errNum: number corresponding to type of error
 * @shellVar: struct containing shell information
 * @exnum: valuel of exit the shell should have
 *
 * Return: 0 success, -1 fail
 */
int errorStrFunc_inner(int errNum, char *concat_a, char *concat_b, char *err[], int z)
{
	concat_b = stringConcatFunc(concat_a, err[errNum]); /*hsh: cnter: error*/
	if (!concat_b)
		return (freSingle(concat_a), printCmt(1), -1);
	freSingle(concat_a);
	while (concat_b[z] != 0)
		z++;
	write(2, concat_b, z), printCmt(2);
	freSingle(concat_b);
	return (0);
}
/*..........................NUM 2 END..........................*/

/*..........................NUM 3 START..........................*/
/**
 * errorStrFunc2 - extra modes for error generation
 * @errNum: number corresponding to type of error
 * @concat_b: error part from errorStrFunc
 * @optNoni: cmd optNoni thaat
 *
 * Return: pointer to string
 */
char *errorStrFunc2(int errNum, char *concat_b, char *optNoni)
{
	char *concat_a, *collctspace = ": ";

	if (errNum == 2) /* exit error */
	{

		concat_a = stringConcatFunc(concat_b, collctspace);
		if (!concat_a) /*hsh: cnter: cmd: error: */
		{
			printCmt(1);
			return (freSingle(concat_b), NULL);
		}
		freSingle(concat_b);

		concat_b = stringConcatFunc(concat_a, optNoni);

		if (!concat_b) /*hsh: cnter: cmd: error: optNoni*/
		{
			printCmt(1);
			return (freSingle(concat_a), NULL);
		}
		freSingle(concat_a);
	}
	if (errNum > 3) /* Errors with options at end */
	{
		errorStrFunc2_inner(concat_b, optNoni, concat_a);
		return (concat_a);
	}
	return (concat_b);

}
