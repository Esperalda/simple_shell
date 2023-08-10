#include "shell.h"



/* ................................NUM 1 START..............................*/
/**
 * string_reverse - Reverses string
 * @s: str to rev
 */
void string_reverse(char *s)
{
	int x = 0, y = 0, z;
	char temp_var;

	while (s[x])
		x++;
	z = x / 2, x = x - 1;
	while (x >= z)
	{
		temp_var  = s[y];
		s[y] = s[x];
		s[x] = temp_var;
		x--, y++;
	}
}

/* ................................NUM 1 BTW................................*/
/* ................................NUM 1 END................................*/

/* ................................NUM 2 START..............................*/
/**
 * freeCharFoluke - frees
 * @temp: head
 */

void freeCharFoluke(char *temp)
{
	free(temp);
}
/* ................................NUM 2 END................................*/

/*..........................NUM 29 START..........................*/
/**
 * lenBTen - get length
 *
 * @n: number
 * @base: base
 * Return: length
 */
int lenBTen(unsigned long int n, unsigned long int base)
{
	unsigned long int x, negNum = 0, ret;

	for (x = 0; n > 0; x++)
		n = b_Length_inner(n, base);
	ret = x + negNum;
	return (ret);
}

/*..........................NUM 29 BTW..........................*/
/**
 * b_Length - obtains length of number in base
 *
 * @n: number
 * @base: base of number
 *
 * Return: length of number
 */
unsigned long int b_Length_inner(unsigned long int n, unsigned long int base)
{
	n = n / base;
	return (n);
}
/*..........................NUM 29 END..........................*/

/**
 * intToAlp - converts
 * @n: number
 * Return: ptr
 */
char *intToAlp(int n)
{
	unsigned long int x = 0, base = 10;
	char *str;

	if (n != 0)
		str = malloc(lenBTen(n, base) + 1);
	else
		str = malloc(2), str[x] = '0', x++;

	if (str == 0)
		return (0);

	for (; n > 0; x++)
	{
		str[x] = (n % base) + '0';
		n = b_Length_inner(n, base);
	}
	str[x] = '\0';
	string_reverse(str);
	return (str);
}


/* ................................NUM 24 START..............................*/
/**
 * errorSetStr - creates str
 * @errn: numb
 * @shell_var: struct
 * @exnum: val
 * Return: 0
 */
int errorSetStr(int errn, shellDType *shell_var, int exnum)
{
	int cnt = shell_var->errnum[0], z = 0;
	char *cmd = shell_var->cmd, **optn = shell_var->options;
	char *hshname = shell_var->hshname;
	char *nustr = "brown", *conc_a = "folu", *conc_b = "foluke", *coluspc = ": ";
	char *err[] = {
		"not found", "Permission denied", "Invalid number",
		"name is NULL, points to string of length 0, or has an '=' chararacter",
		"can't cd(change dire) to ", "Invalid optn ", "Help command error",
		"Error allocating memory", "Wrong Alias", NULL
	};

	errorSetStrFolu1(errn, cnt,  z, hshname, nustr,
				conc_a, conc_b, coluspc, err);

	errorSetStrFolu2(errn, conc_a, conc_b, coluspc, err, cmd);

	if (errn > 1 && errn < 6 && errn != 3)
		conc_b = errorSub(errn, conc_b, optn[1]);
	if (conc_b == NULL)
	{
		printCmt(1);
		return (-1);
	}

	while (conc_b[z] != 0)
		z++;
	write(2, conc_b, z), printCmt(2);
	freeCharFoluke(conc_b);
	shell_var->exitnum[0] = exnum;
	return (0);
}

/* ................................NUM 24 BTW................................*/
/**
 * errorSetStrFolu2 - creates str
 * @errn: numb
 * @conc_a: struct
 * @conc_b: val
 * @coluspc: val
 * @err: val
 * @cmd: val
 * Return: 0
 */
int errorSetStrFolu2(int errn, char *conc_a, char *conc_b,
						char *coluspc, char *err[], char *cmd)
{
	freeCharFoluke(conc_b);
	conc_b = stringCatenator(conc_a, cmd);
	if (!conc_b) /*hsh: cnt: cmd*/
		return (freeCharFoluke(conc_a), printCmt(1), -1);
	freeCharFoluke(conc_a);

	conc_a = stringCatenator(conc_b, coluspc);
	if (!conc_a) /*hsh: cnt: cmd: */
		return (freeCharFoluke(conc_b), printCmt(1), -1);
	freeCharFoluke(conc_b);

	conc_b = stringCatenator(conc_a, err[errn]);
	if (!conc_b) /*hsh: cnt: cmd: error*/
		return (freeCharFoluke(conc_a), printCmt(1), -1);
	freeCharFoluke(conc_a);
	return (0);
}

/* ................................NUM 24 BTW................................*/
/**
 * errorSetStrFolu1 - creates str
 * @errn: numb
 * @cnt: struct
 * @z: val
 * @hshname: val
 * @nustr: val
 * @conc_a: val
 * @conc_b: val
 * @coluspc: val
 * @err: val
 * Return: 0
 */
int errorSetStrFolu1(int errn, int cnt, int  z, char *hshname, char *nustr,
				char *conc_a, char *conc_b, char *coluspc, char *err[])
{
	conc_a = stringCatenator(hshname, coluspc);
	if (!conc_a) /*hsh: */
		return (printCmt(1), -1);

	if (errn == 7) /* Alloc Error */
		errorSetStrFolu(errn, z, conc_a, conc_b, err);

	nustr = intToAlp(cnt);
	if (!nustr)  /* number to string */
		return (freeCharFoluke(conc_a), printCmt(1), -1);

	conc_b = stringCatenator(conc_a, nustr);
	if (!conc_b) /*hsh: cnt*/
	{
		printCmt(1);
		return (freeCharFoluke(conc_a), freeCharFoluke(nustr),  -1);
	}
	freeCharFoluke(conc_a), freeCharFoluke(nustr);

	conc_a = stringCatenator(conc_b, coluspc);
	if (!conc_a) /*hsh: cnt: */
		return (freeCharFoluke(conc_b), printCmt(1), -1);
	return (0);
}


/* ................................NUM 24 BTW................................*/
/**
 * errorSetStrFolu - creates str
 * @errn: numb
 * @z: struct
 * @conc_a: val
 * @conc_b: val
 * @err: val
 * Return: 0
 */
int errorSetStrFolu(int errn, int z, char *conc_a, char *conc_b, char *err[])
{
		conc_b = stringCatenator(conc_a, err[errn]); /*hsh: cnt: error*/
		if (!conc_b)
			return (freeCharFoluke(conc_a), printCmt(1), -1);
		freeCharFoluke(conc_a);
		while (conc_b[z] != 0)
			z++;
		write(2, conc_b, z), printCmt(2);
		freeCharFoluke(conc_b);
		return (0);
}
/* ................................NUM 24 END................................*/


/**
 * errorSub - extra modes
 * @errn: number
 * @conc_b: error
 * @optn: cmd
 * Return: pointer
 */
char *errorSub(int errn, char *conc_b, char *optn)
{
	char *conc_a, *coluspc = ": ";

	if (errn == 2) /* exit error */
	{

		conc_a = stringCatenator(conc_b, coluspc);
		if (!conc_a) /*hsh: cnt: cmd: error: */
		{
			printCmt(1);
			return (freeCharFoluke(conc_b), NULL);
		}
		freeCharFoluke(conc_b);

		conc_b = stringCatenator(conc_a, optn);

		if (!conc_b) /*hsh: cnt: cmd: error: optn*/
		{
			printCmt(1);
			return (freeCharFoluke(conc_a), NULL);
		}
		freeCharFoluke(conc_a);
	}
	if (errn > 3) /* Errors with options at end */
	{
		conc_a = stringCatenator(conc_b, optn);
		if (!conc_a) /*hsh: cnt: cmd: error optn*/
		{
			printCmt(1);
			return (freeCharFoluke(conc_b), NULL);
		}
		freeCharFoluke(conc_b);
		return (conc_a);
	}
	return (conc_b);
}


/**
 * exitCmdFunc - exit command
 * @shell_var: struct
 * Return: -1 if error
 */
ssize_t exitCmdFunc(shellDType *shell_var)
{
	long exit_value;

	if (shell_var->options[1] == NULL || isNumba(shell_var->options[1]))
	{
		exit_value = atoiFol(shell_var->options[1]);

		if (exit_value >= 0 && exit_value < INT_MAX)
		{
			if (exit_value > 255)
				exit_value %= 256;
			if (shell_var->options[1] == NULL)
				exit_value = shell_var->exitnum[0];
			free(*(shell_var->options));
			free(shell_var->options);
			if (*(shell_var->envCpy))
				freeDobleCharPntrFoluke(*(shell_var->envCpy));
			free(shell_var);
			exit(exit_value);
		}
	}
	errorSetStr(2, shell_var, 2);
	free(shell_var->options);
	return (-1);
}

/**
 * envCmd - env command
 * @shell_var: struct
 * Return: 1
 */
ssize_t envCmd(shellDType *shell_var)
{
	char **str;
	int chckr = 1;

	if (*(shell_var->envCpy) == NULL)
	{
		printCmt(3);
		shell_var->exitnum[0] = 2;
		free(shell_var->options);
		return (-1);
	}

	str = *(shell_var->envCpy);

	if (shell_var->options[1] == NULL)
	{
		for (; str && *str; str++)
		{
			write(1, *str, stringLengthFunc(*str));
			printCmt(2);
		}
	}
	else
	{
		errorSetStr(0, shell_var, 2);
		chckr = -1;
	}

	free(shell_var->options);
	return (chckr);
}
/**
 * setEnvironCmd - setenv command
 * @shell_var: struct
 * Return: 1
 */
ssize_t setEnvironCmd(shellDType *shell_var)
{
	char **nenviron, *var1 = NULL, *val1 = NULL;

	if (shell_var->options[1])
	{
		var1 = shell_var->options[1];
		if (!shell_var->options[2])
		{
			printCmt(4);
			shell_var->exitnum[0] = 2;
			free(shell_var->options);
			return (-1);
		}
		else
			val1 = shell_var->options[2];
	}
	if (var1 == 0)
	{
		printCmt(5);
		shell_var->exitnum[0] = 2;
		free(shell_var->options);
		return (-1);
	}

	nenviron = setEnvironm(*(shell_var->envCpy), var1, val1, shell_var);

	if (nenviron == 0)
	{
		free(shell_var->options);
		return (-1);
	}

	*(shell_var->envCpy) = nenviron;
	free(shell_var->options);
	return (1);
}
/**
 * unSetEnvironComnd - unsetenv command
 * @shell_var: struct
 * Return: 1
 */
ssize_t unSetEnvironComnd(shellDType *shell_var)
{
	char **nenviron, *var1 = NULL;

	if (shell_var->options[1])
		var1 = shell_var->options[1];
	else
	{
		shell_var->exitnum[0] = 2;
		printCmt(6);
		return (free(shell_var->options), -1);
	}

	if (var1 == 0)
	{
		free(shell_var->options);
		return (1);
	}

	nenviron = unSetEnviron(*(shell_var->envCpy), var1, shell_var);

	if (nenviron == 0 && shell_var->unsetnull[0] == 0)
	{
		free(shell_var->options);
		shell_var->exitnum[0] = 2;
		return (-1);
	}

	*(shell_var->envCpy) = nenviron;
	free(shell_var->options);
	return (1);
}

/**
 * chckBuiltIn - checks if the command is built in
 * @shell_var: struct
 * Return: On fail 0
 */
ssize_t chckBuiltIn(shellDType *shell_var)
{
	builtIn_s ops[] = {
		{"exit", exitCmdFunc},
		{"env", envCmd},
		{"setenv", setEnvironCmd},
		{"unsetenv", unSetEnvironComnd},
		{"cd", cDirCmnd},
		{"help", hlpComnd}
	};

	int x = 6, builtcheck; /* lenght of ops array */

	while (x--)
		if (!stringCompare(shell_var->cmd, ops[x].cmd))
		{
			shell_var->errnum[0] += 1;
			builtcheck = ops[x].f(shell_var);
			if (builtcheck == 1)
				shell_var->exitnum[0] = 0;
			return (builtcheck);
		}

	return (0);
}


/* ................................NUM 3 START..............................*/

/**
 * secAuxCd - auxiliary built in func of cd
 * @shell_var: struct
 * @cur_dir: current dir
 * Return: pointer
 */
char *secAuxCd(shellDType *shell_var, char *cur_dir)
{
	char *home, *dire = NULL;

	(void) cur_dir;
	home = fetchEnviron("HOME", *(shell_var->envCpy));
	if (home)
		dire = secAuxCdFol(home, dire);

	return (dire);
}
/* ................................NUM 3 BTW................................*/
/**
 * secAuxCdFol - auxiliary built in func of cd
 * @home: struct
 * @dire: current dir
 * Return: pointer
 */
char *secAuxCdFol(char *home, char *dire)
{
	dire = home + 5;
	return (dire);
}
/* ................................NUM 3 END................................*/


/**
 * firstAuxCd - auxiliary built in func of cd
 * @shell_var: struct
 * @cur_dir: current dir
 * Return: Pointe
 */
char *firstAuxCd(shellDType *shell_var, char *cur_dir)
{
	char *oldpwd2 = NULL, *oldpwDir = NULL, *dire = NULL;

	if (shell_var->options[1] && shell_var->options[2])
	{
		printCmt(7);
		shell_var->exitnum[0] = 2;
		free(shell_var->options);
		freeCharFoluke(cur_dir);
		return (dire);
	}

	oldpwd2 = stringDuplicateFunc(fetchEnviron("OLDPWD", *(shell_var->envCpy)));
	if (oldpwd2)
		oldpwDir = stringDuplicateFunc(oldpwd2 + 7), free(oldpwd2);
	if (!oldpwd2)
	{
		oldpwDir = stringDuplicateFunc(cur_dir);
		/* free(oldpwDir), free(shell_var->options), free(cur_dir); */
		/* return (shell_var->exitnum[0] = 2, NULL); */
	}

	dire = oldpwDir;

	return (dire);
}

/**
 * cDirCmnd - built in command for cd
 * @shell_var: struct
 * Return: 1
 */
ssize_t cDirCmnd(shellDType *shell_var)
{
	char *cur_dir = NULL, *dire = NULL, **nenviron, *oldpwDir = NULL;
	int exit = 1, chckr = 1, checkerSubtrctn = 0;

	cur_dir = getcwd(NULL, 4096);
	if (!cur_dir)
		return (errorSetStr(4, shell_var, 2), free(shell_var->options), -1);
	if (!shell_var->options[1] ||
			(shell_var->options[1] && (!stringCompare(shell_var->options[1], "~"))))
	{
		dire = secAuxCd(shell_var, cur_dir);
		if (!dire)
			return (free(shell_var->options), freeCharFoluke(cur_dir), 1);
	}
	else
		if (!stringCompare(shell_var->options[1], "-"))
		{
			dire = firstAuxCd(shell_var, cur_dir);
			if (!dire)
				return (free(shell_var->options), freeCharFoluke(cur_dir), 1);
			checkerSubtrctn = 1;
		}
		else
			dire = shell_var->options[1];
	if (dire)
		chckr = chdir(dire);
	if (chckr == 0 && checkerSubtrctn == 1)
		write(1, dire, stringLengthFunc(dire)), printCmt(2);
	if (chckr != 0)
		errorSetStr(4, shell_var, 2), exit = -1;
	else
	{
		nenviron = setEnvironm(*(shell_var->envCpy), "PWD", dire, shell_var);
		*(shell_var->envCpy) = nenviron;
		nenviron = setEnvironm(*(shell_var->envCpy), "OLDPWD", cur_dir, shell_var);
		*(shell_var->envCpy) = nenviron;
	}
	free(shell_var->options), freeCharFoluke(cur_dir), freeCharFoluke(oldpwDir);
	if (checkerSubtrctn == 1)
		freeCharFoluke(dire);
	return (exit);
}

/* ................................500..............................*/




/* ................................NUM 4 START..............................*/
/**
 * powerFunc - gets the result of base to ower
 * @base: base
 * @pot: power
 *
 * Return: result
 */
long powerFunc(long base, long pot)
{
	long x = 0, res = 1;

	for (x = 0; x < pot; x++)
		powerFuncFol(base, res);

	return (res);
}

/* ................................NUM 4 BTW................................*/
/**
 * powerFuncFol - gets the result of base to ower
 * @base: base
 * @res: power
 * Return: result
 */
long powerFuncFol(long base, long res)
{
	res *= base;
	return (res);
}
/* ................................NUM 4 END................................*/


/* ................................NUM 5 START..............................*/

/**
 * atoiFol - convert char to int
 * @s: char input
 * Return: input
 */

long atoiFol(char *s)
{
	long x = 0, k = 0, len = 0, toRet = 0, subtracn = 0, offset = 48;
	unsigned long result = 0;


	if (!s)
		return (0);

	for (x = 0; *(s + x) != '\0'; x++)
	{
		if (*(s + x) >= 48 && *(s + x) <= 57)
			len++;
		else if (len != 0)
			break;

		if (*(s + x) == '-')
			subtracn = atoiFolFol(subtracn);
	}

	for (x--; len > 0; x--, k++, len--)
		result +=  (*(s + x) - offset) * powerFunc(10, k);

	toRet = (subtracn % 2 != 0) ? result * (-1) : result;

	return (toRet);
}

/* ................................NUM 5 BTW................................*/
/**
 * atoiFolFol - convert char to int
 * @subtracn: char
 * Return: input
 */

long atoiFolFol(long subtracn)
{
	return (subtracn++);
}
/* ................................NUM 5 END................................*/


/* ................................NUM 6 START..............................*/

/**
 * stringCompare - compares two strings
 * @s_one: str1
 * @s_two: str
 * Return: 0 if strings are eql or another val1 if not
 */
int stringCompare(char *s_one, char *s_two)
{
	int x = 0, eql = 0;

	for (x = 0; (*(s_one + x) || *(s_two + x)) && !eql; x++)
		if (*(s_one + x) != *(s_two + x))
			eql = stringCompareFol(s_one, s_two, x);

	return (eql);
}
/* ................................NUM 6 BTW................................*/
/**
 * stringCompareFol - compares two strings
 * @s_one: str1
 * @s_two: str
 * @x: str
 * Return: 0 if strings are eql or another val1 if not
 *
 */
int stringCompareFol(char *s_one, char *s_two, int x)
{
	int eql;

	eql = *(s_one + x) - *(s_two + x);
	return (eql);
}
/* ................................NUM 6 END................................*/

/**
 * isDigitFunc - checks if a character is a digit num
 * @c: character
 * Return: 1
 *
 */
int isDigitFunc(int c)
{
	return ((c >= 48 && c <= 57) ? 1 : 0);
}

/**
 * isNumba - checks if a str has numbers
 * @s: str
 * Return: 1
 */
int isNumba(char *s)
{
	for (; *s; s++)
		if (!isDigitFunc(*s))
			return (0);
	return (1);
}


/**
 * chckInputFunc - checks for input
 * @ac: numb of main arguments
 * @av: main arg
 * @bufsize: size of buffer
 * @buffer: buffer
 * @shell_var: struct of shell info
 * Return: On success 1.
 */
char **chckInputFunc(int ac, char **av, size_t *bufsize,
		   char **buffer, shellDType *shell_var)
{
	ssize_t charctrs;
	char **command;
	int exitnum;

	if (ac == 1)
	{
		if (isatty(STDIN_FILENO))
			printCmt(8);
		charctrs = getline(buffer, bufsize, stdin);

		if (charctrs == -1)
		{
			exitnum = shell_var->exitnum[0];
			freeCharFoluke(*buffer);
			if (*(shell_var->envCpy))
				freeDobleCharPntrFoluke(*(shell_var->envCpy));
			free(shell_var);
			if (isatty(STDIN_FILENO))
				printCmt(2);
			exit(exitnum);
		}
		if (**buffer == '#' || !charctrs || **buffer == '\n')
			return (NULL);
		*buffer = delComnt(*buffer);
		command = fetchParam(*buffer, shell_var);
	}
	else
	{
		command = malloc(sizeof(char *) * (ac - 1));
		if (!command)
		{
			errorSetStr(7, shell_var, 1);
			return (NULL);
		}

		command[ac - 1] = '\0';
		while (ac--)
			command[ac - 1] = av[ac];
	}
	return (command);
}


/* ................................NUM 7 START..............................*/

/**
 * delComnt - deletes a commnet
 * @str: str
 * Return: pointer
 */
char *delComnt(char *str)
{
	char *C_org = str;

	for (; str && *str; str++)
		if (*str == '#' && *(str - 1) == ' ')
		{
			*str = delComntFol(*str);
			break;
		}

	return (C_org);
}
/* ................................NUM 7 BTW................................*/
/**
 * delComntFol - deletes a commnet
 * @str: str
 * Return: pointer
 */
char delComntFol(char str)
{
	str = '\0';
	return (str);
}
/* ................................NUM 7 END................................*/


/**
 * excuteCmd - creates a child prcss to execute a cmd
 * @program: command
 * @command: arg
 * @env: curr env
 * @shell_var: struct
 * Return: pointer
 */
int excuteCmd(char *program, char *command[], char **env,
			shellDType *shell_var)
{
	pid_t prcss, sttus;
	int execSts = 0, wait1_Sts = 0;

	prcss = fork();
	signal(SIGINT, sigHandlr2);
	if (prcss == -1)
	{
		printCmt(9);
		exit(-1);
	}
	if (prcss == 0)
	{

		execSts = execve(program, command, env);
		if (execSts == -1)
		{
			_exit(-1);
		}
	}
	else
	{
		wait1_Sts = wait(&sttus);
		signal(SIGINT, sigHandlr);
		if (wait1_Sts == -1)
			exit(-1);
		if (WEXITSTATUS(sttus) == 0)
			shell_var->exitnum[0] = 0;
		else
			shell_var->exitnum[0] = 2;
	}

	shell_var->errnum[0] += 1;
	return (0);
}


/**
 * fetchEnviron - fetch an environ var
 *
 * @name: name
 * @env: current env
 * Return: pointer to the val1 in the environment, *
 */
char *fetchEnviron(const char *name, char **env)
{
	int x, y, check, z = 0;

	if (!env)
		return (NULL);

	while (name[z] != 0)
		z++;

	for (x = 0; env[x] != 0; x++)
	{
		for (check = 0, y = 0; y < z && env[x][y] != 0; y++)
			if (env[x][y] == name[y])
				check++;
		if (check == z && env[x][check] == '=')
			return (env[x]);
	}

	return (NULL);
}


/* ................................NUM 8 START..............................*/
/**
 * memorySet - fills memory
 * @s: memory
 * @b: constant
 * @n: first n byte
 * Return: On success 1.
 */
char *memorySet(char *s, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		s[x] = memorySetFol(s, b, x);
	return (s);
}
/* ................................NUM 8 BTW................................*/
/**
 * memorySetFol - fills memory
 * @s: memory
 * @b: constant
 * @x: first n byte
 * Return: On success 1.
 */
char memorySetFol(char *s, char b, unsigned int x)
{
	s[x] = b;
	return (s[x]);
}
/* ................................NUM 8 END................................*/


/* ................................NUM 9 START..............................*/
/**
 * memoryCopy - copies mem
 * @dest: destination
 * @src: source
 * @n: size of memory
 *
 * Return: Returns memory copied
 */
char *memoryCopy(char *dest, char *src, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		dest[x] = memoryCopyFol(dest, src, x);
	return (dest);
}
/* ................................NUM 9 BTW................................*/
/**
 * memoryCopyFol - copies mem
 * @dest: destination
 * @src: source
 * @x: size of memory
 *
 * Return: Returns memory copied
 */
char memoryCopyFol(char *dest, char *src, unsigned int x)
{
	dest[x] = src[x];
	return (dest[x]);
}
/* ................................NUM 9 END................................*/

/**
 * reAllocateFunc - reallocates a memory block
 * @ptr: pointer
 * @oldSize: current size
 * @nw_size: size of memory
 * Return: Pointer
 */
void *reAllocateFunc(void *ptr, unsigned int oldSize, unsigned int nw_size)
{
	void *pointr3;

	if (oldSize == nw_size)
		return (ptr);

	if (ptr == NULL)
	{
		pointr3 = malloc(nw_size);
		if (pointr3 == 0)
			return (0);
		freeCharFoluke(ptr);
		return (pointr3);
	}

	if (nw_size == 0 && ptr != NULL)
	{
		freeCharFoluke(ptr);
		return (0);
	}

	pointr3 = malloc(nw_size);

	if (pointr3 == 0)
		return (0);

	pointr3 = memorySet(pointr3, '\0', nw_size);

	memoryCopy(pointr3, ptr, oldSize);
	freeCharFoluke(ptr);
	return (pointr3);
}
/**
 * fetchLine - read string/line from an input stream
 * @buffer: pointer
 * @bufsize: current size
 * @fd: stream
 * Return: Number
 */
int fetchLine(char **buffer, size_t *bufsize, int fd)
{
	static char *buff;
	static size_t size;
	unsigned int len = 0, x = 0, sizeold;
	int r;

	if (*bufsize == 0)
		size = BSIZE;
	if (*buffer == 0)
	{
		buff = malloc(sizeof(char) * size);
		if (!buff)
			return (printCmt(1), 0);
		*buffer = buff;
	}
	buff = memorySet(buff, '\0', size);
	do {

		r = read(fd, buff + len, BSIZE);
		if (r >= 0)
			x = len, len += r;
		if (r == -1 || r == 0)
			return (-1);
		if  (len >= size)
		{
			sizeold = size, size += BSIZE;
			buff = reAllocateFunc(buff, sizeold, size);
			if (!buff)
				return (printCmt(1), 0);
		}
		for (; x < len; x++)
		{
			if (buff[x] == '\n')
			{
				*buffer = buff, *bufsize = size;
				return (len);
			}
		}

	} while (1);
	return (len);
}

/**
 * fetchParam - obtains parameters
 * @raw_buffer: Rbuffer
 * @shell_var: struct of shell info
 * Return: On success 1.
 */
char **fetchParam(char *raw_buffer, shellDType *shell_var)
{
	char **buffer, *cp_raw_buffer;
	ssize_t cnt = 0, i = 0;

	cp_raw_buffer = stringDuplicateFunc(raw_buffer);
	if (!cp_raw_buffer)
	{
		errorSetStr(7, shell_var, 1);
		exit(-1);
	}

	if (stringTokenizeFunc(cp_raw_buffer, " \n"))
		cnt++;
	else
	{
		free(cp_raw_buffer);
		return (NULL);
	}
	while (stringTokenizeFunc(NULL, " \n"))
		cnt++;

	free(cp_raw_buffer);
	buffer = malloc(sizeof(char *) * (cnt + 1));
	if (!buffer)
	{
		errorSetStr(7, shell_var, 1);
		exit(-1);
	}
	buffer[0] = stringTokenizeFunc(raw_buffer, " \n");
	for (i = 1; i < cnt && buffer[i - 1]; i++)
		buffer[i] = stringTokenizeFunc(NULL, " \n");

	if (!buffer[i - 1])
	{
		freeDobleCharPntrFoluke(buffer);
		return (NULL);
	}

	buffer[i] = NULL;
	return (buffer);
}

/* ................................1000..............................*/




/* ................................NUM 10 START..............................*/

/**
 * pthChcker - check current dir
 * @path: path
 * Return: Pointer to adress of new PATH
 *
 */

char *pthChcker(char *path)
{
	char *nwpath;
	int x, y, nwsize, cnt = 0;

	for (x = 0; path[x]; x++)
	{

		if (path[x] == '=' && path[x + 1] == ':')
			cnt++;
		if (path[x] == ':' && path[x + 1] == ':')
			cnt++;
		if (path[x] == ':' && path[x + 1] == '\0')
			cnt++;
	}
	if (cnt == 0)
		return (0);
	nwsize = stringLengthFunc(path) + 1 + cnt;
	nwpath = malloc(sizeof(char) * nwsize);

	for (x = 0, y = 0; x < nwsize; x++, y++)
	{
		if (path[y] == '=' && path[y + 1] == ':')
		{
			nwpath[x] = pthChckerFol(path, nwpath, x, y);
			continue;
		}
		if (path[y] == ':' && path[y + 1] == ':')
		{
			nwpath[x] = pthChckerFol(path, nwpath, x, y);
			continue;
		}
		if (path[y] == ':' && path[y + 1] == '\0')
		{
			nwpath[x] = pthChckerFol(path, nwpath, x, y);
			continue;
		}
		nwpath[x] = path[y];
	}
	freeCharFoluke(path);
	return (nwpath);
}


/* ................................NUM 22 START..............................*/
/**
 * printCmt - Reverses string
 * @chk: str to rev
 */
void printCmt(int chk)
{
	switch (chk)
	{
		case 1:
			write(2, "Memory Error", 22);
			break;
		case 2:
			write(2, "\n", 1);
			break;
		case 3:
			write(2, "Environment is Null\n", 36);
			break;
		case 4:
			write(2, "Invalid VALUE\n", 14);
			break;
		case 5:
			write(2, "Invalid VARIABLE\n", 17);
			break;
		case 6:
		    write(2, "Please provide an argument\n", 27);
			break;
		case 7:
		    write(2, "cd: too many arguments\n", 23);
			break;
		case 8:
		    write(1, "prompt by foluke $ ", 19);
			break;
		case 9:
		    write(2, "Fork Error", 10);
			break;
		case 10:
			write(1, "\nprompt by foluke $ ", 20);
			break;
		case 11:
			write(1, "\n", 1);
			break;
		case 12:
			write(2, "VARIABLE not found\n", 19);
			break;
	}
}
/* ................................NUM 22 END................................*/



/* ................................NUM 10 BTW................................*/
/**
 * pthChckerFol - check current dir
 * @path: path
 * @nwpath: path
 * @x: path
 * @y: path
 * Return: Pointer to adress of new PAT
 */

char pthChckerFol(char *path, char *nwpath, int x, int y)
{
	nwpath[x] = path[y], nwpath[x + 1] = '.', x++;
	return (nwpath[x]);
}
/* ................................NUM 10 END................................*/


/**
 * searchPath - Searches for a cmd
 * @cmd: string
 * @env: current environment
 * @shell_var: stru
 * Return: Point
 */

char *searchPath(char *cmd, char **env, shellDType *shell_var)
{
	char *path, *path2;
	struct stat st;
	char *token, *concat, *concatenat2, *pathChck, *delim = ":=";
	int x;

	for (x = 0; cmd[x]; x++)
		if (cmd[x] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (concat = stringCatenator(cmd, '\0'));
			else
				return (0);
		}

	path2 = fetchEnviron("PATH", env);
	(void) shell_var;
	if (!path2)
		return (0);
	path = stringDuplicateFunc(path2);
	pathChck = pthChcker(path);
	if (pathChck)
		path = pathChck;
	token = stringTokenizeFunc(path, delim);
	for (token = stringTokenizeFunc(0, delim);
		token; token = stringTokenizeFunc(0, delim))
	{
		concat = stringCatenator(token, "/");
		concatenat2 = stringCatenator(concat, cmd);
		freeCharFoluke(concat);
		if (stat(concatenat2, &st) == 0)
		{
			/*Found the command in PATH*/
			free(path);
			return (concatenat2);
		}
		freeCharFoluke(concatenat2);
	}

	freeCharFoluke(path);
	return (0);
}




/**
 * putsFunctn - prints string to std output
 * @s: strin
 */
void putsFunctn(char *s)
{
	write(1, s, stringLengthFunc(s));
}




/* ................................NUM 11 START..............................*/
/**
 * hlpExitFunc - prints hel
 */
void hlpExitFunc(void)
{
	hlpExitFuncFol();
}
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


/**
 * hlpComnd - help of built-in commands
 * @shell_var: struc
 * Return: 1 if succesful, -1 if fail
 */
ssize_t hlpComnd(shellDType *shell_var)
{
	int check = 1, bchck = 0;
	helps_s help[] = {
		{"exit", hlpExitFunc},
		{"env", hlpEnviron},
		{"setenv", hlpSetEnviron},
		{"unsetenv", hlpUnSetEnviron},
		{"cd", cdHlp},
		{"help", hlpHlp},
		{"alias", hlpAlias}
	};

	int i = 7;
	int p = 1;

	for (; shell_var->options[p]; p++, i = 7)
	{
		while (i--)
			if (!stringCompare(shell_var->options[p], help[i].built))
				help[i].h(), bchck = 1;
	}
	if (shell_var->options[1] == NULL)
	{
		prntHlp();
		bchck = 1;
	}
	if (bchck == 0)
	{
		check = -1;
		errorSetStr(6, shell_var, 2);
	}

	free(shell_var->options);
	return (check);
}


/* ................................NUM 14 START..............................*/
/**
 * hlpUnSetEnviron - prints hel
 */
void hlpUnSetEnviron(void)
{
	hlpUnSetEnvironFol();
}
/* ................................NUM 14 BTW................................*/
/**
 * hlpUnSetEnvironFol - prints hel
 */
void hlpUnSetEnvironFol(void)
{
	putsFunctn("unsetenv: unsetenv [VARIABLE]\n");
	putsFunctn("    Initializes a new environment var1, or ");
	putsFunctn("    modifies an existing one.\n\n");
	putsFunctn("    VARIABLE must not have the character '='.\n");
	putsFunctn("    If no arguments are given, setenv prints the current ");
	putsFunctn("    environment.\n");
}
/* ................................NUM 14 END................................*/


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
/* ................................NUM 17 BTW................................*/
/**
 * hlpAliasFol - prints hel
 */
void hlpAliasFol(void)
{
	putsFunctn("alias: alias alias [name[='val1'] ...]\n");
	putsFunctn("    Define or display aliases.\n\n");
	putsFunctn("    Without arguments, `alias' prints the list of aliases ");
	putsFunctn("    in the reusable\n");
	putsFunctn("    form `alias NAME=VALUE' on standard output.\n\n");
	putsFunctn("     Otherwise, an alias is defined for each NAME whose ");
	putsFunctn("    VALUE is given.\n");
	putsFunctn("    A trailing space in VALUE causes the next word to ");
	putsFunctn("    be checked for\n");
	putsFunctn("    alias substitution when the alias is expanded.\n\n");
	putsFunctn("    Exit Status:\n");
	putsFunctn("    alias returns true unless a NAME is supplied for which ");
	putsFunctn("    no alias has been\n");
	putsFunctn("    defined.\n");
}
/* ................................NUM 17 END................................*/


/* ................................NUM 18 START..............................*/
/**
 * prntHlp - prints hel
 */
void prntHlp(void)
{
	prntHlpFol();
}
/* ................................NUM 18 BTW................................*/
/**
 * prntHlpFol - prints hel
 */
void prntHlpFol(void)
{
	putsFunctn("Shell HSH, version 1.0(1)-release (x86_64-pc-linux-gnu)\n");
	putsFunctn("These shell commands are defined internally.\n");
	putsFunctn("Type `help' to see this list.\n");
	putsFunctn("Type help  'BUILTIN'' to find out more about ");
	putsFunctn("the function 'BUILTIN'.\n\n");
	putsFunctn(" exit [n]\n");
	putsFunctn(" env\n");
	putsFunctn(" setenv [VARIABLE] [VALUE]\n");
	putsFunctn(" unsetenv [VARIABLE]\n");
	putsFunctn(" cd [DIRECTORY]\n");
	putsFunctn(" help [BUILTIN ...]\n");
	putsFunctn(" alias [name[='val1'] ...]\n");
}
/* ................................NUM 18 END................................*/

/**
 * freeDobleCharPntrFoluke - frees a double pointe
 * @p: double pointer to free
 */
void freeDobleCharPntrFoluke(char **p)
{
	int x, z = 0;

	while (p[z] != 0)
		z++;

	for (x = 0; x < z; x++)
	{
		freeCharFoluke(p[x]);
	}
	free(p);
}


/**
 * cpyDoblePtr - copies an array of string
 *
 * @p: double pointe
 * @oldSize: original siz
 * @nw_size: size of copy
 * Return: Pointer malloec
 */
char **cpyDoblePtr(char **p, int oldSize, int nw_size)
{
	char **copy;
	int x, copSize;

	if (!p && (oldSize == nw_size))
		return (NULL);

	if (nw_size < oldSize)
	{
		copSize = nw_size;
		copy = malloc(sizeof(char *) * (copSize + 1));
	}
	else
	{
		copSize = oldSize;
		copy = malloc(sizeof(char *) * (nw_size + 1));
	}
	if (copy == 0)
		return (0);

	if (p)
		for (x = 0; x < copSize; x++)
		{
			copy[x] = stringDuplicateFunc(p[x]);
			if (copy[x] == 0)
			{
				x--;
				for (; x >= 0; x--)
					freeCharFoluke(copy[x]);
				freeDobleCharPntrFoluke(copy);
				return (0);
			}
		}
	/* Add Null in the end */
	copy[nw_size] = '\0';

	return (copy);
}



/**
 * strLenPtr - calculates length of double pointe
 * @s: double pointer
 * Return: Length of double pointer
 */
int strLenPtr(char **s)
{
	int x = 0;

	if (!s)
		return (0);

	while (s[x] != NULL)
		x++;
	return (x);
}



/**
 * setEnvironm - overwrite an en
 * @env: array of env variables
 * @var1: env var
 * @val1: val
 * @shell_var: struc
 * Return: 0 on success, -1 on error
 */
char **setEnvironm(char **env, char *var1, char *val1, shellDType *shell_var)
{
	int x, y, check, z = 0, env6 = 0;
	char *catEnvs1, *catEnvs2, *DupCp, **copy;

	if (stringLengthFunc(var1) == 0 || var1 == 0)
		return (errorSetStr(3, shell_var, 1), NULL);
	catEnvs2 = stringCatenator(var1, "=");
	if (catEnvs2 == 0)
		return (errorSetStr(3, shell_var, 1), NULL);
	catEnvs1 = stringCatenator(catEnvs2, val1), free(catEnvs2);
	if (catEnvs1 == 0)
		return (errorSetStr(3, shell_var, 1), NULL);
	z = stringLengthFunc(var1), env6 = strLenPtr(env);
	for (x = 0; env && env[x] != 0; x++)
	{
		for (check = 0, y = 0; y < z && env[x][y] != 0; y++)
		{
			if (var1[y] == '=')
				return (free(catEnvs1), errorSetStr(3, shell_var, 2), NULL);
			if (env[x][y] == var1[y])
				check++;
		}
		if (check == z && env[x][check] == '=')
		{
			free(env[x]), DupCp = stringDuplicateFunc(catEnvs1), free(catEnvs1);
			if (DupCp == 0)
				return (errorSetStr(3, shell_var, 1), NULL);
			return (env[x] = DupCp, env);
		}
	}
	copy = cpyDoblePtr(env, env6, env6 + 1);
	if (env)
		freeDobleCharPntrFoluke(env);
	if (copy == 0)
		return (free(catEnvs1), errorSetStr(3, shell_var, 1), NULL);
	env = copy, DupCp = stringDuplicateFunc(catEnvs1), free(catEnvs1);
	if (DupCp == 0)
		return (errorSetStr(3, shell_var, 1), NULL);
	return (env[env6] = DupCp, env);
}


/**
 * sigHandlr - handles ctrl + c during runtime
 * @x: unused val
 */
void sigHandlr(int x)
{
	(void) x;
	printCmt(10);
}



/**
 * sigHandlr2 - handles ctrl + c during commd executn
 * @x: unused val1
 */
void sigHandlr2(int x)
{
	(void) x;
	printCmt(11);
}


/* ................................NUM 19 START..............................*/
/**
 * stringCatenator - concatenates strings
 * @s_one: str
 * @s_two: strin
 * Return: Pointer
 */
char *stringCatenator(char *s_one, char *s_two)
{
	int l1, l2, i, j;
	char *s;
	/* char *nul = ""; */

	if (s_one == NULL)
		s_one = stringCatenatorFol();
	if (s_two == NULL)
		s_two = stringCatenatorFol();

	l1 = 0, l2 = 0;
	while (*(s_one + l1))
		l1++;
	while (*(s_two + l2))
		l2++;

	s = malloc(sizeof(char) * (l1 + l2 + 1));

	if (s == 0)
		return (0);

	for (i = 0; i < l1; i++)
		*(s + i) = *(s_one + i);

	for (i = 0, j = l1; i <= l2; j++, i++)
		*(s + j) = *(s_two + i);

	return (s);
}
/* ................................NUM 19 BTW................................*/
/**
 * stringCatenatorFol - concatenates strings
 * Return: Pointer
 */
char *stringCatenatorFol(void)
{
	char *sx;

	return (sx = "");
}

/* ................................NUM 19 END................................*/


/* ................................NUM 20 START..............................*/
/**
 * stringCopy - copy source ont destinated
 * @dest: target
 * @src: source
 * Return: dest
 * On error: -1
 */
char *stringCopy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; *(src + i) != '\0'; i++)
		stringCopyFol(dest, src, i);
		/* *(dest + i) = *(src + i); */

	stringCopyFol(dest, src, i);
	/* *(dest + i) = *(src + i); */ /* adding '\0' character */

	return (dest);
}
/* ................................NUM 20 BTW................................*/
/**
 * stringCopyFol - copy source onto destinated
 * @destinatn: target
 * @source: source
 * @i: source
 * Return: dest
 */
char stringCopyFol(char *destinatn, char *source, int i)
{
	*(destinatn + i) = *(source + i);
	return (*(destinatn + i));
}
/* ................................NUM 20 END................................*/



/**
 * stringLengthFunc - function that returns the length of string
 * @s: string
 * Return: -1 inapropiate entr
 */

int stringLengthFunc(char *s)
{
	return ((!*s) ? 0 : 1 + stringLengthFunc(s + 1));
}


/**
 * stringDuplicateFunc - function that returns a pointer to a newly
 * allocated memoty space
 * @str: source
 * Return: address
 * On error: -1
 */

char *stringDuplicateFunc(char *str)
{
	char *arr;

	if (!str)
		return (NULL);

	arr = malloc((stringLengthFunc(str) * sizeof(*arr)) + 1);

	if (!arr)
		return (NULL);

	stringCopy(arr, str);

	return (arr);
}


/**
 * stringTokenizeFunc - tokenizes a string
 *
 * @str: string to operate
 * @delim: delimiter
 * Return: pointer to string
 */
char *stringTokenizeFunc(char *str, const char *delim)
{
	const char *C_org = delim;
	int issEql = 1, issGetInto = 0;
	static char *step, *stepNull;
	static int isEnd;

	if (str)
		isEnd = 0;
	if (isEnd)
		return (NULL);
	step = (str) ? str : (stepNull + 1);
	if (str)
		stepNull = str;
	else
		str = step;
	while (*str && issEql)
	{
		issEql = 0;
		for (delim = C_org; *delim; delim++)
			if (*str == *delim)
				issEql = 1;
		str = (!issEql) ? str : str + 1;
		isEnd = (*str) ? 0 : 1;
		if (isEnd)
			return (NULL);
	}
	step = str;
	while (*str && !issEql)
	{
		issEql = 0;
		for (delim = C_org; *delim; delim++)
			if (*str == *delim)
			{
				issGetInto = 1, issEql = 1;
				isEnd = (*(str + 1)) ? 0 : 1, *str = '\0';
			}
		str = (issEql) ? str : str + 1;
		if (!issGetInto && !*str)
			isEnd = 1;
	}
	return (stepNull = str, step);
}


/**
 * cpyDoblePtrDel - copies an array of string
 * @p: double pointe
 * @nw_size: siz
 * @jump: val to skip during operation
 * Return: Pointer malloec
 */
char **cpyDoblePtrDel(char **p, int nw_size, int jump)
{
	char **copy;
	int i, j, copSize;

	copSize = nw_size;
	copy = malloc(sizeof(char *) * (copSize + 1));
	if (copy == 0)
		return (0);

	for (i = 0, j = 0; j < copSize; i++, j++)
	{
		if (i == jump)
			i++;
		copy[j] = stringDuplicateFunc(p[i]);
		if (copy[j] == 0)
		{
			j--;
			for (; j >= 0; j--)
				free(copy[j]);
			freeDobleCharPntrFoluke(copy);
			return (0);
		}
	}

	copy[nw_size] = '\0';

	return (copy);
}

/**
 * unSetEnviron - unsets an enviromenta
 * @env: array of en
 * @var1: env var
 * @shell_var: struc
 * Return: 0 on success
 */
char **unSetEnviron(char **env, char *var1, shellDType *shell_var)
{
	int i, j, check, l = 0, lenv = 0, found = 0;
	char **copy;

	shell_var->unsetnull[0] = 0;
	if (!env)
		return (printCmt(3), NULL);
	if (stringLengthFunc(var1) == 0 || var1 == 0)
		return (errorSetStr(3, shell_var, 1), NULL);
	l = stringLengthFunc(var1), lenv = strLenPtr(env);
	for (i = 0; env[i] != 0; i++)
	{
		for (check = 0, j = 0; j < l && env[i][j] != 0; j++)
		{
			if (var1[j] == '=')
				return (errorSetStr(3, shell_var, 2), NULL);
			if (env[i][j] == var1[j])
				check++;
		}
		if (check == l && env[i][check] == '=')
		{
			/* Found env to erase */
			found = 1;
			if ((lenv - 1) != 0)
			{
				copy = cpyDoblePtrDel(env, lenv - 1, i);
				if (copy == 0)
					return (errorSetStr(7, shell_var, 1), NULL);
			}
			else
				shell_var->unsetnull[0] = 1, copy = NULL;
			freeDobleCharPntrFoluke(env), env = copy;
			return (env);
		}
	}
	if (found == 0)
		return (printCmt(12), NULL);
	return (env);

}
