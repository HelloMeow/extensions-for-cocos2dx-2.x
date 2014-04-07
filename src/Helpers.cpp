//
//  Helpers.cpp
// 
//
//  Created by HelloMeow on 14-3-13.
//
//

#include "Helpers.h"
#include "MacroHelpers.h"

using cocos2d::CCString;
using cocos2d::CCNode;
using cocos2d::CCPoint;
using cocos2d::CCNodeRGBA;

const char* safeGetCString(CCString* var)
{
    return var ? var->getCString() : "";
}

CCPoint positionRelativeToNodeAP(CCNode* obj, const CCPoint& anchorPoint)
{
    assert(obj);
    
    return CCPointMake(obj->getPositionX() +
                       obj->getContentSize().width *
                       (anchorPoint.x - obj->getAnchorPoint().x),
                       
                       obj->getPositionY() +
                       obj->getContentSize().height *
                       (anchorPoint.y - obj->getAnchorPoint().y));
}
CCPoint positionAt(CCNode* obj, const CCPoint& proportion)
{
    assert(obj);
    
    return CCPointMake(obj->getContentSize().width * proportion.x,
                       obj->getContentSize().height * proportion.y);
}

void addChildToCenter(CCNode *parent, CCNode *child)
{
    addChildRelativeToParent(parent, child, AP_Center, AP_Center);
}

void addChildRelativeToParent(CCNode*parent, CCNode *child,
                              CCPoint childAnchorPoint,
                              CCPoint relativeAnchorPoint,
                              CCPoint extraPosition)
{
    addChild(parent, child, childAnchorPoint,
             cocos2d::ccpAdd(positionAt(parent, relativeAnchorPoint), extraPosition));
}

void addChildRelativeToNode(CCNode*parent, CCNode *child,
                            CCPoint childAnchorPoint, CCNode* node,
                            CCPoint relativeAnchorPoint,
                            CCPoint extraPosition)
{
    addChild(parent, child, childAnchorPoint,
             cocos2d::ccpAdd(positionRelativeToNodeAP(node, relativeAnchorPoint),
                             extraPosition));
}

void addChild(CCNode* parent, CCNode* child, CCPoint anchorPoint,
              CCPoint position)
{
    if (!parent || !child) return;
    child->removeFromParent();
    parent->addChild(child);
    child->ignoreAnchorPointForPosition(false);
    child->setAnchorPoint(anchorPoint);
    child->setPosition(position);
}

cocos2d::CCNodeRGBA* createRGBANode(cocos2d::CCSize contentSize)
{
    cocos2d::CCNodeRGBA* node = new CCNodeRGBA;
    if (!node) return nullptr;
    node->autorelease();
    node->ignoreAnchorPointForPosition(false);
    node->setContentSize(contentSize);
    return node;
}

CCNode* emptyNode(cocos2d::CCSize contentSize)
{
    cocos2d::CCNode* n = cocos2d::CCNode::create();
    n->setContentSize(contentSize);
    return n;
}

cocos2d::CCNode* colorNode(cocos2d::CCSize contentSize, cocos2d::ccColor4B color4B)
{
    cocos2d::CCNode* node = emptyNode(contentSize);
    node->setBackgroundColor(color4B);
    return node;
}

cocos2d::CCSprite* spriteWithPatternImage(const char* image,
                                          cocos2d::CCSize finalSize,
                                          float margin,
                                          float padding)
{
    if (!image) return nullptr;
    
    return spriteWithPatternSprite(cocos2d::CCSprite::create(image), finalSize,
                                   margin, padding);
}

cocos2d::CCSprite* spriteWithPatternSprite(cocos2d::CCSprite* sp,
                                           cocos2d::CCSize finalSize,
                                           float margin,
                                           float padding)
{
    if (!sp) return nullptr;
    
    cocos2d::CCRenderTexture* rt = cocos2d::CCRenderTexture::create(finalSize.width,
                                                                    finalSize.height);
    
    int extraCol = fmod(finalSize.width - 2*margin, sp->getContentSize().width + padding) == 0 ? 0 : 1;
    int extraRow = fmod(finalSize.height - 2*margin, sp->getContentSize().height + padding) == 0 ? 0 : 1;
    int cols = (int)((finalSize.width - 2*margin) / (sp->getContentSize().width + padding)) + extraCol;
    int rows = (int)((finalSize.height - 2*margin) / (sp->getContentSize().height + padding)) + extraRow;
    
    rt->begin();
    
    float x = 0;
    float y = margin;
    for (int i=0; i<rows; i++)
    {
        x = margin;        for (int j=0; j<cols; j++)
        {
            cocos2d::CCSprite* spPlaced = cocos2d::CCSprite::createWithTexture(sp->getTexture());
            spPlaced->setPosition(ccpAdd(ccp(sp->boundingBox().size.width/2,
                                             sp->boundingBox().size.height/2),
                                         ccp(x, y)));
            x += sp->boundingBox().size.width + padding;
            spPlaced->setFlipY(true);
            spPlaced->visit();
        }
        y += sp->getContentSize().height + padding;
    }
    
    rt->end();
    
    return cocos2d::CCSprite::createWithTexture(rt->getSprite()->getTexture());
}
