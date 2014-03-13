//
//  EXButtonImpImage.cpp
//  TetravexDesigner
//
//  Created by jiuzhang tech on 14-3-10.
//
//

#include "EXButtonImpImage.h"
#include "MacroHelpers.h"
#include "CCSpriteMakeFrom.h"
#include "Helpers.h"

NSEXButtonImp_BEGIN
using namespace cocos2d;
EXButtonImpImage* EXButtonImpImage::create(const char* normal,
                                     const char* selected,
                                     const char* disabled)
{
    EXButtonImpImage* btn = new EXButtonImpImage();
    if (btn && btn->init(normal,
                         selected,
                         disabled))
    {
        btn->autorelease();
        return btn;
    }
    CC_SAFE_DELETE(btn);
    return nullptr;
}

bool EXButtonImpImage::init(const char* normal,
                         const char* selected,
                         const char* disabled)
{
    do {
        CC_BREAK_IF(!EXButtonImp::init());
        
        CCSize contentSize = CCSizeZero;
        
        CC_BREAK_IF(!normal && !selected && !disabled);
        
        const char* failSafe = normal ? normal : selected ? selected : disabled;
        
        if (!normal) normal = failSafe;
        _normalNode = spriteMakeFrom(normal);
        contentSize = CCSizeMax(contentSize, _normalNode->getContentSize());
        
        if (!selected) selected = failSafe;
        _selectedNode = spriteMakeFrom(selected);
        contentSize = CCSizeMax(contentSize, _selectedNode->getContentSize());
        
        if (!disabled) disabled = failSafe;
        _disabledNode = spriteMakeFrom(disabled);
        contentSize = CCSizeMax(contentSize, _disabledNode->getContentSize());
        
        setContentSize(contentSize); // max size of 3 children nodes
        
        // MUST addChild after setContentSize 
        addChildToCenter(this, _normalNode);
        addChildToCenter(this, _selectedNode);
        addChildToCenter(this, _disabledNode);
        
        return true;
        
    } while (0);
    
    return false;
}

void EXButtonImpImage::switchState()
{
    switch (getState()) {
        case Normal:
        {
            _normalNode->setVisible(true);
            _selectedNode->setVisible(false);
            _disabledNode->setVisible(false);
            break;
        }
        case Selected:
        {
            _selectedNode->setVisible(true);
            _normalNode->setVisible(false);
            _disabledNode->setVisible(false);
            break;
        }
        case Disabled:
        {
            _disabledNode->setVisible(true);
            _normalNode->setVisible(false);
            _selectedNode->setVisible(false);
            break;
        }
        default:
            break;
    }
}
void EXButtonImpImage::setColor(cocos2d::ccColor3B& color,
                             NameSpaceEXButtonImp::State state)
{
    switch (state) {
        case Normal:
        {
            _normalNode->setCascadeColorEnabled(true);
            _normalNode->setColor(color);
            break;
        }
        case Selected:
        {
            _selectedNode->setCascadeColorEnabled(true);
            _selectedNode->setColor(color);
            break;
        }
        case Disabled:
        {
            _disabledNode->setCascadeColorEnabled(true);
            _disabledNode->setColor(color);
            break;
        }
        default:
            break;
    }
}

NSEXButtonImp_END
