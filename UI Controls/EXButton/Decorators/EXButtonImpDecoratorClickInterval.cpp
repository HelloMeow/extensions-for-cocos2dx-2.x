//
//  EXButtonImpDecoratorClickInterval.cpp
//  TetravexDesigner
//
//  Created by jiuzhang tech on 14-3-10.
//
//

#include "EXButtonImpDecoratorClickInterval.h"

NSEXButtonImp_BEGIN

using namespace cocos2d;

EXButtonImp* EXButtonImpDecoratorClickInterval::create(EXButtonImp *button, float minClickInterval)
{
    EXButtonImpDecoratorClickInterval* btn = new EXButtonImpDecoratorClickInterval();
    if (btn && btn->init(button, minClickInterval))
    {
        btn->autorelease();
        return btn;
    }
    CC_SAFE_DELETE(btn);
    return nullptr;
}
bool EXButtonImpDecoratorClickInterval::init(EXButtonImp* button, float minClickInterval)
{
    do {
        CC_BREAK_IF(!EXButtonImpDecorator::init(button));
        
        _minClickInterval = minClickInterval;
        _lastClickTimeStamp = 0.0f;
        
        return true;
        
    } while (0);
    
    return false;
}
long EXButtonImpDecoratorClickInterval::millisecondsNow()
{
    struct cc_timeval now;
    
    cocos2d::CCTime::gettimeofdayCocos2d(&now, NULL);
    
    return (now.tv_sec * 1000 + now.tv_usec / 1000);
}
void EXButtonImpDecoratorClickInterval::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    long curTimeStamp = millisecondsNow();
    
    if(abs(curTimeStamp - _lastClickTimeStamp) < _minClickInterval * 1000)
    {
        setEnabled(false);
        unschedule(SEL_SCHEDULE(&EXButtonImpDecoratorClickInterval::enableClick));
        scheduleOnce(SEL_SCHEDULE(&EXButtonImpDecoratorClickInterval::enableClick), _minClickInterval);
    }
    else
    {
        EXButtonImpDecorator::ccTouchEnded(touch, event);
    }
    
    _lastClickTimeStamp = curTimeStamp;
}

void EXButtonImpDecoratorClickInterval::enableClick()
{
    setEnabled(true);
}

NSEXButtonImp_END
