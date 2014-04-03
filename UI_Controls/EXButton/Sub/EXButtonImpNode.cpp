//
//  EXButtonImpNode.cpp
// 
//
//  Created by HelloMeow on 14-3-10.
//
//

#include "EXButtonImpNode.h"
#include "MacroHelpers.h"
#include "Helpers.h"
#include "CCSpriteMakeFrom.h"
NSEXButtonImp_BEGIN
using namespace cocos2d;
EXButtonImpNode* EXButtonImpNode::create(cocos2d::CCNode* normal,
                                         cocos2d::CCNode* selected,
                                         cocos2d::CCNode* disabled)
{
    EXButtonImpNode* btn = new EXButtonImpNode();
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

bool EXButtonImpNode::init(cocos2d::CCNode* normal,
                           cocos2d::CCNode* selected,
                           cocos2d::CCNode* disabled)
{
    do {
        CC_BREAK_IF(!EXButtonImp::init());
        
        CCSize contentSize = CCSizeZero;
        
        CC_BREAK_IF(!normal && !selected && !disabled);
        
        CC_BREAK_IF(!normal);
        
        _normalNode = normal;
        contentSize = CCSizeMax(contentSize, _normalNode->getContentSize());
        
        if (selected && selected != _normalNode)
        {
            _selectedNode = selected;
            contentSize = CCSizeMax(contentSize, _selectedNode->getContentSize());
        }
        else
        {
            _selectedNode = spriteMakeFrom(_normalNode);
            contentSize = CCSizeMax(contentSize, _selectedNode->getContentSize());
        }
        
        if (disabled &&
            disabled != _normalNode &&
            (!_selectedNode || disabled != _selectedNode))
        {
            _disabledNode = disabled;
            contentSize = CCSizeMax(contentSize, _disabledNode->getContentSize());
        }
        else
        {
            _disabledNode = spriteMakeFrom(_normalNode);
            contentSize = CCSizeMax(contentSize, _disabledNode->getContentSize());
        }
        
        setContentSize(contentSize); // max size of 3 children nodes
        
        // MUST addChild after setContentSize
        if (_selectedNode) addChildToCenter(this, _selectedNode);
        if (_disabledNode) addChildToCenter(this, _disabledNode);
        addChildToCenter(this, _normalNode);
        
        return true;
        
    } while (0);
    
    return false;
}

void EXButtonImpNode::switchState()
{
    
    switch (getState()) {
        case Normal:
        {
            if (_normalNode) _normalNode->setVisible(true);
            if (_selectedNode) _selectedNode->setVisible(false);
            if (_disabledNode) _disabledNode->setVisible(false);
            break;
        }
        case Selected:
        {
            if (_selectedNode) _selectedNode->setVisible(true);
            if (_normalNode) _normalNode->setVisible(false);
            if (_disabledNode) _disabledNode->setVisible(false);
            break;
        }
        case Disabled:
        {
            if (_disabledNode) _disabledNode->setVisible(true);
            if (_normalNode) _normalNode->setVisible(false);
            if (_selectedNode) _selectedNode->setVisible(false);
            break;
        }
        default:
            break;
    }
}

void EXButtonImpNode::setOpacity(GLubyte opacity)
{
    CCLayerRGBA::setOpacity(opacity);
    
    CCRGBAProtocol* castNode = nullptr;
    if (_normalNode)
    {
        castNode = dynamic_cast<CCRGBAProtocol*>(_normalNode);
        if (castNode)
        {
            castNode->setCascadeOpacityEnabled(isCascadeOpacityEnabled());
            castNode->setOpacity(opacity);
        }
    }
    if (_selectedNode)
    {
        castNode = dynamic_cast<CCRGBAProtocol*>(_selectedNode);
        if (castNode)
        {
            castNode->setCascadeOpacityEnabled(isCascadeOpacityEnabled());
            castNode->setOpacity(opacity);
        }
    }
    if (_disabledNode)
    {
        castNode = dynamic_cast<CCRGBAProtocol*>(_disabledNode);
        if (castNode)
        {
            castNode->setCascadeOpacityEnabled(isCascadeOpacityEnabled());
            castNode->setOpacity(opacity);
        }
    }
}

void EXButtonImpNode::setTintColor(cocos2d::ccColor3B& color,
                             NameSpaceEXButtonImp::State state)
{
    CCRGBAProtocol* castNode = nullptr;
    switch (state) {
        case Normal:
        {
            castNode = dynamic_cast<CCRGBAProtocol*>(_normalNode);
            break;
        }
        case Selected:
        {
            castNode = dynamic_cast<CCRGBAProtocol*>(_selectedNode);
            break;
        }
        case Disabled:
        {
            castNode = dynamic_cast<CCRGBAProtocol*>(_disabledNode);
            break;
        }
        default:
            break;
    }
    
    if (castNode)
    {
        castNode->setCascadeColorEnabled(true);
        castNode->setColor(color);
    }
}

NSEXButtonImp_END
