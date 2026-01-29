# Maze Game with Backtracking

Bu proje, **Veri Yapıları ve Algoritmalar** dersi kapsamında geliştirilen  
**Labirent (Maze) Oyunu: Backtracking Uygulaması**dır.

Amaç, MxN boyutlarında bir labirent içerisinde başlangıç noktasından çıkış noktasına
en uygun yolu **Backtracking (Geri İzleme)** algoritması kullanarak bulmaktır.

---

## 📌 Proje Özeti

- Labirent, bir metin dosyasından (`Harita.txt`) okunur.
- Engel (`#`) ve geçilebilir yollar (` `) ile temsil edilir.
- Algoritma, çıkmaz sokaklara girdiğinde geri dönerek alternatif yolları dener.
- Çıkış bulunduğunda yol `-` karakteri ile işaretlenir.
- Çözüm süreci terminal üzerinde adım adım görselleştirilir.

---

## 🧠 Kullanılan Algoritma

**Backtracking**

Algoritma şu şekilde çalışır:
1. Başlangıç noktasından hareket edilir.
2. Uygun yönler sırayla denenir (Aşağı, Sağ, Yukarı, Sol).
3. Engel veya çıkmaz varsa bir önceki konuma geri dönülür.
4. Daha önce denenmiş yollar tekrar kullanılmaz.
5. Çıkış noktasına ulaşıldığında algoritma sonlanır.

---

## 🧱 Kullanılan Veri Yapıları

- **Stack**
  - Gidilen yolları ve geri dönüşleri takip etmek için kullanılır.
- **Sınıflar**
  - `Labirent` : Haritayı yükler ve çözüm sürecini yönetir.
  - `Konum` : Anlık x-y koordinatlarını ve yön bilgisini tutar.
  - `Stack` : Backtracking işlemleri için kullanılır.

---

## 📂 Proje Dizin Yapısı

```text
.
├── bin
├── include
│   ├── Konum.hpp
│   ├── Labirent.hpp
│   └── Stack.hpp
├── lib
├── src
│   ├── Konum.cpp
│   ├── Labirent.cpp
│   └── test.cpp
├── Harita
│   └── Harita.txt
├── makefile
└── Rapor
```

## ▶️ Programın Çalışması

Derleme ve çalıştırma işlemi **MinGW** kullanılarak yapılmaktadır:

```bash
mingw32-make
```

Program çalıştığında:

- Labirent terminal ekranında çizilir.
- Algoritmanın hareketleri adım adım ve canlı olarak gösterilir.
- Çıkış bulunduğunda ekrana "ÇIKIŞA GELDİ" mesajı yazdırılır.


