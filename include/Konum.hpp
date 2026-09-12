#ifndef KONUM_HPP
#define KONUM_HPP

enum Yon { ASAGI, SOL, YUKARI, SAG };

struct Konum {
    int x;
    int y;
    Yon yon;

    Konum(int x, int y, Yon yon);
    Konum(int x, int y);
    Konum();

    Konum AyniYon() const;
    Konum SaatYonu(Yon yon) const;
    Konum Asagi() const;
    Konum Yukari() const;
    Konum Sol() const;
    Konum Sag() const;
    Yon TersYon() const;
};

#endif
