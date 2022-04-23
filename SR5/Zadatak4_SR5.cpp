#include <iostream>



/*
Definirajte strukturu “Cvor” koja sadrži polje “ime_i_prezime” tipa “string”, zatim polje
“prosjek” tipa “double” i polje “veza” koje je tipa pokazivac na “Cvor”. Iskoristite ovu strukturu
u programu koji cita slijed podataka o studentima sa tastature, koji se sastoje od imena i
prezimena i prosjeka za svakog studenta, sve dok se kao podatak o imenu studenta ne unese
prazan string (tj. dok se ne pritisne samo ENTER bez ikakvog prethodnog unosa). Program treba
da uveže te podatke u povezanu listu cvorova, ali koji nakon unosa svake od recenica umece
cvor na takvo mjesto da lista u svakom trenutku bude sortirana po prosjeku u opadajucem
redoslijedu kada se posmatra u redoslijedu kako idu veze izmeðu cvorova (tj. student sa vecim
prosjekom treba da doðe ispred studenta sa manjim prosjekom). U slucaju da više studenata ima
isti prosjek, njih treba meðusobno poredati po abecedi (preciznije, po poretku ASCII kodova).
Na kraju, program treba da ispiše podatke o svim studentima u listi, da se uvjerimo da je lista
zaista sortirana u skladu sa traženim specifikacijama.
*/
using namespace std;

struct Cvor{
	string ime_prezime;
	double prosjek;
	Cvor *veza;
};


int main(){
	
	Cvor *pocetak(nullptr);
	string unos;
	double p;
	
	while(true){
		cout<<"Unesite ime i prezime studenta: ";
		getline(cin, unos);
		if(unos.empty()) break;
		do{
			cout<<"Unesite prosjek studenta: ";
			cin>>p;
		}while(p<6 || p>10);
		
		cin.ignore();
		Cvor *novi_clan=new Cvor;
		novi_clan->ime_prezime=unos;
		novi_clan->prosjek=p;
		novi_clan->veza=0;
		if(pocetak==0){
			pocetak=novi_clan;
		}
		else if(novi_clan->prosjek > pocetak->prosjek){
			novi_clan->veza=pocetak;
			pocetak=novi_clan;
		}
		else{
			Cvor *temp;
			for(temp=pocetak; temp->veza != 0 && temp->veza->prosjek > novi_clan->prosjek; temp=temp->veza){
				novi_clan->veza = temp->veza;
				temp->veza=novi_clan;
			}
		}
		Cvor *temp;
	for(temp=pocetak; ;temp=temp->veza){
		if(temp==0) break;
		cout<<endl;
		cout<<"Ime i prezime studenta: "<<temp->ime_prezime<<endl;
			cout<<"Prosjek studenta: "<<temp->prosjek<<endl;

	}
	}
	
	
	
return 0;	
}
