#pragma once
#include "stdafx.h"
#include "il2cpp.h"
#include <map>

extern Il2CppGlobalMetadataHeader* pMetadataHdr;
extern uint32_t uiImageCount;
extern uint32_t uiNumTypes;
extern Il2CppImage* pImageTable;
extern Il2CppCodeRegistration* pCodeRegistration;
extern Il2CppMetadataRegistration* pMetadataRegistration;

char* GetString(StringIndex idx);

Il2CppMethodDefinition* GetMethodDefinition(MethodIndex idx);

Il2CppTypeDefinition* GetTypeDefFromIndex(TypeDefinitionIndex idx);

Il2CppTypeDefinition* GetTypeDefFromTypeIndex(TypeIndex idx);

Il2CppFieldDefinition* GetFieldDefFromIndex(FieldIndex idx);

Il2CppParameterDefinition* GetParameterFromIndex(ParameterIndex idx);

Il2CppParameterDefaultValue* GetParameterDefaultFromIndex(ParameterIndex idx);

Il2CppType* GetTypeFromTypeIndex(TypeIndex idx);

Il2CppFieldDefaultValue* GetFieldDefaultFromIndex(FieldIndex idx);

char* GetDefaultValueFromIndex(DefaultValueDataIndex idx);

void LoadMetadata(char* szFile);
