#include "commonMonster.hpp"
#include "Random.hpp"

commonMonster::commonMonster(int num) : CharacterBase(random_num(6, 14), random_num(3, 7)) 
{
    this->num_ = num;
}

commonMonster::commonMonster() : CharacterBase(20, 10) 
{ 
}

commonMonster::~commonMonster()
{
}

std::string commonMonster::getName() const { return "Monster"; }

bool commonMonster::getKilled()
{
    if (HP < 1) 
    {
        std::cout << getName() << num_ << " is dead\n";
        return true;
    }
  return false;
}