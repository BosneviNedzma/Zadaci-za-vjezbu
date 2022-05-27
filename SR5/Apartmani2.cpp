#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Apartmani{
   char naziv[20];
   char mjesto[20];
   int brojKreveta;
   float cijena;
};

int main(){
	
	Apartmani a[20];
	Apartmani temp;
	ofstream ispis("apartmani.txt", ios::app);
	ifstream unos("apartmani.txt");
	int brojApartmana = 0, brojApartmanaUMjestuParalia=0, apartmanZaDvoje=0;
	float prosjecnaCijena=0, suma=0;
	if(!unos){
		cout<<"Nije moguce ucitati datoteku.\n";
	}else{
		while(unos>>temp.naziv>>temp.mjesto>>temp.brojKreveta>>temp.cijena){
			a[brojApartmana] = temp;
			suma += a[brojApartmana].cijena;
			brojApartmana++;
		}
    	unos.close();
	}
	cout<<"Broj apartmana u datoteci je: "<<brojApartmana<<endl;
	prosjecnaCijena=suma/brojApartmana;
	cout<<"Prosjecna cijena apartmana je: "<<prosjecnaCijena<<endl;
	for(int i=0; i<brojApartmana; i++){
		if(!strcmp(a[i].mjesto, "Paralia")){
			brojApartmanaUMjestuParalia++;
		}
	}
	cout<<"Broj apartmana u mjestu Paralia je: "<<brojApartmanaUMjestuParalia<<endl;
    float min=100;
	cout<<"Naziv apartmana za 2 osobe sa najnizom cijenom: \n";
	for(int i=0; i<brojApartmana; i++){
		if(a[i].brojKreveta == 2){
			if(a[i].cijena<min) min=a[i].cijena;
			cout<<a[i].naziv<<" "<<min<<endl;
		}
	}
	
	return 0;
}
