//
//  EXButtonImpDefine.h
// 
//
//  Created by HelloMeow on 14-3-11.
//
//

#ifndef _EXButtonImpDefine_h
#define _EXButtonImpDefine_h

#include "cocos2d.h"

#define NSEXButtonImp_BEGIN    namespace NameSpaceEXButtonImp {
#define NSEXButtonImp_END      }
#define USING_NSEXButtonImp    using namespace NameSpaceEXButtonImp

NSEXButtonImp_BEGIN

typedef enum
{
    Invalid,
    Normal,
    Selected,
    Disabled
}State;
    
NSEXButtonImp_END

#endif
