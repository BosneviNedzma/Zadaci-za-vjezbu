#include <iostream>
#include <cstring>
/*
Kreirajte strukturni tip podataka koji modelira robu u skladistu za svrhe inventure. Potrebno je
cuvati informacije o nazivu robe, broju skladi�ta, kolicini robe u skladi�tu, minimalnoj kolicinu
(ako je koli�ina robe jednaka ili manja od minimalne koli�ine, to zna�i da treba pozvati
dobavljaca da se obezbijede efikasne zalihe robe), jedinicnoj cijeni robe, i imenu dobavljaca.
Zatim napi�ite program koji sa tastature cita podatke o robama u skladi�tu, a nakon toga �tampa
izvje�taj koji za svaki artikal prikazuje njegov naziv, broj skladi�ta, kolicinu u skladi�tu, te ime
dobavljaca za one artikle cija je kolicina u skladi�tu manja od dozvoljene kolicine.
*/

using namespace std;

struct roba{
	char nazivRobe[30];
	int brSkladista;
	int kolicina;
	int minimalnaKolicina;
	int cijena;
	char imeDobavljaca[20];
};

void unos (roba *r, int n){
	cin.ignore();
	for(int i=0; i<n; i++){
		cout<<"Unesite naziv robe: ";
		cin.getline((r+i)->nazivRobe, 30);
		cout<<"Unesite broj skladista: ";
		cin>>(r+i)->brSkladista;
		cout<<"Unesite kolicinu: ";
		cin>>(r+i)->kolicina;
		cout<<"Unesite minimalnu kolicinu: ";
		cin>>(r+i)->minimalnaKolicina;
		cout<<"Unesite cijenu: ";
		cin>>(r+i)->cijena;
		cin.ignore();
		cout<<"Unesite ime dobavljaca: ";
		cin.getline((r+i)->imeDobavljaca, 20);
		cout<<endl;
			}
}

void ispis(roba *r, int n){
	for(int i=0; i<n; i++){
		cout<<"Naziv artikla: "<<(r+i)->nazivRobe<<endl;
		cout<<"Broj skladista u kojem se nalazi artikl: "<<(r+i)->brSkladista<<endl;
		cout<<"Kolicina dostupna u skladistu: "<<(r+i)->kolicina<<endl;
		if((r+i)->kolicina<(r+i)->minimalnaKolicina){
			cout<<"Potrebno je nabaviti dodatnu kolicinu ove artikle, a dobavljac odgovoran za njenu nabavku je: "<<(r+i)->imeDobavljaca<<endl;
		}
	}
}

int main(){
	
	int n;
	cout<<"Koliko artikala zelite unijeti: ";
	cin>>n;
	
	roba *r = new roba[n];
	unos(r,n);
	ispis(r,n);
	
	
	
	
	
	
	
	
	
	
	return 0;
}
