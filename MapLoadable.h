//
// Created by taylor on 1/16/17.
//

#ifndef XMLDATABINDER_MAPCONDUCTABLE_H
#define XMLDATABINDER_MAPCONDUCTABLE_H

#include <map>
#include <string>

using namespace std;
class MapLoadable {
public:
    virtual void loadMap(map<string, string>)=0;

};


#endif //XMLDATABINDER_MAPCONDUCTABLE_H
