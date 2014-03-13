//
//  EXButtonImpDecoratorLongPress.h
//  TetravexDesigner
//
//  Created by jiuzhang tech on 14-3-10.
//
//

#ifndef __TetravexDesigner__EXButtonImpDecoratorLongPress__
#define __TetravexDesigner__EXButtonImpDecoratorLongPress__

#include "EXButtonImpDecorator.h"

NSEXButtonImp_BEGIN

class EXButtonImpDecoratorLongPress : public EXButtonImpDecorator
{
public:
    static EXButtonImp* create(EXButtonImp* button, float timeThreshold);
    
protected:
    using EXButtonImpDecorator::init;
    virtual bool init(EXButtonImp* button, float timeThreshold);
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent* event);
    
private:
    float _timeThreshold;
};

NSEXButtonImp_END

#endif /* defined(__TetravexDesigner__EXButtonImpDecoratorLongPress__) */
