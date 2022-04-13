#include <iostream>

using namespace std;

/*
Deklarišite tri varijable (a, b, c) i inicijaluzujte ih
- deklarišite niz pokazivaca B velicine 100
- neka prva tri elementa niza pokazuju na varijable a, b, c
- ispišite vrijednosti varijabli a, b, c koristeci prva tri elementa niza

*/

int main(){
	

	int a = 4, b=2, c= 8;
	int* B[100] = {&a, &b, &c};
	cout<<"Vrijednosti prva tri clana niza su: \n";
	for (int i=0; i<3; i++){
		cout<<i+1<<". element niza je: "<<*B[i]<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
