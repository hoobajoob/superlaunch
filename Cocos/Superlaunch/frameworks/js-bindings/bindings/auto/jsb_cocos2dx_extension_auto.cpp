#include "jsb_cocos2dx_extension_auto.hpp"
#include "cocos2d_specifics.hpp"
#include "cocos-ext.h"

template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    JSObject* global = ScriptingCore::getInstance()->getGlobalObject();
	isNewValid = JS_GetProperty(cx, global, "initializing", &initializing) && JSVAL_TO_BOOLEAN(initializing);
	if (isNewValid)
	{
		TypeTest<T> t;
		js_type_class_t *typeClass = nullptr;
		std::string typeName = t.s_name();
		auto typeMapIter = _js_global_type_map.find(typeName);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");

		JSObject *_tmp = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));
		return true;
	}

    JS_ReportError(cx, "Don't use `new cc.XXX`, please use `cc.XXX.create` instead! ");
    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	return false;
}

static bool js_is_native_obj(JSContext *cx, JS::HandleObject obj, JS::HandleId id, JS::MutableHandleValue vp)
{
	vp.set(BOOLEAN_TO_JSVAL(true));
	return true;	
}
JSClass  *jsb_cocos2d_extension_Scale9Sprite_class;
JSObject *jsb_cocos2d_extension_Scale9Sprite_prototype;

bool js_cocos2dx_extension_Scale9Sprite_resizableSpriteWithCapInsets(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Scale9Sprite* cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_resizableSpriteWithCapInsets : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Rect arg0;
		ok &= jsval_to_ccrect(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_Scale9Sprite_resizableSpriteWithCapInsets : Error processing arguments");
		cocos2d::extension::Scale9Sprite* ret = cobj->resizableSpriteWithCapInsets(arg0);
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::Scale9Sprite>(cx, (cocos2d::extension::Scale9Sprite*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_resizableSpriteWithCapInsets : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_setInsetBottom(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Scale9Sprite* cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_setInsetBottom : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_Scale9Sprite_setInsetBottom : Error processing arguments");
		cobj->setInsetBottom(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_setInsetBottom : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_initWithSpriteFrameName(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;

	JSObject *obj = NULL;
	cocos2d::extension::Scale9Sprite* cobj = NULL;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_initWithSpriteFrameName : Invalid Native Object");
	do {
		if (argc == 1) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = true; break; }
			bool ret = cobj->initWithSpriteFrameName(arg0);
			jsval jsret = JSVAL_NULL;
			jsret = BOOLEAN_TO_JSVAL(ret);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while(0);

	do {
		if (argc == 2) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = true; break; }
			cocos2d::Rect arg1;
			ok &= jsval_to_ccrect(cx, argv[1], &arg1);
			if (!ok) { ok = true; break; }
			bool ret = cobj->initWithSpriteFrameName(arg0, arg1);
			jsval jsret = JSVAL_NULL;
			jsret = BOOLEAN_TO_JSVAL(ret);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while(0);

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_initWithSpriteFrameName : wrong number of arguments");
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_setInsetTop(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Scale9Sprite* cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_setInsetTop : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_Scale9Sprite_setInsetTop : Error processing arguments");
		cobj->setInsetTop(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_setInsetTop : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_init(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Scale9Sprite* cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_init : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->init();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_init : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_setPreferredSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Scale9Sprite* cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_setPreferredSize : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Size arg0;
		ok &= jsval_to_ccsize(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_Scale9Sprite_setPreferredSize : Error processing arguments");
		cobj->setPreferredSize(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_setPreferredSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_setSpriteFrame(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Scale9Sprite* cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_setSpriteFrame : Invalid Native Object");
	if (argc == 1) {
		cocos2d::SpriteFrame* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::SpriteFrame*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_Scale9Sprite_setSpriteFrame : Error processing arguments");
		cobj->setSpriteFrame(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_setSpriteFrame : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_initWithBatchNode(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;

	JSObject *obj = NULL;
	cocos2d::extension::Scale9Sprite* cobj = NULL;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_initWithBatchNode : Invalid Native Object");
	do {
		if (argc == 3) {
			cocos2d::SpriteBatchNode* arg0;
			do {
				if (!argv[0].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg0 = (cocos2d::SpriteBatchNode*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Rect arg1;
			ok &= jsval_to_ccrect(cx, argv[1], &arg1);
			if (!ok) { ok = true; break; }
			cocos2d::Rect arg2;
			ok &= jsval_to_ccrect(cx, argv[2], &arg2);
			if (!ok) { ok = true; break; }
			bool ret = cobj->initWithBatchNode(arg0, arg1, arg2);
			jsval jsret = JSVAL_NULL;
			jsret = BOOLEAN_TO_JSVAL(ret);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while(0);

	do {
		if (argc == 4) {
			cocos2d::SpriteBatchNode* arg0;
			do {
				if (!argv[0].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg0 = (cocos2d::SpriteBatchNode*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Rect arg1;
			ok &= jsval_to_ccrect(cx, argv[1], &arg1);
			if (!ok) { ok = true; break; }
			bool arg2;
			arg2 = JS::ToBoolean(JS::RootedValue(cx, argv[2]));
			cocos2d::Rect arg3;
			ok &= jsval_to_ccrect(cx, argv[3], &arg3);
			if (!ok) { ok = true; break; }
			bool ret = cobj->initWithBatchNode(arg0, arg1, arg2, arg3);
			jsval jsret = JSVAL_NULL;
			jsret = BOOLEAN_TO_JSVAL(ret);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while(0);

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_initWithBatchNode : wrong number of arguments");
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_getInsetBottom(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Scale9Sprite* cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_getInsetBottom : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getInsetBottom();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_getInsetBottom : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_getCapInsets(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Scale9Sprite* cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_getCapInsets : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Rect ret = cobj->getCapInsets();
		jsval jsret = JSVAL_NULL;
		jsret = ccrect_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_getCapInsets : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_updateWithBatchNode(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Scale9Sprite* cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_updateWithBatchNode : Invalid Native Object");
	if (argc == 4) {
		cocos2d::SpriteBatchNode* arg0;
		cocos2d::Rect arg1;
		bool arg2;
		cocos2d::Rect arg3;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::SpriteBatchNode*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_ccrect(cx, argv[1], &arg1);
		arg2 = JS::ToBoolean(JS::RootedValue(cx, argv[2]));
		ok &= jsval_to_ccrect(cx, argv[3], &arg3);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_Scale9Sprite_updateWithBatchNode : Error processing arguments");
		bool ret = cobj->updateWithBatchNode(arg0, arg1, arg2, arg3);
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_updateWithBatchNode : wrong number of arguments: %d, was expecting %d", argc, 4);
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_getInsetRight(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Scale9Sprite* cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_getInsetRight : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getInsetRight();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_getInsetRight : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_getOriginalSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Scale9Sprite* cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_getOriginalSize : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Size ret = cobj->getOriginalSize();
		jsval jsret = JSVAL_NULL;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_getOriginalSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_initWithFile(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;

	JSObject *obj = NULL;
	cocos2d::extension::Scale9Sprite* cobj = NULL;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_initWithFile : Invalid Native Object");
	do {
		if (argc == 2) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = true; break; }
			cocos2d::Rect arg1;
			ok &= jsval_to_ccrect(cx, argv[1], &arg1);
			if (!ok) { ok = true; break; }
			bool ret = cobj->initWithFile(arg0, arg1);
			jsval jsret = JSVAL_NULL;
			jsret = BOOLEAN_TO_JSVAL(ret);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while(0);

	do {
		if (argc == 3) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = true; break; }
			cocos2d::Rect arg1;
			ok &= jsval_to_ccrect(cx, argv[1], &arg1);
			if (!ok) { ok = true; break; }
			cocos2d::Rect arg2;
			ok &= jsval_to_ccrect(cx, argv[2], &arg2);
			if (!ok) { ok = true; break; }
			bool ret = cobj->initWithFile(arg0, arg1, arg2);
			jsval jsret = JSVAL_NULL;
			jsret = BOOLEAN_TO_JSVAL(ret);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while(0);

	do {
		if (argc == 2) {
			cocos2d::Rect arg0;
			ok &= jsval_to_ccrect(cx, argv[0], &arg0);
			if (!ok) { ok = true; break; }
			std::string arg1;
			ok &= jsval_to_std_string(cx, argv[1], &arg1);
			if (!ok) { ok = true; break; }
			bool ret = cobj->initWithFile(arg0, arg1);
			jsval jsret = JSVAL_NULL;
			jsret = BOOLEAN_TO_JSVAL(ret);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while(0);

	do {
		if (argc == 1) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = true; break; }
			bool ret = cobj->initWithFile(arg0);
			jsval jsret = JSVAL_NULL;
			jsret = BOOLEAN_TO_JSVAL(ret);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while(0);

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_initWithFile : wrong number of arguments");
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_getInsetTop(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Scale9Sprite* cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_getInsetTop : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getInsetTop();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_getInsetTop : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_setInsetLeft(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Scale9Sprite* cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_setInsetLeft : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_Scale9Sprite_setInsetLeft : Error processing arguments");
		cobj->setInsetLeft(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_setInsetLeft : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_initWithSpriteFrame(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;

	JSObject *obj = NULL;
	cocos2d::extension::Scale9Sprite* cobj = NULL;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_initWithSpriteFrame : Invalid Native Object");
	do {
		if (argc == 1) {
			cocos2d::SpriteFrame* arg0;
			do {
				if (!argv[0].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg0 = (cocos2d::SpriteFrame*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			bool ret = cobj->initWithSpriteFrame(arg0);
			jsval jsret = JSVAL_NULL;
			jsret = BOOLEAN_TO_JSVAL(ret);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while(0);

	do {
		if (argc == 2) {
			cocos2d::SpriteFrame* arg0;
			do {
				if (!argv[0].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg0 = (cocos2d::SpriteFrame*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Rect arg1;
			ok &= jsval_to_ccrect(cx, argv[1], &arg1);
			if (!ok) { ok = true; break; }
			bool ret = cobj->initWithSpriteFrame(arg0, arg1);
			jsval jsret = JSVAL_NULL;
			jsret = BOOLEAN_TO_JSVAL(ret);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while(0);

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_initWithSpriteFrame : wrong number of arguments");
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_getPreferredSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Scale9Sprite* cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_getPreferredSize : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Size ret = cobj->getPreferredSize();
		jsval jsret = JSVAL_NULL;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_getPreferredSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_setCapInsets(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Scale9Sprite* cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_setCapInsets : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Rect arg0;
		ok &= jsval_to_ccrect(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_Scale9Sprite_setCapInsets : Error processing arguments");
		cobj->setCapInsets(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_setCapInsets : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_getInsetLeft(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Scale9Sprite* cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_getInsetLeft : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getInsetLeft();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_getInsetLeft : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_setInsetRight(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Scale9Sprite* cobj = (cocos2d::extension::Scale9Sprite *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Scale9Sprite_setInsetRight : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_Scale9Sprite_setInsetRight : Error processing arguments");
		cobj->setInsetRight(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_setInsetRight : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	
	do {
		if (argc == 3) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = true; break; }
			cocos2d::Rect arg1;
			ok &= jsval_to_ccrect(cx, argv[1], &arg1);
			if (!ok) { ok = true; break; }
			cocos2d::Rect arg2;
			ok &= jsval_to_ccrect(cx, argv[2], &arg2);
			if (!ok) { ok = true; break; }
			cocos2d::extension::Scale9Sprite* ret = cocos2d::extension::Scale9Sprite::create(arg0, arg1, arg2);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::Scale9Sprite>(cx, (cocos2d::extension::Scale9Sprite*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	
	do {
		if (argc == 0) {
			cocos2d::extension::Scale9Sprite* ret = cocos2d::extension::Scale9Sprite::create();
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::Scale9Sprite>(cx, (cocos2d::extension::Scale9Sprite*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	
	do {
		if (argc == 2) {
			cocos2d::Rect arg0;
			ok &= jsval_to_ccrect(cx, argv[0], &arg0);
			if (!ok) { ok = true; break; }
			std::string arg1;
			ok &= jsval_to_std_string(cx, argv[1], &arg1);
			if (!ok) { ok = true; break; }
			cocos2d::extension::Scale9Sprite* ret = cocos2d::extension::Scale9Sprite::create(arg0, arg1);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::Scale9Sprite>(cx, (cocos2d::extension::Scale9Sprite*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	
	do {
		if (argc == 2) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = true; break; }
			cocos2d::Rect arg1;
			ok &= jsval_to_ccrect(cx, argv[1], &arg1);
			if (!ok) { ok = true; break; }
			cocos2d::extension::Scale9Sprite* ret = cocos2d::extension::Scale9Sprite::create(arg0, arg1);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::Scale9Sprite>(cx, (cocos2d::extension::Scale9Sprite*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	
	do {
		if (argc == 1) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = true; break; }
			cocos2d::extension::Scale9Sprite* ret = cocos2d::extension::Scale9Sprite::create(arg0);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::Scale9Sprite>(cx, (cocos2d::extension::Scale9Sprite*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_create : wrong number of arguments");
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_createWithSpriteFrameName(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	
	do {
		if (argc == 2) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = true; break; }
			cocos2d::Rect arg1;
			ok &= jsval_to_ccrect(cx, argv[1], &arg1);
			if (!ok) { ok = true; break; }
			cocos2d::extension::Scale9Sprite* ret = cocos2d::extension::Scale9Sprite::createWithSpriteFrameName(arg0, arg1);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::Scale9Sprite>(cx, (cocos2d::extension::Scale9Sprite*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	
	do {
		if (argc == 1) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = true; break; }
			cocos2d::extension::Scale9Sprite* ret = cocos2d::extension::Scale9Sprite::createWithSpriteFrameName(arg0);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::Scale9Sprite>(cx, (cocos2d::extension::Scale9Sprite*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_createWithSpriteFrameName : wrong number of arguments");
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_createWithSpriteFrame(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	
	do {
		if (argc == 2) {
			cocos2d::SpriteFrame* arg0;
			do {
				if (!argv[0].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg0 = (cocos2d::SpriteFrame*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Rect arg1;
			ok &= jsval_to_ccrect(cx, argv[1], &arg1);
			if (!ok) { ok = true; break; }
			cocos2d::extension::Scale9Sprite* ret = cocos2d::extension::Scale9Sprite::createWithSpriteFrame(arg0, arg1);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::Scale9Sprite>(cx, (cocos2d::extension::Scale9Sprite*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	
	do {
		if (argc == 1) {
			cocos2d::SpriteFrame* arg0;
			do {
				if (!argv[0].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg0 = (cocos2d::SpriteFrame*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::extension::Scale9Sprite* ret = cocos2d::extension::Scale9Sprite::createWithSpriteFrame(arg0);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::Scale9Sprite>(cx, (cocos2d::extension::Scale9Sprite*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	JS_ReportError(cx, "js_cocos2dx_extension_Scale9Sprite_createWithSpriteFrame : wrong number of arguments");
	return false;
}
bool js_cocos2dx_extension_Scale9Sprite_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    cocos2d::extension::Scale9Sprite* cobj = new cocos2d::extension::Scale9Sprite();
    cocos2d::Ref *_ccobj = dynamic_cast<cocos2d::Ref *>(cobj);
    if (_ccobj) {
        _ccobj->autorelease();
    }
    TypeTest<cocos2d::extension::Scale9Sprite> t;
    js_type_class_t *typeClass = nullptr;
    std::string typeName = t.s_name();
    auto typeMapIter = _js_global_type_map.find(typeName);
    CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
    typeClass = typeMapIter->second;
    CCASSERT(typeClass, "The value is null.");
    JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
    // link the native object with the javascript object
    js_proxy_t* p = jsb_new_proxy(cobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::Scale9Sprite");
    if (JS_HasProperty(cx, obj, "_ctor", &ok))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    return true;
}


extern JSObject *jsb_cocos2d_Node_prototype;

void js_cocos2d_extension_Scale9Sprite_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (Scale9Sprite)", obj);
}

void js_register_cocos2dx_extension_Scale9Sprite(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_Scale9Sprite_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_Scale9Sprite_class->name = "Scale9Sprite";
	jsb_cocos2d_extension_Scale9Sprite_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_Scale9Sprite_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_Scale9Sprite_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_Scale9Sprite_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_Scale9Sprite_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_Scale9Sprite_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_Scale9Sprite_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_Scale9Sprite_class->finalize = js_cocos2d_extension_Scale9Sprite_finalize;
	jsb_cocos2d_extension_Scale9Sprite_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("resizableSpriteWithCapInsets", js_cocos2dx_extension_Scale9Sprite_resizableSpriteWithCapInsets, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setInsetBottom", js_cocos2dx_extension_Scale9Sprite_setInsetBottom, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initWithSpriteFrameName", js_cocos2dx_extension_Scale9Sprite_initWithSpriteFrameName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setInsetTop", js_cocos2dx_extension_Scale9Sprite_setInsetTop, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("init", js_cocos2dx_extension_Scale9Sprite_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPreferredSize", js_cocos2dx_extension_Scale9Sprite_setPreferredSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setSpriteFrame", js_cocos2dx_extension_Scale9Sprite_setSpriteFrame, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initWithBatchNode", js_cocos2dx_extension_Scale9Sprite_initWithBatchNode, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getInsetBottom", js_cocos2dx_extension_Scale9Sprite_getInsetBottom, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getCapInsets", js_cocos2dx_extension_Scale9Sprite_getCapInsets, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("updateWithBatchNode", js_cocos2dx_extension_Scale9Sprite_updateWithBatchNode, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getInsetRight", js_cocos2dx_extension_Scale9Sprite_getInsetRight, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getOriginalSize", js_cocos2dx_extension_Scale9Sprite_getOriginalSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initWithFile", js_cocos2dx_extension_Scale9Sprite_initWithFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getInsetTop", js_cocos2dx_extension_Scale9Sprite_getInsetTop, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setInsetLeft", js_cocos2dx_extension_Scale9Sprite_setInsetLeft, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initWithSpriteFrame", js_cocos2dx_extension_Scale9Sprite_initWithSpriteFrame, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPreferredSize", js_cocos2dx_extension_Scale9Sprite_getPreferredSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setCapInsets", js_cocos2dx_extension_Scale9Sprite_setCapInsets, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getInsetLeft", js_cocos2dx_extension_Scale9Sprite_getInsetLeft, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setInsetRight", js_cocos2dx_extension_Scale9Sprite_setInsetRight, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_extension_Scale9Sprite_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("createWithSpriteFrameName", js_cocos2dx_extension_Scale9Sprite_createWithSpriteFrameName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("createWithSpriteFrame", js_cocos2dx_extension_Scale9Sprite_createWithSpriteFrame, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_cocos2d_extension_Scale9Sprite_prototype = JS_InitClass(
		cx, global,
		jsb_cocos2d_Node_prototype,
		jsb_cocos2d_extension_Scale9Sprite_class,
		js_cocos2dx_extension_Scale9Sprite_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "Scale9Sprite", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::Scale9Sprite> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_Scale9Sprite_class;
		p->proto = jsb_cocos2d_extension_Scale9Sprite_prototype;
		p->parentProto = jsb_cocos2d_Node_prototype;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

JSClass  *jsb_cocos2d_extension_Control_class;
JSObject *jsb_cocos2d_extension_Control_prototype;

bool js_cocos2dx_extension_Control_setEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Control* cobj = (cocos2d::extension::Control *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Control_setEnabled : Invalid Native Object");
	if (argc == 1) {
		bool arg0;
		arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_Control_setEnabled : Error processing arguments");
		cobj->setEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Control_setEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_Control_getState(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Control* cobj = (cocos2d::extension::Control *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Control_getState : Invalid Native Object");
	if (argc == 0) {
		int ret = (int)cobj->getState();
		jsval jsret = JSVAL_NULL;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Control_getState : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Control_sendActionsForControlEvents(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Control* cobj = (cocos2d::extension::Control *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Control_sendActionsForControlEvents : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::Control::EventType arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_Control_sendActionsForControlEvents : Error processing arguments");
		cobj->sendActionsForControlEvents(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Control_sendActionsForControlEvents : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_Control_setSelected(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Control* cobj = (cocos2d::extension::Control *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Control_setSelected : Invalid Native Object");
	if (argc == 1) {
		bool arg0;
		arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_Control_setSelected : Error processing arguments");
		cobj->setSelected(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Control_setSelected : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_Control_isEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Control* cobj = (cocos2d::extension::Control *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Control_isEnabled : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isEnabled();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Control_isEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Control_needsLayout(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Control* cobj = (cocos2d::extension::Control *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Control_needsLayout : Invalid Native Object");
	if (argc == 0) {
		cobj->needsLayout();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Control_needsLayout : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Control_hasVisibleParents(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Control* cobj = (cocos2d::extension::Control *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Control_hasVisibleParents : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->hasVisibleParents();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Control_hasVisibleParents : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Control_isSelected(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Control* cobj = (cocos2d::extension::Control *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Control_isSelected : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isSelected();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Control_isSelected : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Control_isTouchInside(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Control* cobj = (cocos2d::extension::Control *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Control_isTouchInside : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Touch* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Touch*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_Control_isTouchInside : Error processing arguments");
		bool ret = cobj->isTouchInside(arg0);
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Control_isTouchInside : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_Control_setHighlighted(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Control* cobj = (cocos2d::extension::Control *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Control_setHighlighted : Invalid Native Object");
	if (argc == 1) {
		bool arg0;
		arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_Control_setHighlighted : Error processing arguments");
		cobj->setHighlighted(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Control_setHighlighted : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_Control_getTouchLocation(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Control* cobj = (cocos2d::extension::Control *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Control_getTouchLocation : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Touch* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Touch*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_Control_getTouchLocation : Error processing arguments");
		cocos2d::Vec2 ret = cobj->getTouchLocation(arg0);
		jsval jsret = JSVAL_NULL;
		jsret = vector2_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Control_getTouchLocation : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_Control_isHighlighted(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Control* cobj = (cocos2d::extension::Control *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Control_isHighlighted : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isHighlighted();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Control_isHighlighted : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Control_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		cocos2d::extension::Control* ret = cocos2d::extension::Control::create();
		jsval jsret = JSVAL_NULL;
		do {
		if (ret) {
			js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::Control>(cx, (cocos2d::extension::Control*)ret);
			jsret = OBJECT_TO_JSVAL(jsProxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
	JS_ReportError(cx, "js_cocos2dx_extension_Control_create : wrong number of arguments");
	return false;
}

bool js_cocos2dx_extension_Control_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    cocos2d::extension::Control* cobj = new cocos2d::extension::Control();
    cocos2d::Ref *_ccobj = dynamic_cast<cocos2d::Ref *>(cobj);
    if (_ccobj) {
        _ccobj->autorelease();
    }
    TypeTest<cocos2d::extension::Control> t;
    js_type_class_t *typeClass = nullptr;
    std::string typeName = t.s_name();
    auto typeMapIter = _js_global_type_map.find(typeName);
    CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
    typeClass = typeMapIter->second;
    CCASSERT(typeClass, "The value is null.");
    JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
    // link the native object with the javascript object
    js_proxy_t* p = jsb_new_proxy(cobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::Control");
    if (JS_HasProperty(cx, obj, "_ctor", &ok))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    return true;
}


extern JSObject *jsb_cocos2d_Layer_prototype;

void js_cocos2d_extension_Control_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (Control)", obj);
}

void js_register_cocos2dx_extension_Control(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_Control_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_Control_class->name = "Control";
	jsb_cocos2d_extension_Control_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_Control_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_Control_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_Control_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_Control_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_Control_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_Control_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_Control_class->finalize = js_cocos2d_extension_Control_finalize;
	jsb_cocos2d_extension_Control_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setEnabled", js_cocos2dx_extension_Control_setEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getState", js_cocos2dx_extension_Control_getState, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("sendActionsForControlEvents", js_cocos2dx_extension_Control_sendActionsForControlEvents, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setSelected", js_cocos2dx_extension_Control_setSelected, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isEnabled", js_cocos2dx_extension_Control_isEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("needsLayout", js_cocos2dx_extension_Control_needsLayout, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("hasVisibleParents", js_cocos2dx_extension_Control_hasVisibleParents, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isSelected", js_cocos2dx_extension_Control_isSelected, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isTouchInside", js_cocos2dx_extension_Control_isTouchInside, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setHighlighted", js_cocos2dx_extension_Control_setHighlighted, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTouchLocation", js_cocos2dx_extension_Control_getTouchLocation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isHighlighted", js_cocos2dx_extension_Control_isHighlighted, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_extension_Control_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_cocos2d_extension_Control_prototype = JS_InitClass(
		cx, global,
		jsb_cocos2d_Layer_prototype,
		jsb_cocos2d_extension_Control_class,
		js_cocos2dx_extension_Control_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "Control", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::Control> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_Control_class;
		p->proto = jsb_cocos2d_extension_Control_prototype;
		p->parentProto = jsb_cocos2d_Layer_prototype;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

JSClass  *jsb_cocos2d_extension_ControlButton_class;
JSObject *jsb_cocos2d_extension_ControlButton_prototype;

bool js_cocos2dx_extension_ControlButton_isPushed(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_isPushed : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isPushed();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_isPushed : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setSelected(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setSelected : Invalid Native Object");
	if (argc == 1) {
		bool arg0;
		arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setSelected : Error processing arguments");
		cobj->setSelected(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setSelected : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setTitleLabelForState(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setTitleLabelForState : Invalid Native Object");
	if (argc == 2) {
		cocos2d::Node* arg0;
		cocos2d::extension::Control::State arg1;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setTitleLabelForState : Error processing arguments");
		cobj->setTitleLabelForState(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setTitleLabelForState : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setAdjustBackgroundImage(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setAdjustBackgroundImage : Invalid Native Object");
	if (argc == 1) {
		bool arg0;
		arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setAdjustBackgroundImage : Error processing arguments");
		cobj->setAdjustBackgroundImage(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setAdjustBackgroundImage : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setHighlighted(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setHighlighted : Invalid Native Object");
	if (argc == 1) {
		bool arg0;
		arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setHighlighted : Error processing arguments");
		cobj->setHighlighted(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setHighlighted : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setZoomOnTouchDown(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setZoomOnTouchDown : Invalid Native Object");
	if (argc == 1) {
		bool arg0;
		arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setZoomOnTouchDown : Error processing arguments");
		cobj->setZoomOnTouchDown(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setZoomOnTouchDown : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setTitleForState(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setTitleForState : Invalid Native Object");
	if (argc == 2) {
		std::string arg0;
		cocos2d::extension::Control::State arg1;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setTitleForState : Error processing arguments");
		cobj->setTitleForState(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setTitleForState : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setLabelAnchorPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setLabelAnchorPoint : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Vec2 arg0;
		ok &= jsval_to_vector2(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setLabelAnchorPoint : Error processing arguments");
		cobj->setLabelAnchorPoint(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setLabelAnchorPoint : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_getLabelAnchorPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_getLabelAnchorPoint : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Vec2& ret = cobj->getLabelAnchorPoint();
		jsval jsret = JSVAL_NULL;
		jsret = vector2_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_getLabelAnchorPoint : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlButton_initWithBackgroundSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_initWithBackgroundSprite : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::Scale9Sprite* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::extension::Scale9Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_initWithBackgroundSprite : Error processing arguments");
		bool ret = cobj->initWithBackgroundSprite(arg0);
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_initWithBackgroundSprite : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_getTitleTTFSizeForState(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_getTitleTTFSizeForState : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::Control::State arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_getTitleTTFSizeForState : Error processing arguments");
		double ret = cobj->getTitleTTFSizeForState(arg0);
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_getTitleTTFSizeForState : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setTitleTTFForState(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setTitleTTFForState : Invalid Native Object");
	if (argc == 2) {
		std::string arg0;
		cocos2d::extension::Control::State arg1;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setTitleTTFForState : Error processing arguments");
		cobj->setTitleTTFForState(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setTitleTTFForState : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setTitleTTFSizeForState(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setTitleTTFSizeForState : Invalid Native Object");
	if (argc == 2) {
		double arg0;
		cocos2d::extension::Control::State arg1;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setTitleTTFSizeForState : Error processing arguments");
		cobj->setTitleTTFSizeForState(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setTitleTTFSizeForState : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setTitleLabel(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setTitleLabel : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Node* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setTitleLabel : Error processing arguments");
		cobj->setTitleLabel(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setTitleLabel : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setPreferredSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setPreferredSize : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Size arg0;
		ok &= jsval_to_ccsize(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setPreferredSize : Error processing arguments");
		cobj->setPreferredSize(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setPreferredSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_getCurrentTitleColor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_getCurrentTitleColor : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Color3B& ret = cobj->getCurrentTitleColor();
		jsval jsret = JSVAL_NULL;
		jsret = cccolor3b_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_getCurrentTitleColor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setEnabled : Invalid Native Object");
	if (argc == 1) {
		bool arg0;
		arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setEnabled : Error processing arguments");
		cobj->setEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setBackgroundSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setBackgroundSprite : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::Scale9Sprite* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::extension::Scale9Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setBackgroundSprite : Error processing arguments");
		cobj->setBackgroundSprite(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setBackgroundSprite : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_getBackgroundSpriteForState(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_getBackgroundSpriteForState : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::Control::State arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_getBackgroundSpriteForState : Error processing arguments");
		cocos2d::extension::Scale9Sprite* ret = cobj->getBackgroundSpriteForState(arg0);
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::Scale9Sprite>(cx, (cocos2d::extension::Scale9Sprite*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_getBackgroundSpriteForState : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_getHorizontalOrigin(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_getHorizontalOrigin : Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getHorizontalOrigin();
		jsval jsret = JSVAL_NULL;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_getHorizontalOrigin : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlButton_needsLayout(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_needsLayout : Invalid Native Object");
	if (argc == 0) {
		cobj->needsLayout();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_needsLayout : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlButton_initWithTitleAndFontNameAndFontSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_initWithTitleAndFontNameAndFontSize : Invalid Native Object");
	if (argc == 3) {
		std::string arg0;
		std::string arg1;
		double arg2;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		ok &= jsval_to_std_string(cx, argv[1], &arg1);
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[2]), &arg2);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_initWithTitleAndFontNameAndFontSize : Error processing arguments");
		bool ret = cobj->initWithTitleAndFontNameAndFontSize(arg0, arg1, arg2);
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_initWithTitleAndFontNameAndFontSize : wrong number of arguments: %d, was expecting %d", argc, 3);
	return false;
}
bool js_cocos2dx_extension_ControlButton_getCurrentTitle(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;

	JSObject *obj = NULL;
	cocos2d::extension::ControlButton* cobj = NULL;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_getCurrentTitle : Invalid Native Object");
	do {
		if (argc == 0) {
			std::string ret = cobj->getCurrentTitle();
			jsval jsret = JSVAL_NULL;
			jsret = std_string_to_jsval(cx, ret);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while(0);

	do {
		if (argc == 0) {
			const std::string& ret = cobj->getCurrentTitle();
			jsval jsret = JSVAL_NULL;
			jsret = std_string_to_jsval(cx, ret);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while(0);

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_getCurrentTitle : wrong number of arguments");
	return false;
}
bool js_cocos2dx_extension_ControlButton_getScaleRatio(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_getScaleRatio : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getScaleRatio();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_getScaleRatio : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlButton_getTitleTTFForState(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_getTitleTTFForState : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::Control::State arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_getTitleTTFForState : Error processing arguments");
		const std::string& ret = cobj->getTitleTTFForState(arg0);
		jsval jsret = JSVAL_NULL;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_getTitleTTFForState : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_getBackgroundSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_getBackgroundSprite : Invalid Native Object");
	if (argc == 0) {
		cocos2d::extension::Scale9Sprite* ret = cobj->getBackgroundSprite();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::Scale9Sprite>(cx, (cocos2d::extension::Scale9Sprite*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_getBackgroundSprite : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlButton_getTitleColorForState(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_getTitleColorForState : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::Control::State arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_getTitleColorForState : Error processing arguments");
		cocos2d::Color3B ret = cobj->getTitleColorForState(arg0);
		jsval jsret = JSVAL_NULL;
		jsret = cccolor3b_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_getTitleColorForState : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setTitleColorForState(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setTitleColorForState : Invalid Native Object");
	if (argc == 2) {
		cocos2d::Color3B arg0;
		cocos2d::extension::Control::State arg1;
		ok &= jsval_to_cccolor3b(cx, argv[0], &arg0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setTitleColorForState : Error processing arguments");
		cobj->setTitleColorForState(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setTitleColorForState : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ControlButton_doesAdjustBackgroundImage(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_doesAdjustBackgroundImage : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->doesAdjustBackgroundImage();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_doesAdjustBackgroundImage : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setBackgroundSpriteFrameForState(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setBackgroundSpriteFrameForState : Invalid Native Object");
	if (argc == 2) {
		cocos2d::SpriteFrame* arg0;
		cocos2d::extension::Control::State arg1;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::SpriteFrame*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setBackgroundSpriteFrameForState : Error processing arguments");
		cobj->setBackgroundSpriteFrameForState(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setBackgroundSpriteFrameForState : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setBackgroundSpriteForState(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setBackgroundSpriteForState : Invalid Native Object");
	if (argc == 2) {
		cocos2d::extension::Scale9Sprite* arg0;
		cocos2d::extension::Control::State arg1;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::extension::Scale9Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setBackgroundSpriteForState : Error processing arguments");
		cobj->setBackgroundSpriteForState(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setBackgroundSpriteForState : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setScaleRatio(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setScaleRatio : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setScaleRatio : Error processing arguments");
		cobj->setScaleRatio(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setScaleRatio : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_initWithLabelAndBackgroundSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_initWithLabelAndBackgroundSprite : Invalid Native Object");
	if (argc == 2) {
		cocos2d::Node* arg0;
		cocos2d::extension::Scale9Sprite* arg1;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		do {
			if (!argv[1].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg1 = (cocos2d::extension::Scale9Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_initWithLabelAndBackgroundSprite : Error processing arguments");
		bool ret = cobj->initWithLabelAndBackgroundSprite(arg0, arg1);
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_initWithLabelAndBackgroundSprite : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ControlButton_getTitleLabel(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_getTitleLabel : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Node* ret = cobj->getTitleLabel();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Node>(cx, (cocos2d::Node*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_getTitleLabel : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlButton_getPreferredSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_getPreferredSize : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Size& ret = cobj->getPreferredSize();
		jsval jsret = JSVAL_NULL;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_getPreferredSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlButton_getVerticalMargin(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_getVerticalMargin : Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getVerticalMargin();
		jsval jsret = JSVAL_NULL;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_getVerticalMargin : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlButton_getTitleLabelForState(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_getTitleLabelForState : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::Control::State arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_getTitleLabelForState : Error processing arguments");
		cocos2d::Node* ret = cobj->getTitleLabelForState(arg0);
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Node>(cx, (cocos2d::Node*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_getTitleLabelForState : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setMargins(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setMargins : Invalid Native Object");
	if (argc == 2) {
		int arg0;
		int arg1;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setMargins : Error processing arguments");
		cobj->setMargins(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setMargins : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ControlButton_setTitleBMFontForState(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_setTitleBMFontForState : Invalid Native Object");
	if (argc == 2) {
		std::string arg0;
		cocos2d::extension::Control::State arg1;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_setTitleBMFontForState : Error processing arguments");
		cobj->setTitleBMFontForState(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_setTitleBMFontForState : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ControlButton_getTitleBMFontForState(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_getTitleBMFontForState : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::Control::State arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_getTitleBMFontForState : Error processing arguments");
		const std::string& ret = cobj->getTitleBMFontForState(arg0);
		jsval jsret = JSVAL_NULL;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_getTitleBMFontForState : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_getZoomOnTouchDown(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_getZoomOnTouchDown : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->getZoomOnTouchDown();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_getZoomOnTouchDown : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlButton_getTitleForState(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlButton* cobj = (cocos2d::extension::ControlButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlButton_getTitleForState : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::Control::State arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlButton_getTitleForState : Error processing arguments");
		std::string ret = cobj->getTitleForState(arg0);
		jsval jsret = JSVAL_NULL;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_getTitleForState : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlButton_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	
	do {
		if (argc == 1) {
			cocos2d::extension::Scale9Sprite* arg0;
			do {
				if (!argv[0].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg0 = (cocos2d::extension::Scale9Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::extension::ControlButton* ret = cocos2d::extension::ControlButton::create(arg0);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ControlButton>(cx, (cocos2d::extension::ControlButton*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	
	do {
		if (argc == 0) {
			cocos2d::extension::ControlButton* ret = cocos2d::extension::ControlButton::create();
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ControlButton>(cx, (cocos2d::extension::ControlButton*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	
	do {
		if (argc == 2) {
			cocos2d::Node* arg0;
			do {
				if (!argv[0].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::extension::Scale9Sprite* arg1;
			do {
				if (!argv[1].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg1 = (cocos2d::extension::Scale9Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::extension::ControlButton* ret = cocos2d::extension::ControlButton::create(arg0, arg1);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ControlButton>(cx, (cocos2d::extension::ControlButton*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	
	do {
		if (argc == 3) {
			std::string arg0;
			ok &= jsval_to_std_string(cx, argv[0], &arg0);
			if (!ok) { ok = true; break; }
			std::string arg1;
			ok &= jsval_to_std_string(cx, argv[1], &arg1);
			if (!ok) { ok = true; break; }
			double arg2;
			ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[2]), &arg2);
			if (!ok) { ok = true; break; }
			cocos2d::extension::ControlButton* ret = cocos2d::extension::ControlButton::create(arg0, arg1, arg2);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ControlButton>(cx, (cocos2d::extension::ControlButton*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	JS_ReportError(cx, "js_cocos2dx_extension_ControlButton_create : wrong number of arguments");
	return false;
}
bool js_cocos2dx_extension_ControlButton_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    cocos2d::extension::ControlButton* cobj = new cocos2d::extension::ControlButton();
    cocos2d::Ref *_ccobj = dynamic_cast<cocos2d::Ref *>(cobj);
    if (_ccobj) {
        _ccobj->autorelease();
    }
    TypeTest<cocos2d::extension::ControlButton> t;
    js_type_class_t *typeClass = nullptr;
    std::string typeName = t.s_name();
    auto typeMapIter = _js_global_type_map.find(typeName);
    CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
    typeClass = typeMapIter->second;
    CCASSERT(typeClass, "The value is null.");
    JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
    // link the native object with the javascript object
    js_proxy_t* p = jsb_new_proxy(cobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::ControlButton");
    if (JS_HasProperty(cx, obj, "_ctor", &ok))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    return true;
}


extern JSObject *jsb_cocos2d_extension_Control_prototype;

void js_cocos2d_extension_ControlButton_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ControlButton)", obj);
}

void js_register_cocos2dx_extension_ControlButton(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_ControlButton_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_ControlButton_class->name = "ControlButton";
	jsb_cocos2d_extension_ControlButton_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ControlButton_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_ControlButton_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ControlButton_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_ControlButton_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_ControlButton_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_ControlButton_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_ControlButton_class->finalize = js_cocos2d_extension_ControlButton_finalize;
	jsb_cocos2d_extension_ControlButton_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("isPushed", js_cocos2dx_extension_ControlButton_isPushed, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setSelected", js_cocos2dx_extension_ControlButton_setSelected, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTitleLabelForState", js_cocos2dx_extension_ControlButton_setTitleLabelForState, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setAdjustBackgroundImage", js_cocos2dx_extension_ControlButton_setAdjustBackgroundImage, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setHighlighted", js_cocos2dx_extension_ControlButton_setHighlighted, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setZoomOnTouchDown", js_cocos2dx_extension_ControlButton_setZoomOnTouchDown, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTitleForState", js_cocos2dx_extension_ControlButton_setTitleForState, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setLabelAnchorPoint", js_cocos2dx_extension_ControlButton_setLabelAnchorPoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getLabelAnchorPoint", js_cocos2dx_extension_ControlButton_getLabelAnchorPoint, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initWithBackgroundSprite", js_cocos2dx_extension_ControlButton_initWithBackgroundSprite, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTitleTTFSizeForState", js_cocos2dx_extension_ControlButton_getTitleTTFSizeForState, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTitleTTFForState", js_cocos2dx_extension_ControlButton_setTitleTTFForState, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTitleTTFSizeForState", js_cocos2dx_extension_ControlButton_setTitleTTFSizeForState, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTitleLabel", js_cocos2dx_extension_ControlButton_setTitleLabel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPreferredSize", js_cocos2dx_extension_ControlButton_setPreferredSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getCurrentTitleColor", js_cocos2dx_extension_ControlButton_getCurrentTitleColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setEnabled", js_cocos2dx_extension_ControlButton_setEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBackgroundSprite", js_cocos2dx_extension_ControlButton_setBackgroundSprite, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getBackgroundSpriteForState", js_cocos2dx_extension_ControlButton_getBackgroundSpriteForState, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getHorizontalOrigin", js_cocos2dx_extension_ControlButton_getHorizontalOrigin, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("needsLayout", js_cocos2dx_extension_ControlButton_needsLayout, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initWithTitleAndFontNameAndFontSize", js_cocos2dx_extension_ControlButton_initWithTitleAndFontNameAndFontSize, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getCurrentTitle", js_cocos2dx_extension_ControlButton_getCurrentTitle, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getScaleRatio", js_cocos2dx_extension_ControlButton_getScaleRatio, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTitleTTFForState", js_cocos2dx_extension_ControlButton_getTitleTTFForState, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getBackgroundSprite", js_cocos2dx_extension_ControlButton_getBackgroundSprite, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTitleColorForState", js_cocos2dx_extension_ControlButton_getTitleColorForState, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTitleColorForState", js_cocos2dx_extension_ControlButton_setTitleColorForState, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("doesAdjustBackgroundImage", js_cocos2dx_extension_ControlButton_doesAdjustBackgroundImage, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBackgroundSpriteFrameForState", js_cocos2dx_extension_ControlButton_setBackgroundSpriteFrameForState, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBackgroundSpriteForState", js_cocos2dx_extension_ControlButton_setBackgroundSpriteForState, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setScaleRatio", js_cocos2dx_extension_ControlButton_setScaleRatio, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initWithLabelAndBackgroundSprite", js_cocos2dx_extension_ControlButton_initWithLabelAndBackgroundSprite, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTitleLabel", js_cocos2dx_extension_ControlButton_getTitleLabel, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPreferredSize", js_cocos2dx_extension_ControlButton_getPreferredSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getVerticalMargin", js_cocos2dx_extension_ControlButton_getVerticalMargin, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTitleLabelForState", js_cocos2dx_extension_ControlButton_getTitleLabelForState, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setMargins", js_cocos2dx_extension_ControlButton_setMargins, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTitleBMFontForState", js_cocos2dx_extension_ControlButton_setTitleBMFontForState, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTitleBMFontForState", js_cocos2dx_extension_ControlButton_getTitleBMFontForState, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getZoomOnTouchDown", js_cocos2dx_extension_ControlButton_getZoomOnTouchDown, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTitleForState", js_cocos2dx_extension_ControlButton_getTitleForState, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_extension_ControlButton_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_cocos2d_extension_ControlButton_prototype = JS_InitClass(
		cx, global,
		jsb_cocos2d_extension_Control_prototype,
		jsb_cocos2d_extension_ControlButton_class,
		js_cocos2dx_extension_ControlButton_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "ControlButton", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::ControlButton> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_ControlButton_class;
		p->proto = jsb_cocos2d_extension_ControlButton_prototype;
		p->parentProto = jsb_cocos2d_extension_Control_prototype;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

JSClass  *jsb_cocos2d_extension_ControlHuePicker_class;
JSObject *jsb_cocos2d_extension_ControlHuePicker_prototype;

bool js_cocos2dx_extension_ControlHuePicker_setEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlHuePicker* cobj = (cocos2d::extension::ControlHuePicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlHuePicker_setEnabled : Invalid Native Object");
	if (argc == 1) {
		bool arg0;
		arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlHuePicker_setEnabled : Error processing arguments");
		cobj->setEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlHuePicker_setEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlHuePicker_initWithTargetAndPos(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlHuePicker* cobj = (cocos2d::extension::ControlHuePicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlHuePicker_initWithTargetAndPos : Invalid Native Object");
	if (argc == 2) {
		cocos2d::Node* arg0;
		cocos2d::Vec2 arg1;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_vector2(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlHuePicker_initWithTargetAndPos : Error processing arguments");
		bool ret = cobj->initWithTargetAndPos(arg0, arg1);
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlHuePicker_initWithTargetAndPos : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ControlHuePicker_setHue(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlHuePicker* cobj = (cocos2d::extension::ControlHuePicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlHuePicker_setHue : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlHuePicker_setHue : Error processing arguments");
		cobj->setHue(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlHuePicker_setHue : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlHuePicker_getStartPos(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlHuePicker* cobj = (cocos2d::extension::ControlHuePicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlHuePicker_getStartPos : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Vec2 ret = cobj->getStartPos();
		jsval jsret = JSVAL_NULL;
		jsret = vector2_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlHuePicker_getStartPos : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlHuePicker_getHue(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlHuePicker* cobj = (cocos2d::extension::ControlHuePicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlHuePicker_getHue : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getHue();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlHuePicker_getHue : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlHuePicker_getSlider(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlHuePicker* cobj = (cocos2d::extension::ControlHuePicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlHuePicker_getSlider : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Sprite* ret = cobj->getSlider();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Sprite>(cx, (cocos2d::Sprite*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlHuePicker_getSlider : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlHuePicker_setBackground(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlHuePicker* cobj = (cocos2d::extension::ControlHuePicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlHuePicker_setBackground : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Sprite* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlHuePicker_setBackground : Error processing arguments");
		cobj->setBackground(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlHuePicker_setBackground : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlHuePicker_setHuePercentage(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlHuePicker* cobj = (cocos2d::extension::ControlHuePicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlHuePicker_setHuePercentage : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlHuePicker_setHuePercentage : Error processing arguments");
		cobj->setHuePercentage(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlHuePicker_setHuePercentage : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlHuePicker_getBackground(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlHuePicker* cobj = (cocos2d::extension::ControlHuePicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlHuePicker_getBackground : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Sprite* ret = cobj->getBackground();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Sprite>(cx, (cocos2d::Sprite*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlHuePicker_getBackground : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlHuePicker_getHuePercentage(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlHuePicker* cobj = (cocos2d::extension::ControlHuePicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlHuePicker_getHuePercentage : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getHuePercentage();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlHuePicker_getHuePercentage : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlHuePicker_setSlider(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlHuePicker* cobj = (cocos2d::extension::ControlHuePicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlHuePicker_setSlider : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Sprite* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlHuePicker_setSlider : Error processing arguments");
		cobj->setSlider(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlHuePicker_setSlider : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlHuePicker_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	if (argc == 2) {
		cocos2d::Node* arg0;
		cocos2d::Vec2 arg1;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_vector2(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlHuePicker_create : Error processing arguments");
		cocos2d::extension::ControlHuePicker* ret = cocos2d::extension::ControlHuePicker::create(arg0, arg1);
		jsval jsret = JSVAL_NULL;
		do {
		if (ret) {
			js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ControlHuePicker>(cx, (cocos2d::extension::ControlHuePicker*)ret);
			jsret = OBJECT_TO_JSVAL(jsProxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
	JS_ReportError(cx, "js_cocos2dx_extension_ControlHuePicker_create : wrong number of arguments");
	return false;
}

bool js_cocos2dx_extension_ControlHuePicker_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    cocos2d::extension::ControlHuePicker* cobj = new cocos2d::extension::ControlHuePicker();
    cocos2d::Ref *_ccobj = dynamic_cast<cocos2d::Ref *>(cobj);
    if (_ccobj) {
        _ccobj->autorelease();
    }
    TypeTest<cocos2d::extension::ControlHuePicker> t;
    js_type_class_t *typeClass = nullptr;
    std::string typeName = t.s_name();
    auto typeMapIter = _js_global_type_map.find(typeName);
    CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
    typeClass = typeMapIter->second;
    CCASSERT(typeClass, "The value is null.");
    JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
    // link the native object with the javascript object
    js_proxy_t* p = jsb_new_proxy(cobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::ControlHuePicker");
    if (JS_HasProperty(cx, obj, "_ctor", &ok))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    return true;
}


extern JSObject *jsb_cocos2d_extension_Control_prototype;

void js_cocos2d_extension_ControlHuePicker_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ControlHuePicker)", obj);
}

void js_register_cocos2dx_extension_ControlHuePicker(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_ControlHuePicker_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_ControlHuePicker_class->name = "ControlHuePicker";
	jsb_cocos2d_extension_ControlHuePicker_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ControlHuePicker_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_ControlHuePicker_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ControlHuePicker_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_ControlHuePicker_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_ControlHuePicker_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_ControlHuePicker_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_ControlHuePicker_class->finalize = js_cocos2d_extension_ControlHuePicker_finalize;
	jsb_cocos2d_extension_ControlHuePicker_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setEnabled", js_cocos2dx_extension_ControlHuePicker_setEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initWithTargetAndPos", js_cocos2dx_extension_ControlHuePicker_initWithTargetAndPos, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setHue", js_cocos2dx_extension_ControlHuePicker_setHue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getStartPos", js_cocos2dx_extension_ControlHuePicker_getStartPos, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getHue", js_cocos2dx_extension_ControlHuePicker_getHue, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getSlider", js_cocos2dx_extension_ControlHuePicker_getSlider, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBackground", js_cocos2dx_extension_ControlHuePicker_setBackground, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setHuePercentage", js_cocos2dx_extension_ControlHuePicker_setHuePercentage, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getBackground", js_cocos2dx_extension_ControlHuePicker_getBackground, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getHuePercentage", js_cocos2dx_extension_ControlHuePicker_getHuePercentage, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setSlider", js_cocos2dx_extension_ControlHuePicker_setSlider, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_extension_ControlHuePicker_create, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_cocos2d_extension_ControlHuePicker_prototype = JS_InitClass(
		cx, global,
		jsb_cocos2d_extension_Control_prototype,
		jsb_cocos2d_extension_ControlHuePicker_class,
		js_cocos2dx_extension_ControlHuePicker_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "ControlHuePicker", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::ControlHuePicker> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_ControlHuePicker_class;
		p->proto = jsb_cocos2d_extension_ControlHuePicker_prototype;
		p->parentProto = jsb_cocos2d_extension_Control_prototype;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

JSClass  *jsb_cocos2d_extension_ControlSaturationBrightnessPicker_class;
JSObject *jsb_cocos2d_extension_ControlSaturationBrightnessPicker_prototype;

bool js_cocos2dx_extension_ControlSaturationBrightnessPicker_getShadow(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSaturationBrightnessPicker* cobj = (cocos2d::extension::ControlSaturationBrightnessPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_getShadow : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Sprite* ret = cobj->getShadow();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Sprite>(cx, (cocos2d::Sprite*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_getShadow : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSaturationBrightnessPicker_initWithTargetAndPos(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSaturationBrightnessPicker* cobj = (cocos2d::extension::ControlSaturationBrightnessPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_initWithTargetAndPos : Invalid Native Object");
	if (argc == 2) {
		cocos2d::Node* arg0;
		cocos2d::Vec2 arg1;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_vector2(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_initWithTargetAndPos : Error processing arguments");
		bool ret = cobj->initWithTargetAndPos(arg0, arg1);
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_initWithTargetAndPos : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ControlSaturationBrightnessPicker_getStartPos(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSaturationBrightnessPicker* cobj = (cocos2d::extension::ControlSaturationBrightnessPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_getStartPos : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Vec2 ret = cobj->getStartPos();
		jsval jsret = JSVAL_NULL;
		jsret = vector2_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_getStartPos : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSaturationBrightnessPicker_getOverlay(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSaturationBrightnessPicker* cobj = (cocos2d::extension::ControlSaturationBrightnessPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_getOverlay : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Sprite* ret = cobj->getOverlay();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Sprite>(cx, (cocos2d::Sprite*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_getOverlay : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSaturationBrightnessPicker_setEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSaturationBrightnessPicker* cobj = (cocos2d::extension::ControlSaturationBrightnessPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_setEnabled : Invalid Native Object");
	if (argc == 1) {
		bool arg0;
		arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_setEnabled : Error processing arguments");
		cobj->setEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_setEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlSaturationBrightnessPicker_getSlider(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSaturationBrightnessPicker* cobj = (cocos2d::extension::ControlSaturationBrightnessPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_getSlider : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Sprite* ret = cobj->getSlider();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Sprite>(cx, (cocos2d::Sprite*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_getSlider : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSaturationBrightnessPicker_getBackground(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSaturationBrightnessPicker* cobj = (cocos2d::extension::ControlSaturationBrightnessPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_getBackground : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Sprite* ret = cobj->getBackground();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Sprite>(cx, (cocos2d::Sprite*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_getBackground : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSaturationBrightnessPicker_getSaturation(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSaturationBrightnessPicker* cobj = (cocos2d::extension::ControlSaturationBrightnessPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_getSaturation : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getSaturation();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_getSaturation : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSaturationBrightnessPicker_getBrightness(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSaturationBrightnessPicker* cobj = (cocos2d::extension::ControlSaturationBrightnessPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_getBrightness : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getBrightness();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_getBrightness : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSaturationBrightnessPicker_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	if (argc == 2) {
		cocos2d::Node* arg0;
		cocos2d::Vec2 arg1;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_vector2(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_create : Error processing arguments");
		cocos2d::extension::ControlSaturationBrightnessPicker* ret = cocos2d::extension::ControlSaturationBrightnessPicker::create(arg0, arg1);
		jsval jsret = JSVAL_NULL;
		do {
		if (ret) {
			js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ControlSaturationBrightnessPicker>(cx, (cocos2d::extension::ControlSaturationBrightnessPicker*)ret);
			jsret = OBJECT_TO_JSVAL(jsProxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
	JS_ReportError(cx, "js_cocos2dx_extension_ControlSaturationBrightnessPicker_create : wrong number of arguments");
	return false;
}

bool js_cocos2dx_extension_ControlSaturationBrightnessPicker_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    cocos2d::extension::ControlSaturationBrightnessPicker* cobj = new cocos2d::extension::ControlSaturationBrightnessPicker();
    cocos2d::Ref *_ccobj = dynamic_cast<cocos2d::Ref *>(cobj);
    if (_ccobj) {
        _ccobj->autorelease();
    }
    TypeTest<cocos2d::extension::ControlSaturationBrightnessPicker> t;
    js_type_class_t *typeClass = nullptr;
    std::string typeName = t.s_name();
    auto typeMapIter = _js_global_type_map.find(typeName);
    CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
    typeClass = typeMapIter->second;
    CCASSERT(typeClass, "The value is null.");
    JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
    // link the native object with the javascript object
    js_proxy_t* p = jsb_new_proxy(cobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::ControlSaturationBrightnessPicker");
    if (JS_HasProperty(cx, obj, "_ctor", &ok))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    return true;
}


extern JSObject *jsb_cocos2d_extension_Control_prototype;

void js_cocos2d_extension_ControlSaturationBrightnessPicker_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ControlSaturationBrightnessPicker)", obj);
}

void js_register_cocos2dx_extension_ControlSaturationBrightnessPicker(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_ControlSaturationBrightnessPicker_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_ControlSaturationBrightnessPicker_class->name = "ControlSaturationBrightnessPicker";
	jsb_cocos2d_extension_ControlSaturationBrightnessPicker_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ControlSaturationBrightnessPicker_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_ControlSaturationBrightnessPicker_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ControlSaturationBrightnessPicker_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_ControlSaturationBrightnessPicker_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_ControlSaturationBrightnessPicker_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_ControlSaturationBrightnessPicker_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_ControlSaturationBrightnessPicker_class->finalize = js_cocos2d_extension_ControlSaturationBrightnessPicker_finalize;
	jsb_cocos2d_extension_ControlSaturationBrightnessPicker_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("getShadow", js_cocos2dx_extension_ControlSaturationBrightnessPicker_getShadow, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initWithTargetAndPos", js_cocos2dx_extension_ControlSaturationBrightnessPicker_initWithTargetAndPos, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getStartPos", js_cocos2dx_extension_ControlSaturationBrightnessPicker_getStartPos, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getOverlay", js_cocos2dx_extension_ControlSaturationBrightnessPicker_getOverlay, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setEnabled", js_cocos2dx_extension_ControlSaturationBrightnessPicker_setEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getSlider", js_cocos2dx_extension_ControlSaturationBrightnessPicker_getSlider, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getBackground", js_cocos2dx_extension_ControlSaturationBrightnessPicker_getBackground, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getSaturation", js_cocos2dx_extension_ControlSaturationBrightnessPicker_getSaturation, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getBrightness", js_cocos2dx_extension_ControlSaturationBrightnessPicker_getBrightness, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_extension_ControlSaturationBrightnessPicker_create, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_cocos2d_extension_ControlSaturationBrightnessPicker_prototype = JS_InitClass(
		cx, global,
		jsb_cocos2d_extension_Control_prototype,
		jsb_cocos2d_extension_ControlSaturationBrightnessPicker_class,
		js_cocos2dx_extension_ControlSaturationBrightnessPicker_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "ControlSaturationBrightnessPicker", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::ControlSaturationBrightnessPicker> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_ControlSaturationBrightnessPicker_class;
		p->proto = jsb_cocos2d_extension_ControlSaturationBrightnessPicker_prototype;
		p->parentProto = jsb_cocos2d_extension_Control_prototype;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

JSClass  *jsb_cocos2d_extension_ControlColourPicker_class;
JSObject *jsb_cocos2d_extension_ControlColourPicker_prototype;

bool js_cocos2dx_extension_ControlColourPicker_setEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlColourPicker* cobj = (cocos2d::extension::ControlColourPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlColourPicker_setEnabled : Invalid Native Object");
	if (argc == 1) {
		bool arg0;
		arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlColourPicker_setEnabled : Error processing arguments");
		cobj->setEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlColourPicker_setEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlColourPicker_getHuePicker(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlColourPicker* cobj = (cocos2d::extension::ControlColourPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlColourPicker_getHuePicker : Invalid Native Object");
	if (argc == 0) {
		cocos2d::extension::ControlHuePicker* ret = cobj->getHuePicker();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ControlHuePicker>(cx, (cocos2d::extension::ControlHuePicker*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlColourPicker_getHuePicker : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlColourPicker_setColor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlColourPicker* cobj = (cocos2d::extension::ControlColourPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlColourPicker_setColor : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= jsval_to_cccolor3b(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlColourPicker_setColor : Error processing arguments");
		cobj->setColor(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlColourPicker_setColor : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlColourPicker_hueSliderValueChanged(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlColourPicker* cobj = (cocos2d::extension::ControlColourPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlColourPicker_hueSliderValueChanged : Invalid Native Object");
	if (argc == 2) {
		cocos2d::Ref* arg0;
		cocos2d::extension::Control::EventType arg1;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Ref*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlColourPicker_hueSliderValueChanged : Error processing arguments");
		cobj->hueSliderValueChanged(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlColourPicker_hueSliderValueChanged : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ControlColourPicker_getcolourPicker(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlColourPicker* cobj = (cocos2d::extension::ControlColourPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlColourPicker_getcolourPicker : Invalid Native Object");
	if (argc == 0) {
		cocos2d::extension::ControlSaturationBrightnessPicker* ret = cobj->getcolourPicker();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ControlSaturationBrightnessPicker>(cx, (cocos2d::extension::ControlSaturationBrightnessPicker*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlColourPicker_getcolourPicker : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlColourPicker_setBackground(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlColourPicker* cobj = (cocos2d::extension::ControlColourPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlColourPicker_setBackground : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Sprite* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlColourPicker_setBackground : Error processing arguments");
		cobj->setBackground(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlColourPicker_setBackground : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlColourPicker_setcolourPicker(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlColourPicker* cobj = (cocos2d::extension::ControlColourPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlColourPicker_setcolourPicker : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::ControlSaturationBrightnessPicker* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::extension::ControlSaturationBrightnessPicker*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlColourPicker_setcolourPicker : Error processing arguments");
		cobj->setcolourPicker(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlColourPicker_setcolourPicker : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlColourPicker_colourSliderValueChanged(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlColourPicker* cobj = (cocos2d::extension::ControlColourPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlColourPicker_colourSliderValueChanged : Invalid Native Object");
	if (argc == 2) {
		cocos2d::Ref* arg0;
		cocos2d::extension::Control::EventType arg1;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Ref*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlColourPicker_colourSliderValueChanged : Error processing arguments");
		cobj->colourSliderValueChanged(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlColourPicker_colourSliderValueChanged : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ControlColourPicker_setHuePicker(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlColourPicker* cobj = (cocos2d::extension::ControlColourPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlColourPicker_setHuePicker : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::ControlHuePicker* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::extension::ControlHuePicker*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlColourPicker_setHuePicker : Error processing arguments");
		cobj->setHuePicker(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlColourPicker_setHuePicker : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlColourPicker_getBackground(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlColourPicker* cobj = (cocos2d::extension::ControlColourPicker *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlColourPicker_getBackground : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Sprite* ret = cobj->getBackground();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Sprite>(cx, (cocos2d::Sprite*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlColourPicker_getBackground : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlColourPicker_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		cocos2d::extension::ControlColourPicker* ret = cocos2d::extension::ControlColourPicker::create();
		jsval jsret = JSVAL_NULL;
		do {
		if (ret) {
			js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ControlColourPicker>(cx, (cocos2d::extension::ControlColourPicker*)ret);
			jsret = OBJECT_TO_JSVAL(jsProxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
	JS_ReportError(cx, "js_cocos2dx_extension_ControlColourPicker_create : wrong number of arguments");
	return false;
}

bool js_cocos2dx_extension_ControlColourPicker_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    cocos2d::extension::ControlColourPicker* cobj = new cocos2d::extension::ControlColourPicker();
    cocos2d::Ref *_ccobj = dynamic_cast<cocos2d::Ref *>(cobj);
    if (_ccobj) {
        _ccobj->autorelease();
    }
    TypeTest<cocos2d::extension::ControlColourPicker> t;
    js_type_class_t *typeClass = nullptr;
    std::string typeName = t.s_name();
    auto typeMapIter = _js_global_type_map.find(typeName);
    CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
    typeClass = typeMapIter->second;
    CCASSERT(typeClass, "The value is null.");
    JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
    // link the native object with the javascript object
    js_proxy_t* p = jsb_new_proxy(cobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::ControlColourPicker");
    if (JS_HasProperty(cx, obj, "_ctor", &ok))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    return true;
}


extern JSObject *jsb_cocos2d_extension_Control_prototype;

void js_cocos2d_extension_ControlColourPicker_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ControlColourPicker)", obj);
}

void js_register_cocos2dx_extension_ControlColourPicker(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_ControlColourPicker_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_ControlColourPicker_class->name = "ControlColourPicker";
	jsb_cocos2d_extension_ControlColourPicker_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ControlColourPicker_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_ControlColourPicker_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ControlColourPicker_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_ControlColourPicker_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_ControlColourPicker_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_ControlColourPicker_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_ControlColourPicker_class->finalize = js_cocos2d_extension_ControlColourPicker_finalize;
	jsb_cocos2d_extension_ControlColourPicker_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setEnabled", js_cocos2dx_extension_ControlColourPicker_setEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getHuePicker", js_cocos2dx_extension_ControlColourPicker_getHuePicker, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setColor", js_cocos2dx_extension_ControlColourPicker_setColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("hueSliderValueChanged", js_cocos2dx_extension_ControlColourPicker_hueSliderValueChanged, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getcolourPicker", js_cocos2dx_extension_ControlColourPicker_getcolourPicker, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBackground", js_cocos2dx_extension_ControlColourPicker_setBackground, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setcolourPicker", js_cocos2dx_extension_ControlColourPicker_setcolourPicker, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("colourSliderValueChanged", js_cocos2dx_extension_ControlColourPicker_colourSliderValueChanged, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setHuePicker", js_cocos2dx_extension_ControlColourPicker_setHuePicker, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getBackground", js_cocos2dx_extension_ControlColourPicker_getBackground, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_extension_ControlColourPicker_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_cocos2d_extension_ControlColourPicker_prototype = JS_InitClass(
		cx, global,
		jsb_cocos2d_extension_Control_prototype,
		jsb_cocos2d_extension_ControlColourPicker_class,
		js_cocos2dx_extension_ControlColourPicker_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "ControlColourPicker", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::ControlColourPicker> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_ControlColourPicker_class;
		p->proto = jsb_cocos2d_extension_ControlColourPicker_prototype;
		p->parentProto = jsb_cocos2d_extension_Control_prototype;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

JSClass  *jsb_cocos2d_extension_ControlPotentiometer_class;
JSObject *jsb_cocos2d_extension_ControlPotentiometer_prototype;

bool js_cocos2dx_extension_ControlPotentiometer_setPreviousLocation(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_setPreviousLocation : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Vec2 arg0;
		ok &= jsval_to_vector2(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlPotentiometer_setPreviousLocation : Error processing arguments");
		cobj->setPreviousLocation(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_setPreviousLocation : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_setValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_setValue : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlPotentiometer_setValue : Error processing arguments");
		cobj->setValue(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_setValue : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_getProgressTimer(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_getProgressTimer : Invalid Native Object");
	if (argc == 0) {
		cocos2d::ProgressTimer* ret = cobj->getProgressTimer();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::ProgressTimer>(cx, (cocos2d::ProgressTimer*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_getProgressTimer : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_getMaximumValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_getMaximumValue : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getMaximumValue();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_getMaximumValue : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_angleInDegreesBetweenLineFromPoint_toPoint_toLineFromPoint_toPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_angleInDegreesBetweenLineFromPoint_toPoint_toLineFromPoint_toPoint : Invalid Native Object");
	if (argc == 4) {
		cocos2d::Vec2 arg0;
		cocos2d::Vec2 arg1;
		cocos2d::Vec2 arg2;
		cocos2d::Vec2 arg3;
		ok &= jsval_to_vector2(cx, argv[0], &arg0);
		ok &= jsval_to_vector2(cx, argv[1], &arg1);
		ok &= jsval_to_vector2(cx, argv[2], &arg2);
		ok &= jsval_to_vector2(cx, argv[3], &arg3);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlPotentiometer_angleInDegreesBetweenLineFromPoint_toPoint_toLineFromPoint_toPoint : Error processing arguments");
		double ret = cobj->angleInDegreesBetweenLineFromPoint_toPoint_toLineFromPoint_toPoint(arg0, arg1, arg2, arg3);
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_angleInDegreesBetweenLineFromPoint_toPoint_toLineFromPoint_toPoint : wrong number of arguments: %d, was expecting %d", argc, 4);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_potentiometerBegan(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_potentiometerBegan : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Vec2 arg0;
		ok &= jsval_to_vector2(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlPotentiometer_potentiometerBegan : Error processing arguments");
		cobj->potentiometerBegan(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_potentiometerBegan : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_setMaximumValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_setMaximumValue : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlPotentiometer_setMaximumValue : Error processing arguments");
		cobj->setMaximumValue(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_setMaximumValue : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_getMinimumValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_getMinimumValue : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getMinimumValue();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_getMinimumValue : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_setThumbSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_setThumbSprite : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Sprite* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlPotentiometer_setThumbSprite : Error processing arguments");
		cobj->setThumbSprite(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_setThumbSprite : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_getValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_getValue : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getValue();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_getValue : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_getPreviousLocation(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_getPreviousLocation : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Vec2 ret = cobj->getPreviousLocation();
		jsval jsret = JSVAL_NULL;
		jsret = vector2_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_getPreviousLocation : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_distanceBetweenPointAndPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_distanceBetweenPointAndPoint : Invalid Native Object");
	if (argc == 2) {
		cocos2d::Vec2 arg0;
		cocos2d::Vec2 arg1;
		ok &= jsval_to_vector2(cx, argv[0], &arg0);
		ok &= jsval_to_vector2(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlPotentiometer_distanceBetweenPointAndPoint : Error processing arguments");
		double ret = cobj->distanceBetweenPointAndPoint(arg0, arg1);
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_distanceBetweenPointAndPoint : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_potentiometerEnded(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_potentiometerEnded : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Vec2 arg0;
		ok &= jsval_to_vector2(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlPotentiometer_potentiometerEnded : Error processing arguments");
		cobj->potentiometerEnded(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_potentiometerEnded : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_setProgressTimer(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_setProgressTimer : Invalid Native Object");
	if (argc == 1) {
		cocos2d::ProgressTimer* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::ProgressTimer*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlPotentiometer_setProgressTimer : Error processing arguments");
		cobj->setProgressTimer(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_setProgressTimer : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_setMinimumValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_setMinimumValue : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlPotentiometer_setMinimumValue : Error processing arguments");
		cobj->setMinimumValue(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_setMinimumValue : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_getThumbSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_getThumbSprite : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Sprite* ret = cobj->getThumbSprite();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Sprite>(cx, (cocos2d::Sprite*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_getThumbSprite : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_initWithTrackSprite_ProgressTimer_ThumbSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_initWithTrackSprite_ProgressTimer_ThumbSprite : Invalid Native Object");
	if (argc == 3) {
		cocos2d::Sprite* arg0;
		cocos2d::ProgressTimer* arg1;
		cocos2d::Sprite* arg2;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		do {
			if (!argv[1].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg1 = (cocos2d::ProgressTimer*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
		} while (0);
		do {
			if (!argv[2].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[2]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg2 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg2, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlPotentiometer_initWithTrackSprite_ProgressTimer_ThumbSprite : Error processing arguments");
		bool ret = cobj->initWithTrackSprite_ProgressTimer_ThumbSprite(arg0, arg1, arg2);
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_initWithTrackSprite_ProgressTimer_ThumbSprite : wrong number of arguments: %d, was expecting %d", argc, 3);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_potentiometerMoved(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlPotentiometer* cobj = (cocos2d::extension::ControlPotentiometer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlPotentiometer_potentiometerMoved : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Vec2 arg0;
		ok &= jsval_to_vector2(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlPotentiometer_potentiometerMoved : Error processing arguments");
		cobj->potentiometerMoved(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_potentiometerMoved : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlPotentiometer_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	if (argc == 3) {
		const char* arg0;
		const char* arg1;
		const char* arg2;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
		std::string arg2_tmp; ok &= jsval_to_std_string(cx, argv[2], &arg2_tmp); arg2 = arg2_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlPotentiometer_create : Error processing arguments");
		cocos2d::extension::ControlPotentiometer* ret = cocos2d::extension::ControlPotentiometer::create(arg0, arg1, arg2);
		jsval jsret = JSVAL_NULL;
		do {
		if (ret) {
			js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ControlPotentiometer>(cx, (cocos2d::extension::ControlPotentiometer*)ret);
			jsret = OBJECT_TO_JSVAL(jsProxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
	JS_ReportError(cx, "js_cocos2dx_extension_ControlPotentiometer_create : wrong number of arguments");
	return false;
}

bool js_cocos2dx_extension_ControlPotentiometer_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    cocos2d::extension::ControlPotentiometer* cobj = new cocos2d::extension::ControlPotentiometer();
    cocos2d::Ref *_ccobj = dynamic_cast<cocos2d::Ref *>(cobj);
    if (_ccobj) {
        _ccobj->autorelease();
    }
    TypeTest<cocos2d::extension::ControlPotentiometer> t;
    js_type_class_t *typeClass = nullptr;
    std::string typeName = t.s_name();
    auto typeMapIter = _js_global_type_map.find(typeName);
    CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
    typeClass = typeMapIter->second;
    CCASSERT(typeClass, "The value is null.");
    JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
    // link the native object with the javascript object
    js_proxy_t* p = jsb_new_proxy(cobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::ControlPotentiometer");
    if (JS_HasProperty(cx, obj, "_ctor", &ok))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    return true;
}


extern JSObject *jsb_cocos2d_extension_Control_prototype;

void js_cocos2d_extension_ControlPotentiometer_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ControlPotentiometer)", obj);
}

void js_register_cocos2dx_extension_ControlPotentiometer(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_ControlPotentiometer_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_ControlPotentiometer_class->name = "ControlPotentiometer";
	jsb_cocos2d_extension_ControlPotentiometer_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ControlPotentiometer_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_ControlPotentiometer_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ControlPotentiometer_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_ControlPotentiometer_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_ControlPotentiometer_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_ControlPotentiometer_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_ControlPotentiometer_class->finalize = js_cocos2d_extension_ControlPotentiometer_finalize;
	jsb_cocos2d_extension_ControlPotentiometer_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setPreviousLocation", js_cocos2dx_extension_ControlPotentiometer_setPreviousLocation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setValue", js_cocos2dx_extension_ControlPotentiometer_setValue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getProgressTimer", js_cocos2dx_extension_ControlPotentiometer_getProgressTimer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getMaximumValue", js_cocos2dx_extension_ControlPotentiometer_getMaximumValue, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("angleInDegreesBetweenLineFromPoint_toPoint_toLineFromPoint_toPoint", js_cocos2dx_extension_ControlPotentiometer_angleInDegreesBetweenLineFromPoint_toPoint_toLineFromPoint_toPoint, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("potentiometerBegan", js_cocos2dx_extension_ControlPotentiometer_potentiometerBegan, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setMaximumValue", js_cocos2dx_extension_ControlPotentiometer_setMaximumValue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getMinimumValue", js_cocos2dx_extension_ControlPotentiometer_getMinimumValue, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setThumbSprite", js_cocos2dx_extension_ControlPotentiometer_setThumbSprite, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getValue", js_cocos2dx_extension_ControlPotentiometer_getValue, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPreviousLocation", js_cocos2dx_extension_ControlPotentiometer_getPreviousLocation, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("distanceBetweenPointAndPoint", js_cocos2dx_extension_ControlPotentiometer_distanceBetweenPointAndPoint, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("potentiometerEnded", js_cocos2dx_extension_ControlPotentiometer_potentiometerEnded, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setProgressTimer", js_cocos2dx_extension_ControlPotentiometer_setProgressTimer, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setMinimumValue", js_cocos2dx_extension_ControlPotentiometer_setMinimumValue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getThumbSprite", js_cocos2dx_extension_ControlPotentiometer_getThumbSprite, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initWithTrackSprite_ProgressTimer_ThumbSprite", js_cocos2dx_extension_ControlPotentiometer_initWithTrackSprite_ProgressTimer_ThumbSprite, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("potentiometerMoved", js_cocos2dx_extension_ControlPotentiometer_potentiometerMoved, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_extension_ControlPotentiometer_create, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_cocos2d_extension_ControlPotentiometer_prototype = JS_InitClass(
		cx, global,
		jsb_cocos2d_extension_Control_prototype,
		jsb_cocos2d_extension_ControlPotentiometer_class,
		js_cocos2dx_extension_ControlPotentiometer_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "ControlPotentiometer", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::ControlPotentiometer> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_ControlPotentiometer_class;
		p->proto = jsb_cocos2d_extension_ControlPotentiometer_prototype;
		p->parentProto = jsb_cocos2d_extension_Control_prototype;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

JSClass  *jsb_cocos2d_extension_ControlSlider_class;
JSObject *jsb_cocos2d_extension_ControlSlider_prototype;

bool js_cocos2dx_extension_ControlSlider_getSelectedThumbSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_getSelectedThumbSprite : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Sprite* ret = cobj->getSelectedThumbSprite();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Sprite>(cx, (cocos2d::Sprite*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_getSelectedThumbSprite : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_locationFromTouch(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_locationFromTouch : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Touch* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Touch*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlSlider_locationFromTouch : Error processing arguments");
		cocos2d::Vec2 ret = cobj->locationFromTouch(arg0);
		jsval jsret = JSVAL_NULL;
		jsret = vector2_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_locationFromTouch : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_setSelectedThumbSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_setSelectedThumbSprite : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Sprite* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlSlider_setSelectedThumbSprite : Error processing arguments");
		cobj->setSelectedThumbSprite(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_setSelectedThumbSprite : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_setProgressSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_setProgressSprite : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Sprite* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlSlider_setProgressSprite : Error processing arguments");
		cobj->setProgressSprite(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_setProgressSprite : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_getMaximumAllowedValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_getMaximumAllowedValue : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getMaximumAllowedValue();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_getMaximumAllowedValue : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_getMinimumAllowedValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_getMinimumAllowedValue : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getMinimumAllowedValue();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_getMinimumAllowedValue : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_getMinimumValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_getMinimumValue : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getMinimumValue();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_getMinimumValue : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_setThumbSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_setThumbSprite : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Sprite* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlSlider_setThumbSprite : Error processing arguments");
		cobj->setThumbSprite(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_setThumbSprite : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_setMinimumValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_setMinimumValue : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlSlider_setMinimumValue : Error processing arguments");
		cobj->setMinimumValue(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_setMinimumValue : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_setMinimumAllowedValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_setMinimumAllowedValue : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlSlider_setMinimumAllowedValue : Error processing arguments");
		cobj->setMinimumAllowedValue(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_setMinimumAllowedValue : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_setEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_setEnabled : Invalid Native Object");
	if (argc == 1) {
		bool arg0;
		arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlSlider_setEnabled : Error processing arguments");
		cobj->setEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_setEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_setValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_setValue : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlSlider_setValue : Error processing arguments");
		cobj->setValue(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_setValue : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_setMaximumValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_setMaximumValue : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlSlider_setMaximumValue : Error processing arguments");
		cobj->setMaximumValue(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_setMaximumValue : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_needsLayout(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_needsLayout : Invalid Native Object");
	if (argc == 0) {
		cobj->needsLayout();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_needsLayout : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_getBackgroundSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_getBackgroundSprite : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Sprite* ret = cobj->getBackgroundSprite();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Sprite>(cx, (cocos2d::Sprite*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_getBackgroundSprite : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_initWithSprites(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;

	JSObject *obj = NULL;
	cocos2d::extension::ControlSlider* cobj = NULL;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_initWithSprites : Invalid Native Object");
	do {
		if (argc == 4) {
			cocos2d::Sprite* arg0;
			do {
				if (!argv[0].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg1;
			do {
				if (!argv[1].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg1 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg2;
			do {
				if (!argv[2].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[2]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg2 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg2, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg3;
			do {
				if (!argv[3].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[3]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg3 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg3, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			bool ret = cobj->initWithSprites(arg0, arg1, arg2, arg3);
			jsval jsret = JSVAL_NULL;
			jsret = BOOLEAN_TO_JSVAL(ret);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while(0);

	do {
		if (argc == 3) {
			cocos2d::Sprite* arg0;
			do {
				if (!argv[0].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg1;
			do {
				if (!argv[1].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg1 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg2;
			do {
				if (!argv[2].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[2]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg2 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg2, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			bool ret = cobj->initWithSprites(arg0, arg1, arg2);
			jsval jsret = JSVAL_NULL;
			jsret = BOOLEAN_TO_JSVAL(ret);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while(0);

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_initWithSprites : wrong number of arguments");
	return false;
}
bool js_cocos2dx_extension_ControlSlider_getMaximumValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_getMaximumValue : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getMaximumValue();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_getMaximumValue : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_isTouchInside(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_isTouchInside : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Touch* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Touch*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlSlider_isTouchInside : Error processing arguments");
		bool ret = cobj->isTouchInside(arg0);
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_isTouchInside : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_getValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_getValue : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getValue();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_getValue : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_getThumbSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_getThumbSprite : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Sprite* ret = cobj->getThumbSprite();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Sprite>(cx, (cocos2d::Sprite*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_getThumbSprite : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_getProgressSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_getProgressSprite : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Sprite* ret = cobj->getProgressSprite();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Sprite>(cx, (cocos2d::Sprite*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_getProgressSprite : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_setBackgroundSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_setBackgroundSprite : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Sprite* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlSlider_setBackgroundSprite : Error processing arguments");
		cobj->setBackgroundSprite(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_setBackgroundSprite : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_setMaximumAllowedValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSlider* cobj = (cocos2d::extension::ControlSlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSlider_setMaximumAllowedValue : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlSlider_setMaximumAllowedValue : Error processing arguments");
		cobj->setMaximumAllowedValue(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_setMaximumAllowedValue : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlSlider_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	
	do {
		if (argc == 3) {
			cocos2d::Sprite* arg0;
			do {
				if (!argv[0].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg1;
			do {
				if (!argv[1].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg1 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg2;
			do {
				if (!argv[2].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[2]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg2 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg2, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::extension::ControlSlider* ret = cocos2d::extension::ControlSlider::create(arg0, arg1, arg2);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ControlSlider>(cx, (cocos2d::extension::ControlSlider*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	
	do {
		if (argc == 3) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = true; break; }
			const char* arg1;
			std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
			if (!ok) { ok = true; break; }
			const char* arg2;
			std::string arg2_tmp; ok &= jsval_to_std_string(cx, argv[2], &arg2_tmp); arg2 = arg2_tmp.c_str();
			if (!ok) { ok = true; break; }
			cocos2d::extension::ControlSlider* ret = cocos2d::extension::ControlSlider::create(arg0, arg1, arg2);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ControlSlider>(cx, (cocos2d::extension::ControlSlider*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	
	do {
		if (argc == 4) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = true; break; }
			const char* arg1;
			std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
			if (!ok) { ok = true; break; }
			const char* arg2;
			std::string arg2_tmp; ok &= jsval_to_std_string(cx, argv[2], &arg2_tmp); arg2 = arg2_tmp.c_str();
			if (!ok) { ok = true; break; }
			const char* arg3;
			std::string arg3_tmp; ok &= jsval_to_std_string(cx, argv[3], &arg3_tmp); arg3 = arg3_tmp.c_str();
			if (!ok) { ok = true; break; }
			cocos2d::extension::ControlSlider* ret = cocos2d::extension::ControlSlider::create(arg0, arg1, arg2, arg3);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ControlSlider>(cx, (cocos2d::extension::ControlSlider*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	
	do {
		if (argc == 4) {
			cocos2d::Sprite* arg0;
			do {
				if (!argv[0].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg1;
			do {
				if (!argv[1].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg1 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg2;
			do {
				if (!argv[2].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[2]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg2 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg2, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg3;
			do {
				if (!argv[3].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[3]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg3 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg3, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::extension::ControlSlider* ret = cocos2d::extension::ControlSlider::create(arg0, arg1, arg2, arg3);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ControlSlider>(cx, (cocos2d::extension::ControlSlider*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	JS_ReportError(cx, "js_cocos2dx_extension_ControlSlider_create : wrong number of arguments");
	return false;
}
bool js_cocos2dx_extension_ControlSlider_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    cocos2d::extension::ControlSlider* cobj = new cocos2d::extension::ControlSlider();
    cocos2d::Ref *_ccobj = dynamic_cast<cocos2d::Ref *>(cobj);
    if (_ccobj) {
        _ccobj->autorelease();
    }
    TypeTest<cocos2d::extension::ControlSlider> t;
    js_type_class_t *typeClass = nullptr;
    std::string typeName = t.s_name();
    auto typeMapIter = _js_global_type_map.find(typeName);
    CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
    typeClass = typeMapIter->second;
    CCASSERT(typeClass, "The value is null.");
    JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
    // link the native object with the javascript object
    js_proxy_t* p = jsb_new_proxy(cobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::ControlSlider");
    if (JS_HasProperty(cx, obj, "_ctor", &ok))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    return true;
}


extern JSObject *jsb_cocos2d_extension_Control_prototype;

void js_cocos2d_extension_ControlSlider_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ControlSlider)", obj);
}

void js_register_cocos2dx_extension_ControlSlider(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_ControlSlider_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_ControlSlider_class->name = "ControlSlider";
	jsb_cocos2d_extension_ControlSlider_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ControlSlider_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_ControlSlider_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ControlSlider_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_ControlSlider_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_ControlSlider_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_ControlSlider_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_ControlSlider_class->finalize = js_cocos2d_extension_ControlSlider_finalize;
	jsb_cocos2d_extension_ControlSlider_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("getSelectedThumbSprite", js_cocos2dx_extension_ControlSlider_getSelectedThumbSprite, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("locationFromTouch", js_cocos2dx_extension_ControlSlider_locationFromTouch, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setSelectedThumbSprite", js_cocos2dx_extension_ControlSlider_setSelectedThumbSprite, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setProgressSprite", js_cocos2dx_extension_ControlSlider_setProgressSprite, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getMaximumAllowedValue", js_cocos2dx_extension_ControlSlider_getMaximumAllowedValue, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getMinimumAllowedValue", js_cocos2dx_extension_ControlSlider_getMinimumAllowedValue, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getMinimumValue", js_cocos2dx_extension_ControlSlider_getMinimumValue, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setThumbSprite", js_cocos2dx_extension_ControlSlider_setThumbSprite, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setMinimumValue", js_cocos2dx_extension_ControlSlider_setMinimumValue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setMinimumAllowedValue", js_cocos2dx_extension_ControlSlider_setMinimumAllowedValue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setEnabled", js_cocos2dx_extension_ControlSlider_setEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setValue", js_cocos2dx_extension_ControlSlider_setValue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setMaximumValue", js_cocos2dx_extension_ControlSlider_setMaximumValue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("needsLayout", js_cocos2dx_extension_ControlSlider_needsLayout, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getBackgroundSprite", js_cocos2dx_extension_ControlSlider_getBackgroundSprite, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initWithSprites", js_cocos2dx_extension_ControlSlider_initWithSprites, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getMaximumValue", js_cocos2dx_extension_ControlSlider_getMaximumValue, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isTouchInside", js_cocos2dx_extension_ControlSlider_isTouchInside, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getValue", js_cocos2dx_extension_ControlSlider_getValue, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getThumbSprite", js_cocos2dx_extension_ControlSlider_getThumbSprite, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getProgressSprite", js_cocos2dx_extension_ControlSlider_getProgressSprite, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBackgroundSprite", js_cocos2dx_extension_ControlSlider_setBackgroundSprite, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setMaximumAllowedValue", js_cocos2dx_extension_ControlSlider_setMaximumAllowedValue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_extension_ControlSlider_create, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_cocos2d_extension_ControlSlider_prototype = JS_InitClass(
		cx, global,
		jsb_cocos2d_extension_Control_prototype,
		jsb_cocos2d_extension_ControlSlider_class,
		js_cocos2dx_extension_ControlSlider_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "ControlSlider", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::ControlSlider> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_ControlSlider_class;
		p->proto = jsb_cocos2d_extension_ControlSlider_prototype;
		p->parentProto = jsb_cocos2d_extension_Control_prototype;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

JSClass  *jsb_cocos2d_extension_ControlStepper_class;
JSObject *jsb_cocos2d_extension_ControlStepper_prototype;

bool js_cocos2dx_extension_ControlStepper_setMinusSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_setMinusSprite : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Sprite* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlStepper_setMinusSprite : Error processing arguments");
		cobj->setMinusSprite(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_setMinusSprite : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_getMinusLabel(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_getMinusLabel : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Label* ret = cobj->getMinusLabel();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Label>(cx, (cocos2d::Label*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_getMinusLabel : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_setWraps(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_setWraps : Invalid Native Object");
	if (argc == 1) {
		bool arg0;
		arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlStepper_setWraps : Error processing arguments");
		cobj->setWraps(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_setWraps : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_isContinuous(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_isContinuous : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isContinuous();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_isContinuous : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_getMinusSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_getMinusSprite : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Sprite* ret = cobj->getMinusSprite();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Sprite>(cx, (cocos2d::Sprite*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_getMinusSprite : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_updateLayoutUsingTouchLocation(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_updateLayoutUsingTouchLocation : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Vec2 arg0;
		ok &= jsval_to_vector2(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlStepper_updateLayoutUsingTouchLocation : Error processing arguments");
		cobj->updateLayoutUsingTouchLocation(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_updateLayoutUsingTouchLocation : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_setValueWithSendingEvent(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_setValueWithSendingEvent : Invalid Native Object");
	if (argc == 2) {
		double arg0;
		bool arg1;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		arg1 = JS::ToBoolean(JS::RootedValue(cx, argv[1]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlStepper_setValueWithSendingEvent : Error processing arguments");
		cobj->setValueWithSendingEvent(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_setValueWithSendingEvent : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_getPlusLabel(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_getPlusLabel : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Label* ret = cobj->getPlusLabel();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Label>(cx, (cocos2d::Label*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_getPlusLabel : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_stopAutorepeat(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_stopAutorepeat : Invalid Native Object");
	if (argc == 0) {
		cobj->stopAutorepeat();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_stopAutorepeat : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_setMinimumValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_setMinimumValue : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlStepper_setMinimumValue : Error processing arguments");
		cobj->setMinimumValue(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_setMinimumValue : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_getPlusSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_getPlusSprite : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Sprite* ret = cobj->getPlusSprite();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Sprite>(cx, (cocos2d::Sprite*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_getPlusSprite : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_setPlusSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_setPlusSprite : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Sprite* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlStepper_setPlusSprite : Error processing arguments");
		cobj->setPlusSprite(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_setPlusSprite : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_setMinusLabel(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_setMinusLabel : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Label* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Label*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlStepper_setMinusLabel : Error processing arguments");
		cobj->setMinusLabel(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_setMinusLabel : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_setValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_setValue : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlStepper_setValue : Error processing arguments");
		cobj->setValue(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_setValue : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_setStepValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_setStepValue : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlStepper_setStepValue : Error processing arguments");
		cobj->setStepValue(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_setStepValue : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_setMaximumValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_setMaximumValue : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlStepper_setMaximumValue : Error processing arguments");
		cobj->setMaximumValue(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_setMaximumValue : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_update(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_update : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlStepper_update : Error processing arguments");
		cobj->update(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_update : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_startAutorepeat(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_startAutorepeat : Invalid Native Object");
	if (argc == 0) {
		cobj->startAutorepeat();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_startAutorepeat : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_initWithMinusSpriteAndPlusSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_initWithMinusSpriteAndPlusSprite : Invalid Native Object");
	if (argc == 2) {
		cocos2d::Sprite* arg0;
		cocos2d::Sprite* arg1;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		do {
			if (!argv[1].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg1 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlStepper_initWithMinusSpriteAndPlusSprite : Error processing arguments");
		bool ret = cobj->initWithMinusSpriteAndPlusSprite(arg0, arg1);
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_initWithMinusSpriteAndPlusSprite : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_getValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_getValue : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getValue();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_getValue : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_setPlusLabel(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlStepper* cobj = (cocos2d::extension::ControlStepper *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlStepper_setPlusLabel : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Label* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Label*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlStepper_setPlusLabel : Error processing arguments");
		cobj->setPlusLabel(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_setPlusLabel : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlStepper_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	if (argc == 2) {
		cocos2d::Sprite* arg0;
		cocos2d::Sprite* arg1;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		do {
			if (!argv[1].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg1 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlStepper_create : Error processing arguments");
		cocos2d::extension::ControlStepper* ret = cocos2d::extension::ControlStepper::create(arg0, arg1);
		jsval jsret = JSVAL_NULL;
		do {
		if (ret) {
			js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ControlStepper>(cx, (cocos2d::extension::ControlStepper*)ret);
			jsret = OBJECT_TO_JSVAL(jsProxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
	JS_ReportError(cx, "js_cocos2dx_extension_ControlStepper_create : wrong number of arguments");
	return false;
}

bool js_cocos2dx_extension_ControlStepper_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    cocos2d::extension::ControlStepper* cobj = new cocos2d::extension::ControlStepper();
    cocos2d::Ref *_ccobj = dynamic_cast<cocos2d::Ref *>(cobj);
    if (_ccobj) {
        _ccobj->autorelease();
    }
    TypeTest<cocos2d::extension::ControlStepper> t;
    js_type_class_t *typeClass = nullptr;
    std::string typeName = t.s_name();
    auto typeMapIter = _js_global_type_map.find(typeName);
    CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
    typeClass = typeMapIter->second;
    CCASSERT(typeClass, "The value is null.");
    JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
    // link the native object with the javascript object
    js_proxy_t* p = jsb_new_proxy(cobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::ControlStepper");
    if (JS_HasProperty(cx, obj, "_ctor", &ok))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    return true;
}


extern JSObject *jsb_cocos2d_extension_Control_prototype;

void js_cocos2d_extension_ControlStepper_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ControlStepper)", obj);
}

void js_register_cocos2dx_extension_ControlStepper(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_ControlStepper_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_ControlStepper_class->name = "ControlStepper";
	jsb_cocos2d_extension_ControlStepper_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ControlStepper_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_ControlStepper_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ControlStepper_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_ControlStepper_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_ControlStepper_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_ControlStepper_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_ControlStepper_class->finalize = js_cocos2d_extension_ControlStepper_finalize;
	jsb_cocos2d_extension_ControlStepper_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setMinusSprite", js_cocos2dx_extension_ControlStepper_setMinusSprite, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getMinusLabel", js_cocos2dx_extension_ControlStepper_getMinusLabel, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setWraps", js_cocos2dx_extension_ControlStepper_setWraps, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isContinuous", js_cocos2dx_extension_ControlStepper_isContinuous, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getMinusSprite", js_cocos2dx_extension_ControlStepper_getMinusSprite, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("updateLayoutUsingTouchLocation", js_cocos2dx_extension_ControlStepper_updateLayoutUsingTouchLocation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setValueWithSendingEvent", js_cocos2dx_extension_ControlStepper_setValueWithSendingEvent, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPlusLabel", js_cocos2dx_extension_ControlStepper_getPlusLabel, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("stopAutorepeat", js_cocos2dx_extension_ControlStepper_stopAutorepeat, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setMinimumValue", js_cocos2dx_extension_ControlStepper_setMinimumValue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPlusSprite", js_cocos2dx_extension_ControlStepper_getPlusSprite, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPlusSprite", js_cocos2dx_extension_ControlStepper_setPlusSprite, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setMinusLabel", js_cocos2dx_extension_ControlStepper_setMinusLabel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setValue", js_cocos2dx_extension_ControlStepper_setValue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setStepValue", js_cocos2dx_extension_ControlStepper_setStepValue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setMaximumValue", js_cocos2dx_extension_ControlStepper_setMaximumValue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("update", js_cocos2dx_extension_ControlStepper_update, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("startAutorepeat", js_cocos2dx_extension_ControlStepper_startAutorepeat, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initWithMinusSpriteAndPlusSprite", js_cocos2dx_extension_ControlStepper_initWithMinusSpriteAndPlusSprite, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getValue", js_cocos2dx_extension_ControlStepper_getValue, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPlusLabel", js_cocos2dx_extension_ControlStepper_setPlusLabel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_extension_ControlStepper_create, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_cocos2d_extension_ControlStepper_prototype = JS_InitClass(
		cx, global,
		jsb_cocos2d_extension_Control_prototype,
		jsb_cocos2d_extension_ControlStepper_class,
		js_cocos2dx_extension_ControlStepper_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "ControlStepper", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::ControlStepper> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_ControlStepper_class;
		p->proto = jsb_cocos2d_extension_ControlStepper_prototype;
		p->parentProto = jsb_cocos2d_extension_Control_prototype;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

JSClass  *jsb_cocos2d_extension_ControlSwitch_class;
JSObject *jsb_cocos2d_extension_ControlSwitch_prototype;

bool js_cocos2dx_extension_ControlSwitch_setEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSwitch* cobj = (cocos2d::extension::ControlSwitch *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSwitch_setEnabled : Invalid Native Object");
	if (argc == 1) {
		bool arg0;
		arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlSwitch_setEnabled : Error processing arguments");
		cobj->setEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSwitch_setEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlSwitch_setOn(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;

	JSObject *obj = NULL;
	cocos2d::extension::ControlSwitch* cobj = NULL;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cobj = (cocos2d::extension::ControlSwitch *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSwitch_setOn : Invalid Native Object");
	do {
		if (argc == 1) {
			bool arg0;
			arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
			cobj->setOn(arg0);
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return true;
		}
	} while(0);

	do {
		if (argc == 2) {
			bool arg0;
			arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
			bool arg1;
			arg1 = JS::ToBoolean(JS::RootedValue(cx, argv[1]));
			cobj->setOn(arg0, arg1);
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return true;
		}
	} while(0);

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSwitch_setOn : wrong number of arguments");
	return false;
}
bool js_cocos2dx_extension_ControlSwitch_isOn(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSwitch* cobj = (cocos2d::extension::ControlSwitch *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSwitch_isOn : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isOn();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSwitch_isOn : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSwitch_initWithMaskSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;

	JSObject *obj = NULL;
	cocos2d::extension::ControlSwitch* cobj = NULL;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cobj = (cocos2d::extension::ControlSwitch *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSwitch_initWithMaskSprite : Invalid Native Object");
	do {
		if (argc == 6) {
			cocos2d::Sprite* arg0;
			do {
				if (!argv[0].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg1;
			do {
				if (!argv[1].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg1 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg2;
			do {
				if (!argv[2].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[2]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg2 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg2, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg3;
			do {
				if (!argv[3].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[3]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg3 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg3, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Label* arg4;
			do {
				if (!argv[4].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[4]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg4 = (cocos2d::Label*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg4, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Label* arg5;
			do {
				if (!argv[5].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[5]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg5 = (cocos2d::Label*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg5, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			bool ret = cobj->initWithMaskSprite(arg0, arg1, arg2, arg3, arg4, arg5);
			jsval jsret = JSVAL_NULL;
			jsret = BOOLEAN_TO_JSVAL(ret);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while(0);

	do {
		if (argc == 4) {
			cocos2d::Sprite* arg0;
			do {
				if (!argv[0].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg1;
			do {
				if (!argv[1].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg1 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg2;
			do {
				if (!argv[2].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[2]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg2 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg2, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg3;
			do {
				if (!argv[3].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[3]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg3 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg3, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			bool ret = cobj->initWithMaskSprite(arg0, arg1, arg2, arg3);
			jsval jsret = JSVAL_NULL;
			jsret = BOOLEAN_TO_JSVAL(ret);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while(0);

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSwitch_initWithMaskSprite : wrong number of arguments");
	return false;
}
bool js_cocos2dx_extension_ControlSwitch_hasMoved(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSwitch* cobj = (cocos2d::extension::ControlSwitch *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSwitch_hasMoved : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->hasMoved();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSwitch_hasMoved : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ControlSwitch_locationFromTouch(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ControlSwitch* cobj = (cocos2d::extension::ControlSwitch *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ControlSwitch_locationFromTouch : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Touch* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Touch*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ControlSwitch_locationFromTouch : Error processing arguments");
		cocos2d::Vec2 ret = cobj->locationFromTouch(arg0);
		jsval jsret = JSVAL_NULL;
		jsret = vector2_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ControlSwitch_locationFromTouch : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ControlSwitch_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	
	do {
		if (argc == 4) {
			cocos2d::Sprite* arg0;
			do {
				if (!argv[0].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg1;
			do {
				if (!argv[1].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg1 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg2;
			do {
				if (!argv[2].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[2]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg2 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg2, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg3;
			do {
				if (!argv[3].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[3]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg3 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg3, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::extension::ControlSwitch* ret = cocos2d::extension::ControlSwitch::create(arg0, arg1, arg2, arg3);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ControlSwitch>(cx, (cocos2d::extension::ControlSwitch*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	
	do {
		if (argc == 6) {
			cocos2d::Sprite* arg0;
			do {
				if (!argv[0].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg0 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg1;
			do {
				if (!argv[1].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg1 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg2;
			do {
				if (!argv[2].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[2]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg2 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg2, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Sprite* arg3;
			do {
				if (!argv[3].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[3]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg3 = (cocos2d::Sprite*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg3, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Label* arg4;
			do {
				if (!argv[4].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[4]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg4 = (cocos2d::Label*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg4, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::Label* arg5;
			do {
				if (!argv[5].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[5]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg5 = (cocos2d::Label*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg5, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::extension::ControlSwitch* ret = cocos2d::extension::ControlSwitch::create(arg0, arg1, arg2, arg3, arg4, arg5);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ControlSwitch>(cx, (cocos2d::extension::ControlSwitch*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	JS_ReportError(cx, "js_cocos2dx_extension_ControlSwitch_create : wrong number of arguments");
	return false;
}
bool js_cocos2dx_extension_ControlSwitch_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    cocos2d::extension::ControlSwitch* cobj = new cocos2d::extension::ControlSwitch();
    cocos2d::Ref *_ccobj = dynamic_cast<cocos2d::Ref *>(cobj);
    if (_ccobj) {
        _ccobj->autorelease();
    }
    TypeTest<cocos2d::extension::ControlSwitch> t;
    js_type_class_t *typeClass = nullptr;
    std::string typeName = t.s_name();
    auto typeMapIter = _js_global_type_map.find(typeName);
    CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
    typeClass = typeMapIter->second;
    CCASSERT(typeClass, "The value is null.");
    JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
    // link the native object with the javascript object
    js_proxy_t* p = jsb_new_proxy(cobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::ControlSwitch");
    if (JS_HasProperty(cx, obj, "_ctor", &ok))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    return true;
}


extern JSObject *jsb_cocos2d_extension_Control_prototype;

void js_cocos2d_extension_ControlSwitch_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ControlSwitch)", obj);
}

void js_register_cocos2dx_extension_ControlSwitch(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_ControlSwitch_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_ControlSwitch_class->name = "ControlSwitch";
	jsb_cocos2d_extension_ControlSwitch_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ControlSwitch_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_ControlSwitch_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ControlSwitch_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_ControlSwitch_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_ControlSwitch_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_ControlSwitch_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_ControlSwitch_class->finalize = js_cocos2d_extension_ControlSwitch_finalize;
	jsb_cocos2d_extension_ControlSwitch_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setEnabled", js_cocos2dx_extension_ControlSwitch_setEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setOn", js_cocos2dx_extension_ControlSwitch_setOn, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isOn", js_cocos2dx_extension_ControlSwitch_isOn, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initWithMaskSprite", js_cocos2dx_extension_ControlSwitch_initWithMaskSprite, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("hasMoved", js_cocos2dx_extension_ControlSwitch_hasMoved, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("locationFromTouch", js_cocos2dx_extension_ControlSwitch_locationFromTouch, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_extension_ControlSwitch_create, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_cocos2d_extension_ControlSwitch_prototype = JS_InitClass(
		cx, global,
		jsb_cocos2d_extension_Control_prototype,
		jsb_cocos2d_extension_ControlSwitch_class,
		js_cocos2dx_extension_ControlSwitch_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "ControlSwitch", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::ControlSwitch> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_ControlSwitch_class;
		p->proto = jsb_cocos2d_extension_ControlSwitch_prototype;
		p->parentProto = jsb_cocos2d_extension_Control_prototype;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

JSClass  *jsb_cocos2d_extension_ScrollView_class;
JSObject *jsb_cocos2d_extension_ScrollView_prototype;

bool js_cocos2dx_extension_ScrollView_isClippingToBounds(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_isClippingToBounds : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isClippingToBounds();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_isClippingToBounds : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ScrollView_setContainer(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_setContainer : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Node* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ScrollView_setContainer : Error processing arguments");
		cobj->setContainer(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_setContainer : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ScrollView_setContentOffsetInDuration(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_setContentOffsetInDuration : Invalid Native Object");
	if (argc == 2) {
		cocos2d::Vec2 arg0;
		double arg1;
		ok &= jsval_to_vector2(cx, argv[0], &arg0);
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[1]), &arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ScrollView_setContentOffsetInDuration : Error processing arguments");
		cobj->setContentOffsetInDuration(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_setContentOffsetInDuration : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ScrollView_setZoomScaleInDuration(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_setZoomScaleInDuration : Invalid Native Object");
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[1]), &arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ScrollView_setZoomScaleInDuration : Error processing arguments");
		cobj->setZoomScaleInDuration(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_setZoomScaleInDuration : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ScrollView_setBounceable(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_setBounceable : Invalid Native Object");
	if (argc == 1) {
		bool arg0;
		arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ScrollView_setBounceable : Error processing arguments");
		cobj->setBounceable(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_setBounceable : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ScrollView_getDirection(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_getDirection : Invalid Native Object");
	if (argc == 0) {
		int ret = (int)cobj->getDirection();
		jsval jsret = JSVAL_NULL;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_getDirection : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ScrollView_getContainer(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_getContainer : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Node* ret = cobj->getContainer();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Node>(cx, (cocos2d::Node*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_getContainer : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ScrollView_updateTweenAction(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_updateTweenAction : Invalid Native Object");
	if (argc == 2) {
		double arg0;
		std::string arg1;
		ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
		ok &= jsval_to_std_string(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ScrollView_updateTweenAction : Error processing arguments");
		cobj->updateTweenAction(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_updateTweenAction : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_ScrollView_getZoomScale(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_getZoomScale : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getZoomScale();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_getZoomScale : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ScrollView_updateInset(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_updateInset : Invalid Native Object");
	if (argc == 0) {
		cobj->updateInset();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_updateInset : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ScrollView_initWithViewSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_initWithViewSize : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Size arg0;
		ok &= jsval_to_ccsize(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ScrollView_initWithViewSize : Error processing arguments");
		bool ret = cobj->initWithViewSize(arg0);
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
	if (argc == 2) {
		cocos2d::Size arg0;
		cocos2d::Node* arg1;
		ok &= jsval_to_ccsize(cx, argv[0], &arg0);
		do {
			if (!argv[1].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg1 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ScrollView_initWithViewSize : Error processing arguments");
		bool ret = cobj->initWithViewSize(arg0, arg1);
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_initWithViewSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ScrollView_pause(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_pause : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Ref* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Ref*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ScrollView_pause : Error processing arguments");
		cobj->pause(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_pause : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ScrollView_setDirection(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_setDirection : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::ScrollView::Direction arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ScrollView_setDirection : Error processing arguments");
		cobj->setDirection(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_setDirection : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ScrollView_init(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_init : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->init();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_init : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ScrollView_setContentOffset(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_setContentOffset : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Vec2 arg0;
		ok &= jsval_to_vector2(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ScrollView_setContentOffset : Error processing arguments");
		cobj->setContentOffset(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}
	if (argc == 2) {
		cocos2d::Vec2 arg0;
		bool arg1;
		ok &= jsval_to_vector2(cx, argv[0], &arg0);
		arg1 = JS::ToBoolean(JS::RootedValue(cx, argv[1]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ScrollView_setContentOffset : Error processing arguments");
		cobj->setContentOffset(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_setContentOffset : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ScrollView_isDragging(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_isDragging : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isDragging();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_isDragging : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ScrollView_isTouchEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_isTouchEnabled : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isTouchEnabled();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_isTouchEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ScrollView_isBounceable(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_isBounceable : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isBounceable();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_isBounceable : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ScrollView_setTouchEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_setTouchEnabled : Invalid Native Object");
	if (argc == 1) {
		bool arg0;
		arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ScrollView_setTouchEnabled : Error processing arguments");
		cobj->setTouchEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_setTouchEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ScrollView_getContentOffset(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_getContentOffset : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Vec2 ret = cobj->getContentOffset();
		jsval jsret = JSVAL_NULL;
		jsret = vector2_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_getContentOffset : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ScrollView_resume(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_resume : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Ref* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Ref*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ScrollView_resume : Error processing arguments");
		cobj->resume(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_resume : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ScrollView_setClippingToBounds(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_setClippingToBounds : Invalid Native Object");
	if (argc == 1) {
		bool arg0;
		arg0 = JS::ToBoolean(JS::RootedValue(cx, argv[0]));
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ScrollView_setClippingToBounds : Error processing arguments");
		cobj->setClippingToBounds(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_setClippingToBounds : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ScrollView_setViewSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_setViewSize : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Size arg0;
		ok &= jsval_to_ccsize(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ScrollView_setViewSize : Error processing arguments");
		cobj->setViewSize(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_setViewSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ScrollView_getViewSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_getViewSize : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Size ret = cobj->getViewSize();
		jsval jsret = JSVAL_NULL;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_getViewSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ScrollView_maxContainerOffset(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_maxContainerOffset : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Vec2 ret = cobj->maxContainerOffset();
		jsval jsret = JSVAL_NULL;
		jsret = vector2_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_maxContainerOffset : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ScrollView_isTouchMoved(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_isTouchMoved : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isTouchMoved();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_isTouchMoved : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ScrollView_isNodeVisible(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_isNodeVisible : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Node* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_ScrollView_isNodeVisible : Error processing arguments");
		bool ret = cobj->isNodeVisible(arg0);
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_isNodeVisible : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_ScrollView_minContainerOffset(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::ScrollView* cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_minContainerOffset : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Vec2 ret = cobj->minContainerOffset();
		jsval jsret = JSVAL_NULL;
		jsret = vector2_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_minContainerOffset : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_ScrollView_setZoomScale(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;

	JSObject *obj = NULL;
	cocos2d::extension::ScrollView* cobj = NULL;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cobj = (cocos2d::extension::ScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_ScrollView_setZoomScale : Invalid Native Object");
	do {
		if (argc == 2) {
			double arg0;
			ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
			if (!ok) { ok = true; break; }
			bool arg1;
			arg1 = JS::ToBoolean(JS::RootedValue(cx, argv[1]));
			cobj->setZoomScale(arg0, arg1);
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return true;
		}
	} while(0);

	do {
		if (argc == 1) {
			double arg0;
			ok &= JS::ToNumber( cx, JS::RootedValue(cx, argv[0]), &arg0);
			if (!ok) { ok = true; break; }
			cobj->setZoomScale(arg0);
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return true;
		}
	} while(0);

	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_setZoomScale : wrong number of arguments");
	return false;
}
bool js_cocos2dx_extension_ScrollView_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	
	do {
		if (argc == 0) {
			cocos2d::extension::ScrollView* ret = cocos2d::extension::ScrollView::create();
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ScrollView>(cx, (cocos2d::extension::ScrollView*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	
	do {
		if (argc == 1) {
			cocos2d::Size arg0;
			ok &= jsval_to_ccsize(cx, argv[0], &arg0);
			if (!ok) { ok = true; break; }
			cocos2d::extension::ScrollView* ret = cocos2d::extension::ScrollView::create(arg0);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ScrollView>(cx, (cocos2d::extension::ScrollView*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	do {
		if (argc == 2) {
			cocos2d::Size arg0;
			ok &= jsval_to_ccsize(cx, argv[0], &arg0);
			if (!ok) { ok = true; break; }
			cocos2d::Node* arg1;
			do {
				if (!argv[1].isObject()) { ok = false; break; }
				js_proxy_t *jsProxy;
				JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
				jsProxy = jsb_get_js_proxy(tmpObj);
				arg1 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
				JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
			} while (0);
			if (!ok) { ok = true; break; }
			cocos2d::extension::ScrollView* ret = cocos2d::extension::ScrollView::create(arg0, arg1);
			jsval jsret = JSVAL_NULL;
			do {
				if (ret) {
					js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::ScrollView>(cx, (cocos2d::extension::ScrollView*)ret);
					jsret = OBJECT_TO_JSVAL(jsProxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return true;
		}
	} while (0);
	JS_ReportError(cx, "js_cocos2dx_extension_ScrollView_create : wrong number of arguments");
	return false;
}
bool js_cocos2dx_extension_ScrollView_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    cocos2d::extension::ScrollView* cobj = new cocos2d::extension::ScrollView();
    cocos2d::Ref *_ccobj = dynamic_cast<cocos2d::Ref *>(cobj);
    if (_ccobj) {
        _ccobj->autorelease();
    }
    TypeTest<cocos2d::extension::ScrollView> t;
    js_type_class_t *typeClass = nullptr;
    std::string typeName = t.s_name();
    auto typeMapIter = _js_global_type_map.find(typeName);
    CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
    typeClass = typeMapIter->second;
    CCASSERT(typeClass, "The value is null.");
    JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
    // link the native object with the javascript object
    js_proxy_t* p = jsb_new_proxy(cobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::ScrollView");
    if (JS_HasProperty(cx, obj, "_ctor", &ok))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    return true;
}


extern JSObject *jsb_cocos2d_Layer_prototype;

void js_cocos2d_extension_ScrollView_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ScrollView)", obj);
}

static bool js_cocos2d_extension_ScrollView_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    cocos2d::extension::ScrollView *nobj = new cocos2d::extension::ScrollView();
    if (nobj) {
        nobj->autorelease();
    }
    js_proxy_t* p = jsb_new_proxy(nobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::ScrollView");
    bool isFound = false;
    if (JS_HasProperty(cx, obj, "_ctor", &isFound))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return true;
}
void js_register_cocos2dx_extension_ScrollView(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_ScrollView_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_ScrollView_class->name = "ScrollView";
	jsb_cocos2d_extension_ScrollView_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ScrollView_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_ScrollView_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_ScrollView_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_ScrollView_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_ScrollView_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_ScrollView_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_ScrollView_class->finalize = js_cocos2d_extension_ScrollView_finalize;
	jsb_cocos2d_extension_ScrollView_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("isClippingToBounds", js_cocos2dx_extension_ScrollView_isClippingToBounds, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setContainer", js_cocos2dx_extension_ScrollView_setContainer, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setContentOffsetInDuration", js_cocos2dx_extension_ScrollView_setContentOffsetInDuration, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setZoomScaleInDuration", js_cocos2dx_extension_ScrollView_setZoomScaleInDuration, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBounceable", js_cocos2dx_extension_ScrollView_setBounceable, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDirection", js_cocos2dx_extension_ScrollView_getDirection, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getContainer", js_cocos2dx_extension_ScrollView_getContainer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("updateTweenAction", js_cocos2dx_extension_ScrollView_updateTweenAction, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getZoomScale", js_cocos2dx_extension_ScrollView_getZoomScale, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("updateInset", js_cocos2dx_extension_ScrollView_updateInset, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initWithViewSize", js_cocos2dx_extension_ScrollView_initWithViewSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("pause", js_cocos2dx_extension_ScrollView_pause, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setDirection", js_cocos2dx_extension_ScrollView_setDirection, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("init", js_cocos2dx_extension_ScrollView_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setContentOffset", js_cocos2dx_extension_ScrollView_setContentOffset, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isDragging", js_cocos2dx_extension_ScrollView_isDragging, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isTouchEnabled", js_cocos2dx_extension_ScrollView_isTouchEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isBounceable", js_cocos2dx_extension_ScrollView_isBounceable, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTouchEnabled", js_cocos2dx_extension_ScrollView_setTouchEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getContentOffset", js_cocos2dx_extension_ScrollView_getContentOffset, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("resume", js_cocos2dx_extension_ScrollView_resume, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setClippingToBounds", js_cocos2dx_extension_ScrollView_setClippingToBounds, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setViewSize", js_cocos2dx_extension_ScrollView_setViewSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getViewSize", js_cocos2dx_extension_ScrollView_getViewSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("maxContainerOffset", js_cocos2dx_extension_ScrollView_maxContainerOffset, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isTouchMoved", js_cocos2dx_extension_ScrollView_isTouchMoved, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isNodeVisible", js_cocos2dx_extension_ScrollView_isNodeVisible, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("minContainerOffset", js_cocos2dx_extension_ScrollView_minContainerOffset, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setZoomScale", js_cocos2dx_extension_ScrollView_setZoomScale, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_cocos2d_extension_ScrollView_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_extension_ScrollView_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_cocos2d_extension_ScrollView_prototype = JS_InitClass(
		cx, global,
		jsb_cocos2d_Layer_prototype,
		jsb_cocos2d_extension_ScrollView_class,
		js_cocos2dx_extension_ScrollView_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "ScrollView", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::ScrollView> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_ScrollView_class;
		p->proto = jsb_cocos2d_extension_ScrollView_prototype;
		p->parentProto = jsb_cocos2d_Layer_prototype;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

JSClass  *jsb_cocos2d_extension_TableViewCell_class;
JSObject *jsb_cocos2d_extension_TableViewCell_prototype;

bool js_cocos2dx_extension_TableViewCell_reset(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::TableViewCell* cobj = (cocos2d::extension::TableViewCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_TableViewCell_reset : Invalid Native Object");
	if (argc == 0) {
		cobj->reset();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_TableViewCell_reset : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_TableViewCell_getIdx(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::TableViewCell* cobj = (cocos2d::extension::TableViewCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_TableViewCell_getIdx : Invalid Native Object");
	if (argc == 0) {
		ssize_t ret = cobj->getIdx();
		jsval jsret = JSVAL_NULL;
		jsret = ssize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_TableViewCell_getIdx : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_TableViewCell_setIdx(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::TableViewCell* cobj = (cocos2d::extension::TableViewCell *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_TableViewCell_setIdx : Invalid Native Object");
	if (argc == 1) {
		ssize_t arg0;
		ok &= jsval_to_ssize(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_TableViewCell_setIdx : Error processing arguments");
		cobj->setIdx(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_TableViewCell_setIdx : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_TableViewCell_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		cocos2d::extension::TableViewCell* ret = cocos2d::extension::TableViewCell::create();
		jsval jsret = JSVAL_NULL;
		do {
		if (ret) {
			js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::TableViewCell>(cx, (cocos2d::extension::TableViewCell*)ret);
			jsret = OBJECT_TO_JSVAL(jsProxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
	JS_ReportError(cx, "js_cocos2dx_extension_TableViewCell_create : wrong number of arguments");
	return false;
}

bool js_cocos2dx_extension_TableViewCell_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    cocos2d::extension::TableViewCell* cobj = new cocos2d::extension::TableViewCell();
    cocos2d::Ref *_ccobj = dynamic_cast<cocos2d::Ref *>(cobj);
    if (_ccobj) {
        _ccobj->autorelease();
    }
    TypeTest<cocos2d::extension::TableViewCell> t;
    js_type_class_t *typeClass = nullptr;
    std::string typeName = t.s_name();
    auto typeMapIter = _js_global_type_map.find(typeName);
    CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
    typeClass = typeMapIter->second;
    CCASSERT(typeClass, "The value is null.");
    JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
    // link the native object with the javascript object
    js_proxy_t* p = jsb_new_proxy(cobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::TableViewCell");
    if (JS_HasProperty(cx, obj, "_ctor", &ok))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    return true;
}


extern JSObject *jsb_cocos2d_Node_prototype;

void js_cocos2d_extension_TableViewCell_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (TableViewCell)", obj);
}

static bool js_cocos2d_extension_TableViewCell_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    cocos2d::extension::TableViewCell *nobj = new cocos2d::extension::TableViewCell();
    if (nobj) {
        nobj->autorelease();
    }
    js_proxy_t* p = jsb_new_proxy(nobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::TableViewCell");
    bool isFound = false;
    if (JS_HasProperty(cx, obj, "_ctor", &isFound))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return true;
}
void js_register_cocos2dx_extension_TableViewCell(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_TableViewCell_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_TableViewCell_class->name = "TableViewCell";
	jsb_cocos2d_extension_TableViewCell_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_TableViewCell_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_TableViewCell_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_TableViewCell_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_TableViewCell_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_TableViewCell_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_TableViewCell_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_TableViewCell_class->finalize = js_cocos2d_extension_TableViewCell_finalize;
	jsb_cocos2d_extension_TableViewCell_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("reset", js_cocos2dx_extension_TableViewCell_reset, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getIdx", js_cocos2dx_extension_TableViewCell_getIdx, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setIdx", js_cocos2dx_extension_TableViewCell_setIdx, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_cocos2d_extension_TableViewCell_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_extension_TableViewCell_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_cocos2d_extension_TableViewCell_prototype = JS_InitClass(
		cx, global,
		jsb_cocos2d_Node_prototype,
		jsb_cocos2d_extension_TableViewCell_class,
		js_cocos2dx_extension_TableViewCell_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "TableViewCell", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::TableViewCell> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_TableViewCell_class;
		p->proto = jsb_cocos2d_extension_TableViewCell_prototype;
		p->parentProto = jsb_cocos2d_Node_prototype;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

JSClass  *jsb_cocos2d_extension_TableView_class;
JSObject *jsb_cocos2d_extension_TableView_prototype;

bool js_cocos2dx_extension_TableView_updateCellAtIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::TableView* cobj = (cocos2d::extension::TableView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_TableView_updateCellAtIndex : Invalid Native Object");
	if (argc == 1) {
		ssize_t arg0;
		ok &= jsval_to_ssize(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_TableView_updateCellAtIndex : Error processing arguments");
		cobj->updateCellAtIndex(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_TableView_updateCellAtIndex : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_TableView_setVerticalFillOrder(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::TableView* cobj = (cocos2d::extension::TableView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_TableView_setVerticalFillOrder : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::TableView::VerticalFillOrder arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_TableView_setVerticalFillOrder : Error processing arguments");
		cobj->setVerticalFillOrder(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_TableView_setVerticalFillOrder : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_TableView_scrollViewDidZoom(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::TableView* cobj = (cocos2d::extension::TableView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_TableView_scrollViewDidZoom : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::ScrollView* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::extension::ScrollView*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_TableView_scrollViewDidZoom : Error processing arguments");
		cobj->scrollViewDidZoom(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_TableView_scrollViewDidZoom : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_TableView__updateContentSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::TableView* cobj = (cocos2d::extension::TableView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_TableView__updateContentSize : Invalid Native Object");
	if (argc == 0) {
		cobj->_updateContentSize();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_TableView__updateContentSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_TableView_getVerticalFillOrder(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::TableView* cobj = (cocos2d::extension::TableView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_TableView_getVerticalFillOrder : Invalid Native Object");
	if (argc == 0) {
		int ret = (int)cobj->getVerticalFillOrder();
		jsval jsret = JSVAL_NULL;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_TableView_getVerticalFillOrder : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_TableView_removeCellAtIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::TableView* cobj = (cocos2d::extension::TableView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_TableView_removeCellAtIndex : Invalid Native Object");
	if (argc == 1) {
		ssize_t arg0;
		ok &= jsval_to_ssize(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_TableView_removeCellAtIndex : Error processing arguments");
		cobj->removeCellAtIndex(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_TableView_removeCellAtIndex : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_TableView_initWithViewSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::TableView* cobj = (cocos2d::extension::TableView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_TableView_initWithViewSize : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Size arg0;
		ok &= jsval_to_ccsize(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_TableView_initWithViewSize : Error processing arguments");
		bool ret = cobj->initWithViewSize(arg0);
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
	if (argc == 2) {
		cocos2d::Size arg0;
		cocos2d::Node* arg1;
		ok &= jsval_to_ccsize(cx, argv[0], &arg0);
		do {
			if (!argv[1].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg1 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_TableView_initWithViewSize : Error processing arguments");
		bool ret = cobj->initWithViewSize(arg0, arg1);
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_TableView_initWithViewSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_TableView_scrollViewDidScroll(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::TableView* cobj = (cocos2d::extension::TableView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_TableView_scrollViewDidScroll : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::ScrollView* arg0;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::extension::ScrollView*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_TableView_scrollViewDidScroll : Error processing arguments");
		cobj->scrollViewDidScroll(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_TableView_scrollViewDidScroll : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_TableView_reloadData(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::TableView* cobj = (cocos2d::extension::TableView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_TableView_reloadData : Invalid Native Object");
	if (argc == 0) {
		cobj->reloadData();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_TableView_reloadData : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_TableView_insertCellAtIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::TableView* cobj = (cocos2d::extension::TableView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_TableView_insertCellAtIndex : Invalid Native Object");
	if (argc == 1) {
		ssize_t arg0;
		ok &= jsval_to_ssize(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_TableView_insertCellAtIndex : Error processing arguments");
		cobj->insertCellAtIndex(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_TableView_insertCellAtIndex : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_TableView_cellAtIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::TableView* cobj = (cocos2d::extension::TableView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_TableView_cellAtIndex : Invalid Native Object");
	if (argc == 1) {
		ssize_t arg0;
		ok &= jsval_to_ssize(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_TableView_cellAtIndex : Error processing arguments");
		cocos2d::extension::TableViewCell* ret = cobj->cellAtIndex(arg0);
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::TableViewCell>(cx, (cocos2d::extension::TableViewCell*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_TableView_cellAtIndex : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_TableView_dequeueCell(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::TableView* cobj = (cocos2d::extension::TableView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_TableView_dequeueCell : Invalid Native Object");
	if (argc == 0) {
		cocos2d::extension::TableViewCell* ret = cobj->dequeueCell();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::TableViewCell>(cx, (cocos2d::extension::TableViewCell*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_TableView_dequeueCell : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_TableView_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    cocos2d::extension::TableView* cobj = new cocos2d::extension::TableView();
    cocos2d::Ref *_ccobj = dynamic_cast<cocos2d::Ref *>(cobj);
    if (_ccobj) {
        _ccobj->autorelease();
    }
    TypeTest<cocos2d::extension::TableView> t;
    js_type_class_t *typeClass = nullptr;
    std::string typeName = t.s_name();
    auto typeMapIter = _js_global_type_map.find(typeName);
    CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
    typeClass = typeMapIter->second;
    CCASSERT(typeClass, "The value is null.");
    JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
    // link the native object with the javascript object
    js_proxy_t* p = jsb_new_proxy(cobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::TableView");
    if (JS_HasProperty(cx, obj, "_ctor", &ok))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    return true;
}


extern JSObject *jsb_cocos2d_extension_ScrollView_prototype;

void js_cocos2d_extension_TableView_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (TableView)", obj);
}

static bool js_cocos2d_extension_TableView_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    cocos2d::extension::TableView *nobj = new cocos2d::extension::TableView();
    if (nobj) {
        nobj->autorelease();
    }
    js_proxy_t* p = jsb_new_proxy(nobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::TableView");
    bool isFound = false;
    if (JS_HasProperty(cx, obj, "_ctor", &isFound))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return true;
}
void js_register_cocos2dx_extension_TableView(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_TableView_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_TableView_class->name = "TableView";
	jsb_cocos2d_extension_TableView_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_TableView_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_TableView_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_TableView_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_TableView_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_TableView_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_TableView_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_TableView_class->finalize = js_cocos2d_extension_TableView_finalize;
	jsb_cocos2d_extension_TableView_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("updateCellAtIndex", js_cocos2dx_extension_TableView_updateCellAtIndex, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setVerticalFillOrder", js_cocos2dx_extension_TableView_setVerticalFillOrder, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("scrollViewDidZoom", js_cocos2dx_extension_TableView_scrollViewDidZoom, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("_updateContentSize", js_cocos2dx_extension_TableView__updateContentSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getVerticalFillOrder", js_cocos2dx_extension_TableView_getVerticalFillOrder, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("removeCellAtIndex", js_cocos2dx_extension_TableView_removeCellAtIndex, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initWithViewSize", js_cocos2dx_extension_TableView_initWithViewSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("scrollViewDidScroll", js_cocos2dx_extension_TableView_scrollViewDidScroll, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("reloadData", js_cocos2dx_extension_TableView_reloadData, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("insertCellAtIndex", js_cocos2dx_extension_TableView_insertCellAtIndex, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("cellAtIndex", js_cocos2dx_extension_TableView_cellAtIndex, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("dequeueCell", js_cocos2dx_extension_TableView_dequeueCell, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_cocos2d_extension_TableView_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	jsb_cocos2d_extension_TableView_prototype = JS_InitClass(
		cx, global,
		jsb_cocos2d_extension_ScrollView_prototype,
		jsb_cocos2d_extension_TableView_class,
		js_cocos2dx_extension_TableView_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "TableView", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::TableView> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_TableView_class;
		p->proto = jsb_cocos2d_extension_TableView_prototype;
		p->parentProto = jsb_cocos2d_extension_ScrollView_prototype;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

JSClass  *jsb_cocos2d_extension_EditBox_class;
JSObject *jsb_cocos2d_extension_EditBox_prototype;

bool js_cocos2dx_extension_EditBox_getText(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_getText : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getText();
		jsval jsret = JSVAL_NULL;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_getText : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_EditBox_setFontSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_setFontSize : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_setFontSize : Error processing arguments");
		cobj->setFontSize(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_setFontSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_EditBox_setPlaceholderFontName(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_setPlaceholderFontName : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_setPlaceholderFontName : Error processing arguments");
		cobj->setPlaceholderFontName(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_setPlaceholderFontName : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_EditBox_getPlaceHolder(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_getPlaceHolder : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getPlaceHolder();
		jsval jsret = JSVAL_NULL;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_getPlaceHolder : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_EditBox_setFontName(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_setFontName : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_setFontName : Error processing arguments");
		cobj->setFontName(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_setFontName : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_EditBox_setText(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_setText : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_setText : Error processing arguments");
		cobj->setText(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_setText : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_EditBox_setPlaceholderFontSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_setPlaceholderFontSize : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_setPlaceholderFontSize : Error processing arguments");
		cobj->setPlaceholderFontSize(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_setPlaceholderFontSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_EditBox_setInputMode(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_setInputMode : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::EditBox::InputMode arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_setInputMode : Error processing arguments");
		cobj->setInputMode(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_setInputMode : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_EditBox_setPlaceholderFontColor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_setPlaceholderFontColor : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= jsval_to_cccolor3b(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_setPlaceholderFontColor : Error processing arguments");
		cobj->setPlaceholderFontColor(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_setPlaceholderFontColor : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_EditBox_setFontColor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_setFontColor : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= jsval_to_cccolor3b(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_setFontColor : Error processing arguments");
		cobj->setFontColor(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_setFontColor : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_EditBox_setPlaceholderFont(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_setPlaceholderFont : Invalid Native Object");
	if (argc == 2) {
		const char* arg0;
		int arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_setPlaceholderFont : Error processing arguments");
		cobj->setPlaceholderFont(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_setPlaceholderFont : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_EditBox_initWithSizeAndBackgroundSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_initWithSizeAndBackgroundSprite : Invalid Native Object");
	if (argc == 2) {
		cocos2d::Size arg0;
		cocos2d::extension::Scale9Sprite* arg1;
		ok &= jsval_to_ccsize(cx, argv[0], &arg0);
		do {
			if (!argv[1].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg1 = (cocos2d::extension::Scale9Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_initWithSizeAndBackgroundSprite : Error processing arguments");
		bool ret = cobj->initWithSizeAndBackgroundSprite(arg0, arg1);
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_initWithSizeAndBackgroundSprite : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_EditBox_setPlaceHolder(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_setPlaceHolder : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_setPlaceHolder : Error processing arguments");
		cobj->setPlaceHolder(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_setPlaceHolder : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_EditBox_setReturnType(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_setReturnType : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::EditBox::KeyboardReturnType arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_setReturnType : Error processing arguments");
		cobj->setReturnType(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_setReturnType : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_EditBox_setInputFlag(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_setInputFlag : Invalid Native Object");
	if (argc == 1) {
		cocos2d::extension::EditBox::InputFlag arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_setInputFlag : Error processing arguments");
		cobj->setInputFlag(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_setInputFlag : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_EditBox_getMaxLength(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_getMaxLength : Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getMaxLength();
		jsval jsret = JSVAL_NULL;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_getMaxLength : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_EditBox_setMaxLength(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_setMaxLength : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_setMaxLength : Error processing arguments");
		cobj->setMaxLength(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_setMaxLength : wrong number of arguments: %d, was expecting %d", argc, 1);
	return false;
}
bool js_cocos2dx_extension_EditBox_setFont(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EditBox* cobj = (cocos2d::extension::EditBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EditBox_setFont : Invalid Native Object");
	if (argc == 2) {
		const char* arg0;
		int arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_setFont : Error processing arguments");
		cobj->setFont(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_setFont : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_EditBox_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	if (argc == 2) {
		cocos2d::Size arg0;
		cocos2d::extension::Scale9Sprite* arg1;
		ok &= jsval_to_ccsize(cx, argv[0], &arg0);
		do {
			if (!argv[1].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg1 = (cocos2d::extension::Scale9Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_create : Error processing arguments");
		cocos2d::extension::EditBox* ret = cocos2d::extension::EditBox::create(arg0, arg1);
		jsval jsret = JSVAL_NULL;
		do {
		if (ret) {
			js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::EditBox>(cx, (cocos2d::extension::EditBox*)ret);
			jsret = OBJECT_TO_JSVAL(jsProxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
	if (argc == 3) {
		cocos2d::Size arg0;
		cocos2d::extension::Scale9Sprite* arg1;
		cocos2d::extension::Scale9Sprite* arg2;
		ok &= jsval_to_ccsize(cx, argv[0], &arg0);
		do {
			if (!argv[1].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg1 = (cocos2d::extension::Scale9Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
		} while (0);
		do {
			if (!argv[2].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[2]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg2 = (cocos2d::extension::Scale9Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg2, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_create : Error processing arguments");
		cocos2d::extension::EditBox* ret = cocos2d::extension::EditBox::create(arg0, arg1, arg2);
		jsval jsret = JSVAL_NULL;
		do {
		if (ret) {
			js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::EditBox>(cx, (cocos2d::extension::EditBox*)ret);
			jsret = OBJECT_TO_JSVAL(jsProxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
	if (argc == 4) {
		cocos2d::Size arg0;
		cocos2d::extension::Scale9Sprite* arg1;
		cocos2d::extension::Scale9Sprite* arg2;
		cocos2d::extension::Scale9Sprite* arg3;
		ok &= jsval_to_ccsize(cx, argv[0], &arg0);
		do {
			if (!argv[1].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg1 = (cocos2d::extension::Scale9Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg1, cx, false, "Invalid Native Object");
		} while (0);
		do {
			if (!argv[2].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[2]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg2 = (cocos2d::extension::Scale9Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg2, cx, false, "Invalid Native Object");
		} while (0);
		do {
			if (!argv[3].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[3]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg3 = (cocos2d::extension::Scale9Sprite*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg3, cx, false, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EditBox_create : Error processing arguments");
		cocos2d::extension::EditBox* ret = cocos2d::extension::EditBox::create(arg0, arg1, arg2, arg3);
		jsval jsret = JSVAL_NULL;
		do {
		if (ret) {
			js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::EditBox>(cx, (cocos2d::extension::EditBox*)ret);
			jsret = OBJECT_TO_JSVAL(jsProxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
	JS_ReportError(cx, "js_cocos2dx_extension_EditBox_create : wrong number of arguments");
	return false;
}

bool js_cocos2dx_extension_EditBox_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    cocos2d::extension::EditBox* cobj = new cocos2d::extension::EditBox();
    cocos2d::Ref *_ccobj = dynamic_cast<cocos2d::Ref *>(cobj);
    if (_ccobj) {
        _ccobj->autorelease();
    }
    TypeTest<cocos2d::extension::EditBox> t;
    js_type_class_t *typeClass = nullptr;
    std::string typeName = t.s_name();
    auto typeMapIter = _js_global_type_map.find(typeName);
    CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
    typeClass = typeMapIter->second;
    CCASSERT(typeClass, "The value is null.");
    JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
    // link the native object with the javascript object
    js_proxy_t* p = jsb_new_proxy(cobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::EditBox");
    if (JS_HasProperty(cx, obj, "_ctor", &ok))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    return true;
}


extern JSObject *jsb_cocos2d_extension_ControlButton_prototype;

void js_cocos2d_extension_EditBox_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (EditBox)", obj);
}

void js_register_cocos2dx_extension_EditBox(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_EditBox_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_EditBox_class->name = "EditBox";
	jsb_cocos2d_extension_EditBox_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_EditBox_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_EditBox_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_EditBox_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_EditBox_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_EditBox_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_EditBox_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_EditBox_class->finalize = js_cocos2d_extension_EditBox_finalize;
	jsb_cocos2d_extension_EditBox_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("getString", js_cocos2dx_extension_EditBox_getText, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFontSize", js_cocos2dx_extension_EditBox_setFontSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPlaceholderFontName", js_cocos2dx_extension_EditBox_setPlaceholderFontName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPlaceHolder", js_cocos2dx_extension_EditBox_getPlaceHolder, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFontName", js_cocos2dx_extension_EditBox_setFontName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setString", js_cocos2dx_extension_EditBox_setText, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPlaceholderFontSize", js_cocos2dx_extension_EditBox_setPlaceholderFontSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setInputMode", js_cocos2dx_extension_EditBox_setInputMode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPlaceholderFontColor", js_cocos2dx_extension_EditBox_setPlaceholderFontColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFontColor", js_cocos2dx_extension_EditBox_setFontColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPlaceholderFont", js_cocos2dx_extension_EditBox_setPlaceholderFont, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initWithSizeAndBackgroundSprite", js_cocos2dx_extension_EditBox_initWithSizeAndBackgroundSprite, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPlaceHolder", js_cocos2dx_extension_EditBox_setPlaceHolder, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setReturnType", js_cocos2dx_extension_EditBox_setReturnType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setInputFlag", js_cocos2dx_extension_EditBox_setInputFlag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getMaxLength", js_cocos2dx_extension_EditBox_getMaxLength, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setMaxLength", js_cocos2dx_extension_EditBox_setMaxLength, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFont", js_cocos2dx_extension_EditBox_setFont, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_extension_EditBox_create, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_cocos2d_extension_EditBox_prototype = JS_InitClass(
		cx, global,
		jsb_cocos2d_extension_ControlButton_prototype,
		jsb_cocos2d_extension_EditBox_class,
		js_cocos2dx_extension_EditBox_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "EditBox", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::EditBox> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_EditBox_class;
		p->proto = jsb_cocos2d_extension_EditBox_prototype;
		p->parentProto = jsb_cocos2d_extension_ControlButton_prototype;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

JSClass  *jsb_cocos2d_extension_EventAssetsManager_class;
JSObject *jsb_cocos2d_extension_EventAssetsManager_prototype;

bool js_cocos2dx_extension_EventAssetsManager_getAssetsManager(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EventAssetsManager* cobj = (cocos2d::extension::EventAssetsManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EventAssetsManager_getAssetsManager : Invalid Native Object");
	if (argc == 0) {
		cocos2d::extension::AssetsManager* ret = cobj->getAssetsManager();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::AssetsManager>(cx, (cocos2d::extension::AssetsManager*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EventAssetsManager_getAssetsManager : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_EventAssetsManager_getAssetId(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EventAssetsManager* cobj = (cocos2d::extension::EventAssetsManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EventAssetsManager_getAssetId : Invalid Native Object");
	if (argc == 0) {
		std::string ret = cobj->getAssetId();
		jsval jsret = JSVAL_NULL;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EventAssetsManager_getAssetId : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_EventAssetsManager_getCURLECode(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EventAssetsManager* cobj = (cocos2d::extension::EventAssetsManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EventAssetsManager_getCURLECode : Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getCURLECode();
		jsval jsret = JSVAL_NULL;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EventAssetsManager_getCURLECode : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_EventAssetsManager_getMessage(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EventAssetsManager* cobj = (cocos2d::extension::EventAssetsManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EventAssetsManager_getMessage : Invalid Native Object");
	if (argc == 0) {
		std::string ret = cobj->getMessage();
		jsval jsret = JSVAL_NULL;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EventAssetsManager_getMessage : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_EventAssetsManager_getCURLMCode(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EventAssetsManager* cobj = (cocos2d::extension::EventAssetsManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EventAssetsManager_getCURLMCode : Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getCURLMCode();
		jsval jsret = JSVAL_NULL;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EventAssetsManager_getCURLMCode : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_EventAssetsManager_getPercentByFile(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EventAssetsManager* cobj = (cocos2d::extension::EventAssetsManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EventAssetsManager_getPercentByFile : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getPercentByFile();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EventAssetsManager_getPercentByFile : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_EventAssetsManager_getEventCode(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EventAssetsManager* cobj = (cocos2d::extension::EventAssetsManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EventAssetsManager_getEventCode : Invalid Native Object");
	if (argc == 0) {
		int ret = (int)cobj->getEventCode();
		jsval jsret = JSVAL_NULL;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EventAssetsManager_getEventCode : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_EventAssetsManager_getPercent(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EventAssetsManager* cobj = (cocos2d::extension::EventAssetsManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EventAssetsManager_getPercent : Invalid Native Object");
	if (argc == 0) {
		double ret = cobj->getPercent();
		jsval jsret = JSVAL_NULL;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EventAssetsManager_getPercent : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}

extern JSObject *jsb_cocos2d_EventCustom_prototype;

void js_cocos2d_extension_EventAssetsManager_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (EventAssetsManager)", obj);
}

void js_register_cocos2dx_extension_EventAssetsManager(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_EventAssetsManager_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_EventAssetsManager_class->name = "EventAssetsManager";
	jsb_cocos2d_extension_EventAssetsManager_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_EventAssetsManager_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_EventAssetsManager_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_EventAssetsManager_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_EventAssetsManager_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_EventAssetsManager_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_EventAssetsManager_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_EventAssetsManager_class->finalize = js_cocos2d_extension_EventAssetsManager_finalize;
	jsb_cocos2d_extension_EventAssetsManager_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("getAssetsManager", js_cocos2dx_extension_EventAssetsManager_getAssetsManager, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getAssetId", js_cocos2dx_extension_EventAssetsManager_getAssetId, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getCURLECode", js_cocos2dx_extension_EventAssetsManager_getCURLECode, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getMessage", js_cocos2dx_extension_EventAssetsManager_getMessage, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getCURLMCode", js_cocos2dx_extension_EventAssetsManager_getCURLMCode, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPercentByFile", js_cocos2dx_extension_EventAssetsManager_getPercentByFile, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getEventCode", js_cocos2dx_extension_EventAssetsManager_getEventCode, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPercent", js_cocos2dx_extension_EventAssetsManager_getPercent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	jsb_cocos2d_extension_EventAssetsManager_prototype = JS_InitClass(
		cx, global,
		jsb_cocos2d_EventCustom_prototype,
		jsb_cocos2d_extension_EventAssetsManager_class,
		dummy_constructor<cocos2d::extension::EventAssetsManager>, 0, // no constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "EventAssetsManager", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::EventAssetsManager> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_EventAssetsManager_class;
		p->proto = jsb_cocos2d_extension_EventAssetsManager_prototype;
		p->parentProto = jsb_cocos2d_EventCustom_prototype;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

JSClass  *jsb_cocos2d_extension_Manifest_class;
JSObject *jsb_cocos2d_extension_Manifest_prototype;

bool js_cocos2dx_extension_Manifest_getManifestFileUrl(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Manifest_getManifestFileUrl : Invalid Native Object");
	if (argc == 0) {
		const std::string& ret = cobj->getManifestFileUrl();
		jsval jsret = JSVAL_NULL;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Manifest_getManifestFileUrl : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Manifest_isVersionLoaded(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Manifest_isVersionLoaded : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isVersionLoaded();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Manifest_isVersionLoaded : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Manifest_isLoaded(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Manifest_isLoaded : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isLoaded();
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Manifest_isLoaded : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Manifest_getPackageUrl(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Manifest_getPackageUrl : Invalid Native Object");
	if (argc == 0) {
		const std::string& ret = cobj->getPackageUrl();
		jsval jsret = JSVAL_NULL;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Manifest_getPackageUrl : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Manifest_getVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Manifest_getVersion : Invalid Native Object");
	if (argc == 0) {
		const std::string& ret = cobj->getVersion();
		jsval jsret = JSVAL_NULL;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Manifest_getVersion : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_Manifest_getVersionFileUrl(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::Manifest* cobj = (cocos2d::extension::Manifest *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_Manifest_getVersionFileUrl : Invalid Native Object");
	if (argc == 0) {
		const std::string& ret = cobj->getVersionFileUrl();
		jsval jsret = JSVAL_NULL;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_Manifest_getVersionFileUrl : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}


void js_cocos2d_extension_Manifest_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (Manifest)", obj);
}

void js_register_cocos2dx_extension_Manifest(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_Manifest_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_Manifest_class->name = "Manifest";
	jsb_cocos2d_extension_Manifest_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_Manifest_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_Manifest_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_Manifest_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_Manifest_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_Manifest_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_Manifest_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_Manifest_class->finalize = js_cocos2d_extension_Manifest_finalize;
	jsb_cocos2d_extension_Manifest_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("getManifestFileUrl", js_cocos2dx_extension_Manifest_getManifestFileUrl, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isVersionLoaded", js_cocos2dx_extension_Manifest_isVersionLoaded, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isLoaded", js_cocos2dx_extension_Manifest_isLoaded, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPackageUrl", js_cocos2dx_extension_Manifest_getPackageUrl, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getVersion", js_cocos2dx_extension_Manifest_getVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getVersionFileUrl", js_cocos2dx_extension_Manifest_getVersionFileUrl, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	JSFunctionSpec *st_funcs = NULL;

	jsb_cocos2d_extension_Manifest_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		jsb_cocos2d_extension_Manifest_class,
		empty_constructor, 0,
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "Manifest", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::Manifest> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_Manifest_class;
		p->proto = jsb_cocos2d_extension_Manifest_prototype;
		p->parentProto = NULL;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

JSClass  *jsb_cocos2d_extension_AssetsManager_class;
JSObject *jsb_cocos2d_extension_AssetsManager_prototype;

bool js_cocos2dx_extension_AssetsManager_getState(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::AssetsManager* cobj = (cocos2d::extension::AssetsManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_AssetsManager_getState : Invalid Native Object");
	if (argc == 0) {
		int ret = (int)cobj->getState();
		jsval jsret = JSVAL_NULL;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_AssetsManager_getState : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_AssetsManager_checkUpdate(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::AssetsManager* cobj = (cocos2d::extension::AssetsManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_AssetsManager_checkUpdate : Invalid Native Object");
	if (argc == 0) {
		cobj->checkUpdate();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_AssetsManager_checkUpdate : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_AssetsManager_getStoragePath(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::AssetsManager* cobj = (cocos2d::extension::AssetsManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_AssetsManager_getStoragePath : Invalid Native Object");
	if (argc == 0) {
		const std::string& ret = cobj->getStoragePath();
		jsval jsret = JSVAL_NULL;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_AssetsManager_getStoragePath : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_AssetsManager_update(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::AssetsManager* cobj = (cocos2d::extension::AssetsManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_AssetsManager_update : Invalid Native Object");
	if (argc == 0) {
		cobj->update();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_AssetsManager_update : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_AssetsManager_getLocalManifest(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::AssetsManager* cobj = (cocos2d::extension::AssetsManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_AssetsManager_getLocalManifest : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::extension::Manifest* ret = cobj->getLocalManifest();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::Manifest>(cx, (cocos2d::extension::Manifest*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_AssetsManager_getLocalManifest : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_AssetsManager_getRemoteManifest(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::AssetsManager* cobj = (cocos2d::extension::AssetsManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_AssetsManager_getRemoteManifest : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::extension::Manifest* ret = cobj->getRemoteManifest();
		jsval jsret = JSVAL_NULL;
		do {
			if (ret) {
				js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::Manifest>(cx, (cocos2d::extension::Manifest*)ret);
				jsret = OBJECT_TO_JSVAL(jsProxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_AssetsManager_getRemoteManifest : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_AssetsManager_downloadFailedAssets(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::AssetsManager* cobj = (cocos2d::extension::AssetsManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_AssetsManager_downloadFailedAssets : Invalid Native Object");
	if (argc == 0) {
		cobj->downloadFailedAssets();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_AssetsManager_downloadFailedAssets : wrong number of arguments: %d, was expecting %d", argc, 0);
	return false;
}
bool js_cocos2dx_extension_AssetsManager_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		ok &= jsval_to_std_string(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_AssetsManager_create : Error processing arguments");
		cocos2d::extension::AssetsManager* ret = cocos2d::extension::AssetsManager::create(arg0, arg1);
		jsval jsret = JSVAL_NULL;
		do {
		if (ret) {
			js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::AssetsManager>(cx, (cocos2d::extension::AssetsManager*)ret);
			jsret = OBJECT_TO_JSVAL(jsProxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
	JS_ReportError(cx, "js_cocos2dx_extension_AssetsManager_create : wrong number of arguments");
	return false;
}

bool js_cocos2dx_extension_AssetsManager_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    std::string arg0;
    std::string arg1;
    ok &= jsval_to_std_string(cx, argv[0], &arg0);
    ok &= jsval_to_std_string(cx, argv[1], &arg1);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_AssetsManager_constructor : Error processing arguments");
    cocos2d::extension::AssetsManager* cobj = new cocos2d::extension::AssetsManager(arg0, arg1);
    cocos2d::Ref *_ccobj = dynamic_cast<cocos2d::Ref *>(cobj);
    if (_ccobj) {
        _ccobj->autorelease();
    }
    TypeTest<cocos2d::extension::AssetsManager> t;
    js_type_class_t *typeClass = nullptr;
    std::string typeName = t.s_name();
    auto typeMapIter = _js_global_type_map.find(typeName);
    CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
    typeClass = typeMapIter->second;
    CCASSERT(typeClass, "The value is null.");
    JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
    // link the native object with the javascript object
    js_proxy_t* p = jsb_new_proxy(cobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::AssetsManager");
    if (JS_HasProperty(cx, obj, "_ctor", &ok))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    return true;
}



void js_cocos2d_extension_AssetsManager_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (AssetsManager)", obj);
}

void js_register_cocos2dx_extension_AssetsManager(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_AssetsManager_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_AssetsManager_class->name = "AssetsManager";
	jsb_cocos2d_extension_AssetsManager_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_AssetsManager_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_AssetsManager_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_AssetsManager_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_AssetsManager_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_AssetsManager_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_AssetsManager_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_AssetsManager_class->finalize = js_cocos2d_extension_AssetsManager_finalize;
	jsb_cocos2d_extension_AssetsManager_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("getState", js_cocos2dx_extension_AssetsManager_getState, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("checkUpdate", js_cocos2dx_extension_AssetsManager_checkUpdate, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getStoragePath", js_cocos2dx_extension_AssetsManager_getStoragePath, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("update", js_cocos2dx_extension_AssetsManager_update, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getLocalManifest", js_cocos2dx_extension_AssetsManager_getLocalManifest, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getRemoteManifest", js_cocos2dx_extension_AssetsManager_getRemoteManifest, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("downloadFailedAssets", js_cocos2dx_extension_AssetsManager_downloadFailedAssets, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_extension_AssetsManager_create, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_cocos2d_extension_AssetsManager_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		jsb_cocos2d_extension_AssetsManager_class,
		js_cocos2dx_extension_AssetsManager_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "AssetsManager", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::AssetsManager> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_AssetsManager_class;
		p->proto = jsb_cocos2d_extension_AssetsManager_prototype;
		p->parentProto = NULL;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

JSClass  *jsb_cocos2d_extension_EventListenerAssetsManager_class;
JSObject *jsb_cocos2d_extension_EventListenerAssetsManager_prototype;

bool js_cocos2dx_extension_EventListenerAssetsManager_init(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::EventListenerAssetsManager* cobj = (cocos2d::extension::EventListenerAssetsManager *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_extension_EventListenerAssetsManager_init : Invalid Native Object");
	if (argc == 2) {
		const cocos2d::extension::AssetsManager* arg0;
		std::function<void (cocos2d::extension::EventAssetsManager *)> arg1;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (const cocos2d::extension::AssetsManager*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		do {
			std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, JS_THIS_OBJECT(cx, vp), argv[1]));
			auto lambda = [=](cocos2d::extension::EventAssetsManager* larg0) -> void {
				jsval largv[1];
				do {
					if (larg0) {
						js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::EventAssetsManager>(cx, (cocos2d::extension::EventAssetsManager*)larg0);
						largv[0] = OBJECT_TO_JSVAL(jsProxy->obj);
					} else {
						largv[0] = JSVAL_NULL;
					}
				} while (0);
				jsval rval;
				bool ok = func->invoke(1, &largv[0], rval);
				if (!ok && JS_IsExceptionPending(cx)) {
					JS_ReportPendingException(cx);
				}
			};
			arg1 = lambda;
		} while(0)
		;
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EventListenerAssetsManager_init : Error processing arguments");
		bool ret = cobj->init(arg0, arg1);
		jsval jsret = JSVAL_NULL;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}

	JS_ReportError(cx, "js_cocos2dx_extension_EventListenerAssetsManager_init : wrong number of arguments: %d, was expecting %d", argc, 2);
	return false;
}
bool js_cocos2dx_extension_EventListenerAssetsManager_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
	if (argc == 2) {
		cocos2d::extension::AssetsManager* arg0;
		std::function<void (cocos2d::extension::EventAssetsManager *)> arg1;
		do {
			if (!argv[0].isObject()) { ok = false; break; }
			js_proxy_t *jsProxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			jsProxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::extension::AssetsManager*)(jsProxy ? jsProxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
		} while (0);
		do {
			std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, JS_THIS_OBJECT(cx, vp), argv[1]));
			auto lambda = [=](cocos2d::extension::EventAssetsManager* larg0) -> void {
				jsval largv[1];
				do {
					if (larg0) {
						js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::EventAssetsManager>(cx, (cocos2d::extension::EventAssetsManager*)larg0);
						largv[0] = OBJECT_TO_JSVAL(jsProxy->obj);
					} else {
						largv[0] = JSVAL_NULL;
					}
				} while (0);
				jsval rval;
				bool ok = func->invoke(1, &largv[0], rval);
				if (!ok && JS_IsExceptionPending(cx)) {
					JS_ReportPendingException(cx);
				}
			};
			arg1 = lambda;
		} while(0)
		;
		JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_extension_EventListenerAssetsManager_create : Error processing arguments");
		cocos2d::extension::EventListenerAssetsManager* ret = cocos2d::extension::EventListenerAssetsManager::create(arg0, arg1);
		jsval jsret = JSVAL_NULL;
		do {
		if (ret) {
			js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::extension::EventListenerAssetsManager>(cx, (cocos2d::extension::EventListenerAssetsManager*)ret);
			jsret = OBJECT_TO_JSVAL(jsProxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return true;
	}
	JS_ReportError(cx, "js_cocos2dx_extension_EventListenerAssetsManager_create : wrong number of arguments");
	return false;
}

bool js_cocos2dx_extension_EventListenerAssetsManager_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	bool ok = true;
    cocos2d::extension::EventListenerAssetsManager* cobj = new cocos2d::extension::EventListenerAssetsManager();
    cocos2d::Ref *_ccobj = dynamic_cast<cocos2d::Ref *>(cobj);
    if (_ccobj) {
        _ccobj->autorelease();
    }
    TypeTest<cocos2d::extension::EventListenerAssetsManager> t;
    js_type_class_t *typeClass = nullptr;
    std::string typeName = t.s_name();
    auto typeMapIter = _js_global_type_map.find(typeName);
    CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
    typeClass = typeMapIter->second;
    CCASSERT(typeClass, "The value is null.");
    JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
    // link the native object with the javascript object
    js_proxy_t* p = jsb_new_proxy(cobj, obj);
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::EventListenerAssetsManager");
    if (JS_HasProperty(cx, obj, "_ctor", &ok))
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", argc, argv);
    return true;
}


extern JSObject *jsb_cocos2d_EventListenerCustom_prototype;

void js_cocos2d_extension_EventListenerAssetsManager_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (EventListenerAssetsManager)", obj);
}

void js_register_cocos2dx_extension_EventListenerAssetsManager(JSContext *cx, JSObject *global) {
	jsb_cocos2d_extension_EventListenerAssetsManager_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_cocos2d_extension_EventListenerAssetsManager_class->name = "EventListenerAssetsManager";
	jsb_cocos2d_extension_EventListenerAssetsManager_class->addProperty = JS_PropertyStub;
	jsb_cocos2d_extension_EventListenerAssetsManager_class->delProperty = JS_DeletePropertyStub;
	jsb_cocos2d_extension_EventListenerAssetsManager_class->getProperty = JS_PropertyStub;
	jsb_cocos2d_extension_EventListenerAssetsManager_class->setProperty = JS_StrictPropertyStub;
	jsb_cocos2d_extension_EventListenerAssetsManager_class->enumerate = JS_EnumerateStub;
	jsb_cocos2d_extension_EventListenerAssetsManager_class->resolve = JS_ResolveStub;
	jsb_cocos2d_extension_EventListenerAssetsManager_class->convert = JS_ConvertStub;
	jsb_cocos2d_extension_EventListenerAssetsManager_class->finalize = js_cocos2d_extension_EventListenerAssetsManager_finalize;
	jsb_cocos2d_extension_EventListenerAssetsManager_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("init", js_cocos2dx_extension_EventListenerAssetsManager_init, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_extension_EventListenerAssetsManager_create, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_cocos2d_extension_EventListenerAssetsManager_prototype = JS_InitClass(
		cx, global,
		jsb_cocos2d_EventListenerCustom_prototype,
		jsb_cocos2d_extension_EventListenerAssetsManager_class,
		js_cocos2dx_extension_EventListenerAssetsManager_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
//	bool found;
//FIXME: Removed in Firefox v27	
//	JS_SetPropertyAttributes(cx, global, "EventListenerAssetsManager", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::EventListenerAssetsManager> t;
	js_type_class_t *p;
	std::string typeName = t.s_name();
	if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_cocos2d_extension_EventListenerAssetsManager_class;
		p->proto = jsb_cocos2d_extension_EventListenerAssetsManager_prototype;
		p->parentProto = jsb_cocos2d_EventListenerCustom_prototype;
		_js_global_type_map.insert(std::make_pair(typeName, p));
	}
}

void register_all_cocos2dx_extension(JSContext* cx, JSObject* obj) {
	// first, try to get the ns
	JS::RootedValue nsval(cx);
	JS::RootedObject ns(cx);
	JS_GetProperty(cx, obj, "cc", &nsval);
	if (nsval == JSVAL_VOID) {
		ns = JS_NewObject(cx, NULL, NULL, NULL);
		nsval = OBJECT_TO_JSVAL(ns);
		JS_SetProperty(cx, obj, "cc", nsval);
	} else {
		JS_ValueToObject(cx, nsval, &ns);
	}
	obj = ns;

	js_register_cocos2dx_extension_Control(cx, obj);
	js_register_cocos2dx_extension_ControlHuePicker(cx, obj);
	js_register_cocos2dx_extension_TableViewCell(cx, obj);
	js_register_cocos2dx_extension_Scale9Sprite(cx, obj);
	js_register_cocos2dx_extension_AssetsManager(cx, obj);
	js_register_cocos2dx_extension_ControlColourPicker(cx, obj);
	js_register_cocos2dx_extension_EventAssetsManager(cx, obj);
	js_register_cocos2dx_extension_ControlButton(cx, obj);
	js_register_cocos2dx_extension_ControlSlider(cx, obj);
	js_register_cocos2dx_extension_ControlSaturationBrightnessPicker(cx, obj);
	js_register_cocos2dx_extension_ScrollView(cx, obj);
	js_register_cocos2dx_extension_Manifest(cx, obj);
	js_register_cocos2dx_extension_ControlPotentiometer(cx, obj);
	js_register_cocos2dx_extension_ControlStepper(cx, obj);
	js_register_cocos2dx_extension_TableView(cx, obj);
	js_register_cocos2dx_extension_EditBox(cx, obj);
	js_register_cocos2dx_extension_EventListenerAssetsManager(cx, obj);
	js_register_cocos2dx_extension_ControlSwitch(cx, obj);
}

