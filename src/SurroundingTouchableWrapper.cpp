//
//  SurroundingTouchableWrapper.cpp
//
//  Created by HelloMeow on 14-3-17.
//
//

#include "SurroundingTouchableWrapper.h"
#include "CXHeaders.h"

using namespace cocos2d;

SurroundingTouchableWrapper* SurroundingTouchableWrapper::create(cocos2d::CCNode* wrappedLayer,
                                           cocos2d::CCSize contentSize)
{
    SurroundingTouchableWrapper* pRet = new SurroundingTouchableWrapper;
    if (pRet && pRet->init(wrappedLayer,contentSize))
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

SurroundingTouchableWrapper::SurroundingTouchableWrapper()
{
    _wrappedLayer = nullptr;
}

SurroundingTouchableWrapper::~SurroundingTouchableWrapper()
{
    CC_SAFE_RELEASE_NULL(_wrappedLayer);
}

void SurroundingTouchableWrapper::setLambda(std::function<void ()> lambda)
{
    _lambda = lambda;
}

bool SurroundingTouchableWrapper::init(cocos2d::CCNode *wrappedLayer,
                                 cocos2d::CCSize contentSize)
{
    do {
        CC_BREAK_IF(!CCLayer::init());
        
        ignoreAnchorPointForPosition(false);
        setContentSize(contentSize);
        
        CC_BREAK_IF(!wrappedLayer);
        
        _wrappedLayer = wrappedLayer;
        CC_SAFE_RETAIN(_wrappedLayer);

        addChildToCenter(this, _wrappedLayer);
        
        setTouchPriority(-128);
        setTouchMode(kCCTouchesOneByOne);
        setTouchEnabled(true);
        
        return true;
        
    } while (0);
    
    return false;
}

bool SurroundingTouchableWrapper::swallowTouch(cocos2d::CCTouch *touch)
{
    CCRect rect = CCRect(0, 0,
                         this->getContentSize().width,
                         this->getContentSize().height);
    
    CCPoint point = this->convertTouchToNodeSpace(touch);
    
    if (rect.containsPoint(point))
    {
        rect = CCRect(0, 0,
                      _wrappedLayer->getContentSize().width,
                      _wrappedLayer->getContentSize().height);
        point = _wrappedLayer->convertTouchToNodeSpace(touch);
        if (!rect.containsPoint(point))
        {
            return true;
        }
        return true;
    }
    
    return false;
}

bool SurroundingTouchableWrapper::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    do {
        CC_BREAK_IF(!m_bVisible);
        
        if (swallowTouch(touch)) return true;
        
    } while (0);
    
    return false;
}
void SurroundingTouchableWrapper::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
    if (swallowTouch(touch))
    {
        if (_lambda) _lambda();
    }
}
