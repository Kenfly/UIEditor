#include "MainScene.h"

using namespace cocos2d;

MainScene::MainScene()

{
}

MainScene::~MainScene()
{
}

CCScene* MainScene::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        MainScene *layer = MainScene::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    bool bRet = false;
    do 
    {
        CC_BREAK_IF(! CCLayer::init());
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();

        bRet = true;
    } while (0);

    return bRet;
}
