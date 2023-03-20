#ifndef COMMONMONSTER_HPP
#define COMMONMONSTER_HPP
#include "CharacterBase.hpp"
#include <iostream>

class commonMonster final : public CharacterBase
{
public:
    commonMonster();
    commonMonster(int num);
    ~commonMonster();
    
    std::string getName() const override;
    bool getKilled() override;
    int getMonsterNum() { return num_; };
    
private:
  int num_ = 1;
};

#endif // COMMONMONSTER_HPP
