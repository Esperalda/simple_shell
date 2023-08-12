#include "header.h"

/**
 * free_strct_variable_MemDaf - frees
 * @temp: head
 */

void free_strct_variable_MemDaf(strct_variable *temp)
{
	free(temp);
}
/* .........................NUM 9 END...........................*/

/**
 * include_LN_node_extr - adds
 * @head: head
 * @line: command
 * Return: address
 */
srtct_line *include_LN_node_extr(srtct_line **head, char *line)
{
	srtct_line *new, *temp;

	new = malloc(sizeof(srtct_line));
	if (new == NULL)
		return (NULL);

	new->line = line;
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
 * include_Revar_node - add
 * @head: head
 * @lhvar: length
 * @val: value
 * @lvalr: length
 * Return: address
 */

strct_variable *include_Revar_node(strct_variable **head, int lhvar,
									char *val, int lvalr)
{
	strct_variable *new, *temp;

	new = malloc(sizeof(strct_variable));
	if (new == NULL)
		return (NULL);

	new->len_var = lhvar;
	new->val = val;
	new->len_val = lvalr;

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

/* .........................NUM 10 START.......................*/
/**
 * test_CurrentDir - checks
 * @path: type
 * @i: type
 * Return: 1
 */

int test_CurrentDir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		test_CurrentDirDaf(i);
	}

	if (path[*i])
		test_CurrentDirDaf(i);

	return (0);
}
/* .........................NUM 10 BTW.........................*/

/**
 * test_CurrentDirDaf - checks
 * @i: type
 * Return: 1
 */

int test_CurrentDirDaf(int *i)
{
	*i += 1;
	return (*i);
}
/* .........................NUM 10 END.........................*/
