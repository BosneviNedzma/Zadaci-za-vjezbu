#include <iostream>

using namespace std;

/*

Napišite program u kojem cete:
 Kreirati dinamicki niz od onoliko cjelobrojnih elemenata koliko želi korisnik;
 Omoguciti inicijalizaciju clanova niza unosom s tastature;
 Utvrditi koliko elemenata niza je manje od 0;
 Kreirati novi niz ciji ce elementi biti elementi prvog niza koji zadovoljavaju prethodni uvjet (manji su od
0);
 Koristite funkcije.
*/

int ucitaj(int* p, int v){
	int br=0;
	cout<<"Funkcija "<<__FUNCTION__<<" je pocela sa radom!\n";
	cout<<"Unesite "<<v<<" elemenata niza: "<<endl;
	for (int i=0; i<v; i++){
		do{
			cin.clear();
			cin.ignore(256, '\n');
			cout<<i+1<<". clan: ";
			cin>>*(p+i);
		}while(cin.fail());
		if(p[i]<0) br++;
	}
	return br;
}

void napraviNiz(int* p1,int* p2, int v){
     int br=0;
     for (int i=0; i<v; i++){
     	if(p1[i]<0) p2[br++] = p1[i];
	 }
}

void ispis (int* p,  int x){
	cout<<"Funkcija "<<__FUNCTION__<<" je pozvana!\n";
	for (int i=0; i<x; i++){
		cout<<i+1<<". clan: "<<p[i]<<endl;
	}
}

int main(){

int v1;
cout<<"Unesite dimenziju niza: ";
cin>>v1;

int* N = new int[v1];
ucitaj(N,v1);

int v2 = 0;
v2 = ucitaj (N,v1);
if( v2 != 0){
	int *B = new int[v2];
	napraviNiz(N,B, v1);
	ispis(B, v2);
	delete[] B;
	B = NULL;
}else {
	cout<<"Nema negativnih brojeva u prvom nizu!";
}

delete[]  N;
N = NULL;



	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
