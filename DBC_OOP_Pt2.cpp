#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>

class Warrior{
private:
    int attackMax;
    int blockMax;
public:
    std::string name;
    int health;
    Warrior(std::string name, int health, int attackMax, int blockMax){
        this->name = name;
        this->health = health;
        this->attackMax = attackMax;
        this->blockMax = blockMax;
    }
    int Attack(){
        return std::rand() % this->attackMax;
    }
    int Block(){
        return std::rand() % this->blockMax;
    }
};

class Battle{
public:
    static void StartFight(Warrior& warrior1, Warrior& warrior2){
        while(true){
            if(Battle::GetAttackResult(warrior1,warrior2).compare("Game Over") == 0){
                std::cout << "Game Over" << std::endl;
                break;
            }
            if(Battle::GetAttackResult(warrior2,warrior1).compare("Game Over") == 0){
                std::cout << "Game Over" << std::endl;
                break;
            }
        }
    }
    static std::string GetAttackResult(Warrior& warriorA, Warrior& warriorB){
        int warriorAAttackAmount = warriorA.Attack();
        int warriorBBlockAmount = warriorB.Block();
        int damage2WarriorB = ceil(warriorAAttackAmount-warriorBBlockAmount);
        damage2WarriorB = (damage2WarriorB <= 0) ? 0: damage2WarriorB;
        warriorB.health = warriorB.health - damage2WarriorB;

        printf("%s attacks %s and deals %d damage \n", warriorA.name.c_str(), warriorB.name.c_str(), damage2WarriorB);
        printf("%s is down to %d health \n", warriorA.name.c_str(), warriorA.health);
        printf("%s is down to %d health \n", warriorB.name.c_str(), warriorB.health);

        if(warriorB.health <= 0){
            printf("%s has died and %s is victorious. \n", warriorB.name.c_str(), warriorA.name.c_str());
            return "Game over";
        }
        else{
            return "Fight again";
        }
    }
};

int main(){

    //random number generator
    srand(time(NULL));

    //warrior obj
    Warrior thor("Thor", 100, 30, 15);
    Warrior hulk("Hulk", 135, 25, 10);

    Battle::StartFight(thor, hulk);
    return 0;
}