#include "shell.h"

/*..........................errorStrFunc..........................*/
/*..........................NUM 11 START..........................*/
/**
 * reverseString - Reverses a string
 * @s: string to reverse
 *
 * Return: Nothing
 */
void reverseString(char *s)
{
	int x = 0, y = 0, z;

	x = reverseString_upper(s, x);
	z = x / 2, x = x - 1;
	reverseString_lower(s, x, y, z);
}
/*..........................NUM 11 BTW..........................*/
/**
 * reverseString - Reverses a string
 * @s: string to reverse
 *
 * Return: Nothing
 */
int reverseString_upper(char *s, int x)
{
	while (s[x])
		x++;
	return (x);
}
/*..........................NUM 11 BTW..........................*/
/**
 * reverseString - Reverses a string
 * @s: string to reverse
 *
 * Return: Nothing
 */
void reverseString_lower(char *s, int x, int y, int z)
{
	char tmp;

	while (x >= z)
	{
		tmp  = s[y];
		s[y] = s[x];
		s[x] = tmp;
		x--, y++;
	}

}
/*..........................NUM 11 END..........................*/

/*..........................NUM 1 START..........................*/
/**
 * Length_base - obtains length of number in base
 *
 * @n: number
 * @base: base of number
 *
 * Return: length of number
 */
int Length_base(unsigned long int n, unsigned long int base)
{
	unsigned long int x, neg = 0;

	for (x = 0; n > 0; x++)
		n = Length_base_inner(n, base);
	return (x + neg);
}
/*..........................NUM 1 BTW..........................*/
/**
 * Length_base - obtains length of number in base
 *
 * @n: number
 * @base: base of number
 *
 * Return: length of number
 */
unsigned long int Length_base_inner(unsigned long int n, unsigned long int base)
{
	n = n / base;
	return (n);
}
/*..........................NUM 1 END..........................*/
