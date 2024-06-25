#include <iostream>

using namespace std;

//Да се дефинира класа Vozilo која ќе содржи информација за неговата маса (децимален број), ширина и висина (цели броеви).
//
// Од оваа класа да се изведе класата Автомобил во која како дополнителна информација се чува информацијата за бројот на врати (цел број).
//
// Од класата возило да се изведе и класата Автобус во која се чуваат информации и за бројот на патници кои може да ги пренесува.

//
// Од класата возило да се изведе класата Камион во која се чуваат информации и за максималната маса која може да се товари на него (децимална вредност).

class Vozilo {
protected:
    double masa;
    int sirina;
    int visina;

public:
    Vozilo() {
    }

    Vozilo(double masa, int sirina, int visina) {
        this->masa = masa;
        this->sirina = sirina;
        this->visina = visina;
    }

    Vozilo(const Vozilo &v) {
        masa = v.masa;
        sirina = v.sirina;
        visina = v.visina;
    }

    Vozilo &operator=(const Vozilo &v) {
        if (this != &v) {
            masa = v.masa;
            sirina = v.sirina;
            visina = v.visina;
        }
        return *this;
    }

    ~Vozilo() {
    }

    double getMasa() {
        return masa;
    }

    int getSirina() {
        return sirina;
    }

    virtual int vratiDnevnaCena() = 0;
};

class Avtomobil : public Vozilo {
private:
    int vrati;

public:
    Avtomobil() : Vozilo() {
    }

    Avtomobil(double masa, int sirina, int visina, int vrati) : Vozilo(masa, sirina, visina) {
        this->vrati = vrati;
    }

    Avtomobil(const Avtomobil &a) : Vozilo(a) {
        vrati = a.vrati;
    }

    Avtomobil &operator=(const Avtomobil &a) {
        if (this != &a) {
            masa = a.masa;
            sirina = a.sirina;
            visina = a.visina;
            vrati = a.vrati;
        }
        return *this;
    }

    ~Avtomobil() {
    }

    //    За секој автомобил со помалку од 5 врати дневната цена е 100, а инаку е 130 денари.
    int vratiDnevnaCena() {
        if (vrati < 5) {
            return 100;
        }
        return 130;
    }
};

class Avtobus : public Vozilo {
private:
    int patnici;

public:
    Avtobus() : Vozilo() {
    }

    Avtobus(double masa, int sirina, int visina, int patnici) : Vozilo(masa, sirina, visina) {
        this->patnici = patnici;
    }

    Avtobus(const Avtobus &aa) : Vozilo(aa) {
        patnici = aa.patnici;
    }

    Avtobus &operator=(const Avtobus &aa) {
        if (this != &aa) {
            masa = aa.masa;
            sirina = aa.sirina;
            visina = aa.visina;
            patnici = aa.patnici;
        }
        return *this;
    }

    ~Avtobus() {
    }

    //    За секој автобус цената е 5 денари по лице кое може да се пренесува.
    int vratiDnevnaCena() {
        return patnici * 5;
    }
};

class Kamion : public Vozilo {
private:
    double nosivost;

public:
    Kamion() : Vozilo() {
    }

    Kamion(double masa, int sirina, int visina, double nosivost) : Vozilo(masa, sirina, visina) {
        this->nosivost = nosivost;
    }

    Kamion(const Kamion &k) : Vozilo(k) {
        this->nosivost = k.nosivost;
    }

    Kamion &operator=(const Kamion &k) {
        if (this != &k) {
            masa = k.masa;
            sirina = k.sirina;
            visina = k.visina;
            nosivost = k.nosivost;
        }
        return *this;
    }

    ~Kamion() {
    }

    double getNosivost() {
        return nosivost;
    }

    int vratiDnevnaCena() {
        return (masa + nosivost) * 0.02;
    }
};

class ParkingPlac {
private:
    Vozilo **vozilo;
    int n;

public:
    ParkingPlac() {
        vozilo = new Vozilo *[0];
        n = 0;
    }

    ~ParkingPlac() {
        delete[]vozilo;
    }

    ParkingPlac &operator+=(Vozilo *v) {
        Vozilo **tmp = new Vozilo *[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = vozilo[i];
        }
        tmp[n++] = v;
        delete[]vozilo;
        vozilo = tmp;
        return *this;
    }

    float presmetajVkupnaMasa() {
        float sum = 0.0;
        for (int i = 0; i < n; i++) {
            sum += vozilo[i]->getMasa();
        }
        return sum;
    }

    int brojVozilaPoshirokiOd(int l) {
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (vozilo[i]->getSirina() > l) {
                count++;
            }
        }
        return count;
    }

    int vratiDnevnaZarabotka() {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += vozilo[i]->vratiDnevnaCena();
        }
        return sum;
    }

    // функција int pogolemaNosivostOd(Vozilo& v) во која се враќа бројот на сите камиони кои имаат носивост поголема од масата на возилото предадено како аргумент.

    int pogolemaNosivostOd(Vozilo &v) {
        int counter = 0;

        for (int i = 0; i < n; i++) {
            Kamion *ka = dynamic_cast<Kamion *>(vozilo[i]);
            if (ka) {
                if (ka->getNosivost() > v.getMasa()) {
                    ++counter;
                }
            }
        }
        return counter;
    }

    void pecati() {
        int avt = 0, bus = 0, kam = 0;
        for (int i = 0; i < n; i++) {
            Avtomobil *av = dynamic_cast<Avtomobil *>(vozilo[i]);
            if (av) {
                ++avt;
                continue;
            }

            Avtobus *bu = dynamic_cast<Avtobus *>(vozilo[i]);
            if (bu) {
                ++bus;
                continue;
            }

            kam++;
        }
        cout << "Brojot na avtomobili e " << avt << ", brojot na avtobusi e " << bus << " i brojot na kamioni e "
                << kam << "." << endl;
        //        Brojot na avtomobili e X, brojot na avtobusi e Y i brojot na kamioni e Z.
    }
};

//
// За сите класи да се креираат погодни контруктори, како и set и get функции.
//
// Да се дефинира класа ParkingPlac за која се чува динамичко алоцирано поле од покажувачи кон Vozilo, како и бројот на елементи во полето.
// Во оваа класа да се дефинираат:
//
// конструктор
// деструктор
// операторот += за додавање на ново возило (аргументот е покажувач кон Vozilo)
// функција float presmetajVkupnaMasa() со која се пресметува вкупната маса на сите возила во паркинг плацот
// функција int brojVozilaPoshirokiOd(int l) со која се пресметува бројот на возила кои се пошироки од дадената вредност
// функција void pecati() со која се печати: Brojot na avtomobili e X, brojot na avtobusi e Y i brojot na kamioni e Z.
// функција int pogolemaNosivostOd(Vozilo& v) во која се враќа бројот на сите камиони кои имаат носивост поголема од масата на возилото предадено како аргумент.
// Да се дефинира виртуелна функција int vratiDnevnaCena() во класата Vozilo и истата да се преоптовари во сите изведени класи.
// За секој автомобил со помалку од 5 врати дневната цена е 100, а инаку е 130 денари. За секој камион цената се пресметува со формулата:
// (masa+nosivost)*0.02. За секој автобус цената е 5 денари по лице кое може да се пренесува.
//
// Во класата ParkingPlac да се додаде следната функција: - функција int vratiDnevnaZarabotka() со која се враќа дневната заработка од сите возила на паркингот.
int main() {
    ParkingPlac p;

    int n;
    cin >> n;
    int shirina, visina, broj;
    float masa, nosivost;
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            cin >> masa >> shirina >> visina >> broj;
            Avtomobil *a = new Avtomobil(masa, shirina, visina, broj);
            p += a;
        }
        if (type == 2) {
            cin >> masa >> shirina >> visina >> broj;
            p += new Avtobus(masa, shirina, visina, broj);
        }
        if (type == 3) {
            cin >> masa >> shirina >> visina >> nosivost;
            p += new Kamion(masa, shirina, visina, nosivost);
        }
    }

    p.pecati();

    cout << "\nZarabotkata e " << p.vratiDnevnaZarabotka() << endl;
    cout << "Vkupnata masa e " << p.presmetajVkupnaMasa() << endl;
    cout << "Brojot poshiroki od 5 e " << p.brojVozilaPoshirokiOd(5) << endl;
    Avtomobil a(1200, 4, 3, 5);
    cout << "Brojot na kamioni so nosivost pogolema od avtomobilot e " << p.pogolemaNosivostOd(a) << endl;
}

//Input
// 5
// 1 1300 3 2 3
// 2 4500 10 4 45
// 3 6000 8 5 2000
// 1 2100 3 3 5
// 2 4200 9 5 52
//Output
// Brojot na avtomobili e 2, brojot na avtobusi e 2 i brojot na kamioni e 1.
// Zarabotkata e 875
// Vkupnata masa e 18100
// Brojot poshiroki od 5 e 3
// Brojot na kamioni so nosivost pogolema od avtomobilot e 1
