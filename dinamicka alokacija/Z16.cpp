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
Prepravite prethodni program tako da koristite sljedece funkcije
void ispis(int** X, int r, int k)
void ucitaj(int** X, int r, int k)

---
Prepravite prethodni program tako da se staticki nizovi 
R1, R2 i R3 zamjene sa dinamickom alokacijom.

---
Prepravite prethodni program tako da se nizovi R1, R2 i R3 zamjene sa dinamickom alokacijom i to bez
korištenja dodatnih pokazivaca, tj. za alokaciju svih nizova dozvoljeno je koristiti samo niz pokazivaca M.

---
Prepravite prethodni program tako da se niz pokazivaca M alocira dinamicki.

---
Prepravite prethodni program tako da korisnik može odrediti broj kolona i broj redova matrice M.

---
U prethodni program dodajte sljedece funkcije:
int Izracunaj_sumu(int** X, int r, int k)
float Izracunaj_prosjek(int** X, int r,int k)
*/

void ucitaj (int** M, int r, int m){
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


int Izracunaj_sumu(int** X, int r, int k){
	int suma = 0;
	for (int i=0; i<r; i++){
		for (int j=0; j<r; j++){
			suma += X[i][j];
		}
	}
	return suma;
}

float Izracunaj_prosjek(int** X, int r, int k){
	return static_cast<float>(Izracunaj_sumu(X,r,k))/static_cast<float>(r*k);
}

int main(){
	
int r,m;
cout<<"Unesite broj kolona matrice: ";
cin>>r;
cout<<"Unesite broj redova matrice: ";
cin>>m;
int** M= new int*[m];
for (int i=0; i<m; i++){
	M[i] = new int[r];
}


ucitaj(M,r,m);
ispis(M,r,m);	
	
cout<<"\nProsjek iznosi: "<<Izracunaj_prosjek(M,m,r);
	
for (int i=0; i<m; i++){
	delete [] M[i];
	M[i]=NULL;
}	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
