#include <iostream>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
using namespace std;

int main(){
	
srand(time(NULL));
rand();
int a = rand()%11+10;
int *niz = new int[a];
for(int i=0; i<a; i++){
	niz[i] = rand()%51+30;
}

cout<<"Generisani elementi su: \n";
for_each(niz, niz+a, [](int x){cout<<x<<" ";});


int maks = *niz;
for_each(niz, niz+a, [&](int a){if (a>maks) maks=a;});
cout<<"Najveca vrijednost niza je: "<<maks<<endl;
	return 0;
}
