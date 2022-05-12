#include <iostream>

using namespace std;



int main(){
	
auto saberi = [](int a, int b){
return a+b;	
};
	
	cout<<saberi(3,4);
	
	int x;
	double y;
	double z = 4.3;
	x = saberi(5,7);
	y = saberi (4,2);
	cout<<endl;
	cout<<x<<" "<<y<<endl;
	
	auto pomnozi = [x,y](double c){return x*y*c;};
	cout<<pomnozi(z)<<endl;
	
	auto podijeli = [&x,y](){
	  x= 26;
	  return x/y;	
	};
	cout<<podijeli();
	cout<<x<<" "<<y<<endl;
	
	auto oduzmi = [=](){
	return z-x;	
	};
	
	cout<<oduzmi()<<endl;
	
	auto ispis = [&](){
	  z = 11.22;
	  return z;	
	};
	
	cout<<ispis()<<endl;
	
	return 0;
}

