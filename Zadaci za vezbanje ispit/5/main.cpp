#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;
//
// Да се креира класа Customer за опишување на купувачи на една книжара. За секој купувач се чуваат податоци за:
//
// името (низа од 50 знаци),
// електронска адреса (низа од 50 знаци),
// вид на купувач (стандардни, лојални или вип),
// основен попуст (цел број изразен во проценти),
// дополнителен попуст (цел број изразен во проценти) и
// број на купени производи. (5 поени)
// Сите лојални купувачи со покажување на клуб картичка имаат право на основниот попуст при купување од книжарата. Основниот попуст е ист за сите лојални купувачи и изнесува 10%. Оваа вредност може да се смени со одлука на раководството на книжарата. Дополнителниот попуст е фиксен и може да го користат само вип купувачите и изнесува 20%. Стандардните купувачи немаат право на попуст (5 поени).
//
// За оваа класа да се имплементира оператор << за печатење на купувач во формат:
//
// [ime_na_kupuvac]
// [email_na_kupuvac]
// [broj_na_proizvodi]
// [vid_na_kupuvac] [popust_sto_moze_da_go_koristi]
// каде попустот е 0% ако купувачот е стандарден, вредноста на основниот попуст, ако е лојален или збир од основниот и дополнителниот попуст, ако купувачот е вип. (5 поени)
//
// Да се креира класа за онлајн книжара FINKI-bookstore во која се чува низа од регистрирани купувачи (динамички алоцирана низа) и број на купувачи. (5 поени) За класата да се обезбедат:
//
// operator+= (10 поени) за додавање купувач во листата од купувачи, но само ако веќе не е дел од неа (ако во листата нема купувач со иста електронска адреса). Ако во листата постои корисник со иста електронска адреса, треба да се генерира исклучок UserExistsException. Потребно е да се обезбеди справување со исклучокот во функцијата main на означеното место. Во ваква ситуација се печати порака "The user already exists in the list" (5 поени).
// Функција update со која сите стандардни купувачи со купени повеќе од 5 производи стануваат лојални, а сите лојални купувачи со над 10 купени производи, стануваат вип (5 поени).
// Оператор << за печатење на информациите за сите регистрирани купувачи (5 поени).
// Да се обезбедат сите дополнителни методи потребни за правилно функционирање на програмата. (10 поени)

enum typeC {
    standard = 0,
    loyal = 1,
    vip = 2
};

class UserExistsException {
public:
    UserExistsException() {
    }

    void showMessage() {
        cout << "The user already exists in the list!\n";
    }
};


class Customer {
private:
    char ime[50];
    char adresa[50];
    typeC kupuvac;
    static int popust;
    const static int dopPopust;
    int brProizvodi;

public:
    Customer() {
    }

    Customer(char *ime, char *adresa, typeC kupuvac1, int brProizvodi) {
        strcpy(this->ime, ime);
        strcpy(this->adresa, adresa);
        this->kupuvac = kupuvac1;
        this->brProizvodi = brProizvodi;
    }

    Customer(const Customer &c) {
        strcpy(this->ime, c.ime);
        strcpy(this->adresa, c.adresa);
        this->kupuvac = c.kupuvac;
        this->brProizvodi = c.brProizvodi;
    }

    Customer &operator=(const Customer &c) {
        if (this != &c) {
            strcpy(this->ime, c.ime);
            strcpy(this->adresa, c.adresa);
            this->kupuvac = c.kupuvac;
            this->brProizvodi = c.brProizvodi;
        }

        return *this;
    }

    ~Customer() {
    }

    char *getAdresa() {
        return adresa;
    }

    int getProizvodi() {
        return brProizvodi;
    }

    typeC getTip() {
        return kupuvac;
    }

    void setKupuvac(typeC kupuvac) {
        this->kupuvac = kupuvac;
    }

    int popustSporedTip() {
        if (kupuvac == 0) {
            return 0;
        } else if (kupuvac == 1) {
            return popust;
        }
        return popust + dopPopust;
    }


    friend ostream &operator<<(ostream &os, Customer &customer) {
        os << customer.ime << endl;
        os << customer.adresa << endl;
        os << customer.brProizvodi << endl;
        if (customer.kupuvac == standard) {
            os << "standard ";
        } else if (customer.kupuvac == loyal) {
            os << "loyal ";
        } else {
            os << "vip ";
        }
        os << customer.popustSporedTip() << endl;
    }

    static void setDiscount1(int osnoven) {
        popust = osnoven;
    }
};

int Customer::popust = 10;
const int Customer::dopPopust = 20;


class FINKI_bookstore {
private:
    Customer *customers;
    int numCustomers;

public:
    FINKI_bookstore() {
        customers = new Customer[0];
        numCustomers = 0;
    }

    FINKI_bookstore(Customer *customers, int numCustomers) {
        this->numCustomers = numCustomers;
        this->customers = new Customer[numCustomers];
        for (int i = 0; i < numCustomers; i++) {
            this->customers[i] = customers[i];
        }
    }

    FINKI_bookstore(const FINKI_bookstore &fb) {
        this->numCustomers = fb.numCustomers;
        this->customers = new Customer[numCustomers];
        for (int i = 0; i < numCustomers; i++) {
            this->customers[i] = fb.customers[i];
        }
    }

    FINKI_bookstore operator=(const FINKI_bookstore &fb) {
        if (this != &fb) {
            delete[] customers;
            this->numCustomers = fb.numCustomers;
            this->customers = new Customer[numCustomers];
            for (int i = 0; i < numCustomers; i++) {
                this->customers[i] = fb.customers[i];
            }
        }

        return *this;
    }

    ~FINKI_bookstore() {
        delete[] customers;
    }

    void setCustomers(Customer *customers, int numCustomers) {
        this->numCustomers = numCustomers;
        this->customers = new Customer[numCustomers];
        for (int i = 0; i < numCustomers; i++) {
            this->customers[i] = customers[i];
        }
    }

    FINKI_bookstore &operator+=(Customer &nov) {
        for (int i = 0; i < numCustomers; i++) {
            if (strcmp(customers[i].getAdresa(), nov.getAdresa()) == 0) {
                throw UserExistsException();
            }
        }

        Customer *tmp = new Customer[numCustomers + 1];
        for (int i = 0; i < numCustomers; i++) {
            tmp[i] = customers[i];
        }

        tmp[numCustomers] = nov;
        delete[] customers;
        numCustomers++;
        customers = new Customer[numCustomers];
        for (int i = 0; i < numCustomers; i++) {
            customers[i] = tmp[i];
        }

        return *this;
    }

    void update() {
        for (int i = 0; i < numCustomers; i++) {
            if (customers[i].getTip() == standard && customers[i].getProizvodi() > 5) {
                customers[i].setKupuvac(loyal);
            } else if (customers[i].getTip() == loyal && customers[i].getProizvodi() > 10) {
                customers[i].setKupuvac(vip);
            }
        }
    }

    friend ostream &operator<<(ostream &out, FINKI_bookstore &fb) {
        for (int i = 0; i < fb.numCustomers; i++) {
            out << fb.customers[i];
        }
        return out;
    }
};

int main() {
    int testCase;
    cin >> testCase;

    char name[MAX];
    char email[MAX];
    int tC;
    int discount;
    int numProducts;


    if (testCase == 1) {
        cout << "===== Test Case - Customer Class ======" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;
    }

    if (testCase == 2) {
        cout << "===== Test Case - Static Members ======" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

        c.setDiscount1(5);

        cout << c;
    }

    if (testCase == 3) {
        cout << "===== Test Case - FINKI-bookstore ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << fc << endl;
    }

    if (testCase == 4) {
        cout << "===== Test Case - operator+= ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);
        fc += c;

        cout << fc;
    }

    if (testCase == 5) {
        cout << "===== Test Case - operator+= (exception) ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);
        try {
            fc += c;
        } catch (UserExistsException &ex) {
            ex.showMessage();
        }


        cout << fc;
    }

    if (testCase == 6) {
        cout << "===== Test Case - update method  ======" << endl << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << "Update:" << endl;
        fc.update();
        cout << fc;
    }
    return 0;
}
