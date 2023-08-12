#include "header.h"

/**
 * basc_chararacter - finds
 *
 * @input: input
 * @i: index
 * Return: 1
 */

int basc_chararacter(char *input, int *i)
{
	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * my_realloc - reallocate
 * @ptr: pointe
 * @old_size: siz
 * @new_size: new siz
 *
 * Return: ptr.
 */

void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *neweptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		freeCharMemDaf(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	neweptr = malloc(new_size);
	if (neweptr == NULL)
		return (NULL);

	if (new_size < old_size)
		memorycopy(neweptr, ptr, new_size);
	else
		memorycopy(neweptr, ptr, old_size);

	freeCharMemDaf(ptr);
	return (neweptr);
}

/**
 * my_realloc_hdp - reallocate
 * @ptr: double
 * @old_size: siz
 * @new_size: new size
 *
 * Return: ptr.
 */

char **my_realloc_hdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **neweptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	neweptr = malloc(sizeof(char *) * new_size);
	if (neweptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		neweptr[i] = ptr[i];

	free(ptr);

	return (neweptr);
}

/**
 * fetch_lengthe - Get
 * @n: type
 * Return: Lenght
 */

int fetch_lengthe(int n)
{
	unsigned int n1 = 0;
	int lenght = 1;

	if (n < 0)
	{
		lenght++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}
	while (n1 > 9)
	{
		lenght++;
		n1 = n1 / 10;
	}

	return (lenght);
}

/**
 * include_nodes - ad
 *
 * @head_s: hea
 * @head_l: hea
 * @input: inpu
 */

void include_nodes(strct_list **head_s, srtct_line **head_l, char *input)
{
	int x;
	char *line;

	input = exchange_character(input, 0);

	for (x = 0; input[x]; x++)
	{
		if (input[x] == ';')
			inc_dif_node_extr(head_s, input[x]);

		if (input[x] == '|' || input[x] == '&')
		{
			inc_dif_node_extr(head_s, input[x]);
			x++;
		}
	}

	line = stringtok(input, ";|&");
	do {
		line = exchange_character(line, 1);
		include_LN_node_extr(head_l, line);
		line = stringtok(NULL, ";|&");
	} while (line != NULL);
}
