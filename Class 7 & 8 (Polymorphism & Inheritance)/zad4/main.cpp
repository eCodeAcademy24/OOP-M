#include <iostream>
#include <cstring>
using namespace std;
//Да се развие класа Nediviznina за коjа се чуваат следниве информации:

// адреса (динамички алоцирана низа од знаци)
// квадратура (цел боj)
// цена за квадрат (цел боj)
// За оваа класа да се имплементираат соодветните конструктори и следните методи:
//
// cena() коj ќе jа враќа цената на недвижнината (квадратура * цена-за-квадрат)
// pecati() коj ќе ги испечати сите информации за истата
// danokNaImot() коj го ваќа данокот што се плаќа за недвижнината, а истиот се пресметува како 5% од цената на недвижнината.
// Од оваа класа да се изведе класа Vila за коjа дополнително се чува данок на луксуз (цел боj, пр. 10%).
// За оваа класа да се преоптоварат методите:
//
// pecati()
// danokNaImot() со тоа што пресметаниот данок се зголемува процентуално за данокот на луксуз.
// И за двете класи треба да се преоптовари operator >>.

//Input
//Kukja_vo_Centar
// 60
// 850
// Vila_na_Vodno
// 110
// 1120
// 10
//Output
//Kukja_vo_Centar, Kvadratura: 60, Cena po Kvadrat: 850
// Danok za: Kukja_vo_Centar, e: 2550
// Vila_na_Vodno, Kvadratura: 110, Cena po Kvadrat: 1120, Danok na luksuz: 10
// Danok za: Vila_na_Vodno, e: 18480

class Nedviznina {
protected:
    char *adresa;
    int kvadratura;
    int cenaKvad;

public:
    Nedviznina() {
        adresa = new char[0];
        kvadratura = 0;
        cenaKvad = 0;
    }

    Nedviznina(char *adresa, int kvadratura, int cenaKvad) {
        this->adresa = new char[strlen(adresa) + 1];
        strcpy(this->adresa, adresa);
        this->kvadratura = kvadratura;
        this->cenaKvad = cenaKvad;
    }

    Nedviznina(const Nedviznina &n) {
        this->adresa = new char[strlen(n.adresa) + 1];
        strcpy(this->adresa, n.adresa);
        this->kvadratura = n.kvadratura;
        this->cenaKvad = n.cenaKvad;
    }

    Nedviznina &operator=(const Nedviznina &n) {
        if (this != &n) {
            delete[]adresa;
            this->adresa = new char[strlen(n.adresa) + 1];
            strcpy(this->adresa, n.adresa);
            this->kvadratura = n.kvadratura;
            this->cenaKvad = n.cenaKvad;
        }
        return *this;
    }

    ~Nedviznina() {
        delete[]adresa;
    }

    int cena() {
        return kvadratura * cenaKvad;
    }

    char *getAdresa() {
        return adresa;
    }

    // /Kukja_vo_Centar, Kvadratura: 60, Cena po Kvadrat: 850
    void pecati() {
        cout << adresa << " Kvadratura: " << kvadratura << ", Cena po Kvadrat: " << cenaKvad << endl;
    }

    double danokNaImot() {
        return (cena() * 0.05);
    }

    friend istream &operator>>(istream &in, Nedviznina &n) {
        in >> n.adresa >> n.kvadratura >> n.cenaKvad;
        return in;
    }
};

class Vila : public Nedviznina {
private:
    int broj;
public:
    Vila() : Nedviznina() {
    }

    Vila(char *adresa, int kvadratura, int cenaKvad, int broj) : Nedviznina(adresa, kvadratura, cenaKvad) {
        this->broj = broj;
    }

    Vila(const Vila &v) : Nedviznina(v) {
        broj = v.broj;
    }

    Vila &operator=(const Vila &n) {
        if (this != &n) {
            delete[]adresa;
            this->adresa = new char[strlen(n.adresa) + 1];
            strcpy(this->adresa, n.adresa);
            this->kvadratura = n.kvadratura;
            this->cenaKvad = n.cenaKvad;
            this->broj = n.broj;
        }
        return *this;
    }

    ~Vila() {
    }

    void pecati() {
        cout << adresa << " Kvadratura: " << kvadratura << ", Cena po Kvadrat: " << cenaKvad << ", Danok na luksuz: "
                << broj << endl;
    }

    // danokNaImot() со тоа што пресметаниот данок се зголемува процентуално за данокот на луксуз.
    double danokNaImot() {
        double danok = Nedviznina::danokNaImot();
        double novDanok = ((double) broj * cena()) / 100;
        return danok + novDanok;
    }

    friend istream &operator>>(istream &in, Vila &v) {
        in >> v.adresa >> v.kvadratura >> v.cenaKvad >> v.broj;
        return in;
    }
};


int main() {
    Nedviznina n;
    Vila v;
    cin >> n;
    cin >> v;
    n.pecati();
    cout << "Danok za: " << n.getAdresa() << ", e: " << n.danokNaImot() << endl;
    v.pecati();
    cout << "Danok za: " << v.getAdresa() << ", e: " << v.danokNaImot() << endl;
    return 0;
}
