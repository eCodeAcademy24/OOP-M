#include <iostream>
#include <string.h>
using namespace std;

// Сите класи кои се справуваат со исклучоци треба да го имаат имплементирано методот void message() така што
// за првите две класи ќе ја печати пораката којашто е испратена како параметар, а за последната класа ќе печати
// You can't add more than N users, каде што N е параметарот кој е пратен.

// Доколку лозинката на корисникот не содржи барем 1 голема буква, 1 мала буква и 1 број да се фрли исклучок од класа InvalidPassword
// така што како параметар ќе се прати пораката Password is too weak.
class InvalidPassword {
private:
    char msg[50];

public:
    InvalidPassword(char *msg) {
        strcpy(this->msg, msg);
    }

    void message() {
        cout << msg << endl;
    }
};

// Доколку емаилот на корисникот не содржи точно еднаш @ да се фрли исклучок од класа InvalidEmail така што како параметар ќ
// е се прати пораката Mail is not valid.
class InvalidEmail {
private:
    char msg[50];

public:
    InvalidEmail(char *msg) {
        strcpy(this->msg, msg);
    }

    void message() {
        cout << msg << endl;
    }
};

// Доколку проба да се додаде корисник во социјалната мрежа, а веќе максималниот број на корисници е пополнет
// да се фрли исклучок од класа MaximumSizeLimit така што како параметар ќе се прати максималниот број на корисници во мрежата.
class MaximumSizeLimit {
private:
    int maxUsers;

public:
    MaximumSizeLimit(int maxUsers) {
        this->maxUsers = maxUsers;
    }

    void message() {
        cout << "You can't add more than " << maxUsers << " users" << endl;
    }
};

//Да се дефинира апстрактна класа User за која ќе се чуваат:
//
// username (char[50])
// password (char[50])
// email (char[50])
// Класата треба да содржи еден чист виртуелен метод double popularity().
class User {
protected:
    char username[50];
    char password[50];
    char email[50];

    void copy(const User &u) {
        strcpy(username, u.username);
        strcpy(password, u.password);
        strcpy(email, u.email);
    }

public:
    User() {
    }

    User(char *username, char *password, char *email) {
        int upper = 0, lower = 0, digit = 0;
        for (int i = 0; i < strlen(password); i++) {
            if (isupper(password[i])) {
                ++upper;
            }

            if (islower(password[i])) {
                ++lower;
            }

            if (isdigit(password[i])) {
                ++digit;
            }
        }

        if (upper == 0 || lower == 0 || digit == 0) {
            throw InvalidPassword("Password is too weak.");
        }

        int counter = 0;
        for (int i = 0; i < strlen(email); i++) {
            if (email[i] == '@') {
                ++counter;
            }
        }

        if (counter != 1) {
            throw InvalidEmail("Mail is not valid.");
        }

        strcpy(this->username, username);
        strcpy(this->password, password);
        strcpy(this->email, email);
    }

    User(const User &u) {
        copy(u);
    }

    User &operator=(const User &u) {
        if (this != &u) {
            copy(u);
        }

        return *this;
    }

    ~User() {
    }

    virtual double popularity() = 0;
};

// Од оваа класа да се изведат две класи и тоа FacebookUser и TwitterUser.
//
// За класата FacebookUser уште се чуваат и:
//
// број на пријатели
// број на лајкови и
// број на коментари
// Популарноста се пресметува така што се собираат бројот на пријатели, бројот на лајкови и бројот на коментари,
// но притоа бројот на лајкови се множи со коефициент на вредност на лајкот кој е ист за секој корисник и изнесува 0.1,
// а исто така и бројот на коментари се множи со ист таков коефициент кој е 0.5.
class FacebookUser : public User {
private:
    int friends;
    int likes;
    int comments;

    void copy(const FacebookUser &fu) {
        friends = fu.friends;
        likes = fu.likes;
        comments = fu.comments;
    }

public:
    FacebookUser() : User() {
    }

    FacebookUser(char *username, char *password, char *email, int friends, int likes, int comments) : User(
        username, password, email) {
        this->friends = friends;
        this->likes = likes;
        this->comments = comments;
    }

    FacebookUser(const FacebookUser &fu) : User(fu) {
        copy(fu);
    }

    FacebookUser &operator=(const FacebookUser &fu) {
        if (this != &fu) {
            strcpy(username, fu.username);
            strcpy(password, fu.password);
            strcpy(email, fu.email);
            copy(fu);
        }

        return *this;
    }

    ~FacebookUser() {
    }

    // Популарноста се пресметува така што се собираат бројот на пријатели, бројот на лајкови и бројот на коментари,
    // но притоа бројот на лајкови се множи со коефициент на вредност на лајкот кој е ист за секој корисник и изнесува 0.1,
    // а исто така и бројот на коментари се множи со ист таков коефициент кој е 0.5.
    double popularity() {
        // double popularnost = 0;
        // popularnost = friends + (likes * 0.1) + (comments * 0.5);
        // return popularnost;

        return friends + (likes * 0.1) + (comments * 0.5);
    }
};

// За класата TwitterUser уште се чуваат и:
//
// број на следачи и
// број на твитови
// Популарноста се пресметува така што се собираат бројот на следачи и бројот на твитови, но притоа бројот на твитови
// се множи со коефициент на вредност на твитот кој е ист за секој корисник и изнесува 0.5.
class TwitterUser : public User {
private:
    int followers;
    int tweets;

    void copy(const TwitterUser &tu) {
        followers = tu.followers;
        tweets = tu.tweets;
    }

public:
    TwitterUser() : User() {
    }

    TwitterUser(char *username, char *password, char *email, int followers, int tweets) : User(
        username, password, email) {
        this->followers = followers;
        this->tweets = tweets;
    }

    TwitterUser(const TwitterUser &tu) : User(tu) {
        copy(tu);
    }

    TwitterUser &operator=(const TwitterUser &tu) {
        if (this != &tu) {
            strcpy(username, tu.username);
            strcpy(password, tu.password);
            strcpy(email, tu.email);
            copy(tu);
        }

        return *this;
    }

    ~TwitterUser() {
    }

    // Популарноста се пресметува така што се собираат бројот на следачи и бројот на твитови, но притоа бројот на твитови
    // се множи со коефициент на вредност на твитот кој е ист за секој корисник и изнесува 0.5.
    double popularity() {
        return followers + (tweets * 0.5);
    }
};

// Да се креира класа SocialNetwork која ќе содржи:
//
// динамичка низа од покажувачи од класата User
// број на тековни корисници и
// максимален број на корисници кој може да го содржи мрежата и кој е ист за сите мрежи и иницијално е поставен на 5
// Да се преоптовари операторот += со кој ќе се додава нов корисник.
//
// Да се дефинира метод avgPopularity() кој ќе ја враќа просечната популарност на корисниците во мрежата.
//
// Исто така да се овозможи промена на максималната големина на низата преку методот changeMaximumSize(int number).
class SocialNetwork {
private:
    User **users;
    int numUsers;
    int maxUsers;

    void copy(const SocialNetwork &sn) {
        maxUsers = sn.maxUsers;
        numUsers = sn.numUsers;
        users = new User *[numUsers];
        for (int i = 0; i < numUsers; i++) {
            users[i] = sn.users[i];
        }
    }

public:
    SocialNetwork() {
        users = new User *[0];
        numUsers = 0;
        maxUsers = 5;
    }

    SocialNetwork(User **users, int numUsers) {
        maxUsers = 5;
        this->numUsers = numUsers;
        this->users = new User *[numUsers];
        for (int i = 0; i < numUsers; i++) {
            this->users[i] = users[i];
        }
    }

    SocialNetwork(const SocialNetwork &sn) {
        copy(sn);
    }

    SocialNetwork &operator=(const SocialNetwork &sn) {
        if (this != &sn) {
            delete[] users;
            copy(sn);
        }

        return *this;
    }

    ~SocialNetwork() {
        delete[] users;
    }

    // Да се преоптовари операторот += со кој ќе се додава нов корисник.
    SocialNetwork &operator+=(User *user) {
        if (numUsers == maxUsers) {
            throw MaximumSizeLimit(maxUsers);
        }

        User **tmp = new User *[numUsers + 1];
        for (int i = 0; i < numUsers; i++) {
            tmp[i] = users[i];
        }

        tmp[numUsers] = user;
        ++numUsers;
        delete[] users;

        users = tmp;
        return *this;
    }

    // Да се дефинира метод avgPopularity() кој ќе ја враќа просечната популарност на корисниците во мрежата.
    double avgPopularity() {
        double sum = 0.0;
        for (int i = 0; i < numUsers; i++) {
            sum += users[i]->popularity();
        }

        double avg = sum / numUsers;
        return avg;
    }

    // Исто така да се овозможи промена на максималната големина на низата преку методот changeMaximumSize(int number).
    void changeMaximumSize(int numbers) {
        maxUsers = numbers;
    }
};


//
// Потребно е да се справите со следните исклучоци:
//
// Доколку лозинката на корисникот не содржи барем 1 голема буква, 1 мала буква и 1 број да се фрли исклучок од класа InvalidPassword
// така што како параметар ќе се прати пораката Password is too weak.
// Доколку емаилот на корисникот не содржи точно еднаш @ да се фрли исклучок од класа InvalidEmail така што како параметар ќ
// е се прати пораката Mail is not valid.
// Доколку проба да се додаде корисник во социјалната мрежа, а веќе максималниот број на корисници е пополнет
// да се фрли исклучок од класа MaximumSizeLimit така што како параметар ќе се прати максималниот број на корисници во мрежата.
// Сите класи кои се справуваат со исклучоци треба да го имаат имплементирано методот void message() така што
// за првите две класи ќе ја печати пораката којашто е испратена како параметар, а за последната класа ќе печати
// You can't add more than N users, каде што N е параметарот кој е пратен. Исто така со try-catch
// блокови справете се со исклучоците на соодветните места во main(), каде што во catch ќе го повикате методот
// message() од соодветниот исклучок.
int main() {
    SocialNetwork network = SocialNetwork();
    int n;
    cin >> n;
    char username[50];
    char password[50];
    char email[50];
    int userType;
    for (int i = 0; i < n; ++i) {
        cin >> username;
        cin >> password;
        cin >> email;
        cin >> userType;
        if (userType == 1) {
            int friends;
            int likes;
            int comments;
            cin >> friends >> likes >> comments;

            try {
                User *u = new FacebookUser(username, password, email, friends, likes, comments);
                network += u;
            } catch (InvalidPassword &ip) {
                ip.message();
            } catch (InvalidEmail &ie) {
                ie.message();
            } catch (MaximumSizeLimit &msl) {
                msl.message();
            }
        } else {
            int followers;
            int tweets;
            cin >> followers >> tweets;

            try {
                User *u = new TwitterUser(username, password, email, followers, tweets);
                network += u;
            } catch (InvalidPassword &ip) {
                ip.message();
            } catch (InvalidEmail &ie) {
                ie.message();
            } catch (MaximumSizeLimit &msl) {
                msl.message();
            }
        }
    }
    network.changeMaximumSize(6);
    cin >> username;
    cin >> password;
    cin >> email;
    int followers;
    int tweets;
    cin >> followers >> tweets;


    try {
        User *u = new TwitterUser(username, password, email, followers, tweets);
        network += u;
    } catch (InvalidPassword &ip) {
        ip.message();
    } catch (InvalidEmail &ie) {
        ie.message();
    } catch (MaximumSizeLimit &msl) {
        msl.message();
    }

    cout << network.avgPopularity();
}

//Input
// 7
// blazer Gargamel2  blazeryahoo.com 1 123 411 204
// Scooby cart00nNetw0rk scoobydoo@gmail.com 1 282 1098 41
// IronMan Avangers iron@man.com 2 678 1025
// Dexter Massuc0 lisbon@dexter.com 2 418 299
// ABBA_Official EibibiEi0 ABBA@baba.com 2 21932 98
// Labrador co1nc1denCe labrador@hotmail.com 1 101 57 19
// FernandoVerdasco schW1b fverdasco@tennis.com 2 8726 455
// EdSheeran D1v1d3 edsheeransheeran.com 2 10423 188
//Output
// Mail is not valid.
// Password is too weak.
// Mail is not valid.
// 6406.1

//Input
// 7
// blazer Gargamel2  blazer@yahoo.com 1 123 411 204
// Scooby cart00nNetw0rk scoobydoo@gmail.com 1 282 1098 41
// IronMan Avangers iron@man.com 2 678 1025
// Dexter Massuc0 lisbon@dexter.com 2 418 299
// ABBA_Official EibibiEi0 ABBA@baba.com 2 21932 98
// Labrador co1nc1denCe labrador@hotmail.com 1 101 57 19
// FernandoVerdasco schW1b fverdasco@tennis.com 2 8726 455
// EdSheeran D1v1d3 edsheeran@sheeran.com 2 10423 188
//Output
// Password is too weak.
// You can't add more than 5 users.
// 4759.43
