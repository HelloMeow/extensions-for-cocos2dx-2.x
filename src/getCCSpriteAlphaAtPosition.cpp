#include "getCCSpriteAlphaAtPosition.h"
#include "CCSpriteToCCImage.h"

using cocos2d::CCPoint;
using cocos2d::CCRect;
using cocos2d::CCImage;
using cocos2d::CCSprite;

float getCCSpriteAlphaAtPosition(cocos2d::CCSprite *sp, cocos2d::CCPoint position)
{
    if (!sp) return .0f;
    
    bool touchInSelf = CCRectMake(0, 0,
                                  sp->getContentSize().width,
                                  sp->getContentSize().height).containsPoint(position);
    if (!touchInSelf) return .0f;
    
    CCImage *img= CCSpriteToCCImage(sp);
    if (!img || !img->hasAlpha())
        return .0f;
    
    unsigned char *data = img->getData();
    
    int i = (int)position.x;
    int j = (int)position.y;
    
    if (i >= img->getWidth() || i < 0) return .0f;
    if (j >= img->getHeight() || j < 0) return .0f;
    
    // [0][0] => Left-Top Pixel !
    // But cocos2d Location Y-axis is Bottom(0) to Top(max)

    unsigned char *pixel = data + (i + (img->getHeight() - j) * img->getWidth()) * 4;
    return *(pixel+3);
}
