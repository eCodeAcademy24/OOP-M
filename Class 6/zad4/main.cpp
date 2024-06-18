#include <iostream>
#include <cstring>
//Да се креира класа за претставување на планинарско друштво во која ќе се чуваат информации за името на друштвото (динамички алоцирана низа од знаци),
// број на поминати тури (цел број) и број на членови во планинарското друштво (цел број). За оваа класа да се напише:
//
// *оператор + за собирање на две друштва што како резултат враќа друштво со број на членови еднаков на збирот од членовите од двете друштва,
// а останатите атрибути на резултантното друштво ги добиваат вредностите на соодветните атрибути од друштвото со поголем број на членови
//
// *оператори >, < за споредба во однос на бројот на членови во планинарските друштва
//
// *оператор << за печатење на информациите за планинарското друштво
//
//Да се напише функција што на влез прима низа од планинарски друштва и вкупен број на друштва во низата и го печати планинарското друштво што има најголем број на членови.

//Input
// Bistra
// 12
// 75
// Kozuv
// 15
// 89
// Kozjak
// 2
// 15
//Output
//Ime: Kozuv Turi: 15 Clenovi: 164
//Najmnogu clenovi ima planinarskoto drustvo: Ime: Kozuv Turi: 15 Clenovi: 89
#include <iostream>
#include <cstring>
using namespace std;


class PlDrustvo {
private:
    char *ime;
    int turi;
    int brclen;

public:
    PlDrustvo() {
        this->ime = new char[0];
        turi = 0;
        brclen = 0;
    }

    PlDrustvo(char *ime, int turi, int brclen) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->turi = turi;
        this->brclen = brclen;
    }

    PlDrustvo(const PlDrustvo &p) {
        this->ime = new char[strlen(p.ime) + 1];
        strcpy(this->ime, p.ime);
        this->turi = p.turi;
        this->brclen = p.brclen;
    }

    PlDrustvo &operator=(const PlDrustvo &p) {
        if (this != &p) {
            delete[] ime;
            this->ime = new char[strlen(p.ime) + 1];
            strcpy(this->ime, p.ime);
            this->turi = p.turi;
            this->brclen = p.brclen;
        }
        return *this;
    }

    ~PlDrustvo() {
        delete[]ime;
    }

    int getBrClen() {
        return brclen;
    }

    PlDrustvo operator+(const PlDrustvo &p) {
        PlDrustvo result;
        result.brclen = this->brclen + p.brclen;
        if (this->brclen > p.brclen) {
            result.ime = new char[strlen(this->ime) + 1];
            strcpy(result.ime, this->ime);
            result.turi = this->turi;
        } else {
            result.ime = new char[strlen(p.ime) + 1];
            strcpy(result.ime, p.ime);
            result.turi = p.turi;
        }

        return result;
    }

    bool operator>(const PlDrustvo &p) {
        return this->brclen > p.brclen;
    }

    bool operator<(const PlDrustvo &p) {
        return this->brclen < p.brclen;
    }

    friend ostream &operator<<(ostream &out, const PlDrustvo &p) {
        out << "Ime: " << p.ime << " Turi: " << p.turi << " Clenovi: " << p.brclen << endl;
        return out;
    }
};


void najmnoguClenovi(PlDrustvo *p, int n) {
    PlDrustvo max = p[0];

    for (int i = 1; i < n; i++) {
        if (p[i] > max) {
            max = p[i];
        }
    }

    cout << "Najmnogu clenovi ima planinarskoto drustvo: " << max;
}

int main() {
    PlDrustvo drustva[3];
    PlDrustvo pl;
    for (int i = 0; i < 3; i++) {
        char ime[100];
        int brTuri;
        int brClenovi;
        cin >> ime;
        cin >> brTuri;
        cin >> brClenovi;
        PlDrustvo p(ime, brTuri, brClenovi);
        drustva[i] = p;
    }

    pl = drustva[0] + drustva[1];
    cout << pl;

    najmnoguClenovi(drustva, 3);

    return 0;
}
