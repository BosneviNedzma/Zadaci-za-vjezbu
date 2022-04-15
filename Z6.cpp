/*
Program za izlaz iz petlje pri unosu odredjenog broja.
*/
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main(){


srand(time(NULL));
rand();
int a, unos;
while (unos != a){
	a=rand();
	cout<<"Unesi broj "<<a<<" ako zelis izaci iz petlje: "<<endl;
	cin>>unos;
	}
	cout<<"\nCestitamo, izasli ste iz petlje!"<<endl;
	
}
