#include <iostream>
#include <string.h>

using namespace std;

//Да се дефинира класа Potpisuvac во која се чуваат информации за:
//
//име (низа од максимум 20 знаци)
//презиме (низа од максимум 20 знаци)
//ЕМБГ (низа од максимум 14 знаци)
//За класата да се дефинира copy конструктор, default конструктор и конструктор со аргументи.
//
//Да се дефинира класа Dogovor, во која се чуваат информации за:
//
//број на договор (int),
//категорија на договор (низа од 50 знаци),
//поле од 3 потпишувачи на договорот (објекти од класата Potpisuvac)
//Во класата да се додаде метод кој ќе проверува дали постојат два исти потпишувачи (имаат ист ЕМБГ).


class Potpisuvac {
private:
    char ime[20];
    char prezime[20];
    char EMBG[14];
public:
    Potpisuvac() {

    }

    Potpisuvac(char *ime, char *prezime, char *EMBG) {
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        strcpy(this->EMBG, EMBG);
    }

    Potpisuvac(const Potpisuvac &p) {
        strcpy(ime, p.ime);
        strcpy(prezime, p.prezime);
        strcpy(EMBG, p.EMBG);
    }

    Potpisuvac &operator=(const Potpisuvac &p) {
        if (this != &p) {
            strcpy(ime, p.ime);
            strcpy(prezime, p.prezime);
            strcpy(EMBG, p.EMBG);
        }

        return *this;
    }

    char *getEMBG() {
        return EMBG;
    }

    ~Potpisuvac() {}
};


class Dogovor {
private:
    int brojDogovor;
    char kategorija[50];
    Potpisuvac potpisuvac[3];
public:
    Dogovor() {

    }

    Dogovor(int brojDogovor, char *kategorija, Potpisuvac *potpisuvac) {
        this->brojDogovor = brojDogovor;
        strcpy(this->kategorija, kategorija);
        for (int i = 0; i < 3; i++) {
            this->potpisuvac[i] = potpisuvac[i];
        }
    }

    Dogovor(const Dogovor &dogovor) {
        brojDogovor = dogovor.brojDogovor;
        strcpy(kategorija, dogovor.kategorija);
        for (int i = 0; i < 3; i++) {
            potpisuvac[i] = dogovor.potpisuvac[i];
        }
    }

    Dogovor &operator=(const Dogovor &dogovor) {
        if (this != &dogovor) {
            brojDogovor = dogovor.brojDogovor;
            strcpy(kategorija, dogovor.kategorija);
            for (int i = 0; i < 3; i++) {
                potpisuvac[i] = dogovor.potpisuvac[i];
            }
        }

        return *this;
    }

    ~Dogovor() {}

    //Во класата да се додаде метод кој ќе проверува дали постојат два исти потпишувачи (имаат ист ЕМБГ).
    bool proverka() {
        for (int i = 0; i < 3; i++) {
            if (strcmp(potpisuvac[i].getEMBG(), potpisuvac[i + 1].getEMBG()) == 0) {
                return true;
            }
        }

        return false;
    }
};

//Input
//2
//0101988450001 Alek Aleksov
//0101988450001 Alek Aleksov
//0202987440022 Marko Markov
//1 Osiguruvanje
//0101988450001 Alek Aleksov
//0101988450011 Tome Tomov
//0202987440022 Marko Markov
//2 Kreditiranje
//Output
//Dogovor 1:
//Postojat potpishuvaci so ist EMBG
//Dogovor 2:
//Ne postojat potpishuvaci so ist EMBG


//ne smee da se menuva main funkcijata
int main() {
    char embg[14], ime[20], prezime[20], kategorija[20];
    int broj, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> embg >> ime >> prezime;
        Potpisuvac p1(ime, prezime, embg);
        cin >> embg >> ime >> prezime;
        Potpisuvac p2(ime, prezime, embg);
        cin >> embg >> ime >> prezime;
        Potpisuvac p3(ime, prezime, embg);
        cin >> broj >> kategorija;
        Potpisuvac p[3];
        p[0] = p1;
        p[1] = p2;
        p[2] = p3;
        Dogovor d(broj, kategorija, p);
        cout << "Dogovor " << broj << ":" << endl;
        if (d.proverka() == true)
            cout << "Postojat potpishuvaci so ist EMBG" << endl;
        else
            cout << "Ne postojat potpishuvaci so ist EMBG" << endl;
    }
    return 0;
}