//
//  DraggingWrapper.cpp
//
//  Created by HelloMeow on 14-3-14.
//
//

#include "DraggingWrapper.h"
#include "Helpers.h"
using namespace cocos2d;

CCString* DraggingWrapper::kDraggingWrapperInfo = new CCString("kDraggingWrapperInfo");

DraggingWrapper::DraggingWrapper()
{
    _wrappedLayer = nullptr;
}

DraggingWrapper::~DraggingWrapper()
{
    CC_SAFE_RELEASE_NULL(_wrappedLayer);
}

bool DraggingWrapper::init(cocos2d::CCLayer *wrappedLayer)
{
    do {
        CC_BREAK_IF(!CCLayer::init());
        
        CC_BREAK_IF(!wrappedLayer);
        
        _wrappedLayer = wrappedLayer;
        CC_SAFE_RETAIN(_wrappedLayer);
        
        // disable _wrappedLayer touchability to receive touch event itself.
        _wrappedLayer->setTouchEnabled(false);
        
        ignoreAnchorPointForPosition(false);
        setContentSize(_wrappedLayer->getContentSize());
        
        addChildToCenter(this, _wrappedLayer);
        
        setTouchPriority(-128);
        setTouchMode(kCCTouchesOneByOne);
        setTouchEnabled(true);
        
        return true;
    } while (0);
    
    return false;
}

DraggingWrapper* DraggingWrapper::create(cocos2d::CCLayer* wrappedLayer)
{
    DraggingWrapper* pRet = new DraggingWrapper;
    if (pRet && pRet->init(wrappedLayer))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }  
}

bool DraggingWrapper::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    do {
        CC_BREAK_IF(!m_bVisible);
        
        CCRect rect = CCRect(0, 0,
                             this->getContentSize().width,
                             this->getContentSize().height);
        
        CCPoint point = this->convertTouchToNodeSpace(touch);
        
        if (rect.containsPoint(point))
        {
            _movingStartPosition = touch->getLocation();
            return true;
        }
        
    } while (0);
    
    return false;
}
void DraggingWrapper::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    setPosition(ccpAdd(getPosition(), ccpSub(touch->getLocation(), _movingStartPosition)));
    _movingStartPosition = touch->getLocation();
    broadcastWorldLocation(touch->getLocation(), false);
}
void DraggingWrapper::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    _movingStartPosition = CCPointZero;
    broadcastWorldLocation(touch->getLocation(), true);
}
void DraggingWrapper::ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent* event)
{
    _movingStartPosition = CCPointZero;
    broadcastWorldLocation(touch->getLocation(), true);
}

void DraggingWrapper::broadcastWorldLocation(cocos2d::CCPoint worldLocation, bool hasEnded)
{
    CCDictionary* extraInfo = CCDictionary::create();
    extraInfo->setObject(CCDouble::create(worldLocation.x), kDraggingWrapperLocationX);
    extraInfo->setObject(CCDouble::create(worldLocation.y), kDraggingWrapperLocationY);
    extraInfo->setObject(this, kDraggingWrapperSender);
    extraInfo->setObject(CCBool::create(hasEnded), kDraggingWrapperHasEnded);
    
    CCNotificationCenter::sharedNotificationCenter()->postNotification(kDraggingWrapperInfo->getCString(),
                                                                       extraInfo);
}
