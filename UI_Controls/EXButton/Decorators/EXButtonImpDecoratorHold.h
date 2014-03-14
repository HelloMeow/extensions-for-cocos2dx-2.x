//
//  EXButtonImpDecoratorHold.h
// 
//
//  Created by HelloMeow on 14-3-10.
//
//

#ifndef __EXButtonImpDecoratorHold__
#define __EXButtonImpDecoratorHold__

#include "EXButtonImpDecorator.h"

NSEXButtonImp_BEGIN

class EXButtonImpDecoratorHold : public EXButtonImpDecorator
{
public:
    static EXButtonImp* create(EXButtonImp* button, float timeThreshold);
    
protected:
    using EXButtonImpDecorator::init;
    virtual bool init(EXButtonImp* button, float timeThreshold);
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent* event);
    void holdDetected();
    virtual void activate();
private:
    float _timeThreshold;
    bool _holdDetected;
    bool _touchCancelled;
};

NSEXButtonImp_END

#endif /* defined(__EXButtonImpDecoratorHold__) */
