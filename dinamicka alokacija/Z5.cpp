#include <iostream>

using namespace std;

/*

a) Implementirajte funkciju void ucitaj(int* p, int v)
b) Implementirajte funkciju void ispis(int* p, int v)
c) Implementirajte funkciju main:
deklarišite konstanu v = 10
deklarišite niz N velicine v.
pozovite funkciju ucitaj
pozovite funkciju ispis

*/

void ucitaj(int* p, int v){
	cout<<"Funkcija "<<__FUNCTION__<<" je pocela sa radom!\n";
	cout<<"Unesite "<<v<<" elemenata niza: "<<endl;
	for (int i=0; i<v; i++){
		cout<<i+1<<". clan: ";
		cin>>*(p+i);
	}
}

void ispis(int* p, int v){
	cout<<"\nFunckija "<<__FUNCTION__<<" je pocela sa radom!\n";
	cout<<"\nElementi niza su: \n";
	for (int i=0; i<v; i++){
		cout<<i+1<<". clan: "<<p[i]<<endl;
	}
}

int main(){

const int v=10;
int N[10];
ucitaj(N,v);
cout<<endl;
ispis(N,v);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
