/****************************************************************************
Copyright (c) 2012-2013 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#ifndef  __CCX_PROTOCOL_SHARE_H__
#define  __CCX_PROTOCOL_SHARE_H__

#include "PluginProtocol.h"
#include <map>
#include <string>
#include <functional>

namespace cocos2d { namespace plugin {

typedef std::map<std::string, std::string> TShareDeveloperInfo;
typedef std::map<std::string, std::string> TShareInfo;

typedef enum 
{
    kShareSuccess = 0,
    kShareFail,
    kShareCancel,
    kShareTimeOut,
} ShareResultCode;

class ShareResultListener
{
public:
    virtual void onShareResult(ShareResultCode ret, const char* msg) = 0;
};

class ProtocolShare : public PluginProtocol
{
public:
	ProtocolShare();
	virtual ~ProtocolShare();
    
    typedef std::function<void(int, std::string&)> ProtocolShareCallback;

    /**
    @brief config the share developer info
    @param devInfo This parameter is the info of developer,
           different plugin have different format
    @warning Must invoke this interface before other interfaces.
             And invoked only once.
    */
    void configDeveloperInfo(TShareDeveloperInfo devInfo);

    /**
    @brief share information
    @param info The info of share, contains key:
            SharedText                	The text need to share
            SharedImagePath				The full path of image file need to share (optinal)
    @warning For different plugin, the parameter should have other keys to share.
             Look at the manual of plugins.
    */
    void share(TShareInfo info);

    /**
    @breif set the result listener
    @param pListener The callback object for share result
    @wraning Must invoke this interface before share
    */
    void setResultListener(ShareResultListener* pListener);
    
    /**
     @breif get the result listener
     @return The callback object for share result
     @wraning Must invoke this interface before share
     */
    ShareResultListener* getResultListener();
    
    /**
     @brief set login callback function
     */
    inline void setListener(const ProtocolShareCallback &cb)
    {
        _callback = cb;
    }
    
    /**
     @brief get login callback function
     */
    inline ProtocolShareCallback& getListener()
    {
        return _callback;
    }

    /**
    @brief share result callback
    */
    void onShareResult(ShareResultCode ret, const char* msg);

protected:
    ShareResultListener* _listener;
    ProtocolShareCallback _callback;
};

}} // namespace cocos2d { namespace plugin {

#endif   /* ----- #ifndef __CCX_PROTOCOL_SHARE_H__ ----- */
