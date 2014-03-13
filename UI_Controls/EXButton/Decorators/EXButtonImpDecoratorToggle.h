//
//  EXButtonImpDecoratorToggle.h
// 
//
//  Created by HelloMeow on 14-3-10.
//
//

#ifndef __EXButtonImpDecoratorToggle__
#define __EXButtonImpDecoratorToggle__

#include "EXButtonImpDecorator.h"

NSEXButtonImp_BEGIN

class EXButtonImpDecoratorToggle : public EXButtonImpDecorator
{
public:
    static EXButtonImp* create(cocos2d::CCArray* exButtonArray);
    
protected:
    using EXButtonImpDecorator::init;
    virtual bool init(cocos2d::CCArray* exButtonArray);
    virtual void activate();
private:
    cocos2d::CCArray* _buttons;
    int _selectedIndex;
    EXButtonImpDecoratorToggle();
    virtual ~EXButtonImpDecoratorToggle();
};

NSEXButtonImp_END

#endif /* defined(__EXButtonImpDecoratorToggle__) */
