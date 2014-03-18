//
//  SurroundingTouchableWrapper.cpp
//
//  Created by HelloMeow on 14-3-17.
//
//

#ifndef __SurroundingTouchableWrapper__
#define __SurroundingTouchableWrapper__

#include "cocos2d.h"

class SurroundingTouchableWrapper : public cocos2d::CCLayer
{
public:
    static SurroundingTouchableWrapper* create(cocos2d::CCNode* wrappedLayer,
                                               cocos2d::CCSize contentSize);
    void setLambda(std::function<void()> lambda);
    
protected:
    virtual bool init(cocos2d::CCNode* wrappedLayer,
                      cocos2d::CCSize contentSize);
    
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    
    SurroundingTouchableWrapper();
    ~SurroundingTouchableWrapper();
    
    bool swallowTouch(cocos2d::CCTouch *touch);
    
private:
    cocos2d::CCNode* _wrappedLayer;
    std::function<void()> _lambda;
};

#endif /* defined(__SurroundingTouchableWrapper__) */
