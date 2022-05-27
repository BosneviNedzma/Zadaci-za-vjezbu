#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Klijent{
	char ime[10];
	string prezime;
	char mjesto[20];
	char telefonskiBroj[9];
	float posljednjiRacun;
};

int main(){
	
	Klijent k[20];
	Klijent temp;
	int brojKlijenata=0, klijentiIzZenice=0, najveciRacun=0;
	float prosjecanRacunZaPosljednjiMjesec=0, suma=0;
	ifstream ispis("klijenti.txt");
	
	if(!ispis){
		cout<<"Nije moguce otvoriti dokument!\n";
	}else{
		while(ispis>>temp.ime>>temp.prezime>>temp.mjesto>>temp.telefonskiBroj>>temp.posljednjiRacun){
			k[brojKlijenata] = temp;
				suma += k[brojKlijenata].posljednjiRacun;
				if(k[brojKlijenata].posljednjiRacun>najveciRacun) {
					najveciRacun=k[brojKlijenata].posljednjiRacun;
				}
				brojKlijenata++;

			}
			ispis.close();

				}
cout<<"Brojevi telefona klijenata iz Zenice: \n";
for(int i=0; i<brojKlijenata; i++){
	if(strcmp(k[i].mjesto, "Zenica")){
		klijentiIzZenice++;
		cout<<"Telefonski broj: "<<k[i].telefonskiBroj<<endl;
		}
}
	cout<<endl;
	prosjecanRacunZaPosljednjiMjesec=suma/brojKlijenata;
	cout<<"Ukupan broj klijenata je: "<<brojKlijenata<<endl;
	cout<<"Prosjecan racn za posljednji mjesec je: "<<prosjecanRacunZaPosljednjiMjesec<<endl;
	cout<<"Broj klijenata iz Zenice je: "<<klijentiIzZenice<<endl;
    
	
	for(int i=0; i<brojKlijenata; i++){
		for(int j=i; j<brojKlijenata; j++){
			for(int x=0; x<k[i].prezime.length(); x++){
				if(int(tolower(k[i].prezime[x])) > int(tolower(k[j].prezime[x]))){
					swap(k[i], k[j]);
					break;
				}
				else if (int(tolower(k[i].prezime[x])) == int(tolower(k[j].prezime[x]))){
					continue;
				}
				
				else break;
			}
		}
	}
	
	cout<<endl;
	
	cout<<"\nKlijenti sortirani po prezmenima su: \n";
	for(int i=0; i<brojKlijenata; i++){
		cout<<"Ime i prezime: "<<k[i].ime<<" "<<k[i].prezime<<endl;
		cout<<"Mjesto: "<<k[i].mjesto<<endl;
		cout<<"Telefonski broj: "<<k[i].posljednjiRacun<<endl;
		cout<<"Posljednji racun klijenta: "<<k[i].posljednjiRacun<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
