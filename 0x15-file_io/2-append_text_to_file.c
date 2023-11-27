#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: filename.
 * @text_content: added content.
 *
 * Return: 1 if the file exists. -1 if the fails does not exist
 * or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
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
