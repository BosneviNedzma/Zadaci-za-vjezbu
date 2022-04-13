#include <iostream>

using namespace std;

/*

a)
- Deklarišite niz A tipa integer velicine 99 i inicijalizujte elemente na vrijednosti 301,
302, 303, .., 399
- Deklarišite niz B velicine 33, tipa pokazivac na integer
- Inicijalizujte elemente niza B tako da pokazivaci pokazuju na element niza A, na
sljedeci nacin npr:
- prvi element niza B treba da pokazuje na prvi element niza A
- drugi element niza B treba da pokazuje na cetvrti element niza A, …
- Ispišite sve vrijednosti integera na koji niz B pokazuje (dereferenciranjem elemenata
niza B)
b) Prepravite rješenje tako da dereferencirate pomocu operatora '*'; umjesto operatora
'[]'

*/

int main(){
	//a)
int A[99];
for (int i=0; i<99; i++){
	A[i]=301+i;
}
int* B[33];
for (int i=0; i<33; i++){
	B[i]=A+i*3;
}

cout<<"Vrijednosti integera B su:\n";
for (int i=0; i<33; i++){
	cout<<*B[i]<<" ";
}


//b)
cout<<"\nDrugi nacin: \n";
for (int i=0; i<33; i++){
	cout<<**(B+i)<<" ";
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
