#ifndef FileWithIncomies_H
#define FileWithIncomies_H
#include <iostream>
#include <vector>
#include <string>

#include "Markup.h"
#include "Incomies.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithIncomies
{
public:
    void addIncomiesToFileXML(Incomies incomiesC);
    vector <Incomies> loadIncomiesFromFileXML(int loggedInUserId);
};

#endif
