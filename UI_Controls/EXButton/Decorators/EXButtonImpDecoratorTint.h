//
//  EXButtonImpDecoratorTint.h
//  TetravexDesigner
//
//  Created by jiuzhang tech on 14-3-10.
//
//

#ifndef __TetravexDesigner__EXButtonImpDecoratorTint__
#define __TetravexDesigner__EXButtonImpDecoratorTint__

#include "EXButtonImpDecorator.h"

NSEXButtonImp_BEGIN

class EXButtonImpDecoratorTint : public EXButtonImpDecorator
{
public:
    static EXButtonImp* create(EXButtonImp* button,
                            cocos2d::ccColor3B selectedTintedColor,
                            cocos2d::ccColor3B disabledTintedColor);
};

NSEXButtonImp_END

#endif /* defined(__TetravexDesigner__EXButtonImpDecoratorTint__) */
