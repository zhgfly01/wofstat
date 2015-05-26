/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/xpcom/components/nsIClassInfo.idl
 */

#ifndef __gen_nsIClassInfo_h__
#define __gen_nsIClassInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
/**
 * Calling QueryInterface with this special IID will return a null-terminated
 * table of QITableEntry's. Not all objects support this.
 * Note that this breaks XPCOM rules a bit (the table doesn't derive from
 * nsISupports).
 */
#define NS_THISPTROFFSETS_SID \
    { 0x23e017cc, 0x5d6f, 0x430c, \
      { 0xb3, 0xe6, 0x9d, 0x32, 0x65, 0x70, 0xd6, 0xb8 } }

/* starting interface:    nsIClassInfo */
#define NS_ICLASSINFO_IID_STR "986c11d0-f340-11d4-9075-0010a4e73d9a"

#define NS_ICLASSINFO_IID \
  {0x986c11d0, 0xf340, 0x11d4, \
    { 0x90, 0x75, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIClassInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICLASSINFO_IID)

  /* void getInterfaces (out PRUint32 count, [array, size_is (count), retval] out nsIIDPtr array); */
  NS_SCRIPTABLE NS_IMETHOD GetInterfaces(PRUint32 *count NS_OUTPARAM, nsIID ***array NS_OUTPARAM) = 0;

  /* nsISupports getHelperForLanguage (in PRUint32 language); */
  NS_SCRIPTABLE NS_IMETHOD GetHelperForLanguage(PRUint32 language, nsISupports * *_retval NS_OUTPARAM) = 0;

  /* readonly attribute string contractID; */
  NS_SCRIPTABLE NS_IMETHOD GetContractID(char * *aContractID) = 0;

  /* readonly attribute string classDescription; */
  NS_SCRIPTABLE NS_IMETHOD GetClassDescription(char * *aClassDescription) = 0;

  /* readonly attribute nsCIDPtr classID; */
  NS_SCRIPTABLE NS_IMETHOD GetClassID(nsCID **aClassID) = 0;

  /* readonly attribute PRUint32 implementationLanguage; */
  NS_SCRIPTABLE NS_IMETHOD GetImplementationLanguage(PRUint32 *aImplementationLanguage) = 0;

  enum { SINGLETON = 1U };

  enum { THREADSAFE = 2U };

  enum { MAIN_THREAD_ONLY = 4U };

  enum { DOM_OBJECT = 8U };

  enum { PLUGIN_OBJECT = 16U };

  enum { CONTENT_NODE = 64U };

  enum { RESERVED = 2147483648U };

  /* readonly attribute PRUint32 flags; */
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) = 0;

  /* [notxpcom] readonly attribute nsCID classIDNoAlloc; */
  NS_IMETHOD GetClassIDNoAlloc(nsCID *aClassIDNoAlloc) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIClassInfo, NS_ICLASSINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICLASSINFO \
  NS_SCRIPTABLE NS_IMETHOD GetInterfaces(PRUint32 *count NS_OUTPARAM, nsIID ***array NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetHelperForLanguage(PRUint32 language, nsISupports * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetContractID(char * *aContractID); \
  NS_SCRIPTABLE NS_IMETHOD GetClassDescription(char * *aClassDescription); \
  NS_SCRIPTABLE NS_IMETHOD GetClassID(nsCID **aClassID); \
  NS_SCRIPTABLE NS_IMETHOD GetImplementationLanguage(PRUint32 *aImplementationLanguage); \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags); \
  NS_IMETHOD GetClassIDNoAlloc(nsCID *aClassIDNoAlloc); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICLASSINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInterfaces(PRUint32 *count NS_OUTPARAM, nsIID ***array NS_OUTPARAM) { return _to GetInterfaces(count, array); } \
  NS_SCRIPTABLE NS_IMETHOD GetHelperForLanguage(PRUint32 language, nsISupports * *_retval NS_OUTPARAM) { return _to GetHelperForLanguage(language, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetContractID(char * *aContractID) { return _to GetContractID(aContractID); } \
  NS_SCRIPTABLE NS_IMETHOD GetClassDescription(char * *aClassDescription) { return _to GetClassDescription(aClassDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetClassID(nsCID **aClassID) { return _to GetClassID(aClassID); } \
  NS_SCRIPTABLE NS_IMETHOD GetImplementationLanguage(PRUint32 *aImplementationLanguage) { return _to GetImplementationLanguage(aImplementationLanguage); } \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return _to GetFlags(aFlags); } \
  NS_IMETHOD GetClassIDNoAlloc(nsCID *aClassIDNoAlloc) { return _to GetClassIDNoAlloc(aClassIDNoAlloc); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICLASSINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInterfaces(PRUint32 *count NS_OUTPARAM, nsIID ***array NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfaces(count, array); } \
  NS_SCRIPTABLE NS_IMETHOD GetHelperForLanguage(PRUint32 language, nsISupports * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHelperForLanguage(language, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetContractID(char * *aContractID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContractID(aContractID); } \
  NS_SCRIPTABLE NS_IMETHOD GetClassDescription(char * *aClassDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassDescription(aClassDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetClassID(nsCID **aClassID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassID(aClassID); } \
  NS_SCRIPTABLE NS_IMETHOD GetImplementationLanguage(PRUint32 *aImplementationLanguage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImplementationLanguage(aImplementationLanguage); } \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlags(aFlags); } \
  NS_IMETHOD GetClassIDNoAlloc(nsCID *aClassIDNoAlloc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassIDNoAlloc(aClassIDNoAlloc); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsClassInfo : public nsIClassInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICLASSINFO

  nsClassInfo();

private:
  ~nsClassInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsClassInfo, nsIClassInfo)

nsClassInfo::nsClassInfo()
{
  /* member initializers and constructor code */
}

nsClassInfo::~nsClassInfo()
{
  /* destructor code */
}

/* void getInterfaces (out PRUint32 count, [array, size_is (count), retval] out nsIIDPtr array); */
NS_IMETHODIMP nsClassInfo::GetInterfaces(PRUint32 *count NS_OUTPARAM, nsIID ***array NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getHelperForLanguage (in PRUint32 language); */
NS_IMETHODIMP nsClassInfo::GetHelperForLanguage(PRUint32 language, nsISupports * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string contractID; */
NS_IMETHODIMP nsClassInfo::GetContractID(char * *aContractID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string classDescription; */
NS_IMETHODIMP nsClassInfo::GetClassDescription(char * *aClassDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsCIDPtr classID; */
NS_IMETHODIMP nsClassInfo::GetClassID(nsCID **aClassID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 implementationLanguage; */
NS_IMETHODIMP nsClassInfo::GetImplementationLanguage(PRUint32 *aImplementationLanguage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 flags; */
NS_IMETHODIMP nsClassInfo::GetFlags(PRUint32 *aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] readonly attribute nsCID classIDNoAlloc; */
NS_IMETHODIMP nsClassInfo::GetClassIDNoAlloc(nsCID *aClassIDNoAlloc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIClassInfo_h__ */
