#ifndef FT_NM_H
# define FT_NM_H

#include "libft.h"
#include <stdio.h>
#include <sys/mman.h>
#include <elf.h>

#define NM_DEFAULT_PATH 	"./a.out"
#define NM_PATH_ERROR		"Incorrect path"
#define NM_STAT_ERROR		"Failed to get file's stat"
#define NM_MAP_ERROR		"Failed to map executeable to memory"
#define NM_TYPE_ERROR		"Failed to determine file type"
#define NM_ELF_MATCH		"MAGIC\t\tELF"
#define NM_ELF_CLASS32		"ELFCLASS\t32"
#define NM_ELF_CLASS64		"ELFCLASS\t64"
#define NM_ELF_CLASSNONE	"ELFCLASS\tERROR"

typedef struct stat			t_stat;


void	nm_error(char *message);
int		nm_message(char *message, int return_code);

#endif
