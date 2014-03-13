//
//  EXButtonImp.cpp
//  TetravexDesigner
//
//  Created by jiuzhang tech on 14-3-10.
//
//

#include "EXButton.h"
#include "Helpers.h"
#include "CCSpriteMakeFrom.h"
#include "EXButtonImpNode.h"
#include "EXButtonImpDecoratorLongPress.h"
#include "EXButtonImpDecoratorSize.h"
#include "EXButtonImpDecoratorTint.h"
#include "EXButtonImpDecoratorToggle.h"
#include "EXButtonImpDecoratorClickInterval.h"

USING_NSEXButtonImp;

using namespace cocos2d;

#define CREATE_EXBUTTON(_buttonImp_) ({\
    EXButton* btn = new EXButton(); \
    if (btn && btn->init(_buttonImp_)) \
        btn->autorelease(); \
    else \
        CC_SAFE_DELETE(btn); \
    btn; \
})

EXButton::EXButton()
{
    _buttonImp = nullptr;
}

bool EXButton::init(EXButtonImp *buttonImp)
{
    if (!buttonImp) return false;
    
    _buttonImp = buttonImp;
    CC_SAFE_RETAIN(_buttonImp);
    
    ignoreAnchorPointForPosition(false);
    setContentSize(_buttonImp->getContentSize());
    addChildToCenter(this, _buttonImp);
    return true;
}

EXButton::~EXButton()
{
    CC_SAFE_RELEASE_NULL(_buttonImp);
}

EXButton* EXButton::createButtonWithImage(cocos2d::CCString* normal,
                                          cocos2d::CCString* selected,
                                          cocos2d::CCString* disabled)
{
    return createButtonWithImage(safeGetCString(normal),
                                 safeGetCString(selected),
                                 safeGetCString(disabled));
}

EXButton* EXButton::createButtonWithImage(const char* normal,
                                          const char* selected,
                                          const char* disabled)
{
    CCSprite *normalSprite = nullptr,
    *selectedSprite = nullptr,
    *disabledSprite = nullptr;
    
    const char* failSafe = normal ? normal : selected ? selected : disabled;
    
    if (!normal) normal = failSafe;
    normalSprite = spriteMakeFrom(normal);
    
    if (!selected) selected = failSafe;
    selectedSprite = spriteMakeFrom(selected);
    
    if (!disabled) disabled = failSafe;
    disabledSprite = spriteMakeFrom(disabledSprite);
    
    EXButtonImp* btnImp = EXButtonImpNode::create(normalSprite,
                                                  selectedSprite,
                                                  disabledSprite);
    return CREATE_EXBUTTON(btnImp);
}

EXButton* EXButton::createButtonWithNode(cocos2d::CCNode* normal,
                                         cocos2d::CCNode* selected,
                                         cocos2d::CCNode* disabled)
{
    EXButtonImp* btnImp = EXButtonImpNode::create(normal, selected, disabled);
    return CREATE_EXBUTTON(btnImp);
}

EXButton* EXButton::createButtonWithColor(cocos2d::CCSize contentSize,
                                                       cocos2d::ccColor4B normal,
                                                       cocos2d::ccColor4B selected,
                                                       cocos2d::ccColor4B disabled)
{
    CCLayerColor* normalNode = CCLayerColor::create(normal, contentSize.width, contentSize.height);
    CCLayerColor* selectedNode = CCLayerColor::create(selected, contentSize.width, contentSize.height);
    CCLayerColor* disabledNode = CCLayerColor::create(disabled, contentSize.width, contentSize.height);
    
    EXButtonImp* btnImp = EXButtonImpNode::create(normalNode,
                                                  selectedNode,
                                                  disabledNode);
    return CREATE_EXBUTTON(btnImp);
}

EXButton* EXButton::createLongPressButton(EXButton *button, float timeThreshold)
{
    if (!button) return nullptr;
    EXButtonImp* btnImp = EXButtonImpDecoratorLongPress::create(button->_buttonImp,
                                                                timeThreshold);
    return CREATE_EXBUTTON(btnImp);
}

EXButton* EXButton::createButtonWithExtraTouchArea(EXButton* button,
                                                   cocos2d::CCSize extraSize)
{
    if (!button) return nullptr;
    EXButtonImp* btnImp = EXButtonImpDecoratorSize::create(button->_buttonImp,
                                                           extraSize);
    return CREATE_EXBUTTON(btnImp);
}

EXButton* EXButton::createTintedButton(EXButton* button,
                                       cocos2d::ccColor3B selectedTintedColor,
                                       cocos2d::ccColor3B disabledTintedColor)
{
    if (!button) return nullptr;
    EXButtonImp* btnImp = EXButtonImpDecoratorTint::create(button->_buttonImp,
                                                           selectedTintedColor,
                                                           disabledTintedColor);
    return CREATE_EXBUTTON(btnImp);
}

EXButton* EXButton::createButtonWithClickInterval(EXButton *button,
                                                  float interval)
{
    if (!button) return nullptr;
    EXButtonImp* btnImp = EXButtonImpDecoratorClickInterval::create(button->_buttonImp,
                                                                    interval);
    return CREATE_EXBUTTON(btnImp);
}

EXButton* EXButton::createToggledButtons(cocos2d::CCArray *buttons)
{
    if (!buttons || buttons->count()<=0) return nullptr;
    
    CCArray* buttonImps = CCArray::create();
    for (int i=0; i<buttons->count(); i++)
    {
        EXButtonImp* btnImp = ((EXButton*)buttons->objectAtIndex(i))->_buttonImp;
        buttonImps->addObject(btnImp);
    }
    
    EXButtonImp* btnImp = EXButtonImpDecoratorToggle::create(buttonImps);
    return CREATE_EXBUTTON(btnImp);
}

#pragma mark - properties

void EXButton::setEnabled(bool enabled)
{
    _buttonImp->setEnabled(enabled);
}

bool EXButton::getEnabled()
{
    return _buttonImp->getEnabled();
}

void EXButton::setLambda(std::function<void ()> lambda)
{
    _buttonImp->setLambda(lambda);
}

#undef CREATE_EXBUTTON
