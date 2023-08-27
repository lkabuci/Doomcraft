#include "../includes/libft.h"

// TODO: void the message when submitting
void	fatal(const char *message)
{
	write(2, "Error\n", 6);
	while (*message)
		write(2, message++, 1);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
