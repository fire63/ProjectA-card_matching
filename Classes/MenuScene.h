#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

#define TAG_MENUITEM_PLAY   0
#define TAG_MENUITEM_HELP   1
#define TAG_MENUITEM_OPTION 2
#define TAG_MENUITEM_QUIT   3


class MenuScene : public Layer
{
public:

	static Scene* createScene();

	virtual bool init();
	CREATE_FUNC(MenuScene);

	void initBG();   //화면 배경 생성메소드
	void initMenu(); // 메뉴 생성 메소드

	void menuCallback(Ref *sender);  // 메뉴 아이템 선택시 호출되는 메소드
	
};

#endif