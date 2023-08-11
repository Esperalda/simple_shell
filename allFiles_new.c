#include "shell.h"

/*..........................errorStrFunc..........................*/
/*..........................NUM 11 START..........................*/
/**
 * reverseString - Reverses a string
 * @s: string to reverse
 *
 * Return: Nothing
 */
void reverseString(char *s)
{
	int x = 0, y = 0, z;

	x = reverseString_upper(s, x);
	z = x / 2, x = x - 1;
	reverseString_lower(s, x, y, z);
}
/*..........................NUM 11 BTW..........................*/
/**
 * reverseString - Reverses a string
 * @s: string to reverse
 *
 * Return: Nothing
 */
int reverseString_upper(char *s, int x)
{
	while (s[x])
		x++;
	return (x);
}
/*..........................NUM 11 BTW..........................*/
/**
 * reverseString - Reverses a string
 * @s: string to reverse
 *
 * Return: Nothing
 */
void reverseString_lower(char *s, int x, int y, int z)
{
	char tmp;

	while (x >= z)
	{
		tmp  = s[y];
		s[y] = s[x];
		s[x] = tmp;
		x--, y++;
	}

}
/*..........................NUM 11 END..........................*/

/*..........................NUM 1 START..........................*/
/**
 * Length_base - obtains length of number in base
 *
 * @n: number
 * @base: base of number
 *
 * Return: length of number
 */
int Length_base(unsigned long int n, unsigned long int base)
{
	unsigned long int x, neg = 0;

	for (x = 0; n > 0; x++)
		n = Length_base_inner(n, base);
	return (x + neg);
}
/*..........................NUM 1 BTW..........................*/
/**
 * Length_base - obtains length of number in base
 *
 * @n: number
 * @base: base of number
 *
 * Return: length of number
 */
unsigned long int Length_base_inner(unsigned long int n, unsigned long int base)
{
	n = n / base;
	return (n);
}
/*..........................NUM 1 END..........................*/


/*..........................NUM 12 START..........................*/
/**
 * intToAlph - converts an integer to string
 *
 * @n: number
 *
 * Return: pointer to string
 */
char *intToAlph(int n)
{
	unsigned long int x = 0, base = 10;
	char *str;

	str = intToAlph_upper(n, x, base);

	if (str == 0)
		return (0);

	for (; n > 0; x++)
	{
		str[x] = (n % base) + '0';
		n = Length_base_inner(n, base);
		/* n = n / base; */
	}
	str[x] = '\0';
	reverseString(str);
	return (str);
}
/*..........................NUM 12 BTW..........................*/
/**
 * intToAlph - converts an integer to string
 *
 * @n: number
 *
 * Return: pointer to string
 */
char *intToAlph_upper(int n, unsigned long int x, unsigned long int base)
{	
	char *str;

	if (n != 0)
		str = malloc(Length_base(n, base) + 1);
	else
		str = malloc(2), str[x] = '0', x++;
	return (str);
}
/*..........................NUM 12 BTW..........................*/
/*..........................NUM 12 END..........................*/

/*..........................NUM 2 START..........................*/
/**
 * errorStrFunc - creates a string with error line
 * @errNum: number corresponding to type of error
 * @shellVar: struct containing shell information
 * @exnum: valuel of exit the shell should have
 *
 * Return: 0 success, -1 fail
 */
int errorStrFunc(int errNum, shellDType *shellVar, int exnum)
{
	int cnter = shellVar->errnum[0], z = 0;
	char *cmd = shellVar->cmd, **optNoni = shellVar->options;
	char *sh_Name = shellVar->hshname;
	char *numStr, *concat_a, *concat_b, *collctspace = ": ";
	char *err[] = {
		"not found", "Permission denied", "Illegal number",
		"name is NULL, points to string of len 0, or has an '=' char.",
		"can't cd to ", "Illegal optNoni ", "Help command error",
		"Error allocating memory", "Wrong Alias",
		NULL
	};

	concat_a = stringConcatFunc(sh_Name, collctspace);
	if (!concat_a) /*hsh: */
		return (printCmt(1), -1);

	if (errNum == 7) /* Alloc Error */
	{
		concat_b = "fol";
		errorStrFunc_inner(errNum, concat_a, concat_b, err, z);
	}

	numStr = intToAlph(cnter);
	if (!numStr)  /* number to string */
		return (freSingle(concat_a), printCmt(1), -1);

	concat_b = stringConcatFunc(concat_a, numStr);
	if (!concat_b) /*hsh: cnter*/
	{
		printCmt(1);
		return (freSingle(concat_a), freSingle(numStr),  -1);
	}
	freSingle(concat_a), freSingle(numStr);

	concat_a = stringConcatFunc(concat_b, collctspace);
	if (!concat_a) /*hsh: cnter: */
		return (freSingle(concat_b), printCmt(1), -1);

	freSingle(concat_b);
	concat_b = stringConcatFunc(concat_a, cmd);
	if (!concat_b) /*hsh: cnter: cmd*/
		return (freSingle(concat_a), printCmt(1), -1);
	freSingle(concat_a);

	concat_a = stringConcatFunc(concat_b, collctspace);
	if (!concat_a) /*hsh: cnter: cmd: */
		return (freSingle(concat_b), printCmt(1), -1);
	freSingle(concat_b);

	concat_b = stringConcatFunc(concat_a, err[errNum]);
	if (!concat_b) /*hsh: cnter: cmd: error*/
		return (freSingle(concat_a), printCmt(1), -1);
	freSingle(concat_a);

	if (errNum > 1 && errNum < 6 && errNum != 3)
		concat_b = errorStrFunc2(errNum, concat_b, optNoni[1]);
	if (concat_b == NULL)
	{
		printCmt(1);
		return (-1);
	}

	while (concat_b[z] != 0)
		z++;
	write(2, concat_b, z), printCmt(2);
	freSingle(concat_b);
	shellVar->exit_Num[0] = exnum;
	return (0);
}


/*..........................NUM 2 BTW..........................*/
/**
 * errorStrFunc - creates a string with error line
 * @errNum: number corresponding to type of error
 * @shellVar: struct containing shell information
 * @exnum: valuel of exit the shell should have
 *
 * Return: 0 success, -1 fail
 */
int errorStrFunc_inner(int errNum, char *concat_a, char *concat_b, char *err[], int z)
{
	concat_b = stringConcatFunc(concat_a, err[errNum]); /*hsh: cnter: error*/
	if (!concat_b)
		return (freSingle(concat_a), printCmt(1), -1);
	freSingle(concat_a);
	while (concat_b[z] != 0)
		z++;
	write(2, concat_b, z), printCmt(2);
	freSingle(concat_b);
	return (0);
}
/*..........................NUM 2 END..........................*/

/*..........................NUM 3 START..........................*/
/**
 * errorStrFunc2 - extra modes for error generation
 * @errNum: number corresponding to type of error
 * @concat_b: error part from errorStrFunc
 * @optNoni: cmd optNoni thaat
 *
 * Return: pointer to string
 */
char *errorStrFunc2(int errNum, char *concat_b, char *optNoni)
{
	char *concat_a, *collctspace = ": ";

	if (errNum == 2) /* exit error */
	{

		concat_a = stringConcatFunc(concat_b, collctspace);
		if (!concat_a) /*hsh: cnter: cmd: error: */
		{
			printCmt(1);
			return (freSingle(concat_b), NULL);
		}
		freSingle(concat_b);

		concat_b = stringConcatFunc(concat_a, optNoni);

		if (!concat_b) /*hsh: cnter: cmd: error: optNoni*/
		{
			printCmt(1);
			return (freSingle(concat_a), NULL);
		}
		freSingle(concat_a);
	}
	if (errNum > 3) /* Errors with options at end */
	{
		errorStrFunc2_inner(concat_b, optNoni, concat_a);
		return (concat_a);
	}
	return (concat_b);

}
/*..........................NUM 3 BTW..........................*/
/**
 * errorStrFunc2 - extra modes for error generation
 * @errNum: number corresponding to type of error
 * @concat_b: error part from errorStrFunc
 * @optNoni: cmd optNoni thaat
 *
 * Return: pointer to string
 */
char *errorStrFunc2_inner(char *concat_b, char *optNoni, char *concat_a)
{
	concat_a = stringConcatFunc(concat_b, optNoni);
	if (!concat_a) /*hsh: cnter: cmd: error optNoni*/
	{
		printCmt(1);
		return (freSingle(concat_b), NULL);
	}
	freSingle(concat_b);
	return (concat_a);
}
/*..........................NUM 3 END..........................*/


/*..........................built_ins1..........................*/

/**
 * exitCmdFunc - built in command exit
 * @shellVar: struct containing shell info
 *
 * Return: -1 if error
 */
ssize_t exitCmdFunc(shellDType *shellVar)
{
	long val2Exit;

	if (shellVar->options[1] == NULL || isNumFunc(shellVar->options[1]))
	{
		val2Exit = a2iFunc(shellVar->options[1]);

		if (val2Exit >= 0 && val2Exit < INT_MAX)
		{
			if (val2Exit > 255)
				val2Exit %= 256;
			if (shellVar->options[1] == NULL)
				val2Exit = shellVar->exit_Num[0];
			free(*(shellVar->options));
			free(shellVar->options);
			if (*(shellVar->envCpy))
				freeDbPtrFunc(*(shellVar->envCpy));
			free(shellVar);
			exit(val2Exit);
		}
	}
	errorStrFunc(2, shellVar, 2);
	free(shellVar->options);
	return (-1);
}

/*..........................NUM 13 START..........................*/
/**
 * envCmdFunc - built in command env
 * @shellVar: struct containing shell info
 *
 * Return: 1 if succesful
 */
ssize_t envCmdFunc(shellDType *shellVar)
{
	char **str;
	int chcka = 1, chk;

	if (*(shellVar->envCpy) == NULL)
	{
		chk = 1;
		chcka = cmdMore(shellVar, chk);
	}

	str = *(shellVar->envCpy);

	if (shellVar->options[1] == NULL)
	{
		envCmdFunc_lower(str);
	}
	else
	{
		errorStrFunc(0, shellVar, 2);
		chcka = -1;
	}

	free(shellVar->options);
	return (chcka);
}
/*..........................NUM 13 BTW..........................*/
/**
 * envCmdFunc - built in command env
 * @shellVar: struct containing shell info
 *
 * Return: 1 if succesful
 */
int cmdMore(shellDType *shellVar, int chk)
{
	if (chk == 1)
	{
		/* write(2, "Environment is Null, Can't Print it\n", 36); */
		printCmt(3);
	}
	else if (chk == 2)
		printCmt(4);
	else if (chk == 3)
		printCmt(5);

	shellVar->exit_Num[0] = 2;
	free(shellVar->options);
	return (-1);
}
/*..........................NUM 13 BTW..........................*/
/**
 * envCmdFunc - built in command env
 * @shellVar: struct containing shell info
 *
 * Return: 1 if succesful
 */
void envCmdFunc_lower(char **str)
{
	for (; str && *str; str++)
	{
		write(1, *str, strLen1(*str));
		printCmt(11);
	}
}
/*..........................NUM 13 END..........................*/


/**
 * setEnvCmdFunc - built in command setenv
 * @shellVar: struct containing shell info
 *
 * Return: 1 if succesful, -1 if fail
 */
ssize_t setEnvCmdFunc(shellDType *shellVar)
{
	char **nEnv;
	char *variable = NULL;
	char *valuel = NULL;

	if (shellVar->options[1])
	{
		variable = shellVar->options[1];
		if (!shellVar->options[2])
		{
			cmdMore(shellVar, 2);
		}
		else
			valuel = shellVar->options[2];

	}
	if (variable == 0)
	{
		cmdMore(shellVar, 3);
	}

	nEnv = setEnvFunc1(*(shellVar->envCpy), variable, valuel, shellVar);

	if (nEnv == 0)
	{
		free(shellVar->options);
		return (-1);
	}

	*(shellVar->envCpy) = nEnv;
	free(shellVar->options);
	return (1);
}

/**
 * unSetEnvCmdFunc - built in command unsetenv
 * @shellVar: struct containing shell info
 *
 * Return: 1 if succesful, -1 if fail
 */
ssize_t unSetEnvCmdFunc(shellDType *shellVar)
{
	char **nEnv;
	char *variable = NULL;

	if (shellVar->options[1])
		variable = shellVar->options[1];
	else
	{
		shellVar->exit_Num[0] = 2;
		printCmt(6);
		return (free(shellVar->options), -1);
	}

	if (variable == 0)
	{
		free(shellVar->options);
		return (1);
	}

	nEnv = unSetEnvFunf(*(shellVar->envCpy), variable, shellVar);

	if (nEnv == 0 && shellVar->unsetnull[0] == 0)
	{
		free(shellVar->options);
		shellVar->exit_Num[0] = 2;
		return (-1);
	}

	*(shellVar->envCpy) = nEnv;
	free(shellVar->options);
	return (1);
}

/**
 * checkIfBuiltinFunc - checks if cmd is a built in
 * @shellVar: struct containing shell info
 *
 * Return: On fail 0
 */
ssize_t checkIfBuiltinFunc(shellDType *shellVar)
{
	builtIn_s ops[] = {
		{"exit", exitCmdFunc},
		{"env", envCmdFunc},
		{"setenv", setEnvCmdFunc},
		{"unsetenv", unSetEnvCmdFunc},
		{"cd", cdCmdFunc},
		{"help", helpCmdFunc1}
	};

	int x = 6, builtcheck; /* lenght of ops array */

	while (x--)
		if (!stringCompareFunc(shellVar->cmd, ops[x].cmd))
		{
			shellVar->errnum[0] += 1;
			builtcheck = ops[x].f(shellVar);
			if (builtcheck == 1)
				shellVar->exit_Num[0] = 0;
			return (builtcheck);
		}

	return (0);
}

/*..........................built_ins2..........................*/
/*..........................NUM 14 START..........................*/
/**
 * auxChnDir2 - auxiliary function of cd built in
 * @shellVar: struct containing shell info
 * @curDire: current directory
 *
 * Return: pointer to HOME or NULL if fail
 */
char *auxChnDir2(shellDType *shellVar, char *curDire)
{
	char *home, *dir = NULL;

	(void) curDire;
	home = getEnvi("HOME", *(shellVar->envCpy));
	if (home)
		dir = auxChnDir2_inner(home);

	return (dir);
}

/*..........................NUM 14 BTW..........................*/
/**
 * auxChnDir2 - auxiliary function of cd built in
 * @shellVar: struct containing shell info
 * @curDire: current directory
 *
 * Return: pointer to HOME or NULL if fail
 */
char *auxChnDir2_inner(char *home)
{
	return (home + 5);
}
/*..........................NUM 14 BTW..........................*/
/*..........................NUM 14 END..........................*/


/*..........................NUM 15 START..........................*/
/**
 * auxChnDir - auxiliary function of cd built in
 * @shellVar: struct containing shell info
 * @curDire: the current directory
 *
 * Return: Pointer to dir or NULL if fail
 */
char *auxChnDir(shellDType *shellVar, char *curDire)
{
	char *oldPwd_b = NULL, *oldPwd_a = NULL, *dir = NULL;

	if (shellVar->options[1] && shellVar->options[2])
	{
		auxChnDir_inner(shellVar, curDire);
		return (dir);
	}

	oldPwd_b = stringDupl(getEnvi("OLDPWD", *(shellVar->envCpy)));
	if (oldPwd_b)
		oldPwd_a = stringDupl(oldPwd_b + 7), freSingle(oldPwd_b);
	if (!oldPwd_b)
	{
		oldPwd_a = stringDupl(curDire);
		/* free(oldPwd_a), free(shellVar->options), free(curDire); */
		/* return (shellVar->exit_Num[0] = 2, NULL); */
	}

	dir = oldPwd_a;

	return (dir);
}
/*..........................NUM 15 BTW..........................*/
/**
 * auxChnDir - auxiliary function of cd built in
 * @shellVar: struct containing shell info
 * @curDire: the current directory
 *
 * Return: Pointer to dir or NULL if fail
 */
void auxChnDir_inner(shellDType *shellVar, char *curDire)
{
	printCmt(7);
	shellVar->exit_Num[0] = 2;
	free(shellVar->options);
	freSingle(curDire);
}
/*..........................NUM 15 BTW..........................*/
/*..........................NUM 15 END..........................*/



/**
 * cdCmdFunc - built in command cd
 * @shellVar: struct containing shell info
 *
 * Return: 1 if succesful, -1 if fail
 */
ssize_t cdCmdFunc(shellDType *shellVar)
{
	char *curDire = NULL, *dir = NULL, **nEnv, *oldPwd_a = NULL;
	int exit = 1, chcka = 1, chcka_minus = 0;

	curDire = getcwd(NULL, 4096);
	if (!curDire)
		return (errorStrFunc(4, shellVar, 2), free(shellVar->options), -1);
	if (!shellVar->options[1] ||
			(shellVar->options[1] && (!stringCompareFunc(shellVar->options[1], "~"))))
	{
		dir = auxChnDir2(shellVar, curDire);
		if (!dir)
			return (free(shellVar->options), freSingle(curDire), 1);
	}
	else
		if (!stringCompareFunc(shellVar->options[1], "-"))
		{
			dir = auxChnDir(shellVar, curDire);
			if (!dir)
				return (free(shellVar->options), freSingle(curDire), 1);
			chcka_minus = 1;
		}
		else
			dir = shellVar->options[1];
	if (dir)
		chcka = chdir(dir);
	if (chcka == 0 && chcka_minus == 1)
		write(1, dir, strLen1(dir)), printCmt(11);
	if (chcka != 0)
		errorStrFunc(4, shellVar, 2), exit = -1;
	else
	{
		nEnv = setEnvFunc1(*(shellVar->envCpy), "PWD", dir, shellVar);
		*(shellVar->envCpy) = nEnv;
		nEnv = setEnvFunc1(*(shellVar->envCpy), "OLDPWD", curDire, shellVar);
		*(shellVar->envCpy) = nEnv;
	}
	free(shellVar->options), freSingle(curDire), freSingle(oldPwd_a);
	if (chcka_minus == 1)
		freSingle(dir);
	return (exit);
}


/*..........................built_ins3..........................*/
/*..........................NUM 4 START..........................*/
/**
 * powerFunc - gets the result of base to ower
 * @base: base decimal
 * @pot: power
 *
 * Return: result
 */
long powerFunc(long base, long pot)
{
	long x = 0;
	long res = 1;

	for (x = 0; x < pot; x++)
		powerFunc_inner(base, res);

	return (res);
}
/*..........................NUM 4 BTW..........................*/
/**
 * powerFunc - gets the result of base to ower
 * @base: base decimal
 * @pot: power
 *
 * Return: result
 */
long powerFunc_inner(long base, long res)
{
	res *= base;
	return (res);
}
/*..........................NUM 4 END..........................*/


/**
 * a2iFunc - convert a char input to int
 * @s: char input
 *
 *
 * Return: input transformed to integer
 * On error: -1 inapropiate entry
 */

long a2iFunc(char *s)
{
	long x = 0;
	long k = 0;
	long len = 0;
	unsigned long result = 0;
	long retrnPpty = 0;
	long mynus = 0;
	long offset = 48;

	if (!s)
		return (0);

	for (x = 0; *(s + x) != '\0'; x++)
	{
		if (*(s + x) >= 48 && *(s + x) <= 57)
			len++;
		else if (len != 0)
			break;

		if (*(s + x) == '-')
			mynus++;
	}

	for (x--; len > 0; x--, k++, len--)
		result +=  (*(s + x) - offset) * powerFunc(10, k);

	retrnPpty = (mynus % 2 != 0) ? result * (-1) : result;

	return (retrnPpty);
}

/*..........................NUM 5 START..........................*/
/**
 * stringCompareFunc - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if strings are equal or another valuel if not
 *
 */
int stringCompareFunc(char *s1, char *s2)
{
	int x = 0;
	int equal = 0;

	for (x = 0; (*(s1 + x) || *(s2 + x)) && !equal; x++)
		if (*(s1 + x) != *(s2 + x))
			equal = stringCompareFunc_inner(s1, s2, x, equal);

	return (equal);
}
/*..........................NUM 5 BTW..........................*/
/**
 * stringCompareFunc - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if strings are equal or another valuel if not
 *
 */
int stringCompareFunc_inner(char *s1, char *s2, int x, int equal)
{
	equal = *(s1 + x) - *(s2 + x);
	return (equal);
}
/*..........................NUM 5 END..........................*/

/**
 * isDigitFunc - checks if a character is a digit
 * @c: character
 *
 * Return: 1 if digit, 0 if not
 *
 */
int isDigitFunc(int c)
{
	return ((c >= 48 && c <= 57) ? 1 : 0);
}
/**
 * isNumFunc - checks if a string is composed of numbers
 * @s: string
 *
 * Return: 1 if string has only numbers, 0 if not
 */
int isNumFunc(char *s)
{
	for (; *s; s++)
		if (!isDigitFunc(*s))
			return (0);
	return (1);
}


/*..........................shPrmptInputs..........................*/

/**
 * shPrmptInput - checks for input in after shell prompt
 * @ac: cnter of main arguments
 * @av: main arguments
 * @bufsize: size of buffer in prompt
 * @buffer: buffer in prompt
 * @shellVar: struct of shell info
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char **shPrmptInput(int ac, char **av, size_t *bufsize,
		   char **buffer, shellDType *shellVar)
{
	ssize_t charctrs;
	char **command;
	int exit_Num;

	if (ac == 1)
	{
		if (isatty(STDIN_FILENO))
			printCmt(8);
		charctrs = getline(buffer, bufsize, stdin);

		if (charctrs == -1)
		{
			exit_Num = shellVar->exit_Num[0];
			free(*buffer);
			if (*(shellVar->envCpy))
				freeDbPtrFunc(*(shellVar->envCpy));
			free(shellVar);
			if (isatty(STDIN_FILENO))
				printCmt(11);
			exit(exit_Num);
		}
		if (**buffer == '#' || !charctrs || **buffer == '\n')
			return (NULL);
		*buffer = delCmntFunc(*buffer);
		command = getParam(*buffer, shellVar);
	}
	else
	{
		command = malloc(sizeof(char *) * (ac - 1));
		if (!command)
		{
			errorStrFunc(7, shellVar, 1);
			return (NULL);
		}

		command[ac - 1] = '\0';
		while (ac--)
			command[ac - 1] = av[ac];
	}
	return (command);
}

/*..........................NUM 6 START..........................*/
/**
 * delCmntFunc - deletes a commnet inside a command line
 *
 * @str: string to operate
 *
 * Return: pointer to string
 *
 */
char *delCmntFunc(char *str)
{
	char *org = str;

	for (; str && *str; str++)
		if (*str == '#' && *(str - 1) == ' ')
		{
			*str = delCmntFunc_inner();
			break;
		}

	return (org);
}
/*..........................NUM 6 BTW..........................*/
/**
 * delCmntFunc - deletes a commnet inside a command line
 *
 * @str: string to operate
 *
 * Return: pointer to string
 *
 */
char delCmntFunc_inner(void)
{
	return ('\0');
}
/*..........................NUM 6 END..........................*/


/*..........................execCmdFunc..........................*/
/**
 * execCmdFunc - creates a child prcss to execute a cmd
 *
 * @program: command that will be executed
 * @command: arguments of command
 * @env: current environment
 * @shellVar: struct with shell information
 *
 * Return: pointer to the valuel in the environment,
 * or NULL if there is no match
 *
 */
int execCmdFunc(char *program, char *command[], char **env, shellDType *shellVar)
{
	pid_t prcss, stat;
	int execveSts = 0, waitSts = 0;

	prcss = fork();
	signal(SIGINT, signalHandlerFunc2);
	if (prcss == -1)
	{
		printCmt(9);
		exit(-1);
	}
	if (prcss == 0)
	{

		execveSts = execve(program, command, env);
		if (execveSts == -1)
		{
			_exit(-1);
		}
	}
	else
	{
		waitSts = wait(&stat);
		signal(SIGINT, signalHandlerFunc);
		if (waitSts == -1)
			exit(-1);
		if (WEXITSTATUS(stat) == 0)
			shellVar->exit_Num[0] = 0;
		else
			shellVar->exit_Num[0] = 2;
	}

	shellVar->errnum[0] += 1;
	return (0);
}

/*..........................getenv..........................*/

/**
 * getEnvi - gets an environment variable
 *
 * @name: name of environmental variable
 * @env: current environment
 *
 * Return: pointer to the valuel in the environment,
 * or NULL if there is no match
 *
 */
char *getEnvi(const char *name, char **env)
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

/*..........................fixed..........................*/
/* .......................NUM 28 START......................*/
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
/* ..........................NUM 28 END.........................*/
/* ..........................NUM 29 START.......................*/
/**
 * freeCharFoluke - frees
 * @temp: head
 */

void freSingle(char *temp)
{
	free(temp);
}
/* ..........................NUM 29 END...........................*/
/*..........................NUM 24 START..........................*/
/**
 * freeDbPtrFunc - frees a double pointer array of strings
 * (must end in NULL)
 *
 * @p: double pointer to free
 *
 * Return: no return
 */
void freeDbPtrFunc(char **p)
{
	int x, z = 0;

	z = freeDbPtrFunc_inner(p, z);

	for (x = 0; x < z; x++)
	{
		free(p[x]);
	}
	free(p);
}
/*..........................NUM 24 BTW..........................*/
/**
 * freeDbPtrFunc - frees a double pointer array of strings
 * (must end in NULL)
 *
 * @p: double pointer to free
 *
 * Return: no return
 */
int freeDbPtrFunc_inner(char **p, int z)
{
	while (p[z] != 0)
		z++;
	return (z);
}
/*..........................NUM 24 BTW..........................*/
/*..........................fixed..........................*/

/*..........................getline..........................*/
/*..........................NUM 7 START..........................*/
/**
 * memorySet - fills memory with constant byte
 * @s: memory area
 * @b: constant byte b
 * @n: first n bytes of memory area pointed by s
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char *memorySet(char *s, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		s[x] = memorySet_inner(s, b, x);
	return (s);
}
/*..........................NUM 7 BTW..........................*/
/**
 * memorySet - fills memory with constant byte
 * @s: memory area
 * @b: constant byte b
 * @n: first n bytes of memory area pointed by s
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char memorySet_inner(char *s, char b, unsigned int x)
{
	s[x] = b;
	return (s[x]);
}
/*..........................NUM 7 END..........................*/

/*..........................NUM 8 START..........................*/
/**
 * memoryCopyFunc - copies memory
 * @dest: destination
 * @src: source
 * @n: size of memory to copy
 *
 * Return: Returns memory copied
 */
char *memoryCopyFunc(char *dest, char *src, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		dest[x] = memoryCopyFunc_inner(dest, src, x);
	return (dest);
}
/*..........................NUM 8 BTW..........................*/
/**
 * memoryCopyFunc - copies memory
 * @dest: destination
 * @src: source
 * @n: size of memory to copy
 *
 * Return: Returns memory copied
 */
char memoryCopyFunc_inner(char *dest, char *src, unsigned int x)
{
	return (dest[x] = src[x]);
}
/*..........................NUM 8 END..........................*/


/*..........................NUM 9 START..........................*/
/**
 * reAllocateMemSpce - reallocates a memory block using malloc and free
 * @ptr: pointer to modify
 * @oldSze: current size of memory
 * @newSze: size memory will now have
 *
 * Return: Pointer to reallocated memory
 */
void *reAllocateMemSpce(void *ptr, unsigned int oldSze, unsigned int newSze)
{
	void *ptr2;
	int chk = 0;

	if (oldSze == newSze)
		return (ptr);

	if (ptr == NULL)
	{
		chk = 1;
		ptr2 = NULL;
		ptr2 = reAllocateMemSpce_inner(ptr, oldSze, newSze, ptr2, chk);
		return (ptr2);
	}

	if (newSze == 0 && ptr != NULL)
	{
		freSingle(ptr);
		return (0);
	}

	ptr2 = malloc(newSze);

	if (ptr2 == 0)
		return (0);

	ptr2 = memorySet(ptr2, '\0', newSze);

	ptr2 = reAllocateMemSpce_inner(ptr, oldSze, newSze, ptr2, chk);
	return (ptr2);
}
/*..........................NUM 9 BTW..........................*/
/**
 * reAllocateMemSpce - reallocates a memory block using malloc and free
 * @ptr: pointer to modify
 * @oldSze: current size of memory
 * @newSze: size memory will now have
 *
 * Return: Pointer to reallocated memory
 */
void *reAllocateMemSpce_inner(void *ptr, unsigned int oldSze, unsigned int newSze,
				void *ptr2, int chk)
{
	if (chk == 1)
	{
		ptr2 = malloc(newSze);
		if (ptr2 == 0)
			return (0);
		freSingle(ptr);
	}
	else
	{
		memoryCopyFunc(ptr2, ptr, oldSze);
		freSingle(ptr);
	}
	return (ptr2);
}
/*..........................NUM 9 END..........................*/


/**
 * getInputLine - read a string or a line from an input stream
 * @buffer: pointer to a space where the stdin read will be saved
 * as a string
 * @bufsize: current size of buffer (must be given as 0 initially)
 * @fd: stream to read
 *
 * Return: Number of Characters Read
 */
int getInputLine(char **buffer, size_t *bufsize, int fd)
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
			buff = reAllocateMemSpce(buff, sizeold, size);
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

/*..........................getParam..........................*/
/**
 * getParam - obtains parameters from buffer of prompt
 * @raw_buffer: raw_buffer
 * @shellVar: struct containing shell info
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char **getParam(char *raw_buffer, shellDType *shellVar)
{
	char **buffer, *cp_raw_buffer;
	ssize_t cnt = 0, i = 0;

	cp_raw_buffer = stringDupl(raw_buffer);
	if (!cp_raw_buffer)
	{
		errorStrFunc(7, shellVar, 1);
		exit(-1);
	}

	if (strTokenFunc(cp_raw_buffer, " \n"))
		cnt++;
	else
	{
		freSingle(cp_raw_buffer);
		return (NULL);
	}
	while (strTokenFunc(NULL, " \n"))
		cnt++;

	freSingle(cp_raw_buffer);
	buffer = malloc(sizeof(char *) * (cnt + 1));
	if (!buffer)
	{
		errorStrFunc(7, shellVar, 1);
		exit(-1);
	}
	buffer[0] = strTokenFunc(raw_buffer, " \n");
	for (i = 1; i < cnt && buffer[i - 1]; i++)
		buffer[i] = strTokenFunc(NULL, " \n");

	if (!buffer[i - 1])
	{
		freeDbPtrFunc(buffer);
		return (NULL);
	}

	buffer[i] = NULL;
	return (buffer);
}

/*..........................help001..........................*/
/**
 * putsToStd - prints string to std output
 * @s: string (must be NULL terminated)
 *
 * Return: No Return
 */
void putsToStd(char *s)
{
	write(1, s, strLen1(s));
}

/*..........................NUM 16 START..........................*/
/**
 * helpExit1 - prints help of exit built in
 *
 * Return: No Return
 */
void helpExit1(void)
{
	helpExit1_inner();
}
/*..........................NUM 16 BTW..........................*/
/**
 * helpExit1 - prints help of exit built in
 *
 * Return: No Return
 */
void helpExit1_inner(void)
{
	putsToStd("exit: exit [n]\n");
	putsToStd("    Exit the shell.\n\n");
	putsToStd("    Exits the shell with a stat of N.  ");
	putsToStd("    If N is omitted, the exit stat\n");
	putsToStd("    is that of the last command executed.\n");
}
/*..........................NUM 16 BTW..........................*/
/*..........................NUM 16 END..........................*/


/*..........................NUM 17 START..........................*/
/**
 * helpEnv1 - prints help of env built in
 *
 * Return: No Return
 */
void helpEnv1(void)
{
	helpEnv1_inner();
}
/*..........................NUM 17 BTW..........................*/
/**
 * helpEnv1 - prints help of env built in
 *
 * Return: No Return
 */
void helpEnv1_inner(void)
{
	putsToStd("env: env\n");
	putsToStd("    prints the current environment.\n\n");
	putsToStd("    Has no options\n");
}
/*..........................NUM 17 BTW..........................*/
/*..........................NUM 17 END..........................*/


/*..........................NUM 18 START..........................*/
/**
 * helpSetenv1 - prints help of setenv built in
 *
 * Return: No Return
 */
void helpSetenv1(void)
{
	helpSetenv1_inner();
}
/*..........................NUM 18 BTW..........................*/
/**
 * helpSetenv1 - prints help of setenv built in
 *
 * Return: No Return
 */
void helpSetenv1_inner(void)
{
	putsToStd("setenv: setenv [VARIABLE] [VALUE]\n");
	putsToStd("    Initializes a new environment variable, ");
	putsToStd("    or modifies an existing one.\n\n");
	putsToStd("    VARIABLE must not have the character '='.\n");
	putsToStd("    If no arguments are given, setenv prints ");
	putsToStd("    the current environment.\n");
}
/*..........................NUM 18 BTW..........................*/
/*..........................NUM 18 END..........................*/


/*..........................NUM 19 START..........................*/
/*..........................NUM 19 BTW..........................*/
/*..........................NUM 19 BTW..........................*/
/*..........................NUM 19 END..........................*/
/**
 * helpCmdFunc1 - help of built in commands
 * @shellVar: struct containing shell info
 *
 * Return: 1 if succesful, -1 if fail
 */
ssize_t helpCmdFunc1(shellDType *shellVar)
{
	int check = 1, bcheck = 0;
	helps_s help[] = {
		{"exit", helpExit1},
		{"env", helpEnv1},
		{"setenv", helpSetenv1},
		{"unsetenv", helpUnSetEnv1},
		{"cd", helpCdFunc1},
		{"help", helpHelpFunc1},
		{"alias", helpAliasFunc}
	};

	int i = 7;
	int p = 1;

	for (; shellVar->options[p]; p++, i = 7)
	{
		while (i--)
			if (!stringCompareFunc(shellVar->options[p], help[i].built))
				help[i].h(), bcheck = 1;
	}
	if (shellVar->options[1] == NULL)
	{
		printsHelpFunc1();
		bcheck = 1;
	}
	if (bcheck == 0)
	{
		check = -1;
		errorStrFunc(6, shellVar, 2);
	}

	free(shellVar->options);
	return (check);
}


/*..........................help002..........................*/
/*..........................NUM 19 START..........................*/
/**
 * helpUnSetEnv1 - prints help of unsetenv built in
 *
 * Return: No Return
 */
void helpUnSetEnv1(void)
{
	helpUnSetEnv1_inner();
}
/*..........................NUM 19 BTW..........................*/
/**
 * helpUnSetEnv1 - prints help of unsetenv built in
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
 * helpCdFunc1 - prints help of cd built in
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
 * helpHelpFunc1 - prints help of help built in
 *
 * Return: No Return
 */
void helpHelpFunc1(void)
{
	helpHelpFunc1_inner();
}
/*..........................NUM 21 BTW..........................*/
/**
 * helpHelpFunc1 - prints help of help built in
 *
 * Return: No Return
 */
void helpHelpFunc1_inner(void)
{
	putsToStd("help: help [BUILTIN ...]\n");
	putsToStd("    Display information about builtin commands.\n\n");
	putsToStd("    Displays brief summaries of builtin commands.  If BUILTIN is\n");
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
 * helpAliasFunc - prints help of alias built in
 *
 * Return: No Return
 */
void helpAliasFunc(void)
{
	helpAliasFunc_inner();
}
/*..........................NUM 22 BTW..........................*/
/**
 * helpAliasFunc - prints help of alias built in
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
 * printsHelpFunc1 - prints help of help built in
 *
 * Return: No Return
 */
void printsHelpFunc1(void)
{
	printsHelpFunc1_inner();
}
/*..........................NUM 23 BTW..........................*/
/**
 * printsHelpFunc1 - prints help of help built in
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


/*..........................path..........................*/
/*..........................NUM 10 START..........................*/
/**
 * pathCheckFunc1 - check if current dir must be added
 * @path: path env variable
 *
 * Return: Pointer to adress of new PATH
 *
 */

char *pathCheckFunc1(char *path)
{
	char *nupath;
	int x, y, nusize, cnter = 0;

	for (x = 0; path[x]; x++)
	{

		if (path[x] == '=' && path[x + 1] == ':')
			cnter++;
		if (path[x] == ':' && path[x + 1] == ':')
			cnter++;
		if (path[x] == ':' && path[x + 1] == '\0')
			cnter++;
	}
	if (cnter == 0)
		return (0);
	nusize = strLen1(path) + 1 + cnter;
	nupath = malloc(sizeof(char) * nusize);

	for (x = 0, y = 0; x < nusize; x++, y++)
	{
		if (path[y] == '=' && path[y + 1] == ':')
		{
			nupath[x] = pathCheckFunc1_inner(path, nupath, x, y), x++;
			continue;
		}
		if (path[y] == ':' && path[y + 1] == ':')
		{
			nupath[x] = pathCheckFunc1_inner(path, nupath, x, y), x++;
			continue;
		}
		if (path[y] == ':' && path[y + 1] == '\0')
		{
			nupath[x] = pathCheckFunc1_inner(path, nupath, x, y), x++;
			continue;
		}
		nupath[x] = path[y];
	}
	freSingle(path);
	return (nupath);
}
/*..........................NUM 10 BTW..........................*/
/**
 * pathCheckFunc1 - check if current dir must be added
 * @path: path env variable
 *
 * Return: Pointer to adress of new PATH
 *
 */

char pathCheckFunc1_inner(char *path, char *nupath, int x, int y)
{
	nupath[x] = path[y], nupath[x + 1] = '.';
	return (nupath[x]);
}
/*..........................NUM 10 END..........................*/


/**
 * pathFunc1 - Searches for a cmd in PATH
 * @cmd: string contating env variable PATH
 * @env: current environment
 * @shellVar: struct containing shell info
 *
 * Return: Pointer to adress of cmd in PATH or by itself
 *
 */

char *pathFunc1(char *cmd, char **env, shellDType *shellVar)
{
	char *path, *path2;
	struct stat st;
	char *token, *concaten1, *concaten2, *pthchck1, *delim = ":=";
	int x;

	for (x = 0; cmd[x]; x++)
		if (cmd[x] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (concaten1 = stringConcatFunc(cmd, '\0'));
			else
				return (0);
		}

	path2 = getEnvi("PATH", env);
	(void) shellVar;
	if (!path2)
		return (0);
	path = stringDupl(path2);
	pthchck1 = pathCheckFunc1(path);
	if (pthchck1)
		path = pthchck1;
	token = strTokenFunc(path, delim);
	for (token = strTokenFunc(0, delim); token; token = strTokenFunc(0, delim))
	{
		concaten1 = stringConcatFunc(token, "/");
		concaten2 = stringConcatFunc(concaten1, cmd);
		freSingle(concaten1);
		if (stat(concaten2, &st) == 0)
		{
			/*Found the command in PATH*/
			freSingle(path);
			return (concaten2);
		}
		freSingle(concaten2);
	}

	freSingle(path);
	return (0);
}

/*..........................setenv..........................*/


/**
 * copyDoublePtrFunc - copies an array of strings (double pointer)
 *
 * @p: double pointer to copy
 * @oldSze: original size of P
 * @newSze: size of copy
 *
 * Return: Pointer malloec
 */
char **copyDoublePtrFunc(char **p, int oldSze, int newSze)
{
	char **copy;
	int x, countSize1;

	if (!p && (oldSze == newSze))
		return (NULL);

	if (newSze < oldSze)
	{
		countSize1 = newSze;
		copy = malloc(sizeof(char *) * (countSize1 + 1));
	}
	else
	{
		countSize1 = oldSze;
		copy = malloc(sizeof(char *) * (newSze + 1));
	}
	if (copy == 0)
		return (0);

	if (p)
		for (x = 0; x < countSize1; x++)
		{
			copy[x] = stringDupl(p[x]);
			if (copy[x] == 0)
			{
				x--;
				for (; x >= 0; x--)
					freSingle(copy[x]);
				free(copy);
				return (0);
			}
		}

	/* Add Null in the end */
	copy[newSze] = '\0';

	return (copy);
}

/*..........................NUM 25 START..........................*/
/**
 * strLenDblePtrFunc - calculates length of double pointer (ending in NULL)
 * @s: double pointer
 *
 * Return: Length of double pointer
 *
 */
int strLenDblePtrFunc(char **s)
{
	int x = 0;

	if (!s)
		return (0);

	x = strLenDblePtrFunc_inner(s, x);

	return (x);
}
/*..........................NUM 25 BTW..........................*/
/**
 * strLenDblePtrFunc - calculates length of double pointer (ending in NULL)
 * @s: double pointer
 *
 * Return: Length of double pointer
 *
 */
int strLenDblePtrFunc_inner(char **s, int x)
{
	while (s[x] != NULL)
		x++;
	return (x);
}
/*..........................NUM 25 BTW..........................*/
/*..........................NUM 25 END..........................*/


/**
 * setEnvFunc1 - overwrite an env variable or creates it
 *
 * @env: array of env variables
 * @variable: env variable to set
 * @valuel: valuel to set
 * @shellVar: struct with shell info
 *
 * Return: 0 on success, -1 on error
 */
char **setEnvFunc1(char **env, char *variable, char *valuel, shellDType *shellVar)
{
	int x, y, check, z = 0, zenv = 0;
	char *joinEnv, *joinEnv2, *cpydupl1, **copy;

	if (strLen1(variable) == 0 || variable == 0)
		return (errorStrFunc(3, shellVar, 1), NULL);
	joinEnv2 = stringConcatFunc(variable, "=");
	if (joinEnv2 == 0)
		return (errorStrFunc(3, shellVar, 1), NULL);
	joinEnv = stringConcatFunc(joinEnv2, valuel), freSingle(joinEnv2);
	if (joinEnv == 0)
		return (errorStrFunc(3, shellVar, 1), NULL);
	z = strLen1(variable), zenv = strLenDblePtrFunc(env);
	for (x = 0; env && env[x] != 0; x++)
	{
		for (check = 0, y = 0; y < z && env[x][y] != 0; y++)
		{
			if (variable[y] == '=')
				return (freSingle(joinEnv), errorStrFunc(3, shellVar, 2), NULL);
			if (env[x][y] == variable[y])
				check++;
		}
		if (check == z && env[x][check] == '=')
		{
			freSingle(env[x]), cpydupl1 = stringDupl(joinEnv), freSingle(joinEnv);
			if (cpydupl1 == 0)
				return (errorStrFunc(3, shellVar, 1), NULL);
			return (env[x] = cpydupl1, env);
		}
	}
	copy = copyDoublePtrFunc(env, zenv, zenv + 1);
	if (env)
		freeDbPtrFunc(env);
	if (copy == 0)
		return (freSingle(joinEnv), errorStrFunc(3, shellVar, 1), NULL);
	env = copy, cpydupl1 = stringDupl(joinEnv), freSingle(joinEnv);
	if (cpydupl1 == 0)
		return (errorStrFunc(3, shellVar, 1), NULL);
	return (env[zenv] = cpydupl1, env);
}

/*..........................signalHandle..........................*/
/**
 * signalHandlerFunc - handles ctrl + c in runtime
 * @x: unused valuel, just for betty
 *
 * Return: No return
 */
void signalHandlerFunc(int x)
{
	(void) x;
	printCmt(10);
}
/**
 * signalHandlerFunc2 - handles ctrl + c during cmd exec
 * @x: unused valuel, just for betty
 *
 * Return: No return
 */
void signalHandlerFunc2(int x)
{
	(void) x;
	printCmt(11);
}

/*..........................stringConcatFunc..........................*/

/**
 * stringConcatFunc - concatenates two strings
 * @s1: string1
 * @s2: string2
 *
 * Return: Pointer
 */
char *stringConcatFunc(char *s1, char *s2)
{
	int l1, l2, i, j;
	char *s;
	char *nul = "";

	if (s1 == NULL)
		s1 = nul;
	if (s2 == NULL)
		s2 = nul;

	l1 = 0, l2 = 0;
	while (*(s1 + l1))
		l1++;
	while (*(s2 + l2))
		l2++;

	s = malloc(sizeof(char) * (l1 + l2 + 1));

	if (s == 0)
		return (0);

	for (i = 0; i < l1; i++)
		*(s + i) = *(s1 + i);

	for (i = 0, j = l1; i <= l2; j++, i++)
		*(s + j) = *(s2 + i);

	return (s);
}


/*..........................NUM 26 START..........................*/
/*..........................strdup..........................*/
/**
 * stringCopyFunc - copy a source input ont destinated input
 * @dest: target where will be stored the input
 * @src: source to copy from
 *
 *
 * Return: dest address
 * On error: -1 inapropiate entry
 */

char *stringCopyFunc(char *dest, char *src)
{
	int i = 0;

	for (i = 0; *(src + i) != '\0'; i++)
		*(dest + i) = stringCopyFunc_inner(dest, src, i);

	*(dest + i) = stringCopyFunc_inner(dest, src, i); /* adding '\0' character */

	return (dest);
}
/*..........................NUM 26 BTW..........................*/
/**
 * stringCopyFunc - copy a source input ont destinated input
 * @dest: target where will be stored the input
 * @src: source to copy from
 *
 *
 * Return: dest address
 * On error: -1 inapropiate entry
 */

char stringCopyFunc_inner(char *dest, char *src, int i)
{
	*(dest + i) = *(src + i);
	return (*(dest + i));
}
/*..........................NUM 26 BTW..........................*/
/*..........................NUM 26 END..........................*/


/**
 * strLen1 - function that returns the length of a string
 * @s: string address
 *
 *
 * Return: nothing
 * On error: -1 inapropiate entry
 */

int strLen1(char *s)
{
	return ((!*s) ? 0 : 1 + strLen1(s + 1));
}

/**
 * stringDupl - function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as a parameter
 * @str: source to copy
 *
 *
 * Return: address where is stored the result
 * On error: -1 inapropiate entry
 */

char *stringDupl(char *str)
{
	char *arr;

	if (!str)
		return (NULL);

	arr = malloc((strLen1(str) * sizeof(*arr)) + 1);

	if (!arr)
		return (NULL);

	stringCopyFunc(arr, str);

	return (arr);
}


/*..........................strtok..........................*/
/**
 * strTokenFunc - tokenizes a string based on a delimiter
 *
 * @str: string to operate
 * @delim: delimiter
 *
 * Return: pointer to string
 * or NULL if there is no match
 *
 */
char *strTokenFunc(char *str, const char *delim)
{
	const char *org = delim;
	int isEql = 1, isGtIto = 0;
	static char *step, *stpNull1;
	static int iEnd1;

	if (str)
		iEnd1 = 0;
	if (iEnd1)
		return (NULL);
	step = (str) ? str : (stpNull1 + 1);
	if (str)
		stpNull1 = str;
	else
		str = step;
	while (*str && isEql)
	{
		isEql = 0;
		for (delim = org; *delim; delim++)
			if (*str == *delim)
				isEql = 1;
		str = (!isEql) ? str : str + 1;
		iEnd1 = (*str) ? 0 : 1;
		if (iEnd1)
			return (NULL);
	}
	step = str;
	while (*str && !isEql)
	{
		isEql = 0;
		for (delim = org; *delim; delim++)
			if (*str == *delim)
			{
				isGtIto = 1, isEql = 1;
				iEnd1 = (*(str + 1)) ? 0 : 1, *str = '\0';
			}
		str = (isEql) ? str : str + 1;
		if (!isGtIto && !*str)
			iEnd1 = 1;
	}
	return (stpNull1 = str, step);
}

/*..........................unsetenv..........................*/
/**
 * copyDoublePtrFuncDel - copies an array of strings (double pointer)
 *
 * @p: double pointer to copy
 * @newSze: size of copy
 * @jump: valuel that must be skipped in copy
 *
 * Return: Pointer malloec
 */
char **copyDoublePtrFuncDel(char **p, int newSze, int jump)
{
	char **copy;
	int i, j, countSize1;

	countSize1 = newSze;
	copy = malloc(sizeof(char *) * (countSize1 + 1));
	if (copy == 0)
		return (0);

	for (i = 0, j = 0; j < countSize1; i++, j++)
	{
		if (i == jump)
			i++;
		copy[j] = stringDupl(p[i]);
		if (copy[j] == 0)
		{
			j--;
			for (; j >= 0; j--)
				freSingle(copy[j]);
			free(copy);
			return (0);
		}
	}

	copy[newSze] = '\0';

	return (copy);
}


/*..........................NUM 27 START..........................*/
/*..........................NUM 27 BTW..........................*/
/*..........................NUM 27 BTW..........................*/
/*..........................NUM 27 END..........................*/
/**
 * unSetEnvFunf - unsets an enviromental variable
 *
 * @env: array of env variables
 * @variable: env variable to unset
 * @shellVar: struct with shell info
 *
 * Return: 0 on success, -1 on error
 */
char **unSetEnvFunf(char **env, char *variable, shellDType *shellVar)
{
	int i, j, check, l = 0, ilenv = 0, found = 0;
	char **copy;

	shellVar->unsetnull[0] = 0;
	if (!env)
	{
		return (printCmt(3), NULL);
		/* return (write(2, "Environment is NULL\n", 20), NULL); */
	}
	if (strLen1(variable) == 0 || variable == 0)
		return (errorStrFunc(3, shellVar, 1), NULL);
	l = strLen1(variable), ilenv = strLenDblePtrFunc(env);
	for (i = 0; env[i] != 0; i++)
	{
		for (check = 0, j = 0; j < l && env[i][j] != 0; j++)
		{
			if (variable[j] == '=')
				return (errorStrFunc(3, shellVar, 2), NULL);
			if (env[i][j] == variable[j])
				check++;
		}
		if (check == l && env[i][check] == '=')
		{
			/* Found env to erase */
			found = 1;
			if ((ilenv - 1) != 0)
			{
				copy = copyDoublePtrFuncDel(env, ilenv - 1, i);
				if (copy == 0)
					return (errorStrFunc(7, shellVar, 1), NULL);
			}
			else
				shellVar->unsetnull[0] = 1, copy = NULL;
			freeDbPtrFunc(env), env = copy;
			return (env);
		}
	}
	if (found == 0)
		return (printCmt(12), NULL);
	return (env);
}
