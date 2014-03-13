//
//  EXButtonImpDecoratorSize.h
//  TetravexDesigner
//
//  Created by jiuzhang tech on 14-3-10.
//
//

#ifndef __TetravexDesigner__EXButtonImpDecoratorSize__
#define __TetravexDesigner__EXButtonImpDecoratorSize__

#include "EXButtonImpDecorator.h"
#include "EXButtonImpDefine.h"

NSEXButtonImp_BEGIN

class EXButtonImpDecoratorSize : public EXButtonImpDecorator
{
public:
    static EXButtonImp* create(EXButtonImp* button, cocos2d::CCSize size);
protected:
    using EXButtonImpDecorator::init;
    virtual bool init(EXButtonImp* button, cocos2d::CCSize size);
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
};

NSEXButtonImp_END

#endif /* defined(__TetravexDesigner__EXButtonImpDecoratorSize__) */
