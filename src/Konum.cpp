#include "Konum.hpp"

Konum::Konum(int x, int y, Yon yon) : x(x), y(y), yon(yon) {}

Konum::Konum(int x, int y) : Konum(x, y, ASAGI) {}

Konum::Konum() : Konum(0, 0, ASAGI) {}

Konum Konum::AyniYon() const {
    switch (yon) {
        case YUKARI:
            return Yukari();
        case SAG:
            return Sag();
        case ASAGI:
            return Asagi();
        case SOL:
            return Sol();
    }
    return *this;
}

Konum Konum::SaatYonu(Yon yeniYon) const {
    switch (yeniYon) {
        case YUKARI:
            return Sag();
        case SAG:
            return Asagi();
        case ASAGI:
            return Sol();
        case SOL:
            return Yukari();
    }
    return *this;
}

Konum Konum::Asagi() const { return Konum(x + 1, y, ASAGI); }
Konum Konum::Yukari() const { return Konum(x - 1, y, YUKARI); }
Konum Konum::Sol() const { return Konum(x, y - 1, SOL); }
Konum Konum::Sag() const { return Konum(x, y + 1, SAG); }

Yon Konum::TersYon() const {
    switch (yon) {
        case ASAGI:
            return YUKARI;
        case YUKARI:
            return ASAGI;
        case SOL:
            return SAG;
        case SAG:
            return SOL;
    }
    return YUKARI;
}
