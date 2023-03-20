#include <iostream>
#include <unistd.h>
#include "RoomBase.hpp"
#include "Person.hpp"
#include "CharacterBase.hpp"
#include "commonMonster.hpp"


void summary(std::array<int, 5> &rooms_number_);
std::shared_ptr<RoomBase> create_room(std::array<int, 5> &rooms_total, Person &explorer_);
void run_game();

const char *RoomTypeNames[] = { "camp", "normal", "trap" };

int main(int argc, char **argv)
{
	printf("Welcome to the Game: Exploration of Dungeon!\n");
    run_game();
    
    
	return 0;
}

std::shared_ptr<RoomBase> create_room(std::array<int, 5> &rooms_total, Person &explorer_) {
    RoomType type = pickRoom();
    
    std::cout << "enter " << RoomTypeNames[type] << " room\n";
    switch (type) {
        case RoomType::camp:
          rooms_total[0]++;
          return std::make_shared<Camp>(explorer_);
        case RoomType::normal:
          rooms_total[1]++;
          return std::make_shared<NormalRoom>(explorer_);
        case RoomType::trap:
          rooms_total[2]++;
          return std::make_shared<TrapRoom>(explorer_);
        //case RoomType::lead:
        //case RoomType::weapon:
    }
}

void summary(std::array<int, 5> &rooms_number_) {
  int sum = 0;
  for (const auto i : rooms_number_)
    sum += i;

  std::cout << "There are in total " << sum << " rooms. ";
  std::cout << RoomTypeNames[RoomType::camp] << " :" << rooms_number_[0] << ", ";
  std::cout << RoomTypeNames[RoomType::normal] << ": " << rooms_number_[1] << ", ";
  std::cout << RoomTypeNames[RoomType::trap] << " :" << rooms_number_[2] << ".\n";
  
}

void run_game()
{
    std::array<int, 5> rooms_total = {0, 0, 0, 0, 0};
    Person explorer_ = Person();
    
    while(1) 
    {
        std::shared_ptr<RoomBase> new_room = create_room(rooms_total, explorer_);
        if (!new_room->enterPhase()) { break; } //To complete
        if (!new_room->detectionPhase()) { break; }
        new_room->endPhase();
        sleep(1);
    }
    summary(rooms_total);
}
