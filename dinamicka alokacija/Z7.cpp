#include <iostream>

using namespace std;

/*

Napišite program u kojem ce:
- Korisnik odrediti velicinu x.
- Alocirati dinamicki nizovi A velicine x
- Alocirati dinamicki nizovi B velicine x
- Korisnik treba unijeti elemente nizova A i B.

o koristite funkciju ucitaj iz prethodnog zadatka.
- Alocirati dinamicki nizovi C velicine x
- Sabrati elemente nizova A i B, te rezultat smjestiti u niz C
o koristite funkciji saberi.
- Ispisati elemente niza C
o koristite funkcije ispis iz prethodnog zadatka.
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

void saberi (int* a, int* b, int* c, int x){
	for (int i=0; i<x; i++){
		c[i]=a[i]+b[i];
	}
}

int main(){

 int x;
 cout<<"Unesite velicinu niza: ";
 cin>>x;
int* A = new int[x];
int* B = new int[x];
int* C = new int[x];
cout<<"\nUnesite elemente prvog niza: \n";
ucitaj(A,x);
cout<<endl;
cout<<"\nUnesite elemente drugog niza: \n";
ucitaj(B,x);
saberi(A,B,C,x);
ispis(C,x);

delete [] A;
delete [] B;
delete [] C;


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
