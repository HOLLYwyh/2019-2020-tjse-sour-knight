#include"Knight.h"


 bool Knight::init(const std::string& filename, Weapon* weapon)
{
     if (!Sprite::initWithFile(filename))
         return false;
     else
     {
         /*骑士角色的初始状态为：
         HP：7
         Armor:6
         MP:200
         */
         setActorFilename(filename);
         setAlreadyDead(false);
         setHP(HP_OF_KNIGHT);
         setArmor(ARMOR_OF_KNIGHT);
         setMP(MP_OF_KNIGHT);
         setMaxHP(HP_OF_KNIGHT);
         setMaxArmor(ARMOR_OF_KNIGHT);
         setMaxMP(MP_OF_KNIGHT);
         setSkillPoint(0);
         setMaxSkillPoint(SKILL_POINT_OF_KNIGHT);
         setAttackMode(weapon->getAttackMode());
         setAttackRadius(weapon->getAttackMode());
         setMPConsuming(weapon->getMPConsuming());
         setGold(0);
         return true;
     }
}


 Knight* Knight::create(const std::string& filename, Weapon* weapon)
{
     Knight* knight = new Knight();
     if (knight && knight->init(filename, weapon))
     {
         knight->autorelease();
         //实现角色动画
// ///////////////////////////////////////////////////////////////
         auto herocache = SpriteFrameCache::getInstance();
         herocache->addSpriteFramesWithFile("Heroes/knightMoving.plist");
         Vector<SpriteFrame*>vector;
         char name[40];
         memset(name, 0, 40);
         for (int i = 0; i < 2; i++)
         {
             sprintf(name, "knightMoving%04d", i);
             vector.pushBack(herocache->getSpriteFrameByName(name));
         }
         Animation* moveAnimation = Animation::createWithSpriteFrames(vector, 0.3f);
         Animate* moveAnimate = Animate::create(moveAnimation);

         
         knight->runAction(RepeatForever::create(moveAnimate));
         
// //////////////////////////////////////////////////////////////////////
         return knight;
     }
     else
     {
         CC_SAFE_DELETE(knight);
         return nullptr;
     }
}


 Knight* Knight::create(const std::string& filename, Knight* kt)
 {
     Knight* knight = new Knight();
     if (knight&&knight->init( filename, kt))
     {
         knight->autorelease();
 //实现角色动画
// ///////////////////////////////////////////////////////////////
         auto herocache = SpriteFrameCache::getInstance();
         herocache->addSpriteFramesWithFile("Heroes/knightMoving.plist");
         Vector<SpriteFrame*>vector;
         char name[40];
         memset(name, 0, 40);
         for (int i = 0; i < 2; i++)
         {
             sprintf(name, "knightMoving%04d", i);
             vector.pushBack(herocache->getSpriteFrameByName(name));
         }
         Animation* moveAnimation = Animation::createWithSpriteFrames(vector, 0.3f);
         Animate* moveAnimate = Animate::create(moveAnimation);

       
         knight->runAction(RepeatForever::create(moveAnimate));
         
// //////////////////////////////////////////////////////////////////////
         return knight;
     }
     else
     {
         CC_SAFE_DELETE(knight);
         return nullptr;
     }
 }


 bool Knight::init(const std::string& filename, Knight* knight)
 {
     if (!Sprite::initWithFile(filename))
         return false;
     else
     {
         //Actor部分初始化
         this->setActorFilename(filename);
         this->setHP(knight->getHP());
         this->setMaxHP(HP_OF_KNIGHT);
         this->setAttack(knight->getAttack());
         this->setAlreadyDead(knight->getAlreadyDead());
         this->setAttackRadius(knight->getAttackRadius());
         this->setAttackMode(knight->getAttackMode());
         this->setReleaseDebuff(knight->getReleaseDebuff());
         //Hero 部分初始化
         this->setArmor(knight->getArmor());
         this->setMaxArmor(ARMOR_OF_KNIGHT);
         this->setMP(knight->getMP());
         this->setMaxMP(MP_OF_KNIGHT);
         this->setMPConsuming(knight->getMPConsuming());
         this->setLevelNum(knight->getLevelNum());
         this->setGold(knight->getGold());
         this->setSkillPoint(knight->getSkillPoint());
         this->setMaxSkillPoint(knight->getMaxSkillPoint());
         //Knight部分初始化

         return true;
     }

 }

 void Knight::updateSkill()
 {
     float skill = this->getSkillPoint();
     skill += 0.05;
     if (skill >= this->getMaxSkillPoint())
         skill = this->getMaxSkillPoint();
     this->setSkillPoint(skill);
 }

 void Knight::releaseSkill()//释放大招
 {
     if (this->getSkillPoint() >= this->getMaxSkillPoint())
     {
         this->setSkillPoint(0);
         this->setMP(this->getMaxMP());
     }
 }