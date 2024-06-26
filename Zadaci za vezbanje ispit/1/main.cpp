#include <iostream>
#include <cstring>

using namespace std;

// Издавачката куќа FINKI-Education издава онлајн и печатени книги. За секоја книга се чуваат податоци за ISBN бројот (низа од најмногу 20 знаци),
// насловот (низа од најмногу 50 знаци), авторот (низа од најмногу 30 знаци) и основната цена изразена во $ (реален број).
// Класата за опишување на книгите е апстрактна (5 поени).
//
// За секоја онлајн книга дополнително се чуваат податоци за url од каде може да се симне (динамички резервирана низа од знаци) и големината изразена во MB (цел број).
// За секоја печатена книга дополнително се чуваат податоци за масата изразена во килограми (реален број) и дали ја има на залиха (логичка променлива). (5 поени)
//
//За секој објект од двете изведени класи треба да бидат на располагање следниве методи:
//
//Метод bookPrice, за пресметување на продажната цена на книгата на следниот начин: (10 поени)
//
//За онлајн книга - цената се зголемува за 20% од основната цена ако книгата е поголема од 20MB
//
//За печатена книга - цената се зголемува за 15% од основната цена ако масата на книгата е поголема од 0.7kg
//
//Преоптоварен оператор > за споредба на две книги од каков било вид според нивната цена. (5 поени)
//
//Преоптоварен оператор << за печатење на податоците за книгите во формат: (5 поени)
//Да се имплементира функција mostExpensiveBook со потпис:
//
//void mostExpensiveBook (Book** books, int n)
//
//во која се печати вкупниот број на онлајн, односно, печатени книги во проследената низа посебно. (5 поени) Потоа се наоѓа и печати најскапата книга. (5 поени)
//
//Да се обезбедат сите потребни функции за правилно функционирање на програмата. (5 поени)

class Book {
protected:
    char ISBN[20];
    char naslov[50];
    char avtor[30];
    double cena;
public:
    Book() {}

    Book(char *ISBN, char *naslov, char *avtor, double cena) {
        strcpy(this->ISBN, ISBN);
        strcpy(this->naslov, naslov);
        strcpy(this->avtor, avtor);
        this->cena = cena;
    }

    Book(const Book &b) {
        strcpy(this->ISBN, b.ISBN);
        strcpy(this->naslov, b.naslov);
        strcpy(this->avtor, b.avtor);
        this->cena = b.cena;
    }

    Book &operator=(const Book &b) {
        if (this != &b) {
            strcpy(this->ISBN, b.ISBN);
            strcpy(this->naslov, b.naslov);
            strcpy(this->avtor, b.avtor);
            this->cena = b.cena;
        }

        return *this;
    }

    void setISBN(char *ISBN) {
        strcpy(this->ISBN, ISBN);
    }

    char *getISBN() {
        return ISBN;
    }

    char *getNaslov() {
        return naslov;
    }

    char *getAvtor() {
        return avtor;
    }

    int getCena() {
        return cena;
    }

    ~Book() {}

    virtual double price() = 0;

    bool operator>(Book &b) {
        return cena > b.cena;
    }

    friend ostream &operator<<(ostream &out, Book &b) {
        //007-6092006565: Thinking in C++, Bruce Eckel 59.8
        out << b.ISBN << ": " << b.naslov << ", " << b.avtor << " " << b.price() << endl;
        return out;
    }
};

class OnlineBook : public Book {
private:
    char *url;
    int golemina;
public:
    OnlineBook() : Book() {
        url = new char[0];
        golemina = 0;
    }

    OnlineBook(char *ISBN, char *naslov, char *avtor, double cena, char *url, int golemina) : Book(ISBN, naslov, avtor,
                                                                                                   cena) {
        this->url = new char[strlen(url) + 1];
        strcpy(this->url, url);
        this->golemina = golemina;
    }

    OnlineBook(const OnlineBook &ob) : Book(ob) {
        this->url = new char[strlen(ob.url) + 1];
        strcpy(this->url, ob.url);
        this->golemina = ob.golemina;
    }

    OnlineBook &operator=(const OnlineBook &ob) {
        if (this != &ob) {
            delete[] url;
            strcpy(this->ISBN, ob.ISBN);
            strcpy(this->naslov, ob.naslov);
            strcpy(this->avtor, ob.avtor);
            this->cena = ob.cena;
            this->url = new char[strlen(ob.url) + 1];
            strcpy(this->url, ob.url);
            this->golemina = ob.golemina;
        }

        return *this;
    }

    ~OnlineBook() {
        delete[] url;
    }

    //За онлајн книга - цената се зголемува за 20% од основната цена ако книгата е поголема од 20MB
    double price() {
        if (golemina > 20) {
            return cena * 1.2; // cena + (cena * 0.2)
        } else {
            return cena;
        }
    }
};

class PrintBook : public Book {
private:
    double masa;
    bool zaliha;
public:
    PrintBook() : Book() {

    }

    PrintBook(char *ISBN, char *naslov, char *avtor, double cena, double masa, bool zaliha) : Book(ISBN, naslov, avtor,
                                                                                                   cena) {
        this->masa = masa;
        this->zaliha = zaliha;
    }

    PrintBook(const PrintBook &pb) : Book(pb) {
        masa = pb.masa;
        zaliha = pb.zaliha;
    }

    PrintBook &operator=(const PrintBook &pb) {
        if (this != &pb) {
            strcpy(this->ISBN, pb.ISBN);
            strcpy(this->naslov, pb.naslov);
            strcpy(this->avtor, pb.avtor);
            this->cena = pb.cena;
            masa = pb.masa;
            zaliha = pb.zaliha;
        }

        return *this;
    }

    ~PrintBook() {}

    //За печатена книга - цената се зголемува за 15% од основната цена ако масата на книгата е поголема од 0.7kg
    double price() {
        if (masa > 0.7) {
            return cena * 1.15; // cena + (cena * 0.15)
        } else {
            return cena;
        }
    }
};

//Да се имплементира функција mostExpensiveBook со потпис:
//
//void mostExpensiveBook (Book** books, int n)
//
//во која се печати вкупниот број на онлајн, односно, печатени книги во проследената низа посебно. (5 поени) Потоа се наоѓа и печати најскапата книга. (5 поени)

void mostExpensiveBook(Book **books, int n) {
    cout << "FINKI-Education" << endl;

    int pbCounter = 0;
    int obCounter = 0;

    for (int i = 0; i < n; i++) {
        OnlineBook *ob = dynamic_cast<OnlineBook *>(books[i]);
        if (ob) {
            obCounter++;
        } else {
            pbCounter++;
        }
    }

    //    for (int i = 0; i < n; i++) {
//        PrintBook *pb = dynamic_cast<PrintBook *>(books[i]);
//        if (pb) {
//            pbCounter++;
//        }
//    }
    cout << "Total number of online books: " << obCounter << endl;
    cout << "Total number of print books: " << pbCounter << endl;

    cout << "The most expensive book is: " << endl;

    int max = books[0]->price();
    int maxI = 0;

    for (int i = 1; i < n; i++) {
        if (max < books[i]->price()) {
            max = books[i]->price();
            maxI = i;
        }
    }
    //007-6092006565: Thinking in C++, Bruce Eckel 59.8
    cout << books[maxI]->getISBN() << ": " << books[maxI]->getNaslov() << ", " << books[maxI]->getAvtor() << " "
         << books[maxI]->price();
}


int main() {

    char isbn[20], title[50], author[30], url[100];
    int size, tip;
    float price, weight;
    bool inStock;
    Book **books;
    int n;

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "====== Testing OnlineBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++) {
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> url;
            cin >> size;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new OnlineBook(isbn, title, author, price, url, size);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 2) {
        cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
        cin >> isbn;
        cin.get();
        cin.getline(title, 50);
        cin.getline(author, 30);
        cin >> price;
        cin >> url;
        cin >> size;
        cout << "CONSTRUCTOR" << endl;
        OnlineBook ob1(isbn, title, author, price, url, size);
        cout << ob1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        OnlineBook ob2(ob1);
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
        cout << "OPERATOR =" << endl;
        ob1 = ob2;
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
    }
    if (testCase == 3) {
        cout << "====== Testing PrintBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++) {
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> weight;
            cin >> inStock;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 4) {
        cout << "====== Testing method mostExpensiveBook() ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++) {

            cin >> tip >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            if (tip == 1) {

                cin >> url;
                cin >> size;

                books[i] = new OnlineBook(isbn, title, author, price, url, size);

            } else {
                cin >> weight;
                cin >> inStock;

                books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            }
        }

        mostExpensiveBook(books, n);
    }

    for (int i = 0; i < n; i++) delete books[i];
    delete[] books;
    return 0;
}
