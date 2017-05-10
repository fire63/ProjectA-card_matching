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

	Size winSize;        //������
	  
	int cardOK, life;    // �ٸ� ���� ī��, ������ ���� ����
	int card[4];         // ������ ī�� ��ȣ ������ �迭
	int countCard;       //���� ī�� ���� ����

	bool isTouch;

	void initGameData();  //���� �ʱ�ȭ

	void initBG();        //��� ����
	void initTopMenuLabel(); //ȭ�� ��� �� ����
	void setLabelCard();  //ȭ�� ��� ī�� ���� ǥ�ö�
	void setLabelLife();  //ȭ�� ��� ���� ǥ��
	void initCard();      //ī�� ����
	void initReady();	  // ready �� ����
	void initStart();     // start �� ����
	void actionReady();   // raedy ���� �׼�
	void endReady();	  // ��ŸƮ �׼� ȣ��
	void actionStart();   // ��ŸƮ �׼�
	void endStart(); // ī�� �׼� ȣ��
	void actionCard();  //ī�� �׼�
	void endCard();     //�׼� ������ ��ġ Ȱ��ȭ

	void initO();
	void initX();

	void actionOX(bool isO);
	void endOX();

	bool onTouchBegan(Touch *touch, Event *unused_event);
};

#endif