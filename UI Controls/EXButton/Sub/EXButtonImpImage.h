//
//  EXButtonImpImage.h
//  TetravexDesigner
//
//  Created by jiuzhang tech on 14-3-10.
//
//

#ifndef __TetravexDesigner__EXButtonImpImage__
#define __TetravexDesigner__EXButtonImpImage__

#include "EXButtonImp.h"

NSEXButtonImp_BEGIN

class EXButtonImpImage : public EXButtonImp
{
public:
    static EXButtonImpImage* create(const char* normal,
                                 const char* selected,
                                 const char* disabled);
protected:
    using EXButtonImp::init;
    virtual bool init(const char* normal,
                      const char* selected,
                      const char* disabled);

    virtual void switchState();
    virtual void setColor(cocos2d::ccColor3B& color, NameSpaceEXButtonImp::State state);
private:
    cocos2d::CCSprite* _normalNode, *_selectedNode, *_disabledNode;
};

NSEXButtonImp_END

#endif /* defined(__TetravexDesigner__EXButtonImpImage__) */
