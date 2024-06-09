#include <iostream>
#include <string.h>

using namespace std;
//Креирајте класа Rabotnik која во себе содржи:
//
//ime (низа од максимум 30 знаци)
//prezime (низа од максимум 30 знаци)
//plata (целобројна вредност)
//За оваа класа да се креираат default конструктор и конструктор со аргументи.
// Да се имплементираат и следните методи:
//
//getPlata() која ја враќа платата на работникот
//pecati() која ги печати името, презимето и платата.
class Rabotnik {
private:
    char ime[30];
    char prezime[30];
    int plata;

public:
    Rabotnik() {
    }

    Rabotnik(char *ime, char *prezime, int plata) {
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        this->plata = plata;
    }

    Rabotnik(const Rabotnik &k) {
        strcpy(ime, k.ime);
        strcpy(prezime, k.prezime);
        plata = k.plata;
    }

    Rabotnik &operator=(const Rabotnik &k) {
        if (this != &k) {
            strcpy(ime, k.ime);
            strcpy(prezime, k.prezime);
            plata = k.plata;
        }
        return *this;
    }

    ~Rabotnik() {
    }

    int getPlata() {
        return plata;
    }

    void pecati() {
        cout << ime << " " << prezime << " " << plata << endl;
    }
};

//Креирајте класа Fabrika во која има:
//
//rabotnik [100] (низа од вработени)
//brojVraboteni (целобројна вредност)
//Во класата имплементирајте ги следните методи:
//
//pecatiVraboteni() ги печати сите вработени
//pecatiSoPlata(int plata) ги печати сите вработени со плата поголема или еднаква на
//дадената во аргументот(int plata).
class Fabrika {
private:
    Rabotnik rabotnici[100];
    int brVrab;

public:
    Fabrika() {
    }

    Fabrika(Rabotnik *rabotnici, int brVrab) {
        this->brVrab = brVrab;
        for (int i = 0; i < brVrab; i++) {
            this->rabotnici[i] = rabotnici[i];
        }
    }

    Fabrika(const Fabrika &f) {
        brVrab = f.brVrab;
        for (int i = 0; i < brVrab; i++) {
            rabotnici[i] = f.rabotnici[i];
        }
    }

    Fabrika &operator=(const Fabrika &f) {
        if (this != &f) {
            brVrab = f.brVrab;
            for (int i = 0; i < brVrab; i++) {
                rabotnici[i] = f.rabotnici[i];
            }
        }

        return *this;
    }

    ~Fabrika() {
    }

    //pecatiVraboteni() ги печати сите вработени
    void pecatiVraboteni() {
        for (int i = 0; i < brVrab; i++) {
            rabotnici[i].pecati();
        }
    }

    //pecatiSoPlata(int plata) ги печати сите вработени со плата поголема или еднаква на
    //дадената во аргументот(int plata).

    void pecatiSoPlata(int plata) {
        for (int i = 0; i < brVrab; i++) {
            if (rabotnici[i].getPlata() >= plata) {
                rabotnici[i].pecati();
            }
        }
    }
};

//Во главната функција се внесуваат податоци за n вработени. Притоа прво се внесува n,
// па податоците за сите n вработени. Во последниот ред се чита минималната плата.
//
//На излез да се прикажат прво сите вработени, а потоа само оние со поголема плата од минималната.
// Треба да се корисатат методите pecatiVraboteni и pecatiSoPlata!

//Input
// 6
//  Mile Palkovski 20000
//  Kalina Saleska 9530
//  Aco Noveski 66320
//  Kalina Saleska 10720
//  Ilinka Ilieska 30220
//  Vesna Petkova 10500
//  23000
//Output
// Site vraboteni:
// Mile Palkovski 20000
// Kalina Saleska 9530
// Aco Noveski 66320
// Kalina Saleska 10720
// Ilinka Ilieska 30220
// Vesna Petkova 10500
// Vraboteni so plata povisoka od 23000 :
// Aco Noveski 66320
// Ilinka Ilieska 30220
int main() {
    Rabotnik rab[100];
    int i, n;
    char ime[30], prezime[30];
    int plata, minPlata;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> ime >> prezime >> plata;
        rab[i] = Rabotnik(ime, prezime, plata);
    }
    Fabrika fab(rab, n);
    cin >> minPlata;
    cout << "Site vraboteni: " << endl;
    fab.pecatiVraboteni();
    cout << "Vraboteni so plata povisoka od " << minPlata << " :" << endl;
    fab.pecatiSoPlata(minPlata);
    return 0;
}
