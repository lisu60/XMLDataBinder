//
// Created by taylor on 1/15/17.
//

#ifndef XMLDATABINDER_PERSON_H
#define XMLDATABINDER_PERSON_H

#include <string>
#include <map>
#include <iostream>
#include "MapLoadable.h"

class Person : public MapLoadable{
private:
    std::string name = "Thomas";
    int age = 30;

public:
    Person();
    Person(std::string, int);
    friend std::ostream& operator<< (std::ostream&, Person& p);
    void loadMap(std::map<std::string, std::string>);

};


#endif //XMLDATABINDER_PERSON_H
