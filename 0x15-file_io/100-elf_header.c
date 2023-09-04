#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * display_elf_header_info - Display information from the ELF header.
 *
 * @elf_header: Pointer to the ELF header structure.
 */
void display_elf_header_info(const Elf64_Ehdr *elf_header);

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr elf_header;
	ssize_t bytes_read;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
		return (98);
	}

	bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));

	if (bytes_read != sizeof(Elf64_Ehdr) || elf_header.e_ident[EI_MAG0] != ELFMAG0 || 
			elf_header.e_ident[EI_MAG1] != ELFMAG1 || 
			elf_header.e_ident[EI_MAG2] != ELFMAG2 || elf_header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Error: %s is not a valid ELF file\n", argv[1]);
		close(fd);
		return (98);
	}

	display_elf_header_info(&elf_header);

	close(fd);
	return (0);
}

void display_elf_header_info(const Elf64_Ehdr *elf_header)
{
	int i;
	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", elf_header->e_ident[i]);
		if (i < EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");

	printf("Class:                             %s\n", elf_header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("Data:                              %s\n", elf_header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "Unknown");
	printf("Version:                           %d (current)\n", elf_header->e_ident[EI_VERSION]);
	printf("OS/ABI:                            %d\n", elf_header->e_ident[EI_OSABI]);
	printf("ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);
	printf("Type:                              %d\n", elf_header->e_type);
	printf("Entry point address:               %#lx\n", (unsigned long)elf_header->e_entry);
}
