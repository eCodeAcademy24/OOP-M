#include <iostream>
#include <cstring>

using namespace std;

//Да се дефинира класа Film, во која ќе се чуваат информации за:
//
//име низа од 100 знаци
//режисер низа од 50 знаци
//жанр низа од 50 знаци
//година цел број
//Сите променливи треба да бидат приватни. Соодветно во рамките на класата да се дефинираат:
//
//default конструктор и конструктор со аргументи
//метод за печатење на информациите за филмот
//Дополнително да се реализира надворешна функција:
//
//void pecati_po_godina(Film *f, int n, int godina) која ќе прима аргумент низа од филмови,
// вкупниот број на филмови и година, а треба да ги отпечати само филмовите кои се направени во дадената година.

class Film {
private:
    char ime[100];
    char rezhiser[50];
    char zhanr[50];
    int godina;
public:
    Film() {}

    Film(char *ime, char *rezhiser, char *zhanr, int godina) {
        strcpy(this->ime, ime);
        strcpy(this->rezhiser, rezhiser);
        strcpy(this->zhanr, zhanr);
        this->godina = godina;
    }

    // get methods
    char *getIme() {
        return ime;
    }

    char *getRezhiser() {
        return rezhiser;
    }

    char *getZhanr() {
        return zhanr;
    }

    int getGodina() {
        return godina;
    }

    // set methods
    void setIme(char *ime) {
        strcpy(this->ime, ime);
    }

    void setRezhiser(char *rezhiser) {
        strcpy(this->rezhiser, rezhiser);
    }

    void setZhanr(char *zhanr) {
        strcpy(this->zhanr, zhanr);
    }

    void setGodina(int godina) {
        this->godina = godina;
    }

    //Output
    //Ime: Wall-E
    //Reziser: Andrew_Stanton
    //Zanr: Animation
    //Godina: 2008
    void print() {
        //Ime: Wall-E
        cout << "Ime: " << ime << endl;

        //Reziser: Andrew_Stanton
        cout << "Reziser: " << rezhiser << endl;

        //Zanr: Animation
        cout << "Zanr: " << zhanr << endl;

        //Godina: 2008
        cout << "Godina: " << godina << endl;
    }
};

// void pecati_po_godina(Film *f, int n, int godina) која ќе прима аргумент низа од филмови,
// вкупниот број на филмови и година, а треба да ги отпечати само филмовите кои се направени во дадената година.

void pecati_po_godina(Film *f, int n, int godina) {
    for (int i = 0; i < n; i++) {
        if (f[i].getGodina() == godina) {
            f[i].print();
        }
    }
}

//Input
//4
//Frankenweenie
//Tim_Burton
//Animation
//2012
//Lincoln
//Steven_Spielberg
//History
//2012
//Wall-E
//Andrew_Stanton
//Animation
//2008
//Avatar
//James_Cameron
//Fantasy
//2009
//2008
//Output
//Ime: Wall-E
//Reziser: Andrew_Stanton
//Zanr: Animation
//Godina: 2008
int main() {
    int brFilmovi;
    cin >> brFilmovi;

    Film filmovi[brFilmovi];

    for (int i = 0; i < brFilmovi; i++) {
        char ime[100]; //Frankenweenie --> ime
        char rezhiser[50]; //Tim_Burton --> rezhiser
        char zhanr[50]; //Animation --> zhanr
        int godina; //2012 --> godina
        cin >> ime >> rezhiser >> zhanr >> godina;

        Film film(ime, rezhiser, zhanr, godina);
        filmovi[i] = film;
    }

    //2008 --> godina po koja da se pechati
    int godina_za_pecati;
    cin >> godina_za_pecati;

    pecati_po_godina(filmovi, brFilmovi, godina_za_pecati);
    return 0;
}