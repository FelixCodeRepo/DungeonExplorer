#ifndef PERSON_HPP
#define PERSON_HPP
#include<iostream>
#include<vector>
#include "CharacterBase.hpp"
#include "Weapon.hpp"

enum RoomType { camp, normal, trap, };

struct Buf {
  Buf(int num, int health) : room_remain(num), HP(health) {};
  int room_remain;
  int HP;
};

struct NormalBuf : public Buf {
  NormalBuf() : Buf(2, 5){};
};

struct TrapBuf : public Buf {
  TrapBuf() : Buf(5, -2){};
};

class Person final : public CharacterBase
{
public:
    Person();
    ~Person();
    
    inline void setAddAttack(int attack);
    inline int getExpLimit() { return Exp_limit; };
    inline int getExp() { return Exp; };
    inline void addExp(int exp) { this->Exp += exp; };
    inline void setExp(int exp) { this->Exp = exp; };
    void buff(RoomType room_type);
    bool triggerBuff();
    void clearAllBuff();
    int getAttackVal() override; 
    std::string getName() const override;
    
private:
    int Exp_limit;
    int Exp;
    std::vector<Weapon> epuip_weapon;
    std::vector<std::shared_ptr<Buf>> buffer;
};

#endif // PERSON_HPP
