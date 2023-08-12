#include "header.h"

/**
 * change_dir_loc - changes
 * @datshell: data
 */

void change_dir_loc(data_shell *datshell)
{
	char pwd[PATH_MAX];
	char *dir, *copy_pwdir, *copy_direc;

	getcwd(pwd, sizeof(pwd));

	dir = datshell->args[1];
	if (chdir(dir) == -1)
	{
		get_error(datshell, 2);
		return;
	}

	copy_pwdir = _strdup(pwd);
	prepareEnvron("OLDPWD", copy_pwdir, datshell);

	copy_direc = _strdup(dir);
	prepareEnvron("PWD", copy_direc, datshell);

	freeCharMemDaf(copy_pwdir);
	freeCharMemDaf(copy_direc);

	datshell->status = 0;

	chdir(dir);
}

/**
 * change_dir_lastarg - changes
 * @datshell: data
 */

void change_dir_lastarg(data_shell *datshell)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *copy_pwdir, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	copy_pwdir = _strdup(pwd);

	p_oldpwd = getenviron("OLDPWD", datshell->dtenviron);

	if (p_oldpwd == NULL)
		cp_oldpwd = copy_pwdir;
	else
		cp_oldpwd = _strdup(p_oldpwd);

	prepareEnvron("OLDPWD", copy_pwdir, datshell);

	if (chdir(cp_oldpwd) == -1)
		prepareEnvron("PWD", copy_pwdir, datshell);
	else
		prepareEnvron("PWD", cp_oldpwd, datshell);

	p_pwd = getenviron("PWD", datshell->dtenviron);

	write(STDOUT_FILENO, p_pwd, string_length(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	freeCharMemDaf(copy_pwdir);
	if (p_oldpwd)
		freeCharMemDaf(cp_oldpwd);

	datshell->status = 0;

	chdir(p_pwd);
}

/**
 * change_dir_loc_2 - changes
 *
 * @datshell: data
 */

void change_dir_loc_2(data_shell *datshell)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _strdup(pwd);

	home = getenviron("HOME", datshell->dtenviron);

	if (home == NULL)
	{
		prepareEnvron("OLDPWD", p_pwd, datshell);
		freeCharMemDaf(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		get_error(datshell, 2);
		freeCharMemDaf(p_pwd);
		return;
	}

	prepareEnvron("OLDPWD", p_pwd, datshell);
	prepareEnvron("PWD", home, datshell);
	freeCharMemDaf(p_pwd);
	datshell->status = 0;
}

/**
 * change_dir_SH - changes
 *
 * @datshell: data
 * Return: 1 on success
 */

int change_dir_SH(data_shell *datshell)
{
	char *dir;
	int izhome, izhome2, izddash;

	dir = datshell->args[1];

	if (dir != NULL)
	{
		izhome = stringcompare("$HOME", dir);
		izhome2 = stringcompare("~", dir);
		izddash = stringcompare("--", dir);
	}

	if (dir == NULL || !izhome || !izhome2 || !izddash)
	{
		change_dir_loc_2(datshell);
		return (1);
	}

	if (stringcompare("-", dir) == 0)
	{
		change_dir_lastarg(datshell);
		return (1);
	}

	if (stringcompare(".", dir) == 0 || stringcompare("..", dir) == 0)
	{
		change_dir_ftp(datshell);
		return (1);
	}

	change_dir_loc(datshell);

	return (1);
}

/**
 * duplicate_character - counts
 *
 * @input: input
 * @i: index
 * Return: repetitions
 */

int duplicate_character(char *input, int i)
{
	if (*(input - 1) == *input)
		return (duplicate_character(input - 1, i + 1));

	return (i);
}
