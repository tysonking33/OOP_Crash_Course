/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-1-1.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:30:42 by tytang            #+#    #+#             */
/*   Updated: 2022/04/14 19:05:02 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
 
using namespace std;

//making an abstract employee class called AbstractEmployee
//this Abstract Employee class is reduced in complexity,
	//as the complexity is moved to the Employee class (Abstraction)
class AbstractEmployee {
	//making method called AskForPromotion
	//making it obligatory by making it a virtual function, using virtual keyword
	virtual void AskForPromotion() = 0;
};


//creating an employee class (base class)
//:AbstractEmployee makes every employee obey the AbstractEmployee function above
//the Employee class is inheriting from the AbstractEmployee class
class Employee:AbstractEmployee{
//encapsulates all properties that are private, only accessable within the Employee class
private:
    //attributes and behaviours, only accessable through the setter and getter
    string Company;
    int Age;
//protected access modifier (allows for the current class and the derived classes to access the properties)
protected:
	string Name;
public:
    //making setter
    void setName(string name){
        Name = name;
    }
	void setAge(int age){
		//making a validation rule, the employees will still be the previous age if the conditions aren't met
		//i.e. Employee1.getAge = 300 if Employee1.setAge(9)
		if (age >= 18){
			Age = age;
		}
	}
	void setCompany(string company){
		Company = company;
	}
	//making getter
    string getName(){
        return Name;
    }
	int getAge(){
		return Age;
	}
	string getCompany(){
		return Company;
	}

    //making functions/class method
    void IntroduceYourself()
    {
        cout<< "Name - " << Name << endl;
        cout<< "Company - " << Company << endl;
        cout<< "Age - " << Age << endl;
    }
 
    //making a constructor of class Employee
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }

	//implementing the AbstractEmployee function
	void AskForPromotion() {
		if (Age > 30)
			cout << Name << " got promoted" << endl;
		else
			cout << Name << " sorry no promotion" << endl;
	}

	virtual void Work(){
		cout << Name << " is checking mail, task backlog, performing tasks ..." << endl;
	}
};

//making a derived class called Developer
//the Developer has all the Employer properties
//the inheritance is private by default, that is why the public keyword is added
class Developer: public Employee {
//making a property that developers have but not other employees
public:
	string FavProgrammingLanguage;
	//as we inherited from the employee class, we don't have a default constructor for the Developer class currently
	//making a default Employee constructor
	Developer(string name, string company, int age, string favProgrammingLanguage):Employee(name, company, age)
	{
		//initalising the FavProgrammingLanguage property
		FavProgrammingLanguage = favProgrammingLanguage;
	}
	void FixBug(){
		cout << Name <<getName() << " fixed bug using " << FavProgrammingLanguage << " gang gang " << endl;
	}
	void Work(){
		cout << Name << " is writing " << FavProgrammingLanguage << " code." << endl;
	}
};

//making another derived class
class Teacher: public Employee {
public:
	string Subject;
	//default teacher constructor
	Teacher(string name, string company, int age, string subject):Employee(name, company, age)
	{
		Subject = subject;
	}
	void PrepareLesson(){
		cout << Name << " is preparing to teach how to " << Subject << endl;
	}
	void Work(){
		cout << Name << " is teaching " << Subject << endl;
	}

};

int main()
{
    //making the first employee call Employee1
    //invoking constructor Employee(string name, string company, int age)
    Employee Employee1 = Employee("Sal", "Bricksquad", 300);
    //calling IntroduceYourself function for employee1
    Employee1.IntroduceYourself();
 
    //making employee2
    Employee Employee2 = Employee("John", "Amazon", 35);
    //calling IntroduceYourself function for employee2
    Employee2.IntroduceYourself();
 
	//encapsulation - testing the setter
	Employee1.setAge(20);
	//encapsulation - testing the getter
	cout << Employee1.getName() << " is " << Employee1.getAge() << " years old" << endl;
    
	//abstraction - asking for promotion
	Employee1.AskForPromotion();
	Employee2.AskForPromotion();

	//making a Developer class object
	Developer Dev1 = Developer("Big Jon", "Slime ZOne", 100, "Javascript");
	//getting info on the Dev1
	Dev1.FixBug();
	//asking for the promotion of Dev1
	Dev1.AskForPromotion();

	//making a Teacher class object
	Teacher BigTeach = Teacher("Mr Skinner", "Springfield Elementary School", 50, "Throwin it back");
	//making BigTeach prepare the lesson
	BigTeach.PrepareLesson();
	BigTeach.AskForPromotion();

	//Polymorphism
	Dev1.Work();
	BigTeach.Work();

	//polymorphism when a base class is used to refer to a derived class object
	Employee *employee3 = &Dev1;
	Employee *employee4 = &BigTeach;

	employee3->Work();
	employee4->Work();
	return 0;
}

