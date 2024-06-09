#include <iostream>
using namespace std;
//Да се имплементира класа List во којашто ќе се чуваат информации за:

// броеви што се дел од листата (динамички алоцирана низа од цели броеви)
// бројот на броеви што се дел од листата
// За класата да се дефинираат следните методи:
//
// конструктор (со аргументи), copy-конструктор, деструктор, оператор =
// void pecati()метод што ќе ги печати информациите за листата во форматот:
// [број на елементи во листата]: x1 x2 .. xn sum: [сума] average: [просек]
// int sum() метод што ја враќа сумата на елементите во листата
// double average() метод што ќе го враќа просекот на броевите во листата
class List {
private:
    int *numbers;
    int numElements;

public:
    List() {
        numElements = 0;
        this->numbers = new int[0];
    }

    List(int *numbers, int numElements) {
        this->numElements = numElements;
        this->numbers = new int[numElements];
        for (int i = 0; i < numElements; i++) {
            this->numbers[i] = numbers[i];
        }
    }

    List(const List &l) {
        this->numElements = l.numElements;
        this->numbers = new int[numElements];
        for (int i = 0; i < numElements; i++) {
            this->numbers[i] = l.numbers[i];
        }
    }

    List &operator=(const List &list) {
        if (this != &list) {
            delete[] numbers;
            this->numElements = list.numElements;
            this->numbers = new int[numElements];
            for (int i = 0; i < numElements; i++) {
                this->numbers[i] = list.numbers[i];
            }
        }

        return *this;
    }

    ~List() {
        delete[] numbers;
    }

    int getNumElements() {
        return numElements;
    }

    // int sum() метод што ја враќа сумата на елементите во листата
    int sum() {
        int sum = 0;
        for (int i = 0; i < numElements; i++) {
            sum += numbers[i];
        }

        return sum;
    }

    // double average() метод што ќе го враќа просекот на броевите во листата
    double average() {
        double average = sum() / (double) numElements;
        return average;
        // mozhesh i vo eden red, return sum() / (double) numElements;
    }

    // void pecati()метод што ќе ги печати информациите за листата во форматот:
    // [број на елементи во листата]: x1 x2 .. xn sum: [сума] average: [просек]
    void pecati() {
        cout << numElements << ": ";
        for (int i = 0; i < numElements; i++) {
            cout << numbers[i] << " ";
        }

        cout << "sum: " << sum() << " average: " << average() << endl;
    }
};

// Дополнително, креирајте класата ListContainer, во која што ќе се чуваат информации за:
//
// низа од листи (динамички алоцирана низа од објекти од класата List)
// број на елементи во низата од листи (цел број)
// број на обиди за додавање на листа во контејнерот (цел број првично поставен на нула)
// За класата потребно е да ги дефинирате следните методи:
//
// конструктор (default), copy-конструктор, деструктор, оператор =
// void pecati() метод што ќе ги печати информациите за контејнерот во форматот:
// List number: [реден број на листата] List info: [испечатени информации за листата со методот
// List::pecati()] \n sum: [сума] average: [просек]
// доколку контејнерот е празен се печати само порака The list is empty.
// void addNewList(List l) метод со којшто се додава листа во контејнерот
// Напомена: една листа се додава во контејнерот ако и само ако има различна сума од сите
// листи што се веќе додадени во контејнерот
// int sum() метод што ја враќа сумата на сите елементи во сите листи
// double average() метод што го враќа просекот на сите елементи во сите листи во контејнерот
class ListContainer {
private:
    List *list;
    int numLists;
    int tries;

public:
    ListContainer() {
        numLists = 0;
        list = new List[0];
        tries = 0;
    }

    ListContainer(List *list, int numLists, int tries) {
        this->tries = tries;
        this->numLists = numLists;
        this->list = new List[numLists];
        for (int i = 0; i < numLists; i++) {
            this->list[i] = list[i];
        }
    }

    ListContainer(const ListContainer &lc) {
        this->tries = lc.tries;
        this->numLists = lc.numLists;
        this->list = new List[numLists];
        for (int i = 0; i < numLists; i++) {
            this->list[i] = lc.list[i];
        }
    }

    ListContainer &operator=(const ListContainer &lc) {
        if (this != &lc) {
            delete[] list;
            this->tries = lc.tries;
            this->numLists = lc.numLists;
            this->list = new List[numLists];
            for (int i = 0; i < numLists; i++) {
                this->list[i] = lc.list[i];
            }
        }

        return *this;
    }

    ~ListContainer() {
        delete[] list;
    }


    // int sum() метод што ја враќа сумата на сите елементи во сите листи
    int sum() {
        int sum = 0;
        for (int i = 0; i < numLists; i++) {
            sum += list[i].sum();
        }

        return sum;
    }

    // double average() метод што го враќа просекот на сите елементи во сите листи во контејнерот
    double average() {
        int sumNumElements = 0;
        for (int i = 0; i < numLists; i++) {
            sumNumElements += list[i].getNumElements();
        }

        return sum() / (double) sumNumElements;
    }

    // void addNewList(List l) метод со којшто се додава листа во контејнерот
    // Напомена: една листа се додава во контејнерот ако и само ако има различна сума од сите
    // листи што се веќе додадени во контејнерот
    void addNewList(List l) {
        tries++;
        for (int i = 0; i < numLists; i++) {
            if (list[i].sum() == l.sum()) {
                return;
            }
        }

        List *tmp = new List[numLists + 1];
        for (int i = 0; i < numLists; i++) {
            tmp[i] = list[i];
        }

        tmp[numLists] = l;
        delete[] list;
        ++numLists;

        list = tmp;

        //mozhe i vaka
        // list = new List[numLists];
        //
        // for (int i = 0; i < numLists; i++) {
        //     list[i] = tmp[i];
        // }
    }

    // void pecati() метод што ќе ги печати информациите за контејнерот во форматот:
    // List number: [реден број на листата] List info: [испечатени информации за листата со методот
    // List::pecati()] \n sum: [сума] average: [просек]
    // доколку контејнерот е празен се печати само порака The list is empty.
    void print() {
        if (numLists == 0) {
            cout << "The list is empty" << endl;
        }

        // List number: 1 List info: 5: 1 2 3 4 5 sum: 15 average: 3
        // List number: 2 List info: 3: 1 2 3 sum: 6 average: 2
        // List number: 3 List info: 6: 1 4 5 6 7 10 sum: 33 average: 5.5
        // Sum: 54 Average: 3.85714
        // Successful attempts: 3 Failed attempts: 2
        for (int i = 0; i < numLists; i++) {
            cout << "List number: " << i + 1 << " List info: ";
            list[i].pecati();
        }

        cout << "Sum: " << sum() << " Average: " << average() << endl;
        cout << "Successful attempts: " << numLists << " Failed attempts: " << tries - numLists << endl;
    }
};


//Input
// 5
// 5
// 1 2 3 4 5
// 2
// 10 5
// 3
// 1 2 3
// 6
// 1 4 5 6 7 10
// 3
// 10 10 13
// 0
//Output
// List number: 1 List info: 5: 1 2 3 4 5 sum: 15 average: 3
// List number: 2 List info: 3: 1 2 3 sum: 6 average: 2
// List number: 3 List info: 6: 1 4 5 6 7 10 sum: 33 average: 5.5
// Sum: 54 Average: 3.85714
// Successful attempts: 3 Failed attempts: 2


int main() {
    ListContainer lc;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        int niza[100];

        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> niza[j];
        }

        List l = List(niza, n);

        lc.addNewList(l);
    }


    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "Test case for operator =" << endl;
        ListContainer lc1;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1 = lc;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1.sum();
        lc1.average();
    } else {
        lc.print();
    }

    return 0;
}
