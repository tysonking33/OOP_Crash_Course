#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>

class Animal{
private:
    std::string name;
    double height;
    double weight;

    /*static variable - if the value of the static variable changes in the animal class
    all objects of an animal class (i.e. a shared value)*/

    static int numOfAnimals;
public:
    std::string GetName(){
        return name;
    }
    void SetName(std::string name){
        this->name = name;
    }
    double GetHeight(){
        return height;
    }
    void SetHeight(double height){
        this->height = height;
    }
    double GetWeight(){
        return weight;
    }
    void SetWeight(double weight){
        this->weight = weight;
    }
    void SetAll(std::string, double, double);
    
    //constructor
    Animal(std::string, double, double);

    //overload constructor
    Animal();

    //deconstructor
    ~Animal();

    //making a static method, which can only access static fields (only num of animals)
    static int GetNumOfAnimals(){
        return numOfAnimals;
    }

    void ToString();
};

int Animal::numOfAnimals = 0;

void Animal::SetAll(std::string name, double height, double weight){
    this->name = name;
    this->weight = weight;
    this->height = height;
    Animal::numOfAnimals++;
}

Animal::Animal(std::string name, double height, double weight){
    //constructor
    this->name = name;
    this->weight = weight;
    this->height = height;
    Animal::numOfAnimals++;
}

Animal::Animal(){
    //default constructor
    this->name = " ";
    this->weight = 0;
    this->height = 0;
    Animal::numOfAnimals++;
}

Animal::~Animal(){
    std::cout << "Animal " << this->name << " destroyed" << std::endl;
}

void Animal::ToString(){
    std::cout << this->name << " is " << this->height << " cms tall and " << this->weight << " kgs in weight" << std::endl;
}

class Dog: public Animal{
private:
    std::string sound = "Woof";
public:
    void MakeSound(){
        std::cout << "The dog " << this->GetName() << " says " << this->sound << std::endl;
    }
    Dog(std::string, double, double, std::string);
    Dog(): Animal(){};
    void ToString();
};

Dog::Dog(std::string name, double height, double weight, std::string sound): Animal(name, height, weight){
    this->sound = sound;
}

void Dog::ToString(){
        std::cout << this->GetName() << " is " << this->GetHeight() << 
        " cms tall and " << this->GetWeight() << " kgs in weight and says " << this->sound << std::endl;
}

int main()
{
    Animal fred;
    fred.ToString();
    fred.SetHeight(33);
    fred.SetWeight(10);
    fred.SetName("Fred");
    fred.ToString();

    Animal tom("Tom", 36, 15);
    tom.ToString();

    Dog spot("Spot", 38, 16, "Woooooof");
    spot.ToString();

    std::cout << "Number of animals " << Animal::GetNumOfAnimals() << std::endl;

    return 0;
}