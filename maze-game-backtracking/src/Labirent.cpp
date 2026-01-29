#include "Labirent.hpp"

//Labirent sýnýfý için bir kurucu metot.
Labirent::Labirent(Konum baslangic, Konum bitis) { 
	FILE* fp = fopen("Harita.txt", "r"); 
	unsigned char karakter = 0; //karakter: Okunan bir karakteri tutmak için tanýmlanýr.
	int satir = 0, sutun = 0;
	x = baslangic.x; 
	y = baslangic.y;
	this->bitis = bitis; //Sýnýfýn bitis üyesine, parametre olarak alýnan bitis deðeri atanýr.
	yon = ASAGI; 
	yigit = new Stack<Konum>();
	yigit->push(Konum(-1, -1, yon)); //Yýðýna baþlangýç olarak (-1, -1) koordinatlarýnda ve yon bilgisiyle bir konum eklenir.Bu baþlangýç konumu, yýðýnýn algoritmik iþlemine yardýmcý olur.
	while (!feof(fp)) { //feof(fp): Dosyanýn sonuna gelip gelmediðini kontrol eder.Sonuna ulaþýlana kadar döngü devam eder.
		karakter = getc(fp); //getc(fp): Dosyadan bir karakter okur ve karakter deðiþkenine atar.
		if (karakter == 255) break; 
		if (karakter == 10) { //karakter == 10: Eðer okunan karakter bir satýr sonu karakteriyse
			satir++; //satir bir artýrýlýr (yeni bir satýra geçildiðini ifade eder).
			sutun = 0; //sutun sýfýrlanýr (satýr baþýna geçer).
		}
		else {
			harita[satir][sutun] = karakter; //harita matrisinin [satir][sutun] pozisyonuna karakter yerleþtirilir.
			sutun++; //sutun bir artýrýlarak bir sonraki sütuna geçilir.
		}
	}
}
Konum Labirent::mevcutKonum() { //Bu metot, Labirent sýnýfýnda geçerli konumu (x, y, ve yon) bir Konum nesnesi olarak döndürür.
	return Konum(x, y, yon); //Konum sýnýfýnýn, x, y koordinatlarý ve yön bilgisini tutar.
}
bool Labirent::adimAt(Konum mevcut, Konum ileri) { //Amaç: Bir adým ileri gitmeye çalýþýr.
	if (!EngelVarmi(ileri)) { 
		yigit->push(mevcut); //Geçerli konum (mevcut) yýðýna (yigit) eklenir.
		ayarla(ileri, ileri.yon); 
		return true; 
	}
	return false; //Eðer engel varsa, false döndürülür.
}
void Labirent::ayarla(Konum konum, Yon yon) { //Amaç: Labirentteki konumu ve yönü günceller, görsel olarak gösterir.
	system("cls"); //Ekraný temizleme: system("cls") ekraný temizler (Windows için çalýþýr).
	this->x = konum.x; //Konum ve yön güncelleme: this->x, this->y ve this->yon deðerleri, konum ve yon ile güncellenir.
	this->y = konum.y;
	this->yon = yon;
	harita[konum.x][konum.y] = '-'; //Labirent güncelleme: harita matrisinde yeni konumu '-' karakteri ile iþaretler (muhtemelen yol izini gösteriyor).
	cout << yaz();
	Sleep(30); //Bekleme süresi: Sleep(30); ile 30 milisaniye bekleme eklenir (Windows için).
}
bool Labirent::CikisaGeldimi() { //Amaç: Labirentte çýkýþ noktasýna ulaþýlýp ulaþýlmadýðýný kontrol eder.
	return x == bitis.x && y == bitis.y; //Eðer geçerli konum (x, y) çýkýþ konumuna (bitis.x, bitis.y) eþitse, true döndürülür.Aksi halde false döner.
}
bool Labirent::EngelVarmi(Konum konum) { //Amaç: Belirli bir konumda engel olup olmadýðýný kontrol eder.
	if (konum.x >= YUKSEKLIK || konum.x < 0 || konum.y >= GENISLIK || konum.y < 0) return false; //Sýnýr kontrolü.Eðer konum.x veya konum.y labirentin sýnýrlarý dýþýnda (0 ile YUKSEKLIK/GENISLIK arasýnda deðilse), false döner.
	return harita[konum.x][konum.y] == '#' || harita[konum.x][konum.y] == '-'; //Engel kontrolü.Eðer harita[konum.x][konum.y]:'#' (engel) veya '-' (zaten gidilmiþ bir yol) ise, true döner (engel var). Aksi durumda, false döner (engel yok).
}

string Labirent::yaz() { //Labirent sýnýfýnýn bir üyesi olan yaz() metodu, bir string döndürür.Labirent haritasýnýn mevcut durumunu string olarak formatlar.
	// Yön göstergeleri (Aþaðý, Sol, Yukarý, Sað)
	char YonChr[] = { 'v', '<', '^', '>' }; 
	stringstream ss; //ss adýnda bir stringstream nesnesi tanýmlanýr.Labirent durumunu yazý olarak oluþturmak için kullanýlýr.stringstream, metin birleþtirmeyi kolaylaþtýrýr.
	for (int satir = 0;satir < YUKSEKLIK;satir++) { //Labirenti satýr satýr dolaþýr.satir deðiþkeni her bir satýrý temsil eder.YUKSEKLIK: Labirentin toplam satýr sayýsýný temsil eder.
		ss << setw(10); //ss << setw(10);: Her satýrýn baþýnda 10 karakterlik boþluk býrakýr (görsel düzenleme için).
		for (int sutun = 0;sutun < GENISLIK;sutun++) { //sutun deðiþkeni her bir sütunu temsil eder.GENISLIK: Labirentin toplam sütun sayýsýný temsil eder.Bu iç döngü, mevcut satýrdaki her sütunu iþler.
			if (satir == x && sutun == y) { //Amaç: Eðer döngüdeki konum (satir, sutun) geçerli konuma (x, y) eþitse:
				ss << YonChr[yon]; //YonChr[yon] karakteri ss'e eklenir.Bu, geçerli konumu (örneðin bir oyuncunun veya arama algoritmasýnýn pozisyonunu) yön karakteriyle temsil eder.
			}
			else { //Eðer hücre geçerli konum deðilse:
				if (harita[satir][sutun] == '-') ss << ' '; //Harita hücresinde '-' varsa, bu boþ bir alan olarak gösterilir (' ').
				else ss << harita[satir][sutun]; //Diðer durumlarda, hücredeki karakter (harita[satir][sutun]) olduðu gibi eklenir.
			}
		}
		ss << endl; //Döngü her satýrý iþledikten sonra, bir satýr sonu (endl) eklenir.Bu, labirentin her satýrýný bir alt satýra yazdýrýr.
	}
	return ss.str(); //stringstream'in içeriði (ss.str()) string olarak döndürülür.u string, labirentin güncel durumunu metinsel bir formatta temsil eder.
}