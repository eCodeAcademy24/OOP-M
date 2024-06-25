#include <iostream>
#include <cstring>

using namespace std;

enum zanr {
    akcija,
    komedija,
    drama,
};

class Film {
private:
    char *ime;
    int mb;
    zanr zanrr;

public:
    Film() {
        this->mb = 0;
        this->ime = new char[0];
    }

    Film(char *ime, int mb, zanr zanrr) {
        this->mb = mb;
        this->zanrr = zanrr;
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
    }

    Film(const Film &f) {
        this->mb = f.mb;
        this->zanrr = f.zanrr;
        this->ime = new char[strlen(f.ime) + 1];
        strcpy(this->ime, f.ime);
    }

    Film &operator=(const Film &f) {
        if (this != &f) {
            delete[] ime;
            this->mb = f.mb;
            this->zanrr = f.zanrr;
            this->ime = new char[strlen(f.ime) + 1];
            strcpy(this->ime, f.ime);
        }
        return *this;
    }

    ~Film() {
        delete[]ime;
    }

    void pecati() {
        cout << mb << "MB-\"" << ime << "\"" << endl;
    }

    zanr getZanrr() {
        return zanrr;
    }

    int getMb() {
        return mb;
    }
};

class DVD {
private:
    Film film[5];
    int n;
    int mem;

public:
    DVD() {
        n = 0;
        mem = 0;
    }

    DVD(int mem) {
        this->mem = mem;
        n = 0;
    }

    DVD(const DVD &d) {
        this->n = d.n;
        this->mem = d.mem;
        for (int i = 0; i < n; i++) {
            this->film[i] = d.film[i];
        }
    }

    DVD &operator=(const DVD &d) {
        if (this != &d) {
            this->n = d.n;
            this->mem = d.mem;
            for (int i = 0; i < n; i++) {
                this->film[i] = d.film[i];
            }
        }
        return *this;
    }

    ~DVD() {
    }

    int currenCapacity() {
        int mesto = 0;
        for (int i = 0; i < n; i++) {
            mesto += film[i].getMb();
        }

        return mesto;
    }

    void dodadiFilm(Film &f) {
        if (n < 5 && currenCapacity() + f.getMb() <= mem) {
            film[n] = f;
            n++;
        }
    }

    void pecatiFilmoviDrugZanr(zanr z) {
        for (int i = 0; i < n; i++) {
            if (film[i].getZanrr() != z) {
                film[i].pecati();
            }
        }
    }

    float procentNaMemorijaOdZanr(zanr z) {
        int sumaSite = 0;
        int sumaZanr = 0;
        for (int i = 0; i < n; ++i) {
            sumaSite += film[i].getMb();
            if (film[i].getZanrr() == z) {
                sumaZanr += film[i].getMb();
            }
        }

        return ((float) sumaZanr / sumaSite) * 100.0;
    }

    Film &getFilm(int i) {
        return film[i];
    }

    int getBroj() {
        return n;
    }
};


int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, memorija, kojzanr;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Film ======" << endl;
        cin >> ime;
        cin >> memorija;
        cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
        Film f(ime, memorija, (zanr) kojzanr);
        f.pecati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < n; i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiFilm() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);
    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);
    } else if (testCase == 6) {
        cout << "===== Testiranje na metodot procentNaMemorijaOdZanr() od klasata DVD =====" << endl;
        DVD omileno(40);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        cout << "Procent na filmovi od dadeniot zanr iznesuva: " << omileno.procentNaMemorijaOdZanr((zanr) kojzanr)
                << "%\n";
    }

    return 0;
}
