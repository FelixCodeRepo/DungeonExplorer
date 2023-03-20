# DungeonExplorer
C++ OOP design (tb Cont'd)

This mini-project (500-1000 lines) is a good practice for some new features of C++11/14/17 such as smart pointer (shared_ptr, make_shared), iterators, algorithms from STL, lambda expression, virtual.

## Design a game of Exploration of Dungeon. This game is fully automatic with text output only, contrary to more complex design with images such as this:
![image](https://user-images.githubusercontent.com/89890055/226417229-31c67cdb-8f28-4f18-9a09-2a513944f99d.png)

Game Character Setting:

| attributes\Characters  | Explorer  | Monster | MonsterLead |
| :-------------: | :-------------: | :-------------: | :-------------: |
| HP  | 80/80 | 10/10 | 40/40 |
| Attack | 12  | 5 | 10 |
| Exp | 0/12 | n/a | n/a |


Room Setting:
| Events\RoomTypes | Lounge | Basic Room | Trap Room | MonsterLead Room | Weapon Room |
| :-------------: | :-------------: | :-------------: | :-------------: |
| Probability  | 10% | 40% | 15% | 15% | 10% |
| Buff(Debuff) | Explorer HP = Full  | 15%: Explorer HP + 15; This room and next one, Explorer HP + 6;  | Explorer HP * 0.9; This room and next 4 room, Explorer HP - 3; | Explorer HP + 20; Clear all debuff; | n/a |
| Battle | Randomly generate 2-3 monsters, each one's attributes are ±50% of basic attributes of monster  | 2x times of basic attributes of monster generated | one MonsterLead generated | A monster with 0.3 times of attributes of Explorer plus a weapon generated |
| Experience| Kill one monster, get 1 EXP | get 1 EXP | get 2 EXP | get 2 EXP, explorer attack = basic + this new weapon |

