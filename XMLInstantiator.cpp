//
// Created by taylor on 1/16/17.
//

#include "XMLInstantiator.h"



#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>

using namespace xercesc;
using namespace std;

std::vector<Person> XMLInstantiator::parse(char *file)
{
    vector<Person> result;
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
        DOMNode *nodeAge = elementChild->getElementsByTagName(XMLString::transcode("Age"))->item(0);
        DOMNode *nodeName = elementChild->getElementsByTagName(XMLString::transcode("Name"))->item(0);
        DOMText *textAge = dynamic_cast<DOMText *>(nodeAge->getFirstChild());
        DOMText *textName = dynamic_cast<DOMText *>(nodeName->getFirstChild());
        int age = stoi(string(XMLString::transcode(textAge->getWholeText())));
        string name = string(XMLString::transcode(textName->getWholeText()));

        result.push_back(Person(name, age));
    }


    delete parser;
    delete errHandler;
    return result;
}
