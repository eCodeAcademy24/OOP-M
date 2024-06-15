#include <iostream>
#include <cstring>

using namespace std;

class Pica {
    char ime[15];
    int cena;
    char *sostojki;
    int promocija;

    void copy(const Pica &p) {
        this->sostojki = new char[strlen(p.sostojki) + 1];
        strcpy(this->sostojki, p.sostojki);
        strcpy(this->ime, p.ime);
        this->cena = p.cena;
        this->promocija = p.promocija;
    }

public:
    Pica() {
        strcpy(ime, "");
        this->cena = 0;
        this->promocija = 0;
        this->sostojki = new char[1];
        strcpy(sostojki, "");
    }

    Pica(char *ime, int cena, char *sostojki, int promocija) {
        strcpy(this->ime, ime);
        this->cena = cena;
        this->sostojki = new char[strlen(sostojki) + 1];
        strcpy(this->sostojki, sostojki);
        this->promocija = promocija;
    }

    Pica(const Pica &p) {
        copy(p);
    }

    Pica &operator=(const Pica &p) {
        if (this != &p) {
            delete[] sostojki;
            copy(p);
        }
        return *this;
    }

    ~Pica() {
        delete[] sostojki;
    }

    void pecati() {
        cout << ime << " - " << sostojki << ", " << cena << " " << cena - ((cena * promocija) / 100) << endl;
    }

    bool istiSe(Pica p) {
        return strcmp(this->sostojki, p.sostojki) == 0;
    }

    int getPromocija() {
        return promocija;
    }
};

class Picerija {
    char ime[15];
    Pica *p;
    int brojNaPici;

    void copy(const Picerija &p1) {
        this->brojNaPici = p1.brojNaPici;
        this->p = new Pica[p1.brojNaPici];
        for (int i = 0; i < brojNaPici; i++) {
            this->p[i] = p1.p[i];
        }
        strcpy(this->ime, p1.ime);
    }

public:
    Picerija() {
        strcpy(this->ime, "");
        this->brojNaPici = 0;
        this->p = new Pica[0];
    }

    Picerija(char *ime) {
        strcpy(this->ime, ime);
        this->brojNaPici = 0;
        this->p = new Pica[0];
    }

    Picerija(const Picerija &p1) {
        copy(p1);
    }

    Picerija &operator=(const Picerija &p1) {
        if (this != &p1) {
            delete[] p;
            copy(p1);
        }
        return *this;
    }

    ~Picerija() {
        delete[] p;
    }

    void dodadi(Pica p) {
        for (int i = 0; i < brojNaPici; i++) {
            if (this->p[i].istiSe(p)) {
                return;
            }
        }
        Pica *tmp = new Pica[brojNaPici + 1];
        for (int i = 0; i < brojNaPici; i++) {
            tmp[i] = this->p[i];
        }
        tmp[brojNaPici++] = p;
        delete[] this->p;
        this->p = tmp;
    }

    void piciNaPromocija() {
        for (int i = 0; i < brojNaPici; i++) {
            if (this->p[i].getPromocija() > 0 && this->p[i].getPromocija() < 100) {
                p[i].pecati();
            }
        }
    }

    void setIme(char *ime) {
        strcpy(this->ime, ime);
    }

    char *getIme() {
        return ime;
    }
};

int main() {
    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for (int i = 0; i < n; i++) {
        char imp[100];
        cin.get();
        cin.getline(imp, 100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki, 100);
        int popust;
        cin >> popust;
        Pica p(imp, cena, sostojki, popust);
        p1.dodadi(p);
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp, 100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki, 100);
    int popust;
    cin >> popust;
    Pica p(imp, cena, sostojki, popust);
    p2.dodadi(p);

    cout << p1.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p1.piciNaPromocija();

    cout << p2.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p2.piciNaPromocija();

    return 0;
}
