#include <iostream>
#include <cstring>

using namespace std;

//Да се напише класа Automobile во која се чуваат информации за марката на автомобилот (динамички алоцирана низа од знаци), регистрација (динамички алоцирана низа од 5 цели броја)
//и максимална брзина (цел број). За класата да се обезбедат set и get методите што се користат и да се преоптоварат следните оператори:
//
//оператор == за споредување на два автомобила според регистрацијата
//оператор << за печатење на податоци на автомобил во формат Marka:име Registracija:[x y z k l]

//Да се напише класа RentACar за агенција за измајмување возила во која се чуваат информација за името на агенцијата (низа од 100 знци), низа од автомобили (динамички алоациана
//низа од објекти од класата Automobile) и број на автомобили со кој располага (цел број). Во класата RentACar да се напише конструктор со еден аргумент за иницијализација на
//името на агенцијата. При секое додавање на нов автомобил, динамички алоцираната низа да го зголемува капацитетот за 1 елемент. Во оваа класа да се преоптоварат операторите:
//
//+= за додавање на нов автомобил во агенцијата и
//
//-= за отстранување на даден автомобил од агенцијата (оној со иста регистрација).
//
//Да се напише main функција во која се инстанцира објект од класата RentACar. Во овој објект да се додадат сите автомобили чии информации се читаат од тастатура со операторот +=.
//        Меѓутоа, откриено е дека во внесувањето на податоците има грешка затоа што при обид да се додаде нов автомобил во агенцијата, увидено е дека таа регистрација веќе постои.
//        Во последниот ред од влезот дадени се инфромации тој автомобил. Потребно е да се избрише автомобилот што претходно е погрешно внесен и да се додаде новиот.
//
//На излез да се отпечатат името на агенцијата и листа на автомобили што таа ги изнајмува, а чија максимална брзина е поголема од 150. Последново да се направи со функција
//pecatiNadBrzina(int max) што треба да се дефинира во класата RentACar.

class Automobile {
    char *marka;
    int *registracija;
    int brzina;

    void copy(const Automobile &a) {
        this->marka = new char[strlen(a.marka) + 1];
        strcpy(this->marka, a.marka);
        this->registracija = new int[5];
        for (int i = 0; i < 5; i++) {
            this->registracija[i] = a.registracija[i];
        }
        this->brzina = a.brzina;
    }

public:
    Automobile() {
        marka = new char[0];
        registracija = new int[5];
        brzina = 0;
    }

    Automobile(char *marka, int *registracija, int brzina) {
        this->marka = new char[strlen(marka) + 1];
        strcpy(this->marka, marka);

        // ova go pravime samo dokolku imame niza od int, double, float vrednosti
        this->registracija = new int[5];
        for (int i = 0; i < 5; i++) {
            this->registracija[i] = registracija[i];
        }
        // ------------------------------------------
        this->brzina = brzina;
    }

    Automobile(const Automobile &a) {
        copy(a);
    }

    Automobile &operator=(const Automobile &a) {
        if (this != &a) {
            delete[] marka;
            delete[] registracija;
            copy(a);
        }

        return *this;
    }

    bool operator==(const Automobile &a) {
        int brojac = 0;
        for (int i = 0; i < 5; i++) {
            if (this->registracija[i] == a.registracija[i]) {
                brojac++;
            }
        }
        if (brojac == 5) {
            return true;
        }
        return false;
    }

//    Marka:име Registracija:[x y z k l]
    friend ostream &operator<<(ostream &out, const Automobile &a) {
        out << "Marka:" << a.marka << " Registracija:[ ";
        for (int i = 0; i < 5; i++) {
            out << a.registracija[i] << " ";
        }
        out << "]" << endl;
        return out;
    }

    int getBrzina() {
        return brzina;
    }
};

class RentACar {
    char ime[100];
    Automobile *avtomobili;
    int brojA;

public:
    RentACar(char *ime = "") {
        strcpy(this->ime, ime);
        this->avtomobili = new Automobile[0];
        this->brojA = 0;
    }

    RentACar & operator+=(const Automobile &a) {
        Automobile *tmp = new Automobile[brojA + 1];
        for(int i = 0; i < brojA; i++) {
            tmp[i] = avtomobili[i];
        }
        tmp[brojA++] = a;
        delete [] avtomobili;
        avtomobili = tmp;
        return *this;
    }

    RentACar &operator -=(const Automobile &a) {
        Automobile *tmp = new Automobile[brojA - 1];
        int brojac = 0;
        for(int i = 0; i < brojA; i++) {
            if(avtomobili[i] == a) {
                continue;
            } else {
                tmp[brojac++] = avtomobili[i];
            }
        }
        delete [] avtomobili;
        avtomobili = tmp;
        brojA = brojac;
        return *this;
    }

    void pecatiNadBrzina(int max) {
        cout << ime << endl;
        for(int i = 0; i < brojA; i++) {
            if(avtomobili[i].getBrzina() > max) {
                cout << avtomobili[i] << endl;
            }
        }
    }

};

int main() {
    RentACar agencija("FINKI-Car");
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char marka[100];
        int regisracija[5];
        int maximumBrzina;

        cin >> marka;

        for (int i = 0; i < 5; i++)
            cin >> regisracija[i];

        cin >> maximumBrzina;

        Automobile nov = Automobile(marka, regisracija, maximumBrzina);

        //dodavanje na avtomobil
        agencija += nov;

    }
    //se cita grehsniot avtmobil, za koj shto avtmobilot so ista registracija treba da se izbrishe
    char marka[100];
    int regisracija[5];
    int maximumBrzina;
    cin >> marka;
    for (int i = 0; i < 5; i++)
        cin >> regisracija[i];
    cin >> maximumBrzina;

    Automobile greshka = Automobile(marka, regisracija, maximumBrzina);

    //brishenje na avtomobil
    agencija -= greshka;

    agencija.pecatiNadBrzina(150);

    return 0;
}
