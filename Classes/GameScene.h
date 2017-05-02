#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class GameScene : public LayerColor
{
public:

	static Scene* createScene();

	virtual bool init();
	CREATE_FUNC(GameScene);

	void changeScene(Ref *sender);
};

#endif