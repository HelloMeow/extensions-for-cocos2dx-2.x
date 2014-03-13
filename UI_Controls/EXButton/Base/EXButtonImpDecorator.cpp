//
//  EXButtonImpDecorator.cpp
// 
//
//  Created by HelloMeow on 14-3-10.
//
//

#include "EXButtonImpDecorator.h"
#include "Helpers.h"

NSEXButtonImp_BEGIN

bool EXButtonImpDecorator::init(EXButtonImp* button)
{
    do {
        CC_BREAK_IF(!EXButtonImp::init());
        CC_BREAK_IF(!button);
        
        setButton(button);
        
        return true;
        
    } while (0);
    
    return false;
}

void EXButtonImpDecorator::setButton(EXButtonImp *button)
{
    if (_button == button) return;
    
    if (_button)
    {
        _button->removeFromParent();
        CC_SAFE_RELEASE_NULL(_button);
    }
    
    if (!button) return; // make SetButton(nullptr); meaningful: remove current _button
    
    setContentSize(button->getContentSize());
    _button = button;
    CC_SAFE_RETAIN(_button);
    
    addChildToCenter(this, _button);
    
    _button->setTouchEnabled(false); // very important, prevent _button's touch event triggered.
}

EXButtonImpDecorator::EXButtonImpDecorator()
{
    _button = nullptr;
}

EXButtonImpDecorator::~EXButtonImpDecorator()
{
    CC_SAFE_RELEASE_NULL(_button);
}

void EXButtonImpDecorator::switchState()
{
    _button->switchState();
}

void EXButtonImpDecorator::activate()
{
    _button->activate();
    EXButtonImp::activate();
}

void EXButtonImpDecorator::setState(State newState)
{
    _button->setState(newState);
    EXButtonImp::setState(newState);
}

void EXButtonImpDecorator::setEnabled(bool enabled)
{
    _button->setEnabled(enabled);
    EXButtonImp::setEnabled(enabled);
}

void EXButtonImpDecorator::setColor(cocos2d::ccColor3B &color, NameSpaceEXButtonImp::State state)
{
    _button->setColor(color, state);
}

bool EXButtonImpDecorator::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    return EXButtonImp::ccTouchBegan(touch, event) && _button->ccTouchBegan(touch, event);
}
void EXButtonImpDecorator::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    _button->ccTouchMoved(touch, event);
    EXButtonImp::ccTouchMoved(touch, event);
}
void EXButtonImpDecorator::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    _button->ccTouchEnded(touch, event);
    EXButtonImp::ccTouchEnded(touch, event);
}
void EXButtonImpDecorator::ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent* event)
{
    _button->ccTouchCancelled(touch, event);
    EXButtonImp::ccTouchCancelled(touch, event);
}

NSEXButtonImp_END
