/*
Napisite program za ucitavanje recenice i ispisivanje u obliku: 
Namir.
amir.
mir.
ir.
r.
.
*/
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	
string recenica;
int brzina=0;
int j=0;
getline(cin, recenica, '\n');
brzina=recenica.length();
cout<<endl;
cout<<"\tIspis: \n";
for (int i=0; i<= brzina; i++){
	for(j; j<= brzina; j++){
		cout<<recenica[j];
	}
	cout<<endl;
	j=i;
}	
	
	
	
	
	
	
	
	
}
