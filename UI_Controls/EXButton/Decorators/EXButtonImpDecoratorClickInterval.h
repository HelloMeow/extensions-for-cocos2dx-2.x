//
//  EXButtonImpDecoratorClickInterval.h
//  TetravexDesigner
//
//  Created by jiuzhang tech on 14-3-10.
//
//

#ifndef __TetravexDesigner__EXButtonImpDecoratorClickInterval__
#define __TetravexDesigner__EXButtonImpDecoratorClickInterval__

#include "EXButtonImpDecorator.h"

NSEXButtonImp_BEGIN

class EXButtonImpDecoratorClickInterval : public EXButtonImpDecorator
{
public:
    static EXButtonImp* create(EXButtonImp* button, float minClickInterval);
protected:
    using EXButtonImpDecorator::init;
    virtual bool init(EXButtonImp* button, float minClickInterval);
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    long millisecondsNow();
    void enableClick();
private:
    float _minClickInterval;
    float _lastClickTimeStamp;
};

NSEXButtonImp_END

#endif /* defined(__TetravexDesigner__EXButtonImpDecoratorClickInterval__) */
