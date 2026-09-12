#include "Labirent.hpp"

#include <exception>
#include <iostream>
#include <stdexcept>

int main() {
    try {
        Labirent labirent(Konum(0, 47), Konum(19, 11));

        labirent.yigit->push(Konum(labirent.x, labirent.y, ASAGI));
        Konum ilkAdim = labirent.mevcutKonum().Asagi();
        if (labirent.EngelVarmi(ilkAdim)) {
            throw std::runtime_error("Başlangıç noktasından hareket edilemiyor.");
        }
        labirent.ayarla(ilkAdim, ASAGI);

        while (!labirent.CikisaGeldimi()) {
            const Konum oncekiKonum = labirent.yigit->top();
            const Konum mevcutKonum = labirent.mevcutKonum();
            const Konum ileri = mevcutKonum.AyniYon();

            if (labirent.adimAt(mevcutKonum, ileri)) {
                continue;
            }

            bool hareketEdildi = false;
            for (int i = 0; i < 4 && !hareketEdildi; ++i) {
                Konum yeni = mevcutKonum.SaatYonu(static_cast<Yon>((mevcutKonum.yon + i) % 4));
                if (yeni.yon != mevcutKonum.TersYon()) {
                    hareketEdildi = labirent.adimAt(mevcutKonum, yeni);
                }
            }

            if (!hareketEdildi) {
                labirent.yigit->pop();
                if (oncekiKonum.x < 0 || oncekiKonum.y < 0) {
                    throw std::runtime_error("Labirentin çıkışına ulaşan bir yol bulunamadı.");
                }
                labirent.ayarla(oncekiKonum, oncekiKonum.TersYon());
            }
        }

        std::cout << "ÇIKIŞA ULAŞILDI\n";
        return 0;
    } catch (const std::exception& hata) {
        std::cerr << "Hata: " << hata.what() << '\n';
        return 1;
    }
}
