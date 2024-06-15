#include <iostream>
#include <cstring>

using namespace std;
//Фирмата FINKI Cloud има потреба од решение за управување со image датотеките од различните оперативни системи кои
// ги користат при сетирање на нови сервери. За таа цел потребно е да се дефинираат следниве класи:
//
//OperativenSistem
//Во класата OperativenSistem треба да се чуваат следниве податоци:
//име на оперативниот систем (динамички алоцирана низа од знаци)
//верзија (float)
//тип (енумерација со можни вредности LINUX, UNIX, WINDOWS)
//големина (во GB) (float)

//Дополнително, во рамките на класата потребно е да се дефинира:
//конструктори со и без параметри
//copy constructor
//destructor
//преоптоварување на операторот =

//метод за печатење на информациите - void pecati() (видете го излезот од тест примерите за структурата)
//метод за проверка на еднаквост помеѓу два оперативни системи (два оперативни системи се еднакви ако имаат исто име, верзија,
// тип и големина) - bool ednakviSe(const OperativenSistem &os)
//метод за споредба на верзии помеѓу два оперативни система - int sporediVerzija(const OperativenSistem &os), кој ќе враќа 0
// доколку верзиите се исти, -1 доколку верзијата на оперативниот систем од аргументот е поголема и 1 во преостанатиот случај.
//метод за проверка дали два оперативни системи се од иста фамилија. Два оперативни системи се од иста фамилија доколку имаат
// исто име и се од ист тип. bool istaFamilija(const OperativenSistem &sporedba)

//Repozitorium
//Во класата Repozitorium треба да се чуваат следниве податоци:
//
//име на репозиториумот (низа од 20 знака)
//динамички алоцирана низа од OperativenSistem
//број на оперативни системи кои моментално се наоѓаат во репозиториумот (int)
//Дополнително, во рамките на класата потребно е да се дефинира:
//конструктор Repozitorium(const char *ime)
//деструктор
//метод void pecatiOperativniSistemi() кој ќе ги печати сите оперативни системи кои се дел од репозиториумот
//метод void izbrishi(const OperativenSistem &operativenSistem) кој ќе го избрише оперативниот систем проследен како аргумент,
// доколку тој се наоѓа во репозиториумот. Да се користи методот ednakviSe за споредба на два оперативни система.
//метод за додавање на оперативен систем (void dodadi(const OperativenSistem &nov)) кој ќе го има следново однесување:
//Доколку веќе постои оперативен систем од иста фамилија (да се користи методот за проверка на фамилија) кој е постар од
//проследениот оперативен систем, тогаш постоечкиот оперативен систем се заменува со новиот.
//Во секој друг случај, проследениот оперативен систем се додава како дополнителен во репозиториумот.

enum Tip {
    LINUX,
    UNIX,
    WINDOWS,
};

class OperativenSistem {
    char *ime;
    double verzija;
    Tip tipovi;
    double golemina;

    void copy(const OperativenSistem &o) {
        this->ime = new char[strlen(o.ime) + 1];
        strcpy(this->ime, o.ime);
        this->tipovi = o.tipovi;
        this->verzija = o.verzija;
        this->golemina = o.golemina;
    }

public:
    OperativenSistem() {
        this->ime = new char[1];
        strcpy(this->ime, "");
        this->verzija = 0;
        this->tipovi = (Tip) 0;
        this->golemina = 0;
    }

    OperativenSistem(char *ime, double verzija, Tip tip, double golemina) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->tipovi = tip;
        this->verzija = verzija;
        this->golemina = golemina;
    }

    OperativenSistem(const OperativenSistem &o) {
        copy(o);
    }

    OperativenSistem &operator=(const OperativenSistem &o) {
        if (this != &o) {
            delete[] ime;
            copy(o);
        }
        return *this;
    }

    ~OperativenSistem() {
        delete[] ime;
    }

//    Ime: Ubuntu Verzija: 17.04 Tip: 1 Golemina:2.25GB
    void pecati() {
        cout << "Ime: " << ime << " Verzija: " << verzija << " Tip: " << tipovi << " Golemina:" << golemina << "GB"
             << endl;
    }

    bool ednakviSe(const OperativenSistem &os) {
        if (strcmp(this->ime, os.ime) == 0 && this->verzija == os.verzija && this->tipovi == os.tipovi
            && this->golemina == os.golemina) {
            return true;
        }
        return false;
    }

    int sporediVerzija(const OperativenSistem &os) {
        if (this->verzija == os.verzija) {
            return 0;
        } else if (this->verzija < os.verzija) {
            return -1;
        } else {
            return 1;
        }
    }

    bool istaFamilija(const OperativenSistem &sporedba) {
        if (strcmp(this->ime, sporedba.ime) == 0 && this->tipovi == sporedba.tipovi) {
            return true;
        }
        return false;
    }
};

class Repozitorium {
    char ime[20];
    OperativenSistem *sistemi;
    int broj;

public:
    Repozitorium(char *ime) {
        strcpy(this->ime, ime);
        this->broj = 0;
        this->sistemi = new OperativenSistem[1];
    }

    ~Repozitorium() {
        delete[] sistemi;
    }

    void pecatiOperativniSistemi() {
        cout << "Repozitorium: " << ime << endl;
        for (int i = 0; i < broj; i++) {
            sistemi[i].pecati();
        }
    }

    void izbrishi(const OperativenSistem &os) {
        int brojac = 0;
        OperativenSistem *tmp = new OperativenSistem[broj];
        for (int i = 0; i < broj; i++) {
            if (sistemi[i].ednakviSe(os)) {
                continue;
            } else {
                tmp[brojac++] = sistemi[i];
            }
        }
        if (brojac < broj) {
            delete[] sistemi;
            sistemi = tmp;
            broj = brojac;
        }
    }

    void dodadi(const OperativenSistem &os) {
        OperativenSistem *tmp = new OperativenSistem[broj + 1];
        bool flag = true;
        for (int i = 0; i < broj; i++) {
            tmp[i] = sistemi[i];
            if (sistemi[i].istaFamilija(os)) {
                if (sistemi[i].sporediVerzija(os) == -1) {
                    tmp[i] = os;
                    flag = false;
                }
            }
        }
        if (flag) {
            tmp[broj++] = os;
            delete[] sistemi;
            sistemi = tmp;
        } else {
            delete [] sistemi;
            sistemi = tmp;
        }
    }
};

int main() {
    char repoName[20];
    cin >> repoName;
    Repozitorium repozitorium = Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin >> brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i < brojOperativniSistemi; i++) {
        cin >> ime;
        cin >> verzija;
        cin >> tip;
        cin >> golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
    cin >> ime;
    cin >> verzija;
    cin >> tip;
    cin >> golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
    cout << "=====Brishenje na operativen sistem=====" << endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}
