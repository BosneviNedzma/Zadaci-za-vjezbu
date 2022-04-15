/*
Program broji od 1 do 10, s tim da preskace broj koji korisnik unese.*/
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int broj;
cout<<"Unesi broj od 1 do 10 koji zelis da racunar 'preskoci': \n";
cin>>broj;

for (int i=1; i<11; i++){
	if(i==broj){
		continue;
	}
	cout<<i<<" ";
}
	
	
	
	
	
	
	
}
