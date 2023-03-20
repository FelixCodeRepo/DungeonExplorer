#include "MonsterLead.hpp"

MonsterLead::MonsterLead() : CharacterBase(40, 15)
{
}

MonsterLead::~MonsterLead()
{
}

std::string MonsterLead::getName() const { return "MonsterLead"; }
