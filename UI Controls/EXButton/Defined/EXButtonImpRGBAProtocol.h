//
//  EXButtonImpRGBAProtocol.h
//  TetravexDesigner
//
//  Created by jiuzhang tech on 14-3-10.
//
//

#ifndef __TetravexDesigner__EXButtonImpRGBAProtocol__
#define __TetravexDesigner__EXButtonImpRGBAProtocol__

#include "cocos2d.h"
#include "EXButtonImpDefine.h"

NSEXButtonImp_BEGIN

class EXButtonImpRGBAProtocol
{
public:
    virtual void setColor(cocos2d::ccColor3B& color, NameSpaceEXButtonImp::State state);
    
    virtual ~EXButtonImpRGBAProtocol();
};

NSEXButtonImp_END

#endif /* defined(__TetravexDesigner__EXButtonImpRGBA__) */
