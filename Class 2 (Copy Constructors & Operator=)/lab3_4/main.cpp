#include <iostream>

//Во оваа задача е потребно да уредите даден дом со маси. Креирајте класа Masa со следниве атрибути:
//
//должина (целобројна вредност)
//ширина (целобројна вредност)
//конструктор со и без параметри и метода pecati().
//
//Креирајте класа Soba која содржи:
//
//маса (објект од класата Маса)
//должина на собата (целобројна вредност)
//ширина на собата (целобројна вредност)
//конструктор со и без параметри и метода pecati() во која се повикува и pecati() за објектот Masa.
//
//Креирајте класа Kukja со атрибути:
//
//соба (објект од класата Soba)
//адреса (низа од 50 знаци), и соодветни методи.
//конструктор со и без параметри, деструктор и метода pecati() во која се повикува и pecati() за објектот Soba.

//Input
//2
//1 2 10 5 Dame_Gruev_93b
//1 3 12 3 Petta_Avenija_6
//Output
//Adresa: Dame_Gruev_93b Soba: 10 5 Masa: 1 2
//Adresa: Petta_Avenija_6 Soba: 12 3 Masa: 1 3

//Input
//1
//2 7 12 14 Ruzveltova_3
//Output
//Adresa: Ruzveltova_3 Soba: 12 14 Masa: 2 7

//Input
//3
//2 4 10 20 Goce_Delcev_20
//1 1 12 43 Pitu_Guli_2
//2 4 10 20 Partizanski_Odredi_87_b
//Output
//Adresa: Goce_Delcev_20 Soba: 10 20 Masa: 2 4
//Adresa: Pitu_Guli_2 Soba: 12 43 Masa: 1 1
//Adresa: Partizanski_Odredi_87_b Soba: 10 20 Masa: 2 4
using namespace std;


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int masaSirina, masaDolzina;
        cin >> masaSirina;
        cin >> masaDolzina;
        Masa m(masaSirina, masaDolzina);
        int sobaSirina, sobaDolzina;
        cin >> sobaSirina;
        cin >> sobaDolzina;
        Soba s(sobaSirina, sobaDolzina, m);
        char adresa[30];
        cin >> adresa;
        Kukja k(s, adresa);
        k.pecati();
    }

    return 0;
}
