#ifndef _MAINE_H_
#define _MAINE_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;


/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @dtenviron: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **dtenviron;
	char *pid;
} data_shell;

/**
 * struct strct_list_real_strct - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct strct_list_real_strct
{
	char separator;
	struct strct_list_real_strct *next;
} strct_list;

/**
 * struct srtct_line_strct - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct srtct_line_strct
{
	char *line;
	struct srtct_line_strct *next;
} srtct_line;

/**
 * struct i_variable_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct i_variable_list
{
	int len_var;
	char *val;
	int len_val;
	struct i_variable_list *next;
} strct_variable;

/**
 * struct builtin_strct - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_strct
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_cmds;

/* ................................ START................................*/

/**
 * struct atoistruct - struct
 * @cntst: argument
 * @szst: command
 */
struct atoistruct
{
	unsigned int cntst;
	unsigned int szst;
};
typedef struct atoistruct atoitype;


int theAtoi(char *s);
atoitype theAtoiDaf_count(char *s, unsigned int count, unsigned int size,
					unsigned int pn, unsigned int m);
void authenticate_asst_Ext(void);
void authenticate_asst_ExtDaf(char *hlp);
void authenticator_asst(void);
void authenticator_asstDaf(char *hlp);
void authenticator_asst_alias(void);
void authenticator_asst_aliasDaf(char *hlp);
int error_separator_OP(char *input, int i, char last);
int error_separator_OPDaf(char *input, int i, char last, int count, int chk);
void dis_stx_error(data_shell *datash, char *input, int i, int bool);
char *dis_stx_errorDaf(char *input, int i, int chk);
int confirm_stx_error(data_shell *datash, char *input);
void empty_dif_list(strct_list **head);
void free_strct_list_MemDaf(strct_list *temp);
void empty_LiN_list(srtct_line **head);
void free_srtct_line_MemDaf(srtct_line *temp);
void emptY_Revar_list(strct_variable **head);
void free_strct_variable_MemDaf(strct_variable *temp);
srtct_line *include_LN_node_extr(srtct_line **head, char *line);
strct_variable *include_Revar_node(strct_variable **head,
		int lvar, char *var, int lval);
int test_CurrentDir(char *path, int *i);
int test_CurrentDirDaf(int *i);
char *locteOrigCmd(char *cmd, char **dtenviron);
int test_executionee(data_shell *datash);
int confirm_for_error(char *dir, data_shell *datash);
int for_command_execution(data_shell *datash);
int environ_ident(const char *nenv, const char *name);
char *getenviron(const char *name, char **dtenviron);
int shEnv(data_shell *datash);
void prepareEnvron(char *name, char *value, data_shell *datash);
int setenviron(data_shell *datash);
int unsetenviron(data_shell *datash);
int unsetenvironDaf(data_shell *datash, char *varshEnv,
					char *nameshEnv, int i, int k);
void confirmdtenvironmente(strct_variable **h, char *in, data_shell *data);
int confirm_variable(strct_variable **h, char *in, char *st, data_shell *data);
char *rest_input(strct_variable **head, char *input,
		char *new_input, int nlen);
char *rest_variable(char *input, data_shell *datash);
char *remove_command(char *in);
void aut_asst_current_dir(void);
void aut_asst_current_dirDaf(char *hlp);
char *autIToAlph(int n);
strct_list *inc_dif_node_extr(strct_list **head, char sep);
void memorycopy(void *newptr, const void *ptr, unsigned int size);
char *stringtok(char str[], const char *delim);
int is_digitFunc(const char *s);
int (*get_builtinFunPtr(char *cmd))(data_shell *datash);
int get_error(data_shell *datash, int eval);
int get_asst2(data_shell *datash);
void show_line(char **lineptr, size_t *n, char *buffer, size_t j);
void show_lineDaf(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line3(char **lineptr, size_t *n, FILE *stream);
char *scan_line(int *i_eof);
void fetch_SIGINT(int sig);
char *error_missing(data_shell *datash);
char *error_ext_shell(data_shell *datash);
char *errordtenviron_message(data_shell *datash);
char *error_RD_126(data_shell *datash);
void SH_loop(data_shell *datash);
char *exchange_character(char *input, int bool);
char *exchange_characterDaf(char *input, int i, int chk);
char *exchange_characterDafNest(char *input, int i, int chkgn);
void undo_stringForRev(char *s);
void undo_stringForRevDaf(int i, int j, char *str, char temp);
void undo_stringForRevDafNest(int j, char *str, char temp);
void change_dir_ftp(data_shell *datash);
void change_dir_loc(data_shell *datash);
void change_dir_last(data_shell *datash);
void change_dir_loc_2(data_shell *datash);
int change_dir_SH(data_shell *datash);
int duplicate_character(char *input, int i);
int basc_chararacter(char *input, int *i);
void *my_realloc(void *ptr, unsigned int old_size,
		unsigned int new_size);
char **my_realloc_hdp(char **ptr, unsigned int old_size,
		unsigned int new_size);
int fetch_lengthe(int n);
void include_nodes(strct_list **head_s, srtct_line **head_l,
		char *input);
void next_command_arg(strct_list **list_s, srtct_line **list_l,
		data_shell *datash);
int separate_command_args(data_shell *datash, char *input);
int executecute_line(data_shell *datash);
char *m_detail(char *name, char *value);
int quit_shell_op(data_shell *datash);
char *strcartenate_current_dir(data_shell *, char *, char *, char *);
char *error_getcurrent_dir(data_shell *datash);
char *print_message(char option);
void aut_asstantEnvirone(void);
void aut_asstantEnvironeDaf(char *hlp);
void aut_asstsetenvironee(void);
void aut_asstsetenvironeeDaf(char *hlp);
void aut_asstunsetenvironddd(void);
void aut_asstunsetenvirondddDaf(char *hlp);
void aut_asstant_general(void);
void aut_asstant_generalDaf(char *hlp);
char *string_cartenate(char *dest, const char *src);
char *string_copy(char *dest, char *src);
int stringcompare(char *s1, char *s2);
char *string_locate_character(char *s, char c);
int string_substr_pref_len(char *s, char *accept);
char *_strdup(const char *s);
int string_length(const char *s);
int compare_chars(char str[], const char *delim);
char **separate_line(char *input);
void dis_stx_errorDafIn2(data_shell *datshell, char *msges, char *msges2,
					char *msges3, int length, char *counter);
void dis_stx_errorDafIn(data_shell *datshell, char *msges, char *msges2,
					char *msges3, char *error, char *counter);


void freeIntMemDaf(int *temp);
void freeCharMemDaf(char *temp);
/* ................................ END................................*/



#endif
