#include <iostream>

using namespace std;

void unos(float niz[], int a){
	for(int i=0; i<a; i++){
		do{
			cin>>niz[i];
		}while(niz[i]>7 || niz[i]<-7);
	}
}

bool provjera(float niz[], int a){
	for(int i=0; i<a; i++){
		if(niz[i]<0){
			return false;
		}
	}
	return true;
}
int najvecineg(float niz[], int n){
	int najveci= -100000;
	for(int i=0; i<n; i++){
		if(niz[i]>najveci && niz[i]<0){
			najveci = niz[i];
		}
	}
    return najveci;
}
int main(){
	
	float niz[6];
	
	unos(niz, 6);
	if(!provjera(niz,6)){
		cout<<"Najveci negativni broj je: "<<najvecineg(niz, 6)<<endl;
	}else{
		cout<<"U nizu nema negativnih brojeva."<<endl;
	}
	
	
	
	
	
	return 0;
}
