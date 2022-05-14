#include <iostream>
#include <cmath>
using namespace std;

int brojCifri(int a){
	int duzina=0;
	while(a){
		a /= 10;
		duzina++;
	}
	
	return duzina;
}

bool provjera(int a){
	int duzina = brojCifri(a);
	int kvadrat = a*a;
	int stepen = pow(10, duzina);
	int ostatak = kvadrat%stepen;
	 
	 if(a == ostatak){
	 	return true;
	 }
	 
	 return false;
}

int main(){
	

for(int i=1; i<150; i++){
	if(provjera(i)){
		cout<<i<<" ";
	}
}	
	
	
	
	
	
	
	
	
	return 0;
}
