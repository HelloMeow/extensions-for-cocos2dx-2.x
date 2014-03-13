//
//  EXButtonImpDecoratorToggle.cpp
// 
//
//  Created by HelloMeow on 14-3-10.
//
//

#include "EXButtonImpDecoratorToggle.h"
#include "EXButtonImpDefine.h"

NSEXButtonImp_BEGIN
using namespace cocos2d;
EXButtonImp* EXButtonImpDecoratorToggle::create(cocos2d::CCArray* exButtonArray)
{
    EXButtonImpDecoratorToggle* btn = new EXButtonImpDecoratorToggle();
    if (btn && btn->init(exButtonArray))
    {
        btn->autorelease();
        return btn;
    }
    CC_SAFE_DELETE(btn);
    return nullptr;
}

EXButtonImpDecoratorToggle::EXButtonImpDecoratorToggle()
{
    _selectedIndex = 0;
    _buttons = nullptr;
}

EXButtonImpDecoratorToggle::~EXButtonImpDecoratorToggle()
{
    CC_SAFE_RELEASE_NULL(_buttons);
}

bool EXButtonImpDecoratorToggle::init(cocos2d::CCArray *exButtonArray)
{
    do {
        CC_BREAK_IF(!exButtonArray || exButtonArray->count()<=0);
        
        CC_BREAK_IF(!EXButtonImpDecorator::init((EXButtonImp*)exButtonArray->objectAtIndex(_selectedIndex)));
        
        _buttons = exButtonArray;
        CC_SAFE_RETAIN(_buttons);
        
        return true;
    } while (0);
    
    return false;
}

void EXButtonImpDecoratorToggle::activate()
{
    _selectedIndex = (_selectedIndex+1) % (_buttons->count());
    
    setButton((EXButtonImp*)_buttons->objectAtIndex(_selectedIndex));
}

NSEXButtonImp_END
