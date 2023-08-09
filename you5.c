#include "you_shell.h"

/* ................................NUM 19 BTW................................*/
/**
 * stringCatenatorFol - concatenates strings
 * Return: Pointer
 */
char *stringCatenatorFol()
{
	char *sx;

	return (sx = "");
}

/* ................................NUM 19 END................................*/



/* ................................NUM 20 START..............................*/
/**
 * stringCopy - copy source ont destinated
 * @dest: target
 * @src: source
 * Return: dest
 * On error: -1
 */
char *stringCopy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; *(src + i) != '\0'; i++)
		stringCopyFol(dest, src, i);
		/* *(dest + i) = *(src + i); */

	stringCopyFol(dest, src, i);
	/* *(dest + i) = *(src + i); */ /* adding '\0' character */

	return (dest);
}
/* ................................NUM 20 BTW................................*/
/**
 * stringCopyFol - copy source onto destinated
 * @destinatn: target
 * @source: source
 * @i: source
 * Return: dest
 */
char stringCopyFol(char *destinatn, char *source, int i)
{
	*(destinatn + i) = *(source + i);
	return (*(destinatn + i));
}
/* ................................NUM 20 END................................*/



/**
 * stringLengthFunc - function that returns the length of string
 * @s: string
 * Return: -1 inapropiate entr
 */

int stringLengthFunc(char *s)
{
	return ((!*s) ? 0 : 1 + stringLengthFunc(s + 1));
}


/**
 * stringDuplicateFunc - function that returns a pointer to a newly
 * allocated memoty space
 * @str: source
 * Return: address
 * On error: -1
 */

char *stringDuplicateFunc(char *str)
{
	char *arr;

	if (!str)
		return (NULL);

	arr = malloc((stringLengthFunc(str) * sizeof(*arr)) + 1);

	if (!arr)
		return (NULL);

	stringCopy(arr, str);

	return (arr);
}
