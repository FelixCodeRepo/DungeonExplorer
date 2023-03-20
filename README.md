# DungeonExplorer
C++ OOP design (tb Cont'd)

This mini-project (500-1000 lines) is a good practice for some new features of C++11/14/17 such as smart pointer (shared_ptr, make_shared), iterators, algorithms from STL, lambda expression, virtual.

## Design a game of Exploration of Dungeon. This game is fully automatic with text output only, contrary to more complex design with images such as this:
![image](https://user-images.githubusercontent.com/89890055/226417229-31c67cdb-8f28-4f18-9a09-2a513944f99d.png)



| First Header  | Second Header |
| ------------- | ------------- |
| Content Cell  | Content Cell  |
| Content Cell  | Content Cell  |


Game Character Setting:
| :---: || Explorer | Monster | MonsterLead |
| :---: | :---: | :---: || :---: |
| HP || 80/80 | 10/10 | 40/40 |
| Attack || 12 | 5 | 10 |
| Exp || 0/12 |


Room Setting:
                   Lounge         Basic Room           Trap Room          MonsterLead Room           Weapon Room
Probability         10%               40%                 15%                   15%                      10%
Buff(Debuff)      HP Full         15% HP + 15,
                                    HP + 5, 
                                 2 rooms cont.
