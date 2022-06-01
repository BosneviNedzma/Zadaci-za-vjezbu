#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int ukupanBrojIzostanaka(const vector<int>& izostanci){
	int ukupno=0;
	for(int br: izostanci){
		ukupno += br;
	}
	return ukupno;
}

int prosjecanBrIzostanaka(const vector<int>& izostanci){
	int ukupno=0, broj=0;
	for(int br: izostanci){
		ukupno += br;
		broj++;
	}
	return ukupno/broj;
}
int najveci (const vector<int>&izostanci){
	int max=0;
	for(int br: izostanci){
		if(max<br){
			max=br;
		}
		return max;
	}
}

int brojUcenikaBezIzostanka(const vector<int>& izostanci){
	int brNula=0;
	for(int br: izostanci){
		if(br==0){
			brNula++;
		}
		return brNula;
	}
}

int main(){
	ifstream ispis("izostanci.txt");
	vector<int>izostanci;

	if(!ispis){
		cout<<"Nije moguce otvoriti datoteku.\n";
	}else{
		int temp;
		while(ispis>>temp){
			izostanci.push_back(temp);
		}
	}
	ispis.close();
	
	cout<<"\nDatoteka je ucitana!"<<endl;
			cout<<"Ukupan broj izostanaka: "<<ukupanBrojIzostanaka(izostanci)<<endl;
			cout<<"Prosjecan broj izostanaka: "<<prosjecanBrIzostanaka(izostanci)<<endl;
			cout<<"Najveci broj izostanaka: "<<najveci(izostanci)<<endl;
			cout<<"Broj studenata bez ijednog izostanka: "<<brojUcenikaBezIzostanka(izostanci)<<endl;
	
	
	
	
	
	
	
	
	
	return 0;
}
