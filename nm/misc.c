#include "nm.h"

int		nm_message(char *message, int return_code)
{
	ft_printf("%s\n", message);
	return (return_code);
}

void	nm_error(char *message)
{
	ft_dprintf(2, "nm : %s\n", message);
	exit (2);
}
