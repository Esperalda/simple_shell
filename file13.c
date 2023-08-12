#include "shell.h"

/**
 * helpHelpFunc1_inner - prints helpilt in
 *
 * Return: No Return
 */
void helpHelpFunc1_inner(void)
{
	putsToStd("help: help [BUILTIN ...]\n");
	putsToStd("    Display information about builtin commands.\n\n");
	putsToStd("    Displays brief summaries of builtin commands. If BUILTINs\n");
	putsToStd("    specified, gives detailed help on all commands ");
	putsToStd("    matching BUILTIN,\n");
	putsToStd("    otherwise the list of help topics is printed.\n\n");
	putsToStd("    Arguments:\n");
	putsToStd("      BUILTIN   Builtin specifying a help topic\n\n");
	putsToStd("    Exit Status:\n");
	putsToStd("    Returns success unless PATTERN is not found or an invalid ");
	putsToStd("    optNoni is given.\n");
}
/*..........................NUM 21 BTW..........................*/
/*..........................NUM 21 END..........................*/

/*..........................NUM 22 START..........................*/
/**
 * helpAliasFunc - prints help oflt in
 *
 * Return: No Return
 */
void helpAliasFunc(void)
{
	helpAliasFunc_inner();
}
/*..........................NUM 22 BTW..........................*/
/**
 * helpAliasFunc_inner - prints lias built in
 *
 * Return: No Return
 */
void helpAliasFunc_inner(void)
{
	putsToStd("alias: alias alias [name[='valuel'] ...]\n");
	putsToStd("    Define or display aliases.\n\n");
	putsToStd("    Without arguments, `alias' prints the list of aliases ");
	putsToStd("    in the reusable\n");
	putsToStd("    form `alias NAME=VALUE' on standard output.\n\n");
	putsToStd("     Otherwise, an alias is defined for each NAME whose ");
	putsToStd("    VALUE is given.\n");
	putsToStd("    A trailing space in VALUE causes the next word to ");
	putsToStd("    be checked for\n");
	putsToStd("    alias substitution when the alias is expanded.\n\n");
	putsToStd("    Exit Status:\n");
	putsToStd("    alias returns true unless a NAME is supplied for which ");
	putsToStd("    no alias has been\n");
	putsToStd("    defined.\n");
}
/*..........................NUM 22 BTW..........................*/
/*..........................NUM 22 END..........................*/


/*..........................NUM 23 START..........................*/
/*..........................help003..........................*/
/**
 * printsHelpFunc1 - prints huilt in
 *
 * Return: No Return
 */
void printsHelpFunc1(void)
{
	printsHelpFunc1_inner();
}
/*..........................NUM 23 BTW..........................*/
/**
 * printsHelpFunc1_inner - prints help t in
 *
 * Return: No Return
 */
void printsHelpFunc1_inner(void)
{
	putsToStd("Shell HSH, version 1.0(1)-release (x86_64-pc-linux-gnu)\n");
	putsToStd("These shell commands are defined internally.\n");
	putsToStd("Type `help' to see this list.\n");
	putsToStd("Type help  'BUILTIN'' to find out more about ");
	putsToStd("the function 'BUILTIN'.\n\n");
	putsToStd(" exit [n]\n");
	putsToStd(" env\n");
	putsToStd(" setenv [VARIABLE] [VALUE]\n");
	putsToStd(" unsetenv [VARIABLE]\n");
	putsToStd(" cd [DIRECTORY]\n");
	putsToStd(" help [BUILTIN ...]\n");
	putsToStd(" alias [name[='valuel'] ...]\n");
}
/*..........................NUM 23 BTW..........................*/
/*..........................NUM 23 END..........................*/
