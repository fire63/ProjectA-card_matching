#include "MenuLayer.h"

bool MenuLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	CCLOG("MenuLayer::init()");

	return true;
}