#ifndef LABIRENT_HPP
#define LABIRENT_HPP

#include <string>

#include "Konum.hpp"
#include "Stack.hpp"

constexpr int YUKSEKLIK = 20;
constexpr int GENISLIK = 50;

class Labirent {
public:
    char harita[YUKSEKLIK][GENISLIK]{};
    int x;
    int y;
    Yon yon;
    Konum bitis;
    Stack<Konum>* yigit;

    Labirent(Konum baslangic, Konum bitis);
    ~Labirent();

    Labirent(const Labirent&) = delete;
    Labirent& operator=(const Labirent&) = delete;

    Konum mevcutKonum() const;
    bool adimAt(Konum mevcut, Konum ileri);
    void ayarla(Konum konum, Yon yeniYon);
    bool CikisaGeldimi() const;
    bool EngelVarmi(Konum konum) const;
    std::string yaz() const;

private:
    static bool sinirlarIcinde(Konum konum);
};

#endif
