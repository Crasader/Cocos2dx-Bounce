//
//  TipsLayer.cpp
//  2333
//
//  Created by pjpjpj on 2017/7/24.
//
//

#include "TipsLayer.hpp"

Layer* TipsLayer::createLayer() {
    return TipsLayer::create();
}

bool TipsLayer::init() {
    if (!Layer::init()) {
        return false;
    }
    
    auto visibaleSize = Director::getInstance()->getWinSize();
    
    fingerSprite = Sprite::create("res/finger.png");
    addChild(fingerSprite);
    fingerSprite->setContentSize(Size(60, 105));
    fingerSprite->setPosition(Vec2(visibaleSize.width / 2, visibaleSize.height / 2));
    
    auto move = MoveBy::create(1.0f, Vec2(0, -150));
    fingerSprite->runAction(RepeatForever::create(static_cast<Sequence *>(Sequence::create(move,move->reverse(),NULL))));
    
    tipsLabel = Label::createWithTTF("点击屏幕向下滑，发射小球", "fonts/chinese.ttf", 33);
    tipsLabel->setTextColor(Color4B(108, 108, 108, 255));
    addChild(tipsLabel);
    tipsLabel->setPosition(visibaleSize.width / 2, visibaleSize.height / 3 - 50);
    
    //    changeLabel = Label::createWithTTF("格子到达地面你就输了！", "fonts/chinese.ttf", 33);
    //    addChild(changeLabel);
    //    changeLabel->setTextColor(Color4B(108, 108, 108, 255));
    //    changeLabel->setPosition(visibaleSize.width / 2, visibaleSize.height / 3 - 50);
    //    changeLabel->setVisible(false);
    
    return true;
}

void TipsLayer::changeShow() {
    fingerSprite->setVisible(false);
    tipsLabel->setVisible(false);
}

