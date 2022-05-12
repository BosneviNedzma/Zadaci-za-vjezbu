#include <iostream>
using namespace std;

int main()
{
int int_var = 42;
auto lambda_func = [&int_var]()
{
cout << "lambda funkcija ima referencu na int_var: " << int_var << endl;
};
lambda_func();
for (int i = 0; i < 3; i++) {
int_var++;
lambda_func();
}
return 0;
}
