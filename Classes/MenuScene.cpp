#include "MenuScene.h"


Scene* MenuScene::createScene()
{
	auto scene = Scene::create();

	auto layer = MenuScene::create();
	scene->addChild(layer);

	return scene;
}

bool MenuScene::init()
{
	if (!Layer::init() )
	{
		return false;
	}

	initBG();
	initMenu();


	return true;
}

void MenuScene::initBG()     //menu-bg 이미지로 스프라이트를 만들어 화면에 출력  
						//,getWinSize().width / 2,getWinSize().height / 2 << 화면 사이즈 받아 정중앙에 출력
{
	auto spr = Sprite::create("menu/menu-bg.png");
	spr->setPosition(Point(Director::getInstance()->
		getWinSize().width / 2, Director::getInstance()->
		getWinSize().height / 2));
	this->addChild(spr);
}

void MenuScene::initMenu()
{
	auto item_0 = MenuItemImage::create("menu/play-0.png",
		"menu/play-1.png", CC_CALLBACK_1(MenuScene::menuCallback, this));  //일반상태 선택상태 이미지 결정, 선택시 menucallback 매소드 호출
	auto item_1 = MenuItemImage::create("menu/help-0.png",
		"menu/help-1.png", CC_CALLBACK_1(MenuScene::menuCallback, this));
	auto item_2 = MenuItemImage::create("menu/option-0.png",
		"menu/option-1.png", CC_CALLBACK_1(MenuScene::menuCallback, this));
	auto item_3 = MenuItemImage::create("menu/quit-0.png",
		"menu/quit-1.png", CC_CALLBACK_1(MenuScene::menuCallback, this));

	item_0 -> setTag(TAG_MENUITEM_PLAY);  //태그 설정
	item_1 -> setTag(TAG_MENUITEM_HELP);
	item_2 -> setTag(TAG_MENUITEM_OPTION);
	item_3 -> setTag(TAG_MENUITEM_QUIT);

	auto menu = Menu::create(item_0, item_1, item_2, item_3, NULL); //메뉴 생성함
	menu->alignItemsVerticallyWithPadding(20); //정렬
	this->addChild(menu);

}