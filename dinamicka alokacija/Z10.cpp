#include <iostream>

using namespace std;
/*
a)
- deklarišite nizove R1, R2 i R3 velicine 4 tipa int
o koristite konstantu
- deklarišite niz M tipa pokazivac na int velicine 3
o koristite konstantu
- neka prvi element niza M (prvi pokazivac) pokazuje na niz
R1, drugi element na R2 i treci na R3, kao na slici:
b)
- ucitajte sve elemente koristeci pokazivac M
c)
- ispišite sve elemente koristeci pokazivac M


---
Prepravite prethodni program tako da koristite sljedeæe funkcije
void ispis(int** X, int r, int k)
void ucitaj(int** X, int r, int k)
*/

void ucitaj (int** M, int r, int m){
	cout<<"Unesite elemente niza:\n";
for (int i=0; i<m; i++){
	cout<<"Unesite elemente niza R"<<i+1<<":\n";
	for (int j=0; j<r; j++){
		cin>>M[i][j];
	}
}
}

void ispis (int** M, int r, int m){
		cout<<"\nElementi niza su: \n";
	for (int i=0; i<m; i++){
		cout<<"Elementi niza R"<<i+1<<":\n";
		for (int j=0; j<r; j++){
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	
const int r=4;
const int m=3;
int R1[r], R2[r], R3[r];
int* M[m]={R1,R2,R3};

ucitaj(M,r,m);
ispis(M,r,m);	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
