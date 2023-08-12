#include "you_shell.h"

/**
 * getInputLine - read a string or a line from an input stream
 * @buffer: pointer to a space where the ill be saved
 * as a string
 * @bufsize: current size of buffer ven as 0 initially)
 * @fd: stream to read
 *
 * Return: Number of Charac
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
 * getParam - obtains parameters frf prompt
 * @raw_buffer: raw_buffer
 * @shellVar: struct containing o
 * Return: On success 1.
 * On error, -1 is returned, and et appropriately.
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
 * putsToStd - prints strioutput
 * @s: string (must be Nated)
 *
 * Return: No Return
 */
void putsToStd(char *s)
{
	write(1, s, strLen1(s));
}

/*..........................NUM 16 START..........................*/
/**
 * helpExit1 - prints help of lt in
 *
 * Return: No Return
 */
void helpExit1(void)
{
	helpExit1_inner();
}
/*..........................NUM 16 BTW..........................*/
/**
 * helpExit1_inner - prints heit built in
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
