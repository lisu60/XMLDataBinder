//
// Created by taylor on 1/15/17.
//
#include <iostream>

#include "Person.h"

std::ostream& operator<< (std::ostream& os, Person& p)
{
    os<<"Name: "<<p.name<<std::endl<<"Age: "<<p.age<<std::endl;
    return os;
}

Person::Person(std::string name, int age)
{
    this->name=name;
    this->age=age;
}

Person::Person() {}

void Person::loadMap(map<string, string> params)
{
    name=params["Name"];
    age=stoi(params["Age"]);
}
