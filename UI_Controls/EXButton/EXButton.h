//
//  EXButtonImp.h
// 
//
//  Created by HelloMeow on 14-3-10.
//
//

#ifndef __EXButton__
#define __EXButton__

#include "cocos2d.h"

#define EXButtonDefaultSelectedColor            cocos2d::ccc3(150, 150, 150)
#define EXButtonDefaultDisabledColor            cocos2d::ccc3(126, 126, 126)
#define EXButtonDefaultLongPressTimeThreshold   0.2f

class EXButtonImp;
class EXButton
: public cocos2d::CCLayer
{
public:
    
    static EXButton* createButtonWithImage(cocos2d::CCString* normal,
                                           cocos2d::CCString* selected,
                                           cocos2d::CCString* disabled);
    
    static EXButton* createButtonWithImage(const char* normal,
                                           const char* selected,
                                           const char* disabled);
    
    static EXButton* createButtonWithNode(cocos2d::CCNode* normal,
                                          cocos2d::CCNode* selected,
                                          cocos2d::CCNode* disabled);
    
    static EXButton* createButtonWithColor(cocos2d::CCSize contentSize,
                                           cocos2d::ccColor4B normal,
                                           cocos2d::ccColor4B selected,
                                           cocos2d::ccColor4B disabled);
    
    static EXButton* createLongPressButton(EXButton* button,
                                           float timeThreshold
                                           = EXButtonDefaultLongPressTimeThreshold);
    
    static EXButton* createButtonWithExtraTouchArea(EXButton* button,
                                                    cocos2d::CCSize extraSize);
    
    static EXButton* createTintedButton(EXButton* button,
                                        cocos2d::ccColor3B selectedTintedColor
                                        = EXButtonDefaultSelectedColor,
                                        cocos2d::ccColor3B disabledTintedColor
                                        = EXButtonDefaultDisabledColor);
    
    static EXButton* createButtonWithClickInterval(EXButton* button,
                                                   float interval);
    
    static EXButton* createToggledButtons(cocos2d::CCArray* buttons);
    
public:
    
    /**
     *  Return enable state
     */
    bool getEnabled();
    
    /**
     *  enable/disable the button
     */
    void setEnabled(bool enabled);
    
    /**
     *  Set callback lambda when pressed.
     */
    void setLambda(std::function<void()> lambda);
    
private:
    using CCLayer::init;
    bool init(EXButtonImp* buttonImp);
    EXButton();
    ~EXButton();
    EXButtonImp* _buttonImp;
};

#endif /* defined(__EXButtonImp__) */
