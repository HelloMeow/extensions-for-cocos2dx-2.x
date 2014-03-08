#include "CCSpriteToCCImage.h"

using cocos2d::CCSize;
using cocos2d::CCRenderTexture;
using cocos2d::CCImage;
using cocos2d::CCSprite;
using cocos2d::CCPoint;

CCImage* CCSpriteToCCImage(cocos2d::CCSprite *sp)
{
    if (!sp) return nullptr;
    
    CCSize sz = sp->getContentSize();
    
    CCRenderTexture* rt = CCRenderTexture::create(sz.width, sz.height);
    rt->begin();
    
    sp->setPosition(CCPointMake(sz.width/2, sz.height/2));
    sp->visit();
    
    rt->end();
    
    return rt->newCCImage();
}
