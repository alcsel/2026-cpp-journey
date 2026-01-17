#include <iostream>
using namespace std;

// --- SOYUT SINIF (ABSTRACT CLASS) ---
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

    // SAF SANAL FONKSİYON (Pure Virtual)
    // "= 0" diyerek şunu diyoruz: 
    // "Ben bu fonksiyonun nasıl çalışacağını bilmiyorum. 
    // Beni miras alan çocuklarım bunu yazmak ZORUNDA."
    virtual void paraCek(int miktar) = 0; 
};

// --- ALT SINIF 1: VADESİZ HESAP ---
class VadesizHesap : public Hesap {
public:
    VadesizHesap(int bakiye) : Hesap(bakiye) {}

    // Sözleşmeyi uyguluyoruz: Zorunlu fonksiyonu yazıyoruz.
    void paraCek(int miktar) override {
        if (miktar <= bakiye) {
            bakiye -= miktar;
            cout << "Vadesiz hesaptan " << miktar << " TL cekildi." << endl;
        } else {
            cout << "Yetersiz bakiye!" << endl;
        }
    }
};

// --- ALT SINIF 2: VADELİ HESAP ---
class VadeliHesap : public Hesap {
public:
    VadeliHesap(int bakiye) : Hesap(bakiye) {}

    // Vadeli hesabın kuralı farklı: Para çekerken ceza kesiyor.
    void paraCek(int miktar) override {
        if (miktar <= bakiye) {
            bakiye -= (miktar + 50); // 50 TL ceza kesildi
            cout << "Vadeli hesaptan islem yapildi (Ceza uygulandi)." << endl;
        }
    }
};

int main() {
    // 1. HATA TESTİ: Soyut sınıftan nesne üretmeye çalışalım.
    // Hesap* h = new Hesap(1000); 
    // YUKARIDAKİ SATIRI AÇARSAN HATA ALIRSIN: 
    // "Cannot instantiate abstract class" (Soyut sınıf örneklendirilemez)

    // 2. DOĞRU KULLANIM: Pointer ile Polymorphism
    // Kumanda 'Hesap' tipinde, ama Televizyon 'VadesizHesap' tipinde.
    Hesap* h1 = new VadesizHesap(1000);
    Hesap* h2 = new VadeliHesap(1000);

    h1->paraCek(200); // Vadesiz kuralı çalışır
    h1->bakiyeGoster();

    cout << "----------------" << endl;

    h2->paraCek(200); // Vadeli kuralı çalışır (Ceza keser)
    h2->bakiyeGoster();

    return 0;
}