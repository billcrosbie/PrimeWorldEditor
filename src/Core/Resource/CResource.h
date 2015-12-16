#ifndef CRESOURCE_H
#define CRESOURCE_H

#include "EResType.h"
#include <Common/CFourCC.h>
#include <Common/CUniqueID.h>
#include <Common/types.h>
#include <Common/TString.h>

class CResCache;

// This macro creates functions that allow us to easily identify this resource type.
// Must be included on every CResource subclass.
#define DECLARE_RESOURCE_TYPE(ResTypeEnum) \
public: \
    virtual EResType Type() const \
    { \
        return ResTypeEnum; \
    } \
    \
    static EResType StaticType() \
    { \
        return ResTypeEnum; \
    } \
    \
private: \

class CResource
{
    DECLARE_RESOURCE_TYPE(eResource)
    friend class CResCache;

    TString mResSource;
    CUniqueID mID;
    int mRefCount;

public:
    CResource();
    virtual ~CResource();
    TString Source();
    TString FullSource();
    CUniqueID ResID();
    void Lock();
    void Release();
    bool IsValidResource();
    static EResType ResTypeForExtension(CFourCC Extension);
};

#endif // CRESOURCE_H