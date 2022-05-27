#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Podaci{
	char ime[10];
	char spol[10];
	int godiste;
	float prosjek;
};

int main(){
	
	Podaci temp;
	int brojZenskihOsoba=0, veciProsjek=0;
	char yes = 'n';
	ofstream unos("podaci.txt", ios::app);
do{

		cout<<"Unesite ime: ";
		cin>>temp.ime;
		unos<<temp.ime<<" ";
		do{
           cout<<"Unesite spol: ";
		   cin>>temp.spol;		
		   unos<<temp.spol<<" ";
	
	       if(strcmp(temp.spol, "zenski")){
	       	brojZenskihOsoba++;
		   }
	
		}while(strcmp(temp.spol, "zenski") && strcmp(temp.spol, "muski"));
		cout<<"Unesite godiste: ";
		cin>>temp.godiste;
		unos<<temp.godiste<<" ";
		do{
		cout<<"Unesite prosjek: ";
		cin>>temp.prosjek;
		unos<<temp.prosjek<<" ";	
		}while(temp.prosjek>5 || temp.prosjek<1);
		if(temp.prosjek>4.5) veciProsjek++;
		cout<<"Zelite prekinuti unos (kliknite n), ukoliko zelite nastaviti unos, kliknite bilo koji drugi znak: \n";
		cin>>yes;
}while(yes != 'y');
	
	unos.close();
	cout<<"Broj zenskih osoba je: "<<brojZenskihOsoba<<endl;
	cout<<"Broj osoba sa prosjekom vecim od 4.5 je: "<<veciProsjek<<endl;
	
	
	
	
	
	
	
	
	
	
	return 0;
}
