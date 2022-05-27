#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Proizvod{
	char naziv[30];
	char proizvodjac[30];
	double cijena;
	int kolicina;
};



int main(){
	
	Proizvod p[20];
	int suma=0, i=0;
	ofstream izlaz("proizvodi.txt", ios::app);
	ifstream ulaz("proizvodi.txt");
	if(!ulaz){
		cout<<"Nema ga!"<<endl;
	}else{
		Proizvod temp;
		while(ulaz>>temp.naziv>>temp.proizvodjac>>temp.cijena>>temp.kolicina){
				p[i]=temp;
				suma += p[i].cijena;
			    i++;
		}
		ulaz.close();
		cout<<"Broj proizvoda u datoteci je "<<i<<endl;
		cout<<"Cijena svih proizvoda iznosi: "<<suma<<endl;
		cout<<"Proizvodi cija je kolicina 0: "<<endl;
		for(int j=0; j<1; j++){
			if(p[j].kolicina == 0){
				cout<<p[j].naziv<<endl;
			}
		}
		int br=0;
		cout<<"Broj proizvoda koji proizvode FIAT: ";
		for(int j=0; j<i; j++){
			if(!strcmp(p[j].proizvodjac, "FIAT")){
				br++;
			}
		}
		cout<<br<<endl;
		for(int j=0; j<i; j++){
			for(int m=j; m<i; j++){
				if(p[j].cijena>p[m].cijena) swap(p[j], p[m]);
			}
		}
	}
	cout<<endl;
	for(int j=0; j<i; j++){
		cout<<"Naziv proizvoda je: "<<p[j].naziv<<endl;
		cout<<"Proizvodjac: "<<p[j].proizvodjac<<endl;
		cout<<"Cijena proizvoda je: "<<p[j].cijena<<endl;
		cout<<"Kolicina proizvoda je: "<<p[j].kolicina<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
