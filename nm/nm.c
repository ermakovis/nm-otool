#include "nm.h"

void	*get_mapped_exec(char *path)
{
	int		fd;
	t_stat	stat;
	void	*ret;

	if ((fd = open(path, O_RDONLY)) == -1)
		nm_error(NM_PATH_ERROR);
	if (fstat(fd, &stat) == -1)
		nm_error(NM_STAT_ERROR);
	ret = mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (ret == MAP_FAILED)
		nm_error(NM_MAP_ERROR);
	return (ret);
}

int		check_elf(void *buf)
{
	Elf32_Ehdr	*elf_head;

	elf_head = (Elf32_Ehdr*)buf;
	if (!ft_strncmp((char*)elf_head->e_ident, "\177ELF", 4))
		return (nm_message(NM_ELF_MATCH, EXIT_SUCCESS));
	return (EXIT_FAILURE);
}

int		main(int argc, char **av)
{
	void		*buf;

	av++;
	if (*av)
		buf = get_mapped_exec(*av);
	else
		buf = get_mapped_exec(NM_DEFAULT_PATH);
	if (check_elf(buf) == EXIT_SUCCESS)
		return (parse_elf((Elf32_Ehdr*)buf));
	nm_error(NM_TYPE_ERROR);
}
