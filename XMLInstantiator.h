//
// Created by taylor on 1/16/17.
//

#ifndef XMLDATABINDER_XMLINSTANTIATOR_H
#define XMLDATABINDER_XMLINSTANTIATOR_H

#include <vector>
#include "Person.h"


#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>

using namespace std;
using namespace xercesc;

template <class C>
class XMLInstantiator {
public:
    std::vector<C> parse(const char* file);
    XMLInstantiator(vector<string>);

private:
    vector<string> params;

};
template <class C>
XMLInstantiator<C>::XMLInstantiator(vector<string> paramsToLoad)
{
    params=paramsToLoad;
}

template <class C>
vector<C> XMLInstantiator<C>::parse(const char *file)
{
    vector<C> result;
    try {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Error during initialization! :\n"
             << message << "\n";
        XMLString::release(&message);
        return result;
    }

    XercesDOMParser* parser = new XercesDOMParser();
    parser->setValidationScheme(XercesDOMParser::Val_Always);
    parser->setDoNamespaces(true);    // optional

    ErrorHandler* errHandler = (ErrorHandler*) new HandlerBase();
    parser->setErrorHandler(errHandler);

    try {
        parser->parse(file);
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Exception message is: \n"
             << message << "\n";
        XMLString::release(&message);
        return result;
    }
    catch (const DOMException& toCatch) {
        char* message = XMLString::transcode(toCatch.msg);
        cout << "Exception message is: \n"
             << message << "\n";
        XMLString::release(&message);
        return result;
    }
    catch (...) {
        cout << "Unexpected Exception \n" ;
        return result;
    }


    DOMDocument *doc = parser->getDocument();
    DOMElement *root = doc->getDocumentElement();
    DOMElement *elementChild = root->getFirstElementChild();

    for(; elementChild; elementChild = elementChild->getNextElementSibling()) {
        map<string, string> loaded;
        vector<string>::iterator param;
        for(param=params.begin(); param!=params.end(); param++)
        {
            DOMNode *node = elementChild->getElementsByTagName(XMLString::transcode(param->c_str()))->item(0);
            DOMText *text=dynamic_cast<DOMText*>(node->getFirstChild());
            loaded.insert(pair<string, string>(*param, string(XMLString::transcode(text->getWholeText()))));

        }

        C c;
        c.loadMap(loaded);
        result.push_back(c);
    }



    delete parser;
    delete errHandler;
    return result;
}

#endif //XMLDATABINDER_XMLINSTANTIATOR_H
