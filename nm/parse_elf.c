#include "nm.h"

int		parse_elf(Elf32_Ehdr *elf_head)
{
	if (elf_head->e_ident[EI_CLASS] == ELFCLASS32)
	{
		ft_printf("%s\n", NM_ELF_CLASS32);
		return (0);
	}
	if (elf_head->e_ident[EI_CLASS] == ELFCLASS64)
	{
		ft_printf("%s\n", NM_ELF_CLASS64);
		return (0);
	}
	return (nm_message(NM_ELF_CLASSNONE, EXIT_FAILURE));
}
