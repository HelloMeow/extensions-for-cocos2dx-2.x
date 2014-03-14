//
//  EXButtonImpDecoratorHold.cpp
// 
//
//  Created by HelloMeow on 14-3-10.
//
//

#include "EXButtonImpDecoratorHold.h"

NSEXButtonImp_BEGIN
using namespace cocos2d;
// TODO: 支持传入长按门槛时间

EXButtonImp* EXButtonImpDecoratorHold::create(EXButtonImp *button, float timeThreshold)
{
    EXButtonImpDecoratorHold* btn = new EXButtonImpDecoratorHold();
    if (btn && btn->init(button, timeThreshold))
    {
        btn->autorelease();
        return btn;
    }
    CC_SAFE_DELETE(btn);
    return nullptr;
}
bool EXButtonImpDecoratorHold::init(EXButtonImp* button, float timeThreshold)
{
    do {
        CC_BREAK_IF(!EXButtonImpDecorator::init(button));
        
        CC_BREAK_IF(timeThreshold<=0.0f);
        
        _timeThreshold = timeThreshold;
        
        _holdDetected = false;
        
        return true;
        
    } while (0);
    
    return false;
}

bool EXButtonImpDecoratorHold::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    if (EXButtonImpDecorator::ccTouchBegan(touch, event))
    {
        _holdDetected = false;
        schedule(SEL_SCHEDULE(&EXButtonImpDecoratorHold::holdDetected),
                 _timeThreshold, 1, 0);
        return true;
    }
    
    return false;
}
void EXButtonImpDecoratorHold::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    if (_holdDetected)
        EXButtonImp::ccTouchEnded(touch, event);
    else
        EXButtonImpDecorator::ccTouchEnded(touch, event);
    
    // unschedule
    unschedule(SEL_SCHEDULE(&EXButtonImpDecoratorHold::holdDetected));
}
void EXButtonImpDecoratorHold::ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent* event)
{
    EXButtonImpDecorator::ccTouchCancelled(touch, event);
    // unschedule
    unschedule(SEL_SCHEDULE(&EXButtonImpDecoratorHold::holdDetected));
}

void EXButtonImpDecoratorHold::holdDetected()
{
    CCLog("Hold gesture recognized");
    unschedule(SEL_SCHEDULE(&EXButtonImpDecoratorHold::holdDetected));
    _holdDetected = true;
    EXButtonImp::activate();
}

void EXButtonImpDecoratorHold::activate()
{
    // do not trigger single-click or anything.
    // EXButtonImp::activate();
}

NSEXButtonImp_END
