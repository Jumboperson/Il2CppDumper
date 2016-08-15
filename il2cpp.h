#pragma once

#include <stdint.h>

#define FIELD_ATTRIBUTE_PRIVATE               0x0001
#define FIELD_ATTRIBUTE_FAM_AND_ASSEM         0x0002
#define FIELD_ATTRIBUTE_ASSEMBLY              0x0003
#define FIELD_ATTRIBUTE_FAMILY                0x0004
#define FIELD_ATTRIBUTE_FAM_OR_ASSEM          0x0005
#define FIELD_ATTRIBUTE_PUBLIC                0x0006

#define FIELD_ATTRIBUTE_STATIC                0x0010
#define FIELD_ATTRIBUTE_INIT_ONLY             0x0020
#define FIELD_ATTRIBUTE_LITERAL               0x0040
#define FIELD_ATTRIBUTE_NOT_SERIALIZED        0x0080
#define FIELD_ATTRIBUTE_SPECIAL_NAME          0x0200
#define FIELD_ATTRIBUTE_PINVOKE_IMPL          0x2000

/* For runtime use only */
#define FIELD_ATTRIBUTE_RESERVED_MASK         0x9500
#define FIELD_ATTRIBUTE_RT_SPECIAL_NAME       0x0400
#define FIELD_ATTRIBUTE_HAS_FIELD_MARSHAL     0x1000
#define FIELD_ATTRIBUTE_HAS_DEFAULT           0x8000
#define FIELD_ATTRIBUTE_HAS_FIELD_RVA         0x0100


#define METHOD_IMPL_ATTRIBUTE_CODE_TYPE_MASK       0x0003
#define METHOD_IMPL_ATTRIBUTE_IL                   0x0000
#define METHOD_IMPL_ATTRIBUTE_NATIVE               0x0001
#define METHOD_IMPL_ATTRIBUTE_OPTIL                0x0002
#define METHOD_IMPL_ATTRIBUTE_RUNTIME              0x0003

#define METHOD_IMPL_ATTRIBUTE_MANAGED_MASK         0x0004
#define METHOD_IMPL_ATTRIBUTE_UNMANAGED            0x0004
#define METHOD_IMPL_ATTRIBUTE_MANAGED              0x0000

#define METHOD_IMPL_ATTRIBUTE_FORWARD_REF          0x0010
#define METHOD_IMPL_ATTRIBUTE_PRESERVE_SIG         0x0080
#define METHOD_IMPL_ATTRIBUTE_INTERNAL_CALL        0x1000
#define METHOD_IMPL_ATTRIBUTE_SYNCHRONIZED         0x0020
#define METHOD_IMPL_ATTRIBUTE_NOINLINING           0x0008
#define METHOD_IMPL_ATTRIBUTE_MAX_METHOD_IMPL_VAL  0xffff

#define METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK        0x0007
#define METHOD_ATTRIBUTE_COMPILER_CONTROLLED       0x0000
#define METHOD_ATTRIBUTE_PRIVATE                   0x0001
#define METHOD_ATTRIBUTE_FAM_AND_ASSEM             0x0002
#define METHOD_ATTRIBUTE_ASSEM                     0x0003
#define METHOD_ATTRIBUTE_FAMILY                    0x0004
#define METHOD_ATTRIBUTE_FAM_OR_ASSEM              0x0005
#define METHOD_ATTRIBUTE_PUBLIC                    0x0006

#define METHOD_ATTRIBUTE_STATIC                    0x0010
#define METHOD_ATTRIBUTE_FINAL                     0x0020
#define METHOD_ATTRIBUTE_VIRTUAL                   0x0040


#define TYPE_ATTRIBUTE_VISIBILITY_MASK       0x00000007
#define TYPE_ATTRIBUTE_NOT_PUBLIC            0x00000000
#define TYPE_ATTRIBUTE_PUBLIC                0x00000001
#define TYPE_ATTRIBUTE_NESTED_PUBLIC         0x00000002
#define TYPE_ATTRIBUTE_NESTED_PRIVATE        0x00000003
#define TYPE_ATTRIBUTE_NESTED_FAMILY         0x00000004
#define TYPE_ATTRIBUTE_NESTED_ASSEMBLY       0x00000005
#define TYPE_ATTRIBUTE_NESTED_FAM_AND_ASSEM  0x00000006
#define TYPE_ATTRIBUTE_NESTED_FAM_OR_ASSEM   0x00000007

#define TYPE_ATTRIBUTE_LAYOUT_MASK           0x00000018
#define TYPE_ATTRIBUTE_AUTO_LAYOUT           0x00000000
#define TYPE_ATTRIBUTE_SEQUENTIAL_LAYOUT     0x00000008
#define TYPE_ATTRIBUTE_EXPLICIT_LAYOUT       0x00000010

#define TYPE_ATTRIBUTE_CLASS_SEMANTIC_MASK   0x00000020
#define TYPE_ATTRIBUTE_CLASS                 0x00000000
#define TYPE_ATTRIBUTE_INTERFACE             0x00000020

#define TYPE_ATTRIBUTE_ABSTRACT              0x00000080
#define TYPE_ATTRIBUTE_SEALED                0x00000100
#define TYPE_ATTRIBUTE_SPECIAL_NAME          0x00000400

#define TYPE_ATTRIBUTE_IMPORT                0x00001000
#define TYPE_ATTRIBUTE_SERIALIZABLE          0x00002000

#define TYPE_ATTRIBUTE_STRING_FORMAT_MASK    0x00030000
#define TYPE_ATTRIBUTE_ANSI_CLASS            0x00000000
#define TYPE_ATTRIBUTE_UNICODE_CLASS         0x00010000
#define TYPE_ATTRIBUTE_AUTO_CLASS            0x00020000

#define TYPE_ATTRIBUTE_BEFORE_FIELD_INIT     0x00100000
#define TYPE_ATTRIBUTE_FORWARDER             0x00200000

#define TYPE_ATTRIBUTE_RESERVED_MASK         0x00040800
#define TYPE_ATTRIBUTE_RT_SPECIAL_NAME       0x00000800
#define TYPE_ATTRIBUTE_HAS_SECURITY          0x00040000


#define PARAM_ATTRIBUTE_IN                 0x0001
#define PARAM_ATTRIBUTE_OUT                0x0002
#define PARAM_ATTRIBUTE_OPTIONAL           0x0010
#define PARAM_ATTRIBUTE_RESERVED_MASK      0xf000
#define PARAM_ATTRIBUTE_HAS_DEFAULT        0x1000
#define PARAM_ATTRIBUTE_HAS_FIELD_MARSHAL  0x2000
#define PARAM_ATTRIBUTE_UNUSED             0xcfe0

typedef int32_t TypeIndex;
typedef int32_t TypeDefinitionIndex;
typedef int32_t FieldIndex;
typedef int32_t DefaultValueIndex;
typedef int32_t DefaultValueDataIndex;
typedef int32_t CustomAttributeIndex;
typedef int32_t ParameterIndex;
typedef int32_t MethodIndex;
typedef int32_t GenericMethodIndex;
typedef int32_t PropertyIndex;
typedef int32_t EventIndex;
typedef int32_t GenericContainerIndex;
typedef int32_t GenericParameterIndex;
typedef int16_t GenericParameterConstraintIndex;
typedef int32_t NestedTypeIndex;
typedef int32_t InterfacesIndex;
typedef int32_t VTableIndex;
typedef int32_t InterfaceOffsetIndex;
typedef int32_t RGCTXIndex;
typedef int32_t StringIndex;
typedef int32_t StringLiteralIndex;
typedef int32_t GenericInstIndex;
typedef int32_t ImageIndex;
typedef int32_t AssemblyIndex;
typedef int32_t GuidIndex;

struct Il2CppType;

const int kPublicKeyByteLength = 8;

#pragma pack(push, 4)
struct Il2CppAssemblyName
{
	StringIndex nameIndex;
	StringIndex cultureIndex;
	StringIndex hashValueIndex;
	StringIndex publicKeyIndex;
	uint32_t hash_alg;
	int32_t hash_len;
	uint32_t flags;
	int32_t major;
	int32_t minor;
	int32_t build;
	int32_t revision;
	uint8_t publicKeyToken[kPublicKeyByteLength];
};

struct Il2CppMethodDefinition
{
	StringIndex nameIndex;
	TypeDefinitionIndex declaringType;
	TypeIndex returnType;
	ParameterIndex parameterStart;
	CustomAttributeIndex customAttributeIndex;
	GenericContainerIndex genericContainerIndex;
	MethodIndex methodIndex;
	MethodIndex invokerIndex;
	MethodIndex delegateWrapperIndex;
	RGCTXIndex rgctxStartIndex;
	int32_t rgctxCount;
	uint32_t token;
	uint16_t flags;
	uint16_t iflags;
	uint16_t slot;
	uint16_t parameterCount;
};

struct Il2CppImageDefinition
{
	StringIndex nameIndex;
	AssemblyIndex assemblyIndex;

	TypeDefinitionIndex typeStart;
	uint32_t typeCount;

	MethodIndex entryPointIndex;
	uint32_t token;
};

/*
struct Il2CppDebugMethodInfo
{
	const Il2CppDebugDocument *document;
	// Table of [offset -> lineno] mapping.
	// Ends with {-1,-1}
	const int32_t *offsets_table;
	const size_t code_size;
	const Il2CppDebugLocalsInfo **locals;

	int32_t sequence_points_count;
	int32_t breakpoints_count;// incremented atomically
	SequencePointRecord *sequence_points;
};
#endif

union Il2CppRGCTXData
{
	void* rgctxDataDummy;
	const MethodInfo* method;
	const Il2CppType* type;
	Il2CppClass* klass;
};

struct MethodInfo
{
	Il2CppMethodPointer method;
	InvokerMethod invoker_method;
	const char* name;
	Il2CppClass *declaring_type;
	const Il2CppType *return_type;
	const ParameterInfo* parameters;

	union
	{
		const Il2CppRGCTXData* rgctx_data; // is_inflated is true and is_generic is false, i.e. a generic instance method 
		const Il2CppMethodDefinition* methodDefinition;
	};

	// note, when is_generic == true and is_inflated == true the method represents an uninflated generic method on an inflated type. 
	union
	{
		const Il2CppGenericMethod* genericMethod; // is_inflated is true 
		const Il2CppGenericContainer* genericContainer; // is_inflated is false and is_generic is true 
	};

	CustomAttributeIndex customAttributeIndex;
	uint32_t token;
	uint16_t flags;
	uint16_t iflags;
	uint16_t slot;
	uint8_t parameters_count;
	uint8_t is_generic : 1; // true if method is a generic method definition 
	uint8_t is_inflated : 1; // true if declaring_type is a generic instance or if method is a generic instance

#if IL2CPP_DEBUGGER_ENABLED
	const Il2CppDebugMethodInfo *debug_info;
#endif
};*/

/*struct Il2CppRuntimeInterfaceOffsetPair
{
	Il2CppClass* interfaceType;
	int32_t offset;
};*/

/*
struct Il2CppClass
{
	// The following fields are always valid for a Il2CppClass structure
	const Il2CppImage* image;
	void* gc_desc;
	const char* name;
	const char* namespaze;
	const Il2CppType* byval_arg;
	const Il2CppType* this_arg;
	Il2CppClass* element_class;
	Il2CppClass* castClass;
	Il2CppClass* declaringType;
	Il2CppClass* parent;
	Il2CppGenericClass *generic_class;
	const Il2CppTypeDefinition* typeDefinition; // non-NULL for Il2CppClass's constructed from type defintions
												// End always valid fields

												// The following fields need initialized before access. This can be done per field or as an aggregate via a call to Class::Init
	FieldInfo* fields; // Initialized in SetupFields
	const EventInfo* events; // Initialized in SetupEvents
	const PropertyInfo* properties; // Initialized in SetupProperties
	const MethodInfo** methods; // Initialized in SetupMethods
	Il2CppClass** nestedTypes; // Initialized in SetupNestedTypes
	Il2CppClass** implementedInterfaces; // Initialized in SetupInterfaces
	const MethodInfo** vtable; // Initialized in Init
	Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets; // Initialized in Init
	void* static_fields; // Initialized in Init
	const Il2CppRGCTXData* rgctx_data; // Initialized in Init
									   // used for fast parent checks
	Il2CppClass** typeHierarchy; // Initialized in SetupTypeHierachy
								 // End initialization required fields

#if IL2CPP_DEBUGGER_ENABLED
	const Il2CppDebugTypeInfo *debug_info;
#endif

	uint32_t cctor_started;
	uint32_t cctor_finished;
	uint64_t cctor_thread;

	// Remaining fields are always valid except where noted
	GenericContainerIndex genericContainerIndex;
	CustomAttributeIndex customAttributeIndex;
	uint32_t instance_size;
	uint32_t actualSize;
	uint32_t element_size;
	int32_t native_size;
	uint32_t static_fields_size;
	uint32_t thread_static_fields_size;
	int32_t thread_static_fields_offset;
	uint32_t flags;
	uint32_t token;

	uint16_t method_count; // lazily calculated for arrays, i.e. when rank > 0
	uint16_t property_count;
	uint16_t field_count;
	uint16_t event_count;
	uint16_t nested_type_count;
	uint16_t vtable_count; // lazily calculated for arrays, i.e. when rank > 0
	uint16_t interfaces_count;
	uint16_t interface_offsets_count; // lazily calculated for arrays, i.e. when rank > 0

	uint8_t typeHierarchyDepth; // Initialized in SetupTypeHierachy
	uint8_t rank;
	uint8_t minimumAlignment;
	uint8_t packingSize;

	uint8_t valuetype : 1;
	uint8_t initialized : 1;
	uint8_t enumtype : 1;
	uint8_t is_generic : 1;
	uint8_t has_references : 1;
	uint8_t init_pending : 1;
	uint8_t size_inited : 1;
	uint8_t has_finalize : 1;
	uint8_t has_cctor : 1;
	uint8_t is_blittable : 1;
	uint8_t is_import : 1;
};
*/

struct Il2CppGenericInst 
{
	uint32_t type_argc;
	Il2CppType **type_argv;
};

struct Il2CppGenericContext 
{
	/* The instantiation corresponding to the class generic parameters */
	Il2CppGenericInst *class_inst;
	/* The instantiation corresponding to the method generic parameters */
	Il2CppGenericInst *method_inst;
};

struct Il2CppGenericParameter
{
	GenericContainerIndex ownerIndex;  /* Type or method this parameter was defined in. */
	StringIndex nameIndex;
	GenericParameterConstraintIndex constraintsStart;
	int16_t constraintsCount;
	uint16_t num;
	uint16_t flags;
};

struct Il2CppGenericContainer
{
	/* index of the generic type definition or the generic method definition corresponding to this container */
	int32_t ownerIndex; // either index into Il2CppClass metadata array or Il2CppMethodDefinition array
	int32_t type_argc;
	/* If true, we're a generic method, otherwise a generic type definition. */
	int32_t is_method;
	/* Our type parameters. */
	GenericParameterIndex genericParameterStart;
};

struct Il2CppGenericClass
{
	TypeDefinitionIndex typeDefinitionIndex;	/* the generic type definition */
	Il2CppGenericContext context;	/* a context that contains the type instantiation doesn't contain any method instantiation */
	void/*Il2CppClass*/ *cached_class;	/* if present, the Il2CppClass corresponding to the instantiation.  */
};

struct Il2CppGenericMethod
{
	const void* methodDefinition; // MethodInfo
	Il2CppGenericContext context;
};

typedef enum
{
	IL2CPP_TYPE_END = 0x00,       /* End of List */
	IL2CPP_TYPE_VOID = 0x01,
	IL2CPP_TYPE_BOOLEAN = 0x02,
	IL2CPP_TYPE_CHAR = 0x03,
	IL2CPP_TYPE_I1 = 0x04,
	IL2CPP_TYPE_U1 = 0x05,
	IL2CPP_TYPE_I2 = 0x06,
	IL2CPP_TYPE_U2 = 0x07,
	IL2CPP_TYPE_I4 = 0x08,
	IL2CPP_TYPE_U4 = 0x09,
	IL2CPP_TYPE_I8 = 0x0a,
	IL2CPP_TYPE_U8 = 0x0b,
	IL2CPP_TYPE_R4 = 0x0c,
	IL2CPP_TYPE_R8 = 0x0d,
	IL2CPP_TYPE_STRING = 0x0e,
	IL2CPP_TYPE_PTR = 0x0f,       /* arg: <type> token */
	IL2CPP_TYPE_BYREF = 0x10,       /* arg: <type> token */
	IL2CPP_TYPE_VALUETYPE = 0x11,       /* arg: <type> token */
	IL2CPP_TYPE_CLASS = 0x12,       /* arg: <type> token */
	IL2CPP_TYPE_VAR = 0x13,       /* Generic parameter in a generic type definition, represented as number (compressed unsigned integer) number */
	IL2CPP_TYPE_ARRAY = 0x14,       /* type, rank, boundsCount, bound1, loCount, lo1 */
	IL2CPP_TYPE_GENERICINST = 0x15,	   /* <type> <type-arg-count> <type-1> \x{2026} <type-n> */
	IL2CPP_TYPE_TYPEDBYREF = 0x16,
	IL2CPP_TYPE_I = 0x18,
	IL2CPP_TYPE_U = 0x19,
	IL2CPP_TYPE_FNPTR = 0x1b,	      /* arg: full method signature */
	IL2CPP_TYPE_OBJECT = 0x1c,
	IL2CPP_TYPE_SZARRAY = 0x1d,       /* 0-based one-dim-array */
	IL2CPP_TYPE_MVAR = 0x1e,       /* Generic parameter in a generic method definition, represented as number (compressed unsigned integer)  */
	IL2CPP_TYPE_CMOD_REQD = 0x1f,       /* arg: typedef or typeref token */
	IL2CPP_TYPE_CMOD_OPT = 0x20,       /* optional arg: typedef or typref token */
	IL2CPP_TYPE_INTERNAL = 0x21,       /* CLR internal type */

	IL2CPP_TYPE_MODIFIER = 0x40,       /* Or with the following types */
	IL2CPP_TYPE_SENTINEL = 0x41,       /* Sentinel for varargs method signature */
	IL2CPP_TYPE_PINNED = 0x45,       /* Local var that points to pinned object */

	IL2CPP_TYPE_ENUM = 0x55        /* an enumeration */
} Il2CppTypeEnum;

struct Il2CppType 
{
	union 
	{
		// We have this dummy field first because pre C99 compilers (MSVC) can only initializer the first value in a union.
		void* dummy;
		TypeDefinitionIndex klassIndex; /* for VALUETYPE and CLASS */
		const Il2CppType *type;   /* for PTR and SZARRAY */
		void *array; /* for ARRAY */ // Il2CppArrayType
									 //MonoMethodSignature *method;
		GenericParameterIndex genericParameterIndex; /* for VAR and MVAR */
		Il2CppGenericClass *generic_class; /* for GENERICINST */
	} data;
	unsigned int attrs : 16; /* param attributes or field flags */
	Il2CppTypeEnum type : 8;
	unsigned int num_mods : 6;  /* max 64 modifiers follow at the end */
	unsigned int byref : 1;
	unsigned int pinned : 1;  /* valid when included in a local var signature */
							  //MonoCustomMod modifiers [MONO_ZERO_LEN_ARRAY]; /* this may grow */
};

// compiler calcualted values
struct Il2CppTypeDefinitionSizes
{
	uint32_t instance_size;
	int32_t native_size;
	uint32_t static_fields_size;
	uint32_t thread_static_fields_size;
};

struct Il2CppFieldDefaultValue
{
	FieldIndex fieldIndex;
	TypeIndex typeIndex;
	DefaultValueDataIndex dataIndex;
};

struct Il2CppFieldDefinition
{
	StringIndex nameIndex;
	TypeIndex typeIndex;
	CustomAttributeIndex customAttributeIndex;
	uint32_t token;
};


struct Il2CppTypeDefinition
{
	StringIndex nameIndex;
	StringIndex namespaceIndex;
	CustomAttributeIndex customAttributeIndex;
	TypeIndex byvalTypeIndex;
	TypeIndex byrefTypeIndex;

	TypeIndex declaringTypeIndex;
	TypeIndex parentIndex;
	TypeIndex elementTypeIndex; // we can probably remove this one. Only used for enums

	RGCTXIndex rgctxStartIndex;
	int32_t rgctxCount;

	GenericContainerIndex genericContainerIndex;

	MethodIndex delegateWrapperFromManagedToNativeIndex;
	int32_t marshalingFunctionsIndex;
	int32_t ccwFunctionIndex;
	GuidIndex guidIndex;

	uint32_t flags;

	FieldIndex fieldStart;
	MethodIndex methodStart;
	EventIndex eventStart;
	PropertyIndex propertyStart;
	NestedTypeIndex nestedTypesStart;
	InterfacesIndex interfacesStart;
	VTableIndex vtableStart;
	InterfacesIndex interfaceOffsetsStart;

	uint16_t method_count;
	uint16_t property_count;
	uint16_t field_count;
	uint16_t event_count;
	uint16_t nested_type_count;
	uint16_t vtable_count;
	uint16_t interfaces_count;
	uint16_t interface_offsets_count;

	// bitfield to portably encode boolean values as single bits
	// 01 - valuetype;
	// 02 - enumtype;
	// 03 - has_finalize;
	// 04 - has_cctor;
	// 05 - is_blittable;
	// 06 - is_import;
	// 07-10 - One of nine possible PackingSize values (0, 1, 2, 4, 8, 16, 32, 64, or 128)
	uint32_t bitfield;
	uint32_t token;
};

struct Il2CppImage
{
	const char* name;
	AssemblyIndex assemblyIndex;

	TypeDefinitionIndex typeStart;
	uint32_t typeCount;

	MethodIndex entryPointIndex;

	mutable /*Il2CppNameToTypeDefinitionIndexHashTable*/void* nameToClassHashTable;

	uint32_t token;
};

struct Il2CppAssembly
{
	ImageIndex imageIndex;
	CustomAttributeIndex customAttributeIndex;
	int32_t referencedAssemblyStart;
	int32_t referencedAssemblyCount;
	Il2CppAssemblyName aname;
};

struct Il2CppParameterDefinition
{
	StringIndex nameIndex;
	uint32_t token;
	CustomAttributeIndex customAttributeIndex;
	TypeIndex typeIndex;
};

struct Il2CppParameterDefaultValue
{
	ParameterIndex parameterIndex;
	TypeIndex typeIndex;
	DefaultValueDataIndex dataIndex;
};

struct Il2CppGlobalMetadataHeader
{
	int32_t sanity;
	int32_t version;
	int32_t stringLiteralOffset; // string data for managed code
	int32_t stringLiteralCount;
	int32_t stringLiteralDataOffset;
	int32_t stringLiteralDataCount;
	int32_t stringOffset; // string data for metadata
	int32_t stringCount;
	int32_t eventsOffset; // Il2CppEventDefinition
	int32_t eventsCount;
	int32_t propertiesOffset; // Il2CppPropertyDefinition
	int32_t propertiesCount;
	int32_t methodsOffset; // Il2CppMethodDefinition
	int32_t methodsCount;
	int32_t parameterDefaultValuesOffset; // Il2CppParameterDefaultValue
	int32_t parameterDefaultValuesCount;
	int32_t fieldDefaultValuesOffset; // Il2CppFieldDefaultValue
	int32_t fieldDefaultValuesCount;
	int32_t fieldAndParameterDefaultValueDataOffset; // uint8_t
	int32_t fieldAndParameterDefaultValueDataCount;
	int32_t fieldMarshaledSizesOffset; // Il2CppFieldMarshaledSize
	int32_t fieldMarshaledSizesCount;
	int32_t parametersOffset; // Il2CppParameterDefinition
	int32_t parametersCount;
	int32_t fieldsOffset; // Il2CppFieldDefinition
	int32_t fieldsCount;
	int32_t genericParametersOffset; // Il2CppGenericParameter
	int32_t genericParametersCount;
	int32_t genericParameterConstraintsOffset; // TypeIndex
	int32_t genericParameterConstraintsCount;
	int32_t genericContainersOffset; // Il2CppGenericContainer
	int32_t genericContainersCount;
	int32_t nestedTypesOffset; // TypeDefinitionIndex
	int32_t nestedTypesCount;
	int32_t interfacesOffset; // TypeIndex
	int32_t interfacesCount;
	int32_t vtableMethodsOffset; // EncodedMethodIndex
	int32_t vtableMethodsCount;
	int32_t interfaceOffsetsOffset; // Il2CppInterfaceOffsetPair
	int32_t interfaceOffsetsCount;
	int32_t typeDefinitionsOffset; // Il2CppTypeDefinition
	int32_t typeDefinitionsCount;
	int32_t rgctxEntriesOffset; // Il2CppRGCTXDefinition
	int32_t rgctxEntriesCount;
	int32_t imagesOffset; // Il2CppImageDefinition
	int32_t imagesCount;
	int32_t assembliesOffset; // Il2CppAssemblyDefinition
	int32_t assembliesCount;
	int32_t metadataUsageListsOffset; // Il2CppMetadataUsageList
	int32_t metadataUsageListsCount;
	int32_t metadataUsagePairsOffset; // Il2CppMetadataUsagePair
	int32_t metadataUsagePairsCount;
	int32_t fieldRefsOffset; // Il2CppFieldRef
	int32_t fieldRefsCount;
	int32_t referencedAssembliesOffset; // int32_t
	int32_t referencedAssembliesCount;
	int32_t attributesInfoOffset; // Il2CppCustomAttributeTypeRange
	int32_t attributesInfoCount;
	int32_t attributeTypesOffset; // TypeIndex
	int32_t attributeTypesCount;
};

struct Il2CppMarshalingFunctions
{
	uint32_t marshal_to_native_func;
	uint32_t marshal_from_native_func;
	uint32_t marshal_cleanup_func;
};

struct Il2CppCodeRegistration
{
	uint32_t methodPointersCount;
	uint32_t* methodPointers;
	uint32_t delegateWrappersFromNativeToManagedCount;
	uint32_t** delegateWrappersFromNativeToManaged; // note the double indirection to handle different calling conventions
	uint32_t delegateWrappersFromManagedToNativeCount;
	uint32_t* delegateWrappersFromManagedToNative;
	uint32_t marshalingFunctionsCount;
	const Il2CppMarshalingFunctions* marshalingFunctions;
	uint32_t ccwMarshalingFunctionsCount;
	uint32_t* ccwMarshalingFunctions;
	uint32_t genericMethodPointersCount;
	uint32_t* genericMethodPointers;
	uint32_t invokerPointersCount;
	uint32_t* invokerPointers;
	CustomAttributeIndex customAttributeCount;
	uint32_t* customAttributeGenerators;
	GuidIndex guidCount;
	const void** guids; // Il2CppGuid
};

struct Il2CppMethodSpec
{
	MethodIndex methodDefinitionIndex;
	GenericInstIndex classIndexIndex;
	GenericInstIndex methodIndexIndex;
};

struct Il2CppMetadataRegistration
{
	int32_t genericClassesCount;
	Il2CppGenericClass** genericClasses;
	int32_t genericInstsCount;
	Il2CppGenericInst** genericInsts;
	int32_t genericMethodTableCount;
	void* genericMethodTable; // Il2CppGenericMethodFunctionsDefinitions
	int32_t typesCount;
	Il2CppType** types;
	int32_t methodSpecsCount;
	Il2CppMethodSpec* methodSpecs;

	FieldIndex fieldOffsetsCount;
	int32_t* fieldOffsets;

	TypeDefinitionIndex typeDefinitionsSizesCount;
	const Il2CppTypeDefinitionSizes* typeDefinitionsSizes;
	const size_t metadataUsagesCount;
	void*** metadataUsages;
};
#pragma pack(pop)