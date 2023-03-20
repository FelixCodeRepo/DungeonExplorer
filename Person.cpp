#include "Person.hpp"

Person::Person() : CharacterBase(100, 10)
{
    this->Exp_limit = 10;
    this->Exp = 0;
}

Person::~Person() {}

std::string Person::getName() const
{
    return "Explorer";
}

void Person::buff(RoomType room_type)
{
  switch (room_type) 
  {
      case RoomType::normal:
        buffer.emplace_back(std::make_shared<NormalBuf>());
        return;
      case RoomType::trap:
        buffer.emplace_back(std::make_shared<TrapBuf>());
        return;
      default:
        return;
  }
}

bool Person::triggerBuff()
{
    for (auto it = buffer.begin(); it != buffer.end(); ) 
        {
        std::shared_ptr<Buf> buff = *it;
        Person::setHP(buff->HP + getHP());
        buff->room_remain--;
        if(buff->room_remain == 0)
        {
            it = buffer.erase(it);
        }
        else { ++it; }
        
        if(getKilled()) return false;
    }
    return true;
}

void Person::clearAllBuff()
{
    buffer.clear();
}

int Person::getAttackVal() 
{
    return attack;
}