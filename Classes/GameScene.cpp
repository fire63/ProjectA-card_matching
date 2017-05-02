#include "GameScene.h"
#include "MenuScene.h"

Scene* GameScene::createScene()
{
	auto scene = Scene::create();

	auto layer = GameScene::create();
	scene->addChild(layer);

	return scene;
}

bool GameScene::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 0, 0)))
	{
		return false;
	}

	auto item = MenuItemFont::create("Menu Scene", CC_CALLBACK_1(GameScene::changeScene, this));

	auto game = Menu::create(item, NULL);
	game->alignItemsHorizontally();
	this->addChild(game);

	return true;
}

void GameScene::changeScene(Ref *sender)
{
	Director::getInstance()->replaceScene(MenuScene::createScene());
}