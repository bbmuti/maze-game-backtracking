#include "Labirent.hpp"

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <thread>

Labirent::Labirent(Konum baslangic, Konum bitis)
    : x(baslangic.x), y(baslangic.y), yon(ASAGI), bitis(bitis), yigit(new Stack<Konum>()) {
    if (!sinirlarIcinde(baslangic) || !sinirlarIcinde(bitis)) {
        delete yigit;
        throw std::invalid_argument("Başlangıç ve bitiş harita sınırları içinde olmalıdır.");
    }

    std::ifstream dosya("Harita.txt");
    if (!dosya) {
        delete yigit;
        throw std::runtime_error("Harita.txt açılamadı.");
    }

    std::string satir;
    for (int satirNo = 0; satirNo < YUKSEKLIK; ++satirNo) {
        if (!std::getline(dosya, satir) || satir.size() != GENISLIK) {
            delete yigit;
            throw std::runtime_error("Harita 20 satır ve her satır 50 karakter olmalıdır.");
        }
        for (int sutun = 0; sutun < GENISLIK; ++sutun) {
            harita[satirNo][sutun] = satir[sutun];
        }
    }

    if (harita[baslangic.x][baslangic.y] == '#' || harita[bitis.x][bitis.y] == '#') {
        delete yigit;
        throw std::invalid_argument("Başlangıç veya bitiş noktası engel üzerinde olamaz.");
    }
    yigit->push(Konum(-1, -1, ASAGI));
}

Labirent::~Labirent() {
    delete yigit;
}

Konum Labirent::mevcutKonum() const {
    return Konum(x, y, yon);
}

bool Labirent::adimAt(Konum mevcut, Konum ileri) {
    if (EngelVarmi(ileri)) {
        return false;
    }
    yigit->push(mevcut);
    ayarla(ileri, ileri.yon);
    return true;
}

void Labirent::ayarla(Konum konum, Yon yeniYon) {
    if (!sinirlarIcinde(konum)) {
        throw std::out_of_range("Harita sınırlarının dışına çıkılamaz.");
    }
    x = konum.x;
    y = konum.y;
    yon = yeniYon;
    harita[x][y] = '-';
    std::cout << "\x1B[2J\x1B[H" << yaz() << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(30));
}

bool Labirent::CikisaGeldimi() const {
    return x == bitis.x && y == bitis.y;
}

bool Labirent::EngelVarmi(Konum konum) const {
    if (!sinirlarIcinde(konum)) {
        return true;
    }
    return harita[konum.x][konum.y] == '#' || harita[konum.x][konum.y] == '-';
}

std::string Labirent::yaz() const {
    const char yonKarakterleri[] = {'v', '<', '^', '>'};
    std::stringstream cikti;
    for (int satir = 0; satir < YUKSEKLIK; ++satir) {
        cikti << std::setw(10);
        for (int sutun = 0; sutun < GENISLIK; ++sutun) {
            if (satir == x && sutun == y) {
                cikti << yonKarakterleri[yon];
            } else {
                cikti << (harita[satir][sutun] == '-' ? ' ' : harita[satir][sutun]);
            }
        }
        cikti << '\n';
    }
    return cikti.str();
}

bool Labirent::sinirlarIcinde(Konum konum) {
    return konum.x >= 0 && konum.x < YUKSEKLIK && konum.y >= 0 && konum.y < GENISLIK;
}
