#include <iostream>
using namespace std;

class hesap {
protected:
    int bakiye;
    int hesapno;
public:
    hesap(int hesapno, int bakiye)
    {
        this->hesapno = hesapno;
        this->bakiye = bakiye;
    }
    void bakiye_goster()
    {
        cout << "Hesap No: " << hesapno << " | Mevcut Bakiye: " << bakiye << " TL" << endl;
    }
    void para_yatir(int miktar)
    {
        bakiye += miktar;
        cout << miktar << " TL hesabiniza yatirildi." << endl;
    }
    void para_cek(int miktar)
    {
        if (miktar > bakiye)
        {
            cout << "Yetersiz bakiye! Cekebileceginiz miktar: " << bakiye << " TL" << endl;
        }
        else
        {
            bakiye -= miktar;
            cout << miktar << " TL hesabinizdan cekildi." << endl;
        }
    }
};

class vadelihesap : public hesap {
private:
    double faiz_orani;

public: 
    
    // Constructor
    vadelihesap(int hesapno, int bakiye, double faiz_orani)
        : hesap(hesapno, bakiye)
    {
        this->faiz_orani = faiz_orani;
    }

    void faizhesapla() {
        double faiz = bakiye * faiz_orani / 100;
        bakiye += (int)faiz;
        cout << "Faiz getirisi eklendi: " << faiz << " TL" << endl;
    }
};

int main()
{
    int hesapno;
    int bakiye = 1000; 
    double faiz_orani = 10.0; 

    cout << "Bankacilik Uygulamasi" << endl;
    cout << "---------------------" << endl;
    
    cout << "Hesap Numaranizi Giriniz: ";
    cin >> hesapno;

    cout << "Islem Seciniz (1-Vadeli Hesap 2-Vadesiz Hesap 3-Cikis): ";
    int secim;
    cin >> secim;

    switch (secim)
    {
    case 1:
    {
        vadelihesap vh(hesapno, bakiye, faiz_orani);
        int ay;
        cout << "Kac ay vadeli hesap acmak istiyo123rsunuz? ";
        cin >> ay;
        
        cout << "--- Hesaplamalar ---" << endl;
        for (int i = 0; i < ay; i++) {
            cout << (i + 1) << ". Ay sonu: ";
            vh.faizhesapla();
        }
        cout << "--- Son Durum ---" << endl;
        vh.bakiye_goster();
        break;
    }
    case 2:
    {
        hesap h(hesapno, bakiye);
        int islem;
        cout << "Islem Seciniz (1-Para Yatir 2-Para Cek 3-Bakiye Goster): ";
        cin >> islem;
        
        switch (islem)
        {
        case 1:
        {
            int miktar;
            cout << "Yatirmak istediginiz miktar: ";
            cin >> miktar;
            h.para_yatir(miktar);
            h.bakiye_goster();
            break;
        }
        case 2:
        {
            int miktar;
            cout << "Cekmek istediginiz miktar: ";
            cin >> miktar;
            h.para_cek(miktar);
            h.bakiye_goster();
            break;
        }
        case 3:
            h.bakiye_goster();
            break;
        default:
            cout << "Gecersiz islem!" << endl;
        }
        break;
    }
    case 3:
        cout << "Cikis yapiliyor..." << endl;
        break;
    default:
        cout << "Gecersiz secim!" << endl;
    }
    
    return 0;

}
