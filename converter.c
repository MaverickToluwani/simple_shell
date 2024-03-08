#include "main.h"
/**
 * converter - Substitutes string with full path of an executable file
 * @arr_element: String to be substituted
 * Return: Return string to be substituted
 */
char *converter(char *arr_element)
{
	if (strcmp(arr_element, "ls") == 0)
		arr_element = "/bin/ls";
	if (strcmp(arr_element, "pwd") == 0)
		arr_element = "/bin/pwd";
	if (strcmp(arr_element, "env") == 0)
		arr_element = "/bin/env";
	if (strcmp(arr_element, "mv") == 0)
		arr_element = "/bin/mv";
	if (strcmp(arr_element, "cp") == 0)
		arr_element = "/bin/cp";
	if (strcmp(arr_element, "rm") == 0)
		arr_element = "/bin/rm";
	return (arr_element);
}
