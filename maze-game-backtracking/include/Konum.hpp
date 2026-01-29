#ifndef KONUM_HPP    //Bu satýrlar, header guard olarak bilinir. Amacý, bu dosyanýn birden fazla kez dahil edilmesini engellemektir.
#define KONUM_HPP    //Eðer dosya daha önce tanýmlanmýþsa (KONUM_HPP), içeriði tekrar yüklenmez. Aksi takdirde dosya yüklenir ve tanýmlamalar yapýlýr.

typedef enum { ASAGI, SOL, YUKARI, SAG }Yon;    
//Bu satýr, bir enum tanýmýdýr. enum, bir grup sabit deðeri temsil eden bir veri türüdür.Burda YON süslü parantez içindekileri temsil ediyor.

struct Konum {
	int x, y; //x ve y koordinattýndaki yerini temsil eder.
	Yon yon;  // yon, hangi tarafa baktýðýný ifade eder. 
 
	// Yapýcý Fonksiyonlar (Constructor):
	Konum(int, int, Yon); //Bu, bir Konum nesnesini X ve Y koordinatlarý ve bir yön belirterek oluþturur.
	Konum(int, int);      //Bu, bir yön belirtmeden yalnýzca X ve Y koordinatlarý ile bir Konum nesnesi oluþturur.
	Konum();              //Bu, varsayýlan bir Konum nesnesi oluþturur. Koordinatlar ve yön, varsayýlan deðerlere atanabilir.
    
	// Davranýþ Fonksiyonlarý (Metotlar):
	Konum AyniYon();       
	Konum SaatYonu(Yon); 
	Konum Asagi();         
	Konum Yukari();        
	Konum Sol();          
	Konum Sag();           
	Yon TersYon();        
};

#endif //header guardýn son bulduðunu ifade eder.