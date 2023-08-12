#include "header.h"

/* .........................NUM 1 START...........................*/

/**
 * theAtoi - atoi
 * @s: input
 * Return: integer
 */
int theAtoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, x;
	struct atoistruct cnt;

	cnt = theAtoiDaf_count(s, count, size, pn, m);

	for (x = cnt.cntst - cnt.szst; x < count; x++)
	{
		oi = oi + ((*(s + x) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}

/* .........................NUM 1 BTW...........................*/

/**
 * theAtoiDaf_count - struct
 * @s: input
 * @count: input
 * @size: input
 * @pn: input
 * @m: input
 * Return: structure
 */
atoitype theAtoiDaf_count(char *s, unsigned int count, unsigned int size,
			 unsigned int pn, unsigned int m)
{
	atoitype cnt;

	cnt.cntst = count;
	cnt.szst = size;

	while (*(s + cnt.cntst) != '\0')
	{
		if (cnt.szst > 0 && (*(s + cnt.cntst) < '0' || *(s + cnt.cntst) > '9'))
			break;

		if (*(s + cnt.cntst) == '-')
			pn *= -1;

		if ((*(s + cnt.cntst) >= '0') && (*(s + cnt.cntst) <= '9'))
		{
			if (cnt.szst > 0)
				m *= 10;
			cnt.szst++;
		}
		cnt.cntst++;
	}
	return (cnt);
}

/* .........................NUM 1 END...........................*/

/* .........................NUM 2 START.........................*/

/**
 * authenticate_asst_Ext - Hlp
 */
void authenticate_asst_Ext(void)
{
	char *hlp = "exit: exit [n]\n Exit shell.\n";

	authenticate_asst_ExtDaf(hlp);
}

/* .........................NUM 2 BTW.........................*/
/**
 * authenticate_asst_ExtDaf - Hlp
 * @hlp: input
 */
void authenticate_asst_ExtDaf(char *hlp)
{
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "statusis that of the lastarg command executed\n";
	write(STDOUT_FILENO, hlp, string_length(hlp));
}
/* .........................NUM 2 END...........................*/

/* .........................NUM 3 START.........................*/
/**
 * authenticator_asst - Hlp
 */

void authenticator_asst(void)
{
	char *hlp = "hlp: hlp [-dms] [pattern ...]\n";

	authenticator_asstDaf(hlp);
}
/* .........................NUM 3 BTW.........................*/
