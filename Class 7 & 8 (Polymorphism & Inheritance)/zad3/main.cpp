#include <iostream>
#include <cstring>
using namespace std;
//Со цел да се подобри системот Мој Термин, со воведување функционалност за пресметување
//плати за лекарите за еден месец, од Министерството за здравство на Република Македонија,
//ги добивате следните задачи:
//
// Да се креира класа Lekar во која што ќе се чуваат:
//
// факсимил на докторот (цел број)
// име (низа од максимум 10 знаци)
// презиме (низа од максимум 10 знаци)
// почетна плата (децимален број)
// За класата да се имплементираат методите:
//
// void pecati(): Печати информации за лекарот во формат Факсимил: име презиме
//
// double plata(): ја враќа платата на лекарот
class Lekar {
protected:
    int faksimil;
    char ime[15];
    char prezime[15];
    double osnovnaPlata;

public:
    Lekar() {
    }

    Lekar(int faksimil, char *ime, char *prezime, double plata) {
        this->faksimil = faksimil;
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        this->osnovnaPlata = plata;
    }

    Lekar(const Lekar &l) {
        faksimil = l.faksimil;
        strcpy(ime, l.ime);
        strcpy(prezime, l.prezime);
        osnovnaPlata = l.osnovnaPlata;
    }

    Lekar &operator=(const Lekar &l) {
        if (this != &l) {
            faksimil = l.faksimil;
            strcpy(ime, l.ime);
            strcpy(prezime, l.prezime);
            osnovnaPlata = l.osnovnaPlata;
        }

        return *this;
    }

    ~Lekar() {
    }


    // void pecati(): Печати информации за лекарот во формат Факсимил: име презиме
    void pecati() {
        cout << faksimil << ": " << ime << " " << prezime << endl;
    }

    // double plata(): ја враќа платата на лекарот
    double plata() {
        return osnovnaPlata;
    }
};

// Да се креира класа MaticenLekar која што наследува од Lekar и во неа се чуваат дополнителни
// информации за:
//
// број на пациенти со којшто лекарот соработувал во текот на месецот (цел број)
// котизации наплатени од пациентите во текот на месецот (динамички алоцирана низа од децимални броеви)
// За класата да се препокријат методитe:
//
// void pecati() : ги печати основните информации за лекарот, а во нов ред го печати и просекот
// од наплатените котизации
//
// double plata(): ја враќа платата на матичниот лекар
//
// Платата на матичниот лекар се пресметува со зголемување на основната плата за 30% од просекот
// од наплатените котизации за месецот

class MaticenLekar : public Lekar {
private:
    int brPacienti;
    double *kotizacii;

public:
    MaticenLekar() : Lekar() {
        brPacienti = 0;
        kotizacii = new double[0];
    }

    // MaticenLekar(int faksimil, char *ime, char *prezime, double osnovnaPlata, int brPacienti,
    //              double *kotizacii) : Lekar(faksimil, ime, prezime, osnovnaPlata) {
    //     this->brPacienti = brPacienti;
    //     this->kotizacii = new double[brPacienti];
    //     for(int i = 0; i < brPacienti; i++) {
    //         this->kotizacii[i] = kotizacii[i];
    //     }
    // }

    MaticenLekar(Lekar l, int brPacienti, double *kotizacii) : Lekar(l) {
        this->brPacienti = brPacienti;
        this->kotizacii = new double[brPacienti];
        for (int i = 0; i < brPacienti; i++) {
            this->kotizacii[i] = kotizacii[i];
        }
    }

    MaticenLekar(const MaticenLekar &ml) : Lekar(ml) {
        brPacienti = ml.brPacienti;
        kotizacii = new double[brPacienti];
        for (int i = 0; i < brPacienti; i++) {
            kotizacii[i] = ml.kotizacii[i];
        }
    }

    MaticenLekar &operator=(const MaticenLekar &ml) {
        if (this != &ml) {
            delete[] kotizacii;
            faksimil = ml.faksimil;
            strcpy(ime, ml.ime);
            strcpy(prezime, ml.prezime);
            osnovnaPlata = ml.osnovnaPlata;
            brPacienti = ml.brPacienti;
            kotizacii = new double[brPacienti];
            for (int i = 0; i < brPacienti; i++) {
                kotizacii[i] = ml.kotizacii[i];
            }
        }

        return *this;
    }

    ~MaticenLekar() {
        delete[] kotizacii;
    }

    double prosek() {
        double suma = 0.0;
        for (int i = 0; i < brPacienti; i++) {
            suma += kotizacii[i];
        }

        return suma / brPacienti;
    }

    // void pecati() : ги печати основните информации за лекарот, а во нов ред го печати и просекот
    // од наплатените котизации
    void pecati() {
        Lekar::pecati();
        // Prosek na kotizacii: 3772
        cout << "Prosek na kotizacii: " << prosek() << endl;
    }

    // double plata(): ја враќа платата на матичниот лекар
    // Платата на матичниот лекар се пресметува со зголемување на основната плата за 30% од просекот
    // од наплатените котизации за месецот
    double plata() {
        return Lekar::plata() + 0.3 * prosek();
    }
};

//Input
//7
// 766433 Cvetanka Cvetkova 27899.90
// 123122 Stefan Stefanov 31789.50
// 454323 Trajce Trajkov 19458.30
// 343989 Goran Trajkov 28945.10
// 515788 Nikola Nikolov 36985.50
// 784512 Viktorija Stojanovska 37855.00
// 985623 Ivana Ivanova 38745.70
// 5
// 1000 2000 2500 7800 5560
// 4
// 1000 2000 3000 10000
// 6
// 7800 7800 8000 9000 900 1000
// 5
// 1000 1500 2000 2300 2400
// 3
// 15000 10000 7580
// 4
// 10000 7000 8000 1000
// 3
// 1000 2000 3000
// 1
// 1
//Output
//===TESTIRANJE NA KLASATA LEKAR===
// 766433: Cvetanka Cvetkova
// Osnovnata plata na gorenavedeniot lekar e: 27899.9
// 123122: Stefan Stefanov
// Osnovnata plata na gorenavedeniot lekar e: 31789.5
// 454323: Trajce Trajkov
// Osnovnata plata na gorenavedeniot lekar e: 19458.3
// 343989: Goran Trajkov
// Osnovnata plata na gorenavedeniot lekar e: 28945.1
// 515788: Nikola Nikolov
// Osnovnata plata na gorenavedeniot lekar e: 36985.5
// 784512: Viktorija Stojanovska
// Osnovnata plata na gorenavedeniot lekar e: 37855
// 985623: Ivana Ivanova
// Osnovnata plata na gorenavedeniot lekar e: 38745.7

//Input
// 7
//  766433 Cvetanka Cvetkova 27899.90
//  123122 Stefan Stefanov 31789.50
//  454323 Trajce Trajkov 19458.30
//  343989 Goran Trajkov 28945.10
//  515788 Nikola Nikolov 36985.50
//  784512 Viktorija Stojanovska 37855.00
//  985623 Ivana Ivanova 38745.70
//  5
//  1000 2000 2500 7800 5560
//  4
//  1000 2000 3000 10000
//  6
//  7800 7800 8000 9000 900 1000
//  5
//  1000 1500 2000 2300 2400
//  3
//  15000 10000 7580
//  4
//  10000 7000 8000 1000
//  3
//  1000 2000 3000
//  2

//Output
//===TESTIRANJE NA KLASATA MATICENLEKAR===
// 766433: Cvetanka Cvetkova
// Prosek na kotizacii: 3772
// Platata na gorenavedeniot maticen lekar e: 29031.5
// 123122: Stefan Stefanov
// Prosek na kotizacii: 4000
// Platata na gorenavedeniot maticen lekar e: 32989.5
// 454323: Trajce Trajkov
// Prosek na kotizacii: 5750
// Platata na gorenavedeniot maticen lekar e: 21183.3
// 343989: Goran Trajkov
// Prosek na kotizacii: 1840
// Platata na gorenavedeniot maticen lekar e: 29497.1
// 515788: Nikola Nikolov
// Prosek na kotizacii: 10860
// Platata na gorenavedeniot maticen lekar e: 40243.5
// 784512: Viktorija Stojanovska
// Prosek na kotizacii: 6500
// Platata na gorenavedeniot maticen lekar e: 39805
// 985623: Ivana Ivanova
// Prosek na kotizacii: 2000
// Platata na gorenavedeniot maticen lekar e: 39345.7
int main() {
    int n;
    cin >> n;
    int pacienti;
    double kotizacii[100];
    int faksimil;
    char ime[20];
    char prezime[20];
    double osnovnaPlata;

    Lekar *lekari = new Lekar [n];
    MaticenLekar *maticni = new MaticenLekar [n];

    for (int i = 0; i < n; i++) {
        cin >> faksimil >> ime >> prezime >> osnovnaPlata;
        lekari[i] = Lekar(faksimil, ime, prezime, osnovnaPlata);
    }

    for (int i = 0; i < n; i++) {
        cin >> pacienti;
        for (int j = 0; j < pacienti; j++) {
            cin >> kotizacii[j];
        }
        maticni[i] = MaticenLekar(lekari[i], pacienti, kotizacii);
    }

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "===TESTIRANJE NA KLASATA LEKAR===" << endl;
        for (int i = 0; i < n; i++) {
            lekari[i].pecati();
            cout << "Osnovnata plata na gorenavedeniot lekar e: " << lekari[i].plata() << endl;
        }
    } else {
        cout << "===TESTIRANJE NA KLASATA MATICENLEKAR===" << endl;
        for (int i = 0; i < n; i++) {
            maticni[i].pecati();
            cout << "Platata na gorenavedeniot maticen lekar e: " << maticni[i].plata() << endl;
        }
    }

    delete [] lekari;
    delete [] maticni;

    return 0;
}
