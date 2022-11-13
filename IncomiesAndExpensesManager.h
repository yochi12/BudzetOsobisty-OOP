#ifndef IncomiesAndExpensesManager_H
#define IncomiesAndExpensesManager_H
#include <iostream>
#include <vector>

#include "Incomies.h"
#include "AuxiliaryMethods.h" //nie wiem czemu, ale bez tego nie dzialaja metody z tej klasy... (w Ksiazce Adresowej dzialalo bez)

using namespace std;

class IncomiesAndExpensesManager
{
    vector <Incomies> incomiesV;
    int loggedInUserId;
    int dzien, miesiac, rok;

public:
    IncomiesAndExpensesManager()//nie moge wyslac nic do tego konstruktora....
    {
        //loggedInUserId = idZalogowanegoUzytkownika;
        dzien = 0; miesiac = 0; rok = 0;
    };

    void addIncome(int loggedInUserId1); //dodajPrzychod, nie wiem jak przeslac ID zalogowanego uzytkownika z "PersonalBudget", wiec chwilowo kombinuje
    Incomies podajDaneNowegoPrzychodu(int loggedInUserId);
    int getNewIncomieId(); //przypisuje nowe ID do wydatku
    string zamienDateNaTekstBezKresek(string dataZKreskami);

    void wyswietlDaneZVectora();//tymczasowe
    void wyswietl(Incomies incomiesC);//tymczasowe

    void dodajWydatek();//puste
    void bilansZBiezacegoMiasiaca();//puste
    void bilansZPoprzedniegoMiesiaca();//puste
    void bilansZWybranegoOkresu();//puste

    //sprawdzanie daty
    void zamienDateNaZmienneInt(string dataZKreskami);
    bool czyDataJestPrawidlowa(string dataZKreskami);
    int maksymalnaIloscDniWMiesiacu(bool rokPrzestepny);
    bool czyRokJestPrzestepny();

};

#endif
