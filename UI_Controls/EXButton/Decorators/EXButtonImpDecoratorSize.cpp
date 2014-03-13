//
//  EXButtonImpDecoratorSize.cpp
// 
//
//  Created by HelloMeow on 14-3-10.
//
//

#include "EXButtonImpDecoratorSize.h"
#include "MacroHelpers.h"

NSEXButtonImp_BEGIN
using namespace cocos2d;
EXButtonImp* EXButtonImpDecoratorSize::create(EXButtonImp *button, CCSize size)
{
    EXButtonImpDecoratorSize* btn = new EXButtonImpDecoratorSize();
    if (btn && btn->init(button, size))
    {
        btn->autorelease();
        return btn;
    }
    CC_SAFE_DELETE(btn);
    return nullptr;
}
bool EXButtonImpDecoratorSize::init(EXButtonImp* button, CCSize size)
{
    do {
        CC_BREAK_IF(!EXButtonImpDecorator::init(button));
        
        setContentSize(CCSizeMax(size, button->getContentSize()));
        
        _button->setPosition(CENTER_OF(this)); // update position
        
        return true;
        
    } while (0);
    
    return false;
}

bool EXButtonImpDecoratorSize::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    return EXButtonImpDecorator::ccTouchBegan(touch, event) || EXButtonImp::ccTouchBegan(touch, event);
}

NSEXButtonImp_END
