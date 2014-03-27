#ifndef CCSPRITEMAKEFROM_H_VJDT78YS
#define CCSPRITEMAKEFROM_H_VJDT78YS

#include "cocos2d.h"

cocos2d::CCSprite* spriteMakeFrom(cocos2d::CCNode* var);
cocos2d::CCSprite* spriteMakeFrom(cocos2d::CCSprite* var);
cocos2d::CCSprite* spriteMakeFrom(cocos2d::CCString* imagePath);
cocos2d::CCSprite* spriteMakeFrom(const char* imagePath);
cocos2d::CCSprite* spriteMakeFrom(cocos2d::ccColor3B color3, cocos2d::CCSize size);
cocos2d::CCSprite* spriteMakeFrom(cocos2d::ccColor4B color4, cocos2d::CCSize size);
cocos2d::CCSprite* spriteMakeFrom(const char* imagePath, cocos2d::CCSize size);
#endif /* end of include guard: CCSPRITEMAKEFROM_H_VJDT78YS */
