#include "elf_utils.h"

elf_32_shdr* GetSection(int iSection, elf_header* pHdr)
{
	if (iSection > pHdr->get_shnum())
		return 0;
	return (elf_32_shdr*)((char*)pHdr + pHdr->get_shoff() + (pHdr->get_shentsize() * iSection));
}

char* GetStringFromTable(uint32_t uiString, elf_header* pHdr)
{
	elf_32_shdr* pStringSec = GetSection(pHdr->get_shstrndx(), pHdr);
	char* pOffset = (char*)pHdr + pStringSec->sh_offset;
	return &pOffset[uiString];
}

void* MapVirtualAddressToReal(uint32_t uiAddr, elf_header* pHdr)
{
	elf_32_shdr* pFirstSec = GetSection(0, pHdr);
	if (uiAddr < pFirstSec->sh_addr)
		return 0;
	for (uint32_t i = 1; i < pHdr->get_shnum(); ++i)
	{
		elf_32_shdr* pSection = GetSection(i, pHdr);
		if (pSection->sh_addr > uiAddr)
		{
			elf_32_shdr* pRetSec = GetSection(i - 1, pHdr);
			uint32_t uiResOffset = uiAddr - pRetSec->sh_addr;
			return (void*)(pRetSec->sh_offset + (char*)pHdr + uiResOffset);
		}
	}
	elf_32_shdr* pRetSec = GetSection(pHdr->get_shnum() - 1, pHdr);
	uint32_t uiResOffset = uiAddr - pRetSec->sh_addr;
	return (void*)(pRetSec->sh_offset + (char*)pHdr + uiResOffset);
}

uint32_t MapRealToFileOffset(void* addr, elf_header* pHdr)
{
	if (addr < pHdr)
		return 0xffffffff;
	return (uint32_t)addr - (uint32_t)pHdr;
}
