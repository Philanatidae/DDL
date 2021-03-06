#ifndef DDL_H
#define DDL_H

#ifdef __cplusplus
extern "C" {
#endif

#define DDL_VERSION_MAJOR 0
#define DDL_VERSION_MINOR 1
#define DDL_VERSION_PATCH 0

#include <stddef.h>
#include <stdint.h>

#ifndef DDL_TRUE
#define DDL_TRUE 1
#endif
#ifndef DDL_FALSE
#define DDL_FALSE 0
#endif

#ifndef DDL_BOOL_T
#define DDL_BOOL_T int
#endif

#ifndef DDL_NULL
#define DDL_NULL 0
#endif

#ifndef DDL_HALF_T
#define DDL_HALF_T float
#endif

enum DDLStructType {
    DDLStructTypeRoot,
    DDLStructTypeDerived,
    DDLStructTypePrimitive
};
enum DDLDataType {
    DDLDataTypeInvalid = 0,
    DDLDataTypeBool,
    DDLDataTypeInt8,
    DDLDataTypeInt16,
    DDLDataTypeInt32,
    DDLDataTypeInt64,
    DDLDataTypeUInt8,
    DDLDataTypeUInt16,
    DDLDataTypeUInt32,
    DDLDataTypeUInt64,
    DDLDataTypeHalf,
    DDLDataTypeFloat,
    DDLDataTypeDouble,
    DDLDataTypeString,
    DDLDataTypeRef,
    DDLDataTypeType,
    DDLDataTypeBase64
};
enum DDLError {
    DDLErrorUnknown,
    DDLErrorUnexpectedToken,
    DDLErrorInvalidType,
    DDLErrorOutOfMemory,
    DDLErrorOutOfRange,
    DDLErrorUnexpectedEndOfFile,
    DDLErrorInvalidIdentifier,
    DDLErrorUnexpectedEndOfToken,
    DDLErrorInvalidData
};

struct DDLProp;
struct DDL;

enum DDLError DDL_getError();
char const* DDL_getErrorString();

struct DDL* DDL_create();
struct DDL* DDL_parseFromString(char const* ddlStr);
void DDL_free(struct DDL* ddl);

char const* DDL_getPropIdentifier(struct DDLProp* prop);
struct DDLProp* DDL_getPropNext(struct DDLProp* prop);

DDL_BOOL_T DDL_getPropBoolValue(struct DDLProp* prop, DDL_BOOL_T* outVal);
DDL_BOOL_T DDL_getPropInt8Value(struct DDLProp* prop, int8_t* outVal);
DDL_BOOL_T DDL_getPropInt16Value(struct DDLProp* prop, int16_t* outVal);
DDL_BOOL_T DDL_getPropInt32Value(struct DDLProp* prop, int32_t* outVal);
DDL_BOOL_T DDL_getPropInt64Value(struct DDLProp* prop, int64_t* outVal);
DDL_BOOL_T DDL_getPropUInt8Value(struct DDLProp* prop, uint8_t* outVal);
DDL_BOOL_T DDL_getPropUInt16Value(struct DDLProp* prop, uint16_t* outVal);
DDL_BOOL_T DDL_getPropUInt32Value(struct DDLProp* prop, uint32_t* outVal);
DDL_BOOL_T DDL_getPropUInt64Value(struct DDLProp* prop, uint64_t* outVal);
DDL_BOOL_T DDL_getPropHalfValue(struct DDLProp* prop, DDL_HALF_T* outVal);
DDL_BOOL_T DDL_getPropFloatValue(struct DDLProp* prop, float* outVal);
DDL_BOOL_T DDL_getPropDoubleValue(struct DDLProp* prop, double* outVal);
DDL_BOOL_T DDL_getPropStringValue(struct DDLProp* prop, char const** outVal);
DDL_BOOL_T DDL_getPropRefValue(struct DDLProp* prop, struct DDL** outVal);
DDL_BOOL_T DDL_getPropTypeValue(struct DDLProp* prop, enum DDLDataType* outVal);
DDL_BOOL_T DDL_getPropBase64Value(struct DDLProp* prop, void const** outVal, int* outSize);

enum DDLStructType DDL_getStructType(struct DDL* struc);
DDL_BOOL_T DDL_isStructRoot(struct DDL* struc);
DDL_BOOL_T DDL_isStructDerived(struct DDL* struc);
DDL_BOOL_T DDL_isStructPrimitive(struct DDL* struc);

char const* DDL_getStructIdentifier(struct DDL* struc);
DDL_BOOL_T DDL_hasStructName(struct DDL* struc);
char const* DDL_getStructName(struct DDL* struc);
DDL_BOOL_T DDL_isStructNameGlobal(struct DDL* struc);
DDL_BOOL_T DDL_isStructNameLocal(struct DDL* struc);

int DDL_getStructPropCount(struct DDL* struc);
struct DDLProp* DDL_getStructPropStart(struct DDL* struc);
struct DDLProp* DDL_getStructPropByIndex(struct DDL* struc, int index);
struct DDLProp* DDL_findStructProp(struct DDL* struc, char const* propIdentifier);

struct DDL* DDL_getStructSiblingNext(struct DDL* struc);
struct DDL* DDL_getStructSiblingNextByIdentifier(struct DDL* struc, char const* id);

int DDL_getStructSubCount(struct DDL* struc);
struct DDL* DDL_getStructSubStart(struct DDL* struc);
struct DDL* DDL_getStructSubByIndex(struct DDL* struc, int index);
struct DDL* DDL_findStructSubByName(struct DDL* struc, char const* name);
struct DDL* DDL_findStructSubByIdentifier(struct DDL* struc, char const* id);

DDL_BOOL_T DDL_isStructDataFlat(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataArray(struct DDL* struc);
int DDL_getStructDataArraySize(struct DDL* struc);
DDL_BOOL_T DDL_hasStructDataStates(struct DDL* struc);
int DDL_getStructDataCount(struct DDL* struc);
struct DDLData* DDL_getStructDataStart(struct DDL* struc);
struct DDLData* DDL_getStructDataByIndex(struct DDL* struc, int index);

enum DDLDataType DDL_getStructDataType(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataBool(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataInt8(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataInt16(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataInt32(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataInt64(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataUInt8(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataUInt16(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataUInt32(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataUInt64(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataHalf(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataFloat(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataDouble(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataString(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataRef(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataType(struct DDL* struc);
DDL_BOOL_T DDL_isStructDataBase64(struct DDL* struc);

DDL_BOOL_T DDL_getDataBoolValue(struct DDLData* data, DDL_BOOL_T* outVal);
DDL_BOOL_T DDL_getDataBoolArrayValue(struct DDLData* data, DDL_BOOL_T* outVal, int count);
DDL_BOOL_T DDL_getDataInt8Value(struct DDLData* data, int8_t* outVal);
DDL_BOOL_T DDL_getDataInt8ArrayValue(struct DDLData* data, int8_t* outVal, int count);
DDL_BOOL_T DDL_getDataInt16Value(struct DDLData* data, int16_t* outVal);
DDL_BOOL_T DDL_getDataInt16ArrayValue(struct DDLData* data, int16_t* outVal, int count);
DDL_BOOL_T DDL_getDataInt32Value(struct DDLData* data, int32_t* outVal);
DDL_BOOL_T DDL_getDataInt32ArrayValue(struct DDLData* data, int32_t* outVal, int count);
DDL_BOOL_T DDL_getDataInt64Value(struct DDLData* data, int64_t* outVal);
DDL_BOOL_T DDL_getDataInt64ArrayValue(struct DDLData* data, int64_t* outVal, int count);
DDL_BOOL_T DDL_getDataUInt8Value(struct DDLData* data, uint8_t* outVal);
DDL_BOOL_T DDL_getDataUInt8ArrayValue(struct DDLData* data, uint8_t* outVal, int count);
DDL_BOOL_T DDL_getDataUInt16Value(struct DDLData* data, uint16_t* outVal);
DDL_BOOL_T DDL_getDataUInt16ArrayValue(struct DDLData* data, uint16_t* outVal, int count);
DDL_BOOL_T DDL_getDataUInt32Value(struct DDLData* data, uint32_t* outVal);
DDL_BOOL_T DDL_getDataUInt32ArrayValue(struct DDLData* data, uint32_t* outVal, int count);
DDL_BOOL_T DDL_getDataUInt64Value(struct DDLData* data, uint64_t* outVal);
DDL_BOOL_T DDL_getDataUInt64ArrayValue(struct DDLData* data, uint64_t* outVal, int count);
DDL_BOOL_T DDL_getDataHalfValue(struct DDLData* data, DDL_HALF_T* outVal);
DDL_BOOL_T DDL_getDataHalfArrayValue(struct DDLData* data, DDL_HALF_T* outVal, int count);
DDL_BOOL_T DDL_getDataFloatValue(struct DDLData* data, float* outVal);
DDL_BOOL_T DDL_getDataFloatArrayValue(struct DDLData* data, float* outVal, int count);
DDL_BOOL_T DDL_getDataDoubleValue(struct DDLData* data, double* outVal);
DDL_BOOL_T DDL_getDataDoubleArrayValue(struct DDLData* data, double* outVal, int count);
DDL_BOOL_T DDL_getDataStringValue(struct DDLData* data, char const** outVal);
DDL_BOOL_T DDL_getDataStringArrayValue(struct DDLData* data, char const** outVal, int count);
DDL_BOOL_T DDL_getDataRefValue(struct DDLData* data, struct DDL** outVal);
DDL_BOOL_T DDL_getDataRefArrayValue(struct DDLData* data, struct DDL** outVal, int count);
DDL_BOOL_T DDL_getDataTypeValue(struct DDLData* data, enum DDLDataType* outVal);
DDL_BOOL_T DDL_getDataTypeArrayValue(struct DDLData* data, enum DDLDataType* outVal, int count);
DDL_BOOL_T DDL_getDataBase64Value(struct DDLData* data, void const** outVal, int* outSize);
DDL_BOOL_T DDL_getDataBase64ArrayValue(struct DDLData* data, void const** outVal, int* outSizes, int count);

struct DDLData* DDL_getDataNext(struct DDLData* data);
struct DDLData* DDL_getDataNextByIdentifier(struct DDLData* data, char const* identifier);

// #define DDL_IMPLEMENTATION
#ifdef DDL_IMPLEMENTATION

#include <stdlib.h>
#include <string.h>

#ifndef DDL_CUSTOM_MATH
#include <math.h>
#define DDL_DPOW(num, exp) pow((num), (exp))
#endif

enum DDLPropStorageType {
    DDLPropStorageTypeInvalid,
    DDLPropStorageTypeRawString,
    DDLPropStorageTypeString,
    DDLPropStorageTypeRef,
    DDLPropStorageTypeType,
    DDLPropStorageTypeBase64
};

struct DDLProp {
    char* identifier;
    enum DDLPropStorageType storageType;
    char* value;
    size_t size;

    struct DDLProp* next;
};

struct DDLData {
    enum DDLDataType type;
    char* identifier;
    int size;
    void* data;
    struct DDLData* next;
};

struct DDLBase64Data {
    int size;
    void* data;
};

struct DDL {
    enum DDLStructType type;
    char* identifier;
    char* name;
    DDL_BOOL_T isNameGlobal;
    int dataArrayCount;
    enum DDLDataType dataType;
    DDL_BOOL_T isDataStates;
    
    int propCount;
    struct DDLProp* propStart;
    int subCount;
    struct DDL* subStart;
    int dataCount;
    struct DDLData* dataStart;

    struct DDL* next;
};

static enum DDLError global_error;
static char const* global_error_str;
enum DDLError DDL_getError() {
    return global_error;
}
char const* DDL_getErrorString() {
    return global_error_str;
}

void DDL_reportError(enum DDLError error) {
    global_error = error;
    switch(global_error) {
    case DDLErrorUnexpectedToken:
        global_error_str = "Unexpected token.";
        break;
    case DDLErrorInvalidType:
        global_error_str = "Unknown type.";
        break;
    case DDLErrorOutOfMemory:
        global_error_str = "Out of memory.";
        break;
    case DDLErrorOutOfRange:
        global_error_str = "Out of range.";
        break;
    case DDLErrorUnexpectedEndOfFile:
        global_error_str = "Out of range.";
        break;
    case DDLErrorInvalidIdentifier:
        global_error_str = "Invalid identifier.";
        break;
    case DDLErrorInvalidData:
        global_error_str = "Invalid data.";
        break;
    default:
        global_error_str = "Unknown.";
        break;
    }
}

uint32_t DDL_convertHalfBitsToFloatBits(uint16_t halfBits) {
    // Source:
    //  - J. van der Zijp, ???Fast Half Float Conversions,??? Sep-2010. [Online]. Available: http://fox-toolkit.org/ftp/fasthalffloatconversion.pdf. [Accessed: 26-May-2022].

    uint32_t h = (uint32_t)halfBits;

    static uint32_t mantissatable[2028];
    static uint32_t offsettable[64];
    static uint32_t exponenttable[64];
    static DDL_BOOL_T init = DDL_FALSE;
    if(!init) {
        init = DDL_TRUE;

        mantissatable[0] = 0;
        for(int i = 1; i <= 1023; i++) {
            uint32_t m = i << 13;
            uint32_t e = 0;
            while(!(m & 0x00800000)) {
                e -= 0x00800000;
                m <<= 1;
            }
            m &= ~0x00800000;
            e += 0x38800000;
            mantissatable[i] = m | e;
        }
        for(int i = 1024; i <= 2047; i++) {
            mantissatable[i] = 0x38000000 + ((i - 1024) << 13);
        }
        
        exponenttable[0] = 0;
        exponenttable[32] = 0x80000000;
        for(int i = 1; i <= 30; i++) {
            exponenttable[i] = i << 23;
        }
        for(int i = 33; i <= 62; i++) {
            exponenttable[i] = 0x80000000 + ((i - 32) << 23);
        }
        exponenttable[31] = 0x47800000;
        exponenttable[63] = 0xC7800000;

        for(int i = 0; i < 64; i++) {
            if(i == 0 || i == 32) {
                offsettable[i] = 0;
                continue;
            }
            offsettable[i] = 1024;
        }
    }

    return mantissatable[offsettable[h >> 10] + (h & 0x3FF)] + exponenttable[h >> 10];
}
uint16_t DDL_convertFloatBitsToHalfBits(uint32_t floatBits) {
    // Source:
    //  - J. van der Zijp, ???Fast Half Float Conversions,??? Sep-2010. [Online]. Available: http://fox-toolkit.org/ftp/fasthalffloatconversion.pdf. [Accessed: 26-May-2022].
    static uint16_t basetable[512];
    static uint8_t shifttable[512];
    static DDL_BOOL_T init = DDL_FALSE;
    if(!init) {
        init = DDL_TRUE;

        for(int i = 0; i < 256; i++) {
            int e = i - 127;
            if(e < -24) {
                basetable[i | 0x000] = 0x0000;
                basetable[i | 0x100] = 0x8000;
                shifttable[i | 0x000] = 24;
                shifttable[i | 0x100] = 24;
            } else if(e < -14) {
                basetable[i | 0x000] = (0x0400 >> (-e - 14));
                basetable[i | 0x100] = (0x8000 >> (-e - 14) | 0x8000);
                shifttable[i | 0x000] = -e - 1;
                shifttable[i | 0x100] = -e - 1;
            } else if(e <= 15) {
                basetable[i | 0x000] = ((e + 15) << 10);
                basetable[i | 0x100] = ((e + 15) << 10) | 0x8000;
                shifttable[i | 0x000] = 13;
                shifttable[i | 0x100] = 13;
            } else if(e < 128) {
                basetable[i | 0x000] = 0x7C00;
                basetable[i | 0x100] = 0xFC00;
                shifttable[i | 0x000] = 24;
                shifttable[i | 0x100] = 24;
            } else {
                basetable[i | 0x000] = 0x7C00;
                basetable[i | 0x100] = 0xFC00;
                shifttable[i | 0x000] = 13;
                shifttable[i | 0x100] = 13;
            }
        }
    }

    return basetable[(floatBits >> 23) & 0x1FF] + ((floatBits * 0x007FFFFF) >> shifttable[(floatBits >> 23) & 0x1FF]);
}

struct DDL DDL_createStruct(enum DDLStructType structType) {
    return (struct DDL) {
        .type = structType,
        .identifier = DDL_NULL,
        .name = DDL_NULL,
        .isNameGlobal = DDL_FALSE,
        .dataArrayCount = 0,
        .dataType = DDLDataTypeInvalid,
        .isDataStates = DDL_FALSE,

        .propCount = 0,
        .propStart = DDL_NULL,
        .subCount = 0,
        .subStart = DDL_NULL,
        .dataCount = 0,
        .dataStart = DDL_NULL,

        .next = DDL_NULL
    };
}
struct DDL DDL_createRoot() {
    return DDL_createStruct(DDLStructTypeRoot);
}

struct DDLProp DDL_createProp() {
    return (struct DDLProp) {
        .identifier = DDL_NULL,
        .storageType = DDLPropStorageTypeInvalid,
        .value = DDL_NULL,
        .size = 0,
        .next = DDL_NULL
    };
}

struct DDLData DDL_createData(enum DDLDataType type) {
    return (struct DDLData) {
        .type = type
    };
}

struct DDL* DDL_create() {
    // Init if needed
    DDL_convertHalfBitsToFloatBits(0);
    DDL_convertFloatBitsToHalfBits(0);

    struct DDL* root = (struct DDL*)malloc(sizeof(struct DDL));
    if(root == DDL_NULL) {
        DDL_reportError(DDLErrorOutOfMemory);
        return DDL_NULL;
    }
    *root = DDL_createRoot();
    return root;
}

void DDL_freeProp(struct DDLProp* prop) {
    if(prop == DDL_NULL) {
        return;
    }

    if(prop->identifier != DDL_NULL) {
        free(prop->identifier);
    }
    if(prop->value != DDL_NULL) {
        free(prop->value);
    }
    DDL_freeProp(prop->next);
    free(prop);
}
void DDL_freeData(struct DDLData* data) {
    if(data == DDL_NULL) {
        return;
    }

    if(data->identifier != DDL_NULL) {
        free(data->identifier);
    }
    if(data->data != DDL_NULL) {
        free(data->data);
    }
    DDL_freeData(data->next);
    free(data);
}
void DDL_free(struct DDL* ddl) {
    if(ddl == DDL_NULL) {
        return;
    }

    if(ddl->identifier != DDL_NULL) {
        free(ddl->identifier);
    }
    if(ddl->name != DDL_NULL) {
        free(ddl->name);
    }
    DDL_freeProp(ddl->propStart);
    DDL_freeData(ddl->dataStart);
    DDL_free(ddl->subStart);
    DDL_free(ddl->next);
    free(ddl);
}

DDL_BOOL_T DDL_isIdentifierDataType(char const* identifier, int len) {
    if(len < 0) {
        len = strlen(identifier);
    }
    return strncmp(identifier, "bool", len) == 0
        || strncmp(identifier, "b", len) == 0
        || strncmp(identifier, "int8", len) == 0
        || strncmp(identifier, "i8", len) == 0
        || strncmp(identifier, "int16", len) == 0
        || strncmp(identifier, "i16", len) == 0
        || strncmp(identifier, "int32", len) == 0
        || strncmp(identifier, "i32", len) == 0
        || strncmp(identifier, "int64", len) == 0
        || strncmp(identifier, "uint8", len) == 0
        || strncmp(identifier, "u8", len) == 0
        || strncmp(identifier, "uint16", len) == 0
        || strncmp(identifier, "u16", len) == 0
        || strncmp(identifier, "uint32", len) == 0
        || strncmp(identifier, "u32", len) == 0
        || strncmp(identifier, "uint64", len) == 0
        || strncmp(identifier, "u64", len) == 0
        || strncmp(identifier, "half", len) == 0
        || strncmp(identifier, "float16", len) == 0
        || strncmp(identifier, "h", len) == 0
        || strncmp(identifier, "f16", len) == 0
        || strncmp(identifier, "float", len) == 0
        || strncmp(identifier, "float32", len) == 0
        || strncmp(identifier, "f", len) == 0
        || strncmp(identifier, "f32", len) == 0
        || strncmp(identifier, "double", len) == 0
        || strncmp(identifier, "float64", len) == 0
        || strncmp(identifier, "d", len) == 0
        || strncmp(identifier, "f64", len) == 0
        || strncmp(identifier, "string", len) == 0
        || strncmp(identifier, "s", len) == 0
        || strncmp(identifier, "ref", len) == 0
        || strncmp(identifier, "r", len) == 0
        || strncmp(identifier, "type", len) == 0
        || strncmp(identifier, "t", len) == 0
        || strncmp(identifier, "base64", len) == 0
        || strncmp(identifier, "z", len) == 0;
}
enum DDLDataType DDL_convertIdentifierToDataType(char const* identifier, int len) {
    if(len < 0) {
        len = strlen(identifier);
    }
    if((strncmp(identifier, "bool", len) == 0 && len == 4)
        || (strncmp(identifier, "b", len) == 0 && len == 1)) {
        return DDLDataTypeBool;
    }
    if((strncmp(identifier, "int8", len) == 0 && len == 4)
        || (strncmp(identifier, "i8", len) == 0 && len == 2)) {
        return DDLDataTypeInt8;
    }
    if((strncmp(identifier, "int16", len) == 0 && len == 4)
        || (strncmp(identifier, "i16", len) == 0 && len == 3)) {
        return DDLDataTypeInt16;
    }
    if((strncmp(identifier, "int32", len) == 0 && len == 4)
        || (strncmp(identifier, "i32", len) == 0 && len == 3)) {
        return DDLDataTypeInt32;
    }
    if((strncmp(identifier, "int64", len) == 0 && len == 4)
        || (strncmp(identifier, "i64", len) == 0 && len == 3)) {
        return DDLDataTypeInt64;
    }
    if((strncmp(identifier, "uint8", len) == 0 && len == 4)
        || (strncmp(identifier, "u8", len) == 0 && len == 2)) {
        return DDLDataTypeUInt8;
    }
    if((strncmp(identifier, "uint16", len) == 0 && len == 4)
        || (strncmp(identifier, "u16", len) == 0 && len == 3)) {
        return DDLDataTypeUInt16;
    }
    if((strncmp(identifier, "uint32", len) == 0 && len == 4)
        || (strncmp(identifier, "u32", len) == 0 && len == 3)) {
        return DDLDataTypeUInt32;
    }
    if((strncmp(identifier, "uint64", len) == 0 && len == 4)
        || (strncmp(identifier, "u64", len) == 0 && len == 3)) {
        return DDLDataTypeUInt64;
    }
    if((strncmp(identifier, "half", len) == 0 && len == 4)
        || (strncmp(identifier, "float16", len) == 0 && len == 7)
        || (strncmp(identifier, "h", len) == 0 && len == 1)
        || (strncmp(identifier, "f16", len) == 0 && len == 3)) {
        return DDLDataTypeHalf;
    }
    if((strncmp(identifier, "float", len) == 0 && len == 5)
        || (strncmp(identifier, "float32", len) == 0 && len == 7)
        || (strncmp(identifier, "f", len) == 0 && len == 1)
        || (strncmp(identifier, "f32", len) == 0 && len == 3)) {
        return DDLDataTypeFloat;
    }
    if((strncmp(identifier, "double", len) == 0 && len == 6)
        || (strncmp(identifier, "float64", len) == 0 && len == 7)
        || (strncmp(identifier, "d", len) == 0 && len == 1)
        || (strncmp(identifier, "f64", len) == 0 && len == 3)) {
        return DDLDataTypeDouble;
    }
    if((strncmp(identifier, "string", len) == 0 && len == 6)
        || (strncmp(identifier, "s", len) == 0 && len == 1)) {
        return DDLDataTypeString;
    }
    if((strncmp(identifier, "ref", len) == 0 && len == 3)
        || (strncmp(identifier, "r", len) == 0 && len == 1)) {
        return DDLDataTypeRef;
    }
    if((strncmp(identifier, "type", len) == 0 && len == 4)
        || (strncmp(identifier, "t", len) == 0 && len == 1)) {
        return DDLDataTypeType;
    }
    if((strncmp(identifier, "base64", len) == 0 && len == 6)
        || (strncmp(identifier, "z", len) == 0 && len == 1)) {
        return DDLDataTypeBase64;
    }
    return DDLDataTypeInvalid;
}
DDL_BOOL_T DDL_isIdentifierReserved(char const* identifier, int len) {
    if(DDL_isIdentifierDataType(identifier, len)) {
        return DDL_TRUE;
    }
    if(identifier[0] < 'a'
        || identifier[0] > 'z') {
        return DDL_FALSE;
    }
    if(len < 0) {
        len = strlen(identifier);
    }
    if(len == 1) {
        return DDL_FALSE;
    }
    for(int i = 1; i < len; i++) {
        if(identifier[i] < '0'
            || identifier[i] > '9') {
            return DDL_FALSE;
        }
    }
    return DDL_TRUE;
}

struct DDLParserState {
};

#define DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(expr, cleanup) if((expr) < 0) { cleanup; return -1; }
#define DDL_PARSE_ERROR_CHECK(expr) DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(expr, do{}while(0))

int DDL_skipWhitespace(char const* ddlMem, int ddlLen, int cursor, struct DDLParserState* parserState, DDL_BOOL_T expectingBase64) {
    // Advance cursor to first non-whitespace char
    DDL_BOOL_T inComment = DDL_FALSE;
    DDL_BOOL_T isSLComment = DDL_FALSE;
    while(1) {
        if(cursor >= ddlLen || ddlMem[cursor] == '\0') {
            if(inComment && !isSLComment) {
                DDL_reportError(DDLErrorUnexpectedEndOfFile);
                return -1;
            }
            return cursor;
        }

        char const c = ddlMem[cursor];

        switch(c) {
        case '\n':
        case '\r':
            if(inComment && isSLComment) {
                inComment = DDL_FALSE;
            }
        case '\t':
        case ' ':
            break;
        case '/':
            if(!expectingBase64) {
                if(!inComment) {
                    if(cursor + 1 < ddlLen) {
                        char const nextC = ddlMem[cursor + 1];
                        if(nextC == '/') {
                            inComment = DDL_TRUE;
                            isSLComment = DDL_TRUE;
                        } else if(nextC == '*') {
                            inComment = DDL_TRUE;
                            isSLComment = DDL_FALSE;
                        }
                    }
                } else if(!isSLComment) {
                    if(ddlMem[cursor - 1] == '*') {
                        inComment = DDL_FALSE;
                    }
                }
            }
            break;
        default:
            if(!inComment) {
                return cursor;
            }
            break;
        }

        cursor++;
    }

    DDL_reportError(DDLErrorUnknown);
    return -1;
}

int DDL_parseIdentifier(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    char const** outIdentifier,
    int* outIdentifierLen) {
    int const start = cursor;
    while(1) {
        if(cursor >= ddlLen || ddlMem[cursor] == '\0') {
            if(cursor == start) {
                DDL_reportError(DDLErrorUnexpectedEndOfFile);
                return -1;
            }
            return cursor;
        }

        char const c = ddlMem[cursor];

        if((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9' && cursor > start)) {
            cursor++;
            continue;
        }
        break;
    }

    if(outIdentifier != DDL_NULL) {
        *outIdentifier = &ddlMem[start];
    }
    if(outIdentifierLen != DDL_NULL) {
        *outIdentifierLen = cursor - start;
    }
    return DDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, DDL_FALSE);
}


DDL_BOOL_T DDL_parseToken(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    char token) {
    if(cursor >= ddlLen || ddlMem[cursor] == '\0') {
        DDL_reportError(DDLErrorUnexpectedEndOfFile);
        return -1;
    }

    if(ddlMem[cursor] != token) {
        DDL_reportError(DDLErrorUnexpectedToken);
        return -1;
    }
    
    return DDL_skipWhitespace(ddlMem, ddlLen, cursor + 1, parserState, DDL_FALSE);
}

#define DDL_EOF_CHECK_WITH_CLEANUP(cleanup) if(cursor >= ddlLen || ddlMem[cursor] == '\0') { \
    DDL_reportError(DDLErrorUnexpectedEndOfFile); \
    cleanup; \
    return -1; \
}
#define DDL_EOF_CHECK() DDL_EOF_CHECK_WITH_CLEANUP(do{}while(0))

int DDL_parseDecimalLiteral(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    uint64_t* outVal) {
    int const start = cursor;
    uint64_t num = 0;
    char prevC = '\0';
    while(1) {
        DDL_EOF_CHECK();

        char const c = ddlMem[cursor];
        switch(c) {
        case '_':
            if(cursor == start
                || prevC == '_') {
                DDL_reportError(DDLErrorUnexpectedToken);
                return -1;
            }
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            num *= 10;
            num += c - '0';
            break;
        default:
            if(cursor == start) {
                DDL_reportError(DDLErrorUnexpectedToken);
                return -1;
            }
            goto ddl_break;
        }

        prevC = c;
        cursor++;

    ddl_continue:
        continue;
    ddl_break:
        break;
    }

    if(outVal != DDL_NULL) {
        *outVal = num;
    }

    return DDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, DDL_FALSE);
}
static int8_t DDL_hexLookup[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, // 0-9
    -1, -1, -1, -1, -1, -1, -1, // :-@
    10, 11, 12, 13, 14, 15, 16, // A-F
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // G-`
    10, 11, 12, 13, 14, 15, 16 // a-f
};
int DDL_parseHexLiteral(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    uint64_t* outVal) {
    int const start = cursor;
    uint64_t num = 0;
    char prevC = '\0';
    while(1) {
        DDL_EOF_CHECK();

        char const c = ddlMem[cursor];
        switch(c) {
        case '_':
            if(cursor == start
                || prevC == '_') {
                DDL_reportError(DDLErrorUnexpectedToken);
                return -1;
            }
            break;
        default:
            if(c >= '0' && c <= 'f') {
                int8_t val = DDL_hexLookup[c - '0'];
                num *= 16;
                num += c - '0';
            } else {
                if(cursor == start) {
                    DDL_reportError(DDLErrorUnexpectedToken);
                    return -1;
                }
            }
            goto ddl_break;
        }

        prevC = c;
        cursor++;

    ddl_continue:
        continue;
    ddl_break:
        break;
    }

    if(outVal != DDL_NULL) {
        *outVal = num;
    }

    return DDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, DDL_FALSE);
}
int DDL_parseOctalLiteral(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    uint64_t* outVal) {
    int const start = cursor;
    uint64_t num = 0;
    char prevC = '\0';
    while(1) {
        DDL_EOF_CHECK();

        char const c = ddlMem[cursor];
        switch(c) {
        case '_':
            if(cursor == start
                || prevC == '_') {
                DDL_reportError(DDLErrorUnexpectedToken);
                return -1;
            }
            break;
        default:
            if(c >= '0' && c <= '7') {
                num *= 8;
                num += c - '0';
            } else {
                if(cursor == start) {
                    DDL_reportError(DDLErrorUnexpectedToken);
                    return -1;
                }
            }
            goto ddl_break;
        }

        prevC = c;
        cursor++;

    ddl_continue:
        continue;
    ddl_break:
        break;
    }

    if(outVal != DDL_NULL) {
        *outVal = num;
    }

    return DDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, DDL_FALSE);
}
int DDL_parseBinaryLiteral(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    uint64_t* outVal) {
    int const start = cursor;
    uint64_t num = 0;
    char prevC = '\0';
    while(1) {
        DDL_EOF_CHECK();

        char const c = ddlMem[cursor];
        switch(c) {
        case '_':
            if(cursor == start
                || prevC == '_') {
                DDL_reportError(DDLErrorUnexpectedToken);
                return -1;
            }
            break;
        default:
            if(c == '0' || c == '1') {
                num <<= 1;
                num += c - '0';
            } else {
                if(cursor == start) {
                    DDL_reportError(DDLErrorUnexpectedToken);
                    return -1;
                }
            }
            goto ddl_break;
        }

        prevC = c;
        cursor++;

    ddl_continue:
        continue;
    ddl_break:
        break;
    }

    if(outVal != DDL_NULL) {
        *outVal = num;
    }

    return DDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, DDL_FALSE);
}
int DDL_parseCharLiteral(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    uint64_t* outVal) {
    DDL_PARSE_ERROR_CHECK(cursor = DDL_parseToken(ddlMem, ddlLen, cursor, parserState, '\''));
    uint64_t num = 0;
    char prevC = '\0';
    while(1) {
        DDL_EOF_CHECK();

        char const c = ddlMem[cursor];
        if(prevC == '\\') {
            num *= 255;
            switch(c) {
            case '"':
            case '\'':
            case '?':
            case '\\':
                num += c;
                break;
            case 'a':
                num += '\a';
                break;
            case 'b':
                num += '\b';
                break;
            case 'f':
                num += '\f';
                break;
            case 'n':
                num += '\n';
                break;
            case 'r':
                num += '\r';
                break;
            case 't':
                num += '\t';
                break;
            case 'v':
                num += '\v';
                break;
            case 'x':
                // @todo look-ahead
                DDL_PARSE_ERROR_CHECK(cursor = DDL_parseToken(ddlMem, ddlLen, cursor, parserState, 'x'));
                uint64_t spec;
                DDL_PARSE_ERROR_CHECK(cursor = DDL_parseHexLiteral(&ddlMem[cursor + 1], 2, 0, DDL_NULL, &spec))
                num += spec;
                break;
            default:
                DDL_reportError(DDLErrorUnexpectedToken);
                return -1;
            }
        } else {
            switch(c) {
            case '\\':
                // Escape character, do nothing until resolution next character
                break;
            case '\'':
                // End of character list
                DDL_PARSE_ERROR_CHECK(cursor = DDL_parseToken(ddlMem, ddlLen, cursor, parserState, '\''));
                goto ddl_break;
            default:
                num *= 255;
                num += c;
                break;
            }
        }

        prevC = c;
        cursor++;

    ddl_continue:
        continue;
    ddl_break:
        break;
    }

    if(outVal != DDL_NULL) {
        *outVal = num;
    }

    return DDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, DDL_FALSE);
}
int DDL_parseIntegerLiteral(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    uint64_t* outVal) {
    DDL_EOF_CHECK();
    int const start = cursor;
    int sign = ddlMem[cursor] == '-' ? -1 : 1;
    if(ddlMem[cursor] == '-'
        || ddlMem[cursor] == '+') {
        cursor++;
    } 

    uint64_t num;

    DDL_BOOL_T parsed = DDL_FALSE;
    if(ddlMem[cursor] == '\'') {
        DDL_PARSE_ERROR_CHECK(cursor = DDL_parseCharLiteral(ddlMem, ddlLen, cursor, parserState, &num));
        parsed = DDL_TRUE;
    } else {
        if(cursor + 2 < ddlLen
            && ddlMem[cursor] == '0') {
            switch(ddlMem[cursor + 1]) {
            case 'x':
            case 'X':
                cursor += 2;
                DDL_PARSE_ERROR_CHECK(cursor = DDL_parseHexLiteral(ddlMem, ddlLen, cursor, parserState, &num));
                parsed = DDL_TRUE;
                break;
            case 'o':
            case 'O':
                cursor += 2;
                DDL_PARSE_ERROR_CHECK(cursor = DDL_parseOctalLiteral(ddlMem, ddlLen, cursor, parserState, &num));
                parsed = DDL_TRUE;
                break;
            case 'b':
            case 'B':
                cursor += 2;
                DDL_PARSE_ERROR_CHECK(cursor = DDL_parseBinaryLiteral(ddlMem, ddlLen, cursor, parserState, &num));
                parsed = DDL_TRUE;
                break;
            default:
                break;
            }
        }
    }

    if(!parsed) {
        DDL_PARSE_ERROR_CHECK(cursor = DDL_parseDecimalLiteral(ddlMem, ddlLen, cursor, parserState, &num));
    }

    num *= sign;

    if(outVal != DDL_NULL) {
        *outVal = num;
    }    

    return cursor;
}

int DDL_parseFloatLiteral(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    int parsingBytes,
    double* outVal) {
    if(parsingBytes != 2
        && parsingBytes != 4
        && parsingBytes != 8) {
        DDL_reportError(DDLErrorUnknown);
        return -1;
    }

    DDL_EOF_CHECK();
    int const start = cursor;
    int sign = ddlMem[cursor] == '-' ? -1 : 1;
    if(ddlMem[cursor] == '-'
        || ddlMem[cursor] == '+') {
        cursor++;
    } 

    double num = 0;

    DDL_BOOL_T parsed = DDL_FALSE;
    if(cursor + 2 < ddlLen
        && ddlMem[cursor] == '0') {
        uint64_t nbits = 0;
        switch(ddlMem[cursor + 1]) {
        case 'x':
        case 'X':
            cursor += 2;
            DDL_PARSE_ERROR_CHECK(cursor = DDL_parseHexLiteral(ddlMem, ddlLen, cursor, parserState, &nbits));
            if((nbits >> (parsingBytes * 8)) > 0) {
                DDL_reportError(DDLErrorOutOfRange);
                return -1;
            }
            parsed = DDL_TRUE;
            break;
        case 'o':
        case 'O':
            cursor += 2;
            DDL_PARSE_ERROR_CHECK(cursor = DDL_parseOctalLiteral(ddlMem, ddlLen, cursor, parserState, &nbits));
            num = *(double*)&nbits;
            parsed = DDL_TRUE;
            break;
        case 'b':
        case 'B':
            cursor += 2;
            DDL_PARSE_ERROR_CHECK(cursor = DDL_parseBinaryLiteral(ddlMem, ddlLen, cursor, parserState, &nbits));
            num = *(double*)&nbits;
            parsed = DDL_TRUE;
            break;
        default:
            break;
        }
        if(parsed) {
            switch(parsingBytes) {
            case 2:
                {
                    uint32_t fbits = DDL_convertHalfBitsToFloatBits((uint16_t)nbits);
                    num = (double)*(float*)&fbits;
                }
                break;
            case 4:
                num = (double)*(float*)&nbits;
                break;
            case 8:
                num = *(double*)&nbits;
                break;
            default:
                break;
            }
        }
    }

    if(!parsed) {
        double mul = 1;
        double expSign = 1;
        double exp = 0;
        DDL_BOOL_T seenDecimal = DDL_FALSE;
        DDL_BOOL_T seenExponent = DDL_FALSE;
        DDL_BOOL_T expSpecified = DDL_FALSE;

        char prevC = '\0';
        while(1) {
            DDL_EOF_CHECK();

            char const c = ddlMem[cursor];
            switch(c) {
            case '_':
                if(cursor == start
                    || prevC == '_'
                    || prevC == '.'
                    || prevC == 'e'
                    || prevC == 'E') {
                    DDL_reportError(DDLErrorUnexpectedToken);
                    return -1;
                }
                break;
            case '.':
                if(seenDecimal
                    || seenExponent) {
                    DDL_reportError(DDLErrorUnexpectedToken);
                    return -1;
                }
                seenDecimal = DDL_TRUE;
                break;
            case 'e':
            case 'E':
                if(seenExponent
                    || cursor == start) {
                    DDL_reportError(DDLErrorUnexpectedToken);
                    return -1;
                }
                seenExponent = DDL_TRUE;
                break;
            case '-':
            case '+':
                if(!seenExponent
                    || (prevC != 'e' && prevC != 'E')) {
                    DDL_reportError(DDLErrorUnexpectedToken);
                    return -1;
                }
                expSign = c == '-' ? -1 : 1;
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if(seenExponent) {
                    expSpecified = DDL_TRUE;
                    exp *= 10;
                    exp += c - '0';
                } else {
                    if(seenDecimal) {
                        mul /= 10;
                    }
                    num *= 10;
                    num += c - '0';
                }
                break;    
            default:
                if(seenExponent && !expSpecified) {
                    DDL_reportError(DDLErrorUnexpectedToken);
                    return -1;
                }
                DDL_PARSE_ERROR_CHECK(cursor = DDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, DDL_FALSE));
                goto ddl_break;
            }

            prevC = c;
            cursor++;
        
        ddl_continue:
            continue;
        ddl_break:
            break;
        }

        num *= mul;
        exp *= expSign;
        num *= DDL_DPOW(10, exp);
    }

    num *= sign;

    if(outVal != DDL_NULL) {
        *outVal = num;
    }    

    return cursor;
}

int DDL_parseHalf(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    void* outVal) {
    DDL_EOF_CHECK();
    double dnum;
    DDL_PARSE_ERROR_CHECK(cursor = DDL_parseFloatLiteral(ddlMem, ddlLen, cursor, parserState, sizeof(DDL_HALF_T), &dnum));

    float fnum = (float)dnum;
    if(sizeof(DDL_HALF_T) == sizeof(float)) {
        if(outVal != DDL_NULL) {
            *(float*)outVal = fnum;
        }
    } else {
        if(outVal != DDL_NULL) {
            uint32_t fbits = *(uint32_t*)&fnum;
            uint16_t hbits = DDL_convertFloatBitsToHalfBits(fbits);
            *(DDL_HALF_T*)outVal = *(DDL_HALF_T*)&hbits;
        }
    }

    return cursor;
}
int DDL_parseFloat(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    void* outVal) {
    DDL_EOF_CHECK();
    double dnum;
    DDL_PARSE_ERROR_CHECK(cursor = DDL_parseFloatLiteral(ddlMem, ddlLen, cursor, parserState, sizeof(float), &dnum));

    // @todo Check if double can be converted into float?
    float num = dnum;
    
    if(outVal != DDL_NULL) {
        *(float*)outVal = num;
    }

    return cursor;
}
int DDL_parseDouble(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    void* outVal) {
    DDL_EOF_CHECK();
    double dnum;
    DDL_PARSE_ERROR_CHECK(cursor = DDL_parseFloatLiteral(ddlMem, ddlLen, cursor, parserState, sizeof(double), &dnum));
    
    if(outVal != DDL_NULL) {
        *(double*)outVal = dnum;
    }

    return cursor;
}

int DDL_parseBool(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    void* outVal) {
    DDL_EOF_CHECK();
    DDL_BOOL_T b;
    if(ddlMem[cursor] == '0'
        || ddlMem[cursor] == '1') {
        b = ddlMem[cursor] == '1' ? DDL_TRUE : DDL_FALSE;
        cursor++;
    } else {
        if((cursor + 4) >= ddlLen) {
            DDL_reportError(DDLErrorUnexpectedEndOfFile);
            return -1;
        } else {
            if(cursor + 5 < ddlLen
                && strcmp(&ddlMem[cursor], "false") == 0) {
                b = DDL_FALSE;
                cursor += 5;
            } else if(strcmp(&ddlMem[cursor], "true") == 0) {
                b = DDL_TRUE;
                cursor += 4;
            } else {
                DDL_reportError(DDLErrorUnexpectedToken);
                return -1;
            }
        }
    }

    if(outVal != DDL_NULL) {
        *(DDL_BOOL_T*)outVal = b;
    }

    return DDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, DDL_FALSE);
}

int DDL_parseInt8(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    void* outVal) {
    uint64_t unum;
    DDL_PARSE_ERROR_CHECK(cursor = DDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, &unum));
    int64_t num = (uint64_t)unum;
    if(num < -128 || num > 127) {
        DDL_reportError(DDLErrorOutOfRange);
        return -1;
    }

    if(outVal != DDL_NULL) {
        *(int8_t*)outVal = (int8_t)num;
    }

    return cursor;
}
int DDL_parseInt16(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    void* outVal) {
    uint64_t unum;
    DDL_PARSE_ERROR_CHECK(cursor = DDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, &unum));
    int64_t num = (uint64_t)unum;
    if(num < -32768 || num > 32767) {
        DDL_reportError(DDLErrorOutOfRange);
        return -1;
    }

    if(outVal != DDL_NULL) {
        *(int16_t*)outVal = (int16_t)num;
    }

    return cursor;
}
int DDL_parseInt32(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    void* outVal) {
    uint64_t unum;
    DDL_PARSE_ERROR_CHECK(cursor = DDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, &unum));
    int64_t num = (uint64_t)unum;
    if(num < -2147483648 || num > 2147483647) {
        DDL_reportError(DDLErrorOutOfRange);
        return -1;
    }

    if(outVal != DDL_NULL) {
        *(int32_t*)outVal = (int32_t)num;
    }

    return cursor;
}
int DDL_parseInt64(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    void* outVal) {
    uint64_t unum;
    DDL_PARSE_ERROR_CHECK(cursor = DDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, &unum));
    int64_t num = (uint64_t)unum;

    if(outVal != DDL_NULL) {
        *(int64_t*)outVal = num;
    }

    return cursor;
}
int DDL_parseUInt8(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    void* outVal) {
    uint64_t num;
    DDL_PARSE_ERROR_CHECK(cursor = DDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, &num));
    if((num >> 8) > 0) {
        DDL_reportError(DDLErrorOutOfMemory);
        return -1;
    }

    if(outVal != DDL_NULL) {
        *(uint8_t*)outVal = (uint8_t)num;
    }

    return cursor;
}
int DDL_parseUInt16(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    void* outVal) {
    uint64_t num;
    DDL_PARSE_ERROR_CHECK(cursor = DDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, &num));
    if((num >> 16) > 0) {
        DDL_reportError(DDLErrorOutOfMemory);
        return -1;
    }

    if(outVal != DDL_NULL) {
        *(uint16_t*)outVal = (uint16_t)num;
    }

    return cursor;
}
int DDL_parseUInt32(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    void* outVal) {
    uint64_t num;
    DDL_PARSE_ERROR_CHECK(cursor = DDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, &num));
    if((num >> 32) > 0) {
        DDL_reportError(DDLErrorOutOfMemory);
        return -1;
    }

    if(outVal != DDL_NULL) {
        *(uint32_t*)outVal = (uint32_t)num;
    }

    return cursor;
}
int DDL_parseUInt64(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    void* outVal) {
    return DDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, (uint64_t*)outVal);
}

int DDL_parseType(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    void* outVal) {
    char const* identifier;
    int identifierLen;
    DDL_PARSE_ERROR_CHECK(cursor = DDL_parseIdentifier(ddlMem, ddlLen, cursor, parserState, &identifier, &identifierLen));

    enum DDLDataType dtype = DDL_convertIdentifierToDataType(identifier, identifierLen);
    if(dtype == DDLDataTypeInvalid) {
        DDL_reportError(DDLErrorUnexpectedToken);
        return -1;
    } 

    if(outVal != DDL_NULL) {
        *(enum DDLDataType*)outVal = dtype;
    }

    return cursor;
}

static int (*DDL_dataTypeParsers[])(char const*, int, int, struct DDLParserState*, void*) = {
    DDL_NULL, // Invalid
    &DDL_parseBool,
    &DDL_parseInt8,
    &DDL_parseInt16,
    &DDL_parseInt32,
    &DDL_parseInt64,
    &DDL_parseUInt8,
    &DDL_parseUInt16,
    &DDL_parseUInt32,
    &DDL_parseUInt64,
    &DDL_parseHalf,
    &DDL_parseFloat,
    &DDL_parseDouble,
    DDL_NULL, // String
    DDL_NULL, // Ref
    &DDL_parseType, // Type
    DDL_NULL // Base64
};
static int DDL_dataTypeSizes[] = {
    -1, // Invalid
    sizeof(DDL_BOOL_T),
    sizeof(int8_t),
    sizeof(int16_t),
    sizeof(int32_t),
    sizeof(int64_t),
    sizeof(uint8_t),
    sizeof(uint16_t),
    sizeof(uint32_t),
    sizeof(uint64_t),
    sizeof(DDL_HALF_T),
    sizeof(float),
    sizeof(double),
    -1, // String
    -1, // Ref
    sizeof(enum DDLDataType),
    -1 // Base64
};

int DDL_parseInnerProps(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    struct DDLProp** outPropStart,
    int* outPropCount) {
    struct DDLProp* propStart = DDL_NULL;
    struct DDLProp** propNext = DDL_NULL;
    int propCount = 0;

    int const start = cursor;
    while(1) {
        DDL_EOF_CHECK();

        if(ddlMem[cursor] == ')') {
            break;
        }

        // If we are on a ',', we need to skip to the identifier
        if(ddlMem[cursor] == ',') {
            DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_parseToken(ddlMem, ddlLen, cursor, parserState, ','), DDL_freeProp(propStart));
        }

        // Identifier
        char const* identifier;
        int identifierLen;
        DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_parseIdentifier(ddlMem, ddlLen, cursor, parserState, &identifier, &identifierLen), DDL_freeProp(propStart));

        struct DDLProp* prop = (struct DDLProp*)malloc(sizeof(struct DDLProp));
        if(prop == DDL_NULL) {
            DDL_reportError(DDLErrorOutOfMemory);
            DDL_freeProp(propStart);
            return -1;
        }
        *prop = DDL_createProp();
        if(propStart == DDL_NULL) {
            propStart = prop;
        } else {
            *propNext = prop;
        }
        propNext = &prop->next;
        propCount++;
        prop->identifier = (char*)malloc((identifierLen + 1) * sizeof(char));
        if(prop->identifier == DDL_NULL) {
            DDL_reportError(DDLErrorOutOfMemory);
            DDL_freeProp(propStart);
            return -1;
        }
        strncpy(prop->identifier, identifier, identifierLen);
        prop->identifier[identifierLen] = '\0';

        // Value
        DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, DDL_FALSE), DDL_freeProp(propStart));
        DDL_EOF_CHECK_WITH_CLEANUP(DDL_freeProp(propStart));
        if(ddlMem[cursor] == ',' || ddlMem[cursor] == ')') {
            // Boolean true
            prop->value = strdup("1");
            prop->size = 1;
            prop->storageType = DDLPropStorageTypeRawString;
            if(prop->value == DDL_NULL) {
                DDL_reportError(DDLErrorOutOfMemory);
                DDL_freeProp(propStart);
                return -1;
            }
            continue;
        }

        // Expecting a '='
        DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_parseToken(ddlMem, ddlLen, cursor, parserState, '='), DDL_freeProp(propStart));

        // Grab raw string value
        DDL_BOOL_T inString = DDL_FALSE;
        DDL_BOOL_T escaping = DDL_FALSE;
        int const rawStrStart = cursor;
        while(1) {
            if(cursor < ddlLen && ddlMem[cursor] == '\0') {
                DDL_reportError(DDLErrorUnexpectedEndOfFile);
                DDL_freeProp(propStart);
                return -1;
            }
            char const c = ddlMem[cursor];

            if(c == ',' || c == ')') {
                break;
            }

            if(c == '"') {
                if(!escaping) {
                    inString = !inString;
                }
            }
            if(escaping) {
                escaping = DDL_FALSE;
            }
            if(inString) {
                if(!escaping && c == '\\') {
                    escaping = DDL_TRUE;
                }
            }

            cursor++;
        }
        int const rawStrLen = cursor - rawStrStart;
        prop->size = rawStrLen;
        prop->value = (char*)malloc((rawStrLen + 1) * sizeof(char));
        if(prop->value == DDL_NULL) {
            DDL_reportError(DDLErrorOutOfMemory);
            DDL_freeProp(propStart);
            return -1;
        }
        strncpy(prop->value, &ddlMem[rawStrStart], rawStrLen);
        ((char*)(prop->value))[rawStrLen] = '\0';
    }

    if(outPropStart != DDL_NULL) {
        *outPropStart = propStart;
    }
    if(outPropCount != DDL_NULL) {
        *outPropCount = propCount;
    }

    return cursor;
}
int DDL_parseInnerDataWithParser(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    struct DDL* struc) {
    if(struc == DDL_NULL) {
        DDL_reportError(DDLErrorUnknown);
        return -1;
    }

    struct DDLData* dataStart = DDL_NULL;
    struct DDLData** dataNext = DDL_NULL;
    int dataCount = 0;

    while(1) {
        DDL_EOF_CHECK();

        if(ddlMem[cursor] == '}') {
            break;
        }

        struct DDLData* data = (struct DDLData*)malloc(sizeof(struct DDLData));
        if(data == DDL_NULL) {
            DDL_reportError(DDLErrorOutOfMemory);
            DDL_freeData(dataStart);
            return -1;
        }
        *data = DDL_createData(struc->dataType);
        if(dataStart == DDL_NULL) {
            dataStart = data;
        } else {
            *dataNext = data;
        }
        dataNext = &data->next;
        dataCount++;
        int dataLen = 1;
        if(struc->dataArrayCount > 0) {
            dataLen = struc->dataArrayCount;
        }
        data->size = sizeof(DDL_dataTypeSizes[(int)data->type]) * dataLen;

        data->data = malloc(data->size);
        if(data == DDL_NULL) {
            DDL_reportError(DDLErrorOutOfMemory);
            DDL_freeData(dataStart);
            return -1;
        }
        if(struc->dataArrayCount > 0) {
            DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_parseToken(ddlMem, ddlLen, cursor, parserState, '{'), DDL_freeData(dataStart));
            for(int i = 0; i < struc->dataArrayCount; i++) {
                intptr_t ptr = (intptr_t)data->data;
                ptr += i * sizeof(DDL_dataTypeSizes[(int)data->type]);
                DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_dataTypeParsers[(int)data->type](ddlMem, ddlLen, cursor, parserState, (void*)ptr), DDL_freeData(dataStart));
                if(i < struc->dataArrayCount - 1) {
                    DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_parseToken(ddlMem, ddlLen, cursor, parserState, ','), DDL_freeData(dataStart));
                } else {
                    DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_parseToken(ddlMem, ddlLen, cursor, parserState, '}'), DDL_freeData(dataStart));
                }
            }
        } else {
            // No outer braces
            DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_dataTypeParsers[(int)data->type](ddlMem, ddlLen, cursor, parserState, data->data), DDL_freeData(dataStart));
        }

        // Either a `,` or a `}`
        DDL_EOF_CHECK();
        if(ddlMem[cursor] == ',') {
            DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_parseToken(ddlMem, ddlLen, cursor, parserState, ','), DDL_freeData(dataStart))
        }
    }

    struc->dataStart = dataStart;
    struc->dataCount = dataCount;

    return cursor;
}
int DDL_parseStructure(char const* ddlMem, int ddlLen,
    int cursor,
    struct DDLParserState* parserState,
    struct DDL** outStruc) {
    char const* identifier;
    int identifierLen;
    DDL_PARSE_ERROR_CHECK(cursor = DDL_parseIdentifier(ddlMem, ddlLen, cursor, parserState, &identifier, &identifierLen));

    DDL_BOOL_T isStrucPrimitive = DDL_FALSE;
    enum DDLDataType strucDataType = DDL_convertIdentifierToDataType(identifier, identifierLen);

    if(strucDataType != DDLDataTypeInvalid) {
        isStrucPrimitive = DDL_TRUE;
    } else {
        if(DDL_isIdentifierReserved(identifier, identifierLen)) {
            DDL_reportError(DDLErrorInvalidIdentifier);
            return -1;
        } else {
            isStrucPrimitive = DDL_FALSE;
        }
    }

    DDL_EOF_CHECK();

    struct DDL* struc = (struct DDL*)malloc(sizeof(struct DDL));
    if(struc == DDL_NULL) {
        DDL_reportError(DDLErrorOutOfMemory);
        return -1;
    }
    *struc = DDL_createStruct(isStrucPrimitive ? DDLStructTypePrimitive : DDLStructTypeDerived);
    if(isStrucPrimitive) {
        struc->dataType = strucDataType;
    }
    struc->identifier = (char*)malloc((identifierLen + 1) * sizeof(char));
    if(struc->identifier == DDL_NULL) {
        DDL_reportError(DDLErrorOutOfMemory);
        DDL_free(struc);
        return -1;
    }
    strncpy(struc->identifier, identifier, identifierLen);
    struc->identifier[identifierLen] = '\0';

    DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_skipWhitespace(ddlMem, ddlLen, cursor, parserState, DDL_FALSE), DDL_free(struc));
    DDL_BOOL_T expectingName = DDL_TRUE;
    DDL_BOOL_T expectingProperties = struc->type == DDLStructTypeDerived;
    DDL_BOOL_T expectingSubarrayN = struc->type == DDLStructTypePrimitive;
    DDL_BOOL_T expectingDataStates = DDL_FALSE;
    while(1) {
        switch(ddlMem[cursor]) {
        case '$':
        case '%':
            if(!expectingName) {
                DDL_reportError(DDLErrorUnexpectedToken);
                DDL_free(struc);
                return -1;
            }
            struc->isNameGlobal = ddlMem[cursor] == '$';
            cursor++;
            char const* name;
            int nameLen;
            DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_parseIdentifier(ddlMem, ddlLen, cursor, parserState, &name, &nameLen), DDL_free(struc));
            struc->name = (char*)malloc((nameLen + 1) * sizeof(char));
            if(struc->name == DDL_NULL) {
                DDL_reportError(DDLErrorOutOfMemory);
                DDL_free(struc);
                return -1;
            }
            strncpy(struc->name, name, nameLen);
            struc->name[nameLen] = '\0';

            expectingSubarrayN = expectingDataStates = expectingName = DDL_FALSE;
            break;
        case '{':
            DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_parseToken(ddlMem, ddlLen, cursor, parserState, '{'), DDL_free(struc));

            if(struc->type == DDLStructTypeDerived) {
                struct DDL** subNext = &struc->subStart;
                while(cursor < ddlLen
                    && ddlMem[cursor] != '\0'
                    && ddlMem[cursor] != '}') {
                    struct DDL* subStruc = DDL_NULL;
                    DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_parseStructure(ddlMem, ddlLen, cursor, parserState, &subStruc), DDL_free(struc));
                    *subNext = subStruc;
                    subNext = &subStruc->next;
                    struc->subCount++;
                }
            } else {
                DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_parseInnerDataWithParser(ddlMem, ddlLen, cursor, parserState, struc), DDL_free(struc));
            }

            DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_parseToken(ddlMem, ddlLen, cursor, parserState, '}'), DDL_free(struc));
            goto ddl_break;
        case '[':
            if(!expectingSubarrayN) {
                DDL_reportError(DDLErrorUnexpectedToken);
                DDL_free(struc);
                return -1;
            }

            DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_skipWhitespace(ddlMem, ddlLen, cursor + 1, parserState, DDL_FALSE), DDL_free(struc));
            uint64_t subarrayN;
            DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_parseIntegerLiteral(ddlMem, ddlLen, cursor, parserState, &subarrayN), DDL_free(struc));
            if(subarrayN <= 0) {
                DDL_reportError(DDLErrorOutOfRange);
                DDL_free(struc);
                return -1;
            }
            DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_parseToken(ddlMem, ddlLen, cursor, parserState, ']'), DDL_free(struc));
            struc->dataArrayCount = subarrayN;

            expectingSubarrayN = DDL_FALSE;
            expectingDataStates = DDL_TRUE;
            break;
        case '*':
            if(!expectingDataStates) {
                DDL_reportError(DDLErrorUnexpectedToken);
                DDL_free(struc);
                return -1;
            }

            DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_skipWhitespace(ddlMem, ddlLen, cursor + 1, parserState, DDL_FALSE), DDL_free(struc));
            struc->isDataStates = DDL_TRUE;

            expectingDataStates = DDL_FALSE;
            break;
        case '(':
            if(!expectingProperties) {
                DDL_reportError(DDLErrorUnexpectedToken);
                DDL_free(struc);
                return -1;
            }

            DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_parseToken(ddlMem, ddlLen, cursor, parserState, '('), DDL_free(struc));
            DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_parseInnerProps(ddlMem, ddlLen, cursor, parserState, &struc->propStart, &struc->propCount), DDL_free(struc));
            DDL_PARSE_ERROR_CHECK_WITH_CLEANUP(cursor = DDL_parseToken(ddlMem, ddlLen, cursor, parserState, ')'), DDL_free(struc));

            expectingProperties = DDL_FALSE;
            break;

        default:
            DDL_reportError(DDLErrorUnexpectedToken);
            return -1;
        }

    ddl_continue:
        continue;
    ddl_break:
        break;
    }

    if(outStruc != DDL_NULL) {
        *outStruc = struc;
    }

    return cursor;
}

struct DDL* DDL_parseFromString(char const* ddlStr) {
    struct DDL* root = DDL_create();
    if(root == DDL_NULL) {
        DDL_reportError(DDLErrorOutOfMemory);
        return DDL_NULL;
    }

    int const ddlLen = strlen(ddlStr);
    struct DDLParserState parserState;
    int cursor = DDL_skipWhitespace(ddlStr, ddlLen, 0, &parserState, DDL_FALSE);

    struct DDL** subNext = &root->subStart;
    while(cursor < ddlLen && ddlStr[cursor] != '\0') {
        struct DDL* subStruc = DDL_NULL;
        cursor = DDL_parseStructure(ddlStr, ddlLen, cursor, &parserState, &subStruc);
        if(cursor < 0) {
            DDL_free(root);
            return DDL_NULL;
        }
        *subNext = subStruc;
        subNext = &subStruc->next;
        root->subCount++;
    }

    return root;
}

char const* DDL_getPropIdentifier(struct DDLProp* prop) {
    return prop->identifier;
}
struct DDLProp* DDL_getPropNext(struct DDLProp* prop) {
    return prop->next;
}

DDL_BOOL_T DDL_getPropBoolValue(struct DDLProp* prop, DDL_BOOL_T* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseBool((char const*)prop->value, prop->size, 0, DDL_NULL, outVal);
}
DDL_BOOL_T DDL_getPropInt8Value(struct DDLProp* prop, int8_t* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseInt8((char const*)prop->value, prop->size, 0, DDL_NULL, outVal);
}
DDL_BOOL_T DDL_getPropInt16Value(struct DDLProp* prop, int16_t* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseInt16((char const*)prop->value, prop->size, 0, DDL_NULL, outVal);
}
DDL_BOOL_T DDL_getPropInt32Value(struct DDLProp* prop, int32_t* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseInt32((char const*)prop->value, prop->size, 0, DDL_NULL, outVal);
}
DDL_BOOL_T DDL_getPropInt64Value(struct DDLProp* prop, int64_t* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseInt64((char const*)prop->value, prop->size, 0, DDL_NULL, outVal);
}
DDL_BOOL_T DDL_getPropUInt8Value(struct DDLProp* prop, uint8_t* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseUInt8((char const*)prop->value, prop->size, 0, DDL_NULL, outVal);
}
DDL_BOOL_T DDL_getPropUInt16Value(struct DDLProp* prop, uint16_t* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseUInt16((char const*)prop->value, prop->size, 0, DDL_NULL, outVal);
}
DDL_BOOL_T DDL_getPropUInt32Value(struct DDLProp* prop, uint32_t* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseUInt32((char const*)prop->value, prop->size, 0, DDL_NULL, outVal);
}
DDL_BOOL_T DDL_getPropUInt64Value(struct DDLProp* prop, uint64_t* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    return DDL_parseUInt64((char const*)prop->value, prop->size, 0, DDL_NULL, outVal);
}
DDL_BOOL_T DDL_getPropHalfValue(struct DDLProp* prop, DDL_HALF_T* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    // return DDL_parseStringAsHalf((char*)prop->value, prop->size, outVal);
}
DDL_BOOL_T DDL_getPropFloatValue(struct DDLProp* prop, float* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    // return DDL_parseStringAsFloat((char*)prop->value, prop->size, outVal);
}
DDL_BOOL_T DDL_getPropDoubleValue(struct DDLProp* prop, double* outVal) {
    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    // return DDL_parseStringAsDouble((char*)prop->value, prop->size, outVal);
}
DDL_BOOL_T DDL_getPropStringValue(struct DDLProp* prop, char const** outVal) {
    if(prop->storageType == DDLPropStorageTypeString) {
        if(outVal != DDL_NULL) {
            *outVal = (char const*)prop->value;
        }
        return DDL_TRUE;
    }

    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    void* valuePtr = prop->value;
    // if(!DDL_parseStringAsString((char*)prop->value, prop->size, (char**)&prop->value)) {
    //     return DDL_FALSE;
    // }
    free(valuePtr);
    prop->storageType = DDLPropStorageTypeString;
    return DDL_getPropStringValue(prop, outVal);
}
DDL_BOOL_T DDL_getPropRefValue(struct DDLProp* prop, struct DDL** outVal) {
    DDL_reportError(DDLErrorUnknown);
    return DDL_FALSE;
}
DDL_BOOL_T DDL_getPropTypeValue(struct DDLProp* prop, enum DDLDataType* outVal) {
    if(prop->storageType == DDLPropStorageTypeType) {
        if(outVal != DDL_NULL) {
            *outVal = *(enum DDLDataType*)prop->value;
        }
        return DDL_TRUE;
    }

    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    void* valuePtr = prop->value;
    // enum DDLDataType* dataType = malloc(sizeof(enum DDLDataType)); 
    // if(!DDL_parseStringAsType((char*)prop->value, prop->size, dataType)) {
    //     return DDL_FALSE;
    // }
    // free(valuePtr);
    // prop->value = valuePtr;
    // prop->storageType = DDLPropStorageTypeType;
    // return DDL_getPropTypeValue(prop, outVal);
}
DDL_BOOL_T DDL_getPropBase64Value(struct DDLProp* prop, void const** outVal, int* outSize) {
    if(prop->storageType == DDLPropStorageTypeType) {
        if(outVal != DDL_NULL) {
            *outVal = (enum DDLDataType*)prop->value;
        }
        return DDL_TRUE;
    }

    if(prop->storageType != DDLPropStorageTypeRawString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }

    void* valuePtr = prop->value;
    size_t dataSize;
    // if(!DDL_parseStringAsBase64((char*)prop->value, prop->size, (uint8_t**)&prop->value, &dataSize)) {
    //     return DDL_FALSE;
    // }
    free(valuePtr);
    prop->storageType = DDLPropStorageTypeBase64;
    prop->size = dataSize;
    return DDL_getPropBase64Value(prop, outVal, outSize);
}

enum DDLStructType DDL_getStructType(struct DDL* struc) {
    return struc->type;
}
DDL_BOOL_T DDL_isStructRoot(struct DDL* struc) {
    return struc->type == DDLStructTypeRoot;
}
DDL_BOOL_T DDL_isStructDerived(struct DDL* struc) {
    return struc->type == DDLStructTypeDerived;
}
DDL_BOOL_T DDL_isStructPrimitive(struct DDL* struc) {
    return struc->type == DDLStructTypePrimitive;
}

char const* DDL_getStructIdentifier(struct DDL* struc) {
    if(struc->identifier == DDL_NULL) {
        return "";
    }
    return struc->identifier;
}
DDL_BOOL_T DDL_hasStructName(struct DDL* struc) {
    return struc->name != DDL_NULL;
}
char const* DDL_getStructName(struct DDL* struc) {
    if(struc->name == DDL_NULL) {
        return "";
    }
    return struc->name;
}
DDL_BOOL_T DDL_isStructNameGlobal(struct DDL* struc) {
    return struc->isNameGlobal;
}
DDL_BOOL_T DDL_isStructNameLocal(struct DDL* struc) {
    return !struc->isNameGlobal;
}

int DDL_getStructPropCount(struct DDL* struc) {
    return struc->propCount;
}
struct DDLProp* DDL_getStructPropStart(struct DDL* struc) {
    return struc->propStart;
}
struct DDLProp* DDL_getStructPropByIndex(struct DDL* struc, int index) {
    int i = 0;
    struct DDLProp* prop = struc->propStart;
    do {
        if(prop == DDL_NULL) {
            return DDL_NULL;
        }
        prop = prop->next;
    }while(++i < index);
    return prop;
}
struct DDLProp* DDL_findStructProp(struct DDL* struc, char const* propIdentifier) {
    struct DDLProp* prop = struc->propStart;
    while(prop != DDL_NULL) {
        if(strcmp(prop->identifier, propIdentifier) == 0) {
            return prop;
        }
        prop = prop->next;
    }
    return DDL_NULL;
}

struct DDL* DDL_getStructSiblingNext(struct DDL* struc) {
    return struc->next;
}
struct DDL* DDL_getStructSiblingNextByIdentifier(struct DDL* struc, char const* id) {
    while(struc != DDL_NULL) {
        if(strcmp(struc->identifier, id) == 0) {
            return struc;
        }
        struc = struc->next;
    }
    return DDL_NULL;
}

int DDL_getStructSubCount(struct DDL* struc) {
    return struc->subCount;
}
struct DDL* DDL_getStructSubStart(struct DDL* struc) {
    return struc->subStart;
}
struct DDL* DDL_getStructSubByIndex(struct DDL* struc, int index) {
    struct DDL* sub = struc->subStart;
    int i = 0;
    do {
        if(sub == DDL_NULL) {
            return DDL_NULL;
        }
        sub = sub->next;
    } while(++i < index);
    return sub;
}
struct DDL* DDL_findStructSubByName(struct DDL* struc, char const* name) {
    struct DDL* sub = struc->subStart;
    while(sub != DDL_NULL) {
        if(strcmp(sub->name, name) == 0) {
            return sub;
        }
        sub = sub->next;
    }
    return DDL_NULL;
}
struct DDL* DDL_findStructSubByIdentifier(struct DDL* struc, char const* id) {
    struct DDL* sub = struc->subStart;
    while(sub != DDL_NULL) {
        if(strcmp(sub->identifier, id) == 0) {
            return sub;
        }
        sub = sub->next;
    }
    return DDL_NULL;
}

DDL_BOOL_T DDL_isStructDataFlat(struct DDL* struc) {
    return struc->dataArrayCount == 0;
}
DDL_BOOL_T DDL_isStructDataArray(struct DDL* struc) {
    return struc->dataArrayCount > 0;
}
int DDL_getStructDataArraySize(struct DDL* struc) {
    return struc->dataArrayCount;
}
DDL_BOOL_T DDL_hasStructDataStates(struct DDL* struc) {
    return struc->isDataStates;
}
int DDL_getStructDataCount(struct DDL* struc) {
    return struc->dataCount;
}
struct DDLData* DDL_getStructDataStart(struct DDL* struc) {
    return struc->dataStart;
}
struct DDLData* DDL_getStructDataByIndex(struct DDL* struc, int index) {
    struct DDLData* data = struc->dataStart;
    int i = 0;
    do {
        if(data == DDL_NULL) {
            return DDL_NULL;
        }
        data = data->next;
    } while(++i < index);
    return data;
}

enum DDLDataType DDL_getStructDataType(struct DDL* struc) {
    return struc->dataType;
}
DDL_BOOL_T DDL_isStructDataBool(struct DDL* struc) {
    return struc->dataType == DDLDataTypeBool;
}
DDL_BOOL_T DDL_isStructDataInt8(struct DDL* struc) {
    return struc->dataType == DDLDataTypeInt8;
}
DDL_BOOL_T DDL_isStructDataInt16(struct DDL* struc) {
    return struc->dataType == DDLDataTypeInt16;
}
DDL_BOOL_T DDL_isStructDataInt32(struct DDL* struc) {
    return struc->dataType == DDLDataTypeInt32;
}
DDL_BOOL_T DDL_isStructDataInt64(struct DDL* struc) {
    return struc->dataType == DDLDataTypeInt64;
}
DDL_BOOL_T DDL_isStructDataUInt8(struct DDL* struc) {
    return struc->dataType == DDLDataTypeUInt8;
}
DDL_BOOL_T DDL_isStructDataUInt16(struct DDL* struc) {
    return struc->dataType == DDLDataTypeUInt16;
}
DDL_BOOL_T DDL_isStructDataUInt32(struct DDL* struc) {
    return struc->dataType == DDLDataTypeUInt32;
}
DDL_BOOL_T DDL_isStructDataUInt64(struct DDL* struc) {
    return struc->dataType == DDLDataTypeUInt64;
}
DDL_BOOL_T DDL_isStructDataHalf(struct DDL* struc) {
    return struc->dataType == DDLDataTypeHalf;
}
DDL_BOOL_T DDL_isStructDataFloat(struct DDL* struc) {
    return struc->dataType == DDLDataTypeFloat;
}
DDL_BOOL_T DDL_isStructDataDouble(struct DDL* struc) {
    return struc->dataType == DDLDataTypeDouble;
}
DDL_BOOL_T DDL_isStructDataString(struct DDL* struc) {
    return struc->dataType == DDLDataTypeString;
}
DDL_BOOL_T DDL_isStructDataRef(struct DDL* struc) {
    return struc->dataType == DDLDataTypeRef;
}
DDL_BOOL_T DDL_isStructDataType(struct DDL* struc) {
    return struc->dataType == DDLDataTypeType;
}
DDL_BOOL_T DDL_isStructDataBase64(struct DDL* struc) {
    return struc->dataType == DDLDataTypeBase64;
}

DDL_BOOL_T DDL_getDataBoolValue(struct DDLData* data, DDL_BOOL_T* outVal) {
    if(data->type != DDLDataTypeBool) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(DDL_BOOL_T*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataBoolArrayValue(struct DDLData* data, DDL_BOOL_T* outVal, int count) {
    if(data->type != DDLDataTypeBool) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(DDL_BOOL_T);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((DDL_BOOL_T*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataInt8Value(struct DDLData* data, int8_t* outVal) {
    if(data->type != DDLDataTypeInt8) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(int8_t*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataInt8ArrayValue(struct DDLData* data, int8_t* outVal, int count) {
    if(data->type != DDLDataTypeInt8) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(int8_t);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((int8_t*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataInt16Value(struct DDLData* data, int16_t* outVal) {
    if(data->type != DDLDataTypeInt16) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(int16_t*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataInt16ArrayValue(struct DDLData* data, int16_t* outVal, int count) {
    if(data->type != DDLDataTypeInt16) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(int16_t);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((int16_t*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataInt32Value(struct DDLData* data, int32_t* outVal) {
    if(data->type != DDLDataTypeInt32) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(int32_t*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataInt32ArrayValue(struct DDLData* data, int32_t* outVal, int count) {
    if(data->type != DDLDataTypeInt32) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(int32_t);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((int32_t*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataInt64Value(struct DDLData* data, int64_t* outVal) {
    if(data->type != DDLDataTypeInt64) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(int64_t*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataInt64ArrayValue(struct DDLData* data, int64_t* outVal, int count) {
    if(data->type != DDLDataTypeInt16) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(int16_t);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((int8_t*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataUInt8Value(struct DDLData* data, uint8_t* outVal) {
    if(data->type != DDLDataTypeUInt8) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(int8_t*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataUInt8ArrayValue(struct DDLData* data, uint8_t* outVal, int count) {
    if(data->type != DDLDataTypeUInt8) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(uint8_t);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((uint8_t*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataUInt16Value(struct DDLData* data, uint16_t* outVal) {
    if(data->type != DDLDataTypeUInt16) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(uint16_t*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataUInt16ArrayValue(struct DDLData* data, uint16_t* outVal, int count) {
    if(data->type != DDLDataTypeUInt16) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(uint16_t);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((uint16_t*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataUInt32Value(struct DDLData* data, uint32_t* outVal) {
    if(data->type != DDLDataTypeUInt32) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(uint32_t*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataUInt32ArrayValue(struct DDLData* data, uint32_t* outVal, int count) {
    if(data->type != DDLDataTypeUInt32) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(uint32_t);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((uint32_t*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataUInt64Value(struct DDLData* data, uint64_t* outVal) {
    if(data->type != DDLDataTypeUInt64) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(uint64_t*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataUInt64ArrayValue(struct DDLData* data, uint64_t* outVal, int count) {
    if(data->type != DDLDataTypeUInt64) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(uint64_t);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((uint64_t*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataHalfValue(struct DDLData* data, DDL_HALF_T* outVal) {
    if(data->type != DDLDataTypeHalf) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(DDL_HALF_T*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataHalfArrayValue(struct DDLData* data, DDL_HALF_T* outVal, int count) {
    if(data->type != DDLDataTypeHalf) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(DDL_HALF_T);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((DDL_HALF_T*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataFloatValue(struct DDLData* data, float* outVal) {
    if(data->type != DDLDataTypeFloat) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(float*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataFloatArrayValue(struct DDLData* data, float* outVal, int count) {
    if(data->type != DDLDataTypeFloat) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(float);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((float*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataDoubleValue(struct DDLData* data, double* outVal) {
    if(data->type != DDLDataTypeDouble) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(double*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataDoubleArrayValue(struct DDLData* data, double* outVal, int count) {
    if(data->type != DDLDataTypeDouble) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(double);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((double*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataStringValue(struct DDLData* data, char const** outVal) {
    if(data->type != DDLDataTypeString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    if(outVal != DDL_NULL) {
        *outVal = (char*)data->data;
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataStringArrayValue(struct DDLData* data, char const** outVal, int count) {
    if(data->type != DDLDataTypeString) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size; // This one is a bit different, stores string count instead of total data size
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }

    char const* strStart = (char*)data->data;

    if(outVal != DDL_NULL) {
        outVal[0] = strStart;
        for(int i = 1; i < count; i++) {
            strStart = strStart + strlen(strStart) + 2;
            outVal[i] = strStart;
        }
    }

    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataRefValue(struct DDLData* data, struct DDL** outVal) {
    DDL_reportError(DDLErrorUnknown);
    return DDL_FALSE;
}
DDL_BOOL_T DDL_getDataRefArrayValue(struct DDLData* data, struct DDL** outVal, int count) {
    DDL_reportError(DDLErrorUnknown);
    return DDL_FALSE;
}
DDL_BOOL_T DDL_getDataTypeValue(struct DDLData* data, enum DDLDataType* outVal) {
    if(data->type != DDLDataTypeType) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    *outVal = *(enum DDLDataType*)data->data;
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataTypeArrayValue(struct DDLData* data, enum DDLDataType* outVal, int count) {
    if(data->type != DDLDataTypeType) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size / sizeof(enum DDLDataType);
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }
    for(int i = 0; i < count; i++) {
        outVal[i] = ((enum DDLDataType*)data->data)[i];
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataBase64Value(struct DDLData* data, void const** outVal, int* outSize) {
    if(data->type != DDLDataTypeBase64) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    struct DDLBase64Data* base64Data = (struct DDLBase64Data*)data->data;

    if(outVal != DDL_NULL) {
        if(outSize == DDL_NULL) {
            DDL_reportError(DDLErrorUnknown);
            return DDL_FALSE;
        }
        *outVal = base64Data->data;
        *outSize = base64Data->size;
    }
    return DDL_TRUE;
}
DDL_BOOL_T DDL_getDataBase64ArrayValue(struct DDLData* data, void const** outVal, int* outSizes, int count) {
    if(data->type != DDLDataTypeBase64) {
        DDL_reportError(DDLErrorInvalidType);
        return DDL_FALSE;
    }
    int dataCount = data->size; // This one is a bit different, stores blob count instead of total data size
    if(dataCount < count) {
        DDL_reportError(DDLErrorOutOfRange);
        return DDL_FALSE;
    }

    if(outVal != DDL_NULL) {
        if(outSizes == DDL_NULL) {
            DDL_reportError(DDLErrorUnknown);
            return DDL_FALSE;
        }

        uint8_t* dataStart = (uint8_t*)data->data;
        for(int i = 0; i < count; i++) {
            // First sizeof(uint64_t) bytes store size of blob after it, in bytes 
            uint64_t blobSize = ((uint64_t*)dataStart)[0];

            outVal[i] = dataStart;    
            outSizes[i] = blobSize;
            dataStart += sizeof(uint64_t) + blobSize;
        }
    }
    return DDL_TRUE;
}

#endif

#ifdef __cplusplus
}
#endif

#endif /* DDL_H */
