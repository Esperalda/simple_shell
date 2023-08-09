#include "you_shell.h"

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
