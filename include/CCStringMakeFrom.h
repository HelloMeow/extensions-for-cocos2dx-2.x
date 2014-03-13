//
//  CCStringMakeFrom.h
// 
//
//  Created by HelloMeow on 14-3-13.
//
//

#ifndef __CCStringMakeFrom__
#define __CCStringMakeFrom__

#include "cocos2d.h"

cocos2d::CCString* CCStringMakeFrom(int var);
cocos2d::CCString* CCStringMakeFrom(bool var);
cocos2d::CCString* CCStringMakeFrom(double var);
cocos2d::CCString* CCStringMakeFrom(const char* var);
cocos2d::CCString* CCStringMakeFrom(cocos2d::CCSize var);
cocos2d::CCString* CCStringMakeFrom(cocos2d::CCPoint var);

#endif /* defined(__CCStringMakeFrom__) */
