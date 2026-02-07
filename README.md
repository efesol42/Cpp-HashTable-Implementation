# Hash Table Implementation with Chaining Strategy

Bu proje, **Veri Yapıları ve Algoritmalar** dersi kapsamında geliştirilmiş, "Chaining" (Zincirleme) yöntemiyle çakışma (collision) yönetimi yapan özel bir Hash Table implementasyonudur.

## 🎯 Proje Amacı
Verilen ham veri setini belirli matematiksel işlemlerden (radyan dönüşümü, normalizasyon) geçirerek hash anahtarları üretmek ve bunları bellekte dinamik bağlı listeler (Linked Lists) kullanarak saklamaktır.

## ⚙️ Teknik Detaylar & Algoritma
* **Dil:** C++
* **Veri Yapısı:** Hash Table & Singly Linked List (Tek Yönlü Bağlı Liste)
* **Collision Handling:** Chaining (Her hash indeksi bir bağlı listenin başlangıcını (head) tutar).
* **Hash Fonksiyonu:** Veri setine özel geliştirilen modüler aritmetik tabanlı fonksiyon.

## 🚀 Nasıl Çalışır?
1. **Veri İşleme:** Ham veriler Excel/Algoritma aşamasında işlenerek benzersiz anahtarlara dönüştürülür.
2. **Hashing:** `hashFonksiyonu` gelen veriyi `index = value % size` mantığıyla tabloya yerleştirir.
3. **Çakışma Yönetimi:** Eğer hesaplanan indekste zaten veri varsa, yeni veri o indisteki bağlı listenin sonuna eklenir (Tail insertion).
4. **Görselleştirme:** Konsol çıktısı olarak tablonun doluluk oranı ve zincir yapısı görselleştirilir.

## 📂 Dosya İçeriği
* `main.cpp`: Kaynak kod ve algoritmalar.
* `ProjectReport.pdf`: Algoritmanın akış diyagramları, sözde kodları (pseudocode) ve detaylı analiz raporu.

## 📊 Akış Diyagramı


---
*Geliştirici: Ali Efe Sarıoğlu*
