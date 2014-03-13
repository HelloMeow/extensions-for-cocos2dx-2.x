//
//  EXButtonImp.cpp
// 
//
//  Created by HelloMeow on 14-3-10.
//
//

#include "EXButtonImp.h"
#include "Helpers.h"
#include "MacroHelpers.h"

USING_NSEXButtonImp;

using namespace cocos2d;

bool EXButtonImp::init()
{
    do {
        CC_BREAK_IF(!CCLayer::init());
        
        ignoreAnchorPointForPosition(false);
        
        _state = Invalid;
        _enabled = true;
        _lambda = nullptr;
        
        setTouchPriority(-128);
        setTouchMode(kCCTouchesOneByOne);
        setTouchEnabled(true);
        
        return true;
        
    } while (0);
    
    return false;
}

void EXButtonImp::onExit()
{
    CCLayer::onExit();
}
void EXButtonImp::onEnterTransitionDidFinish()
{
    CCLayer::onEnterTransitionDidFinish();
    
    if (getState() == Invalid)
        setState(Normal);
}

void EXButtonImp::setState(State newState)
{
    _state = newState;
    switchState();
}

void EXButtonImp::switchState()
{
    WarnNotImplemented();
}

void EXButtonImp::activate()
{
    if (m_bVisible && getEnabled() && _lambda)
        _lambda();
}

bool EXButtonImp::swallowTouch(cocos2d::CCTouch *touch)
{
    return isTouchInSelf(touch);
}

bool EXButtonImp::isTouchInSelf(cocos2d::CCTouch *touch)
{
    CCRect rect = CCRect(0, 0,
                         this->getContentSize().width,
                         this->getContentSize().height);
    
    CCPoint point = this->convertTouchToNodeSpace(touch);
    
    return rect.containsPoint(point);
}

void EXButtonImp::setEnabled(bool enabled)
{
    if (_enabled != enabled)
    {
        _enabled = enabled;
    }

    // TODO: put this outside or inside the block above?
    if (!getEnabled())
    {
        setState(Disabled);
    }
    else
    {
        setState(Normal);
    }
}

void EXButtonImp::setLambda(std::function<void ()> lambda)
{
    _lambda = lambda;
}

bool EXButtonImp::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    do {
        CC_BREAK_IF(!m_bVisible || !getEnabled());
        
        if (swallowTouch(touch))
        {
            setState(Selected);
            return true;
        }
        
    } while (0);
    
    return false;
}
void EXButtonImp::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    setState(Selected);
}
void EXButtonImp::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    setState(Normal);
    if (swallowTouch(touch))
    {
        this->activate();
    }
}
void EXButtonImp::ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent* event)
{
    setState(Normal);
}
