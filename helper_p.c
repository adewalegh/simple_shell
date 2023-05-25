#include "shell.h"

/**
* _print - prints an array of characters
* @string: pointer to array of characters
*
* Return: the number of bytes or -1 if an error occurs
*/
int _print(char *string)
{
	return (write(STDOUT_FILENO, string, str_length(string)));
}

/**
* _printe - prints an array of characters to stderr
* @string: pointer to the array of characters
*
* Return: the number of bytes or -1 if an error occurs
*/

int _printe(char *string)
{
	return (write(STDERR_FILENO, string, str_length(string)));
}
/**
* _print_error - prints standard error
* @errorcode: print error code
* @data: program data
*
* Return: the number of bytes
*/

int _print_error(int errorcode, data_of_program *data)
{
	char n_as_string[10] = {'\0'};

	long_to_string((long) data->exec_counter, n_as_string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->tokens[0]);

		if (errorcode == 2)
			_printe(": Illegal number: ");
		else
			_printe(": can't cd to ");
		_printe(data->tokens[1]);
		_printe("\n");
	}
	else if (errorcode == 127)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": not found\n");
	}
	else if (errorcode == 126)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": Permission denied\n");
	}
	return (0);
}
