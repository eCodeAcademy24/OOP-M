#include <iostream>
using namespace std;

//Да се дефинира апстрктна класа Number со следните чисто виртуелни методи:
//
// double doubleValue() - ја враќа децималната вредност на даден број
// int intValue()- ја враќа целобројната вредност на даден број
// void print() - печати информации за бројот. (1 поен)

class Number {
public:
    virtual double doubleValue() = 0;

    virtual int intValue() = 0;

    virtual void print() = 0;
};

// Од оваа класа да се изведат две класи:
//
// Integer (во која што се чува еден број од тип int)
// Double (во која што се чува еден број од тип double) (1 поен).
// За двете изведени класи да се имплементираaт соодветни конструктори, како и да се препокријат
// методите од основната класа. (1 поени)
class Integer : public Number {
private:
    int brojInt;

public:
    Integer(int brojInt) {
        this->brojInt = brojInt;
    }

    double doubleValue() {
        return brojInt; // (double) brojInt
    }

    int intValue() {
        return brojInt;
    }

    void print() {
        cout << "Integer: " << brojInt << endl;
    }
};

class Double : public Number {
private:
    double brojDouble;

public:
    Double(double brojDouble) {
        this->brojDouble = brojDouble;
    }

    double doubleValue() {
        return brojDouble;
    }

    int intValue() {
        return brojDouble; //(int) brojDouble;
    }

    void print() {
        cout << "Double: " << brojDouble << endl;
    }
};

// Да се преоптовари операторот == којшто ќе споредува два броеви според нивната вредност
// (објекти од класа Number) (1 поен)
bool operator==(Number &n1, Number &n2) {
    return n1.doubleValue() == n2.doubleValue();
}

// Дополнително да се дефинира класа Numbers во која што ќе се чуваат:
//
// динамички алоцирана низа од покажувачи кон објекти од класата Number
// број на елементи во низата од покажувачи
// За класата да се имплементира соодветен конструктор (default), како и: (1 поени)
// операторот += за додавање на броеви во низата од броеви (1 поен)
// Бројот се додава ако и само ако сите броеви што се веќе додадени во низата се различни од него
// функција void statistics() која што печати информации за броевите во низата: (2 поени)
// Count of numbers: [број на броеви во низата
//
// Sum of all numbers: [сума на сите броеви во низата]
//
// Count of integer numbers: [број на цели броеви (Integer)]
//
// Sum of integer numbers: [сума на сите цели броеви (Integer)]
//
// Count of double numbers: [број на децимални броеви (Double)]
//
// Sum of double numbers: [сума на сите децимални броеви (Double)]
//
// функција void integersLessThan (Integer n) која што ги печати сите цели броеви помали од бројот n (1 поен)
// функција void doublesBiggerThan (Double n) која што ги печати сите децимални броеви поголеми од бројот n (1 поен)

class Numbers {
private:
    Number **numbers;
    int n;

public:
    Numbers() {
        numbers = new Number *[0];
        n = 0;
    }

    Numbers(Number **numbers, int n) {
        // chisto za vezhba
        this->n = n;
        this->numbers = new Number *[n];
        for (int i = 0; i < n; i++) {
            this->numbers[i] = numbers[i];
        }
    }

    //TODO: copy constructor and operator=

    ~Numbers() {
        delete[] numbers;
    }

    // операторот += за додавање на броеви во низата од броеви (1 поен)
    // Бројот се додава ако и само ако сите броеви што се веќе додадени во низата се различни од него
    Numbers &operator+=(Number *nov) {
        Number **tmp = new Number *[n + 1];
        for (int i = 0; i < n; i++) {
            if (*numbers[i] == *nov) {
                delete[] tmp;
                return *this;
            }
            tmp[i] = numbers[i];
        }

        tmp[n] = nov;
        ++n;
        delete[] numbers;
        // numbers = tmp;
        numbers = new Number *[n];
        for (int i = 0; i < n; i++) {
            numbers[i] = tmp[i];
        }

        return *this;
    }

    // функција void integersLessThan (Integer n) која што ги печати сите цели броеви помали од бројот n (1 поен)
    void integersLessThan(Integer broj) {
        bool none = true; // pretpostavuvame deka ne postoi nitu eden

        for (int i = 0; i < n; i++) {
            Integer *k = dynamic_cast<Integer *>(numbers[i]);
            if (k) {
                if (numbers[i]->intValue() < broj.intValue()) {
                    numbers[i]->print();
                    none = false; // pretpostavkata ni e greshna, ima broj shto e pomal od brojot n
                }
            }
        }

        if (none) {
            // pretpostavkata ni bila tochna i flag-ot none ni ostanal na true
            cout << "None" << endl;
        }
    }

    // функција void doublesBiggerThan (Double n) која што ги печати сите децимални броеви поголеми од бројот n (1 поен)
    void doublesBiggerThan(Double broj) {
        bool none = true;

        for (int i = 0; i < n; i++) {
            Double *d = dynamic_cast<Double *>(numbers[i]);
            if (d) {
                if (numbers[i]->doubleValue() > broj.doubleValue()) {
                    numbers[i]->print();
                    none = false;
                }
            }
        }

        if (none) {
            cout << "None" << endl;
        }
    }

    // функција void statistics() која што печати информации за броевите во низата: (2 поени)


    void statistics() {
        double sumDoubles = 0.0;
        int sumIntegers = 0, countIntegers = 0, countDoubles = 0;
        for (int i = 0; i < n; i++) {
            Integer *k = dynamic_cast<Integer *>(numbers[i]);

            if (k) {
                sumIntegers += k->intValue();
                countIntegers++;
                continue;
            }


            Double *d = dynamic_cast<Double *>(numbers[i]);
            if (d) {
                sumDoubles += d->doubleValue();
                countDoubles++;
            }
        }

        // Count of numbers: [број на броеви во низата]
        cout << "Count of numbers: " << n << endl;

        // Sum of all numbers: [сума на сите броеви во низата]
        cout << "Sum of all numbers: " << sumIntegers + sumDoubles << endl;

        // Count of integer numbers: [број на цели броеви (Integer)]
        cout << "Count of integer numbers: " << countIntegers << endl;

        // Sum of integer numbers: [сума на сите цели броеви (Integer)]
        cout << "Sum of integer numbers: " << sumIntegers << endl;

        // Count of double numbers: [број на децимални броеви (Double)]
        cout << "Count of double numbers: " << countDoubles << endl;

        // Sum of double numbers: [сума на сите децимални броеви (Double)]
        cout << "Sum of double numbers: " << sumDoubles << endl;
    }
};


int main() {
    int n;
    cin >> n;
    Numbers numbers;
    for (int i = 0; i < n; i++) {
        int type;
        double number;
        cin >> type >> number;
        if (type == 0) //Integer object
        {
            Integer *integer = new Integer((int) number);
            numbers += integer;
        } else {
            Double *doublee = new Double(number);
            numbers += doublee;
        }
    }

    int lessThan;
    double biggerThan;

    cin >> lessThan;
    cin >> biggerThan;

    cout << "STATISTICS FOR THE NUMBERS\n";
    numbers.statistics();
    cout << "INTEGER NUMBERS LESS THAN " << lessThan << endl;
    numbers.integersLessThan(Integer(lessThan));
    cout << "DOUBLE NUMBERS BIGGER THAN " << biggerThan << endl;
    numbers.doublesBiggerThan(Double(biggerThan));

    return 0;
}

//Input
// 2
// 0
// 10
// 1
// 15.5
// 11
// 10.0
//Output
// STATISTICS FOR THE NUMBERS
// Count of numbers: 2
// Sum of all numbers: 25.5
// Count of integer numbers: 1
// Sum of integer numbers: 10
// Count of double numbers: 1
// Sum of double numbers: 15.5
// INTEGER NUMBERS LESS THAN 11
// Integer: 10
// DOUBLE NUMBERS BIGGER THAN 10
// Double: 15.5

//Input
// 10
// 0 10
// 1 15.55
// 0 7
// 1 78.1
// 0 17
// 1 17.5
// 0 25
// 1 35.55
// 0 -12
// 1 -10.575
// -100
// 3000
//Output
// STATISTICS FOR THE NUMBERS
// Count of numbers: 10
// Sum of all numbers: 183.125
// Count of integer numbers: 5
// Sum of integer numbers: 47
// Count of double numbers: 5
// Sum of double numbers: 136.125
// INTEGER NUMBERS LESS THAN -100
// None
// DOUBLE NUMBERS BIGGER THAN 3000
// None
