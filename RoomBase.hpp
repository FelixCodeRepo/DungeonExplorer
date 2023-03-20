#ifndef ROOMBASE_HPP
#define ROOMBASE_HPP
#include <iostream>
#include <vector>
#include "commonMonster.hpp"
#include "Person.hpp"
#include "Random.hpp"


RoomType pickRoom();

class RoomBase
{
public:
    RoomBase(Person &explorer) : explorer_(explorer) {};
    virtual ~RoomBase() {};
    virtual bool enterPhase() = 0;
    virtual void fightPhase();
    virtual void endPhase() const;
    virtual bool detectionPhase();
    
protected:
    std::vector<std::shared_ptr<commonMonster>> monsters_;
    int monsters_nums_ = 0;
    Person &explorer_;
    
};

class Camp : public RoomBase
{
public:
    Camp(Person &explorer) : RoomBase(explorer) {};
    virtual ~Camp() {};
    bool enterPhase() override;
};

class NormalRoom : public RoomBase
{
public:
    NormalRoom(Person &explorer);
    virtual ~NormalRoom() {};
    bool enterPhase() override;
};

class TrapRoom : public RoomBase
{
public:
    TrapRoom(Person &explorer);
    virtual ~TrapRoom() {};
    bool enterPhase() override;
};


#endif // ROOMBASE_HPP
