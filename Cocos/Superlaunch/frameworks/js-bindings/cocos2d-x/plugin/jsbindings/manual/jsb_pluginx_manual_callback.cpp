#include "jsb_pluginx_manual_callback.h"
#include "jsb_pluginx_basic_conversions.h"
#include "jsb_pluginx_spidermonkey_specifics.h"
#include "ProtocolAds.h"
#include "AgentManager.h"

using namespace pluginx;

static JSContext* s_cx = NULL;

class Pluginx_PurchaseResult : public cocos2d::plugin::PayResultListener
{
public:
    virtual void onPayResult(cocos2d::plugin::PayResultCode ret, const char* msg, cocos2d::plugin::TProductInfo info)
    {
        char goodInfo[1024] = { 0 };
        sprintf(goodInfo, "商品名称:%s\n商品价格:%s\n商品描述:%s",
                info.find("productName")->second.c_str(),
                info.find("productPrice")->second.c_str(),
                info.find("productDesc")->second.c_str());
        LOGD(goodInfo);
        
        JSContext* cx = s_cx;
        
        JSObject* obj = _JSDelegate;
        JSAutoCompartment ac(cx, obj);
        
        bool hasAction;
        jsval retval;
        JS::RootedValue temp_retval(cx);
        jsval dataVal[3];
        dataVal[0] = INT_TO_JSVAL(ret);
        std::string strMsgInfo = msg;
        dataVal[1] = std_string_to_jsval(cx, strMsgInfo);
        dataVal[2] = TProductInfo_to_jsval(cx, info);
        
        
        if (JS_HasProperty(cx, obj, "onPayResult", &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, "onPayResult", &temp_retval)) {
                return;
            }
            if(temp_retval == JSVAL_VOID) {
                return;
            }

            JS_CallFunctionName(cx, obj, "onPayResult",
                                3, dataVal, &retval);
        }
    }

    void setJSDelegate(JSObject* pJSDelegate)
    {
        _JSDelegate = pJSDelegate;
    }
    JSObject* getJSDelegate()
    {
        return _JSDelegate;
    }
    
    virtual void onRequestProductsResult(cocos2d::plugin::IAPProductRequest ret, cocos2d::plugin::TProductList info){
        JSContext* cx = s_cx;
        
        JSObject* obj = _JSDelegate;
        JSAutoCompartment ac(cx, obj);
        
        bool hasAction;
        jsval retval;
        JS::RootedValue temp_retval(cx);
        jsval dataVal[2];
        dataVal[0] = INT_TO_JSVAL(ret);
        if(info.size() > 0){
            dataVal[1] = TProductList_to_jsval(cx, info);
        }
        
        if (JS_HasProperty(cx, obj, "onRequestProductResult", &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, "onRequestProductResult", &temp_retval)) {
                return;
            }
            if(temp_retval == JSVAL_VOID) {
                return;
            }
            
            JS_CallFunctionName(cx, obj, "onRequestProductResult",
                                2, dataVal, &retval);
        }

    }
private:
    JSObject* _JSDelegate;
};

bool js_pluginx_ProtocolIAP_setResultListener(JSContext *cx, uint32_t argc, jsval *vp)
{
    s_cx = cx;
    jsval *argv = JS_ARGV(cx, vp);
    JSObject *obj = JS_THIS_OBJECT(cx, vp);
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::plugin::ProtocolIAP* cobj = (cocos2d::plugin::ProtocolIAP *)(proxy ? proxy->ptr : NULL);
    bool ok = true;

    if (argc == 1) {
        // save the delegate
        JSObject *jsDelegate = JSVAL_TO_OBJECT(argv[0]);
        Pluginx_PurchaseResult* nativeDelegate = new Pluginx_PurchaseResult();
        nativeDelegate->setJSDelegate(jsDelegate);
        cobj->setResultListener(nativeDelegate);
        
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return true;
    }

    JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}

bool js_pluginx_ProtocolIAP_getResultListener(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::plugin::ProtocolIAP* cobj = (cocos2d::plugin::ProtocolIAP *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_pluginx_ProtocolIAP_getResultListener : Invalid Native Object");
	if (argc == 0) {
		Pluginx_PurchaseResult* listener = (Pluginx_PurchaseResult*)cobj->getResultListener();
        JSObject *ret = listener->getJSDelegate();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				jsret = OBJECT_TO_JSVAL(ret);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
    
	JS_ReportError(cx, "js_pluginx_ProtocolIAP_getResultListener : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}

class Pluginx_AdsListener : public cocos2d::plugin::AdsListener
{
public:

    virtual void onAdsResult(AdsResultCode code, const char* msg)
    {
        JSContext* cx = s_cx;
        JSObject* obj = _JSDelegate;
        JSAutoCompartment ac(cx, obj);

        bool hasAction;
        jsval retval;
        JS::RootedValue temp_retval(cx);
        jsval dataVal[2];
        dataVal[0] = INT_TO_JSVAL(code);
        std::string strMsgInfo = msg;
        dataVal[1] = std_string_to_jsval(cx, strMsgInfo);
        
        bool bRet = JS_HasProperty(cx, obj, "onAdsResult", &hasAction);
        if (bRet && hasAction) {
            if(!JS_GetProperty(cx, obj, "onAdsResult", &temp_retval)) {
                return;
            }
            if(temp_retval == JSVAL_VOID) {
                return;
            }
            JS_CallFunctionName(cx, obj, "onAdsResult",
                                2, dataVal, &retval);
        }
    }

    virtual void onPlayerGetPoints(ProtocolAds* pAdsPlugin, int points)
    {
        JSContext* cx = s_cx;
        JSObject* obj = _JSDelegate;
        JSAutoCompartment ac(cx, obj);

        bool hasAction;
        jsval retval;
        JS::RootedValue temp_retval(cx);

        js_proxy_t * p;
        JS_GET_PROXY(p, pAdsPlugin);
        
        if (! p) return;
        jsval dataVal[2];
        jsval arg = OBJECT_TO_JSVAL(p->obj);
        dataVal[0] = arg;
        dataVal[1] = INT_TO_JSVAL(points);
        
        bool bRet = JS_HasProperty(cx, obj, "onPlayerGetPoints", &hasAction);
        if (bRet && hasAction) {
            if(!JS_GetProperty(cx, obj, "onPlayerGetPoints", &temp_retval)) {
                return;
            }
            if(temp_retval == JSVAL_VOID) {
                return;
            }
            JS_CallFunctionName(cx, obj, "onPlayerGetPoints",
                                2, NULL, &retval);
        }
    }

    void setJSDelegate(JSObject* pJSDelegate)
    {
        _JSDelegate = pJSDelegate;
    }
    JSObject* getJSDelegate()
    {
        return _JSDelegate;
    }

private:
    JSObject* _JSDelegate;
};

bool js_pluginx_ProtocolAds_setAdsListener(JSContext *cx, uint32_t argc, jsval *vp)
{
    s_cx = cx;
    jsval *argv = JS_ARGV(cx, vp);
    JSObject *obj = JS_THIS_OBJECT(cx, vp);
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::plugin::ProtocolAds* cobj = (cocos2d::plugin::ProtocolAds *)(proxy ? proxy->ptr : NULL);
    bool ok = true;
    if (argc == 1) {
        // save the delegate
        JSObject *jsDelegate = JSVAL_TO_OBJECT(argv[0]);
        Pluginx_AdsListener* nativeDelegate = new Pluginx_AdsListener();
        nativeDelegate->setJSDelegate(jsDelegate);
        cobj->setAdsListener(nativeDelegate);
        
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return true;
    }

    JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}

bool js_pluginx_ProtocolAds_getAdsListener(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::plugin::ProtocolAds* cobj = (cocos2d::plugin::ProtocolAds *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_pluginx_ProtocolAds_getAdsListener : Invalid Native Object");
	if (argc == 0) {
		Pluginx_AdsListener* listener = (Pluginx_AdsListener*)cobj->getAdsListener();
        JSObject *ret = listener->getJSDelegate();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				jsret = OBJECT_TO_JSVAL(ret);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
    
	JS_ReportError(cx, "js_pluginx_ProtocolAds_getAdsListener : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}

class Pluginx_ShareResult : public cocos2d::plugin::ShareResultListener
{
public:
    virtual void onShareResult(cocos2d::plugin::ShareResultCode ret, const char* msg)
    {
        JSContext* cx = s_cx;
        JSObject* obj = _JSDelegate;
        JSAutoCompartment ac(cx, obj);

        bool hasAction;
        jsval retval;
        JS::RootedValue temp_retval(cx);
        jsval dataVal[2];
        dataVal[0] = INT_TO_JSVAL(ret);
        std::string strMsgInfo = msg;
        dataVal[1] = std_string_to_jsval(cx, strMsgInfo);
        
        if (JS_HasProperty(cx, obj, "onShareResult", &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, "onShareResult", &temp_retval)) {
                return;
            }
            if(temp_retval == JSVAL_VOID) {
                return;
            }
            JS_CallFunctionName(cx, obj, "onShareResult",
                                2, dataVal, &retval);
        }
    }

    void setJSDelegate(JSObject* pJSDelegate)
    {
        _JSDelegate = pJSDelegate;
    }
    
    JSObject* getJSDelegate()
    {
        return _JSDelegate;
    }

private:
    JSObject* _JSDelegate;
};

bool js_pluginx_ProtocolShare_setResultListener(JSContext *cx, uint32_t argc, jsval *vp)
{
    s_cx = cx;
    jsval *argv = JS_ARGV(cx, vp);
    JSObject *obj = JS_THIS_OBJECT(cx, vp);
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::plugin::ProtocolShare* cobj = (cocos2d::plugin::ProtocolShare *)(proxy ? proxy->ptr : NULL);
    bool ok = true;

    if (argc == 1) {
        // save the delegate
        JSObject *jsDelegate = JSVAL_TO_OBJECT(argv[0]);
        Pluginx_ShareResult* nativeDelegate = new Pluginx_ShareResult();
        nativeDelegate->setJSDelegate(jsDelegate);
        cobj->setResultListener(nativeDelegate);
        
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return true;
    }

    JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}

bool js_pluginx_ProtocolShare_getResultListener(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::plugin::ProtocolShare* cobj = (cocos2d::plugin::ProtocolShare *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_pluginx_ProtocolShare_getResultListener : Invalid Native Object");
	if (argc == 0) {
		Pluginx_ShareResult* listener = (Pluginx_ShareResult*)cobj->getResultListener();
        JSObject *ret = listener->getJSDelegate();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				jsret = OBJECT_TO_JSVAL(ret);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
    
	JS_ReportError(cx, "js_pluginx_ProtocolShare_getResultListener : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}

class Pluginx_SocialResult : public cocos2d::plugin::SocialListener
{
public:
    virtual void onSocialResult(cocos2d::plugin::SocialRetCode ret, const char* msg)
    {
        JSContext* cx = s_cx;
        JSObject* obj = _JSDelegate;
        JSAutoCompartment ac(cx, obj);

        bool hasAction;
        jsval retval;
        JS::RootedValue temp_retval(cx);
        jsval dataVal[2];
        dataVal[0] = INT_TO_JSVAL(ret);
        std::string strMsgInfo = msg;
        dataVal[1] = std_string_to_jsval(cx, strMsgInfo);
        
        if (JS_HasProperty(cx, obj, "onSocialResult", &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, "onSocialResult", &temp_retval)) {
                return;
            }
            if(temp_retval == JSVAL_VOID) {
                return;
            }
            JS_CallFunctionName(cx, obj, "onSocialResult",
                                2, dataVal, &retval);
        }
    }

    void setJSDelegate(JSObject* pJSDelegate)
    {
        _JSDelegate = pJSDelegate;
    }
    
    JSObject* getJSDelegate()
    {
        return _JSDelegate;
    }

private:
    JSObject* _JSDelegate;
};

bool js_pluginx_ProtocolSocial_setListener(JSContext *cx, uint32_t argc, jsval *vp)
{
    s_cx = cx;
    jsval *argv = JS_ARGV(cx, vp);
    JSObject *obj = JS_THIS_OBJECT(cx, vp);
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::plugin::ProtocolSocial* cobj = (cocos2d::plugin::ProtocolSocial *)(proxy ? proxy->ptr : NULL);
    bool ok = true;

    if (argc == 1) {
        // save the delegate
        JSObject *jsDelegate = JSVAL_TO_OBJECT(argv[0]);
        Pluginx_SocialResult* nativeDelegate = new Pluginx_SocialResult();
        nativeDelegate->setJSDelegate(jsDelegate);
        cobj->setListener(nativeDelegate);
        
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return true;
    }

    JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}

bool js_pluginx_ProtocolSocial_getListener(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::plugin::ProtocolSocial* cobj = (cocos2d::plugin::ProtocolSocial *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_pluginx_ProtocolSocial_getListener : Invalid Native Object");
	if (argc == 0) {
		Pluginx_SocialResult* listener = (Pluginx_SocialResult*)cobj->getListener();
        JSObject *ret = listener->getJSDelegate();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				jsret = OBJECT_TO_JSVAL(ret);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
    
	JS_ReportError(cx, "js_pluginx_ProtocolSocial_getListener : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}

class Pluginx_UserActionListener : public cocos2d::plugin::UserActionListener
{
public:
    virtual void onActionResult(ProtocolUser* userPlugin, cocos2d::plugin::UserActionResultCode ret, const char* msg)
    {
        JSContext* cx = s_cx;
        JSObject* obj = _JSDelegate;
        JSAutoCompartment ac(cx, obj);

        bool hasAction;
        jsval retval;
        JS::RootedValue temp_retval(cx);

        js_proxy_t * p;
        JS_GET_PROXY(p, userPlugin);
        
        if (! p) return;
        jsval dataVal[3];
        jsval arg1 = OBJECT_TO_JSVAL(p->obj);
        dataVal[0] = arg1;
        dataVal[1] = INT_TO_JSVAL(ret);
        std::string strMsgInfo = msg;
        dataVal[2] = std_string_to_jsval(cx, strMsgInfo);
        
        if (JS_HasProperty(cx, obj, "onActionResult", &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, "onActionResult", &temp_retval)) {
                return;
            }
            if(temp_retval == JSVAL_VOID) {
                return;
            }
            JS_CallFunctionName(cx, obj, "onActionResult",
                                3, dataVal, &retval);
        }
    }

    void setJSDelegate(JSObject* pJSDelegate)
    {
        _JSDelegate = pJSDelegate;
    }
    
    JSObject* getJSDelegate()
    {
        return _JSDelegate;
    }

private:
    JSObject* _JSDelegate;
};

bool js_pluginx_ProtocolUser_setActionListener(JSContext *cx, uint32_t argc, jsval *vp)
{
    s_cx = cx;
    jsval *argv = JS_ARGV(cx, vp);
    JSObject *obj = JS_THIS_OBJECT(cx, vp);
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cocos2d::plugin::ProtocolUser* cobj = (cocos2d::plugin::ProtocolUser *)(proxy ? proxy->ptr : NULL);
    bool ok = true;

    if (argc == 1) {
        // save the delegate
        JSObject *jsDelegate = JSVAL_TO_OBJECT(argv[0]);
        Pluginx_UserActionListener* nativeDelegate = new Pluginx_UserActionListener();
        nativeDelegate->setJSDelegate(jsDelegate);
        cobj->setActionListener(nativeDelegate);
        
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return true;
    }

    JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}

bool js_pluginx_ProtocolUser_getActionListener(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::plugin::ProtocolUser* cobj = (cocos2d::plugin::ProtocolUser *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_pluginx_ProtocolUser_getActionListener : Invalid Native Object");
	if (argc == 0) {
		Pluginx_UserActionListener* listener = (Pluginx_UserActionListener*)cobj->getActionListener();
        JSObject *ret = listener->getJSDelegate();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				jsret = OBJECT_TO_JSVAL(ret);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
    
	JS_ReportError(cx, "js_pluginx_ProtocolUser_getActionListener : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}


bool js_pluginx_protocols_AgentManager_login(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    
	JSObject *obj = NULL;
	cocos2d::plugin::AgentManager* cobj = NULL;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cobj = (cocos2d::plugin::AgentManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_pluginx_protocols_AgentManager_login : Invalid Native Object");
	do {
		if (argc == 1) {
			std::function<void (int, std::string&)> arg0;
			do {
				std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, JS_THIS_OBJECT(cx, vp), argv[0]));
				auto lambda = [=](int larg0, std::string& larg1) -> void {
                    JSAutoCompartment ac(cx, obj);
					jsval largv[2];
					largv[0] = int32_to_jsval(cx, larg0);
                    largv[1] = std_string_to_jsval(cx, larg1);
					jsval rval;
					bool succeed = func->invoke(2, &largv[0], rval);
					if (!succeed && JS_IsExceptionPending(cx)) {
						JS_ReportPendingException(cx);
					}
				};
				arg0 = lambda;
			} while(0)
                ;
			if (!ok) { ok = true; break; }
			cobj->login(arg0);
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return true;
		}
	} while(0);
    
	do {
		if (argc == 0) {
			cobj->login();
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return true;
		}
	} while(0);
    
	JS_ReportError(cx, "js_pluginx_protocols_AgentManager_login : wrong number of arguments");
	return false;
}

bool js_pluginx_protocols_AgentManager_share(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    
	JSObject *obj = NULL;
	cocos2d::plugin::AgentManager* cobj = NULL;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cobj = (cocos2d::plugin::AgentManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_pluginx_protocols_AgentManager_share : Invalid Native Object");
	do {
		if (argc == 2) {
			cocos2d::plugin::TShareInfo arg0;
			ok &= pluginx::jsval_to_TShareInfo(cx, argv[0], &arg0);
			if (!ok) { ok = true; break; }
			std::function<void (int, std::basic_string<char> &)> arg1;
			do {
				std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, JS_THIS_OBJECT(cx, vp), argv[1]));
				auto lambda = [=](int larg0, std::string& larg1) -> void {
                    JSAutoCompartment ac(cx, obj);
					jsval largv[2];
					largv[0] = int32_to_jsval(cx, larg0);
                    largv[1] = std_string_to_jsval(cx, larg1);
					jsval rval;
					bool succeed = func->invoke(2, &largv[0], rval);
					if (!succeed && JS_IsExceptionPending(cx)) {
						JS_ReportPendingException(cx);
					}
				};
				arg1 = lambda;
			} while(0)
                ;
			if (!ok) { ok = true; break; }
			cobj->share(arg0, arg1);
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return true;
		}
	} while(0);
    
	do {
		if (argc == 1) {
			cocos2d::plugin::TShareInfo arg0;
			ok &= pluginx::jsval_to_TShareInfo(cx, argv[0], &arg0);
			if (!ok) { ok = true; break; }
			cobj->share(arg0);
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return true;
		}
	} while(0);
    
	JS_ReportError(cx, "js_pluginx_protocols_AgentManager_share : wrong number of arguments");
	return false;
}
