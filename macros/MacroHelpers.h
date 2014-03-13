//
//  MacroHelpers.h
//  TetravexDesigner
//
//  Created by jiuzhang tech on 14-3-13.
//
//

#ifndef _MacroHelpers_h
#define _MacroHelpers_h


/**
 *  cocos2d-x relevant macros
 */

#pragma mark

/**
 *  random color3B
 */
#define ccRandomColor   ccc3(arc4random()%255, arc4random()%255, arc4random()%255)

#pragma mark -
/**
 *  CCString switch-case
 *  e.g:
 *
 *  CXSWITCH_STR_BEGIN(CCString::create("abc123"))
 *  {
 *      _CASE_NULLPTR_
 *      {
 *          CCLog("Null ptr");
 *      }
 *      _CASE_EMPTY_
 *      {
 *          CCLog("empty CCString");
 *      }
 *      _CASE_STR_VALUE_(CCString::create("abc123"))
 *      {
 *          CCLog("Match");
 *      }
 *  }
 *  CXSWITCH_STR_END
 */
#define CXSWITCH_STR_BEGIN(_CCSTRING_VALUE_)    { CCString* _value_ = _CCSTRING_VALUE_;_value_; if (0){

#define _CASE_NULLPTR_                          } else if (nullptr == _value_) {

#define _CASE_EMPTY_                            } else if (STRING_EMPTY(_value_)){

#define _CASE_STR_VALUE_(_V_)                   } else if (STRING_EQUAL(b, CCStringMakeFrom(_V_))) {

#define CXSWITCH_STR_END                        }}

#pragma mark -
/**
 *  CCArray traversing each item
 *  e.g:
 *
 *  CCArray* a = CCArray::create();
 *  a->addObject(CCSprite::create("xxx.png"));
 *  CXARRAY_FOREACH(a, sp, CCSprite*) {
 *      addChild(sp);
 *  }
 */
#define CXARRAY_FOREACH(array, __itemInArray__, __itemType__) \
    __itemType__ __itemInArray__ = nullptr;\
    CCArray *__array__ = (CCArray *) array;\
    if ((__array__) && (__array__)->data->num > 0) \
        for(CCObject** __arr__ = (__array__)->data->arr, \
            **__end__ = (__array__)->data->arr + (__array__)->data->num-1; \
            __arr__ <= __end__ && (((__itemInArray__) = (__itemType__) *__arr__) != NULL); \
            __arr__++)

#pragma mark -
/**
 *  CCArray traversing each item by index
 *  e.g:
 *
 *  CCArray* a = CCArray::create();
 *  a->addObject(CCSprite::create("xxx.png"));
 *  CXARRAY_FOREACH_IDX(a, sp, CCSprite*, idx) {
 *      addChild(sp);
 *      CCLog("Add sprite No.%d", idx);
 *  }
 */
#define CXARRAY_FOREACH_IDX(array, __itemInArray__, __itemType__, __itemIndex__) \
    __itemType__ __itemInArray__ = nullptr;\
    int __itemIndex__ = 0; \
    CCArray *__array__ = (CCArray *) array;\
    if ((__array__) && (__array__)->data->num > 0) \
        for(CCObject** __arr__ = (__array__)->data->arr, \
        **__end__ = (__array__)->data->arr + (__array__)->data->num-1;    \
        __arr__ <= __end__ && (((__itemInArray__) = (__itemType__) *__arr__) != NULL/* || true*/); \
        (__arr__++, __itemIndex__++))

#pragma mark -
/**
 *  DLog: only log when DEBUG is defined
 */
#ifdef DEBUG
#   define DLog(fmt, ...) cocos2d::CCLog(("[%s - %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif

/**
 *  ALog always displays output regardless of the DEBUG setting
 */
#define ALog(fmt, ...) CCLog(("[%s - %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);

#pragma mark - logging helpers
/**
 *  logging helpers for values of mostly used types
 */
#define LOGFunction()       DLog("[%s]",__FUNCTION__)
#define LOGInt(i)           DLog("int:"#i":%d", i)
#define LOGFloat(f)         DLog("float:"#f":%.2f", f)
#define LOGCCPoint(p)       DLog("Point:"#p":(%.2f,%.2f)", p.x, p.y)
#define LOGCCSize(s)        DLog("Size:"#s":(%.2f,%.2f)", s.width, s.height)
#define LOGCCString(s)      DLog("String:"#s":%s", (s) ? (s)->getCString() : "[Empty String]")
#define LOGString(s)        DLog("String:"#s":%s", (s) ? (const char*)s : "[Empty String]")
#define LOGCCRect(r)        DLog("Rect:"#r":(%.2f,%.2f,%.2f,%.2f)", r.origin.x, r.origin.y, r.size.width, r.size.height)
#define LOGccc3(c)          DLog("ccColor3B:"#c":0x%2x%2x%2x", c.r, c.g, c.b)
#define LOGccc4(c)          DLog("ccColor4B:"#c":0x%2x%2x%2x%2x", c.r, c.g, c.b, c.a)
#define LOGBool(b)          DLog("Bool:"#b":%s", b ? "true" : "false")
#define LOGAnchorPoint(o)   (o ? LOGCCPoint(o->getAnchorPoint()) : LOGString(""#o" is nullptr"))
#define LOGPosition(o)      (o ? LOGCCPoint(o->getPosition()) : LOGString(""#o" is nullptr"))
#define LOGSize(o)          (o ? LOGCCSize(o->getContentSize()) : LOGString(""#o" is nullptr"))
#define LOGBasic(o)         {LOGAnchorPoint(o);LOGPosition(o);LOGSize(o);}
#define WarnNotImplemented()    {DLog("NOT_IMPLEMENTED");}
#pragma mark -
/**
 *  CXASSERT: if cond not meet, log the cond for debugging.
 */
#ifdef DEBUG
#   define CXASSERT(cond)  CCAssert(cond, #cond)
#else
#   define CXASSERT(cond)
#endif

#pragma mark -
/**
 *  CX_BREAK_IF: if cond meets, log the cond for debugging
 */
#define CX_BREAK_IF(cond) if (cond) {LOGDEBUG("BREAK:"#cond); break;}

#pragma mark -
/**
 *  WARN_IF: log exp if true for debugging
 */
#define WARN_IF(EXP) \
do { if (EXP) \
DLog("Warning: %s", #EXP); } while (0)

#pragma mark -
/**
 *  use this can declare objective-c class in both C++ and objective-c headers.
 */
#ifdef __OBJC__
#   define OBJC_CLASS(name) @class name
#else
#   define OBJC_CLASS(name) typedef struct objc_object name
#endif

#pragma mark -
/**
 *  fast way to define shared instance in class declaration
 */
#define CC_SHARED_INSTANCE(__TYPE__)\
static __TYPE__* sharedInstance() \
{ \
    static __TYPE__ *pRet = new __TYPE__(); \
    return pRet; \
}

#define CC_SHARED_INSTANCE_INIT(__TYPE__) \
static __TYPE__* sharedInstance() \
{ \
    static __TYPE__ *pRet = NULL; \
    if (!pRet) { \
        pRet = new __TYPE__(); \
        if (pRet && pRet->init()); \
    } \
    return pRet; \
}

#pragma mark -
/**
 *  fast way to define CCScene (create() method required)
 */
#define CC_CREATE_SCENE(__TYPE__) \
static CCScene* scene() \
{ \
    CCScene *scene = CCScene::create(); \
    __TYPE__ *layer = __TYPE__::create(); \
    scene->addChild(layer); \
    return scene; \
}

#pragma mark - Constructor and Deconstructor declaration / definition
/**
 *  fast way to declare / define constructor and deconstructor
 */
#define CC_CSTR_00(__TYPE__) \
__TYPE__();\
~__TYPE__();

#define CC_CSTR_11(__TYPE__) \
__TYPE__(){}\
~__TYPE__(){}

#define CC_CSTR_V00(__TYPE__) \
__TYPE__();\
virtual ~__TYPE__();

#define CC_CSTR_V11(__TYPE__) \
__TYPE__(){}\
virtual ~__TYPE__(){}

#pragma mark -
/**
 *  set retained value (C++0x11 required)
 */
#define CXSET_RETAIN(property, value)\
    {auto __value__ = value;\
    if( property != __value__ ) {\
        CC_SAFE_RELEASE_NULL(property);\
        property = __value__;\
        CC_SAFE_RETAIN(property);}}

#pragma mark - property setter and getter declaration
/**
 *  declare property setter and getter
 */
#define CC_PROPERTY_GETTER(varType, varName, funName) varType get##funName(void)
#define CC_PROPERTY_SETTER(varType, varName, funName) void set##funName(varType var)

#define CC_PROPERTY_VIRTUAL_GETTER(varType, varName, funName) \
virtual CC_PROPERTY_GETTER(varType, varName, funName)

#define CC_PROPERTY_VIRTUAL_SETTER(varType, varName, funName) \
virtual CC_PROPERTY_SETTER(varType, varName, funName)

#pragma mark - property setter and getter definition
/**
 *  define property setter(retain and assign) and getter
 */
#define CC_SYNTHESIZE_GETTER(varType, varName, funName, className) \
varType className::get##funName(void){return varName;}

#define CC_SYNTHESIZE_SETTER_RETAIN(varType, varName, funName, className) \
void className::set##funName(varType var) {\
    CXSET_RETAIN(varName, var); }

#define CC_SYNTHESIZE_SETTER(varType, varName, funName, className) \
void className::set##funName(varType var) {\
    varName = var; }

#pragma mark - fast way to define setter AND getter both.
/**
 *  define property both the setter(retain or assign) and getter
 */
#define CC_SYNTHESIZE_GS_ASSIGN(varType, varName, funName, className) \
    CC_SYNTHESIZE_GETTER(varType, varName, funName, className); \
    CC_SYNTHESIZE_SETTER(varType, varName, funName, className);

#define CC_SYNTHESIZE_GS_RETAIN(varType, varName, funName, className) \
    CC_SYNTHESIZE_GETTER(varType, varName, funName, className); \
    CC_SYNTHESIZE_SETTER_RETAIN(varType, varName, funName, className);

#pragma mark - CCSize helper macros
/**
 * return a CCSize with  bigger width and height of passed-in two ccsizes
 */
#define CCSizeMax(__a__, __b__) (CCSizeMake(MAX(__a__.width, __b__.width), MAX(__a__.height, __b__.height)))

#pragma mark -
/**
 *  get node's center position
 */
#define CENTER_OF(node) CCPointMake(node->getContentSize().width/2, node->getContentSize().height/2)

#pragma mark - anchor point
/**
 *  mostly used anchorPoint
 */
#define AP_BottomLeft       ccp(0,   0)
#define AP_BottomCenter     ccp(0.5, 0)
#define AP_BottomRight      ccp(1,   0)

#define AP_CenterLeft       ccp(0,   0.5)
#define AP_Center           ccp(0.5, 0.5)
#define AP_CenterRight      ccp(1,   0.5)

#define AP_TopLeft          ccp(0,   1)
#define AP_TopCenter        ccp(0.5, 1)
#define AP_TopRight         ccp(1,   1)



#pragma mark -

#endif
