//
// Created by taylor on 1/15/17.
//

#ifndef XMLDATABINDER_PERSON_H
#define XMLDATABINDER_PERSON_H

#include <string>
#include <iostream>

class Person {
private:
    std::string name = "Thomas";
    int age = 30;

public:
    Person(std::string, int);
    friend std::ostream& operator<< (std::ostream&, Person& p);

};


#endif //XMLDATABINDER_PERSON_H
