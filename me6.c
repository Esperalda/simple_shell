#include "me_shell.h"

/*..........................NUM 26 START..........................*/
/*..........................strdup..........................*/
/**
 * stringCopyFunc - copyce input ont destinated input
 * @dest: target where wiored the input
 * @src: source to cop
 *
 *
 * Return: dest addr
 * On error: -1 inapropy
 */

char *stringCopyFunc(char *dest, char *src)
{
	int i = 0;

	for (i = 0; *(src + i) != '\0'; i++)
		*(dest + i) = stringCopyFunc_inner(dest, src, i);

	*(dest + i) = stringCopyFunc_inner(dest, src, i); /* adding '\0' character */

	return (dest);
}
/*..........................NUM 26 BTW..........................*/
/**
 * stringCopyFunc_inner - source input ont destinated input
 * @dest: target whered the input
 * @src: source to com
 * @i: source to c
 *
 *
 * Return: dest ad
 * On error: -1 inapr
 */

char stringCopyFunc_inner(char *dest, char *src, int i)
{
	*(dest + i) = *(src + i);
	return (*(dest + i));
}
/*..........................NUM 26 BTW..........................*/
/*..........................NUM 26 END..........................*/


/**
 * strLen1 - function that r length of a string
 * @s: string
 *
 *
 * Return: nothing
 * On error: -1 inap
 */

int strLen1(char *s)
{
	return ((!*s) ? 0 : 1 + strLen1(s + 1));
}

/**
 * stringDupl - function that recated space
 * in memory, which contains a ing given as a parameter
 * @str: source to
 *
 *
 * Return: address red the result
 * On error: -1 inapro
 */

char *stringDupl(char *str)
{
	char *arr;

	if (!str)
		return (NULL);

	arr = malloc((strLen1(str) * sizeof(*arr)) + 1);

	if (!arr)
		return (NULL);

	stringCopyFunc(arr, str);

	return (arr);
}


/*..........................strtok..........................*/
/**
 * strTokenFunc - tokenizes a string based on a delimiter
 *
 * @str: string
 * @delim: delimit
 *
 * Return: pointto string
 * or NULL ifis no match
 *
 */
char *strTokenFunc(char *str, const char *delim)
{
	const char *org = delim;
	int isEql = 1, isGtIto = 0;
	static char *step, *stpNull1;
	static int iEnd1;

	if (str)
		iEnd1 = 0;
	if (iEnd1)
		return (NULL);
	step = (str) ? str : (stpNull1 + 1);
	if (str)
		stpNull1 = str;
	else
		str = step;
	while (*str && isEql)
	{
		isEql = 0;
		for (delim = org; *delim; delim++)
			if (*str == *delim)
				isEql = 1;
		str = (!isEql) ? str : str + 1;
		iEnd1 = (*str) ? 0 : 1;
		if (iEnd1)
			return (NULL);
	}
	step = str;
	while (*str && !isEql)
	{
		isEql = 0;
		for (delim = org; *delim; delim++)
			if (*str == *delim)
			{
				isGtIto = 1, isEql = 1;
				iEnd1 = (*(str + 1)) ? 0 : 1, *str = '\0';
			}
		str = (isEql) ? str : str + 1;
		if (!isGtIto && !*str)
			iEnd1 = 1;
	}
	return (stpNull1 = str, step);
}
