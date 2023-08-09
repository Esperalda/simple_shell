#include "you_shell.h"

/* ................................NUM 4 BTW................................*/
/**
 * powerFuncFol - gets the result of base to ower
 * @base: base
 * @res: power
 * Return: result
 */
long powerFuncFol(long base, long res)
{
	res *= base;
	return (res);
}
/* ................................NUM 4 END................................*/


/* ................................NUM 5 START..............................*/

/**
 * atoiFol - convert char to int
 * @s: char input
 * Return: input
 */

long atoiFol(char *s)
{
	long x = 0, k = 0, len = 0, toRet = 0, subtracn = 0, offset = 48;
	unsigned long result = 0;


	if (!s)
		return (0);

	for (x = 0; *(s + x) != '\0'; x++)
	{
		if (*(s + x) >= 48 && *(s + x) <= 57)
			len++;
		else if (len != 0)
			break;

		if (*(s + x) == '-')
			subtracn = atoiFolFol(subtracn);
	}

	for (x--; len > 0; x--, k++, len--)
		result +=  (*(s + x) - offset) * powerFunc(10, k);

	toRet = (subtracn % 2 != 0) ? result * (-1) : result;

	return (toRet);
}

/* ................................NUM 5 BTW................................*/
/**
 * atoiFolFol - convert char to int
 * @subtracn: char
 * Return: input
 */

long atoiFolFol(long subtracn)
{
	return (subtracn++);
}
/* ................................NUM 5 END................................*/


/* ................................NUM 6 START..............................*/

/**
 * stringCompare - compares two strings
 * @s_one: str1
 * @s_two: str
 * Return: 0 if strings are eql or another val1 if not
 */
int stringCompare(char *s_one, char *s_two)
{
	int x = 0, eql = 0;

	for (x = 0; (*(s_one + x) || *(s_two + x)) && !eql; x++)
		if (*(s_one + x) != *(s_two + x))
			eql = stringCompareFol(s_one, s_two, x);

	return (eql);
}
/* ................................NUM 6 BTW................................*/
/**
 * stringCompareFol - compares two strings
 * @s_one: str1
 * @s_two: str
 * @x: str
 * Return: 0 if strings are eql or another val1 if not
 *
 */
int stringCompareFol(char *s_one, char *s_two, int x)
{
	int eql;

	eql = *(s_one + x) - *(s_two + x);
	return (eql);
}
/* ................................NUM 6 END................................*/
