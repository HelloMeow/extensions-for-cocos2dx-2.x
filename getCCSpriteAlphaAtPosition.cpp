float getCCSpriteAlphaAtPosition(cocos2d::CCSprite *sp, cocos2d::CCPoint position)
{
    if (!sp) return 0.0f;
    
    CCPoint touchLocationInSelf = sp->convertToNodeSpace(position);
    bool touchInSelf = CCRectMake(0, 0,
                                  sp->getContentSize().width,
                                  sp->getContentSize().height).containsPoint(touchLocationInSelf);
    if (!touchInSelf) return 0.0f;
    
    CCImage *img= CCSpriteToCCImage(sp);
    if (!img || !img->hasAlpha())
        return 0.0f;
    
    int x=4;
    
    unsigned char *data = new unsigned char[img->getDataLen()*x];
    data = img->getData();
    
    int i = (int)position.x;
    int j = (int)position.y;
    
    if (i >= img->getWidth() || i < 0) return 0;
    if (j >= img->getHeight() || j < 0) return 0;
    
    // [0][0] => Left-Top Pixel !
    // But cocos2d Location Y-axis is Bottom(0) to Top(max)

    unsigned char *pixel = data + (i + (img->getHeight() - j) * img->getWidth()) * x;
    return *(pixel+3);
}