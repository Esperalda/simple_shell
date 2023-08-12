#include "header.h"

/**
 * string_substr_pref_len - gets
 * @s: initial
 * @accept: accepted
 * Return: the
 */

int string_substr_pref_len(char *s, char *accept)
{
	int i, j, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}

/**
 * _strdup - duplicates
 * @s: Type
 * Return: duplicated
 */

char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = string_length(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	memorycopy(new, s, len + 1);
	return (new);
}

/**
 * string_length - Returns
 * @s: Type
 * Return: Always 0.
 */

int string_length(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * compare_chars - compare
 * @str: input
 * @delimmta: delimit
 *
 * Return: 1 if are equals
 */

int compare_chars(char str[], const char *delimmta)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delimmta[j]; j++)
		{
			if (str[i] == delimmta[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * separate_line - tokenizes
 *
 * @input: input
 * Return: string
 */
char **separate_line(char *input)
{
	size_t besize12;
	size_t x;
	char **tokens, *token;

	besize12 = TOK_BUFSIZE;

	tokens = malloc(sizeof(char *) * (besize12));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}
	token = stringtok(input, TOK_DELIM);
	tokens[0] = token;
	for (x = 1; token != NULL; x++)
	{
		if (x == besize12)
		{
			besize12 += TOK_BUFSIZE;
			tokens = my_realloc_hdp(tokens, x, sizeof(char *) * besize12);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = stringtok(NULL, TOK_DELIM);
		tokens[x] = token;
	}
	return (tokens);
}
