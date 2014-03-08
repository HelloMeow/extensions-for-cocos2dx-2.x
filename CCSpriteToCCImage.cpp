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