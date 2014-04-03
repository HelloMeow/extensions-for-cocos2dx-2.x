//
//  EXButtonImpDecoratorTint.cpp
// 
//
//  Created by HelloMeow on 14-3-10.
//
//

#include "EXButtonImpDecoratorTint.h"
#include "EXButtonImpDefine.h"

NSEXButtonImp_BEGIN
using namespace cocos2d;
EXButtonImp* EXButtonImpDecoratorTint::create(EXButtonImp *button,
                                        cocos2d::ccColor3B selectedTintedColor,
                                        cocos2d::ccColor3B disabledTintedColor)
{
    EXButtonImpDecoratorTint* btn = new EXButtonImpDecoratorTint;
    if (btn && btn->init(button))
    {
        btn->setTintColor(selectedTintedColor, Selected);
        btn->setTintColor(disabledTintedColor, Disabled);
        
        btn->autorelease();
        return btn;
    }
    CC_SAFE_DELETE(btn);
    return nullptr;
}

NSEXButtonImp_END
