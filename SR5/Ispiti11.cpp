#include <iostream>
#include <fstream>
using namespace std;

struct Ispiti{
	int brIndexa;
	string predmet;
	int ocjena;
};


int main(){
	
Ispiti isp[20];
Ispiti temp;
int br=0;

ifstream ulaz("ispiti.txt");
if(!ulaz){
	cout<<"Nije moguce otvoriti datoteku.\n";
}else{
	while(ulaz>>temp.brIndexa>>temp.predmet>>temp.ocjena){
		isp[br]=temp;
		br++;
	}
}
ulaz.close();
int x;
do{
cout<<"1. NTP"<<endl;
cout<<"2. OS"<<endl;
cout<<"3. RM"<<endl;
cout<<"4. EJ"<<endl;
cout<<"5. DM"<<endl;
cout<<"Unesite redni broj predmeta za koji zelite unijeti podatke: ";
cin>>x;
}while(x<1 || x>5);

float prosjecnaOcjena, suma=0;
int broj=0, brojProlaznihOcjena=0;

switch(x){
	case 1:
		for(int i=0; i<br; i++){
			if(isp[i].predmet == "NTP"){
				suma += isp[i].ocjena;
				broj++;
			}
		    if(isp[i].ocjena>5) brojProlaznihOcjena++;
		}
		break;
	case 2:
	    for(int i=0; i<br; i++){
			if(isp[i].predmet == "OS"){
				suma += isp[i].ocjena;
				broj++;
			}
		    if(isp[i].ocjena>5) brojProlaznihOcjena++;
		}
		break;	
	case 3:
		for(int i=0; i<br; i++){
			if(isp[i].predmet == "RM"){
				suma += isp[i].ocjena;
				broj++;
			}
		    if(isp[i].ocjena>5) brojProlaznihOcjena++;
		}
		break;
	case 4:
		for(int i=0; i<br; i++){
			if(isp[i].predmet == "DM"){
				suma += isp[i].ocjena;
				broj++;
			}
		    if(isp[i].ocjena>5) brojProlaznihOcjena++;
		}
		break;
	case 5: 
	    for(int i=0; i<br; i++){
			if(isp[i].predmet == "EJ"){
				suma += isp[i].ocjena;
				broj++;
			}
		    if(isp[i].ocjena>5) brojProlaznihOcjena++;
		}
		break;
}
	
	prosjecnaOcjena=suma/broj;
	cout<<"Prosjecna ocjena iznosi: "<<prosjecnaOcjena<<endl;
	cout<<"Prolaznost je: "<<(float(brojProlaznihOcjena)/broj)*100<<"%"<<endl;
	
	int index;
	cout<<"Unesite broj indexa: ";
	cin>>index;
	int brojSlusanih=0, brojPolozenih=0;
	float s=0, prosjek;
	for(int i=0; i<br; i++){
		if(isp[i].brIndexa == index){
			if(isp[i].predmet == "NTP") brojSlusanih++;
			if(isp[i].predmet == "DM") brojSlusanih++;
			if(isp[i].predmet == "EJ") brojSlusanih++;
			if(isp[i].predmet == "OS") brojSlusanih++;
			if(isp[i].predmet == "RM") brojSlusanih++;
			
			if(isp[i].ocjena>5) brojPolozenih++;
			s += isp[i].ocjena;
		}
	}
	prosjek = s/brojPolozenih;
	cout<<"Student/ica sa indexom "<<index<<" je slusao/la ukupno "<<brojSlusanih<<" predmeta."<<endl;
	cout<<"Student/ica sa indexom "<<index<<" je polozio/la ukupno "<<brojPolozenih<<" predmeta.\n";
	cout<<"Prosjek osobe sa indexom "<<index<<" je "<<prosjek<<"."<<endl;
	
	
	
	
	
	
	
	
	return 0;
}
