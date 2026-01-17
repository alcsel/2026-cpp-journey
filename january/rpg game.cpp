#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Karakter {
protected:
    string isim;
    int can;
    int hasar;
    int sans;

public:
    Karakter(string gelenisim, int gelencan, int gelenhasar) {
        this->isim = gelenisim;
        this->can = gelencan;
        this->hasar = gelenhasar;
        this->sans = rand() % 10 + 1;
    }

    virtual void saldir(Karakter* rakip) = 0;


    void hasarAl(int gelenHasar) {
        this->can -= gelenHasar;
        if (this->can < 0) this->can = 0;
        cout << isim << " " << gelenHasar << " hasar aldi. (Kalan Can: " << can << ")" << endl;
    }

    bool hayattaMi() {
        return can > 0;
    }

    string isimGetir() { return isim; }
};


class Savasci : public Karakter {
public:
    Savasci(string isim, int can, int hasar) : Karakter(isim, can, hasar) {}

    void saldir(Karakter* rakip) override {
        cout << isim << " kilicini savurdu!" << endl;
        rakip->hasarAl(this->hasar);
    }
};


class Buyucu : public Karakter {
public:
    Buyucu(string isim, int can, int hasar) : Karakter(isim, can, hasar) {}

    void saldir(Karakter* rakip) override {
        int anliksans = rand() % 10 + 1; 

        if (anliksans > 8) {
            cout << isim << " GUCLU BUYU yapti! (3x Hasar)" << endl;
            rakip->hasarAl(this->hasar * 3);
        }

        else if (anliksans <= 8 && anliksans >= 3) {
            cout << isim << " buyusu isabet etti." << endl;
            rakip->hasarAl(this->hasar);
        }
        else {
            cout << isim << " buyuyu iskaladi!" << endl;
        }
    }
};


class Okcu : public Karakter {
public:
    Okcu(string isim, int can, int hasar) : Karakter(isim, can, hasar) {}

    void saldir(Karakter* rakip) override { 
        int menzil = 5; 
        menzil += (5 - (rand() % 10 + 1));


        if (menzil > 6) {
            cout << isim << " Uzaktan Tam Isabet! (2x Hasar)" << endl;
            rakip->hasarAl(this->hasar * 2);
        }
        else if (menzil <= 6 && menzil > 2) {
            cout << isim << " Normal ok atisi." << endl;
            rakip->hasarAl(this->hasar);
        }
        else {
            cout << isim << " Cok yakin oldugu icin iskaladi!" << endl;
        }
    }
};

int main() {
    srand(time(NULL));
	
    Karakter* k1 = new Savasci("Arthur", 120, 15);
    Karakter* k2 = new Buyucu("Gandalf", 80, 25);
    Karakter* k3 = new Okcu("Kante", 100, 18); // k2 yerine k3 yapıldı

    cout << "--- SALDIRI TESTI ---" << endl;
    
    k3->saldir(k2);

    if (k2->hayattaMi()) {
        cout << k2->isimGetir() << " hala hayatta." << endl;
    } else {
        cout << k2->isimGetir() << " oldu." << endl;
    }

    delete k1;
    delete k2;
    delete k3;

    return 0;
}