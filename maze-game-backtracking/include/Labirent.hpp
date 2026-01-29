#ifndef LABIRENT_HPP //Bu, dosyanýn birden fazla kez yüklenmesini engeller.
#define LABIRENT_HPP

//Bu bölge, gerekli kütüphanelerin ve diðer header dosyalarýnýn projeye dahil edilmesini saðlar.
#include <fstream>    // Dosya giriþ ve çýkýþ iþlemleri için kullanýlýr.
#include <iomanip>    //Giriþ ve çýkýþ iþlemlerinde formatlama saðlar.
#include "Windows.h"  //Windows'a özgü API iþlevlerini kullanmak için.
#include <sstream>   //String tabanlý veri akýþlarý için.
#include "Konum.hpp" // Daha önce tanýmlanmýþ Konum yapýsýný içeren baþlýk dosyasý.
#include "Stack.hpp" // Yýðýn (stack) veri yapýsýný saðlayan baþlýk dosyasý.

//Labirentin yükseklik ve geniþiðini belirler
#define YUKSEKLIK 20 
#define GENISLIK 50  

class Labirent {   //Labirent Sýnýfý
public:
	char harita[YUKSEKLIK][GENISLIK]; //Labirentin yapýsýný temsil eden iki boyutlu bir dizi.
	int x, y; //Karakterin labirentteki X ve Y koordinatlarýný temsil eder.
	Yon yon;  //Karakterin mevcut yönünü ifade eder. Bu ASAGI, SOL, YUKARI veya SAG olabilir.
	Konum bitis;  //Labirentin bitiþ noktasýný temsil eden bir konum.
	Stack<Konum>* yigit; //Hareketlerin kaydedildiði bir yýðýn veri yapýsý.Bu, geri adým atma veya çözüm yolunu takip etme gibi iþlevler için kullanýlýr.

	//Yapýcý Fonksiyon (Constructor):
	Labirent(Konum, Konum);
	//Metodlar
	Konum mevcutKonum();
	bool adimAt(Konum, Konum);
	void ayarla(Konum, Yon);
	bool CikisaGeldimi();
	bool EngelVarmi(Konum);
	string yaz();
};
#endif //Bu satýr, header guardýn sonunu belirtir.


