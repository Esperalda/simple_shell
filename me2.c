#include "me_shell.h"

/*..........................help002..........................*/
/*..........................NUM 19 START..........................*/
/**
 * helpUnSetEnv1 - prints help ofuilt in
 *
 * Return: No Return
 */
void helpUnSetEnv1(void)
{
	helpUnSetEnv1_inner();
}
/*..........................NUM 19 BTW..........................*/
/**
 * helpUnSetEnv1_inner - prints hev built in
 *
 * Return: No Return
 */
void helpUnSetEnv1_inner(void)
{
	putsToStd("unsetenv: unsetenv [VARIABLE]\n");
	putsToStd("    Initializes a new environment variable, or ");
	putsToStd("    modifies an existing one.\n\n");
	putsToStd("    VARIABLE must not have the character '='.\n");
	putsToStd("    If no arguments are given, setenv prints the current ");
	putsToStd("    environment.\n");
}
/*..........................NUM 19 BTW..........................*/
/*..........................NUM 19 END..........................*/


/*..........................NUM 20 START..........................*/
/**
 * helpCdFunc1 - prints help of cd built in
 *
 * Return: No Return
 */
void helpCdFunc1(void)
{
	helpCdFunc1_inner();
}
/*..........................NUM 20 BTW..........................*/
/**
 * helpCdFunc1_inner - prints huilt in
 *
 * Return: No Return
 */
void helpCdFunc1_inner(void)
{
	putsToStd("cd: cd [DIRECTORY]\n");
	putsToStd("    Change the shell working directory.\n\n");
	putsToStd("    Change the current directory to DIR.  ");
	putsToStd("    The default DIR is the valuel of the\n");
	putsToStd("    HOME shell variable.\n\n");
	putsToStd("    Options:\n");
	putsToStd("    -  If a mynus signed is used instead a directory, ");
	putsToStd("    cd will change to the\n");
	putsToStd("       previous used directory\n\n");
	putsToStd("    Each time cd runs successfuly, the env variable ");
	putsToStd("    PWD is updated\n\n");
	putsToStd("    Exit Status:\n");
	putsToStd("    Returns 1 if the directory is changed, and if $PWD is set ");
	putsToStd("    successfully when\n");
	putsToStd("    is used; -1 otherwise.\n");
}
/*..........................NUM 20 BTW..........................*/
/*..........................NUM 20 END..........................*/


/*..........................NUM 21 START..........................*/
/**
 * helpHelpFunc1 - prints help built in
 *
 * Return: No Return
 */
void helpHelpFunc1(void)
{
	helpHelpFunc1_inner();
}
/*..........................NUM 21 BTW..........................*/
