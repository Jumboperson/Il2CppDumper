#include "il2cpp_utils.h"

Il2CppGlobalMetadataHeader* pMetadataHdr = 0;
uint32_t uiImageCount = 0;
uint32_t uiNumTypes = 0;
Il2CppImage* pImageTable = 0;
Il2CppCodeRegistration* pCodeRegistration = 0;
Il2CppMetadataRegistration* pMetadataRegistration = 0;

std::map<TypeIndex, TypeDefinitionIndex> type_index_mapping;

#define GetOffPtr(offset) (void*)(((uint8_t*)pMetadataHdr) + offset)
char* GetString(StringIndex idx)
{
	if (idx > pMetadataHdr->stringCount)
		return "";
	return (char*)pMetadataHdr + pMetadataHdr->stringOffset + idx;
}

Il2CppMethodDefinition* GetMethodDefinition(MethodIndex idx)
{
	return ((Il2CppMethodDefinition*)((char*)GetOffPtr(pMetadataHdr->methodsOffset))) + idx;
}

Il2CppTypeDefinition* GetTypeDefFromIndex(TypeDefinitionIndex idx)
{
	return ((Il2CppTypeDefinition*)((char*)GetOffPtr(pMetadataHdr->typeDefinitionsOffset))) + idx;
}

Il2CppType* GetTypeFromTypeIndex(TypeIndex idx)
{
	if ((uint32_t)idx >= (uint32_t)pMetadataRegistration->typesCount)
		return 0;
	return pMetadataRegistration->types[idx];
}

Il2CppFieldDefinition* GetFieldDefFromIndex(FieldIndex idx)
{
	return ((Il2CppFieldDefinition*)GetOffPtr(pMetadataHdr->fieldsOffset)) + idx;
}

Il2CppParameterDefinition* GetParameterFromIndex(ParameterIndex idx)
{
	return ((Il2CppParameterDefinition*)GetOffPtr(pMetadataHdr->parametersOffset)) + idx;
}

Il2CppParameterDefaultValue* GetParameterDefaultFromIndex(ParameterIndex idx)
{
	Il2CppParameterDefaultValue* pList = ((Il2CppParameterDefaultValue*)GetOffPtr(pMetadataHdr->parameterDefaultValuesOffset));
	for (int i = 0; i < pMetadataHdr->parameterDefaultValuesCount; ++i)
	{
		if (pList[i].parameterIndex == idx)
			return &pList[i];
	}
	return 0;
}

Il2CppFieldDefaultValue* GetFieldDefaultFromIndex(FieldIndex idx)
{
	Il2CppFieldDefaultValue* pList = ((Il2CppFieldDefaultValue*)GetOffPtr(pMetadataHdr->fieldDefaultValuesOffset));
	for (int i = 0; i < pMetadataHdr->fieldDefaultValuesCount; ++i)
	{
		if (pList[i].fieldIndex == idx)
			return &pList[i];
	}
	return 0;
}

char* GetDefaultValueFromIndex(DefaultValueDataIndex idx)
{
	if (idx > pMetadataHdr->fieldAndParameterDefaultValueDataCount)
		return 0;
	return ((char*)GetOffPtr(pMetadataHdr->fieldAndParameterDefaultValueDataOffset)) + idx;
}

void LoadMetadata(char* szFile)
{
	FILE* pFile = fopen(szFile, "rb");
	fseek(pFile, 0, SEEK_END);
	uint32_t uiSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);

	pMetadataHdr = (Il2CppGlobalMetadataHeader*)malloc(uiSize);
	fread((void*)pMetadataHdr, uiSize, 1, pFile);

	if (pMetadataHdr->sanity != 0xFAB11BAF)
	{
		fprintf_s(stderr, "ERROR: Metadata file supplied is not valid metadata file.\n");
		exit(1);
	}

	if (pMetadataHdr->version != 21)
	{
		fprintf_s(stderr, "ERROR: Metadata file supplied is not a supported version.\n");
		exit(1);
	}

	uiImageCount = pMetadataHdr->imagesCount / sizeof(Il2CppImageDefinition);
	pImageTable = (Il2CppImage*)calloc(uiImageCount, sizeof(Il2CppImage));
	uiNumTypes = pMetadataHdr->typeDefinitionsCount / sizeof(Il2CppTypeDefinition);

	Il2CppImageDefinition* imageDefinitions = (Il2CppImageDefinition*)GetOffPtr(pMetadataHdr->imagesOffset);
	for (uint32_t imageIndex = 0; imageIndex < uiImageCount; imageIndex++)
	{
		const Il2CppImageDefinition* imageDefinition = imageDefinitions + imageIndex;
		Il2CppImage* image = pImageTable + imageIndex;
		image->name = GetString(imageDefinition->nameIndex);
		image->assemblyIndex = imageDefinition->assemblyIndex;
		image->typeStart = imageDefinition->typeStart;
		image->typeCount = imageDefinition->typeCount;
		image->entryPointIndex = imageDefinition->entryPointIndex;
		image->token = imageDefinition->token;
		fprintf_s(stdout, "// Image %d: %s - %u\n", imageIndex, image->name, image->typeStart);
	}
}
