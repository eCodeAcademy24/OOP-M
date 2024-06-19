#include <iostream>
#include <string.h>
using namespace std;
//NBAPlayer
// Да се дефинира класа NBAPlayer за која ќе се чуваат:
//
// динамички алоцирана низа од карактери за името на играчот
// низа од максимум 40 карактери за тимот во кој играчот моментално настапува
// просечен број на поени на играчот оваа сезона (double)
// просечен број на асистенции на играчот оваа сезона (double)
// просечен број на скокови на играчот оваа сезона (double)
// За потребите на класата да се дефинираат:
//
// default конструктор и конструктор со аргументи
// copy constructor и оператор =
// деструктор
// метод rating() кој го враќа рејтингот на кошаркарот кој се пресметува како:
//
//     45% од поените + 30% од асистенциите + 25% од скоковите
//
//     метод print() кој го печати играчот во следниот формат:
//
//         Име - тим
//
//         Points: поени
//
//         Assists: асистенции
//
//         Rebounds: скокови
//
//         Rating: рејтинг

class NBAPlayer {
protected:
    char *ime;
    char tim[40];
    double poeni;
    double asistencii;
    double skokovi;

public:
    // default конструктор
    NBAPlayer() {
        ime = new char[0];
        poeni = 0;
        asistencii = 0;
        skokovi = 0;
    }

    // конструктор со аргументи
    NBAPlayer(char *ime, char *tim, double poeni, double asistencii, double skokovi) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        strcpy(this->tim, tim);
        this->poeni = poeni;
        this->asistencii = asistencii;
        this->skokovi = skokovi;
    }

    // copy constructor
    NBAPlayer(const NBAPlayer &np) {
        ime = new char[strlen(np.ime) + 1];
        strcpy(ime, np.ime);
        strcpy(tim, np.tim);
        poeni = np.poeni;
        asistencii = np.asistencii;
        skokovi = np.skokovi;
    }

    // оператор =
    NBAPlayer &operator=(const NBAPlayer &np) {
        if (this != &np) {
            delete[] ime;
            ime = new char[strlen(np.ime) + 1];
            strcpy(ime, np.ime);
            strcpy(tim, np.tim);
            poeni = np.poeni;
            asistencii = np.asistencii;
            skokovi = np.skokovi;
        }

        return *this;
    }

    // деструктор
    ~NBAPlayer() {
        delete[] ime;
    }

    // метод rating() кој го враќа рејтингот на кошаркарот кој се пресметува како:
    //45% од поените + 30% од асистенциите + 25% од скоковите
    double rating() {
        return (poeni * 0.45) + (asistencii * 0.3) + (skokovi * 0.25);
    }

    //     метод print() кој го печати играчот во следниот формат:
    // Nikola_Jokic - Denver_Nuggets
    // Points: 18.3
    // Assists: 6.1
    // Rebounds: 10.6
    // Rating: 12.715
    void print() {
        //Име - тим
        cout << ime << " - " << tim << endl;

        //Points: поени
        cout << "Points: " << poeni << endl;

        //Assists: асистенции
        cout << "Assists: " << asistencii << endl;

        //Rebounds: скокови
        cout << "Rebounds: " << skokovi << endl;

        //Rating: рејтинг
        cout << "Rating: " << rating() << endl;
    }
};

//AllStarPlayer
//Од претходната класа NBAPlayer да се изведе класата AllStarPlayer за која дополнително ќе се чуваат и:
//
//             просечен број на поени на играчот од All Star натпреварите (double)
//             просечен број на асистенции на играчот од All Star натпреварите (double)
//             просечен број на скокови на играчот од All Star натпреварите (double)
//             За потребите на класата да се дефинираат:
//
//                 default конструктор
//                 конструктор кој прима објект од NBAPlayer и плус додатните информации (погледни main)
//                 конструктор кој ги прима сите аргументи (погледни main)
//                 copy constructor, оператор =, деструктор
//                 метод allStarRating() кој го враќа рејтингот на кошаркарот од All Star натпреварите
//                 и кој се пресметува како:
//
//                 30% од поените + 40% од асистенциите + 30% од скоковите
//
//                 Да се препокријат методите:
//
//                 rating() кој го враќа просекот од обичниот рејтинг на кошаркарот и неговиот All Star рејтинг
//                 print() кој покрај основните информации за кошаркарот печати и:
//
//                 All Star Rating: рејтингот од All Star натпреварите
//
//                 New Rating: просечниот рејтинг
class AllStarPlayer : public NBAPlayer {
private:
    double poeniAS;
    double asistenciiAS;
    double skokoviAS;

public:
    // default конструктор
    AllStarPlayer() : NBAPlayer() {
    }

    //конструктор кој прима објект од NBAPlayer и плус додатните информации (погледни main)
    AllStarPlayer(NBAPlayer np, double poeniAS, double asistenciiAS, double skokoviAS) : NBAPlayer(np) {
        this->poeniAS = poeniAS;
        this->asistenciiAS = asistenciiAS;
        this->skokoviAS = skokoviAS;
    }

    //конструктор кој ги прима сите аргументи (погледни main)
    AllStarPlayer(char *ime, char *tim, double poeni, double asistencii, double skokovi,
                  double poeniAS, double asistenciiAS, double skokoviAS
    ) : NBAPlayer(ime, tim, poeni, asistencii, skokovi) {
        this->poeniAS = poeniAS;
        this->asistenciiAS = asistenciiAS;
        this->skokoviAS = skokoviAS;
    }

    //copy constructor
    AllStarPlayer(const AllStarPlayer &asp) : NBAPlayer(asp) {
        poeniAS = asp.poeniAS;
        asistenciiAS = asp.asistenciiAS;
        skokoviAS = asp.skokoviAS;
    }

    //оператор =
    AllStarPlayer &operator=(const AllStarPlayer &asp) {
        if (this != &asp) {
            delete[] ime;
            ime = new char[strlen(asp.ime) + 1];
            strcpy(ime, asp.ime);
            strcpy(tim, asp.tim);
            poeni = asp.poeni;
            asistencii = asp.asistencii;
            skokovi = asp.skokovi;
            poeniAS = asp.poeniAS;
            asistenciiAS = asp.asistenciiAS;
            skokoviAS = asp.skokoviAS;
        }

        return *this;
    }

    //деструктор
    ~AllStarPlayer() {
    }

    //метод allStarRating() кој го враќа рејтингот на кошаркарот од All Star натпреварите и кој се пресметува како:
    // 30% од поените + 40% од асистенциите + 30% од скоковите
    double allStarRating() {
        return (poeniAS * 0.3) + (asistenciiAS * 0.4) + (skokoviAS * 0.3);
    }

    //rating() кој го враќа просекот од обичниот рејтинг на кошаркарот и неговиот All Star рејтинг
    double rating() {
        return (NBAPlayer::rating() + allStarRating()) / 2;
    }


    // Carmelo_Anthony - Oklahoma_City_Thunder
    // Points: 16.3
    // Assists: 1.3
    // Rebounds: 5.9
    // Rating: 9.2
    // All Star Rating: 10.38
    // New Rating: 9.79
    void print() {
        //print() кој покрај основните информации за кошаркарот печати и:
        NBAPlayer::print();

        // All Star Rating: рејтингот од All Star натпреварите
        cout << "All Star Rating: " << allStarRating() << endl;

        // New Rating: просечниот рејтинг
        cout << "New Rating: " << rating() << endl;
    }
};

//Input
// 1
//  Nikola_Jokic Denver_Nuggets 18.3 6.1 10.6
//  Lonzo_Ball Los_Angeles_Lakers 10.2 7.2 6.9
//  Donovan_Mitchell Utah_Jazz 20.4 3.6 3.7
//  Ben_Simmons Philadelphia_76ers 16 8.2 8.2
//  Kristaps_Porzingis New_York_Knicks 22.7 1.2 6.6
//Output
//NBA PLAYERS:
// =====================================
// Nikola_Jokic - Denver_Nuggets
// Points: 18.3
// Assists: 6.1
// Rebounds: 10.6
// Rating: 12.715
// Lonzo_Ball - Los_Angeles_Lakers
// Points: 10.2
// Assists: 7.2
// Rebounds: 6.9
// Rating: 8.475
// Donovan_Mitchell - Utah_Jazz
// Points: 20.4
// Assists: 3.6
// Rebounds: 3.7
// Rating: 11.185
// Ben_Simmons - Philadelphia_76ers
// Points: 16
// Assists: 8.2
// Rebounds: 8.2
// Rating: 11.71
// Kristaps_Porzingis - New_York_Knicks
// Points: 22.7
// Assists: 1.2
// Rebounds: 6.6
// Rating: 12.225

//Input
// 3
// Carmelo_Anthony Oklahoma_City_Thunder 16.3 1.3 5.9 24.1 3 6.5
// LeBron_James Cleveland_Cavaliers 27.7 9.2 8.7 27.2 7.2 7.4
// James_Harden Houston_Rockets 30.6 8.7 5.4 23 6 5.1
// Stephen_Curry Golden_State_Warriors 26.4 6.1 5.1 23.1 6.8 4.4
// Giannis_Antetokounmpo Milwaukee_Bucks 27.1 4.8 10 17.2 3.8 7.5

//Output
//ALL STAR PLAYERS:
// =====================================
// Carmelo_Anthony - Oklahoma_City_Thunder
// Points: 16.3
// Assists: 1.3
// Rebounds: 5.9
// Rating: 9.2
// All Star Rating: 10.38
// New Rating: 9.79
// LeBron_James - Cleveland_Cavaliers
// Points: 27.7
// Assists: 9.2
// Rebounds: 8.7
// Rating: 17.4
// All Star Rating: 13.26
// New Rating: 15.33
// James_Harden - Houston_Rockets
// Points: 30.6
// Assists: 8.7
// Rebounds: 5.4
// Rating: 17.73
// All Star Rating: 10.83
// New Rating: 14.28
// Stephen_Curry - Golden_State_Warriors
// Points: 26.4
// Assists: 6.1
// Rebounds: 5.1
// Rating: 14.985
// All Star Rating: 10.97
// New Rating: 12.9775
// Giannis_Antetokounmpo - Milwaukee_Bucks
// Points: 27.1
// Assists: 4.8
// Rebounds: 10
// Rating: 16.135
// All Star Rating: 8.93
// New Rating: 12.5325
int main() {
    char name[50];
    char team[40];
    double points;
    double assists;
    double rebounds;
    double allStarPoints;
    double allStarAssists;
    double allStarRebounds;

    NBAPlayer *players = new NBAPlayer[5];
    AllStarPlayer *asPlayers = new AllStarPlayer[5];
    int n;
    cin >> n;

    if (n == 1) {
        cout << "NBA PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i) {
            cin >> name >> team >> points >> assists >> rebounds;
            players[i] = NBAPlayer(name, team, points, assists, rebounds);
            players[i].print();
        }
    } else if (n == 2) {
        for (int i = 0; i < 5; ++i) {
            cin >> name >> team >> points >> assists >> rebounds;
            cin >> allStarPoints >> allStarAssists >> allStarRebounds;
            players[i] = NBAPlayer(name, team, points, assists, rebounds);
            asPlayers[i] = AllStarPlayer(players[i], allStarPoints, allStarAssists, allStarRebounds);
        }

        cout << "NBA PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i)
            players[i].print();

        cout << "ALL STAR PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i)
            asPlayers[i].print();
    } else if (n == 3) {
        for (int i = 0; i < 5; ++i) {
            cin >> name >> team >> points >> assists >> rebounds;
            cin >> allStarPoints >> allStarAssists >> allStarRebounds;
            asPlayers[i] = AllStarPlayer(name, team, points, assists, rebounds,
                                         allStarPoints, allStarAssists, allStarRebounds);
        }
        cout << "ALL STAR PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i)
            asPlayers[i].print();
    }

    delete [] players;
    delete [] asPlayers;
}
