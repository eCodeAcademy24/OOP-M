//Да се напише класа за матрица. Во класата се чуваат елементите од матрицата од тип float (матрица со максимална димензија [10]x[10])
// и големината на матрицата (број на редици и колони). За оваа класа да се преоптоварат следните оператори:
//
//    оператор + за собирање матрица со број
//    оператор - за одземање на матрици
//    оператор * за множење на матрици
//    операторот >> за внесување на елементите на матрицата
//    операторот << за печатење на елементите на матрицата
//
//Во главната функција да се креираат објекти A, B и C со подразбирливиот конструктор на класата Matrica.
// Од стандарден влез
// да се прочитаат нивните вредности. Да се отпечати вредноста на изразот A-(B*C)+2 на стандарден излез.
//
//Да се претпостави дека секогаш матриците ќе бидат квадратни со ист број на редици и колони.

#include <iostream>
#include <cmath>

using namespace std;

class Matrica {
private:
    float matrica[10][10];
    int redica;
    int kolona;
public:
    Matrica() {

    }

    ~Matrica() {}

    friend istream &operator>>(istream &in, Matrica &m) {
        in >> m.redica >> m.kolona;
        for (int i = 0; i < m.redica; i++) {
            for (int j = 0; j < m.kolona; j++) {
                in >> m.matrica[i][j];
            }
        }
        return in;
    }

    friend ostream &operator<<(ostream &out, const Matrica &m) {
        for (int i = 0; i < m.redica; i++) {
            for (int j = 0; j < m.kolona; j++) {
                out << m.matrica[i][j] << " ";
            }
            out << endl;
        }

        return out;
    }

    Matrica operator+(const int broj) {
        Matrica nov;
        nov.redica = redica;
        nov.kolona = kolona;
        for (int i = 0; i < redica; i++) {
            for (int j = 0; j < kolona; j++) {
                nov.matrica[i][j] = matrica[i][j] + broj;
            }
        }

        return nov;
    }

    Matrica operator-(const Matrica &m) {
        Matrica nov;
        nov.redica = redica;
        nov.kolona = kolona;
        for (int i = 0; i < redica; i++) {
            for (int j = 0; j < kolona; j++) {
                nov.matrica[i][j] = matrica[i][j] - m.matrica[i][j];
            }
        }

        return nov;
    }

    Matrica operator*(const Matrica &ma) {
        Matrica nov;
        nov.redica = redica;
        nov.kolona = kolona;
        for (int i = 0; i < redica; i++) {
            for (int j = 0; j < kolona; j++) {
                nov.matrica[i][j] = matrica[i][j] * ma.matrica[i][j];
            }
        }
        return nov;
    }
};

int main() {
    Matrica A, B, C;
    cin >> A >> B >> C;
    Matrica D = B * C;
    Matrica R = A - D + 2;
    cout << R;
}