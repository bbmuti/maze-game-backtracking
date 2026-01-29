#include "Konum.hpp"

//Yapýcý Fonksiyon (Constructor):
Konum::Konum(int x, int y, Yon yon) { //Bu, bir Konum nesnesi oluþtururken X koordinatýný, Y koordinatýný ve yön bilgisini (Yon) ayarlamak için kullanýlýr.
	this->x = x;  
	this->y = y;  
	this->yon = yon;
}
Konum::Konum(int x, int y) { //Konum yapýsýný yalnýzca X ve Y koordinatlarýyla baþlatýr. Yön belirtilmezse varsayýlan olarak ASAGI atanýr.
	this->x = x;
	this->y = y;
	this->yon = ASAGI;
}
//Varsayýlan Yapýcý Fonksiyon:
Konum::Konum() { //Bir Konum nesnesi oluþturulduðunda, bu nesnenin veri üyelerine baþlangýç deðerleri atamak ve bu deðerlerle belirli bir varsayýlan durum tanýmlamaktýr.
	x = 0; //X ve Y deðerlerine 0 atanmasýnýn amacý bir koordinat sisteminde baþlangýç noktasý olarak (0, 0)'ý temsil eder.
	y = 0;
	yon = ASAGI; //yon üyesine ASAGI atanýyor. Bu, bir enum sabiti olup, yönlerden birini temsil eder.
} 
//AyniYon() Metodu
Konum Konum::AyniYon() { //Mevcut yön (yon) doðrultusunda bir hareket gerçekleþtirir ve yeni bir Konum döndürür.
	switch (yon) { 
	case YUKARI:
		return Yukari(); 
	case SAG:
		return Sag();    
	case ASAGI:
		return Asagi();  
	default:              
		return Sol();    
	}
}

Konum Konum::SaatYonu(Yon yn) { //Verilen yönü (parametre yn) saat yönünde bir sonraki yön olarak deðiþtirir ve yeni yön doðrultusunda bir hareket saðlar.
	switch (yn) {   
	case YUKARI:
		return Sag(); 
	case SAG:
		return Asagi(); 
	case ASAGI:
		return Sol();  
	default:
		return Yukari();
	}
}
Konum Konum::Asagi() {   //Aþaðý yönde bir hareket yapar ve yeni bir Konum nesnesi oluþturur.
	return Konum(x + 1, y, ASAGI);  //Çalýþma Mantýðý: X koordinatýný bir artýrýr.Y koordinatý sabit kalýr.Yön ASAGI olarak atanýr.
}
Konum Konum::Yukari() {  //Yukarý yönde bir hareket yapar ve yeni bir Konum nesnesi oluþturur.
	return Konum(x - 1, y, YUKARI);  //Çalýþma Mantýðý: X koordinatýný bir azaltýr.Y koordinatý sabit kalýr.Yön YUKARI olarak atanýr.
}
Konum Konum::Sol() {  //Sol yönde bir hareket yapar ve yeni bir Konum nesnesi oluþturur.
	return Konum(x, y - 1, SOL);  //Çalýþma Mantýðý: X koordinatý sabit kalýr.Y koordinatýný bir azaltýr.Yön SOL olarak atanýr.
}
Konum Konum::Sag() {  //Sað yönde bir hareket yapar ve yeni bir Konum nesnesi oluþturur.
	return Konum(x, y + 1, SAG);  //Çalýþma Mantýðý: X koordinatý sabit kalýr.Y koordinatýný bir artýrýr.Yön SAG olarak atanýr.
}
Yon Konum::TersYon() {   //Mevcut yönün tam tersini döndürür.
	if (yon == ASAGI) return YUKARI;  //Çalýþma Mantýðý: yon deðiþkenine baðlý olarak ters yön döndürülür.
	if (yon == YUKARI) return ASAGI;  
	if (yon == SOL) return SAG;
	if (yon == SAG) return SOL;
	return YUKARI; // Varsayýlan olarak YUKARI döndürülür.
}