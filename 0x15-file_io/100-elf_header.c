#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include "main.h"

#define EXIT_ERROR 98

void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abiversion(unsigned char *e_ident);
void print_type(uint16_t e_type);
void print_entry(uint64_t e_entry);

/**
 * print_magic - prints the magic bytes of the ELF header
 * @e_ident: pointer to the e_ident array
 */

void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", e_ident[i]);
	printf("\n");
}

/**
 * print_class - prints the class of the ELF header
 * @e_ident: pointer to the e_ident array
 */

void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
			break;
	}
}

/**
 * print_data - prints the data encoding of the ELF header
 * @e_ident: pointer to the e_ident array
 */

void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_DATA]);
			break;
	}
}

/**
 * print_version - prints the version of the ELF header
 * @e_ident: pointer to the e_ident array
 */

void print_version(unsigned char *e_ident)
{
	printf("  Version:                           ");
	switch (e_ident[EI_VERSION])
	{
		case EV_NONE:
			printf("0 (invalid)\n");
			break;
		case EV_CURRENT:
			printf("1 (current)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_VERSION]);
			break;
	}
}

/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */

void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Sun Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("SGI Irix\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("Compaq TRU64 UNIX\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) application\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
			break;
	}
}

/**
 * print_abiversion - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */

void print_abiversion(unsigned char *e_ident)
{
	printf("  ABI Version:                       ");
	printf("%d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints the type of the ELF file
 * @e_type: the type of the ELF file
 */

void print_type(uint16_t e_type)
{
	printf("  Type:                              ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
			break;
	}
}

/**
 * print_entry - prints the entry point address of the ELF file
 * @e_entry: the entry point address of the ELF file
 */

void print_entry(uint64_t e_entry)
{
	printf("  Entry point address:               ");
	printf("%#lx\n", e_entry);
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, EXIT_ERROR on failure
 */
int main(int argc, char **argv)
{
	FILE *file;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(EXIT_ERROR);
	}

	file = fopen(argv[1], "rb");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_ERROR);
	}

	if (fread(&header, sizeof(header), 1, file) != 1)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		fclose(file);
		exit(EXIT_ERROR);
	}

	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr,
				"Error: Not an ELF file - it has the wrong magic bytes at the start\n");
		fclose(file);
		exit(EXIT_ERROR);
	}

	printf("ELF Header:\n");
	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_osabi(header.e_ident);
	print_abiversion(header.e_ident);
	print_type(header.e_type);
	print_entry(header.e_entry);

	fclose(file);
	return (0);
}
