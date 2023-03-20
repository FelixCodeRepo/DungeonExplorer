#ifndef MONSTERLEAD_HPP
#define MONSTERLEAD_HPP
#include "CharacterBase.hpp"
#include <iostream>

class MonsterLead final : public CharacterBase
{
public:
    MonsterLead();
    ~MonsterLead();

    std::string getName() const override;
};

#endif // MONSTERLEAD_HPP
