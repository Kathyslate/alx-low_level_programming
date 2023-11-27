#include "main.h"

/**
 * create_file - creates a file
 * @filename: filename.
 * @text_content: content writed in the file.
 * Return: 1 if it success. -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int result1;
	int result2;
	int result3;

	if (!filename)
		return (-1);

	result1 = open(filename, O_WRONLY | O_APPEND);

	if (result1 == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (result2 = 0; text_content[result2]; result2++)
		;

	result3 = write(result1, text_content, result2);

	if (result3 == -1)
		return (-1);

	close(result1);

	return (1);
}
