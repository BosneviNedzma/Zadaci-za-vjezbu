#include <iostream>
#include <cstring>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
using namespace std;

struct Radnik{
	int ib;
	char ime[10];
	char prezime[10];
	double dohodak[12];
	int staz;
	char spol[10];
};


void unos(Radnik* niz, int vel){
	srand(time(NULL));
	rand();
	for(int i=0; i<vel; i++){
		cout<<"Unesite podatke za "<<i+1<<". osobu: \n";
		cout<<"IB: ";
		cin>>niz[i].ib;
		cin.ignore();
		cout<<"Ime: ";
		cin.getline(niz[i].ime, 10);
		cout<<"Prezime: ";
		cin.getline(niz[i].prezime, 10);
		for(int j=0; j<12; j++){
			cout<<j+1<<". mjesec: ";
			niz[i].dohodak[j] = rand()%200+801;
			cout<<niz[i].dohodak[j]<<endl;
		}
		cout<<"Staz: ";
		cin>>niz[i].staz;
		cin.ignore();
		do{
			cout<<"Spol (muski, zenski): ";
			cin.getline(niz[i].spol, 10);
		}while(strcmp(niz[i].spol, "zenski") != 0 && strcmp(niz[i].spol, "muski") != 0);
	}
}

void ispis(Radnik* r){
	cout<<"IB: "<<r->ib<<endl;
	cout<<"Ime i prezime: "<<r->ime<<" "<<r->prezime<<endl;
	cout<<"Staz: "<<r->staz<<"\tSpol: "<<r->spol<<endl;
	cout<<"Dohodci po mjesecima: \n";
	for(int i=0; i<12; i++){
		cout<<setw(2)<<i+1<<". mjesec: "<<r->dohodak[i]<<"KM"<<endl;
	}
}

int prebrojiZene(Radnik* niz, int vel){
	int br=0;
	for(int i=0; i<vel; i++){
		if(strcmp(niz[i].spol, "zenski")==0) br++;
	}
	return br;
}

void kopirajZene (Radnik *nizR, Radnik *nizZ, int vel){
	int br=0;
	for(int i=0; i<vel; i++){
		if(strcmp(nizR[i].spol, "zenski")==0){
			nizZ[br++] = nizR[i];
		}
	}
}
Radnik* najduzePrezime(Radnik* niz, int vel){
	int brSlova=0, pom=0;
	Radnik * p = NULL;
	for(int i=0; i<vel; i++){
		pom=strlen(niz[i].prezime);
		if(pom>brSlova){
			brSlova = pom;
			p = niz+i;
			
		}
	}
	return p;
}
void pretragaPoImenu(Radnik* niz, char* ime, int vel){
	bool ima=false;
	for(int i=0; i<vel; i++){
		if(strcmp(niz[i].ime, ime) == 0){
			ispis(niz+i);
			ima = true;
		}
	}
	if(!ima){
		cout<<"Nema radnika sa tim imenom!\n";
	}
}

double prihodi2(Radnik* niz, int vel, int IB){
	double plata=0;
	for(int i=0; i<vel; i++){
		if(niz[i].ib == IB){
			for(int j=0; j<12; j++){
				plata += niz[i].dohodak[j];
			}
			plata *= (1+0.06*niz[i].staz);
		}
	}
	return plata;
}

int main(){
	
	int brRadnika;
	cout<<"Koliko imate radnika: ";
	cin>>brRadnika;
	cin.ignore();
	Radnik* nizRadnika = new Radnik[brRadnika];
	cout<<"Unos podataka za radnike:\n";
	unos(nizRadnika, brRadnika);
	
	cout<<"\nIspis radnika:\n";
	for(int i=0; i<brRadnika; i++){
		ispis(nizRadnika+i);
	}
	
	cout<<"Radnik sa najduzim prezimenom:\n";
	ispis(najduzePrezime(nizRadnika, brRadnika));
	
	char traziIme[10];
	cout<<"Unesite ime za pretragu: ";
	cin.getline(traziIme, 10);
	pretragaPoImenu(nizRadnika, traziIme, brRadnika);
	
	int IB;
	cout<<"Unesite IB radnika za obracun: ";
	cin>>IB;
	cin.ignore();
	double prihodi = prihodi2(nizRadnika, brRadnika, IB);
	if(prihodi != 0){
		cout<<"\nGodisnji prihodi radnika sa IB: "<<IB<<" iznosi: "<<prihodi<<"KM\n";
	}else{
		cout<<"Ne postoji radnik sa IB: "<<IB<<endl;
	}
	
	int brZena = prebrojiZene(nizRadnika, brRadnika);
	if(brZena != 0){
		Radnik* nizZena = new Radnik [brZena];
		kopirajZene(nizRadnika, nizZena, brRadnika);
		for(int i=0; i<brZena; i++){
			ispis(nizZena+i);
		}
		delete[] nizZena;
		nizZena = NULL;
	}else{
		cout<<"Nema zenskih radnika!\n";
	}
	
	delete[] nizRadnika;
	nizRadnika = NULL;
	
	return 0;
}
