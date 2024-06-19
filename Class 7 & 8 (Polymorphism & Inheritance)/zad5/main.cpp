#include <iostream>
#include <cstring>
using namespace std;
//Да се дефинира класа Ekipa за коjа се чуваат следниве информации:
//
// името на екипата (низа од наjмногу 15 знаци)
// броj на порази
// броj на победи
// За оваа класа да се дефинира метод pecati() коjа ги печати податоците за екипаta.
class Ekipa {
protected:
    char ime[15];
    int brPorazi;
    int brPobedi;

public:
    Ekipa() {
    }

    Ekipa(char *ime, int brPobedi, int brPorazi) {
        strcpy(this->ime, ime);
        this->brPobedi = brPobedi;
        this->brPorazi = brPorazi;
    }

    Ekipa(const Ekipa &e) {
        strcpy(ime, e.ime);
        brPobedi = e.brPobedi;
        brPorazi = e.brPorazi;
    }

    Ekipa &operator=(const Ekipa &e) {
        if (this != &e) {
            strcpy(ime, e.ime);
            brPobedi = e.brPobedi;
            brPorazi = e.brPorazi;
        }

        return *this;
    }

    // За оваа класа да се дефинира метод pecati() коjа ги печати податоците за екипаta.
    void pecati() {
        //Ime: Arsenal Pobedi: 4 Porazi: 6
        cout << "Ime: " << ime << " Pobedi: " << brPobedi << " Porazi: " << brPorazi;
    }

    ~Ekipa() {
    }
};

// Од оваа класа да се изведe новa класa, FudbalskaEkipa.
//
// За фудбалската екипа дополнително се чуваат информации за:
//
// вкупниот броj на црвени картони
// вкупниот броj жолти картони
// броjот на нерешени натпревари
// За фудбалската екипа да се преоптовари методот pecati(), така што покрај останатите информации,
// ќе се испечатат и бројот на нерешени резултати и вкупен број на поени во формат: Име на екипа, броj на победи,
// броj на порази, броj на нерешени натпревари и вкупен броj на поени
// (за победа фудбалската екипа добива 3 поени, додека за нерешен резултата, 1 поен);
class FudbalskaEkipa : public Ekipa {
private:
    int brCrveni;
    int brZholti;
    int brNeresheni;

public:
    FudbalskaEkipa(): Ekipa() {
    }

    FudbalskaEkipa(char *ime, int brPobedi, int brPorazi, int brCrveni, int brZholti, int brNeresheni) : Ekipa(
        ime, brPobedi, brPorazi) {
        this->brCrveni = brCrveni;
        this->brZholti = brZholti;
        this->brNeresheni = brNeresheni;
    }

    FudbalskaEkipa(const FudbalskaEkipa &fe) : Ekipa(fe) {
        brCrveni = fe.brCrveni;
        brZholti = fe.brZholti;
        brNeresheni = fe.brNeresheni;
    }

    FudbalskaEkipa &operator=(const FudbalskaEkipa &fe) {
        if (this != &fe) {
            strcpy(ime, fe.ime);
            brPobedi = fe.brPobedi;
            brPorazi = fe.brPorazi;
            brCrveni = fe.brCrveni;
            brZholti = fe.brZholti;
            brNeresheni = fe.brNeresheni;
        }

        return *this;
    }

    ~FudbalskaEkipa() {
    }

    double poeni() {
        return (brPobedi * 3) + (brNeresheni * 1); // mozhe i samo + brNeresheni, poradi toa shto mnozhime so 1.
    }

    // За фудбалската екипа да се преоптовари методот pecati(), така што покрај останатите информации,
    // ќе се испечатат и бројот на нерешени резултати и вкупен број на поени во формат: Име на екипа, броj на победи,
    // броj на порази, броj на нерешени натпревари и вкупен броj на поени
    // (за победа фудбалската екипа добива 3 поени, додека за нерешен резултат, 1 поен);
    void pecati() {
        Ekipa::pecati(); // --> tuka kje se ispechati samo do broj na porazi

        // Nereseni: 5 Poeni: 17
        cout << " Nereseni: " << brNeresheni << " Poeni: " << poeni() << endl;
    }
};

//Input
// Arsenal
//  4
//  6
//  1
//  2
//  5
//Output
//Ime: Arsenal Pobedi: 4 Porazi: 6 Nereseni: 5 Poeni: 17

int main() {
    char ime[15];
    int pob, por, ck, zk, ner;
    cin >> ime >> pob >> por >> ck >> zk >> ner;
    FudbalskaEkipa f1(ime, pob, por, ck, zk, ner);
    f1.pecati();
    return 0;
}
