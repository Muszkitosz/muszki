#include "std_lib_facilities.h"
using namespace std;
main()
{
int a=0, b=0;
cout<<"Adjon erteket a-nak es b-nek: \n";
cin>>a>>b;

cout<<"1. valtozo= "<<a<<'\n';
cout<<"2. valtozo= "<<b<<'\n';

//csere

a=a^b;
b=a^b;
a=a^b;

cout<<"Csere utan: \n";

cout<<"1. valtozo= "<<a<<'\n';
cout<<"2. valtozo= "<<b<<'\n';

return 0;
}
