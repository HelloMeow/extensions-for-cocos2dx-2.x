//
//  DraggingWrapper.cpp
//
//  Created by HelloMeow on 14-3-14.
//
//

#ifndef __DraggingWrapper__
#define __DraggingWrapper__

#include "cocos2d.h"

class DraggingWrapper : public cocos2d::CCLayer
{
public:
    static cocos2d::CCString* kDraggingWrapperInfo;
    
    typedef enum
    {
        kDraggingWrapperLocationX,
        kDraggingWrapperLocationY,
        kDraggingWrapperSender,
        kDraggingWrapperHasEnded
    }kDraggingWrapper;
    
    static DraggingWrapper* create(cocos2d::CCLayer* wrappedLayer);

protected:
    void broadcastWorldLocation(cocos2d::CCPoint worldLocation, bool hasEnded);
    virtual bool init(cocos2d::CCLayer* wrappedLayer);
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent* event);
private:
    cocos2d::CCLayer* _wrappedLayer;
    DraggingWrapper();
    ~DraggingWrapper();
    cocos2d::CCPoint _movingStartPosition;
};

#endif /* defined(__DraggingWrapper__) */
