//
//  CCStringMakeFrom.cpp
//  TetravexDesigner
//
//  Created by jiuzhang tech on 14-3-13.
//
//

#include "CCStringMakeFrom.h"

using cocos2d::CCPoint;
using cocos2d::CCString;
using cocos2d::CCSize;

CCString* CCStringMakeFrom(CCPoint var)
{
    return CCString::createWithFormat("(%.2f, %.2f)", var.x, var.y);
}

CCString* CCStringMakeFrom(CCSize var)
{
    return CCString::createWithFormat("(%.2f, %.2f)", var.width, var.width);
}

CCString* CCStringMakeFrom(int var)
{
    return CCString::createWithFormat("%d", var);
}

CCString* CCStringMakeFrom(bool var)
{
    return CCString::createWithFormat("%s", var ? "true" : "false");
}

CCString* CCStringMakeFrom(double var)
{
    return CCString::createWithFormat("%.2f", var);
}

CCString* CCStringMakeFrom(const char* var)
{
    return var ? CCString::create(var) : CCString::create("");
}

