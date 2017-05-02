#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public Layer
{
public:

	static Scene* createScene();

	virtual bool init();
	CREATE_FUNC(HelloWorld);

	bool onTouchBegan(Touch *touch, Event *unused_event);
};

#endif