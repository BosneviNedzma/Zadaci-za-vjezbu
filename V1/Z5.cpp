#include <iostream>
#include <cmath>

using namespace std;





int main()
{
float result = 0;
float memory = 0;
auto f1_dodaj = [&result](int a) { result += a;};
auto f2_oduzmi = [&result](int a) {result -= a;};
auto f3_pomnozi = [&result](int a) {result *= a; };
auto f4_korijen = [&result]() {result = sqrt(result);};
auto f5_kvadrat = [& result]() { result *= result;};
auto f6_stepenuj = [&result](int a) {result = pow(result, a); };
auto f7_memory_store = [&result, &memory]() { memory = result;};
auto f8_memory_recall = [&result, &memory]() {result = memory; };
auto f9_memory_clear = [&memory]() {memory = 0; };
auto f10_result_reset = [&result]() {result = 0; };
int x = 0;
do
{
system("cls");
cout << "RESULT = " << result << endl;
cout << "MEMORY = " << memory << endl;
cout << "1. saberi" << endl;
cout << "2. oduzmi" << endl;
cout << "3. pomnozi" << endl;
cout << "4. korijen" << endl;
cout << "5. kvadrat" << endl;
cout << "6. stepenuj" << endl;
cout << "7. memory_store" << endl;
cout << "8. memory_recall" << endl;
cout << "9. memory_clear " << endl;
cout << "10. result reset " << endl;
cout << "0. EXIT " << endl;
cout<<"Unesite operaciju: ";
cin >> x;
int a;
switch (x)
{
case 1:
	cout<<"Unesite broj: ";
	cin>>a;
f1_dodaj(a); break;
case 2:
	cout<<"Unesite broj: ";
	cin>>a;
f2_oduzmi(a); break;
case 3:
	cout<<"Unesite broj: ";
	cin>>a;
f3_pomnozi(a); break;
case 4:
f4_korijen(); break;
case 5:
f5_kvadrat(); break;
case 6:
	cout<<"Unesite broj: ";
	cin>>a;
f6_stepenuj(a); break;
case 7:
f7_memory_store(); break;
case 8:
f8_memory_recall(); break;
case 9:
f9_memory_clear(); break;
case 10:
f10_result_reset(); break;
default:
break;
}
} while (x != 0);

return 0;
}
