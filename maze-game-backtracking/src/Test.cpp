#include "Labirent.hpp"

int main() {
	Labirent* labirent = new Labirent(Konum(0, 48), Konum(19, 11)); //Yeni bir Labirent nesnesi oluþturulur.Baþlangýç konumu: (0, 48) Bitiþ konumu: (19, 11).namik bellek kullanýlarak labirent nesnesi oluþturulur.

    // Baþlangýç Konumunu Yýðýna Ekleme:
	labirent->yigit->push(Konum(labirent->x, labirent->y, ASAGI)); //yigit, labirentin bir yýðýn (Stack) veri yapýsýdýr.Labirentin baþlangýç konumu (labirent->x, labirent->y) ve yön bilgisi (ASAGI) yýðýna eklenir.
	labirent->ayarla(Konum(labirent->x, labirent->y, ASAGI).Asagi(), ASAGI); //ayarla metodu çaðrýlarak labirentin baþlangýç durumu ayarlanýr.ASAGI.Asagi(): Aþaðý yöndeki ilk hareket için bir ayar yapýlýr.
	//Çýkýþa Ulaþma Döngüsü:
	while (!labirent->CikisaGeldimi()) { //Labirentin çýkýþ noktasýna ulaþýlana kadar döngü devam eder.CikisaGeldimi() metodu, labirentin bitiþ konumuna ulaþýlýp ulaþýlmadýðýný kontrol eder.
		//Yön Denemesi ve Konum Ýþlemleri:
		int denemeYonSayisi = 1; //denemeYonSayisi: Hareket yönü için kaç deneme yapýldýðýný takip eder.
		Konum oncekiKonum = labirent->yigit->top(); //oncekiKonum: Yýðýnýn tepesindeki konumu alýr (bir önceki konum).
		Konum mevcutKonum = labirent->mevcutKonum(); //mevcutKonum: Geçerli konumu (x, y ve yön) alýr.
		Konum ileri = mevcutKonum.AyniYon(); //ileri: Geçerli konumdan, ayný yönde bir ileri adýmý temsil eder.

        //Engel Varsa Alternatif Yön Denemeleri:
		if (!labirent->adimAt(mevcutKonum, ileri)) { //Eðer ileri doðru hareket edilemiyorsa:
			int i = 0; //i: Saat yönünde kaçýncý alternatif yönün denendiðini takip eder.
			bool sonuc = false; //sonuc: Hareketin baþarýlý olup olmadýðýný belirler. Baþarýyla bir adým atýlýrsa true olur.
			Konum yeni = mevcutKonum; //yeni: Yeni yön ve pozisyon hesaplanýr.
			while (!sonuc && denemeYonSayisi < 5) { //Yön denemeleri denemeYonSayisi < 5 koþuluna kadar devam eder.
				yeni = mevcutKonum.SaatYonu((Yon)((mevcutKonum.yon + i) % 4)); //SaatYonu: Geçerli yönün saat yönünde bir sonraki yönünü hesaplar.
				//(mevcutKonum.yon + i) % 4: Yönleri döngüsel bir þekilde dolaþýr (0: Aþaðý, 1: Sol, 2: Yukarý, 3: Sað).
				i++;
				denemeYonSayisi++;

				//Ters Yön Kontrolü:
				if (yeni.yon == mevcutKonum.TersYon()) { //Eðer yeni yön, mevcut yönün tersiyse (geri dönmeyi önlemek için), hareket denemesi baþarýsýz olarak iþaretlenir (sonuc = false).
					sonuc = false;
				}
				else { //Aksi halde, yeni yönde hareket denenir:
					sonuc = labirent->adimAt(mevcutKonum, yeni); //adimAt(mevcutKonum, yeni): Yeni yönde hareket etmeye çalýþýr. Baþarýlý olursa sonuc = true döner.
				}
			}
			// Baþarýsýzlýk Durumunda Geri Dönme:
			if (denemeYonSayisi == 5) { //Eðer tüm yön denemeleri baþarýsýz olursa (denemeYonSayisi == 5):
				labirent->yigit->pop(); //Yýðýndan Çýkartma: Bir önceki konum yýðýndan çýkarýlýr (pop()).
				labirent->ayarla(oncekiKonum, oncekiKonum.TersYon()); //Geri Dönüþ: Labirent bir önceki konuma ve ters yöne döndürülür.TersYon(): Hareket yönünün tam tersini hesaplar.
			}
		}

	}
	//Çýkýþ Noktasýna Ulaþma Durumu:
	cout << "CIKISA GELDI" << endl; 

	getchar(); //Amaç: Kullanýcýnýn bir tuþa basmasýný bekler.

	delete labirent; //Amaç: Dinamik olarak ayrýlmýþ belleði serbest býrakýr.
	return 0; 
}