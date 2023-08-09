#ifndef SHELL_H
#define SHELL_H

#define BSIZE 4

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/wait.h>

/*..........................NUM 1 START..........................*/
/*..........................NUM 1 BTW..........................*/
/*..........................NUM 1 END..........................*/

/**
 * struct shellDType - struct containing important shell info
 * @hshname: name of the shell (argv[0])
 * @buffer: full buffer written in prompt
 * @cmd: command written after prompt
 * @options: options of the command
 * @path: path of the cmd if found, else cmd itself
 * @errnum: error count
 * @exitnum: number of exit that the shell will have
 * @relation: true or false for logical operators
 * @run_able: check for running or not a command
 * @next: singly list link
 * @envCpy: copy of environment
 * @unsetnull: check for setting environment to NULL
 *
 * Description: Struct containing important shell info
 *
 */
typedef struct shellDType
{
	char *hshname;        /* Name of shell argv[0] */
	char *buffer;         /* complete line written in prompt */
	char *cmd;            /* current command */
	char **options;       /* options of current command */
	char *path;           /* absolute path of command */
	int *errnum;          /* error number for message */
	int *exitnum;         /* exit number */
	int *relation;        /* 0 Undef, 1 ||, 2 && */
	int *run_able;        /* 0 False 1 True (Is able to run)*/
	struct shellDType *next; /*adress of next cmd to run */
	char ***envCpy;       /* current environment */
	int *unsetnull;       /*check for setting environment to NULL */

} shellDType;


/**
 * struct builtIn_s - struct for built ins
 * @cmd: built in
 * @f: function of built in
 *
 * Description: Struct for calling built in functions
 *
 */
typedef struct builtIn_s
{
	char *cmd;
	ssize_t (*f)(shellDType *shellVar);
} builtIn_s;

/**
 * struct Helps_strct - struct for built ins
 * @built: built in command
 * @h: help function of built in
 *
 * Description: Struct for calling built in functions
 *
 */
typedef struct Helps_strct
{
	char *built;
	void (*h)(void);
} helps_s;




char *_getenv(const char *name, char **env);
char *_path(char *cmd, char **env, shellDType *shellVar);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, const char *delim);
char **getParameters(char *buffer, shellDType *shellVar);
int executeCmd(char *program, char *command[], char **env, shellDType *shellVar);
void signal_handler(int x);
void signal_handler2(int x);
int _getline(char **buffer, size_t *bufsize, int fd);
void free_doubpoint(char **p);
int _strlendp(char **s);
char **checkInput(int ac, char **av, size_t *bufsize,
		  char **buffer, shellDType *shellVar);
shellDType *set_struct(char *argv0, int *errn, int *exnum, int *relation,
		    int *run_able, char ***env, int *unsetnull);
int _error(int errn, shellDType *shellVar, int exnum);
void addCmd(shellDType *shellVar, char *buffer, char *command, char **parameters);
void addPathToCmd(shellDType *shellVar, char *pathCmd);
ssize_t built_ints(shellDType *shellVar);
ssize_t _exit_cmd(shellDType *shellVar);
int _strcmp(char *s1, char *s2);
long _atoi(char *s);
long _pow(long base, long pot);
char **_copydoublep(char **p, int old_size, int new_size);
int _strlendp(char **s);
char **_setenv(char **env, char *variable, char *value, shellDType *shellVar);
char **_unsetenv(char **env, char *variable, shellDType *shellVar);
int _isdigit(int c);
int _isnumber(char *s);
ssize_t _cd_cmd(shellDType *shellVar);
char *deleteComment(char *str);


ssize_t _help_cmd(shellDType *shellVar);
void _puts(char *s);
void help_unsetenv(void);
void help_cd(void);
void help_help(void);
void help_alias(void);
void printsHelp(void);

/*..........................START..........................*/
void rev_str_Daf(char *s, int x, int y, char tmp);

/*..........................END..........................*/


#endif
