#include <iostream>
#define MAX 22
using namespace std;
// bağlı liste yapısını kullanabilmek için bir node oluşturdum.
struct node
{
    float deger;
    node *next;
};

void hashFonksiyonu(float values[MAX], node *dizi[]);
// Kullanacak olduğum fonksiyonları burada tanıttım. Tanımlamaları main bloğunun altında mevcut.
void yazdir(node *dizi[]);

// Excel üzerinde gerçekleştirdiğim işlemler sonucu elde ettiğim değerleri hashValues adındaki diziye aktardım.

float hashValues[22] = {22.73, 18.54, 19.26, 20.13, 22.13, 17.85, 14.15, 19.37, 20.80, 17.39, 10.76, 4.76, 14.98, 15.29, 3.48, 9.28,
                        8.09, 72.47, 61.48, 68.22, 71.14, 68.36};

// 19 numaralı kod satırında bulunan her bir değeri A etiketine ait satırlardan,
// ve 20 Numaralı kod satırındaki değerleri ise B etiketine ait satırlardan elde ettim.

int main()
{

    node *HashTablosu[2] = {NULL, NULL}; // Hash Tablosu için elemanları bağlı liste olan bir dizi oluşturdum.
    hashFonksiyonu(hashValues, HashTablosu);
    yazdir(HashTablosu);

} // Hash Fonksiyonu birinci parametre olarak bir float değişken(elde edilen hashValue) alıyor.
void hashFonksiyonu(float values[MAX], node *dizi[])
{ // İkinci parametre olarak ise elemanları bağlı liste olan bir dizi alıyor.
  // Bu parametreyi  verileri Hash Tablosuna işleyebilmek için oluşturdum.

    // HashValues Dizisindeki  her bir değere ait çıktı üretmek için birer kez tekrar edecek bir döngü oluşturdum.
    for (int i = 0; i < MAX; ++i)
    {

        int index = values[i] / 40; // Hash Tablosuna uygun biçimde 0 ve 1 indislerini elde edebilmek için daha önce elde ettiğim
                                    // Hash değerlerini 40'a böldüm. Böylece tüm indisler 0 ve 1 olarak basitleşmiş olacak.
        node *root = new node();
        root->deger = values[i]; // Elde edeceğim değerleri bağlı liste formatında tutabilmek için root adında bir node işaretçisi tanımladım
        root->next = NULL;

        if (dizi[index] == NULL)
        { // Dizinin indisleri boş ise doğrudan bu indislere root'u atadım.
            dizi[index] = root;
        }

        else if (dizi[index]->next == NULL)
        { // Dizinin indislerinde tek bir eleman var ise ikinci elemana doğrudan root'u atadım.
            dizi[index]->next = root;
        }

        else
        {
            node *temp = dizi[index];  // Dizinin indislerinde birden fazla eleman olması durumunda NULL'dan bir önceki elemana kadar
            while (temp->next != NULL) // Diziyi dolaşıp dizinin sonuna eleman ekleyebilmek adına temp adında bir işaretçi oluşturdum.
                temp = temp->next;     // Bu işaretçi dizinin sonuna ulaştığında bir sonraki elemanına root'u atadım.

            temp->next = root;
        }
    }
}

void yazdir(node *dizi[])
{ // Sonuçları ekranda daha rahat görüntüleyebilmek için yazdir fonksiyonunu tanımladım.
    // Parametre olarak HashTablosunu temsil eden bir dizi alıyor.
    node *rootA = dizi[0]; // dizinin 0 ve 1. indislerindeki bağlı listeleri dolaşabilmek için bu indislerdeki ilk elemanı işaret eden
    node *rootB = dizi[1]; // A ve B işaretçileri oluşturdum.
    int sayacA = 1;        // Her bir grupta kaç eleman olduğunu takip edebilmek için A ve B için iki adet sayac değişkeni oluşturdum.
    int sayacB = 1;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "\t\t   Hash Tablosu" << endl
         << "-----------------------------------------------------------------------" << endl;
    cout << "A Grubuna ait Veriler:\t\tB Grubuna Ait Veriler \n"
         << "-----------------------------------------------------------------------\n";
    while (rootA != NULL || rootB != NULL)
    { // Dizinin 0 ve 1. indislerinde bulunan iki bağlı listenin de sonuna ulaşılana kadar
      // listeleri dolaşacak bir while döngüsü oluşturdum.
        if (rootA != NULL)
        {                                                                // hashTablosunun 1. indisinde bulunan yani etiketine sahip bağlı listenin sonuna ulaşılmadıysa
            cout << "A[" << sayacA++ << "] = " << rootA->deger << "\t|"; // A etiketindeki değeri yazdır ve sonraki elemana geç.
            rootA = rootA->next;
        }
        if (rootB != NULL)
        { // hashTablosunun 0. indisinde bulunan yani etiketine sahip bağlı listenin sonuna ulaşılmadıysa
          // B etiketindeki değeri yazdır ve sonraki elemana geç.
            cout << "\t\tB[" << sayacB++ << "] = " << rootB->deger << "\t|" << endl
                 << endl;
            rootB = rootB->next;
        }
        else if (rootB == NULL)
        { // Ekrana yazdırma aşamasında B grubuna ait veriler kısa olduğu için görüntünün bozulmaması adına
          // B listesinin sonuna ulaşıldığında boşluk bırakmaya devam ettim.
            cout << endl
                 << endl;
        }
    }
}