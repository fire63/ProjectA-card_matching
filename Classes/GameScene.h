#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

#define TAG_LABEL_CARD		0
#define TAG_LABEL_LIFE		1
#define TAG_LABEL_READY		2
#define TAG_LABEL_START		3
#define TAG_SPRITE_O		4
#define TAG_SPRITE_X		5
#define TAG_LABEL_GAMEOVER	6
#define TAG_LABEL_GAMECLEAR	7
#define TAG_MENU			8

#define TAG_SPRITE_CARD		10


class GameScene : public Layer
{
public:

	static Scene* createScene();

	virtual bool init();
	CREATE_FUNC(GameScene);

	Size winSize;        //사이즈
	  
	int cardOK, life;    // 바른 선택 카드, 라이프 저장 변수
	int card[4];         // 뒤집을 카드 번호 저장할 배열
	int countCard;       //맞출 카드 순서 저장

	bool isTouch;

	void initGameData();  //변수 초기화

	void initBG();        //배경 선언
	void initTopMenuLabel(); //화면 상단 라벨 생성
	void setLabelCard();  //화면 사단 카드 갯수 표시라벨
	void setLabelLife();  //화면 상단 생명 표시
	void initCard();      //카드 생성
	void initReady();	  // ready 라벨 생성
	void initStart();     // start 라벨 생성
	void actionReady();   // raedy 라벨의 액션
	void endReady();	  // 스타트 액션 호출
	void actionStart();   // 스타트 액션
	void endStart(); // 카드 액션 호출
	void actionCard();  //카드 액션
	void endCard();     //액션 끝나면 터치 활성화

	void initO();
	void initX();

	void actionOX(bool isO);
	void endOX();

	bool onTouchBegan(Touch *touch, Event *unused_event);
};

#endif