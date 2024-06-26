#include <iostream>
using namespace std;
//Да се креира класа PositiveIntegers во која што ќе се чуваат информации за:
//
// низа од позитивни броеви (>0) (динамички алоцирана низа од цели броеви)
// број на елементи во низата
// максимален капацитет на низата
// За класата да се имплементираат:
//
// потребниот конструктор (погледнете во главната функција како се креира објект од оваа класа)
// метод void increaseCapacity(int c) којшто го зголемува максималниот капацитет на низата за бројот с
// оператор за додавање на нов број во низата од позитивни броеви +=
// број се додава ако и само ако
// оператор за множење * за множење на низата со друг цел број
// Пример, низата има објекти (1 2 3 4 5) и истата се множи со 2, резултатот ќе биде (1 2 3 4 5)*2 = (2 3 6 8 10)
// оператор за делење \ за делење на низата до друг цел број
// потребно е секој елемент од низата да биде делив со тој број, како и делителот не смее да биде нула.
// оператор [] за пристап до елемент од низата
// Потребно е да се дефинираат класи за исклучоци и секој од нив да има метод void message() којшто ќе принта соодветна
// порака кога исклучокот ќе биде фатен. Можните исклучоци се следните:
//
// ArithmeticException (се фрла ако се проба да се дели со нула)
// принта порака Division by zero is not allowed
// NumbersNotDivisibleException (се фрла ако се проба да се дели низата со некој број, а барем еден елемент од низата
// не е делив со тој број)
// принта порака Division by number [делителот] is not supported
// ArrayFullException (се фрла ако се проба да се додади елемент во низа која и е исполнет максималниот капацитет)
// принта порака The array is full. Increase the capacity
// IndexOutOfBoundsException (се фрла доколку се проба да се пристапи до елемент од низата со несоодветен индекс)
// принта порака Index [индексот] is out of bounds
// NumberIsNotPositiveException (се фрла доколку се проба да се внесе во низата број што не е позитивен или е нула)
// принта порака Number [бројот] is not positive integer.
int main() {
    int n, capacity;
    cin >> n >> capacity;
    PositiveIntegers pi(capacity);
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        pi += number;
    }
    cout << "===FIRST ATTEMPT TO ADD NUMBERS===" << endl;
    pi.print();
    int incCapacity;
    cin >> incCapacity;
    pi.increaseCapacity(incCapacity);
    cout << "===INCREASING CAPACITY===" << endl;
    pi.print();

    int n1;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        int number;
        cin >> number;
        pi += number;
    }
    cout << "===SECOND ATTEMPT TO ADD NUMBERS===" << endl;

    pi.print();
    PositiveIntegers pi1;

    cout << "===TESTING DIVISION===" << endl;

    pi1 = pi / 0;
    pi1.print();

    pi1 = pi / 1;
    pi1.print();

    pi1 = pi / 2;
    pi1.print();

    cout << "===TESTING MULTIPLICATION===" << endl;
    pi1 = pi * 3;
    pi1.print();


    cout << "===TESTING [] ===" << endl;
    cout << "PositiveIntegers[-1] = " << pi[-1] << endl;
    cout << "PositiveIntegers[2] = " << pi[2] << endl;
    cout << "PositiveIntegers[3] = " << pi[3] << endl;
    cout << "PositiveIntegers[12] = " << pi[12] << endl;


    return 0;
}

//Input
// 6
// 3
// 1
// -10
// 0
// 2
// 3
// 4
// 3
// 5
// 0
// -5
// 1
// -2
// 3
//Output
// Number -10 is not positive integer
// Number 0 is not positive integer
// The array is full. Increase the capacity
// ===FIRST ATTEMPT TO ADD NUMBERS===
// Size: 3 Capacity: 3 Numbers: 1 2 3
// ===INCREASING CAPACITY===
// Size: 3 Capacity: 6 Numbers: 1 2 3
// Number 0 is not positive integer
// Number -5 is not positive integer
// Number -2 is not positive integer
// ===SECOND ATTEMPT TO ADD NUMBERS===
// Size: 5 Capacity: 6 Numbers: 1 2 3 1 3
// ===TESTING DIVISION===
// Division by zero is not allowed
// Size: 5 Capacity: 6 Numbers: 1 2 3 1 3
// Division by 2 is not supported
// ===TESTING MULTIPLICATION===
// Size: 5 Capacity: 6 Numbers: 3 6 9 3 9
// ===TESTING [] ===
// PositiveIntegers[-1] = Index -1 is out of bounds
// PositiveIntegers[2] = 3
// PositiveIntegers[3] = 1
// PositiveIntegers[12] = Index 12 is out of bounds
