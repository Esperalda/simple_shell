#include "you_shell.h"

/* ................................NUM 1 START..............................*/
/**
 * string_reverse - Reverses string
 * @s: str to rev
 */
void string_reverse(char *s)
{
	int x = 0, y = 0, z;
	char temp_var = 'A';

	while (s[x])
		x++;
	z = x / 2, x = x - 1;
	while (x >= z)
	{
		string_reverseSub(s, temp_var, x, y);
	}
}

/* ................................NUM 1 BTW................................*/
/**
 * string_reverseSub - R
 * @s: str
 * @temp_var: str
 * @x: str
 * @y: str
 */
void string_reverseSub(char *s, char temp_var, int x, int y)
{
	temp_var  = s[y];
	s[y] = s[x];
	s[x] = temp_var;
	x--, y++;
}
/* ................................NUM 1 END................................*/

/* ................................NUM 2 START..............................*/
/**
 * freeCharFoluke - frees
 * @temp: head
 */

void freeCharFoluke(char *temp)
{
	free(temp);
}
/* ................................NUM 2 END................................*/


/**
 * lenBTen - get length
 *
 * @n: number
 * @base: base
 * Return: length
 */
int lenBTen(unsigned long int n, unsigned long int base)
{
	unsigned long int x, negNum = 0, ret;

	for (x = 0; n > 0; x++)
		n = n / base;
	ret = x + negNum;
	return (ret);
}


/**
 * intToAlp - converts
 * @n: number
 * Return: ptr
 */
char *intToAlp(int n)
{
	unsigned long int x = 0, base = 10;
	char *str;

	if (n != 0)
		str = malloc(lenBTen(n, base) + 1);
	else
		str = malloc(2), str[x] = '0', x++;

	if (str == 0)
		return (0);

	for (; n > 0; x++)
	{
		str[x] = (n % base) + '0';
		n = n / base;
	}
	str[x] = '\0';
	string_reverse(str);
	return (str);
}
