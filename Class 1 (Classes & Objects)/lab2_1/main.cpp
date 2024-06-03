#include <iostream>
#include <cstring>
//Да се дефинира класа Agol, во која се чуваат информации за:
//
//степени, минути и секунди (int)
//Во класата да се реализираат:
//
//конструктор по потреба
//методи за поставување на вредности на атрибутите на класата (set методи)
//метод за пресметување на вредноста на аголот во секунди
//Да се дефинира и метод за проверување на тоа дали внесениот агол е валиден,
// односно дали се внесени соодветни вредности за атрибутите (во границите кои ги дозволуваат).
//Input
//15 20 20
//Output
// 55220

//Input
//380 80 0
//Output
//Nevalidni vrednosti za agol
using namespace std;


class Agol {
private:
    int stepeni;
    int minuti;
    int sekundi;
public:
    Agol() {}

    Agol(int stepeni, int minuti, int sekundi) {
        this->stepeni = stepeni;
        this->minuti = minuti;
        this->sekundi = sekundi;
    }

    int getStepeni() {
        return stepeni;
    }

    void set_stepeni(int stepeni) {
        this->stepeni = stepeni;
    }

    int getMinuti() {
        return minuti;
    }

    void set_minuti(int min) {
        minuti = min;
    }

    int getSekundi() {
        return sekundi;
    }

    void set_sekundi(int sek) {
        sekundi = sek;
    }

    int to_sekundi() {
        int vkupno = sekundi + minuti * 60 + stepeni * 3600;

        return vkupno;
    }
};

bool changeOfSeconds(Agol a, int sec) {
    return a.getSekundi() != sec;
}

bool proveri(int stepeni, int minuti, int sekundi) {
    if (stepeni > 360 || stepeni < 0) {
        return false;
    }

    if (minuti > 60 || minuti < 0) {
        return false;
    }

    if (sekundi > 60 || sekundi < 0) {
        return false;
    }

    return true;
}


int main() {
    //da se instancira objekt od klasata Agol
    Agol a1;
    int deg, min, sec;
    cin >> deg >> min >> sec;

    if (proveri(deg, min, sec)) {
        a1.set_stepeni(deg);
        a1.set_minuti(min);
        a1.set_sekundi(sec);
        cout << a1.to_sekundi();
        if (changeOfSeconds(a1, sec))
            cout << "Ne smeete da gi menuvate sekundite vo ramkite na klasata!" << endl;

    } else {
        cout << "Nevalidni vrednosti za agol";
    }

    return 0;
}