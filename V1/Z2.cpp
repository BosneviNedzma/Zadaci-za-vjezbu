#include <iostream>

using namespace std;

int saberi (int a, int b){
	return a+b;
}

int main(){
	
auto pok1 = saberi;
int (*pok2)(int, int) = saberi;
int a,b;
cout<<"Unesite dva broja: ";
cin>>a>>b;
int x1 = pok1(a,b);
int x2 = pok2(a,b);
cout<<x1<<" "<<x2<<endl;

auto saberi = [=](){return a+b;};
cout<<saberi()<<endl;



int (*saberi4)(int, int)= [](int a, int b){ return a+b;};
cout<<saberi4(a,b)<<endl;
	
	
	
	
	
	
	return 0;
}
