#include "you_shell.h"

/**
 * a2iFunc - converinput to int
 * @s: char input
 *
 *
 * Return: input tnteger
 * On error: -1 inapr
 */

long a2iFunc(char *s)
{
	long x = 0;
	long k = 0;
	long len = 0;
	unsigned long result = 0;
	long retrnPpty = 0;
	long mynus = 0;
	long offset = 48;

	if (!s)
		return (0);

	for (x = 0; *(s + x) != '\0'; x++)
	{
		if (*(s + x) >= 48 && *(s + x) <= 57)
			len++;
		else if (len != 0)
			break;

		if (*(s + x) == '-')
			mynus++;
	}

	for (x--; len > 0; x--, k++, len--)
		result +=  (*(s + x) - offset) * powerFunc(10, k);

	retrnPpty = (mynus % 2 != 0) ? result * (-1) : result;

	return (retrnPpty);
}

/*..........................NUM 5 START..........................*/
/**
 * stringCompareFunc - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if stringsanother valuel if not
 *
 */
int stringCompareFunc(char *s1, char *s2)
{
	int x = 0;
	int equal = 0;

	for (x = 0; (*(s1 + x) || *(s2 + x)) && !equal; x++)
		if (*(s1 + x) != *(s2 + x))
			equal = stringCompareFunc_inner(s1, s2, x, equal);

	return (equal);
}
/*..........................NUM 5 BTW..........................*/
/**
 * stringCompareFunc_inner - compares two strings
 * @s1: string 1
 * @s2: string 2
 * @x: string 2
 * @equal: string 2
 *
 * Return: 0 if strings areother valuel if not
 *
 */
int stringCompareFunc_inner(char *s1, char *s2, int x, int equal)
{
	equal = *(s1 + x) - *(s2 + x);
	return (equal);
}
/*..........................NUM 5 END..........................*/

/**
 * isDigitFunc - checks if a chs a digit
 * @c: character
 *
 * Return: 1 if digit,
 *
 */
int isDigitFunc(int c)
{
	return ((c >= 48 && c <= 57) ? 1 : 0);
}
/**
 * isNumFunc - checks if a string is composed of numbers
 * @s: string
 *
 * Return: 1 if string has only numbers, 0 if not
 */
int isNumFunc(char *s)
{
	for (; *s; s++)
		if (!isDigitFunc(*s))
			return (0);
	return (1);
}
