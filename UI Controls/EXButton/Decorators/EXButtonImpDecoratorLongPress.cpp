//
//  EXButtonImpDecoratorLongPress.cpp
//  TetravexDesigner
//
//  Created by jiuzhang tech on 14-3-10.
//
//

#include "EXButtonImpDecoratorLongPress.h"

NSEXButtonImp_BEGIN
using namespace cocos2d;
// TODO: 支持传入长按门槛时间

EXButtonImp* EXButtonImpDecoratorLongPress::create(EXButtonImp *button, float timeThreshold)
{
    EXButtonImpDecoratorLongPress* btn = new EXButtonImpDecoratorLongPress();
    if (btn && btn->init(button, timeThreshold))
    {
        btn->autorelease();
        return btn;
    }
    CC_SAFE_DELETE(btn);
    return nullptr;
}
bool EXButtonImpDecoratorLongPress::init(EXButtonImp* button, float timeThreshold)
{
    do {
        CC_BREAK_IF(!EXButtonImpDecorator::init(button));
        
        CC_BREAK_IF(timeThreshold<=0.0f);
        
        _timeThreshold = timeThreshold;
        
        return true;
        
    } while (0);
    
    return false;
}

bool EXButtonImpDecoratorLongPress::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    if (EXButtonImpDecorator::ccTouchBegan(touch, event))
    {
        schedule(SEL_SCHEDULE(&EXButtonImpDecorator::activate), _timeThreshold, kCCRepeatForever, _timeThreshold);
        return true;
    }
    
    return false;
}
void EXButtonImpDecoratorLongPress::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    EXButtonImpDecorator::ccTouchEnded(touch, event);
    
    // unschedule
    unschedule(SEL_SCHEDULE(&EXButtonImpDecorator::activate));
}
void EXButtonImpDecoratorLongPress::ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent* event)
{
    EXButtonImpDecorator::ccTouchCancelled(touch, event);
    // unschedule
    unschedule(SEL_SCHEDULE(&EXButtonImpDecorator::activate));
}

NSEXButtonImp_END
