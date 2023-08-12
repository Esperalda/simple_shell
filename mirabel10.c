#include "header.h"

/* .........................NUM 12 END.........................*/
/**
 * autIToAlph - functio
 * @n: type int
 * Return: String.
 */

char *autIToAlph(int n)
{
	unsigned int n1;
	int lenght = fetch_lengthe(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (lenght + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + lenght) = '\0';

	if (n < 0)
	{
		n1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		n1 = n;
	}

	lenght--;
	do {
		*(buffer + lenght) = (n1 % 10) + '0';
		n1 = n1 / 10;
		lenght--;
	} while (n1 > 0);
	return (buffer);
}

/**
 * inc_dif_node_extr - adds
 * @head: head
 * @sep1: separato
 * Return: address
 */

strct_list *inc_dif_node_extr(strct_list **head, char sep1)
{
	strct_list *new, *temp;

	new = malloc(sizeof(strct_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep1;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * memorycopy - copies
 * @neweptr: destination
 * @ptr: source
 * @size: size
 */

void memorycopy(void *neweptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_neweptr = (char *)neweptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_neweptr[i] = char_ptr[i];
}

/**
 * stringtok - splits
 * @str: input
 * @delimmta: delimiter.
 * Return: char
 */

char *stringtok(char str[], const char *delimmta)
{
	static char *splitte, *str_ed;
	char *str_start1;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (compare_chars(str, delimmta))
			return (NULL);
		splitte = str;
		i = string_length(str);
		str_ed = &str[i];
	}
	str_start1 = splitte;
	if (str_start1 == str_ed)
		return (NULL);

	for (bool = 0; *splitte; splitte++)
	{

		if (splitte != str_start1)
			if (*splitte && *(splitte - 1) == '\0')
				break;

		for (i = 0; delimmta[i]; i++)
		{
			if (*splitte == delimmta[i])
			{
				*splitte = '\0';
				if (splitte == str_start1)
					str_start1++;
				break;
			}
		}
		if (bool == 0 && *splitte)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (str_start1);
}

/**
 * is_digitFunc - define
 * @s: inpu
 * Return: 1
 */

int is_digitFunc(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
