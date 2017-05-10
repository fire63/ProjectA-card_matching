#include "GameScene.h"

Scene* GameScene::createScene()
{
	auto scene = Scene::create();

	auto layer = GameScene::create();
	scene->addChild(layer);

	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	isTouch = false;

	initGameData();

	initBG();
	initTopMenuLabel();

	initCard();

	initReady();
	initStart();

	initO();
	initX();

	actionReady();

	return true;
}

void GameScene::initGameData()
{
	winSize = Director::getInstance()->getWinSize(); //getwinsize 메소드로 사이즈 가져옴

	cardOK = 0;
	life = 3;

	srand(time(NULL)); //랜덤을 생성하는 소스, 시드를 랜덤하게 하기 위해서 시간을 시드로 받음

	for (int i = 0; i<4; i++) { //앞면을 보여주는 카드 정하는 매소드
		card[i] = rand() % 6;
	}

	countCard = 0;
}

void GameScene::initBG()
{
	auto spr = CCSprite::create("game/game-bg.png");
	spr->setPosition(Point(winSize.width / 2, winSize.height / 2));
	this->addChild(spr);
}

void GameScene::initTopMenuLabel()
{
	auto label_0 = Label::createWithSystemFont("", "", 20);
	label_0->setAnchorPoint(Point(0, 1));
	label_0->setPosition(Point(10, winSize.height - 10));
	label_0->setTag(TAG_LABEL_CARD);
	label_0->setColor(Color3B::BLACK);
	this->addChild(label_0);

	auto label_1 = Label::createWithSystemFont("", "", 20);
	label_1->setAnchorPoint(Point(1, 1));
	label_1->setPosition(Point(winSize.width - 10, winSize.height - 10));
	label_1->setTag(TAG_LABEL_LIFE);
	label_1->setColor(Color3B::BLACK);
	this->addChild(label_1);

	setLabelCard();
	setLabelLife();
}

void GameScene::setLabelCard()
{
	auto label = (Label*)this->getChildByTag(TAG_LABEL_CARD);
	label->setString(StringUtils::format("CARD : %d/4", cardOK));
}

void GameScene::setLabelLife()
{
	auto label = (Label*)this->getChildByTag(TAG_LABEL_LIFE);
	label->setString(StringUtils::format("LIFE : %d", life));
}

void GameScene::initCard()
{
	for (int i = 0; i<6; i++) {
		auto spr = Sprite::create("game/card-back.png");
		spr->setPosition(Point(winSize.width / 2 - 60 + 60 * 2 * (i % 2), winSize.height / 2 + 120 - 120 * (i / 2)));
		this->addChild(spr);

		auto sprFront = Sprite::create(String::createWithFormat("game/card_%d.png", (i + 1))->getCString());
		sprFront->setPosition(Point(winSize.width / 2 - 60 + 60 * 2 * (i % 2), winSize.height / 2 + 120 - 120 * (i / 2)));
		sprFront->setVisible(false);
		sprFront->setTag(TAG_SPRITE_CARD + i);
		this->addChild(sprFront);
	}
}

void GameScene::initReady()
{
	auto label = Label::createWithSystemFont("READY", "", 80);
	label->setPosition(Point(winSize.width / 2, winSize.height / 2));
	label->setTag(TAG_LABEL_READY);
	label->setColor(Color3B::BLACK);
	label->setScale(0.0);
	this->addChild(label);
}

void GameScene::initStart()
{
	auto label = Label::createWithSystemFont("START", "", 80);
	label->setPosition(Point(winSize.width / 2, winSize.height / 2));
	label->setTag(TAG_LABEL_START);
	label->setColor(Color3B::BLACK);
	label->setScale(0.0);
	this->addChild(label);
}

void GameScene::actionReady()
{
	auto action = Sequence::create(
		ScaleTo::create(1.0, 1.0),
		DelayTime::create(2.0),
		ScaleTo::create(1.0, 0.0),
		CallFunc::create(CC_CALLBACK_0(GameScene::endReady, this)),
		NULL);

	auto label = (Label*)this->getChildByTag(TAG_LABEL_READY);
	label->runAction(action);
}

void GameScene::endReady()
{
	actionStart();
}

void GameScene::actionStart()
{
	auto action = Sequence::create(
		ScaleTo::create(1.0, 1.0),
		DelayTime::create(2.0),
		ScaleTo::create(1.0, 0.0),
		CallFunc::create(CC_CALLBACK_0(GameScene::endStart, this)),
		NULL);

	auto label = (Label*)this->getChildByTag(TAG_LABEL_START);
	label->runAction(action);
}

void GameScene::endStart()
{
	actionCard();
}

void GameScene::actionCard()
{
	for (int i = 0; i<4; i++) {
		auto action = Sequence::create(
			DelayTime::create(3.0*i),
			Show::create(),
			DelayTime::create(2.0),
			Hide::create(),
			NULL);

		auto spr = (Sprite *)this->getChildByTag(TAG_SPRITE_CARD + card[i]);
		spr->runAction(action);
	}

	auto action = Sequence::create(
		DelayTime::create(11.0),
		CallFunc::create(CC_CALLBACK_0(GameScene::endCard, this)),
		NULL);
	this->runAction(action);
}

void GameScene::endCard()
{
	isTouch = true;
}

void GameScene::initO()
{
	auto spr = Sprite::create("game/o.png");
	spr->setPosition(Point(winSize.width / 2, winSize.height / 2));
	spr->setTag(TAG_SPRITE_O);
	spr->setVisible(false);
	this->addChild(spr);
}

void GameScene::initX()
{
	auto spr = Sprite::create("game/x.png");
	spr->setPosition(Point(winSize.width / 2, winSize.height / 2));
	spr->setTag(TAG_SPRITE_X);
	spr->setVisible(false);
	this->addChild(spr);
}

void GameScene::actionOX(bool isO)
{
	auto action = Sequence::create(
		Show::create(),
		DelayTime::create(0.5),
		Hide::create(),
		CallFunc::create(CC_CALLBACK_0(GameScene::endOX, this)),
		NULL);

	Sprite *spr;

	if (isO) {
		spr = (Sprite*)this->getChildByTag(TAG_SPRITE_O);
	}
	else {
		spr = (Sprite*)this->getChildByTag(TAG_SPRITE_X);
	}

	spr->runAction(action);
}

void GameScene::endOX()
{
	if (!(cardOK == 4 || life == 0)) {
		isTouch = true;
	}
}

bool GameScene::onTouchBegan(Touch *touch, Event *unused_event)
{
	if (!isTouch) return true;  //터치 불가시(isTouch가 false일때) 빠져나옴.

	Point location = touch->getLocation();//터치 영약 좌표 가져옴

	for (int i = 0; i<6; i++) {
		auto spr = (Sprite*)this->getChildByTag(TAG_SPRITE_CARD + i);
		Rect sprRect = spr->getBoundingBox();

		if (sprRect.containsPoint(location)) {//충돌 체크

			isTouch = false; //충돌시 중복 터치를 막기위해 터치불가로 변환(isTouch가 false)

			auto action = Sequence::create(
				Show::create(),
				DelayTime::create(0.5),
				Hide::create(),
				NULL);
			spr->runAction(action);//터치된 카드 0.5초동안 보여줌

			if (i == card[countCard]) {

				cardOK++;
				countCard++;

				setLabelCard();
				actionOX(true);
			}
			else {

				life--;

				setLabelLife();
				actionOX(false);
			}
		}
	}

	return true;
}

