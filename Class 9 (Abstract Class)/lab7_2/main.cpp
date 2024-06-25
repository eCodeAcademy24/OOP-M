#include <iostream>
using namespace std;

//Да се дефинира апстрктна класа Number со следните чисто виртуелни методи:
//
// double doubleValue() -ја враќа децималната вредност на даден број
// int intValue()- ја враќа целобројната вредност на даден број
// void print() - печати информации за бројот. (1 поен)
// Од оваа класа да се изведат две класи:
//
// Integer (во која што се чува еден број од тип int)
// Double (во која што се чува еден број од тип double) (1 поен).
// За двете изведени класи да се имплементираaт соодветен конструктори, како и да се препокријат
// методите од основната класа. (1 поени)
//
// Да се преоптовари операторот == којшто ќе споредува два броеви според нивната вредност
// (објекти од класа Number) (1 поен)
//
// Дополнително да се дефинира класа Numbers во која што ќе се чуваат:
//
// динамички алоцирана низа од покажувачи кон објекти од класата Number
// број на елементи во низата од покажувачи
// За класата да се имплементира соодветен конструктор (default) , како и: (1 поени)
//
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
//Input
// 2
// 0
// 10
// 1
// 15.5
// 11
// 10.0
//Output
//STATISTICS FOR THE NUMBERS
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
//STATISTICS FOR THE NUMBERS
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
int main()
{

    int n;
    cin>>n;
    Numbers numbers;
    for (int i=0; i<n; i++)
    {
        int type;
        double number;
        cin>>type>>number;
        if (type==0) //Integer object
        {
            Integer * integer = new Integer((int) number);
            numbers+=integer;
        }
        else
        {
            Double * doublee = new Double(number);
            numbers+=doublee;
        }
    }

    int lessThan;
    double biggerThan;

    cin>>lessThan;
    cin>>biggerThan;

    cout<<"STATISTICS FOR THE NUMBERS\n";
    numbers.statistics();
    cout<<"INTEGER NUMBERS LESS THAN "<<lessThan<<endl;
    numbers.integersLessThan(Integer(lessThan));
    cout<<"DOUBLE NUMBERS BIGGER THAN "<<biggerThan<<endl;
    numbers.doublesBiggerThan(Double(biggerThan));

    return 0;
}
