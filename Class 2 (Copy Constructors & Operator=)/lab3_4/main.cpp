#include <iostream>
#include <cstring>
using namespace std;
//Во оваа задача е потребно да уредите даден дом со маси. Креирајте класа Masa со следниве атрибути:
//
//должина (целобројна вредност)
//ширина (целобројна вредност)
//конструктор со и без параметри и метода pecati().

class Masa {
private:
    int dol;
    int sir;

public:
    Masa() {
    }

    Masa(int sir, int dol) {
        this->sir = sir;
        this->dol = dol;
    }

    Masa(const Masa &m) {
        sir = m.sir;
        dol = m.dol;
    }

    Masa &operator=(const Masa &m) {
        if (this != &m) {
            sir = m.sir;
            dol = m.dol;
        }
        return *this;
    }

    ~Masa() {
    }

    void pecati() {
        cout << "Masa: " << sir << " " << dol << endl;
    }

    int getDol() {
        return dol;
    }

    void setDol(int dol) {
        this->dol = dol;
    }

    int getSir() {
        return sir;
    }

    void setSir(int sir) {
        this->sir = sir;
    }
};


//Креирајте класа Soba која содржи:
//
//маса (објект од класата Маса)
//должина на собата (целобројна вредност)
//ширина на собата (целобројна вредност)
//конструктор со и без параметри и метода pecati() во која се повикува и pecati()
//за објектот Masa.

class Soba {
private:
    Masa masa;
    int dol;
    int sir;

public:
    Soba() {
    }

    Soba(int sir, int dol, Masa masa) {
        this->sir = sir;
        this->dol = dol;
        this->masa = masa;
    }

    Soba(const Soba &s) {
        sir = s.sir;
        dol = s.dol;
        masa = s.masa;
    }

    Soba &operator=(const Soba &s) {
        if (this != &s) {
            sir = s.sir;
            dol = s.dol;
            masa = s.masa;
        }
        return *this;
    }

    ~Soba() {
    }

    void pecati() {
        cout << "Soba: " << sir << " " << dol << " ";
        masa.pecati();
    }

    Masa getMasa() {
        return masa;
    }

    void setMasa(Masa masa) {
        this->masa = masa;
    }

    int getDol() {
        return dol;
    }

    void setDol(int dol) {
        this->dol = dol;
    }

    int getSir() {
        return sir;
    }

    void setSir(int sir) {
        this->sir = sir;
    }
};


//Креирајте класа Kukja со атрибути:
//
//соба (објект од класата Soba)
//адреса (низа од 50 знаци), и соодветни методи.
//конструктор со и без параметри, деструктор и метода pecati() во која се повикува и pecati() за објектот Soba.
class Kukja {
private:
    Soba soba;
    char adr[50];

public:
    Kukja() {
    }

    Kukja(Soba soba, char *adr) {
        this->soba = soba;
        strcpy(this->adr, adr);
    }

    Kukja(const Kukja &k) {
        soba = k.soba;
        strcpy(adr, k.adr);
    }

    Kukja &operator=(const Kukja &k) {
        if (this != &k) {
            soba = k.soba;
            strcpy(adr, k.adr);
        }
        return *this;
    }

    ~Kukja() {
    }

    void pecati() {
        cout << "Adresa: " << adr << " ";
        soba.pecati();
    }

    Soba getSoba() {
        return soba;
    }

    void setSoba(Soba soba) {
        this->soba = soba;
    }

    char *getAdr() {
        return adr;
    }

    void setAdr(char *adr) {
        strcpy(this->adr, adr);
    }
};

//Input
//1
//2 7 12 14 Ruzveltova_3
//Output
//Adresa: Ruzveltova_3 Soba: 12 14 Masa: 2 7

//Input
//3
//
//2 4 10 20 Goce_Delcev_20
//1 1 12 43 Pitu_Guli_2
//2 4 10 20 Partizanski_Odredi_87_b
//Output
//Adresa: Goce_Delcev_20 Soba: 10 20 Masa: 2 4
//Adresa: Pitu_Guli_2 Soba: 12 43 Masa: 1 1
//Adresa: Partizanski_Odredi_87_b Soba: 10 20 Masa: 2 4
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
