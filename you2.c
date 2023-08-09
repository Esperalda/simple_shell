#include "you_shell.h"

/* ................................NUM 15 START..............................*/
/**
 * cdHlp - prints help of commandsd built-in
 */
void cdHlp(void)
{
	void cdHlpFol(void);
}
/* ................................NUM 15 BTW................................*/
/**
 * cdHlpFol - prints hel
 */
void cdHlpFol(void)
{
	putsFunctn("cd: cd [DIRECTORY]\n");
	putsFunctn("    Change the shell working directory.\n\n");
	putsFunctn("    Change the current directory to DIR.  ");
	putsFunctn("    The default DIR is the val1 of the\n");
	putsFunctn("    HOME shell var1.\n\n");
	putsFunctn("    Options:\n");
	putsFunctn("    -  If a subtracn signed is used instead a directory, ");
	putsFunctn("    cd will change to the\n");
	putsFunctn("       previous used directory\n\n");
	putsFunctn("    Each time cd runs successfuly, the env var1 ");
	putsFunctn("    PWD is updated\n\n");
	putsFunctn("    Exit Status:\n");
	putsFunctn("    Returns 1 if the directory is changed, and if $PWD is set ");
	putsFunctn("    successfully when\n");
	putsFunctn("    is used; -1 otherwise.\n");
}
/* ................................NUM 15 END................................*/



/* ................................NUM 16 START..............................*/
/**
 * hlpHlp - prints hel
 */
void hlpHlp(void)
{
	hlpHlpFol();
}
/* ................................NUM 16 BTW................................*/
/**
 * hlpHlpFol - prints he
 */
void hlpHlpFol(void)
{
	putsFunctn("help: help [BUILTIN ...]\n");
	putsFunctn("    Display information about builtin commands.\n\n");
	putsFunctn("    Displays brief summaries of builtin commands.If BUILTINs\n");
	putsFunctn("    specified, gives detailed help on all commands ");
	putsFunctn("    matching BUILTIN,\n");
	putsFunctn("    otherwise the list of help topics is printed.\n\n");
	putsFunctn("    Arguments:\n");
	putsFunctn("      BUILTIN   Builtin specifying a help topic\n\n");
	putsFunctn("    Exit Status:\n");
	putsFunctn("    Returns success unless PATTERN is not found or an invalid ");
	putsFunctn("    optn is given.\n");
}
/* ................................NUM 16 END................................*/


/* ................................NUM 17 START..............................*/
/**
 * hlpAlias - prints hel
 */
void hlpAlias(void)
{
	hlpAliasFol();
}
