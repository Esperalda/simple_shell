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
 * @exit_Num: number of exit that the shell will have
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
	int *exit_Num;         /* exit number */
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




char *getEnvi(const char *name, char **env);
char *pathFunc1(char *cmd, char **env, shellDType *shellVar);
char *stringDupl(char *str);
char *stringConcatFunc(char *s1, char *s2);
int strLen1(char *s);
char *stringCopyFunc(char *dest, char *src);
char *strTokenFunc(char *str, const char *delim);
char **getParam(char *buffer, shellDType *shellVar);
int execCmdFunc(char *program, char *command[], char **env, shellDType *shellVar);
void signalHandlerFunc(int x);
void signalHandlerFunc2(int x);
int getInputLine(char **buffer, size_t *bufsize, int fd);
int _strlendp(char **s);
char **shPrmptInput(int ac, char **av, size_t *bufsize,
		  char **buffer, shellDType *shellVar);
shellDType *set_struct(char *argv0, int *errn, int *exnum, int *relation,
		    int *run_able, char ***env, int *unsetnull);
int errorStrFunc(int errn, shellDType *shellVar, int exnum);
void addCmd(shellDType *shellVar, char *buffer, char *command, char **parameters);
void addPathToCmd(shellDType *shellVar, char *pathCmd);
ssize_t checkIfBuiltinFunc(shellDType *shellVar);
ssize_t exitCmdFunc(shellDType *shellVar);
int stringCompareFunc(char *s1, char *s2);
long a2iFunc(char *s);
long powerFunc(long base, long pot);
char **copyDoublePtrFunc(char **p, int old_size, int new_size);
int strLenDblePtrFunc(char **s);
char **setEnvFunc1(char **env, char *variable, char *value, shellDType *shellVar);
char **unSetEnvFunf(char **env, char *variable, shellDType *shellVar);
int isDigitFunc(int c);
int isNumFunc(char *s);
ssize_t cdCmdFunc(shellDType *shellVar);
char *delCmntFunc(char *str);


ssize_t helpCmdFunc1(shellDType *shellVar);
void putsToStd(char *s);
void helpUnSetEnv1(void);
void helpCdFunc1(void);
void helpHelpFunc1(void);
void helpAliasFunc(void);
void printsHelpFunc(void);

/*..........................START..........................*/
int Length_base(unsigned long int n, unsigned long int base);
unsigned long int Length_base_inner(unsigned long int n, unsigned long int base);
char *intToAlph(int n);
void reverseString(char *s);
char *errorStrFunc2(int errn, char *conc2, char *option);
int errorStrFunc_inner(int errn, char *conc1, char *conc2, char *err[], int z);
char *errorStrFunc2_inner(char *conc2, char *option, char *conc1);
long powerFunc_inner(long base, long res);
int stringCompareFunc_inner(char *s1, char *s2, int x, int equal);
char delCmntFunc_inner(void);
void *reAllocateMemSpce_inner(void *ptr, unsigned int old_size, unsigned int new_size,
				void *ptr2, int chk);
char pathCheckFunc1_inner(char *path, char *npath, int x, int y);
char str_concat_inner(char *s1, char *s2, char *s, int l1, int l2, int chk);
int reverseString_upper(char *s, int x);
void reverseString_lower(char *s, int x, int y, int z);
char *intToAlph_upper(int n, unsigned long int x, unsigned long int base);
int cmdMore(shellDType *shellVar, int chk);
void helpSetenv1_inner(void);

/*..........................fixed..........................*/
ssize_t envCmdFunc(shellDType *shellVar);
void envCmdFunc_lower(char **str);
ssize_t setEnvCmdFunc(shellDType *shellVar);
ssize_t unSetEnvCmdFunc(shellDType *shellVar);
char *auxChnDir2(shellDType *shellVar, char *currdir);
char *memorySet(char *s, char b, unsigned int n);
char memorySet_inner(char *s, char b, unsigned int x);
char *memoryCopyFunc(char *dest, char *src, unsigned int n);
char memoryCopyFunc_inner(char *dest, char *src, unsigned int x);
void *reAllocateMemSpce(void *ptr, unsigned int oldSze, unsigned int newSze);
void helpExit1(void);
void helpEnv1(void);
void helpSetenv1(void);
void printsHelpFunc1(void);
int strLenDblePtrFunc(char **s);
int strLenDblePtrFunc_inner(char **s, int x);

/*..........................fixed..........................*/

char *auxChnDir2_inner(char *home);
void auxChnDir_inner(shellDType *shellVar, char *currdir);
void helpExit1_inner(void);
void helpEnv1_inner(void);
void helpSetenv1_inner(void);
void helpUnSetEnv1_inner(void);
void helpCdFunc1_inner(void);
void helpHelpFunc1_inner(void);
void helpAliasFunc_inner(void);
void printsHelpFunc1_inner(void);
int _strlendp_inner(char **s, int x);
char stringCopyFunc_inner(char *dest, char *src, int i);



void freeDbPtrFunc(char **p);
int freeDbPtrFunc_inner(char **p, int z);
void freSingle(char *temp);
void printCmt(int chk);


/*..................4567891011213........END..........................*/

/*..........................NUM 27 START..........................*/
/*..........................NUM 27 BTW..........................*/
/*..........................NUM 27 BTW..........................*/
/*..........................NUM 27 END..........................*/

/*..........................NUM 1 START..........................*/
/*..........................NUM 1 BTW..........................*/
/*..........................NUM 1 END..........................*/
#endif
