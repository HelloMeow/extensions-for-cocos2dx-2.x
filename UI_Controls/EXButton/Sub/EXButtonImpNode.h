//
//  EXButtonImpNode.h
// 
//
//  Created by HelloMeow on 14-3-10.
//
//

#ifndef __EXButtonImpNode__
#define __EXButtonImpNode__

#include "EXButtonImp.h"

NSEXButtonImp_BEGIN

class EXButtonImpNode : public EXButtonImp
{
public:
    static EXButtonImpNode* create(cocos2d::CCNode* normal,
                                   cocos2d::CCNode* selected,
                                   cocos2d::CCNode* disabled);
protected:
    using EXButtonImp::init;
    virtual bool init(cocos2d::CCNode* normal,
                      cocos2d::CCNode* selected,
                      cocos2d::CCNode* disabled);

    virtual void switchState();
    virtual void setColor(cocos2d::ccColor3B& color,
                          NameSpaceEXButtonImp::State state);
private:
    cocos2d::CCNode* _normalNode, *_selectedNode, *_disabledNode;
};

NSEXButtonImp_END

#endif /* defined(__EXButtonImpNode__) */
