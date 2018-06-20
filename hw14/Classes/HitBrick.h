#ifndef __HIT_BRICK_H__
#define __HIT_BRICK_H__

#include "cocos2d.h"
using namespace std;
USING_NS_CC;
class HitBrick : public Layer {
public:
  static PhysicsWorld* world;
  static cocos2d::Scene* createScene();
  void setPhysicsWorld(PhysicsWorld * world);
  virtual bool init();
	
  void fire(); // 发射小球
  void move(); // 板子移动

  void setJoint();
  void addSprite();   // 添加背景和各种精灵
  void addPlayer();   // 添加玩家
  void addListener(); // 添加监听器

  void update(float dt);
  void BrickGeneraetd();  // 掉落箱子

  void onKeyPressed(EventKeyboard::KeyCode code, Event * event);
  void onKeyReleased(EventKeyboard::KeyCode code, Event * event);
  bool onConcactBegin(PhysicsContact & contact);

  void preloadMusic();                   // 预加载音乐
  void GameOver();                      // 游戏结束

  // 重玩或退出按钮响应函数
  void replayCallback(Ref * pSender);
  void exitCallback(Ref * pSender);

  // implement the "static create()" method manually
  CREATE_FUNC(HitBrick);

private:
	PhysicsWorld* m_world;
	Size visibleSize;
	Sprite* player;
	Sprite* ship;
	bool onBall;
	Sprite* ball;
	// 固定关节
	PhysicsJointPin * joint1;
	bool spHolded;
	int spFactor;
	bool moveHold;
	ParticleFire* fireBall;
	char dir;

};

#endif // __HIT_BRICK_H__
