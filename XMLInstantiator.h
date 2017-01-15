//
// Created by taylor on 1/16/17.
//

#ifndef XMLDATABINDER_XMLINSTANTIATOR_H
#define XMLDATABINDER_XMLINSTANTIATOR_H

#include <vector>
#include "Person.h"

class XMLInstantiator {
public:
    std::vector<Person> parse(char* file);

};


#endif //XMLDATABINDER_XMLINSTANTIATOR_H
