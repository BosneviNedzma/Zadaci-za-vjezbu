#include <iostream>
#include <cmath>
using namespace std;

void unos(char niz[], int a){
	for(int i=0; i<a; i++){
		do{
			cin>>niz[i];
		}while(niz[i]<'a' || niz[i]>'z');
	}
}

void promijeni (int niz[], char niz2[], int a){
	for(int i=0; i<a; i++){
		niz[i]=niz2[i];
	}
}

int binarni (int niz[], int a){
	int binarni = 0, ostatak, brojac = 0;
	do{
		ostatak = a%2;
		binarni = binarni + ostatak * pow(10.0, brojac);
		brojac++;
	    a /= 2;
	}while(a>0);
	
	return binarni;
}


int main(){
	
	cout<<"Unesite 5 malih slova: ";
	char niz[5];
	unos(niz, 5);
	
	int niz2[5];
	promijeni(niz2,niz,5);
	cout<<"\nNovi niz, kada se slova pretvore u brojeve: \n";
	for(int i=0; i<5; i++){
		cout<<niz2[i]<<" ";
	}
	
	binarni(niz2,5);

	
	
	
	
	return 0;
}
