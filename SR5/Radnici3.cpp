#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Radnik{
	string ime;
	string prezime;
	int brojGodinaStaza;
	int stepenStrucneSpreme;
	double plata;
};

int main(){
	
	
	
	Radnik r[20];
	Radnik temp;
	
	int b=0, suma=0, brojRadnikaPrekoPetGodinaIskustva=0;
	float prosjecnaPlata;
	int zaposleniciSaNajvecimStepenomStrucneSpreme;
	ifstream ispis("radnici.txt");
	if(!ispis){
		cout<<"Nemoguc ispis.\n";
	}else{
		while(ispis>>temp.ime>>temp.prezime>>temp.brojGodinaStaza>>temp.stepenStrucneSpreme>>temp.plata){
			r[b]=temp;
			suma += r[b].plata;
			if(r[b].brojGodinaStaza>5){
				brojRadnikaPrekoPetGodinaIskustva++;
			}
			if(r[b].stepenStrucneSpreme>zaposleniciSaNajvecimStepenomStrucneSpreme){
				zaposleniciSaNajvecimStepenomStrucneSpreme = r[b].stepenStrucneSpreme;
			}
			b++;
		}
    	ispis.close();
	}

    prosjecnaPlata = static_cast<float>(suma)/b;
	cout<<"Ukupan broj radnika u datoteci je: "<<b<<endl;
	cout<<"Prosjecna plata radnika je: "<<prosjecnaPlata<<endl;
	cout<<"Broj radnika koji imaju vise of 5 godina radnog iskustva je: "<<brojRadnikaPrekoPetGodinaIskustva<<endl;
    cout<<"Imena radnika sa "<<zaposleniciSaNajvecimStepenomStrucneSpreme<<". stepenom strucne spreme: \n";
	for(int j=0; j<b; j++){
		if(r[j].stepenStrucneSpreme == zaposleniciSaNajvecimStepenomStrucneSpreme){
			cout<<r[j].ime<<" "<<r[j].prezime<<endl;
		}
	}
	
	cout<<"Spisak radnika sortiranih po imenima: \n";
	for(int i=0; i<b; i++){
		for(int j=i; j<b; j++){
			for(int x=0; x<r[i].ime.length(); x++){
				if(int(tolower(r[i].ime[x]))>int(tolower(r[j].ime[x]))){
					swap (r[i], r[j]);
					break;
				}
				else if (int(tolower(r[i].ime[x]))== int(tolower(r[j].ime[x]))){
					continue;
				}
				else  break;
			}
		}
	}
	for(int i=0; i<b; i++){
	cout<<"Ime i prezime: "<<r[i].ime<<" "<<r[i].prezime<<endl;
	cout<<"Broj godina radnog staza: "<<r[i].brojGodinaStaza<<endl;
	cout<<"Stepen strucne spreme: "<<r[i].stepenStrucneSpreme<<endl;
	cout<<"Plata: "<<r[i].plata<<endl;
	cout<<endl;
	}
	
	
	
	
	
	
	
	return 0;
}
