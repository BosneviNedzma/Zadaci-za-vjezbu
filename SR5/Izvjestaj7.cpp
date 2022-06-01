#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Vjezbe{
	string ime;
	float prosjecnaOcjena;
	int brojPropustenihVjezbi;
};

struct Izvjestaj{
	char ime[15];
	float zakljucnaOcjena;
	string komentar;
};

int main(){
	
	Vjezbe v[20];
	Vjezbe temp1;
	ofstream("grupa1.txt", ios::app);
	ofstream("grupa2.txt", ios::app);
	ofstream("grupa3.txt", ios::app);

	ifstream ulaz1("grupa1.txt");
	ofstream unos1("izvjestaj.txt", ios::app);
	if(!ulaz1){
		cout<<"Nije moguce otvoriti datoteku!\n";
	}else{
		while(ulaz1>>temp1.ime>>temp1.prosjecnaOcjena>>temp1.brojPropustenihVjezbi){
			unos1<<temp1.ime<<" "<<temp1.prosjecnaOcjena<<" "<<temp1.brojPropustenihVjezbi<<endl;
		}
	}
	ulaz1.close();
	
	ifstream ulaz2("grupa2.txt");
	if(!ulaz2){
		cout<<"Nije moguce otvoriti datoteku.\n";
	}else{
		while(ulaz2>>temp1.ime>>temp1.prosjecnaOcjena>>temp1.brojPropustenihVjezbi){
			unos1<<temp1.ime<<" "<<temp1.prosjecnaOcjena<<" "<<temp1.brojPropustenihVjezbi<<endl;
		}
	}
	ulaz2.close();
	
	ifstream ulaz3("grupa3.txt");
	if(!ulaz3){
		cout<<"Nije moguce otvoriti datoteku.\n";
	}else{
		while(ulaz3>>temp1.ime>>temp1.prosjecnaOcjena>>temp1.brojPropustenihVjezbi){
			unos1<<temp1.ime<<" "<<temp1.prosjecnaOcjena<<" "<<temp1.brojPropustenihVjezbi<<endl;
		}
	}
	ulaz3.close();
	unos1.close();
	int broj=0;
	ifstream ulaz4("izvjestaji.txt");
	if(!ulaz4){
		cout<<"Nije moguce otvoriti datoteku.\n";
	}else{
		while(ulaz4>>temp1.ime>>temp1.prosjecnaOcjena>>temp1.brojPropustenihVjezbi){
			v[broj] = temp1;
			broj++;
		}
	}
	for(int i=0; i<broj; i++){
		for(int j=i; j<broj; j++){
			for(int x=0; x<v[i].ime.length(); x++){
				
				if(int(tolower(v[i].ime[x])) > int(tolower(v[j].ime[x]))){
					swap (v[i], v[j]);
					break;
				}
				
				else if(int(tolower(v[i].ime[x])) == int(tolower(v[j].ime[x]))){
					continue;
				}
				
				else break;
				
				
			}
		}
	}
	Izvjestaj isp[20];
	ofstream unos2("izvjestaji.txt", ios::app);
	int br=0;
	while(br != broj){
		unos2<<v[br].ime<<" ";
		isp[br].zakljucnaOcjena = v[br].prosjecnaOcjena;
		unos2<<isp[br].zakljucnaOcjena<<" ";
		if(v[br].brojPropustenihVjezbi<5){
			isp[br].komentar ="zadovoljio/la";
			unos2<<isp[br].komentar<<endl;
		}else{
			isp[br].komentar="nije zadovoljio/la";
			unos2<<isp[br].komentar<<endl;
		}
		br++;
	}
	unos2.close();
	
	
	
	
	
	
	return 0;
}
