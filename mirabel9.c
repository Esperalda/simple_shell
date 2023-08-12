#include "header.h"

/**
 * rest_input - replace
 *
 * @head: head
 * @input: input
 * @n1_input: new
 * @nlen1: new
 * Return: replaced
 */

char *rest_input(strct_variable **head, char *input, char *n1_input, int nlen1)
{
	strct_variable *indx2;
	int i, j, k;

	indx2 = *head;
	for (j = i = 0; i < nlen1; i++)
	{
		if (input[j] == '$')
		{
			if (!(indx2->len_var) && !(indx2->len_val))
			{
				n1_input[i] = input[j];
				j++;
			}
			else if (indx2->len_var && !(indx2->len_val))
			{
				for (k = 0; k < indx2->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < indx2->len_val; k++)
				{
					n1_input[i] = indx2->val[k];
					i++;
				}
				j += (indx2->len_var);
				i--;
			}
			indx2 = indx2->next;
		}
		else
		{
			n1_input[i] = input[j];
			j++;
		}
	}
	return (n1_input);
}

/**
 * rest_variable - calls
 *
 * @input: input string
 * @datshell: data structure
 * Return: replaced string
 */

char *rest_variable(char *input, data_shell *datshell)
{
	strct_variable *head, *indx2;
	char *status, *n1_input;
	int olen, nlen1;

	status = autIToAlph(datshell->status);
	head = NULL;

	olen = confirm_variable(&head, input, status, datshell);

	if (head == NULL)
	{
		freeCharMemDaf(status);
		return (input);
	}

	indx2 = head;
	nlen1 = 0;

	while (indx2 != NULL)
	{
		nlen1 += (indx2->len_val - indx2->len_var);
		indx2 = indx2->next;
	}

	nlen1 += olen;

	n1_input = malloc(sizeof(char) * (nlen1 + 1));
	n1_input[nlen1] = '\0';

	n1_input = rest_input(&head, input, n1_input, nlen1);

	freeCharMemDaf(input);
	freeCharMemDaf(status);
	emptY_Revar_list(&head);

	return (n1_input);
}

/**
 * remove_command - deletes
 *
 * @in: input
 * Return: input
 */
char *remove_command(char *in)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				freeCharMemDaf(in);
				return (NULL);
			}
			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				up_to = i;
		}
	}
	if (up_to != 0)
	{
		in = my_realloc(in, i, up_to + 1);
		in[up_to] = '\0';
	}
	return (in);
}


/* .........................NUM 17 START.......................*/
/**
 * aut_asst_current_dir - Hlp
 */

void aut_asst_current_dir(void)
{
	char *hlp = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	aut_asst_current_dirDaf(hlp);
}

/* .........................NUM 17 BTW.........................*/
/**
 * aut_asst_current_dirDaf - Hlp
 * @hlp: str
 */

void aut_asst_current_dirDaf(char *hlp)
{
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, hlp, string_length(hlp));
}
