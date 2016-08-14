#pragma once
#include "stdafx.h"

enum OSABI : byte
{
	OS_SYSV = 0,
	OS_HP_UX,
	OS_NETBSD,
	OS_LINUX,
	OS_SOLAR,
	OS_AIX,
	OS_IRIX,
	OS_FREEBSD,
	OS_OPENBSD,
	OS_OPENVMS,
	OS_END
};

enum ISA : byte
{
	ISA_NONE = 0,
	ISA_SPARC = 2,
	ISA_x86 = 3,
	ISA_MIPS = 8,
	ISA_POWERPC = 0x14,
	ISA_ARM = 0x28,
	ISA_SUPERH = 0x2a,
	ISA_IA_64 = 0x32,
	ISA_x86_64 = 0x3e,
	ISA_AARCH64 = 0xb7,
	ISA_END
};

struct elf_header
{
	// 0x7f followed by ELF in ascii
	dword m_dwFormat;

	// 1 - 32 bit
	// 2 - 64 bit
	byte m_arch;

	// 1 - little endian
	// 2 - big endian
	byte m_endian;

	// 1 is original elf format
	byte m_version;

	// set based on OS, refer to OSABI enum
	byte m_osabi;

	// refer to elf documentation
	byte m_osabi_ver;

	// unused
	byte e_pad[7];

	// 1 - relocatable
	// 2 - executable
	// 3 - shared
	// 4 - core
	byte e_type;

	// refer to isa enum
	word e_machine;

	dword e_version;

	byte __buf[0x3e - 0x1c];

#define GetOffset(type, offset) *(type*)((byte*)this + offset)
	bool get_x64()
	{
		return m_arch == 2;
	}

	// Entry of the process
	size_t get_entry()
	{
		if (get_x64())
			return GetOffset(size_t, 0x18);
		return (size_t)GetOffset(dword, 0x18);
	}

	// Program header table pointer
	size_t get_phoff()
	{
		if (get_x64())
			return GetOffset(size_t, 0x20);
		return (size_t)GetOffset(dword, 0x1c);
	}

	// Section header table pointer
	size_t get_shoff()
	{
		if (get_x64())
			return GetOffset(size_t, 0x28);
		return (size_t)GetOffset(dword, 0x20);
	}

	// Depends on architecture
	dword get_flags()
	{
		if (get_x64())
			return GetOffset(dword, 0x30);
		return GetOffset(dword, 0x24);
	}

	// size of this header
	word get_ehsize()
	{
		if (get_x64())
			return GetOffset(word, 0x34);
		return GetOffset(word, 0x28);
	}

	// size of the program header table
	word get_phentsize()
	{
		if (get_x64())
			return GetOffset(word, 0x36);
		return GetOffset(word, 0x2a);
	}

	// number of entries in the program header table
	word get_phnum()
	{
		if (get_x64())
			return GetOffset(word, 0x38);
		return GetOffset(word, 0x2c);
	}

	// size of the section header table
	word get_shentsize()
	{
		if (get_x64())
			return GetOffset(word, 0x3a);
		return GetOffset(word, 0x2e);
	}

	// number of entries in the section header table
	word get_shnum()
	{
		if (get_x64())
			return GetOffset(word, 0x3c);
		return GetOffset(word, 0x30);
	}

	// index of the section header table that contains section names
	word get_shstrndx()
	{
		if (get_x64())
			return GetOffset(word, 0x3e);
		return GetOffset(word, 0x32);
	}
#undef GetOffset
};

struct elf_64_phdr
{
	dword p_type;
	dword p_flags;
	qword p_offset;
	qword p_vaddr;
	qword p_paddr;
	qword p_filesz;
	qword p_memsz;
	qword p_align;
};

struct elf_32_phdr
{
	dword p_type;
	dword p_offset;
	dword p_vaddr;
	dword p_paddr;
	dword p_filesz;
	dword p_memsz;
	dword p_flags;
	dword p_align;
};

struct elf_64_shdr
{
	dword sh_name;
	dword sh_type;
	qword sh_flags;
	qword sh_addr;
	qword sh_offset;
	qword sh_size;
	dword sh_link;
	dword sh_info;
	qword sh_addralign;
	qword sh_entsize;
};

struct elf_32_shdr
{
	dword sh_name;
	dword sh_type;
	dword sh_flags;
	dword sh_addr;
	dword sh_offset;
	dword sh_size;
	dword sh_link;
	dword sh_info;
	dword sh_addralign;
	dword sh_entsize;
};

typedef struct
{
	dword	st_name;
	dword	st_value;
	dword	st_size;
	byte	st_info;
	byte	st_other;
	word	st_shndx;
} elf_32_sym;

typedef struct
{
	dword	st_name;
	byte	st_info;
	byte	st_other;
	dword	st_shndx;
	qword	st_value;
	qword	st_size;
} elf_64_sym;

typedef struct
{
	dword	r_offset;
	dword	r_info;
} elf_32_rel;

typedef struct
{
	qword	r_offset;
	qword	r_info;
} elf_64_rel;

typedef struct
{
	dword	r_offset;
	dword	r_info;
	__int32 r_addend;
} elf_32_rela;

typedef struct
{
	qword	r_offset;
	qword	r_info;
	__int64 r_addend;
} ela_64_rela;