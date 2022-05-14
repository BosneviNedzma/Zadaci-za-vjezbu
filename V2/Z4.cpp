#include <iostream>

using namespace std;

int suma_pravih_djeljitelja(int a){
	int suma = 0;
	for(int i=1; i<=a/2; i++){
		if(a%i==0){
			suma += i;
		}
	}
	return suma;
}

bool provjera (int a, int b){
     
	if(a==suma_pravih_djeljitelja(b) && b==suma_pravih_djeljitelja(a)){
		return true;
	}
	
	return false;
}


int main(){
	
	int a, b;
	cout<<"Unesite dva broja: ";
	cin>>a>>b;
	
if(provjera(a,b)){
	cout<<"Brojevi "<<a<<" i "<<b<<" su prijateljski brojevi."<<endl;
}else{
    cout<<"Brojevi "<<a<<" i "<<b<<" nisu prijateljski brojevi."<<endl;
	
}

	
	
	
	
	
	
	
	
	
	return 0;
}
