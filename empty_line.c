#include "shell.h"

/**
 * _empty - checks if a string is empty
 * @buffer: string to check
 * Return: 1 if empty, 0 if not
 */
 int _empty(char *buffer)
 {
	 int i = 0;
 
	 while (buffer[i])
	 {
		 if (buffer[i] != ' ')
			 return (0);
		 i++;
	 }
	 return (1);
 }