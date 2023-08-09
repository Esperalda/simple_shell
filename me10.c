#include "you_shell.h"

/* ................................NUM 11 BTW................................*/
/**
 * hlpExitFuncFol - prints hel
 */
void hlpExitFuncFol(void)
{
	putsFunctn("exit: exit [n]\n");
	putsFunctn("    Exit the shell.\n\n");
	putsFunctn("    Exits the shell with a sttus of N.  ");
	putsFunctn("    If N is omitted, the exit sttus\n");
	putsFunctn("    is that of the last command executed.\n");
}
/* ................................NUM 11 END................................*/



/* ................................NUM 12 START..............................*/
/**
 * hlpEnviron - prints hel
 */
void hlpEnviron(void)
{
	hlpEnvironFol();
}
/* ................................NUM 12 BTW................................*/
/**
 * hlpEnvironFol - prints hel
 */
void hlpEnvironFol(void)
{
	putsFunctn("env: env\n");
	putsFunctn("    prints the current environment.\n\n");
	putsFunctn("    Has no options\n");
}
/* ................................NUM 12 END................................*/




/* ................................NUM 13 START..............................*/
/**
 * hlpSetEnviron - prints hel
 */
void hlpSetEnviron(void)
{
	hlpSetEnvironFol();
}
/* ................................NUM 13 BTW................................*/
/**
 * hlpSetEnvironFol - prints hel
 */
void hlpSetEnvironFol(void)
{
	putsFunctn("setenv: setenv [VARIABLE] [VALUE]\n");
	putsFunctn("    Initializes a new environment var1, ");
	putsFunctn("    or modifies an existing one.\n\n");
	putsFunctn("    VARIABLE must not have the character '='.\n");
	putsFunctn("    If no arguments are given, setenv prints ");
	putsFunctn("    the current environment.\n");
}
/* ................................NUM 13 END................................*/
