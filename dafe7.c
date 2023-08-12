#include "header.h"

/**
 * next_command_arg - g
 *
 * @list_s: separato
 * @list_l: comman
 * @datshell: data structure
 */

void next_command_arg(strct_list **list_s, srtct_line **list_l,
						data_shell *datshell)
{
	int loop_sep1;
	strct_list *ls_s1;
	srtct_line *ls_l1;

	loop_sep1 = 1;
	ls_s1 = *list_s;
	ls_l1 = *list_l;

	while (ls_s1 != NULL && loop_sep1)
	{
		if (datshell->status == 0)
		{
			if (ls_s1->separator == '&' || ls_s1->separator == ';')
				loop_sep1 = 0;
			if (ls_s1->separator == '|')
				ls_l1 = ls_l1->next, ls_s1 = ls_s1->next;
		}
		else
		{
			if (ls_s1->separator == '|' || ls_s1->separator == ';')
				loop_sep1 = 0;
			if (ls_s1->separator == '&')
				ls_l1 = ls_l1->next, ls_s1 = ls_s1->next;
		}
		if (ls_s1 != NULL && !loop_sep1)
			ls_s1 = ls_s1->next;
	}

	*list_s = ls_s1;
	*list_l = ls_l1;
}

/**
 * separate_command_args - splits
 * @datshell: data
 * @input: input
 * Return: 0 to exit, 1 to continue
 */

int separate_command_args(data_shell *datshell, char *input)
{

	strct_list *head_s, *list_s;
	srtct_line *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	include_nodes(&head_s, &head_l, input);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		datshell->input = list_l->line;
		datshell->args = separate_line(datshell->input);
		loop = executecute_line(datshell);
		free(datshell->args);

		if (loop == 0)
			break;

		next_command_arg(&list_s, &list_l, datshell);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	empty_dif_list(&head_s);
	empty_LiN_list(&head_l);
	if (loop == 0)
		return (0);
	return (1);
}

/**
 * executecute_line - finds
 * @datshell: data
 * Return: 1 on success.
 */

int executecute_line(data_shell *datshell)
{
	int (*builtin)(data_shell *datshell);

	if (datshell->args[0] == NULL)
		return (1);

	builtin = get_builtinFunPtr(datshell->args[0]);

	if (builtin != NULL)
		return (builtin(datshell));
	return (for_command_execution(datshell));
}

/**
 * m_detail - copies
 * @name: name
 * @value: value
 * Return: new
 */

char *m_detail(char *name, char *value)
{
	char *new;
	int len_name1, len_value1, len;

	len_name1 = string_length(name);
	len_value1 = string_length(value);
	len = len_name1 + len_value1 + 2;
	new = malloc(sizeof(char) * (len));
	string_copy(new, name);
	string_cartenate(new, "=");
	string_cartenate(new, value);
	string_cartenate(new, "\0");
	return (new);
}

/**
 * quit_shell_op - exits
 * @datshell: data
 * Return: 0 on success.
 */

int quit_shell_op(data_shell *datshell)
{
	unsigned int ustatus;
	int isDigit1;
	int strLen1;
	int big_numb;

	if (datshell->args[1] != NULL)
	{
		ustatus = theAtoi(datshell->args[1]);
		isDigit1 = is_digitFunc(datshell->args[1]);
		strLen1 = string_length(datshell->args[1]);
		big_numb = ustatus > (unsigned int)INT_MAX;
		if (!isDigit1 || strLen1 > 10 || big_numb)
		{
			get_error(datshell, 2);
			datshell->status = 2;
			return (1);
		}
		datshell->status = (ustatus % 256);
	}
	return (0);
}
