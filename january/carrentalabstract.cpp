#include<iostream>
using namespace std;
class araba {
protected:
    string marka;
    string model;
    int yil;
public:
    araba(string marka, string model , int yil) {
        this->marka = marka;
        this->model = model;
        this->yil = yil;
    }
    virtual void bilgileriGoster() = 0;
    virtual void kiralamaUcretiHesapla() = 0; };
class sedan : public araba {
    public:
    sedan(string marka, string model, int yil) : araba(marka, model, yil) {}
    void bilgileriGoster() override {
        cout << "Sedan Araba - Marka: " << marka << ", Model: " << model << ", Yil: " << yil << endl;
    }
    void kiralamaUcretiHesapla() override {
        cout << "Sedan araba kiralama ucreti: 100 USD/gun" << endl;
    }
};
class luxury : public araba {
    public:
    luxury(string marka, string model, int yil) : araba(marka, model, yil) {}
    void bilgileriGoster() override {
        cout << "Luxury Araba - Marka: " << marka << ", Model: " << model << ", Yil: " << yil << endl;
    }
    void kiralamaUcretiHesapla() override {
        cout << "Luxury araba kiralama ucreti: 300 USD/gun" << endl;
    }
};
int main() {
    sedan *s1=new sedan("Toyota", "Camry", 2020);
    luxury *l1=new luxury("BMW", "7 Series", 2021);

    s1->bilgileriGoster();
    s1->kiralamaUcretiHesapla();

    l1->bilgileriGoster();
    l1->kiralamaUcretiHesapla();

    return 0;
}