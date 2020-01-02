#include "ft_nm.h"

int		main(void)
{
	int		fd;
	int		size;
	t_stat	stat;
	void	*buf;


	if ((fd = open("./a.out", O_RDONLY)) == -1)
	{
		ft_printf("Failed to open file\n");
		exit (0);
	}
	if (fstat(fd, &stat) == -1)
	{
		ft_printf("Failed to get stat\n");
		exit (0);
	}
	buf = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
	ft_printf("nm\n");
	return (0);
}
