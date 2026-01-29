#ifndef STACK_HPP  
#define STACK_HPP 
#include <iostream>  // Giriþ ve çýkýþ iþlemleri(cin cout) için standart C++ kütüphanesidir.
using namespace std; 

template <typename Object> //Object türü, düðümün tutacaðý veri türünü belirtir. Bu sayede Node sýnýfý herhangi bir türle çalýþabilir. 
class Node { //Bu düðüm sýnýfýnda, her düðüm (node), bir veri (item) ve bir sonraki düðüme iþaret eden bir gösterici (next) içerir.
public:
	Object item;   //Düðümde saklanan veri.
	Node<Object>* next;   //Bir sonraki düðüme iþaret eden gösterici.

	//Yapýcý Fonksiyon:
	Node(const Object& item, Node<Object>* next = NULL) {
	//item: Düðümde saklanacak veriyi belirtir. next: Varsayýlan olarak NULL olan, bir sonraki düðüme iþaret eden gösterici.
		this->item = item; 
		this->next = next; 
	}
};

template <typename Object> //Yýðýndaki öðelerin türü Object ile belirtilir. Bu, Stack sýnýfýnýn farklý türlerle çalýþmasýný saðlar.
class Stack { //Yýðýn veri yapýsýný temsil eder. Verileri LIFO (Last-In, First-Out) mantýðýna göre saklar ve iþler.
private:
	Node<Object>* topOfStack; //Yýðýnýn en üstünde bulunan düðüme iþaret eder.

public:
	Stack() { //
		topOfStack = NULL; //Yýðýn ilk oluþturulduðunda, topOfStack deðerinin NULL olarak ayarlanýr. Bu, yýðýnýn baþlangýçta boþ olduðunu ifade eder.
	}
	bool isEmpty()const {   //Yýðýnýn boþ olup olmadýðýný kontrol eder.  const eklenmesi, bu metodun Stack nesnesini deðiþtirmeyeceðini garanti eder.
		return topOfStack == NULL; //topOfStack == NULL ifadesi doðruysa, yýðýn boþtur ve true döner.
	}
	void push(const Object& item) {  //Yýðýna yeni bir eleman ekler.
		topOfStack = new Node<Object>(item, topOfStack); //item: Yeni eklenen elemanýn deðeri. topOfStack: Yeni düðümün, eski topOfStack'i iþaret eden bir baðlantýsý var.Ardýndan topOfStack, yeni oluþturulan düðümü gösterecek þekilde güncellenir.
	}
	void pop() {  //Yýðýnýn en üstündeki elemaný kaldýrýr.
		if (isEmpty()) throw "Stack is Empty"; //Ýlk olarak, yýðýnýn boþ olup olmadýðýný kontrol eder. Eðer boþsa bir hata(Stack is Empty) fýrlatýr.
		Node<Object>* tmp = topOfStack;  //tmp: Geçici bir gösterici oluþturulur ve topOfStack'i gösterir.
		topOfStack = topOfStack->next;   //topOfStack, bir sonraki düðümü (topOfStack->next) gösterecek þekilde güncellenir.
		delete tmp;  //Eski düðüm (tmp) bellekten silinir.
	}
	const Object& top()const { //Yýðýnýn en üstündeki elemanýn deðerini döner. const olduðundan, bu metod yýðýný deðiþtirmez.
		if (isEmpty()) throw "Stack is Empty"; //Eðer yýðýn boþsa bir hata(Stack is Empty) fýrlatýr. 
		return topOfStack->item; //topOfStack->item: En üst düðümdeki eleman döndürülür.
	}
	void makeEmpty() {   //Yýðýný tamamen boþaltýr.
		while (!isEmpty()) pop();  //Yýðýn boþalana kadar pop() metodunu çaðýrýr ve tüm düðümleri sýrayla kaldýrýr.
	}
	~Stack() {  //Yýkýcý metot (destructor), Stack nesnesi silinirken çaðrýlýr.
		makeEmpty();  //makeEmpty() metodunu çaðýrarak yýðýn içindeki tüm elemanlarý bellekten temizler ve bellekte sýzýntý oluþmasýný engeller.

	}

};

#endif
