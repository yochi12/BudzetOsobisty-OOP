#ifndef FileWithIncomies_H
#define FileWithIncomies_H
#include <iostream>
#include <vector>
#include <string>

#include "Markup.h"
#include "Incomies.h"

using namespace std;

class FileWithIncomies
{
public:
    void addIncomiesToFileXML(Incomies incomies);
    vector <Incomies> loadIncomiessFromFileXML(int loggedInUserId);
};

#endif
