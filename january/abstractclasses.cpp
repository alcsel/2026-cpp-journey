#include <iostream>
using namespace std;

class Hesap {
protected:
    int bakiye;
public:
    Hesap(int bakiye) {
        this->bakiye = bakiye;
    }

    void bakiyeGoster() {
        cout << "Mevcut Bakiye: " << bakiye << " TL" << endl;
    }
    virtual void paraCek(int miktar) = 0; 
};


class VadesizHesap : public Hesap {
public:
    VadesizHesap(int bakiye) : Hesap(bakiye) {}

    void paraCek(int miktar) override {
        if (miktar <= bakiye) {
            bakiye -= miktar;
            cout << "Vadesiz hesaptan " << miktar << " TL cekildi." << endl;
        } else {
            cout << "Yetersiz bakiye!" << endl;
        }
    }
};

class VadeliHesap : public Hesap {
public:
    VadeliHesap(int bakiye) : Hesap(bakiye) {}

    void paraCek(int miktar) override {
        if (miktar <= bakiye) {
            bakiye -= (miktar + 50); 
            cout << "Vadeli hesaptan islem yapildi (Ceza uygulandi)." << endl;
        }
    }
};

int main() {

    Hesap* h1 = new VadesizHesap(1000);
    Hesap* h2 = new VadeliHesap(1000);

    h1->paraCek(200); 
    h1->bakiyeGoster();

    cout << "----------------" << endl;

    h2->paraCek(200); 
    h2->bakiyeGoster();

    return 0;

}

