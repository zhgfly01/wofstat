/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/indexedDB/nsIIDBIndex.idl
 */

#ifndef __gen_nsIIDBIndex_h__
#define __gen_nsIIDBIndex_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIIDBObjectStore; /* forward declaration */

class nsIIDBRequest; /* forward declaration */


/* starting interface:    nsIIDBIndex */
#define NS_IIDBINDEX_IID_STR "1da60889-3db4-4f66-9fd7-b78c1e7969b7"

#define NS_IIDBINDEX_IID \
  {0x1da60889, 0x3db4, 0x4f66, \
    { 0x9f, 0xd7, 0xb7, 0x8c, 0x1e, 0x79, 0x69, 0xb7 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIIDBIndex : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBINDEX_IID)

  /* readonly attribute DOMString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute DOMString storeName; */
  NS_SCRIPTABLE NS_IMETHOD GetStoreName(nsAString & aStoreName) = 0;

  /* readonly attribute DOMString keyPath; */
  NS_SCRIPTABLE NS_IMETHOD GetKeyPath(nsAString & aKeyPath) = 0;

  /* readonly attribute boolean unique; */
  NS_SCRIPTABLE NS_IMETHOD GetUnique(bool *aUnique) = 0;

  /* readonly attribute nsIIDBObjectStore objectStore; */
  NS_SCRIPTABLE NS_IMETHOD GetObjectStore(nsIIDBObjectStore * *aObjectStore) = 0;

  /* [implicit_jscontext] nsIIDBRequest get (in jsval key); */
  NS_SCRIPTABLE NS_IMETHOD Get(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM) = 0;

  /* [implicit_jscontext] nsIIDBRequest getKey (in jsval key); */
  NS_SCRIPTABLE NS_IMETHOD GetKey(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM) = 0;

  /* [implicit_jscontext,optional_argc] nsIIDBRequest getAll ([optional] in jsval key, [optional] in unsigned long limit); */
  NS_SCRIPTABLE NS_IMETHOD GetAll(const JS::Value & key, PRUint32 limit, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) = 0;

  /* [implicit_jscontext,optional_argc] nsIIDBRequest getAllKeys ([optional] in jsval key, [optional] in unsigned long limit); */
  NS_SCRIPTABLE NS_IMETHOD GetAllKeys(const JS::Value & key, PRUint32 limit, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) = 0;

  /* [implicit_jscontext,optional_argc] nsIIDBRequest openCursor ([optional] in jsval key, [optional] in unsigned short direction); */
  NS_SCRIPTABLE NS_IMETHOD OpenCursor(const JS::Value & key, PRUint16 direction, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) = 0;

  /* [implicit_jscontext,optional_argc] nsIIDBRequest openKeyCursor ([optional] in jsval key, [optional] in unsigned short direction); */
  NS_SCRIPTABLE NS_IMETHOD OpenKeyCursor(const JS::Value & key, PRUint16 direction, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) = 0;

  /* [implicit_jscontext,optional_argc] nsIIDBRequest count ([optional] in jsval key); */
  NS_SCRIPTABLE NS_IMETHOD Count(const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBIndex, NS_IIDBINDEX_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBINDEX \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetStoreName(nsAString & aStoreName); \
  NS_SCRIPTABLE NS_IMETHOD GetKeyPath(nsAString & aKeyPath); \
  NS_SCRIPTABLE NS_IMETHOD GetUnique(bool *aUnique); \
  NS_SCRIPTABLE NS_IMETHOD GetObjectStore(nsIIDBObjectStore * *aObjectStore); \
  NS_SCRIPTABLE NS_IMETHOD Get(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetKey(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAll(const JS::Value & key, PRUint32 limit, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAllKeys(const JS::Value & key, PRUint32 limit, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OpenCursor(const JS::Value & key, PRUint16 direction, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OpenKeyCursor(const JS::Value & key, PRUint16 direction, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Count(const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBINDEX(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetStoreName(nsAString & aStoreName) { return _to GetStoreName(aStoreName); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyPath(nsAString & aKeyPath) { return _to GetKeyPath(aKeyPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnique(bool *aUnique) { return _to GetUnique(aUnique); } \
  NS_SCRIPTABLE NS_IMETHOD GetObjectStore(nsIIDBObjectStore * *aObjectStore) { return _to GetObjectStore(aObjectStore); } \
  NS_SCRIPTABLE NS_IMETHOD Get(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM) { return _to Get(key, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetKey(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM) { return _to GetKey(key, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAll(const JS::Value & key, PRUint32 limit, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return _to GetAll(key, limit, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllKeys(const JS::Value & key, PRUint32 limit, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return _to GetAllKeys(key, limit, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenCursor(const JS::Value & key, PRUint16 direction, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return _to OpenCursor(key, direction, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenKeyCursor(const JS::Value & key, PRUint16 direction, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return _to OpenKeyCursor(key, direction, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Count(const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return _to Count(key, cx, _argc, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBINDEX(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetStoreName(nsAString & aStoreName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStoreName(aStoreName); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyPath(nsAString & aKeyPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyPath(aKeyPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnique(bool *aUnique) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnique(aUnique); } \
  NS_SCRIPTABLE NS_IMETHOD GetObjectStore(nsIIDBObjectStore * *aObjectStore) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObjectStore(aObjectStore); } \
  NS_SCRIPTABLE NS_IMETHOD Get(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(key, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetKey(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKey(key, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAll(const JS::Value & key, PRUint32 limit, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAll(key, limit, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllKeys(const JS::Value & key, PRUint32 limit, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllKeys(key, limit, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenCursor(const JS::Value & key, PRUint16 direction, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenCursor(key, direction, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OpenKeyCursor(const JS::Value & key, PRUint16 direction, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenKeyCursor(key, direction, cx, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Count(const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Count(key, cx, _argc, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBIndex : public nsIIDBIndex
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBINDEX

  nsIDBIndex();

private:
  ~nsIDBIndex();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBIndex, nsIIDBIndex)

nsIDBIndex::nsIDBIndex()
{
  /* member initializers and constructor code */
}

nsIDBIndex::~nsIDBIndex()
{
  /* destructor code */
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsIDBIndex::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString storeName; */
NS_IMETHODIMP nsIDBIndex::GetStoreName(nsAString & aStoreName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString keyPath; */
NS_IMETHODIMP nsIDBIndex::GetKeyPath(nsAString & aKeyPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean unique; */
NS_IMETHODIMP nsIDBIndex::GetUnique(bool *aUnique)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIIDBObjectStore objectStore; */
NS_IMETHODIMP nsIDBIndex::GetObjectStore(nsIIDBObjectStore * *aObjectStore)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIIDBRequest get (in jsval key); */
NS_IMETHODIMP nsIDBIndex::Get(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIIDBRequest getKey (in jsval key); */
NS_IMETHODIMP nsIDBIndex::GetKey(const JS::Value & key, JSContext* cx, nsIIDBRequest * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIIDBRequest getAll ([optional] in jsval key, [optional] in unsigned long limit); */
NS_IMETHODIMP nsIDBIndex::GetAll(const JS::Value & key, PRUint32 limit, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIIDBRequest getAllKeys ([optional] in jsval key, [optional] in unsigned long limit); */
NS_IMETHODIMP nsIDBIndex::GetAllKeys(const JS::Value & key, PRUint32 limit, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIIDBRequest openCursor ([optional] in jsval key, [optional] in unsigned short direction); */
NS_IMETHODIMP nsIDBIndex::OpenCursor(const JS::Value & key, PRUint16 direction, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIIDBRequest openKeyCursor ([optional] in jsval key, [optional] in unsigned short direction); */
NS_IMETHODIMP nsIDBIndex::OpenKeyCursor(const JS::Value & key, PRUint16 direction, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIIDBRequest count ([optional] in jsval key); */
NS_IMETHODIMP nsIDBIndex::Count(const JS::Value & key, JSContext* cx, PRUint8 _argc, nsIIDBRequest * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBIndex_h__ */
