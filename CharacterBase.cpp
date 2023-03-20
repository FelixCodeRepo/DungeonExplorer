#include "CharacterBase.hpp"

CharacterBase::CharacterBase(int hp_limit, int attack)
{
    this->HP_limit = hp_limit;
    this->HP = hp_limit;
    this->attack = attack;
}

CharacterBase::~CharacterBase()
{
}

bool CharacterBase::getKilled()
{
    if (HP < 1) 
    {
        std::cout << getName() << " is dead\n";
        return true;
    }
  return false;
}

int CharacterBase::getAttackVal()
{
    return attack;
}