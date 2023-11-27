#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 * Return: numbers of letters printed. if It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int var1;
	ssize_t test1, test2;
	char *var2;

	if (!filename)
		return (0);

	var1 = open(filename, O_RDONLY);

	if (var1 == -1)
		return (0);

	var2 = malloc(sizeof(char) * (letters));
	if (!var2)
		return (0);

	test1 = read(var1, var2, letters);
	test2 = write(STDOUT_FILENO, var2, test1);

	close(var1);

	free(var2);

	return (test2);
}
