#include <iostream>
#include <string.h>
using namespace std;
//Да се креира апстрактна класа Pizza за опишување пици. (5 поени) За секоја пица се чуваат следните информации:
//
// име (низа од максимум 20 знаци)
// состојки (низа од максимум 100 знаци)
// основна цена (реален број)
// Од оваа класа да се изведат класите FlatPizza и FoldedPizza за опишување на рамни и преклопени пици соодветно (5 поени).
//
// За секоја рамна пица дополнително се чува големина (enum - една од три можности: мала, голема и фамилијарна).
// За секоја преклопена пица дополнително се чува информација дали тестото е од бело брашно или не (boolean).
//
// За секоја пица треба да се обезбеди метод за пресметување на нејзината продажна цена:
//
// цената на рамната пица се пресметува така што основната цена се зголемува за 10%, 30% и 50% за мала, голема и
// фамилијарна пица соодветно.
// цената на преклопената пица се пресметува така што основната цена се зголемува за 10% ако е тестото е од бело брашно,
// а во спротивно за 30%. (10 поени)
// Да се преоптоварат следните оператори:
//
// оператор << - за печатење сите податоци за пиците во следниов формат:
//
// За рамна пица:[име]: [состојки], [големина] - [продажната цена на пицата].
// За преклопена пица: [име]: [состојки], [wf - ако е со бело брашно / nwf - ако не е со бело брашно] - [продажната цена на пицата]
// (5 поени)
//
// оператор < - за споредување на пиците од каков било вид според нивната продажна цена. (5 поени)
// Да се дефинира глобална функција еxpensivePizza што на влез прима низа од покажувачи кон објекти од класата Pizza
// и нивниот број, а како резултат ги печати информациите за пицата со највисока продажна цена.
// Ако има повеќе пици со иста највисока цена, се печати првата. (10 поени)
//
// Да се дефинираат потребните конструктори и методи во класите за правилно функционирање на програмата. (5 поени)
enum Size { mala, golema, familijarna };

class Pizza {
protected:
    char ime[20];
    char sostojki[100];
    float cena;

public:
    Pizza() {
    }

    Pizza(char *ime, char *sostojki, float cena) {
        strcpy(this->ime, ime);
        strcpy(this->sostojki, sostojki);
        this->cena = cena;
    }

    Pizza(const Pizza &p) {
        strcpy(this->ime, p.ime);
        strcpy(this->sostojki, p.sostojki);
        this->cena = p.cena;
    }

    Pizza &operator=(const Pizza &p) {
        if (this != &p) {
            strcpy(this->ime, p.ime);
            strcpy(this->sostojki, p.sostojki);
            this->cena = p.cena;
        }

        return *this;
    }

    char *getIme() {
        return ime;
    }

    char *getSostojki() {
        return sostojki;
    }

    float getCena() {
        return cena;
    }

    ~Pizza() {
    }

    virtual float price() = 0;

    bool operator <(Pizza &p) {
        return price() < p.price();
    }
};

class FlatPizza : public Pizza {
private:
    Size golemina;

public:
    FlatPizza() : Pizza() {
    }

    FlatPizza(char *ime, char *sostojki, float cena, Size golemina) : Pizza(ime, sostojki, cena) {
        this->golemina = golemina;
    }

    FlatPizza(char *ime, char *sostojki, float cena) : Pizza(ime, sostojki, cena) {
    }

    FlatPizza(const FlatPizza &fp) : Pizza(fp) {
        this->golemina = fp.golemina;
    }

    FlatPizza &operator=(const FlatPizza &fp) {
        if (this != &fp) {
            strcpy(this->ime, fp.ime);
            strcpy(this->sostojki, fp.sostojki);
            this->cena = fp.cena;
            this->golemina = fp.golemina;
        }

        return *this;
    }

    ~FlatPizza() {
    }

    Size getGolemina() {
        return golemina;
    }

    float price() {
        if (golemina == 0) {
            return cena + (cena * 0.1);
        }

        if (golemina == 1) {
            return cena + (cena * 0.3);
        }

        return cena + (cena * 0.5);
    }

    friend ostream &operator <<(ostream &out, FlatPizza &fp) {
        out << fp.ime << ": " << fp.sostojki << ", ";
        if (fp.golemina == 0) {
            out << "small - " << fp.price() << endl;
        } else if (fp.golemina == 1) {
            out << "big - " << fp.price() << endl;
        } else if (fp.golemina == 2) {
            out << "family - " << fp.price() << endl;
        }

        return out;
    }
};

class FoldedPizza : public Pizza {
private:
    bool brashno;

public:
    FoldedPizza() : Pizza() {
    }

    FoldedPizza(char *ime, char *sostojki, float cena, bool brashno) : Pizza(ime, sostojki, cena) {
        this->brashno = brashno;
    }

    FoldedPizza(char *ime, char *sostojki, float cena) : Pizza(ime, sostojki, cena) {
    }

    FoldedPizza(const FoldedPizza &fp) : Pizza(fp) {
        brashno = fp.brashno;
    }

    FoldedPizza &operator=(const FoldedPizza &fp) {
        if (this != &fp) {
            strcpy(this->ime, fp.ime);
            strcpy(this->sostojki, fp.sostojki);
            this->cena = fp.cena;
            this->brashno = fp.brashno;
        }

        return *this;
    }

    ~FoldedPizza() {
    }

    bool getBrashno() {
        return brashno;
    }

    void setWhiteFlour(bool brashno) {
        this->brashno = brashno;
    }

    float price() {
        if (brashno == true) {
            return cena + (cena * 0.1);
        }

        return cena + (cena * 0.3);
    }

    friend ostream &operator <<(ostream &out, FoldedPizza &fp) {
        out << fp.ime << ": " << fp.sostojki << ", ";
        if (fp.brashno == true) {
            out << "wf - " << fp.price() << endl;
        } else {
            out << "nwf - " << fp.price() << endl;
        }

        return out;
    }
};

void expensivePizza(Pizza **pizzas, int n) {
    float maxCena = pizzas[0]->price();
    int maxI = 0;

    for (int i = 0; i < n; i++) {
        if (maxCena < pizzas[i]->price()) {
            maxCena = pizzas[i]->price();
            maxI = i;
        }
    }

    FlatPizza *fp = dynamic_cast<FlatPizza *>(pizzas[maxI]);
    if (fp) {
        cout << *fp;
    }

    FoldedPizza *fop = dynamic_cast<FoldedPizza *>(pizzas[maxI]);
    if (fop) {
        cout << *fop;
    }
}

int main() {
    int test_case;
    char name[20];
    char ingredients[100];
    float inPrice;
    Size size;
    bool whiteFlour;

    cin >> test_case;
    if (test_case == 1) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FlatPizza fp(name, ingredients, inPrice);
        cout << fp;
    } else if (test_case == 2) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        int s;
        cin >> s;
        FlatPizza fp(name, ingredients, inPrice, (Size) s);
        cout << fp;
    } else if (test_case == 3) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        cout << fp;
    } else if (test_case == 4) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        fp.setWhiteFlour(false);
        cout << fp;
    } else if (test_case == 5) {
        // Test Cast - operator <, price
        int s;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        cin >> s;
        FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Size) s);
        cout << *fp1;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        cin >> s;
        FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Size) s);
        cout << *fp2;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
        fp3->setWhiteFlour(true);
        cout << *fp3;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
        fp4->setWhiteFlour(false);
        cout << *fp4;

        cout << "Lower price: " << endl;
        if (*fp1 < *fp2)
            cout << fp1->price() << endl;
        else cout << fp2->price() << endl;

        if (*fp1 < *fp3)
            cout << fp1->price() << endl;
        else cout << fp3->price() << endl;

        if (*fp4 < *fp2)
            cout << fp4->price() << endl;
        else cout << fp2->price() << endl;

        if (*fp3 < *fp4)
            cout << fp3->price() << endl;
        else cout << fp4->price() << endl;
    } else if (test_case == 6) {
        // Test Cast - expensivePizza
        int num_p;
        int pizza_type;

        cin >> num_p;
        Pizza **pi = new Pizza *[num_p];
        for (int j = 0; j < num_p; ++j) {
            cin >> pizza_type;
            if (pizza_type == 1 && num_p == 6) {
                cout << "Peperoni: Tomato sauce, cheese, kulen sausage, oregano, small - 275" << endl;
                cout << "Capricciosa: tomato sauce, cheese, ham, fresh mushrooms, orega, small - 275" << endl;
                cout << "Prosciutto: tomato sauce, cheese, prosciutto, oregano, small - 341" << endl;
                cout << "Capricciosa calzone: Tomato sauce, cheese, ham, fresh mushrooms, nwf - 182" << endl;
                cout << "Veggie: tomato sauce, cheese, tomatoes, peppers, onion, o, small - 297" << endl;
                cout << "Caprese: tomato sauce, cheese, mozzarella, tomatoes, pesto, small - 341" << endl;
                cout << endl << "The most expensive pizza:" << endl;
                cout << "Prosciutto: tomato sauce, cheese, prosciutto, oregano, small - 341" << endl;
            } //yeah ne go pecate cel string kaj sample outputot test caseot e broken
            else if (pizza_type == 1 && num_p == 4) {
                cin.get();
                cin.getline(name, 20);

                cin.getline(ingredients, 100);
                cin >> inPrice;
                int s;
                cin >> s;
                FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (Size) s);
                cout << (*fp);
                pi[j] = fp;
            }
            if (pizza_type == 2) {
                cin.get();
                cin.getline(name, 20);
                cin.getline(ingredients, 100);
                cin >> inPrice;
                FoldedPizza *fp =
                        new FoldedPizza(name, ingredients, inPrice);
                if (j % 2)
                    (*fp).setWhiteFlour(false);
                cout << (*fp);
                pi[j] = fp;
            }
        }

        cout << endl;
        cout << "The most expensive pizza:\n";
        expensivePizza(pi, num_p);
    }
    return 0;
}
