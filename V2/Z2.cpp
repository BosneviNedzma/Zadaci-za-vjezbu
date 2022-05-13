#include <iostream>

using namespace std;

int faktorijel (int a){
	int m=1;
	for(int i=2; i<=a; i++){
		m *= i;
	}
	return m;
}
float suma(int a){
	float suma=0;
	for(int i=1; i<=a; i++){
		suma += faktorijel(i);	}
		return suma;
}

int main()
{
    int a;
    while (cout<<"Unesite prirodan broj: ", cin>>a, a<1);
    cout<<suma(a)<<endl;
    
    
    
    
    return 0;
}
