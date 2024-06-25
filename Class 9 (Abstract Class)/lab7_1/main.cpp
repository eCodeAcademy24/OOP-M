#include <iostream>
#include <string.h>
using namespace std;
//Да се дефинира апстрактна класа Employee којашто ќе содржи име на вработениот, години и работно
//искуство во години (integer). Да се дефинираат чисти виртуелни функции plata() и bonus() (double).

class Employee {
protected:
    char *name;
    int year;
    int experience;

public:
    Employee() {
        name = new char[0];
    }

    Employee(char *name, int year, int experience) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->year = year;
        this->experience = experience;
    }

    Employee(const Employee &emp) {
        name = new char[strlen(emp.name) + 1];
        strcpy(this->name, emp.name);
        this->year = emp.year;
        this->experience = emp.experience;
    }

    Employee &operator=(const Employee &emp) {
        if (this != &emp) {
            delete [] name;
            name = new char[strlen(emp.name) + 1];
            strcpy(this->name, emp.name);
            this->year = emp.year;
            this->experience = emp.experience;
        }
        return *this;
    }

    ~Employee() {
        delete[] name;
    }

    // Да се дефинираат чисти виртуелни функции plata() и bonus() (double).
    virtual double plata() = 0;

    virtual double bonus() = 0;

    // Да се преоптовари операторот == кој ќе прима два објекти од класата Employee и ќе ги
    // споредува според тоа дали имаат ист број на години.
    bool operator ==(Employee &em) {
        //eden nachin
        // if(year == em.year) {
        //     return true;
        // }
        //
        // return false;

        //vtor nachin
        return year == em.year;
    }
};

// Од класата Employee да се изведе класа SalaryEmployee која покрај основните информации содржи и
// информација за основната плата. Бонусот на овие работници се пресметува како процент од основната плата,
// а процентот е бројот на години со работно искуство. На пример ако работеле 10 години,
// бонусот е 10 проценти од основната плата. Вкупната плата се пресметува како основната плата плус бонусот.
class SalaryEmployee : public Employee {
private:
    int basicSalary;

public:
    SalaryEmployee() : Employee() {
    }

    SalaryEmployee(char *name, int year, int experience, int basicSalary) : Employee(name, year, experience) {
        this->basicSalary = basicSalary;
    }

    SalaryEmployee(const SalaryEmployee &se) : Employee(se) {
        this->basicSalary = se.basicSalary;
    }

    SalaryEmployee &operator=(const SalaryEmployee &se) {
        if (this != &se) {
            delete[] name;
            name = new char[strlen(se.name) + 1];
            strcpy(this->name, se.name);
            this->year = se.year;
            this->experience = se.experience;
            this->basicSalary = se.basicSalary;
        }

        return *this;
    }

    ~SalaryEmployee() {
    }

    // Бонусот на овие работници се пресметува како процент од основната плата,
    // а процентот е бројот на години со работно искуство. На пример ако работеле 10 години,
    // бонусот е 10 проценти од основната плата.
    double bonus() {
        return basicSalary * experience / 100.0;
    }

    // Вкупната плата се пресметува како основната плата плус бонусот.
    double plata() {
        return basicSalary + bonus();
    }
};

// Од класата Employee исто така да се изведе класа HourlyEmployee која покрај основните
// информации содржи информација и за вкупниот број на часови кои ги одработил работникот и платата по час.
// Вкупната плата се пресметува како бројот на часови помножен со платата по час плус бонусот,
// додека бонусот се пресметува на следниот начин: За секој час над 320-тиот се добива 50 проценти
// од платата по час.
class HourlyEmployee : public Employee {
private:
    int totalHours;
    int payPerHour;

public:
    HourlyEmployee() : Employee() {
    }

    HourlyEmployee(char *name, int year, int experience, int totalHours, int payPerHour) : Employee(
        name, year, experience) {
        this->totalHours = totalHours;
        this->payPerHour = payPerHour;
    }

    HourlyEmployee(const HourlyEmployee &he) : Employee(he) {
        totalHours = he.totalHours;
        payPerHour = he.payPerHour;
    }

    HourlyEmployee &operator=(const HourlyEmployee &he) {
        if (this != &he) {
            delete [] name;
            name = new char[strlen(he.name) + 1];
            strcpy(this->name, he.name);
            this->year = he.year;
            this->experience = he.experience;
            totalHours = he.totalHours;
            payPerHour = he.payPerHour;
        }

        return *this;
    }

    ~HourlyEmployee() {
    }


    // додека бонусот се пресметува на следниот начин: За секој час над 320-тиот се добива 50 проценти
    // од платата по час.
    double bonus() {
        double count = 0;

        if (totalHours > 320) {
            count = (totalHours - 320) * 0.5 * payPerHour;
        }

        return count;
    }

    // Вкупната плата се пресметува како бројот на часови помножен со платата по час плус бонусот,
    double plata() {
        return totalHours * payPerHour + bonus();
    }
};

// Од класата Employee на крај се изведува класата Freelancer која покрај основните информации содржи
// и број на проекти на кои работел вработениет и низа со суми кои ги добил за тие проекти (double).
// По направени 5 проекти, за секој нареден вработените добиваат бонус од 1000 денари.
// Вкупната плата на овој тип на вработени изнесува вкупната сума добиена од сите проекти плус бонусот.
class Freelancer : public Employee {
private:
    int numProjects;
    double *projects;

public:
    Freelancer() : Employee() {
        numProjects = 0;
        projects = new double[0];
    }

    Freelancer(char *name, int year, int experience, int numProjects, double *projects) : Employee(
        name, year, experience) {
        this->numProjects = numProjects;
        this->projects = new double[numProjects];
        for (int i = 0; i < numProjects; i++) {
            this->projects[i] = projects[i];
        }
    }

    Freelancer(const Freelancer &fl) : Employee(fl) {
        numProjects = fl.numProjects;
        projects = new double[numProjects];
        for (int i = 0; i < numProjects; i++) {
            projects[i] = fl.projects[i];
        }
    }

    Freelancer &operator=(const Freelancer &fl) {
        if (this != &fl) {
            delete[] name;
            delete[] projects;
            name = new char[strlen(fl.name) + 1];
            strcpy(this->name, fl.name);
            this->year = fl.year;
            this->experience = fl.experience;
            numProjects = fl.numProjects;
            projects = new double[numProjects];
            for (int i = 0; i < numProjects; i++) {
                projects[i] = fl.projects[i];
            }
        }

        return *this;
    }

    ~Freelancer() {
        delete[] projects;
    }

    // По направени 5 проекти, за секој нареден вработените добиваат бонус од 1000 денари.
    double bonus() {
        double count = 0;

        if (numProjects > 5) {
            count = (numProjects - 5) * 1000;
        }

        return count;
    }

    // Вкупната плата на овој тип на вработени изнесува вкупната сума добиена од сите проекти плус бонусот.
    double sum() {
        double total = 0;
        for (int i = 0; i < numProjects; i++) {
            total += projects[i];
        }

        return total;
    }

    double plata() {
        return sum() + bonus();
    }
};

// Да се преоптовари операторот == кој ќе прима два објекти од класата Employee и ќе ги
// споредува според тоа дали имаат ист број на години.

// Да се дефинира класа Company која ќе содржи информации за името на компанијата, бројот на вработени,
// и динамична низа од покажувачи од класата Employee или Employee **.
// За потребите на оваа класа
// треба да се дефинира конструктор кој прима само еден аргумент - името на компанијата,
// да се преоптовари операторот += и да се дефинираат следните методи:
//
// double vkupnaPlata() - метод којшто ја враќа вкупната плата на сите вработени во компанијата
// double filtriranaPlata(Employee * emp) - метод којшто ја враќа платата само на работниците
// кои се еднакви со дадениот вработен (според оператор ==)
// void pecatiRabotnici() - метод којшто печати по колку вработени има од секој тип на работници
// во компанијата, а форматот на печатење можете да го видите од тест примерите
class Company {
private:
    char *name;
    int numEmployees;
    Employee **employees;

public:
    Company() {
        name = new char[0];
        numEmployees = 0;
        employees = new Employee *[0];
    }

    Company(char *name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        numEmployees = 0;
        employees = new Employee *[0];
    }

    // ne treba, samo za praksa e staven
    Company(char *name, int numEmployees, Employee **employees) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->numEmployees = numEmployees;
        this->employees = new Employee *[numEmployees];
        for (int i = 0; i < numEmployees; i++) {
            this->employees[i] = employees[i];
        }
    }

    Company(const Company &c) {
        this->name = new char[strlen(c.name) + 1];
        strcpy(this->name, c.name);
        this->numEmployees = c.numEmployees;
        this->employees = new Employee *[numEmployees];
        for (int i = 0; i < numEmployees; i++) {
            this->employees[i] = c.employees[i];
        }
    }

    Company &operator=(const Company &c) {
        if (this != &c) {
            delete[] name;
            delete[] employees;
            this->name = new char[strlen(c.name) + 1];
            strcpy(this->name, c.name);
            this->numEmployees = c.numEmployees;
            this->employees = new Employee *[numEmployees];
            for (int i = 0; i < numEmployees; i++) {
                this->employees[i] = c.employees[i];
            }
        }

        return *this;
    }

    ~Company() {
        delete[] name;
        delete[] employees;
    }

    // да се преоптовари операторот += и
    Company &operator +=(Employee *emp) {
        Employee **tmp = new Employee *[numEmployees + 1];
        for (int i = 0; i < numEmployees; i++) {
            tmp[i] = employees[i];
        }

        tmp[numEmployees] = emp;
        ++numEmployees;
        delete[] employees;

        // employees = tmp;
        employees = new Employee *[numEmployees];
        for (int i = 0; i < numEmployees; i++) {
            employees[i] = tmp[i];
        }

        return *this;
    }

    // да се дефинираат следните методи:
    // double vkupnaPlata() - метод којшто ја враќа вкупната плата на сите вработени во компанијата
    double vkupnaPlata() {
        double totalSalary = 0;
        for (int i = 0; i < numEmployees; i++) {
            totalSalary += employees[i]->plata();
        }

        return totalSalary;
    }

    // double filtriranaPlata(Employee * emp) - метод којшто ја враќа платата само на работниците
    // кои се еднакви со дадениот вработен (според оператор ==)
    double filtriranaPlata(Employee *emp) {
        double total = 0;
        for (int i = 0; i < numEmployees; i++) {
            if (*emp == *employees[i]) {
                total += employees[i]->plata();
            }
        }

        return total;
    }

    // void pecatiRabotnici() - метод којшто печати по колку вработени има од секој тип на работници
    // во компанијата, а форматот на печатење можете да го видите од тест примерите

    void pecatiRabotnici() {
        SalaryEmployee *se;
        HourlyEmployee *he;
        Freelancer *fl;
        int salary_count = 0, hourly_count = 0, freelancers_count = 0;
        for (int i = 0; i < numEmployees; i++) {
            se = dynamic_cast<SalaryEmployee *>(employees[i]);
            he = dynamic_cast<HourlyEmployee *>(employees[i]);
            fl = dynamic_cast<Freelancer *>(employees[i]);

            if (se) {
                salary_count++;
            } else if (he) {
                hourly_count++;
            } else if (fl) {
                freelancers_count++;
            }
        }

        // Vo kompanijata Market_Dejli rabotat:
        cout << "Vo kompanijata " << name << " rabotat:" << endl;

        // Salary employees: 2
        cout << "Salary employees: " << salary_count << endl;

        // Hourly employees: 2
        cout << "Hourly employees: " << hourly_count << endl;

        // Freelancers: 2
        cout << "Freelancers: " << freelancers_count << endl;
    }
};


// Hint: За потребите на последниот метод можете да искористите статички членови и статички
// функции во секоја од класата, dynamic_cast, виртуелна функција која ќе ја преоптоварите
// во секоја од класите или нешто друго по ваша желба.
//Input
// Market_Dejli
// 6
// 3 Iva_Damjanovska 37 14 6 3000 3300 2900 3450 1980 4010
// 1 Lidija_Andova 31 5 16000
// 2 Martin_Kovacev 54 29 336 100
// 1 Krume_Petrov 44 11 27000
// 2 Tea_Vinarova 29 4 330 60
// 3 Luka_Mihajlovski 41 20 3 6040 2060 3000
//Output
// Vo kompanijata Market_Dejli rabotat:
// Salary employees: 2
// Hourly employees: 2
// Freelancers: 2
// Vkupnata plata e: 132010
// Filtriranata plata e: 16800

int main() {
    char name[50];
    cin >> name;
    Company c(name);

    int n;
    cin >> n;

    char employeeName[50];
    int age;
    int experience;
    int type;

    for (int i = 0; i < n; ++i) {
        cin >> type;
        cin >> employeeName >> age >> experience;

        if (type == 1) {
            int basicSalary;
            cin >> basicSalary;
            c += new SalaryEmployee(employeeName, age, experience, basicSalary);
        } else if (type == 2) {
            int hoursWorked;
            int hourlyPay;
            cin >> hoursWorked >> hourlyPay;
            c += new HourlyEmployee(employeeName, age, experience, hoursWorked, hourlyPay);
        } else {
            int numProjects;
            cin >> numProjects;
            double projects[10];
            for (int i = 0; i < numProjects; ++i) {
                cin >> projects[i];
            }
            c += new Freelancer(employeeName, age, experience, numProjects, projects);
        }
    }

    c.pecatiRabotnici();
    cout << "Vkupnata plata e: " << c.vkupnaPlata() << endl;
    Employee *emp = new HourlyEmployee("Petre_Petrov", 31, 6, 340, 80);
    cout << "Filtriranata plata e: " << c.filtriranaPlata(emp);

    delete emp;
}
