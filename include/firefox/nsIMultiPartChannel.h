/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/netwerk/base/public/nsIMultiPartChannel.idl
 */

#ifndef __gen_nsIMultiPartChannel_h__
#define __gen_nsIMultiPartChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */


/* starting interface:    nsIMultiPartChannel */
#define NS_IMULTIPARTCHANNEL_IID_STR "4b04e835-d131-42af-8bf0-74289f99374f"

#define NS_IMULTIPARTCHANNEL_IID \
  {0x4b04e835, 0xd131, 0x42af, \
    { 0x8b, 0xf0, 0x74, 0x28, 0x9f, 0x99, 0x37, 0x4f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIMultiPartChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMULTIPARTCHANNEL_IID)

  /* readonly attribute nsIChannel baseChannel; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseChannel(nsIChannel * *aBaseChannel) = 0;

  /* readonly attribute PRUint32 partID; */
  NS_SCRIPTABLE NS_IMETHOD GetPartID(PRUint32 *aPartID) = 0;

  /* readonly attribute boolean isLastPart; */
  NS_SCRIPTABLE NS_IMETHOD GetIsLastPart(bool *aIsLastPart) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMultiPartChannel, NS_IMULTIPARTCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMULTIPARTCHANNEL \
  NS_SCRIPTABLE NS_IMETHOD GetBaseChannel(nsIChannel * *aBaseChannel); \
  NS_SCRIPTABLE NS_IMETHOD GetPartID(PRUint32 *aPartID); \
  NS_SCRIPTABLE NS_IMETHOD GetIsLastPart(bool *aIsLastPart); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMULTIPARTCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseChannel(nsIChannel * *aBaseChannel) { return _to GetBaseChannel(aBaseChannel); } \
  NS_SCRIPTABLE NS_IMETHOD GetPartID(PRUint32 *aPartID) { return _to GetPartID(aPartID); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsLastPart(bool *aIsLastPart) { return _to GetIsLastPart(aIsLastPart); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMULTIPARTCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseChannel(nsIChannel * *aBaseChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseChannel(aBaseChannel); } \
  NS_SCRIPTABLE NS_IMETHOD GetPartID(PRUint32 *aPartID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPartID(aPartID); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsLastPart(bool *aIsLastPart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsLastPart(aIsLastPart); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMultiPartChannel : public nsIMultiPartChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMULTIPARTCHANNEL

  nsMultiPartChannel();

private:
  ~nsMultiPartChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMultiPartChannel, nsIMultiPartChannel)

nsMultiPartChannel::nsMultiPartChannel()
{
  /* member initializers and constructor code */
}

nsMultiPartChannel::~nsMultiPartChannel()
{
  /* destructor code */
}

/* readonly attribute nsIChannel baseChannel; */
NS_IMETHODIMP nsMultiPartChannel::GetBaseChannel(nsIChannel * *aBaseChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 partID; */
NS_IMETHODIMP nsMultiPartChannel::GetPartID(PRUint32 *aPartID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isLastPart; */
NS_IMETHODIMP nsMultiPartChannel::GetIsLastPart(bool *aIsLastPart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMultiPartChannel_h__ */
