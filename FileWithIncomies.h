#ifndef FileWithIncomies_H
#define FileWithIncomies_H//w piku cpp trzeba wszystko przerobic na ta klase

#include <iostream>
#include <vector>

#include "Markup.h"
#include "Incomies.h"


using namespace std;

class FileWithIncomies
{
public:
    void addIncomiesToFileXML(Incomies incomies);
    vector <Incomies> loadIncomiessFromFileXML();
};

#endif
