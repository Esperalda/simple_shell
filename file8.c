#include "you_shell.h"

/*..........................fixed..........................*/
/* .......................NUM 28 START......................*/
/**
 * printCmt - Reverses string
 * @chk: str to rev
 */
void printCmt(int chk)
{
	switch (chk)
	{
		case 1:
			write(2, "Memory Error", 22);
			break;
		case 2:
			write(2, "\n", 1);
			break;
		case 3:
			write(2, "Environment is Null\n", 36);
			break;
		case 4:
			write(2, "Invalid VALUE\n", 14);
			break;
		case 5:
			write(2, "Invalid VARIABLE\n", 17);
			break;
		case 6:
		    write(2, "Please provide an argument\n", 27);
			break;
		case 7:
		    write(2, "cd: too many arguments\n", 23);
			break;
		case 8:
		    write(1, "prompt by foluke $ ", 19);
			break;
		case 9:
		    write(2, "Fork Error", 10);
			break;
		case 10:
			write(1, "\nprompt by foluke $ ", 20);
			break;
		case 11:
			write(1, "\n", 1);
			break;
		case 12:
			write(2, "VARIABLE not found\n", 19);
			break;
	}
}
/* ..........................NUM 28 END.........................*/
/* ..........................NUM 29 START.......................*/
/**
 * freSingle - frees
 * @temp: head
 */

void freSingle(char *temp)
{
	free(temp);
}
/* ..........................NUM 29 END...........................*/
/*..........................NUM 24 START..........................*/
/**
 * freeDbPtrFunc - frees a st end
 *
 * @p: double pointe
 *
 * Return: no return
 */
void freeDbPtrFunc(char **p)
{
	int x, z = 0;

	z = freeDbPtrFunc_inner(p, z);

	for (x = 0; x < z; x++)
	{
		free(p[x]);
	}
	free(p);
}
/*..........................NUM 24 BTW..........................*/
/**
 * freeDbPtrFunc_inner - frees a double pointer array of strings
 *
 * @p: double poi
 * @z: double p
 *
 * Return: no return
 */
int freeDbPtrFunc_inner(char **p, int z)
{
	while (p[z] != 0)
		z++;
	return (z);
}
/*..........................NUM 24 BTW..........................*/
/*..........................fixed..........................*/

/*..........................getline..........................*/
/*..........................NUM 7 START..........................*/
/**
 * memorySet - fills memory with constant byte
 * @s: memory area
 * @b: constant byte b
 * @n: first n bytes of memory aed by s
 *
 * Return: On success 1.
 * On error, -1 is returned, set appropriately.
 */
char *memorySet(char *s, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		s[x] = memorySet_inner(s, b, x);
	return (s);
}
/*..........................NUM 7 BTW..........................*/
