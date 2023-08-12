#include "header.h"

/* .........................NUM 18 START.......................*/
/**
 * aut_asstsetenvironee - Hlp
 */

void aut_asstsetenvironee(void)
{

	char *hlp = "setenv: setenv (const char *name, const char *value,";

	aut_asstsetenvironeeDaf(hlp);
}

/* .........................NUM 18 BTW.........................*/
/**
 * aut_asstsetenvironeeDaf - Hlp
 * @hlp: str
 */

void aut_asstsetenvironeeDaf(char *hlp)
{
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "int replace)\n\t";
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, hlp, string_length(hlp));
}

/* .........................NUM 18 END.........................*/

/* .........................NUM 19 START.......................*/
/**
 * aut_asstunsetenvironddd - Hlp
 */

void aut_asstunsetenvironddd(void)
{
	char *hlp = "unsetenv: unsetenv (const char *name)\n\t";

	aut_asstunsetenvirondddDaf(hlp);
}

/* .........................NUM 19 BTW.........................*/
/**
 * aut_asstunsetenvirondddDaf - Hlp
 * @hlp: str
 */

void aut_asstunsetenvirondddDaf(char *hlp)
{
	write(STDOUT_FILENO, hlp, string_length(hlp));
	hlp = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, hlp, string_length(hlp));
}

/* .........................NUM 19 END.........................*/

/* .........................NUM 20 START.......................*/
/**
 * aut_asstant_general - Entr
 */

void aut_asstant_general(void)
{
	char *hlp = "^-^ bash, version 1.0(1)-release\n";

	aut_asstant_generalDaf(hlp);
}
