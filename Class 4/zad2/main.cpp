//Потребно е да се имплементираат класи File (датотека) и Folder (директориум) за работа со едноставен датотечен
// систем.
//
//Во класата File треба да се чуваат следниве податоци:
//
//Име на датотеката (динамички алоцирана низа од знаци)
//Екстензија на датотеката (енумерација со можни вредности: txt, pdf, exe)
//Име на сопственикот на датотеката (динамички алоцирана низа од знаци)
//Големина на датотеката (цел број на мегабајти)

//Дополнително, во класата потребно е да се напишат и:
//
//Конструктор без параметри
//Конструктор со параметри
//Конструктор за копирање
// Деструктор
//Преоптоварување на операторот =
//Метод за печатење на информациите за една датотека (видете го излезот од тест примерите за структурата на печатење) - print()
//Метод за проверка на еднаквост помеѓу две датотеки со потпис bool equals(const File & that) кој ќе враќа true ако датотеките
//имаат исто име, екстензија и сопственик
//Метод за споредба на типот помеѓу две датотеки со потпис bool equalsType(const File & that) кој ќе враќа true ако
//датотеките се од ист тип, т.е. имаат исто име и екстензија

//Во класата Folder треба да се чуваат следниве податоци:
//
//Име на директориумот (динамички алоцирана низа од знаци)
//Број на датотеки во него (на почеток директориумот е празен)
//Динамички алоцирана низа од датотеки, објекти од класата File
//Дополнително, во класата потребно е да се напишат и:
//
//Конструктор со потпис Folder(const char* name)
//Деструктор
//Метод за печатење на информациите за еден директориум (видете го излезот од тест примерите за структурата на печатење)
// - print()
//Метод за бришење на датотека од директориумот со потпис void remove(const File & file) кој ќе ја избрише првата датотека од
//директориумот која е еднаква според equals методот
//Метод за додавање на датотека во директориумот со потпис void add(const File & file) кој ќе додава датотеката во директориумот
//Не го менувајте почетниот код.

//For example:
//
//Input
//1
//rezultati_oop
//FINKI
//2
//0
//
//Result
//======= FILE CONSTRUCTORS AND = OPERATOR =======
//======= CREATED =======
//File name: rezultati_oop.pdf
//File owner: FINKI
//File size: 2
//
//======= COPIED =======
//File name: rezultati_oop.pdf
//        File owner: FINKI
//        File size: 2
//
//======= ASSIGNED =======
//File name: rezultati_oop.pdf
//        File owner: FINKI
//        File size
#include<iostream>
#include<cstring>

using namespace std;

enum Extension {
    txt,
    pdf,
    exe,
};

class File {
    char *name;
    Extension extension;
    char *ownerName;
    int size;
public:
    File() {
        this->name = new char[50];
        strcpy(this->name, "");

        this->ownerName = new char[50];
        strcpy(this->ownerName, "");

        this->size = 0;
        this->extension = (Extension) 0;
    }

    File(char *name, char *ownerName, int size, Extension extension) {
        this->name = new char[50];
        strcpy(this->name, name);

        this->ownerName = new char[50];
        strcpy(this->ownerName, ownerName);

        this->size = size;
        this->extension = extension;
    }

    File(const File &f) {
        this->name = new char[50];
        strcpy(this->name, f.name);

        this->ownerName = new char[50];
        strcpy(this->ownerName, f.ownerName);

        this->size = f.size;
        this->extension = f.extension;
    }

    File &operator=(const File &f) {
        if (this != &f) {
            delete[] name;
            delete[] ownerName;
            this->ownerName = new char[50];
            this->name = new char[50];
            strcpy(this->name, f.name);
            strcpy(this->ownerName, f.ownerName);
            this->extension = f.extension;
            this->size = f.size;
        }

        return *this;
    }

    ~File() {
        delete [] name;
        delete [] ownerName;
    }

    void printExtension(Extension e) {
        if (e == 0) {
            cout << "pdf";
        } else if (e == 1) {
            cout << "txt";
        } else {
            cout << "exe";
        }
    }

    void print() {
        cout << "File name: " << name << ".";
        printExtension(extension);
        cout << endl;
        cout << "File owner: " << ownerName << endl;
        cout << "File size: " << size << endl;
    }

    bool equals(const File & that) {
        if(strcmp(this->name, that.name) == 0 && strcmp(this->ownerName, that.ownerName) == 0 &&
            this->extension == that.extension) {
            return true;
        }
        return false;
    }

    bool equalsType(const File & that) {
        if(strcmp(this->name, that.name) == 0 && this->extension == that.extension) {
            return true;
        }
        return false;
    }
};

class Folder {
    char *name;
    int numFiles;
    File *files;

public:
    Folder() {
        this->name = new char[50];
        strcpy(this->name, "");

        this->numFiles = 0;
        this->files = new File[0];
    }

    Folder(const char* name) {
        this->name = new char[strlen(name)];
        strcpy(this->name, name);

        this->numFiles = 0;
        this->files = new File[0];
    }

    Folder(const Folder &f) {
        this->name = new char[strlen(name)];
        strcpy(this->name, f.name);

        this->numFiles = f.numFiles;
        this->files = new File[0];
        for(int i = 0; i < numFiles; i++) {
            files[i] = f.files[i];
        }
    }

    Folder &operator=(const Folder & f) {
        if(this!=&f) {
            delete [] name;
            delete [] files;

            this->numFiles = f.numFiles;

            this->name = new char[strlen(f.name)];
            strcpy(this->name, f.name);

            this->files = new File[0];
            for(int i = 0; i < numFiles; i++) {
                files[i] = f.files[i];
            }
        }

        return *this;
    }

    ~Folder() {
        delete [] name;
        delete [] files;
    }

//    Folder name: results
//            File name: rezultati_oop.pdf
//            File owner: FINKI
//            File size: 2
//            File name: rezultati_oop.pdf
//            File owner: Ministerot
//            File size: 2
//            File name: rezultati_oop.txt
//            File owner: Ministerot
//            File size: 2
    void print() {
        cout << "Folder name: " << name << endl;
        for(int i = 0; i < numFiles; i++) {
            this->files[i].print();
        }
    }

    void add(const File & file) {
        File *tmp = new File[numFiles + 1];
        for(int i = 0; i < numFiles; i++) {
            tmp[i] = files[i];
        }
        tmp[numFiles++]=file;
        delete [] files;
        files = tmp;
    }

    void remove(const File & file) {
        int index = 0;
        File *tmp = new File[numFiles - 1];
        for(int i = 0; i < numFiles; i++) {
            if(files[i].equals(file)) {
                continue;
            } else {
                tmp[index++]=files[i];
            }
        }
        delete [] files;
        files=tmp;
        numFiles -= 1;
    }
};

int main() {
    char fileName[20];
    char fileOwner[20];
    int ext;
    int fileSize;

    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File created = File(fileName, fileOwner, fileSize, (Extension) ext);
        File copied = File(created);
        File assigned = created;

        cout << "======= CREATED =======" << endl;
        created.print();
        cout << endl;
        cout << "======= COPIED =======" << endl;
        copied.print();
        cout << endl;
        cout << "======= ASSIGNED =======" << endl;
        assigned.print();
    } else if (testCase == 2) {
        cout << "======= FILE EQUALS AND EQUALS TYPE =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File first(fileName, fileOwner, fileSize, (Extension) ext);
        first.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File second(fileName, fileOwner, fileSize, (Extension) ext);
        second.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File third(fileName, fileOwner, fileSize, (Extension) ext);
        third.print();

        bool equals = first.equals(second);
        cout << "FIRST EQUALS SECOND: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equals = first.equals(third);
        cout << "FIRST EQUALS THIRD: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        bool equalsType = first.equalsType(second);
        cout << "FIRST EQUALS TYPE SECOND: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equalsType = second.equals(third);
        cout << "SECOND EQUALS TYPE THIRD: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

    } else if (testCase == 3) {
        cout << "======= FOLDER CONSTRUCTOR =======" << endl;
        cin >> fileName;
        Folder folder(fileName);
        folder.print();

    } else if (testCase == 4) {
        cout << "======= ADD FILE IN FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        folder.print();
    } else {
        cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File file(fileName, fileOwner, fileSize, (Extension) ext);
        folder.remove(file);
        folder.print();
    }
    return 0;
}