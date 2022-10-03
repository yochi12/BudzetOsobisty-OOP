#include "AuxiliaryMethods.h"

char AuxiliaryMethods::loadChar(){
    string input = "";
    char mark = {0};

    while (true){
        getline(cin, input);

        if (input.length() == 1){
            mark = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return mark;
}
