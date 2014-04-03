#include "CCSpriteMakeFrom.h"
#include "cocos-ext.h"


using cocos2d::CCSprite;
using cocos2d::CCNode;
using cocos2d::CCSize;
using cocos2d::CCRenderTexture;
using cocos2d::CCString;
using cocos2d::ccColor3B;
using cocos2d::ccColor4B;
using cocos2d::CCSizeZero;
using cocos2d::CCLayerColor;
using cocos2d::ccc4;
using cocos2d::extension::CCScale9Sprite;
using cocos2d::CCSpriteBatchNode;
using cocos2d::CCRect;

CCSprite* spriteMakeFrom(CCNode* var)
{
    if (!var) return nullptr;
    
    CCSize size = var->boundingBox().size;
    
    CCRenderTexture* rt = CCRenderTexture::create(size.width, size.height);
    
    rt->begin();
    
    var->ignoreAnchorPointForPosition(false);
    var->setAnchorPoint(ccp(0.5, 0.5));
    var->setPosition(size.width/2, size.height/2);
    var->visit();

    rt->end();
    
    return spriteMakeFromRender(rt->getSprite());
}

cocos2d::CCSprite* spriteMakeFromRender(cocos2d::CCSprite* var)
{
    if (!var) return nullptr;
    
    CCSize size = var->getContentSize();
    
    CCRenderTexture* rt = CCRenderTexture::create(size.width, size.height);
    
    rt->begin();
    
    var->ignoreAnchorPointForPosition(false);
    var->setAnchorPoint(ccp(0.5, 0.5));
    var->setPosition(ccp(size.width/2, size.height/2));
    var->setFlipY(true);
    var->visit();
    
    rt->end();
    
    return spriteMakeFrom(rt->getSprite());
}

CCSprite* spriteMakeFrom(CCSprite* var)
{
    if (!var) return nullptr;
    
    return CCSprite::createWithTexture(var->getTexture());
}
CCSprite* spriteMakeFrom(CCString* imagePath)
{
    return spriteMakeFrom(imagePath ? imagePath->getCString() : nullptr);
}
CCSprite* spriteMakeFrom(const char* imagePath)
{
    using cocos2d::CCFileUtils;
    
    if (imagePath != NULL)
    {
        std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(imagePath);
        
        if( CCFileUtils::sharedFileUtils()->isFileExist(fullPath) )
        {
            return CCSprite::create(imagePath);
        }
    }
    
    return CCSprite::create("Icon.png");
}
CCSprite* spriteMakeFrom(ccColor3B color3, CCSize size)
{
    if (size.equals(CCSizeZero)) return nullptr;
    
    return spriteMakeFrom(ccc4(color3.r, color3.g, color3.b, 0xff), size);
}
CCSprite* spriteMakeFrom(ccColor4B color4, CCSize size)
{
    if (size.equals(CCSizeZero)) return nullptr;
    
    return spriteMakeFrom(CCLayerColor::create(color4, size.width, size.height));
}

cocos2d::CCSprite* spriteMakeFrom(const char* imagePath, cocos2d::CCSize size)
{
    cocos2d::CCSprite* sp_original = spriteMakeFrom(imagePath);
    
    if (sp_original)
    {
        cocos2d::CCSize finalSize = CCSizeMake(MAX(size.width, sp_original->getContentSize().width),
                                               MAX(size.height, sp_original->getContentSize().height));
        
        CCScale9Sprite* s = CCScale9Sprite::create();
        if (s != NULL)
        {
            CCSpriteBatchNode* b = CCSpriteBatchNode::createWithTexture(sp_original->getTexture());
            s->initWithBatchNode(b,
                                 CCRectMake(0,
                                            0,
                                            sp_original->getContentSize().width,
                                            sp_original->getContentSize().height),
                                 CCRectMake(sp_original->getContentSize().width/2-1,
                                            sp_original->getContentSize().height/2-1,
                                            1,
                                            1));
            s->setContentSize(finalSize);
            return spriteMakeFrom((CCNode*)s);
        }

    }
    
    return nullptr;
}