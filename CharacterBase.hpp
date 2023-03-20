#ifndef CHARACTERBASE_HPP
#define CHARACTERBASE_HPP
#include <iostream>

class CharacterBase
{
public:
    CharacterBase(int hp_limit, int attack);
    ~CharacterBase();
    
    inline int getHPLimit() { return HP_limit; };
    inline int getHP() { return HP; };
    inline void setHP(int hp) {this->HP = hp > HP_limit ? HP_limit : hp; };
    inline void setAddHP(int add_hp) {this->HP += add_hp; };
    inline void setDelHP(int del_hp) {this->HP -= del_hp; };
    inline void getAttacked(const int attack) { this->HP -= attack; };
    virtual int getAttackVal();
    
    virtual bool getKilled();
    virtual std::string getName() const = 0;
    
protected:
    int HP_limit;
    int HP;
    int attack;
};

#endif // CHARACTERBASE_HPP
