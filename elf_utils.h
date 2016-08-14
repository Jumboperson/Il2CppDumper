#pragma once
#include "stdafx.h"
#include "elf_structures.h"
#include <vector>

#define SHT_NULL 0
#define SHT_PROGBITS 1
#define SHT_SYMTAB 2
#define SHT_STRTAB 3
#define SHT_RELA 4
#define SHT_HASH 5
#define SHT_DYNAMIC 6
#define SHT_NOTE 7
#define SHT_NOBITS 8
#define SHT_REL 9
#define SHT_SHLIB 10
#define SHT_DYNSYM 11
#define SHT_LOPROC 0x70000000
#define SHT_HIPROC 0x7fffffff
#define SHT_LOUSER 0x80000000
#define SHT_HIUSER 0xffffffff

elf_32_shdr* GetSection(int iSection, elf_header* pHdr);

char* GetStringFromTable(uint32_t uiString, elf_header* pHdr);

// Could stand to be improved speed-wise
void* MapVirtualAddressToReal(uint32_t uiAddr, elf_header* pHdr);
#define MapVATR MapVirtualAddressToReal

uint32_t MapRealToFileOffset(void* addr, elf_header* pHdr);
#define MapRTFO MapRealToFileOffset
