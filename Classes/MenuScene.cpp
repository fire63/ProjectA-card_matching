#include "MenuScene.h"
#include "GameScene.h"


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

void MenuScene::initBG()     //menu-bg �̹����� ��������Ʈ�� ����� ȭ�鿡 ���  
						//,getWinSize().width / 2,getWinSize().height / 2 << ȭ�� ������ �޾� ���߾ӿ� ���
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
		"menu/play-1.png", CC_CALLBACK_1(MenuScene::menuCallback, this));  //�Ϲݻ��� ���û��� �̹��� ����, ���ý� menucallback �żҵ� ȣ��
	auto item_1 = MenuItemImage::create("menu/help-0.png",
		"menu/help-1.png", CC_CALLBACK_1(MenuScene::menuCallback, this));
	auto item_2 = MenuItemImage::create("menu/option-0.png",
		"menu/option-1.png", CC_CALLBACK_1(MenuScene::menuCallback, this));
	auto item_3 = MenuItemImage::create("menu/quit-0.png",
		"menu/quit-1.png", CC_CALLBACK_1(MenuScene::menuCallback, this));

	item_0 -> setTag(TAG_MENUITEM_PLAY);  //�±� ����
	item_1 -> setTag(TAG_MENUITEM_HELP);
	item_2 -> setTag(TAG_MENUITEM_OPTION);
	item_3 -> setTag(TAG_MENUITEM_QUIT);

	auto menu = Menu::create(item_0, item_1, item_2, item_3, NULL); //�޴� ������
	menu->alignItemsVerticallyWithPadding(20); //����
	this->addChild(menu);

}

void MenuScene::menuCallback(Ref *sender)
{
	auto item = (MenuItem*)sender;   //menuCallback���� ���� sender�� item���� ����

	switch (item->getTag()) 
	{
	case TAG_MENUITEM_PLAY:  // �÷��� ���ý� ȭ�� ��ȯ
		{
		auto scene = TransitionFadeTR::create(1.0, GameScene::createScene());
		Director::getInstance()->replaceScene(scene);
		}
			break;
		case TAG_MENUITEM_HELP:
			break; 
		case TAG_MENUITEM_OPTION:
			break;
		case TAG_MENUITEM_QUIT:   //���ἱ�ý� ����
			Director::getInstance()->end();
	#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
			exit(0);
	#endif
			break;
		default:
			break;
	}
}