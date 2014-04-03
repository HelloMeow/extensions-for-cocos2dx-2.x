//
//  EXButtonImpRGBAProtocol.h
// 
//
//  Created by HelloMeow on 14-3-10.
//
//

#ifndef __EXButtonImpRGBAProtocol__
#define __EXButtonImpRGBAProtocol__

#include "cocos2d.h"
#include "EXButtonImpDefine.h"

NSEXButtonImp_BEGIN

class EXButtonImpRGBAProtocol
{
public:
    virtual void setTintColor(cocos2d::ccColor3B& color,
                              NameSpaceEXButtonImp::State state);
    
    virtual ~EXButtonImpRGBAProtocol();
};

NSEXButtonImp_END

#endif /* defined(__EXButtonImpRGBA__) */
