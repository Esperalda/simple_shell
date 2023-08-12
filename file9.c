#include "shell.h"

/**
 * memorySet_inner - fills memory with constant byte
 * @s: memory area
 * @b: constant byte b
 * @x: first n bytes of mem
 * Return: On success 1.
 * On error, -1 is returned,opriately.
 */
char memorySet_inner(char *s, char b, unsigned int x)
{
	s[x] = b;
	return (s[x]);
}
/*..........................NUM 7 END..........................*/

/*..........................NUM 8 START..........................*/
/**
 * memoryCopyFunc - copies
 * @dest: destinati
 * @src: source
 * @n: size of memory
 * Return: Returns
 */
char *memoryCopyFunc(char *dest, char *src, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		dest[x] = memoryCopyFunc_inner(dest, src, x);
	return (dest);
}
/*..........................NUM 8 BTW..........................*/
/**
 * memoryCopyFunc_inner - copies memory
 * @dest: destination
 * @src: source
 * @x: size of memo
 *
 * Return: Returns
 */
char memoryCopyFunc_inner(char *dest, char *src, unsigned int x)
{
	return (dest[x] = src[x]);
}
/*..........................NUM 8 END..........................*/


/*..........................NUM 9 START..........................*/
/**
 * reAllocateMemSpce - reallocates a memory block using malloc and free
 * @ptr: pointer to
 * @oldSze: current
 * @newSze: size memo
 *
 * Return: Pointer toory
 */
void *reAllocateMemSpce(void *ptr, unsigned int oldSze, unsigned int newSze)
{
	void *ptr2;
	int chk = 0;

	if (oldSze == newSze)
		return (ptr);

	if (ptr == NULL)
	{
		chk = 1;
		ptr2 = NULL;
		ptr2 = reAllocateMemSpce_inner(ptr, oldSze, newSze, ptr2, chk);
		return (ptr2);
	}

	if (newSze == 0 && ptr != NULL)
	{
		freSingle(ptr);
		return (0);
	}

	ptr2 = malloc(newSze);

	if (ptr2 == 0)
		return (0);

	ptr2 = memorySet(ptr2, '\0', newSze);

	ptr2 = reAllocateMemSpce_inner(ptr, oldSze, newSze, ptr2, chk);
	return (ptr2);
}
/*..........................NUM 9 BTW..........................*/
/**
 * reAllocateMemSpce_inner - reallocates a memory block using malloc and free
 * @ptr: pointer to
 * @oldSze: currentory
 * @newSze: size memow have
 * @ptr2: size memory w
 * @chk: size memory wi
 *
 * Return: Pointer to reallocated memory
 */
void *reAllocateMemSpce_inner(void *ptr, unsigned int oldSze,
					unsigned int newSze, void *ptr2, int chk)
{
	if (chk == 1)
	{
		ptr2 = malloc(newSze);
		if (ptr2 == 0)
			return (0);
		freSingle(ptr);
	}
	else
	{
		memoryCopyFunc(ptr2, ptr, oldSze);
		freSingle(ptr);
	}
	return (ptr2);
}
/*..........................NUM 9 END..........................*/
