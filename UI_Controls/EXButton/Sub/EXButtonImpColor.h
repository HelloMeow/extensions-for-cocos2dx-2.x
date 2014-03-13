//
//  EXButtonImpColor.h
//  TetravexDesigner
//
//  Created by jiuzhang tech on 14-3-10.
//
//

#ifndef __TetravexDesigner__EXButtonImpColor__
#define __TetravexDesigner__EXButtonImpColor__

#include "EXButtonImp.h"
#include "EXButtonImpDefine.h"

NSEXButtonImp_BEGIN

class EXButtonImpColor : public EXButtonImp
{
public:
    static EXButtonImpColor* create(cocos2d::CCSize contentSize,
                                 cocos2d::ccColor4B normal,
                                 cocos2d::ccColor4B selected,
                                 cocos2d::ccColor4B disabled);
protected:
    using EXButtonImp::init;
    virtual bool init(cocos2d::CCSize contentSize,
                      cocos2d::ccColor4B normal,
                      cocos2d::ccColor4B selected,
                      cocos2d::ccColor4B disabled);

    virtual void switchState();
    virtual void setColor(cocos2d::ccColor3B& color, NameSpaceEXButtonImp::State state);
private:
    cocos2d::ccColor4B _normal, _selected, _disabled;
    cocos2d::CCNodeRGBA* _normalNode, *_selectedNode, *_disabledNode;
};

NSEXButtonImp_END

#endif /* defined(__TetravexDesigner__EXButtonImpColor__) */
