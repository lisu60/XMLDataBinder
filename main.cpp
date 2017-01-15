

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>

#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "XMLInstantiator.h"

using namespace std;
using namespace xercesc;

int main (int argc, char* args[]) {
    XMLInstantiator in;
    char* file = "/home/taylor/ClionProjects/XMLDataBinder/persons.xml";

    vector<Person> persons=in.parse(file);
    vector<Person>::iterator iter = persons.begin();
    for(; iter!= persons.end(); iter++)
    {
        cout<<*iter<<endl;
    }

    return 0;
}