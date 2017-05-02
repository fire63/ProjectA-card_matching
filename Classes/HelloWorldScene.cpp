#include "HelloWorldScene.h"

Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();

	auto layer = HelloWorld::create();
	scene->addChild(layer);

	return scene;
}

bool HelloWorld::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	auto spr = Sprite::create("Icon-57.png");
	spr->setPosition(Point(100, 100));
	spr->setTag(1);
	this->addChild(spr);

	return true;
}

bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event)
{
	CCLOG("onTouchBegan");

	Point location = touch->getLocation();

	Sprite *spr = (Sprite*)this->getChildByTag(1);
	Rect rect = spr->getBoundingBox();

	if (rect.containsPoint(location)) {
		spr->setScale(2.0);
	}
	else {
		spr->setScale(1.0);
	}

	return true;
}