//
//  Helpers.cpp
//  TetravexDesigner
//
//  Created by jiuzhang tech on 14-3-13.
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
                              CCPoint relativeAnchorPoint)
{
    addChildRelativeToNode(parent, child, childAnchorPoint,
                           parent, relativeAnchorPoint);
}

void addChildRelativeToNode(CCNode*parent, CCNode *child,
                            CCPoint childAnchorPoint, CCNode* node,
                            CCPoint relativeAnchorPoint)
{
    addChild(parent, child, childAnchorPoint,
             positionAt(node, relativeAnchorPoint));
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