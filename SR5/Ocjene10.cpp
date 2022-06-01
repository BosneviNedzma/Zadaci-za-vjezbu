
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
struct Ucenik{
	char ime[15];
	char prezime[15];
	string predmet;
	int ocjena;
};
int main () {
	ifstream ispis("ocjene.txt");
    int brUcenika;
    Ucenik u[20];
    Ucenik temp;
	string strTemp;
	int ocjena; 
	float engleskiZbir = 0, njemackiZbir = 0;
	int engleskiUkupno = 0, njemackiUkupno = 0;
	int engleskiBrPetica = 0, njemackiBrPetica = 0;
    if(!ispis){
    	cout<<"Nije moguce otvoriti datoteku.\n";
	}else{
		while(ispis>>temp.ime>>temp.prezime>>temp.predmet>>temp.ocjena){
			u[brUcenika]=temp;
			if(u[brUcenika].predmet == "engleski"){
				engleskiZbir += u[brUcenika].ocjena;
				engleskiUkupno++;
				if(u[brUcenika].ocjena == 5){
					engleskiBrPetica++;
				}
			}
			if(u[brUcenika].predmet == "njemacki"){
				njemackiZbir += u[brUcenika].ocjena;
				njemackiUkupno++;
				if(u[brUcenika].ocjena == 5){
					njemackiBrPetica++;
				}
			}
			
		}
	}
ispis.close();
cout << "\tProsjecna ocjena iz engleskog: " <<engleskiZbir/engleskiUkupno;
		cout << "\n\tBroj petica iz engleskog: " << engleskiBrPetica;
		cout << "\n\n\tProsjecna ocjena iz njemackog: " <<  njemackiZbir / njemackiUkupno;
		cout << "\n\tBroj petica iz njemackog: " << njemackiBrPetica;
		return 0;
}
