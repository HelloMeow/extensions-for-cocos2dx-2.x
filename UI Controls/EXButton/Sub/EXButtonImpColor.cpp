//
//  EXButtonImpColor.cpp
//  TetravexDesigner
//
//  Created by jiuzhang tech on 14-3-10.
//
//

#include "EXButtonImpColor.h"
#include "Helpers.h"

NSEXButtonImp_BEGIN

using namespace cocos2d;

EXButtonImpColor* EXButtonImpColor::create(cocos2d::CCSize contentSize,
                                     cocos2d::ccColor4B normal,
                                     cocos2d::ccColor4B selected,
                                     cocos2d::ccColor4B disabled)
{
    EXButtonImpColor* btn = new EXButtonImpColor();
    if (btn && btn->init(contentSize, normal, selected, disabled))
    {
        btn->autorelease();
        return btn;
    }
    CC_SAFE_DELETE(btn);
    return nullptr;
}

bool EXButtonImpColor::init(cocos2d::CCSize contentSize,
                         cocos2d::ccColor4B normal,
                         cocos2d::ccColor4B selected,
                         cocos2d::ccColor4B disabled)
{
    do {
        CC_BREAK_IF(!EXButtonImp::init());
        
        setContentSize(contentSize);
        
        _normal = normal;
        _selected = selected;
        _disabled = disabled;
        
        _normalNode = createRGBANode(contentSize);
        _selectedNode = createRGBANode(contentSize);
        _disabledNode = createRGBANode(contentSize);
        
        addChildToCenter(this, _normalNode);
        
        return true;
        
    } while (0);
    
    return false;
}

void EXButtonImpColor::setColor(cocos2d::ccColor3B& color,
                                NameSpaceEXButtonImp::State state)
{
    _colorNode->setColor(color);
}

void EXButtonImpColor::switchState()
{
    switch (getState()) {
        case Normal:
        {
            _colorNode->setBackgroundColor(_normal);
            break;
        }
        case Selected:
        {
            _colorNode->setBackgroundColor(_selected);
            break;
        }
        case Disabled:
        {
            _colorNode->setBackgroundColor(_disabled);
            break;
        }
        default:
            break;
    }
}

NSEXButtonImp_END
