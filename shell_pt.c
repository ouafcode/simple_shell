#include "main.h"
/**
 * prmpt - to write prompt to user
 * @fl: stream file input
 * @buffer: input buffer in struct
 *
 * Return: nothing(void)
*/
void prmpt(int fl, struct stat buffer)
{
	fstat(fl, &buffer);

	/*we use stat funct to get file path*/
	if (S_ISCHR(buffer.st_mode))
		my_put(PRT);
}
/**
 * my_put - to print str with \n
 * @ptr: input string to print
 *
 * Return: return nothing
 */
void my_put(char *ptr)
{
	unsigned int size;

	size = my_strlen(ptr);

	write(STDOUT_FILENO, ptr, size);
}
