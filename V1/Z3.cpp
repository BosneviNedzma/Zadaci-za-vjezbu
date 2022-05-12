#include <iostream>
#include <cmath>
using namespace std;

float rjesenje_kvadratne_jednacine(float a, float b, float c){
	float D = b*b-4*a*c;
	return (-b+sqrt(D))/(2*a);
}

int main(){
	
	auto pok1 = rjesenje_kvadratne_jednacine;
	float (*pok2)(float, float, float) = rjesenje_kvadratne_jednacine;
	
	float a,b,c;
	cout<<"Unesite argumente kvadratne jednacine: ";
	cin>>a>>b>>c;
	float x1 = pok1(a,b,c);
	float x2 = pok2(a,b,c);
	cout<<x1<<" "<<x2<<endl;
	
	auto pok3 = [=](){ 
		float D = b*b-4*a*c;
	    return (-b+sqrt(D))/(2*a);
	};
	

	
	cout<<pok3()<<endl;
	
	float (*pok5)(float, float, float) = [](float a, float b, float c){
	float D = b*b-4*a*c;
	return (-b+sqrt(D))/(2*a);	
	};
	
	cout<<pok5(a,b,c)<<endl;
	return 0;
}
