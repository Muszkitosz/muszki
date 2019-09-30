#include "std_lib_facilities.h"
using namespace std;
int main()
{
int a=0, b=0;
cout<<"Adjon meg egy-egy erteket a-nak es b-nek: "<<endl;
cin>>a>>b;

cout<<"1. valtozo= "<<a<<'\n';
cout<<"2. valtozo= "<<b<<'\n';

//megcsereljuk oket 

a=a+b;
b=a-b;
a=a-b;

cout<<"Csere utan: "<<endl;

cout<<"1. valtozo= "<<a<<'\n';
cout<<"2. valtozo= "<<b<<'\n';

return 0;
}
