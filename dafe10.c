#include "header.h"

/* .........................NUM 20 BTW.........................*/
/**
 * aut_asstant_generalDaf - Entr
 * @hlp: str
 */

void aut_asstant_generalDaf(char *hlp)
{
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "These commands are defined internally.Type 'hlp' to see the list";
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "Type 'hlp name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "unsetenv [variable]\n";
	write(STDOUT_FILENO, hlp, string_length(hlp));
}

/* .........................NUM 20 END.........................*/

/* .........................NUM 12 START.......................*/
/* .........................NUM 12 BTW.........................*/
/* .........................NUM 12 END.........................*/

/**
 * string_cartenate - concatenate
 * @dest: char
 * @src: const
 * Return: the de
 */

char *string_cartenate(char *dest, const char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * *string_copy - Copies
 * @dest: Type
 * @src: Type
 * Return: the de
 */

char *string_copy(char *dest, char *src)
{

	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}

/**
 * stringcompare - Function
 * @s1: type
 * @s2: type
 * Return: Always 0.
 */

int stringcompare(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * string_locate_character - locates
 * @s: string
 * @c: character
 * Return: th
 */

char *string_locate_character(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}
