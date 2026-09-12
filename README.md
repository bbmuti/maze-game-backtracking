# Labirent Oyunu — Backtracking

20 × 50 karakterlik bir metin haritasında çıkış yolunu, özel bir yığın (stack) veri yapısı ve geri izleme (backtracking) yaklaşımıyla bulan C++ konsol uygulaması.

## Nasıl çalışır?

- `#` karakterleri duvarları, boşluklar geçilebilir alanları temsil eder.
- Program girişten başlayarak uygun komşu hücreleri dener.
- Çıkmaz sokağa ulaştığında yığındaki önceki konuma döner ve farklı bir yönü araştırır.
- Arama süreci terminalde adım adım gösterilir.

## Derleme ve çalıştırma

Gereksinimler: C++17 destekli bir derleyici ve `make`.

```bash
make
make run
```

Derleme çıktılarını kaldırmak için:

```bash
make clean
```

## Proje yapısı

```text
.
├── Harita.txt
├── include/
│   ├── Konum.hpp
│   ├── Labirent.hpp
│   └── Stack.hpp
├── src/
│   ├── Konum.cpp
│   ├── Labirent.cpp
│   └── Test.cpp
└── makefile
```

`bin/` ve `lib/` klasörleri derleme sırasında oluşturulur; üretilen çalıştırılabilir dosyalar ve nesne dosyaları repoya eklenmez.

## Teknik notlar

- Harita boyutu ve başlangıç/bitiş koordinatları çalıştırma sırasında doğrulanır.
- Harita dışındaki koordinatlar engel kabul edilir.
- Dosya ve bellek yönetimi RAII ilkelerine uygun biçimde yapılır.
- Platforma özel Windows başlıkları veya kabuk komutları kullanılmaz.

## Lisans

Bu depo eğitim ve portföy amacıyla paylaşılmıştır.
