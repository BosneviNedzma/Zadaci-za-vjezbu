#include <iostream>

using namespace std;

/*
Deklarišite niz A tipa int velicine 5. Ispišite adrese elemenata niza koristeci operator '+'
bez upotrebe adresnog operatora '&'. Koristite for-petlju.
Zatim, ispišite razliku izmeðu adrese elementa sa indeksom 4 i adrese elementa sa
indeksom 1 koristeci operator '-' i operator '&'.

*/

int main(){
	

	int A[5]={201,202,203,204,205};
	cout<<"Ispis adresa elemenata skupa A: \n";
	for (int i=0; i<5; i++){
		cout<<i+1<<". clan: "<<A+i<<endl;
	}
	cout<<"\nRazlika izmedju adrese elementa sa indeksom 4 i adrese elementa sa indeksom 1 je: "<<&A[4]-&A[1]<<endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
