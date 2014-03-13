//
//  Helpers.h
//
//
//  Created by HelloMeow on 14-3-13.
//
//

#ifndef __Helpers__
#define __Helpers__

#include "cocos2d.h"

/**
 *  return "" if var is null
 */
const char* safeGetCString(cocos2d::CCString* var);

/**
 *  add child to parent and place it at the center of parent
 *  anchorPoint of child will be set to ccp(0.5, 0.5)
 */
void addChildToCenter(cocos2d::CCNode *parent, cocos2d::CCNode *child);

/**
 *  add child to parent with anchorPoint and position
 */
void addChild(cocos2d::CCNode* parent,
              cocos2d::CCNode* child,
              cocos2d::CCPoint anchorPoint,
              cocos2d::CCPoint position);

/**
 *  add child to parent, and place it at the position at the position of parent at relativeAnchorPoint
 */
void addChildRelativeToParent(cocos2d::CCNode*parent,
                              cocos2d::CCNode *child,
                              cocos2d::CCPoint childAnchorPoint,
                              cocos2d::CCPoint relativeAnchorPoint);

/**
 *  add child to parent, and place it at the position at the position of node at relativeAnchorPoint
 */
void addChildRelativeToNode(cocos2d::CCNode*parent,
                            cocos2d::CCNode *child,
                            cocos2d::CCPoint childAnchorPoint,
                            cocos2d::CCNode* node,
                            cocos2d::CCPoint relativeAnchorPoint);

/**
 *  get the screen position of node at the anchorPoint.
 */
cocos2d::CCPoint positionRelativeToNodeAP(cocos2d::CCNode* obj,
                                          const cocos2d::CCPoint& anchorPoint);

/**
 *  get the position of the node at the anchorPoint, bottom-left corner of the node is ccp(0, 0)
 */
cocos2d::CCPoint positionAt(cocos2d::CCNode* obj,
                            const cocos2d::CCPoint& proportion);

#endif /* defined(__Helpers__) */