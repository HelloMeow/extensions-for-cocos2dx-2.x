//
//  EXButtonImp.h
// 
//
//  Created by HelloMeow on 14-3-10.
//
//

#ifndef __EXButtonImp__
#define __EXButtonImp__

#include "cocos2d.h"
#include "EXButtonImpRGBAProtocol.h"
#include "EXButtonImpDefine.h"
class EXButtonImp
: public cocos2d::CCLayerRGBA
, public NameSpaceEXButtonImp::EXButtonImpRGBAProtocol
{
public:
    virtual bool getEnabled(){return _enabled;}
    virtual void setEnabled(bool enabled);
    virtual void setLambda(std::function<void()> lambda);
    
    virtual void switchState();
    virtual void activate();
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent* event);
    virtual void setState(NameSpaceEXButtonImp::State newState);
protected:
    virtual bool init();
    virtual bool swallowTouch(cocos2d::CCTouch* touch);
    virtual bool isTouchInSelf(cocos2d::CCTouch* touch);
    
    virtual void onExit();
    virtual void onEnterTransitionDidFinish();
    
    inline NameSpaceEXButtonImp::State getState(){return _state;}
    
private:
    NameSpaceEXButtonImp::State _state;
    bool _enabled;
    std::function<void()> _lambda;
};

#endif /* defined(__EXButtonImp__) */
