//
//  EXButtonImpDecorator.h
// 
//
//  Created by HelloMeow on 14-3-10.
//
//

#ifndef __EXButtonImpDecorator__
#define __EXButtonImpDecorator__

#include "EXButtonImp.h"

NSEXButtonImp_BEGIN

class EXButtonImpDecorator : public EXButtonImp
{
public:
    EXButtonImpDecorator();
    virtual ~EXButtonImpDecorator();
    virtual void activate();
    
protected:
    void setButton(EXButtonImp* button);
    virtual void setState(State newState);
    virtual void setEnabled(bool enabled);
    virtual void setColor(cocos2d::ccColor3B& color, NameSpaceEXButtonImp::State state);
    using EXButtonImp::init;
    virtual bool init(EXButtonImp* button);
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent* event);
    virtual void switchState();
    EXButtonImp* _button;
};

NSEXButtonImp_END

#endif /* defined(__EXButtonImpDecorator__) */
