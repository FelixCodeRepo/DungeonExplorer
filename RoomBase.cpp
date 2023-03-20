#include "RoomBase.hpp"

void RoomBase::fightPhase()
{
    // Monster list is sorted from hp_min to hp_max
    // Explorer attack monster first
    std::shared_ptr<commonMonster> monster = *(monsters_.rbegin());
    int damage = explorer_.getAttackVal();
    monster->getAttacked(damage);
    std::cout << "Explorer attack monster" << monster->getMonsterNum() << ", cause "
              << damage << " points hurt, Monster"
              << monster->getMonsterNum() << " (" << monster->getHP()
              << "/" << monster->getHPLimit() << ")\n";
              
    // Check current monster is dead or not
    if(monster->getKilled())
    {
        monsters_.erase(monsters_.end() - 1);
    }
    
    // Monster attack explorer
    for (auto it = monsters_.begin(); it != monsters_.end(); ++it) {
       damage = (*it)->getAttackVal();
       explorer_.getAttacked(damage);
       std::cout << "Monster" << (*it)->getMonsterNum() << " attack explorer, cause "
                 << damage << " points hurt, Explorer ("
                 << explorer_.getHP() << "/" << explorer_.getHPLimit() << ")\n";
    }
}

bool RoomBase::detectionPhase()
{
    while(!monsters_.empty())
    {
        fightPhase();
        if(explorer_.getKilled())
        {
            return false;
        }
    }
    return true;
}

bool Camp::enterPhase() {
  explorer_.setHP(explorer_.getHPLimit());
  return true;
}

NormalRoom::NormalRoom(Person &explorer) : RoomBase(explorer)
{
    monsters_nums_ = random_num(1, 3);
    for (int i = 0; i < monsters_nums_; ++i) {
        monsters_.emplace_back(std::make_shared<commonMonster>(i + 1));
    }
    
    std::sort(monsters_.begin(), monsters_.end(),
        [](const std::shared_ptr<commonMonster>& a, const std::shared_ptr<commonMonster>& b)
        {
            return a->getAttackVal() < b->getAttackVal();
        }
    );
}

bool NormalRoom::enterPhase() {
    if (random_num(1, 100) < 10) {
        explorer_.setHP(explorer_.getHP() + 10);
        explorer_.triggerBuff();
        explorer_.buff(RoomType::normal);
    }
    else 
    {
        explorer_.buff(RoomType::normal);
    }
    
    if (explorer_.getKilled())
    {
        return false;
    }
    
    return true;
}

TrapRoom::TrapRoom(Person &explorer) : RoomBase(explorer) 
{
    monsters_nums_ = 1;
    monsters_.emplace_back(std::make_shared<commonMonster>());
}

bool TrapRoom::enterPhase() {
    explorer_.setHP(explorer_.getHP() * 0.9);
    explorer_.triggerBuff();
    explorer_.buff(RoomType::trap);
    if (explorer_.getKilled())
    {
        return false;
    }
    return true;
}

void RoomBase::endPhase() const 
{
    std::cout << "Explorer gets " << monsters_nums_ << " points experience, ";
    explorer_.addExp(monsters_nums_);
    if(explorer_.getExp() >= explorer_.getExpLimit())
    {
        explorer_.setExp(explorer_.getExp() - explorer_.getExpLimit());
    }
}

RoomType pickRoom() 
{
    int num = random_num(1, 100);
    if(num <= 10)
    {
        return RoomType::camp;
    }
    else if (num <= 65)
    {
        return RoomType::normal;
    }
    else 
    {
        return RoomType::trap;
    }
}
