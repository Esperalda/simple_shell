#include "header.h"

/* .........................NUM 7 START.........................*/

/**
 * empty_dif_list - free
 * @head: head
 */

void empty_dif_list(strct_list **head)
{
	strct_list *temp;
	strct_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free_strct_list_MemDaf(temp);
		}
		*head = NULL;
	}
}

/* .........................NUM 7 BTW...........................*/
/**
 * free_strct_list_MemDaf - frees
 * @temp: hea
 */

void free_strct_list_MemDaf(strct_list *temp)
{
	free(temp);
}
/* .........................NUM 7 END...........................*/




/* .........................NUM 8 START.........................*/

/**
 * empty_LiN_list - free
 * @head: head
 */

void empty_LiN_list(srtct_line **head)
{
	srtct_line *temp;
	srtct_line *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free_srtct_line_MemDaf(temp);
		}
		*head = NULL;
	}
}
/* .........................NUM 8 BTW...........................*/
/**
 * free_srtct_line_MemDaf - frees
 * @temp: head
 */

void free_srtct_line_MemDaf(srtct_line *temp)
{
	free(temp);
}
/* .........................NUM 8 END...........................*/

/* .........................NUM 9 START.........................*/
/**
 * emptY_Revar_list - frees
 * @head: head
 */

void emptY_Revar_list(strct_variable **head)
{
	strct_variable *temp;
	strct_variable *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
/* .........................NUM 9 BTW...........................*/
