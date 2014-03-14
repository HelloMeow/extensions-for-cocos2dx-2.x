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

/**
 *  replacement of CCMenu/CCMenuItem ...
 *  3 states: normal, selected and disabled
 *  can directly respond to user touch
 *  take advantage of C++11 lambda to replace target and selector.
 *
 *  e.g:
 *
 *  EXButton* btn = EXButton::createButtonWithImage("xxx.png", "yyy.png", "zzz.png");
 *  btn->setLambda([=]{
 *      // do operation after the button is pressed.
 *  });
 *  someNode->addChild(btn);
 */

class EXButtonImp;
class EXButton
: public cocos2d::CCLayer
{
public:
    
    /**
     *  The following two methods will create EXButton* with image path, 
     *  at least one parameter is not nullptr and valid image path.
     *
     *  @param normal   image path for normal state representation.
     *  @param selected image path for selected state representation.
     *  @param disabled image path for disabled state representation.
     *
     *  @return EXButton*
     */
    static EXButton* createButtonWithImage(cocos2d::CCString* normal,
                                           cocos2d::CCString* selected,
                                           cocos2d::CCString* disabled);
    
    static EXButton* createButtonWithImage(const char* normal,
                                           const char* selected,
                                           const char* disabled);
    
    /**
     *  create EXButton* with 3 CCNode*, at least normal cannot be nullptr.
     *
     *  @param normal   CCNode* to represent normal state.
     *  @param selected CCNode* to represent selected state.
     *  @param disabled CCNode* to represent disabled state.
     *
     *  @return EXButton*
     */
    static EXButton* createButtonWithNode(cocos2d::CCNode* normal,
                                          cocos2d::CCNode* selected,
                                          cocos2d::CCNode* disabled);
    
    /**
     *  create a button with specified color, usually for debugging use.
     *
     *  @param contentSize button size
     *  @param normal      ccColor4B, if alpha is zero, then the button will be transparent.
     *  @param selected    ccColor4B
     *  @param disabled    ccColor4B
     *
     *  @return EXButton*
     */
    static EXButton* createButtonWithColor(cocos2d::CCSize contentSize,
                                           cocos2d::ccColor4B normal,
                                           cocos2d::ccColor4B selected,
                                           cocos2d::ccColor4B disabled);
    /**
     *  to add long press functionality to passed-in button.
     *
     *  @param button                                passed-in EXButton*
     *  @param EXButtonDefaultLongPressTimeThreshold long press time threshold
     *
     *  @return a wrapped EXButton*
     */
    static EXButton* createLongPressButton(EXButton* button,
                                           float timeThreshold
                                           = EXButtonDefaultLongPressTimeThreshold);
    /**
     *  to provide a bigger touch respond area than the button itself.
     *
     *  @param button    EXButton*
     *  @param extraSize generally greater than button's contentSize, can be any value
     *
     *  @return a wrapped EXButton* with reponsive area equal or greater than original button's contentSize.
     */
    static EXButton* createButtonWithExtraTouchArea(EXButton* button,
                                                    cocos2d::CCSize extraSize);
    /**
     *  tint the EXButton* when in state of Selected and Disabled.
     *
     *  @param button                       passed-in EXButton*
     *  @param EXButtonDefaultSelectedColor ccColor3B
     *  @param EXButtonDefaultDisabledColor ccColor3B
     *
     *  @return a wrapped EXButton*
     */
    static EXButton* createTintedButton(EXButton* button,
                                        cocos2d::ccColor3B selectedTintedColor
                                        = EXButtonDefaultSelectedColor,
                                        cocos2d::ccColor3B disabledTintedColor
                                        = EXButtonDefaultDisabledColor);
    
    /**
     *  time interval between two triggers must be at least passed-in interval seconds.
     *
     *  @return a wrapped EXButton*
     */
    static EXButton* createButtonWithClickInterval(EXButton* button,
                                                   float interval);
    
    /**
     *  replacement of CCMenuItemToggle, the order in array decides the display order.
     *
     *  @param buttons array of EXButton*
     *
     *  @return a new EXButton* to trigger each EXButton* in array in sequence.
     */
    static EXButton* createToggledButtons(cocos2d::CCArray* buttons);
    
    static EXButton* createHoldGestureCheckedButton(EXButton* button,
                                                    float holdTimeThreshould);
    
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
    
    /**
     *  Simulate CCLayer behaviors
     */
    virtual bool isTouchEnabled();
    virtual void setTouchEnabled(bool value);
    
private:
    using CCLayer::init;
    bool init(EXButtonImp* buttonImp);
    EXButton();
    ~EXButton();
    EXButtonImp* _buttonImp;
};

#endif /* defined(__EXButtonImp__) */
